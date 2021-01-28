#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0
#define N 9
bool isSafe(int grid[N][N])
{
    unordered_map<int, int>
        row_[9], column_[9], box[3][3];
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            row_[row][grid[row][col]] += 1;
            column_[col][grid[row][col]] += 1;
            box[row / 3][col / 3][grid[row][col]] += 1;

            if (
                box[row / 3][col / 3][grid[row][col]] > 1
                || column_[col][grid[row][col]] > 1
                || row_[row][grid[row][col]] > 1)
                return false;
        }
    }
    return true;
}

/* A utility function to print grid */
void printGrid_1(int grid[N][N])
{
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool SolveSudoku(
    int grid[N][N], int i, int j)
{
    if (i == N - 1 && j == N) {
        if (isSafe(grid)) {
            printGrid_1(grid);
            return true;
        }
        return false;
    }
    if (j == N) {
        i++;
        j = 0;
    }
    if (grid[i][j] != UNASSIGNED)
        return SolveSudoku(grid, i, j + 1);
    for (int num = 1; num <= 9; num++) {
        grid[i][j] = num;

        if (SolveSudoku(grid, i, j + 1))
            return true;

        grid[i][j] = 0;
    }
    return false;
}

void Solve2(int grid[N][N])
{
        clock_t start, end; 
        start = clock();
        if (SolveSudoku(grid, 0, 0) != true)
        {
        cout << "No solution exists";
        }
        else
        {
            end = clock();
            cout << "\nThe time taken to execute the code Backtracking using recursion  is "<< (end - start)  << " ms" << endl;
            
        }

}
