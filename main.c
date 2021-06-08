#include "draw.h"

int main() {
    Cell* board = new_board(10);
    clean();
    set_cell(board, Dead, 3, 4);
    set_cell(board, Alive, 2, 3);
    set_cell(board, Alive, 1, 4);
    draw(board);
}