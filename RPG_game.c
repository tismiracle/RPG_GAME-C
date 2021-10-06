#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void refreshMap(int columns, int rows, char map[][columns], char empty_field[])
{
    // puts only empty spaces on maps
    for (int row = 0; row < rows; row++)
    {
        strcpy(map[row], empty_field);
    }
}
void renderMap(int columns, int rows, char map[][columns])
{
    // renders every row of a map array
    for (int row = 0; row < rows; row++)
    {
        printf("%s\n", map[row]);
    }
}

void refreshScreen()
{
    system("cls");
}

void placePlayer(int columns, char map[][columns], int *player_x, int *player_y, char *player_icon)
{
    //places player on the map
    map[*player_y][*player_x] = *player_icon; 
}
void checkPlayerBorders(int *player_x, int *player_y, int map_rows, int map_columns)
{
    if (*player_x > map_columns - 2)
    {
        *player_x = map_columns - 2;
    } else if (*player_x < 0)
    {
        *player_x = 0;
    } else if (*player_y > map_rows - 1)
    {
        *player_y = map_rows - 1;
    } else if (*player_y < 0)
    {
        *player_y = 0;
    }
}
void movePlayer(int *player_x, int *player_y, char *direction)
{
    //changes the direction of player movement
    if (*direction == 'w')
    {
        *player_y -= 1;
    } else if (*direction == 's')
    {
        *player_y += 1;
    } else if (*direction == 'a')
    {
        *player_x -= 1;
    } else if (*direction == 'd')
    {
        *player_x += 1;
    }
}



char input_func(int OS_FLAG)
{
    // get input and returns it based on OS you're using Windows/Apple
    char input;
    if (OS_FLAG == 1)
    {
        input = getch();
    } else if (OS_FLAG == 0)
    {
        input = getchar();
    }

    return input;
}


struct player
{
    int player_x;
    int player_y;
    char player;
    char direction;
};

struct chest
{
    int chest_x;
    int chest_y;
    char chest;
    int item_id;
};

int main()
{
    bool run = true;
    struct player player1 = {0, 0, '@', 'n'};
    char direction;
    int rows_int = 5;
    const int rows_const = rows_int;
    const int columns_const = 45;
    char empty_field[columns_const];
    strcpy(empty_field, "-");
    // 1 = WINDOWS, 0 = APPLE
    int OS_FLAG;

    #ifdef _WIN32
        printf("Windows system\n");
        #include <conio.h>
        OS_FLAG = 1;
    #endif
    #ifdef __APPLE__
        printf("Apple system\n");
        OS_FLAG = 0;
    #endif


    char map[rows_const][columns_const];
    for (int column = 0; column < columns_const - 2; column++)
    {
        strcat(empty_field, "-");
    }
    
    printf("Empty field %s\n", empty_field);
    // refreshMap(columns_const, rows_const, map, empty_field);

    // mainloop
    while (run)
    {
        
        placePlayer(columns_const, map, &player1.player_x, &player1.player_y, &player1.player);
        renderMap(columns_const, rows_const, map);
        player1.direction = input_func(OS_FLAG);
        movePlayer(&player1.player_x, &player1.player_y, &player1.direction);
        checkPlayerBorders(&player1.player_x, &player1.player_y, rows_const, columns_const);
        refreshScreen();
        refreshMap(columns_const, rows_const, map, empty_field);
    }

    return 0;
}