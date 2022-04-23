#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"
#include <memory>
#include <utility>
#include <iostream>
using std::cout, std::cin, std::string, std::unique_ptr, std::make_unique;

int main() 
{

    unique_ptr<TicTacToe> game;
    TicTacToeData data;
    TicTacToeManager manager = TicTacToeManager(data);
    string first_player;
    char choice;
    int o; int x; int t;
    int gameStyle;

    do
    {
        cout << "Pick a game to play: Tic Tac Toe 3 or 4?\n";
		cin >> gameStyle;

        while (gameStyle != 3 && gameStyle != 4) {
			cout << "Must be  either '3' or '4'.\n";
			cout << "Pick a game to play: Tic Tac Toe 3 or 4?\n";
			cin >> gameStyle;
        }

        if (gameStyle == 3) {
			game = make_unique<TicTacToe3>();
		} 
        else {
			game = make_unique<TicTacToe4>();
		}

        cout << "Enter first player (X or O): ";
        cin >> first_player;
        while (first_player != "X" && first_player != "O")
        {
            cout << "Must be either 'X' or 'O'\n";
            cout << "Enter first player (X or O): ";
            cin >> first_player;
        }
	    game->start_game(first_player);


        
        while(game->game_over() == false)
        {
            cin >> *game;
		    cout << *game;
        }

        if (game->game_over() == true)
        {
            if (game->get_winner() != "C")
            {
                cout << "\nThe winner is... " << game->get_winner() << "\n";
            }
            else 
            {
                cout << "\nTie! Nobody won.\n";
            }

            
            manager.save_game(game);
            manager.get_winner_total(o, x, t);
        }

        

        cout << "Continue type Y: ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');
    
    
    





    return 0;
}