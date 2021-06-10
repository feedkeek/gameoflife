#include "game.h"
#include <string.h>

// allocate new board with given size
// board is 2d array of cell's
Cell *new_board(int size)
{
    Cell *board = (Cell *)malloc(sizeof(Cell) * size * size);
    board->size = size;
    for (int i = 0; i < size * size; i++)
    {
        board[i].cell = Empty;
    }
    return board;
}

Cell *create_copy_board(Cell *board) {
    Cell* copy = new_board(board -> size);
    for(int i = 0;i < board->size; i++) {
        for(int j = 0; j < board->size; j++) {
            set_cell(copy, get_cell(board, i, j), i, j);
        }
    }
    return copy;
}
// get cell at given row and column
int get_cell(Cell *board, int r, int c)
{
    return board[c + r * board->size].cell;
}
// set cell at given position to cellType
void set_cell(Cell *board, int cellType, int r, int c)
{
    board[c + r * board->size].cell = cellType;
}

int compare_boards(Cell *board1, Cell* board2) {
    for(int i = 0; i < board1->size; i++) {
        for(int j = 0; j < board1->size; j++) {
            if(get_cell(board1, i, j) != get_cell(board2, i, j)) {
                return 0;
            }
        }
    }
    return 1;
}

int check_neighbours(Cell *board, int r, int c)
{
    int counter = 0;
    for (int x = r - 1; x <= r + 1; x++)
    {
        for (int y = c - 1; y <= c + 1; y++)
        {
            if (x != r || y != c)
            {
                if (x < 0)
                {
                    get_cell(board, board->size - 1, y) == Alive ? counter ++ : counter;
                }
                else if (x > board->size - 1)
                {
                    get_cell(board, 0, y) == Alive ? counter ++ : counter;
                }
                else if (y < 0)
                {
                    get_cell(board, x, board->size - 1) == Alive ? counter ++ : counter;
                }
                else if (y > board->size - 1)
                {
                    get_cell(board, x, 0) == Alive ? counter ++ : counter;
                }
                else
                {
                    get_cell(board, x, y) == Alive ? counter ++ : counter;
                }
            }
        }
    }
    return counter;
}

Cell* game_logic(Cell* board) {
    Cell* tnew_board = create_copy_board(board);
    for(int i = 0; i < board->size; i++){
        for(int j = 0; j < board->size; j++) {
            int counter = check_neighbours(board, i, j);
            int cell = get_cell(board, i, j);
            if(cell == Alive) {
                if(counter < 2 || counter > 3) {
                    set_cell(tnew_board, Dead, i, j);
                }
                else {
                    continue;
                }
            }
            else if(cell == Dead || cell == Empty) {
                if(counter == 3) {
                    set_cell(tnew_board, Alive, i, j);
                }
                else {
                    continue;
                }
            } 
        }
    }
    return tnew_board;
}