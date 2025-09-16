#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%2d", grid[row][col]);
        }
        printf("\n");
    }
}

/**
 * @brief Checks if it's safe to place a number in a given cell.
 *
 * @param grid The 9x9 Sudoku grid.
 * @param row The cell's row index.
 * @param col The cell's column index.
 * @param num The number to check.
 * @return True if the move is safe, false otherwise.
 */
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check if 'num' is already in the current row
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check if 'num' is already in the current column
    for (int x = 0; x < SIZE; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check if 'num' is in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

/**
 * @brief Solves the Sudoku puzzle using recursive backtracking.
 *
 * @param grid The 9x9 Sudoku grid to be solved.
 * @return True if a solution exists, false otherwise.
 */
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    bool foundEmpty = false;

    // Find the first empty cell (value 0)
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                foundEmpty = true;
                break;
            }
        }
        if (foundEmpty) {
            break;
        }
    }

    // If no empty cell was found, the puzzle is solved
    if (!foundEmpty) {
        return true;
    }

    // Try placing numbers 1 through 9 in the empty cell
    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            // Make a tentative move
            grid[row][col] = num;

            // Recursively try to solve the rest of the puzzle
            if (solveSudoku(grid)) {
                return true; // Success!
            }

            // If the recursive call failed, undo the move (backtrack)
            grid[row][col] = 0;
        }
    }

    // If no number worked, trigger backtracking by returning false
    return false;
}

int main() {
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        printf("Solution found:\n");
        printGrid(grid);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
