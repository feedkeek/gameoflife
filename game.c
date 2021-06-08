#include "game.h"

// allocate new board with given size
// board is 2d array of cell's
Cell* new_board(int size) {
    Cell* board = (Cell*)malloc(sizeof(Cell) * size * size);
    board -> size = size;
    for(int i = 0;i < size * size; i++) {
        board[i].cell = Empty;
    }
    return board;
}
// get cell at given row and column
int get_cell(Cell* board, int r, int c) {
    return board[r + c * board->size].cell;
}
// set cell at given position to cellType
void set_cell(Cell* board, int cellType, int r, int c) {
    board[r + c * board->size].cell = cellType;
}