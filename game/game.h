#include <stdlib.h>
#include <stdio.h>

enum CellType
{
    Empty,
    Dead,
    Alive
};

typedef struct
{
    int size;
    int cell;
} Cell;

Cell *new_board(int size);
Cell* create_copy_board(Cell *board);
int get_cell(Cell *board, int r, int c);
void set_cell(Cell *board, int cellType, int r, int c);
int check_neighbours(Cell *board, int r, int c);
Cell* game_logic(Cell *board);
int compare_boards(Cell *board1, Cell* board2);