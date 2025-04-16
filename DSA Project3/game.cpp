#include "game.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>

extern char get_input();

// A helper function that returns an ANSI background color code
// based on the tile's value. Adjust as you like for different
// color palettes.
std::string tile_color(int val) {
    switch (val) {
        case 2:    return "\033[48;5;230m";  // light color
        case 4:    return "\033[48;5;229m";
        case 8:    return "\033[48;5;221m";
        case 16:   return "\033[48;5;215m";
        case 32:   return "\033[48;5;209m";
        case 64:   return "\033[48;5;203m";
        case 128:  return "\033[48;5;227m";
        case 256:  return "\033[48;5;226m";
        case 512:  return "\033[48;5;220m";
        case 1024: return "\033[48;5;214m";
        case 2048: return "\033[48;5;208m";  
        // Larger tiles
        case 4096: return "\033[48;5;202m";
        case 8192: return "\033[48;5;196m";
        default:   return "\033[48;5;244m";  // fallback grey
    }
}

// The tile text color (foreground). Usually black (30) or white (97).
// We’ll pick black for light backgrounds, white for darker backgrounds:
std::string tile_text_color(int val) {
    // For simplicity, we’ll use black for small tiles,
    // white for big tiles. Adjust threshold or logic as you like.
    if (val <= 4) {
        return "\033[30m"; // black text
    } else {
        return "\033[97m"; // white text
    }
}

Game::Game(int boardSize) : BSIZE(boardSize), turn(1), score(0), prev_score(0) {
    board.assign(BSIZE, std::vector<int>(BSIZE, 0));
    prev_board.assign(BSIZE, std::vector<int>(BSIZE, 0));
    undoStack.clear();
    srand(time(0));
    
    // Place first tile.
    int i = rand() % BSIZE;
    int j = rand() % BSIZE;
    board[i][j] = 2;
    add_new_tile();
}

void Game::step(char& input) {
    // Pause
    if (input == 'p') {
        print_board();
        std::cout << "\n⏸️  Paused. Press any key to continue...\n";
        get_input();
        return;
    }
    // Undo
    if (input == 'u') {
        if (!undoStack.empty()) {
            GameState state = undoStack.back();
            undoStack.pop_back();
            board = state.board;
            score = state.score;
            turn = state.turn;
            std::cout << "\a"; 
        }
        return;
    }
    
    // Save state before move
    GameState state{board, score, turn};
    undoStack.push_back(state);
    if (undoStack.size() > MAX_UNDO)
        undoStack.erase(undoStack.begin());
    
    bool valid_step = false;
    move(input, valid_step);
    combine(input, valid_step);
    if (valid_step) {
        move(input, valid_step);
        add_new_tile();
        ++turn;
        std::cout << "\a"; // beep after a valid move
    }
}

bool Game::move(char& input, bool& valid_step) {
    valid_step = false;
    if (input == 'w') {
        for (int col = 0; col < BSIZE; col++) {
            for (int row = 1; row < BSIZE; row++) {
                if (board[row][col] == 0) continue;
                int r = row;
                while (r > 0 && board[r - 1][col] == 0) {
                    std::swap(board[r - 1][col], board[r][col]);
                    r--;
                    valid_step = true;
                }
            }
        }
    }
    else if (input == 's') {
        for (int col = 0; col < BSIZE; col++) {
            for (int row = BSIZE - 2; row >= 0; row--) {
                if (board[row][col] == 0) continue;
                int r = row;
                while (r < BSIZE - 1 && board[r + 1][col] == 0) {
                    std::swap(board[r + 1][col], board[r][col]);
                    r++;
                    valid_step = true;
                }
            }
        }
    }
    else if (input == 'a') {
        for (int row = 0; row < BSIZE; row++) {
            for (int col = 1; col < BSIZE; col++) {
                if (board[row][col] == 0) continue;
                int c = col;
                while (c > 0 && board[row][c - 1] == 0) {
                    std::swap(board[row][c - 1], board[row][c]);
                    c--;
                    valid_step = true;
                }
            }
        }
    }
    else if (input == 'd') {
        for (int row = 0; row < BSIZE; row++) {
            for (int col = BSIZE - 2; col >= 0; col--) {
                if (board[row][col] == 0) continue;
                int c = col;
                while (c < BSIZE - 1 && board[row][c + 1] == 0) {
                    std::swap(board[row][c + 1], board[row][c]);
                    c++;
                    valid_step = true;
                }
            }
        }
    }
    return valid_step;
}

