#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// int *

void renderMap(char map_field[][7], int rows)
{
    // printf("%d", map_field);
    // char arr[3][7] = *map_field;
    // char arr[3];
    // memcpy(arr, *map_field, 7);
    // char arr[3][7] = *map_field;
    for (int k = 0; k < rows; k++)
    {
        printf("%s\n", map_field);
    }
}

int main()
{
    bool run = true;
    const int rows = 3;
    const int columns = 7;
    char player = '@';
    int player_x = 0;
    int player_y = 0;
    // char empty_symbol[4] = "---";
    char empty_line[] = "-";
    char map_field[rows][columns];
    // strcat(empty_line, empty_symbol);
    // strcpy(map_field[0], "aa");
    // printf("%s", map_field[0]);
    for (int i = 0; i < rows; i++)
    {
        strcpy(map_field[i], "-----");
    }
    printf("%s\n", map_field[0]);
    printf("%s\n", map_field[1]);
    printf("%s\n", map_field[2]);
    // printf("%s\n", map_field[3]);
    // printf("%s\n", map_field[1]);
    // printf("%s\n", map_field[1]);
    int cols = columns;
    for (int f = 0; f < cols - 1; f++)
    {
        strcat(empty_line, "-");
    }
   
    for (int j = 0; j < 2; j++)
    {
        printf("%s\n", map_field[j]);
    }
//   /* 

    // loop which creates an array of chars to make map_field (without game character)




    return 0;
}