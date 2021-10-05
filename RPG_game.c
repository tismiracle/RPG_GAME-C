#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <curses.h>
#include <stdlib.h>




struct player
{
    int player_x;
    int player_y;
    char player;
};

void renderMap(int rows, char map[][rows])
{
    for (int row = 0; row < 3; row++)
    {
        printf("%s", map[1]);
        break;
    }
}


int main()
{
    bool run = true;
    struct player player1 = {0, 0, '@'};
    char direction;
 
    char map[][40] = {
        "---------------------", 
        "------------------DDDD",
        "---------------------"
    }; 
    char *map_p;
    map_p = map[0];
    // printf("%s", map_p);
    const int rows = 40;
    renderMap(rows, map);
    /*
    while (run)
    {

;
        direction = getchar();


        system("clear");
       if (direction == 'w')
       {
           player1.player_y -= 1;
       } else if (direction == 's')
       {
           player1.player_y += 1;
       } else if (direction == 'd')
       {
           player1.player_x += 1;
       } else if (direction == 'a')
       {
           player1.player_x -= 1;
       }
        for (int i = 0; i < 3; i++)
        {
            map[player1.player_y][player1.player_x] = player1.player;
            printf("%s\n", map[i]);
            map[player1.player_y][player1.player_x] = '-';
        }      
    }
    */



    return 0;
}