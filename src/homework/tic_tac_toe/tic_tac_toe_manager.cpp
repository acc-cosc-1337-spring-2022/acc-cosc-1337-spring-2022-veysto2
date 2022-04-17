//cpp
#include "tic_tac_toe_manager.h"
#include <iostream>
using std::cout, std::string, std::cin, std::vector, std::ostream, std::istream;

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    for(auto& game:manager.games)
    {
        out << *game << "\n"; 
    }

    return out; 
}


void TicTacToeManager::save_game(unique_ptr<TicTacToe> &b) 
{
    games.push_back(move(b));
    update_winner_count(b->get_winner());
}

void TicTacToeManager::get_winner_total(int& o, int& x, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;
    cout << "O wins: " << o << "\n";
    cout << "X wins: " << x << "\n";
    cout << "Ties: " << t << "\n";
}


void TicTacToeManager::update_winner_count(std::string winner)
{
    if (winner == "X") 
    {
        x_win+=1;
    } else if (winner == "O") 
    {
        o_win+=1;
    } else if (winner == "C")
    {
        ties+=1;
    }
}