#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int minefield[SIZE][SIZE];
int solution[SIZE][SIZE];

// Directions for neighboring cells (8 directions plus the cell itself)
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1, 0 };

// Check if a cell is within bounds
bool inBounds(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// Count mines around a given cell
int countMines(int x, int y) {
    int count = 0;
    for (int i = 0; i < 9; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inBounds(nx, ny) && solution[nx][ny] == 1) {
            count++;
        }
    }
    return count;
}

// Check if the current solution satisfies the minefield constraints
bool isValid() {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            if (countMines(x, y) != minefield[x][y]) {
                return false;
            }
        }
    }
    return true;
}

// Recursive function to solve the problem
bool solve(int x, int y) {
    if (y == SIZE) {
        y = 0;
        x++;
    }
    if (x == SIZE) {
        return isValid();
    }

    // Try placing a mine
    solution[x][y] = 1;
    if (solve(x, y + 1)) {
        return true;
    }

    // Try without a mine
    solution[x][y] = 0;
    if (solve(x, y + 1)) {
        return true;
    }

    return false;
}

// Print the solution grid
void printSolution() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Read input minefield
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &minefield[i][j]);
            solution[i][j] = 0;
        }
    }

    // Solve and output result
    if (solve(0, 0)) {
        printSolution();
    } else {
        printf("no solution\n");
    }

    return 0;
}

