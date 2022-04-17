//cpp
#include "tic_tac_toe.h"
#include <iostream>
using std::string; using std::cout;

std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    if (game.pegs.size() == 9) {
        for(int i = 0; i < 9; i+=3) {
            out << game.pegs[i] << "|" << game.pegs[i +1] << "|" << game.pegs[i+2] << "\n";
        }
    }
    else {
        for(int i = 0; i < 16; i+=4) {
            out << game.pegs[i] << "|" << game.pegs[i +1] << "|" << game.pegs[i+2] << "|" << game.pegs[i+3] << "\n";
        }
    }

    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game) 
{
    int position;
    if (game.pegs.size() == 9) {
        cout << "Enter position [1-9]: ";
        in >> position;
    }
    else {
        cout << "Enter position [1-16]: ";
	    in >> position;
    }
    game.mark_board(position);
    return in;
}

bool TicTacToe::game_over()
{
    bool game_over;
    if(check_column_win() == true || check_row_win() == true || check_diagonal_win() == true)
    {
        set_winner();
        game_over = true;
    }
    else if (check_board_full() == true)
    {
        winner = "C";
        game_over = true;
    }
    return game_over;
}

void TicTacToe::start_game(string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}



void TicTacToe::set_next_player()
{
    if(player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

bool TicTacToe::check_board_full()
{
    for(auto peg: pegs)
    {
        if (peg == " ")
        {
            return false;
        } 
    }

    return true;
}

void TicTacToe::clear_board()
{
    for (auto& peg: pegs)
    {
        peg = " ";
    }
}

bool TicTacToe::check_column_win()
{
    return false;
}

bool TicTacToe::check_row_win()
{
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    return false;
    
}

void TicTacToe::set_winner()
{
    if(player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
    }
    
}