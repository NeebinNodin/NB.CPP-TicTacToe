
#include "TicTacToe.h"
#include <iostream>
//#include <limits> not covered in class

bool TicTacToe::IsGameOver() const
{
	// Check for a win, 8 possible ways
	// 012
	// 345
	// 678
	if((m_board[0] == m_board[1] && m_board[1] == m_board[2] && m_board[0] != ' ')
		|| (m_board[3] == m_board[4] && m_board[4] == m_board[5] && m_board[3] != ' ')
		|| (m_board[6] == m_board[7] && m_board[7] == m_board[8] && m_board[6] != ' ')
		|| (m_board[0] == m_board[3] && m_board[3] == m_board[6] && m_board[0] != ' ')
		|| (m_board[1] == m_board[4] && m_board[4] == m_board[7] && m_board[1] != ' ')
		|| (m_board[2] == m_board[5] && m_board[5] == m_board[8] && m_board[2] != ' ')
		|| (m_board[0] == m_board[4] && m_board[4] == m_board[8] && m_board[0] != ' ')
		|| (m_board[2] == m_board[4] && m_board[4] == m_board[6] && m_board[2] != ' '))
	{
		// determine who won
		if(m_player == 1) std::cout << "Player 2 wins!\n";
		else std::cout << "Player 1 wins!\n";
		return true;
	}
	else if(m_turn == 9)
	{
		// if 9 turns is reached, game ends in a tie since there are no more moves available
		std::cout << "The game has ended in a tie!\n";
		return true;
	}
	else return false;
}

void TicTacToe::TakeTurn()
{
	int move = 0;
	bool validMove = false;
	while(!validMove)
	{
		// Ask player to enter a move
		std::cout << "Player " << m_player << " enter a move: ";
		std::cin >> move;

		/*input validation if a char/string is entered
		not covered in class so commented out. Does work though.
		
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, please enter a number between 1 and 9.\n";
			continue;
		}
		*/

		if (move < 1 || move > 9){std::cout << "Invalid move, try again.\n";}
		else if(m_board[move - 1] == 'X' || m_board[move - 1] == 'O')
		{
			std::cout << "That space is already taken, try again.\n";
		}
		else
		{
			m_board[move - 1] = (m_player == 1) ? 'X' : 'O'; // Place player's symbol on board
			m_player = (m_player == 1) ? 2 : 1; // switch players for each turn
			m_turn++;
			validMove = true;
		}
	}
}

void TicTacToe::Display() const
{
	system("cls"); // clears the display and displays the move player just made.
	std::cout << m_board[0] << " | " << m_board[1] << " | " << m_board[2] << "\n";
	std::cout << "---------\n";
	std::cout << m_board[3] << " | " << m_board[4] << " | " << m_board[5] << "\n";
	std::cout << "---------\n";
	std::cout << m_board[6] << " | " << m_board[7] << " | " << m_board[8] << "\n";
}