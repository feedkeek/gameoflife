#include "draw.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

void draw(Cell *board)
{
    // retutns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window *win = SDL_CreateWindow("GAME",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       1000, 1000, 0);
    while (1)
        ;

    return 0;
}

// void draw(Cell* board) {
//     // hide cursor
//     printf("\033[?25l");
//     // set background to white
//     printf("\033[47m");
//     for(int i = 0;i < board -> size; i++) {
//         for(int j = 0;j < board -> size; j++) {
//             int cell = get_cell(board, i, j);
//             if(cell == Empty) {
//                 // set background and foreground to gray
//                 printf("\033[48;5;8m");
//                 printf("\033[38;5;8m");
//             }
//             else if(cell == Dead){
//                 // set background and foreground to black
//                 printf("\033[40m");
//                 printf("\033[30m");
//             }
//             else if(cell == Alive){
//                 // set background and foreground to yellow
//                 printf("\033[43m");
//                 printf("\033[33m");
//             }
//             // draw 2 empty spaces
//             printf("   ");
//         }
//         printf("\n");
//     }
//     //show cursor
//     printf("\033[?25h");
//     // reset colors
//     printf("\033[0m");
// }

void clean()
{
    printf("\033[2J");
    printf("\033[H");
}