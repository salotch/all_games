// Class definition for XO_RandomPlayer class
// Which is a computer player playing randomly
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer::RandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}
pyramid_RandomPlayer::pyramid_RandomPlayer (char symbol, int dimension,int dimension1):Player(symbol)
{
    this->dimension = dimension;
    this->dimension1=dimension1;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void pyramid_RandomPlayer::get_move (int& x, int& y) {
    do {
        x = (int) (rand() / (RAND_MAX + 1.0) * dimension);
        y = (int) (rand() / (RAND_MAX + 1.0) * dimension1);
    } while (x == 0 && y == 1 || x == 0 && y == 0 || x == 0 && y == 3 || x == 0 && y == 4 || x == 1 && y == 4);

}
