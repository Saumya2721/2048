#include "stdafx.h"
#include "CppUnitTest.h"
#define private public // to access private members
#include "game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2048Tests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(MovingUP)
		{
            Game g_actual;
            g_actual.board[0][0] = 2;
            g_actual.board[0][1] = 0;
            g_actual.board[0][2] = 0;
            g_actual.board[0][3] = 0;
            g_actual.board[1][0] = 0;
            g_actual.board[1][1] = 4;
            g_actual.board[1][2] = 0;
            g_actual.board[1][3] = 4;
            g_actual.board[2][0] = 0;
            g_actual.board[2][1] = 0;
            g_actual.board[2][2] = 8;
            g_actual.board[2][3] = 0;
            g_actual.board[3][0] = 0;
            g_actual.board[3][1] = 0;
            g_actual.board[3][2] = 8;
            g_actual.board[3][3] = 16;
            
            char input = 'w';
            bool valid_step = false;
            g_actual.move(input, valid_step);

            Assert::AreEqual(true, valid_step);

            Assert::AreEqual(g_actual.board[0][0], 2);
            Assert::AreEqual(g_actual.board[0][1], 4);
            Assert::AreEqual(g_actual.board[0][2], 8);
            Assert::AreEqual(g_actual.board[0][3], 4);
            Assert::AreEqual(g_actual.board[1][0], 0);
            Assert::AreEqual(g_actual.board[1][1], 0);
            Assert::AreEqual(g_actual.board[1][2], 8);
            Assert::AreEqual(g_actual.board[1][3], 16);
            Assert::AreEqual(g_actual.board[2][0], 0);
            Assert::AreEqual(g_actual.board[2][1], 0);
            Assert::AreEqual(g_actual.board[2][2], 0);
            Assert::AreEqual(g_actual.board[2][3], 0);
            Assert::AreEqual(g_actual.board[3][0], 0);
            Assert::AreEqual(g_actual.board[3][1], 0);
            Assert::AreEqual(g_actual.board[3][2], 0);
            Assert::AreEqual(g_actual.board[3][3], 0);
		}

        TEST_METHOD(MovingDOWN)
        {
            Game g_actual;
            g_actual.board[0][0] = 2;
            g_actual.board[0][1] = 0;
            g_actual.board[0][2] = 0;
            g_actual.board[0][3] = 0;
            g_actual.board[1][0] = 0;
            g_actual.board[1][1] = 4;
            g_actual.board[1][2] = 0;
            g_actual.board[1][3] = 4;
            g_actual.board[2][0] = 0;
            g_actual.board[2][1] = 0;
            g_actual.board[2][2] = 8;
            g_actual.board[2][3] = 0;
            g_actual.board[3][0] = 0;
            g_actual.board[3][1] = 0;
            g_actual.board[3][2] = 8;
            g_actual.board[3][3] = 16;

            char input = 's';
            bool valid_step = false;
            g_actual.move(input, valid_step);

            Assert::AreEqual(true, valid_step);

            Assert::AreEqual(g_actual.board[0][0], 0);
            Assert::AreEqual(g_actual.board[0][1], 0);
            Assert::AreEqual(g_actual.board[0][2], 0);
            Assert::AreEqual(g_actual.board[0][3], 0);
            Assert::AreEqual(g_actual.board[1][0], 0);
            Assert::AreEqual(g_actual.board[1][1], 0);
            Assert::AreEqual(g_actual.board[1][2], 0);
            Assert::AreEqual(g_actual.board[1][3], 0);
            Assert::AreEqual(g_actual.board[2][0], 0);
            Assert::AreEqual(g_actual.board[2][1], 0);
            Assert::AreEqual(g_actual.board[2][2], 8);
            Assert::AreEqual(g_actual.board[2][3], 4);
            Assert::AreEqual(g_actual.board[3][0], 2);
            Assert::AreEqual(g_actual.board[3][1], 4);
            Assert::AreEqual(g_actual.board[3][2], 8);
            Assert::AreEqual(g_actual.board[3][3], 16);
        }

        TEST_METHOD(MovingLEFT)
        {
            Game g_actual;
            g_actual.board[0][0] = 2;
            g_actual.board[0][1] = 0;
            g_actual.board[0][2] = 0;
            g_actual.board[0][3] = 0;
            g_actual.board[1][0] = 0;
            g_actual.board[1][1] = 4;
            g_actual.board[1][2] = 0;
            g_actual.board[1][3] = 4;
            g_actual.board[2][0] = 0;
            g_actual.board[2][1] = 0;
            g_actual.board[2][2] = 8;
            g_actual.board[2][3] = 0;
            g_actual.board[3][0] = 0;
            g_actual.board[3][1] = 0;
            g_actual.board[3][2] = 8;
            g_actual.board[3][3] = 16;

            char input = 'a';
            bool valid_step = false;
            g_actual.move(input, valid_step);

            Assert::AreEqual(true, valid_step);

            Assert::AreEqual(g_actual.board[0][0], 2);
            Assert::AreEqual(g_actual.board[0][1], 0);
            Assert::AreEqual(g_actual.board[0][2], 0);
            Assert::AreEqual(g_actual.board[0][3], 0);
            Assert::AreEqual(g_actual.board[1][0], 4);
            Assert::AreEqual(g_actual.board[1][1], 4);
            Assert::AreEqual(g_actual.board[1][2], 0);
            Assert::AreEqual(g_actual.board[1][3], 0);
            Assert::AreEqual(g_actual.board[2][0], 8);
            Assert::AreEqual(g_actual.board[2][1], 0);
            Assert::AreEqual(g_actual.board[2][2], 0);
            Assert::AreEqual(g_actual.board[2][3], 0);
            Assert::AreEqual(g_actual.board[3][0], 8);
            Assert::AreEqual(g_actual.board[3][1], 16);
            Assert::AreEqual(g_actual.board[3][2], 0);
            Assert::AreEqual(g_actual.board[3][3], 0);
        }

        TEST_METHOD(MovingRIGHT)
        {
            Game g_actual;
            g_actual.board[0][0] = 2;
            g_actual.board[0][1] = 0;
            g_actual.board[0][2] = 0;
            g_actual.board[0][3] = 0;
            g_actual.board[1][0] = 0;
            g_actual.board[1][1] = 4;
            g_actual.board[1][2] = 0;
            g_actual.board[1][3] = 4;
            g_actual.board[2][0] = 0;
            g_actual.board[2][1] = 0;
            g_actual.board[2][2] = 8;
            g_actual.board[2][3] = 0;
            g_actual.board[3][0] = 0;
            g_actual.board[3][1] = 0;
            g_actual.board[3][2] = 8;
            g_actual.board[3][3] = 16;

            char input = 'd';
            bool valid_step = false;
            g_actual.move(input, valid_step);

            Assert::AreEqual(true, valid_step);

            Assert::AreEqual(g_actual.board[0][0], 0);
            Assert::AreEqual(g_actual.board[0][1], 0);
            Assert::AreEqual(g_actual.board[0][2], 0);
            Assert::AreEqual(g_actual.board[0][3], 2);
            Assert::AreEqual(g_actual.board[1][0], 0);
            Assert::AreEqual(g_actual.board[1][1], 0);
            Assert::AreEqual(g_actual.board[1][2], 4);
            Assert::AreEqual(g_actual.board[1][3], 4);
            Assert::AreEqual(g_actual.board[2][0], 0);
            Assert::AreEqual(g_actual.board[2][1], 0);
            Assert::AreEqual(g_actual.board[2][2], 0);
            Assert::AreEqual(g_actual.board[2][3], 8);
            Assert::AreEqual(g_actual.board[3][0], 0);
            Assert::AreEqual(g_actual.board[3][1], 0);
            Assert::AreEqual(g_actual.board[3][2], 8);
            Assert::AreEqual(g_actual.board[3][3], 16);
        }

        TEST_METHOD(CombineUP)
        {
            Game g_actual;
            g_actual.board[0][0] = 2;
            g_actual.board[0][1] = 8;
            g_actual.board[0][2] = 4;
            g_actual.board[0][3] = 8;
            g_actual.board[1][0] = 2;
            g_actual.board[1][1] = 8;
            g_actual.board[1][2] = 0;
            g_actual.board[1][3] = 4;
            g_actual.board[2][0] = 4;
            g_actual.board[2][1] = 0;
            g_actual.board[2][2] = 0;
            g_actual.board[2][3] = 4;
            g_actual.board[3][0] = 4;
            g_actual.board[3][1] = 0;
            g_actual.board[3][2] = 0;
            g_actual.board[3][3] = 0;

            char input = 'w';
            bool valid_step = false;
            g_actual.combine(input, valid_step);

            Assert::AreEqual(true, valid_step);

            Assert::AreEqual(g_actual.board[0][0], 4);
            Assert::AreEqual(g_actual.board[0][1], 16);
            Assert::AreEqual(g_actual.board[0][2], 4);
            Assert::AreEqual(g_actual.board[0][3], 8);
            Assert::AreEqual(g_actual.board[1][0], 0);
            Assert::AreEqual(g_actual.board[1][1], 0);
            Assert::AreEqual(g_actual.board[1][2], 0);
            Assert::AreEqual(g_actual.board[1][3], 8);
            Assert::AreEqual(g_actual.board[2][0], 8);
            Assert::AreEqual(g_actual.board[2][1], 0);
            Assert::AreEqual(g_actual.board[2][2], 0);
            Assert::AreEqual(g_actual.board[2][3], 0);
            Assert::AreEqual(g_actual.board[3][0], 0);
            Assert::AreEqual(g_actual.board[3][1], 0);
            Assert::AreEqual(g_actual.board[3][2], 0);
            Assert::AreEqual(g_actual.board[3][3], 0);
        }

        TEST_METHOD(CombineDOWN)
        {
            Game g_actual;
            g_actual.board[0][0] = 4;
            g_actual.board[0][1] = 0;
            g_actual.board[0][2] = 0;
            g_actual.board[0][3] = 0;
            g_actual.board[1][0] = 4;
            g_actual.board[1][1] = 0;
            g_actual.board[1][2] = 0;
            g_actual.board[1][3] = 8;
            g_actual.board[2][0] = 4;
            g_actual.board[2][1] = 8;
            g_actual.board[2][2] = 0;
            g_actual.board[2][3] = 4;
            g_actual.board[3][0] = 4;
            g_actual.board[3][1] = 8;
            g_actual.board[3][2] = 4;
            g_actual.board[3][3] = 4;

            char input = 's';
            bool valid_step = false;
            g_actual.combine(input, valid_step);

            Assert::AreEqual(true, valid_step);

            Assert::AreEqual(g_actual.board[0][0], 0);
            Assert::AreEqual(g_actual.board[0][1], 0);
            Assert::AreEqual(g_actual.board[0][2], 0);
            Assert::AreEqual(g_actual.board[0][3], 0);
            Assert::AreEqual(g_actual.board[1][0], 8);
            Assert::AreEqual(g_actual.board[1][1], 0);
            Assert::AreEqual(g_actual.board[1][2], 0);
            Assert::AreEqual(g_actual.board[1][3], 8);
            Assert::AreEqual(g_actual.board[2][0], 0);
            Assert::AreEqual(g_actual.board[2][1], 0);
            Assert::AreEqual(g_actual.board[2][2], 0);
            Assert::AreEqual(g_actual.board[2][3], 0);
            Assert::AreEqual(g_actual.board[3][0], 8);
            Assert::AreEqual(g_actual.board[3][1], 16);
            Assert::AreEqual(g_actual.board[3][2], 4);
            Assert::AreEqual(g_actual.board[3][3], 8);
        }

        TEST_METHOD(CombineLEFT)
        {
            Game g_actual;
            g_actual.board[0][0] = 4;
            g_actual.board[0][1] = 4;
            g_actual.board[0][2] = 4;
            g_actual.board[0][3] = 4;
            g_actual.board[1][0] = 8;
            g_actual.board[1][1] = 8;
            g_actual.board[1][2] = 0;
            g_actual.board[1][3] = 0;
            g_actual.board[2][0] = 4;
            g_actual.board[2][1] = 0;
            g_actual.board[2][2] = 0;
            g_actual.board[2][3] = 0;
            g_actual.board[3][0] = 4;
            g_actual.board[3][1] = 4;
            g_actual.board[3][2] = 8;
            g_actual.board[3][3] = 0;

            char input = 'a';
            bool valid_step = false;
            g_actual.combine(input, valid_step);

            Assert::AreEqual(true, valid_step);

            Assert::AreEqual(g_actual.board[0][0], 8);
            Assert::AreEqual(g_actual.board[0][1], 0);
            Assert::AreEqual(g_actual.board[0][2], 8);
            Assert::AreEqual(g_actual.board[0][3], 0);
            Assert::AreEqual(g_actual.board[1][0], 16);
            Assert::AreEqual(g_actual.board[1][1], 0);
            Assert::AreEqual(g_actual.board[1][2], 0);
            Assert::AreEqual(g_actual.board[1][3], 0);
            Assert::AreEqual(g_actual.board[2][0], 4);
            Assert::AreEqual(g_actual.board[2][1], 0);
            Assert::AreEqual(g_actual.board[2][2], 0);
            Assert::AreEqual(g_actual.board[2][3], 0);
            Assert::AreEqual(g_actual.board[3][0], 8);
            Assert::AreEqual(g_actual.board[3][1], 0);
            Assert::AreEqual(g_actual.board[3][2], 8);
            Assert::AreEqual(g_actual.board[3][3], 0);
        }

        TEST_METHOD(CombineRIGHT)
        {
            Game g_actual;
            g_actual.board[0][0] = 0;
            g_actual.board[0][1] = 8;
            g_actual.board[0][2] = 4;
            g_actual.board[0][3] = 4;
            g_actual.board[1][0] = 0;
            g_actual.board[1][1] = 0;
            g_actual.board[1][2] = 0;
            g_actual.board[1][3] = 4;
            g_actual.board[2][0] = 0;
            g_actual.board[2][1] = 0;
            g_actual.board[2][2] = 8;
            g_actual.board[2][3] = 8;
            g_actual.board[3][0] = 4;
            g_actual.board[3][1] = 4;
            g_actual.board[3][2] = 4;
            g_actual.board[3][3] = 4;

            char input = 'd';
            bool valid_step = false;
            g_actual.combine(input, valid_step);

            Assert::AreEqual(true, valid_step);

            Assert::AreEqual(g_actual.board[0][0], 0);
            Assert::AreEqual(g_actual.board[0][1], 8);
            Assert::AreEqual(g_actual.board[0][2], 0);
            Assert::AreEqual(g_actual.board[0][3], 8);
            Assert::AreEqual(g_actual.board[1][0], 0);
            Assert::AreEqual(g_actual.board[1][1], 0);
            Assert::AreEqual(g_actual.board[1][2], 0);
            Assert::AreEqual(g_actual.board[1][3], 4);
            Assert::AreEqual(g_actual.board[2][0], 0);
            Assert::AreEqual(g_actual.board[2][1], 0);
            Assert::AreEqual(g_actual.board[2][2], 0);
            Assert::AreEqual(g_actual.board[2][3], 16);
            Assert::AreEqual(g_actual.board[3][0], 0);
            Assert::AreEqual(g_actual.board[3][1], 8);
            Assert::AreEqual(g_actual.board[3][2], 0);
            Assert::AreEqual(g_actual.board[3][3], 8);
        }

        TEST_METHOD(Add_New_Tile_test)
        {
            Game g;
            g.board[0][0] = 0;
            g.board[0][1] = 8;
            g.board[0][2] = 4;
            g.board[0][3] = 4;
            g.board[1][0] = 0;
            g.board[1][1] = 0;
            g.board[1][2] = 0;
            g.board[1][3] = 4;
            g.board[2][0] = 0;
            g.board[2][1] = 0;
            g.board[2][2] = 8;
            g.board[2][3] = 8;
            g.board[3][0] = 4;
            g.board[3][1] = 4;
            g.board[3][2] = 4;
            g.board[3][3] = 4;

            int number_of_tiles = 0;
            for (int i = 0; i < Game::BSIZE; ++i) {
                for (int j = 0; j < Game::BSIZE; ++j) {
                    if (g.board[i][j] != 0) {
                        ++number_of_tiles; // count number of non-empty tiles
                    }
                }
            }
            
            g.add_new_tile();
            int expected_number_of_tiles = number_of_tiles + 1;
            
            number_of_tiles = 0; // reset and count again
            for (int i = 0; i < Game::BSIZE; ++i) {
                for (int j = 0; j < Game::BSIZE; ++j) {
                    if (g.board[i][j] != 0) {
                        ++number_of_tiles;
                    }
                }
            }

            Assert::AreEqual(expected_number_of_tiles, number_of_tiles);
        }

        TEST_METHOD(WINNING_CONDITION)
        {
            Game g_actual;
            g_actual.board[0][0] = 2;
            g_actual.board[0][1] = 0;
            g_actual.board[0][2] = 0;
            g_actual.board[0][3] = 0;
            g_actual.board[1][0] = 0;
            g_actual.board[1][1] = 4;
            g_actual.board[1][2] = 8;
            g_actual.board[1][3] = 4;
            g_actual.board[2][0] = 0;
            g_actual.board[2][1] = 0;
            g_actual.board[2][2] = 8;
            g_actual.board[2][3] = 0;
            g_actual.board[3][0] = 0;
            g_actual.board[3][1] = 0;
            g_actual.board[3][2] = 8;
            g_actual.board[3][3] = 16;


            Assert::AreEqual(false, g_actual.check_win_status());

            g_actual.board[2][2] = Game::WIN_NUMBER;

            Assert::AreEqual(true, g_actual.check_win_status());
        }
	};
}