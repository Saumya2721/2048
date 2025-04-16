#include "game.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#include <iostream>
using namespace std;

// get_input() function supports arrow keys and WASD keys.
char get_input() {
#ifdef _WIN32
    char ch = _getch();
    if (ch == 0 || ch == -32) {
        char arrow = _getch();
        switch (arrow) {
            case 72: return 'w';
            case 80: return 's';
            case 75: return 'a';
            case 77: return 'd';
            default: return ch;
        }
    }
    return ch;
#else
    char ch = 0;
    struct termios old = {};
    tcgetattr(STDIN_FILENO, &old);
    struct termios newt = old;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    read(STDIN_FILENO, &ch, 1);
    if (ch == '\033') {
        char seq[2];
        read(STDIN_FILENO, &seq[0], 1);
        read(STDIN_FILENO, &seq[1], 1);
        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': ch = 'w'; break;
                case 'B': ch = 's'; break;
                case 'C': ch = 'd'; break;
                case 'D': ch = 'a'; break;
            }
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    return ch;
#endif
}

int main() {
    char input;
    bool play_again = true;

    int boardSize;
    cout << "Welcome to 2048!\n";
    cout << "Choose board size (e.g., 4 or 5): ";
    cin >> boardSize;
    cin.ignore();

    while (play_again) {
        Game game(boardSize);
        bool restart_game = false;

        while (true) {
            game.print_board();
            cout << "============ CONTROLS ============\n";
            cout << "WASD / Arrow Keys: Move\n";
            cout << "U: Undo | P: Pause | R: Restart | Q: Quit\n";
            cout << "Goal: Reach " << WIN_NUMBER << "\n";
            cout << "==================================\n\n";

            input = get_input();
            if (input == 'q') break;
            if (input == 'r') {
                restart_game = true;
                break;
            }

            game.step(input);

            if (game.check_win_status()) {
                game.print_board();
                cout << "\n🎉 You reached " << WIN_NUMBER << "! 🎉\a\n";
                break;
            }
            if (game.is_game_over()) {
                game.print_board();
                cout << "\n😢 No moves left! Game over.\a\n";
                break;
            }
        }

        game.save_leaderboard();
        game.print_leaderboard();

        cout << "\nPlay again? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
            play_again = false;
    }

    return 0;
}
