#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test tic tac toe 3 game over for a tie")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");
    game->mark_board(1);
    REQUIRE(false == game->game_over());

    game->mark_board(5);
    REQUIRE(false == game->game_over());        

    game->mark_board(3);
    REQUIRE(false == game->game_over());

    game->mark_board(2);
    REQUIRE(false == game->game_over());

    game->mark_board(8);
    REQUIRE(false == game->game_over());

    game->mark_board(4);
    REQUIRE(false == game->game_over());

    game->mark_board(7);
    REQUIRE(false == game->game_over());

    game->mark_board(9);
    REQUIRE(false == game->game_over());

    game->mark_board(6);
    REQUIRE(true == game->game_over());
    REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Test first player set to X") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");
    REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("O");
    REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column" )
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	game->start_game("X"); 
	game->mark_board(1); 
	game->mark_board(3); 
	game->mark_board(4);  
	game->mark_board(5); 
	game->mark_board(7);  
	REQUIRE(true == game->game_over());
	REQUIRE(game->get_winner() == "X"); 
}

TEST_CASE("Test win by second column" )
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();  
	game->start_game("X"); 
	game->mark_board(2); 
	game->mark_board(3); 
	game->mark_board(5);  
	game->mark_board(6); 
	game->mark_board(8);  
	REQUIRE(true == game->game_over());
	REQUIRE(game->get_winner() == "X"); 
}

TEST_CASE("Test win by third column" )
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();  
	game->start_game("X"); 
	game->mark_board(3); 
	game->mark_board(1); 
	game->mark_board(6);  
	game->mark_board(5); 
	game->mark_board(9);  
	REQUIRE(true == game->game_over());
	REQUIRE(game->get_winner() == "X"); 
}

TEST_CASE("Test win by first row" )
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	game->start_game("X"); 
	game->mark_board(1); 
	game->mark_board(3); 
	game->mark_board(2);  
	game->mark_board(6); 
	game->mark_board(3);  
	REQUIRE(true == game->game_over());
	REQUIRE(game->get_winner() == "X"); 
}

TEST_CASE("Test win by second row" )
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();  
	game->start_game("X"); 
	game->mark_board(4); 
	game->mark_board(3); 
	game->mark_board(5);  
	game->mark_board(8); 
	game->mark_board(6);  
	REQUIRE(true == game->game_over());
	REQUIRE(game->get_winner() == "X"); 
}

TEST_CASE("Test win by third row" )
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();  
	game->start_game("X"); 
	game->mark_board(7); 
	game->mark_board(3); 
	game->mark_board(8);  
	game->mark_board(6); 
	game->mark_board(9);  
	REQUIRE(true == game->game_over());
	REQUIRE(game->get_winner() == "X"); 
}

TEST_CASE("Test win diagonally from top left" )
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();  
	game->start_game("X"); 
	game->mark_board(1); 
	game->mark_board(3); 
	game->mark_board(5);  
	game->mark_board(6); 
	game->mark_board(9);  
	REQUIRE(true == game->game_over());
	REQUIRE(game->get_winner() == "X"); 
}

TEST_CASE("Test win diagonally from bottom left" )
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();  
	game->start_game("X"); 
	game->mark_board(7); 
	game->mark_board(2); 
	game->mark_board(5);  
	game->mark_board(6); 
	game->mark_board(3);  
	REQUIRE(true == game->game_over());
	REQUIRE(game->get_winner() == "X"); 
}

TEST_CASE("Test TicTacToe manager") 
{
	int o; int x; int t; 

	TicTacToeManager manager;
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
	manager.save_game(game);
	
	
	game->start_game("O");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
	manager.save_game(game);
	
	
	game->start_game("X");
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
	manager.save_game(game);

	
	game->start_game("O");
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "C");
	manager.save_game(game);

	manager.get_winner_total(o,x,t);
	REQUIRE(o == 1);
	REQUIRE(x == 2);
	REQUIRE(t == 1);
}

TEST_CASE("Test tic tac toe game 4 over for a tie") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(16);
	REQUIRE(game->game_over() == false);
	game->mark_board(12);
	REQUIRE(game->game_over() == false);
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(14);
	REQUIRE(game->game_over() == false);
	game->mark_board(15);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Test 4 first player set to X") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test 4 first player set to O") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test 4 win by first column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(13);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test 4 win by second column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(14);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test 4 win by third column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(15);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test 4 win by fourth column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(12);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test 4 win by first row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test 4 win by second row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test 4 win by third row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(12);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test 4 win by fourth row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(14);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(15);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test 4 win diagonally from top left") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test 4 win diagonally from bottom left") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test 4 TicTacToe manager get winner total function") {
	int o, w, t; // X, O, and tie totals

	TicTacToeManager manager;
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(14);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(15);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
	manager.save_game(game);

	
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(16);
	REQUIRE(game->game_over() == false);
	game->mark_board(12);
	REQUIRE(game->game_over() == false);
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(14);
	REQUIRE(game->game_over() == false);
	game->mark_board(15);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "C");
	manager.save_game(game);

	
	game->start_game("O");
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
	manager.save_game(game);

	manager.get_winner_total(o,w,t);
	REQUIRE(o == 1);
	REQUIRE(w == 1);
	REQUIRE(t == 1);
}

