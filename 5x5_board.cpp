//
// Created by DELL on 12/17/2023.
//
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;
board_5x5:: board_5x5 () {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;//set all values to 0
    }
}
// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool board_5x5::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
// Display the board and the pieces on it
void board_5x5::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
bool board_5x5::is_winner() {

    if (n_moves==24)
    { for (int i:{0,1,2,3,4})
        for(int j:{0,1,2})
            {
            char row_win, col_win, diag_win;
            if( board[i][j]==board[i][j+1]&&board[i][j+1]==board[i][j+2])
            {   row_win =board[i][j];
            if(row_win=='X')
                winx++;
            else
                wino++;
            }
            if(board[j][i] == board[j+1][i] && board[j+1][i] ==board[j+2][i]) {
                col_win = board[j][i];
                if (col_win == 'X')
                    winx++;
                else
                    wino++;
            }
            for(int k:{0,1,2})
            {
                if(board[j][k]==board[j+1][k+1]&&board[j+1][k+1]==board[j+2][k+2])
                {   diag_win=board[j][k];
                if(diag_win=='X')
                    winx++;
                else
                    wino++;
                }
            }
        }
        if(winx>wino)
        {
            cout  << playerx_n << " wins\n";
            return false;
        }
        else
            return true;
    }
    return false;
}



// Return true if 9 moves are done and no winner
bool board_5x5::is_draw() {
    return (n_moves == 24 && !is_winner());
}

bool board_5x5::game_is_over () {
    return n_moves >= 24;
}
void player_5x5::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
player_5x5::player_5x5 (int order, char symbol): Player(order,symbol) {

}