bool Game::combine(char& input, bool& valid_step) {
    if (input == 'w') {
        for (int col = 0; col < BSIZE; col++) {
            for (int row = 0; row < BSIZE - 1; row++) {
                if (board[row][col] != 0 && board[row][col] == board[row + 1][col]) {
                    board[row][col] *= 2;
                    board[row + 1][col] = 0;
                    score += board[row][col];
                    valid_step = true;
                }
            }
        }
    }
    else if (input == 's') {
        for (int col = 0; col < BSIZE; col++) {
            for (int row = BSIZE - 1; row > 0; row--) {
                if (board[row][col] != 0 && board[row][col] == board[row - 1][col]) {
                    board[row][col] *= 2;
                    board[row - 1][col] = 0;
                    score += board[row][col];
                    valid_step = true;
                }
            }
        }
    }
    else if (input == 'a') {
        for (int row = 0; row < BSIZE; row++) {
            for (int col = 0; col < BSIZE - 1; col++) {
                if (board[row][col] != 0 && board[row][col] == board[row][col + 1]) {
                    board[row][col] *= 2;
                    board[row][col + 1] = 0;
                    score += board[row][col];
                    valid_step = true;
                }
            }
        }
    }
    else if (input == 'd') {
        for (int row = 0; row < BSIZE; row++) {
            for (int col = BSIZE - 1; col > 0; col--) {
                if (board[row][col] != 0 && board[row][col] == board[row][col - 1]) {
                    board[row][col] *= 2;
                    board[row][col - 1] = 0;
                    score += board[row][col];
                    valid_step = true;
                }
            }
        }
    }
    return valid_step;
}

void Game::add_new_tile() {
    std::vector<std::pair<int, int>> empty;
    for (int i = 0; i < BSIZE; ++i)
        for (int j = 0; j < BSIZE; ++j)
            if (board[i][j] == 0)
                empty.push_back({i, j});

    if (empty.empty()) return;
    auto [x, y] = empty[rand() % empty.size()];
    board[x][y] = (rand() % 100 < PROB_NEW_TILE_4) ? 4 : 2;
}

// 🟨 The function that prints the color-coded tiles
void Game::print_board() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    std::cout << "\n\033[1;36m2048\033[0m\n\n";
    for (int i = 0; i < BSIZE; i++) {
        std::cout << "\t";
        for (int j = 0; j < BSIZE; j++) {
            int val = board[i][j];
            if (val == 0) {
                // No tile => print empty space
                std::cout << "  .   ";
            } else {
                // Print tile in color-coded background + text color
                std::string bg = tile_color(val);
                std::string fg = tile_text_color(val);

                // e.g. "  4   "
                // You can tweak spacing so the tile is well-centered
                // \033[0m resets color
                std::cout << bg << fg << "  " 
                          << std::setw(4) << val 
                          << " " << "\033[0m";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\nScore: " << score << " | Turn: " << turn << "\n";
}

bool Game::check_win_status() {
    for (auto& row : board)
        for (int val : row)
            if (val == WIN_NUMBER)
                return true;
    return false;
}

bool Game::is_game_over() {
    // If there's an empty cell, not over
    for (int i = 0; i < BSIZE; i++)
        for (int j = 0; j < BSIZE; j++)
            if (board[i][j] == 0)
                return false;

    // Check if merges are possible
    for (int i = 0; i < BSIZE; i++) {
        for (int j = 0; j < BSIZE; j++) {
            if (i + 1 < BSIZE && board[i][j] == board[i + 1][j]) return false;
            if (j + 1 < BSIZE && board[i][j] == board[i][j + 1]) return false;
        }
    }
    return true;
}

int Game::get_score() {
    return score;
}

void Game::save_leaderboard(const std::string& filename) {
    std::ofstream out(filename, std::ios::app);
    out << score << "\n";
    out.close();
}

void Game::print_leaderboard(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return;
    std::vector<int> scores;
    int s;
    while (in >> s)
        scores.push_back(s);
    in.close();

    std::sort(scores.begin(), scores.end(), std::greater<int>());
    std::cout << "\n🏆 Leaderboard (Top 5 Scores):\n";
    for (size_t i = 0; i < std::min<size_t>(5, scores.size()); i++)
        std::cout << "  " << i + 1 << ". " << scores[i] << "\n";
}

void Game::undo() {
    // Not needed, handled in step()
}
