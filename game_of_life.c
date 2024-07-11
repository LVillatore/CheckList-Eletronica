#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 40

void print_grid(int grid[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("O");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int next_state(int grid[ROWS][COLS], int row, int col) {
    int alive_neighbors = 0;
    
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                alive_neighbors += grid[i][j];
            }
        }
    }
    
    if (grid[row][col] == 1) {
        if (alive_neighbors < 2 || alive_neighbors > 3) {
            return 0;
        } else {
            return 1;
        }
    } else {
        if (alive_neighbors == 3) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    int grid[ROWS][COLS] = {0};
    
    grid[1][2] = 1;
    grid[2][3] = 1;
    grid[3][1] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;
    
    for (int generation = 0; generation < 50; generation++) {
        system("cls");
        print_grid(grid);
        
        int next_grid[ROWS][COLS];
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                next_grid[i][j] = next_state(grid, i, j);
            }
        }
        
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = next_grid[i][j];
            }
        }
        
        sleep(2);
    }
    
    return 0;
}
