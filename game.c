#include "game.h"

Cell* new_board(int size) {
    Cell* board = (Cell*)malloc(sizeof(Cell) * size * size);
    board -> size = size;
    for(int i = 0;i < size * size; i++) {
        board[i].cell = Empty;
    }
    return board;
}

int get_cell(Cell* board, int r, int c) {
    return board[r + c * board->size].cell;
}

void set_cell(Cell* board, int cellType, int r, int c) {
    board[r + c * board->size].cell = cellType;
}