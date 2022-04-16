#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
using std::cout, std::cin, std::string;

int main() 
{

    TicTacToe game;
    TicTacToeManager manager;
    string first_player;
    char choice;
    int o; int x; int t;

    do
    {

        cout << "Enter first player (X or O): ";
        cin >> first_player;
        while (first_player != "X" && first_player != "O")
        {
            cout << "Must be either 'X' or 'O'\n";
            cout << "Enter first player (X or O): ";
            cin >> first_player;
        }
	    game.start_game(first_player);


        
        while(game.game_over() == false)
        {
            cin >> game;
		    cout << game;
        }

        if (game.game_over() == true)
        {
            if (game.get_winner() != "C")
            {
                cout << "\nThe winner is... " << game.get_winner() << "\n";
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