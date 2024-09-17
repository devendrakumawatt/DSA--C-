#include <iostream>
#include <vector>
using namespace std;

void addSolution(const vector<vector<int>> &board, vector<vector<vector<int>>> &ans, int n) {
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = board[i][j];
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, const vector<vector<int>> &board, int n) {
    // Check for same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // upper-left diagonal
    int x = row;
    int y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    // upper-right diagonal
    x = row;
    y = col;
    while (x >= 0 && y < n) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y++;
    }

    return true;
}

void solve(int row, vector<vector<vector<int>>> &ans, vector<vector<int>> &board, int n) {
    // Base case: If all queens are placed
    if (row == n) {
        addSolution(board, ans, n);
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(row + 1, ans, board, n);
            board[row][col] = 0; // Backtrack
        }
    }
}

vector<vector<vector<int>>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<vector<int>>> ans;
    solve(0, ans, board, n);
    return ans;
}

// print all solutions
void printSolutions(const vector<vector<vector<int>>> &solutions) {
    for (auto solution : solutions) {
        for (auto row : solution) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int n = 4; // Change this to test other board sizes
    vector<vector<vector<int>>> ans = nQueens(n);
    cout << "Possible solution to place queen(1) : " << endl;
    printSolutions(ans);
}
