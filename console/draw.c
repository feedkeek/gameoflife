#include "draw.h"

void draw(Cell* board) {
    // hide cursor
    printf("\033[?25l");
    // set background to white
    printf("\033[47m");
    for(int i = 0;i < board -> size; i++) {
        for(int j = 0;j < board -> size; j++) {
            int cell = get_cell(board, i, j);
            if(cell == Empty) {
                // set background and foreground to gray
                printf("\033[48;5;8m");
                printf("\033[38;5;8m");
            }
            else if(cell == Dead){
                // set background and foreground to black
                printf("\033[40m");
                printf("\033[30m");
            }
            else if(cell == Alive){
                // set background and foreground to yellow
                printf("\033[43m");
                printf("\033[33m");
            }
            // draw 2 empty spaces
            printf("   ");
        }
        printf("\n");
    }
    //show cursor
    printf("\033[?25h");
    // reset colors
    printf("\033[0m");
}

void clean() {
    printf("\033[2J");
    printf("\033[H");
}