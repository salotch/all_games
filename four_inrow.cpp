#include "BoardGame_Classes.hpp"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;
fboard::fboard()
{
    n_rows = 6;
    n_cols = 7;
    board =new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool fboard::update_board (int x, int y, char mark) {
    for (int i=5;i>=0;i--)
    {if (!(y < 0 || y > 6) && (board[i][y] == 0)) {
            board[i][y] = toupper(mark);
            n_moves++;
            return true;
        }
    }
    return false;
}
void fboard::display_board()
{cout<<"  ";
    for (int i: {0,1,2,3,4,5,6})cout<<i<<"   ";
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            //cout << "("  << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
bool fboard::is_winner() {
    char row_win[3], col_win[3], diag_win[2];

    for (int i: {0, 1, 2, 3, 4, 5})
        for (int x: {0, 1, 2}) {
            int s = (board[x][i] & board[x + 1][i] & board[x + 2][i] & board[x + 3][i]);
            if ((s) && ((s == 'X') || (s == 'O'))) { return true; }
        }
    for (int i: {0, 1, 2, 3, 4,5})
        for (int x: {0, 1, 2,3}) {
            int s = (board[i][x] & board[i][x+1] & board[i][x+2] & board[i][x+3]);
            if ((s) && ((s == 'X') || (s == 'O'))) { return true; }

        }
    for (int i =0;i<=2;i++)
    {for(int j=0;j<=3;j++)
        {  int s = (board[i][j] & board[i+1 ][j+1] & board[i+2][j+2] & board[i+3][j+3]);
            if ((s) && ((s == 'X') || (s == 'O'))) { return true; }
        }}
    for (int i =0;i<=2;i++) {
        for (int j = 6; j >= 3; j--) {
            int s = (board[i][j] & board[i + 1][j - 1] & board[i + 2][j - 2] & board[i + 3][j - 3]);
            if ((s) && ((s == 'X') || (s == 'O'))) { return true; }
        }
    }
    return false;
}
bool fboard::is_draw() {
    return (n_moves == 42 && !is_winner());
}
bool fboard::game_is_over () {
    return false;
}