#include "console/draw.h"

int main()
{
    Cell *board = new_board(25);
    clean();
    set_cell(board, Dead, 3, 4);
    set_cell(board, Alive, 2, 3);
    set_cell(board, Alive, 1, 4);
    set_cell(board, Alive, 0, 15);
    set_cell(board, Alive, 24, 15);
    set_cell(board, Alive, 0, 0);
    set_cell(board, Alive, 0, 24);
    set_cell(board, Alive, 24, 0);
    set_cell(board, Alive, 24, 24);
    draw(board);


    check_neighbours(board, 0, 24);
}