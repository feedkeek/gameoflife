#include "console/draw.h"
#include <string.h>
#include <unistd.h>

int main()
{
    
    int size = 0;
    printf("Choose a size of board: ");
    scanf("%d", &size);
    Cell *board = new_board(size);
    // Choice loop
    while(1)
    {
        clean();
        draw(board);
        int command;
        printf("\n");
        printf("1.Choose row and column to put Alive cell\n");
        printf("2.Start a game\n");
        printf("3.Exit\n");
        scanf("%d", &command);
        if(command == 1) {
            int r, c;
            printf("Row and column: ");
            scanf("%d %d", &r, &c);
            if(r >= board->size || c >= board->size){
                printf("Index out of range\nPress any key to continue");
                getchar();
                continue;
            }
            set_cell(board, Alive, r, c);
        }
        else if(command == 2) {
            // printf("Number of neighbourd %d", check_neighbours(board, 1 ,3));
            break;
        }
        else if(command == 3) {
            return 0;
        }
    }

    // Game loop
    int checker = 0;
    while (1)
    {
        clean();
        Cell* old_board = create_copy_board(board);
        board = game_logic(board);
        sleep(1);
        if(compare_boards(old_board, board) == 1){
            checker ++;
        }
        else{
            checker = 0;
        }
        if(checker > 3) {
            clean();
            draw(old_board);
            printf("Game ended\n");
            return 1;
        }
        draw(board);
    }
    
}