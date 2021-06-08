#include "draw.h"

void draw(Cell* board) {
    printf("\033[?25l");
    printf("\033[47m");
    for(int i = 0;i < board -> size; i++) {
        for(int j = 0;j < board -> size; j++) {
            int cell = get_cell(board, j, i);
            if(cell == Empty) {
                printf("\033[48;5;8m");
                printf("\033[38;5;8m");
            }
            else if(cell == Dead){
                printf("\033[40m");
                printf("\033[30m");
            }
            else if(cell == Alive){
                printf("\033[43m");
                printf("\033[33m");
            }
            printf("   ");
        }
        printf("\n");
    }
    printf("\033[?25h");
    printf("\033[0m");
}

void clean() {
    printf("\033[2J");
    printf("\033[H");
}