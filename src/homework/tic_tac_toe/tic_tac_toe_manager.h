//h
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <memory>

using std::unique_ptr;
using std::make_unique;

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class TicTacToeManager 
{
    public:
    TicTacToeManager(TicTacToeData data);
    void save_game(unique_ptr<TicTacToe> &game);
    friend std::ostream& operator<<(std::ostream & out, const TicTacToeManager & manager); 
    void get_winner_total(int& o, int& x, int& t);
    ~TicTacToeManager();

    private:
    std::vector<std::unique_ptr<TicTacToe>> games;
    TicTacToeData data;
    int x_win{0};
    int o_win{0};
    int ties{0};
    void update_winner_count(std::string winner);
};

#endif 