#include <stdlib.h>
#include <stdio.h>

enum CellType{
    Empty,
    Dead,
    Alive
};

typedef struct {
    int size;
    int cell;
} Cell;

Cell* new_board(int size);
int get_cell(Cell* board, int r, int c);
void set_cell(Cell* board, int cellType, int r, int c);