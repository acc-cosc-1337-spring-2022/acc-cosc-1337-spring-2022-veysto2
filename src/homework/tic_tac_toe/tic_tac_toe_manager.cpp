//cpp
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_data.h"
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

TicTacToeManager::TicTacToeManager(TicTacToeData d)
: data{d} 
{
    games = data.get_games();

    for (auto& game: games) 
    {
        update_winner_count(game->get_winner());
    }
}



void TicTacToeManager::save_game(unique_ptr<TicTacToe> &game) 
{
    update_winner_count(game->get_winner());
    games.push_back(std::move(game));
    
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

TicTacToeManager::~TicTacToeManager() 
{
    std::cout << "\n Save Games\n";
    data.save_games(games);
}