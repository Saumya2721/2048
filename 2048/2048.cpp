#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "game.h"

using namespace std;

int main() {
    cout << "HI! WELCOME TO '2048' GAME!" << endl
         << "Your goal is to reach 2048 on any tile." << endl
         << "Use keys 'w','a','s','d' to move tiles up, left, down, right respectively" << endl
         << "Good luck and don't get stuck in an unmovable board!" << endl;
    srand(time(NULL));
    Game game;
    cout << game;
    char input;
    cin >> input;
    while (input != '.') {
        game.step(input);
        cout << game;
        if (game.check_win_status()) {
            cout << "Congratualtions! You have won!" << endl
                 << "You final score is: " << game.get_score() << endl;
            return 0;
        }
        cin >> input;
    }

    return 0;
}
