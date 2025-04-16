#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

#define PROB_NEW_TILE_4 10
#define WIN_NUMBER 2048

struct GameState {
    vector<vector<int> > board;
    int score;
    int turn;
};

class Game {
private:
    int BSIZE;
    vector<vector<int> > board;
    vector<vector<int> > prev_board;
    int turn, score, prev_score;
    vector<GameState> undoStack;

public:
    static const int MAX_UNDO = 5;

    // Constructor takes board size (default is 4)
    Game(int boardSize = 4);

    void print_board();
    void step(char& input);
    bool move(char& input, bool& valid_step);
    bool combine(char& input, bool& valid_step);
    void add_new_tile();
    bool check_win_status();
    bool is_game_over();
    int get_score();
    void undo();

    void save_leaderboard(const string& filename = "leaderboard.txt");
    void print_leaderboard(const string& filename = "leaderboard.txt");
};

#endif
