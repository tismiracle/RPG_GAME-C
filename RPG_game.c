#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void refreshMap(int columns, int rows, char map[][columns])
{
    for (int row = 0; row < rows; row++)
    {
        strcpy(map[row], "------");
    }
}
void renderMap(int columns, int rows, char map[][columns])
{
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
    map[*player_y][*player_x] = *player_icon; 
}

void movePlayer(int *player_x, int *player_y, char *direction)
{
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

int main()
{
    bool run = true;
    struct player player1 = {0, 0, '@', 'n'};
    char direction;
    int rows_int = 3;
    const int rows_const = rows_int;
    const int columns_const = 20;
    char empty_field[] = "-";
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
    for (int row = 0; row < rows_const; row++)
    {
        strcpy(map[row], "------");
    }

    while (run)
    {
        placePlayer(columns_const, map, &player1.player_x, &player1.player_y, &player1.player);
        renderMap(columns_const, rows_const, map);
        player1.direction = input_func(OS_FLAG);
        movePlayer(&player1.player_x, &player1.player_y, &player1.direction);
        refreshScreen();
        refreshMap(columns_const, rows_const, map);
    }
    getchar();

    return 0;
}