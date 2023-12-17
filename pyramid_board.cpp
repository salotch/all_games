#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
pyramid_Board::pyramid_Board() {
    n_cols = 5;
    n_rows=3;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool pyramid_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if ((x >= 0 && x <= 2 && y >=0 && y <= 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void pyramid_Board::display_board() {
    cout << "\n             ---------";
    for (int i: {0}) {
        cout << "\n" << setw(15) << " |";
        for (int j: {2}) {
            cout << "(" << i << "," << j << ")";
            cout << board[i][j] << "|";
        }
        cout << "\n       ----------------------";
    }
    for (int i: {1}) {
        cout<<"\n"<<setw(8)<<"|";
        for (int j: {1,2,3}) {
            cout << "(" << i << "," << j << ")";
            cout  << board [i][j] << "|";
        }
        cout << "\n     ------------------------";
    }

    for (int i: {2}) {
        cout<<"\n|";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout  << board [i][j] << "|";
        }
        cout << "\n-------------------------------------";
    }


    cout << endl;
}


// Returns true if there is any winner
// either X or O
bool pyramid_Board::is_winner() {
    if ( board[0][2] == board[1][2] && board[1][2]==board[2][2]&&board[2][2]!=0 ||
         board[1][1] == board[1][2] && board[1][2]==board[1][3]&&board[1][2]!=0||
         board[2][0] == board[2][2] && board[2][2]==board[2][1]&&board[2][2]!=0||
         board[2][1] == board[2][2] && board[2][2]==board[2][3]&&board[2][2]!=0||
         board[2][2] == board[2][4] && board[2][4]==board[2][3]&&board[2][4]!=0||
         board[0][2] == board[1][3] && board[1][3]==board[2][4]&&board[2][4]!=0||
         board[0][2] == board[1][1] && board[1][1]==board[2][0]&&board[2][0]!=0)
        return true;
    return false;
}

// Return true if 9 moves are done and no winner
bool pyramid_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool pyramid_Board::game_is_over () {
    return n_moves >= 9;
}