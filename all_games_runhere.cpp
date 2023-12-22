#include <iostream>
#include"BoardGame_Classes.hpp"
#include "Player.cpp"
#include "GameManager.cpp"
#include "5x5_board.cpp"
#include "RandomPlayer.cpp"
#include "pyramid_board.cpp"
#include"four_inrow.cpp"
#include "X_O_Board.cpp"
using namespace std;

int main() {
    int choice;
    cout << "Welcome to FCAI X-O Game. :)\n";
    cout<<"Which Game Do you want to play? \n";
    cout<<"1.Pyramid Tic Tac Toe\n"<<"2.5 x 5 Tic Tac Toe \n"<<"3.Four in a Row \n"<<"4.Original Tic Tac Toe \n";
    int n;
    cout<<"Enter your Choice: ";
    cin>>n;
    Player* players[2];
    if(n==2) {
        players[0] = new player_5x5 (1, 'x');
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new player_5x5(2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer('o', 5);
        GameManager test_board_5x5(new board_5x5(), players);
        test_board_5x5.run();
        system("pause");

    }
    else if (n==1)
    {  players[0] = new player_5x5 (1, 'x');
        cout << "Press 1 if you want to play with computer or enter any key if you want play two player: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new pyramid_RandomPlayer ('o', 3,5);

        GameManager pyramid_x_o_game (new pyramid_Board(), players);
        pyramid_x_o_game.run();
        system ("pause");
    }
    else if(n==3)
    {
        players[0] = new player1( 1, 'x');

        cout << "Welcome to FCAI four in raw Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new player1( 2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 42);

        GameManager x_o_game (new fboard(), players);
        x_o_game.run();
        system ("pause");
    }
    else if (n==4)
    {
        players[0] = new Player (1,'x');

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);

        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
        system ("pause");
    }
}