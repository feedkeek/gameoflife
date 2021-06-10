#include "game.h"

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
void check_neighbours(Cell *board, int r, int c)
{
    for (int x = r - 1; x <= r + 1; x++)
    {
        for (int y = c - 1; y <= c + 1; y++)
        {
            if (x != r || y != c)
            {
                if (x < 0)
                {
                    printf("%d ", get_cell(board, board->size - 1, y));
                }
                else if (x > board->size - 1)
                {
                    printf("%d ", get_cell(board, 0, y));
                }
                else if (y < 0)
                {
                    printf("%d ", get_cell(board, x, board->size - 1));
                }
                else if (y > board->size - 1)
                {
                    printf("%d ", get_cell(board, x, 0));
                }
                else
                {
                    printf("%d ", get_cell(board, x, y));
                }
            }
        }
    }
}