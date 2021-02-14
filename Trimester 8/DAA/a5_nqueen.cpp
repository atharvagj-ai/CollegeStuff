#include <cmath>
#include <iostream>
#include <vector>
 
using namespace std;
 
void printBoard(vector<vector<char>> &board) {
    for (auto row : board) {
        for (auto ch : row) {
            cout << ch << "  ";
        }
        cout << endl;
    }
}
 
void solveBoard(vector<vector<char>> &board, int row, int rowmask, int ldmask, int rdmask, int &ways) {
    int n = board.size();
    int all_rows_filled = (1 << n) - 1;
 
    if (rowmask == all_rows_filled) {
        ways++;
        cout << "Solution " << ways << ":\n";
        printBoard(board);
        cout << "\n";
        return;
    }
 
    int safe = all_rows_filled & (~(rowmask | ldmask | rdmask));
    
    while (safe) {
        int p = safe & (-safe);
        int col = (int)log2(p);
        board[row][col] = 'Q';
 
        solveBoard(board, row + 1, rowmask | p, (ldmask | p) << 1, (rdmask | p) >> 1, ways);
 
        safe = safe & (safe - 1);
        board[row][col] = '0';
    }
}
 
int main() {
    int n;
    int ways = 0, rowmask = 0, ldmask = 0, rdmask = 0, row = 0;
   
    cout << "Size of Board: ";
    cin >> n;
    cout << "\n";
    vector<vector<char>> board;
    for (int i = 0; i < n; i++) {
        vector<char> tmp;
        for (int j = 0; j < n; j++) {
            tmp.push_back('0');
        }
        board.push_back(tmp);
    }
 
    solveBoard(board, row, rowmask, ldmask, rdmask, ways);
    cout << "Number of ways to solve the n queens problem (with board size = " << n << "): " << ways << "\n";
 
    return 0;
}
