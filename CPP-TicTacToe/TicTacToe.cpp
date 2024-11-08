
#include "TicTacToe.h"
#include <iostream>

bool TicTacToe::IsGameOver() const
{
	// Check for a win, 8 possible ways
	// 012
	// 345
	// 678
	if((m_board[0] == m_board[1] && m_board[1] == m_board[2])
		|| (m_board[3] == m_board[4] && m_board[4] == m_board[5])
		|| (m_board[6] == m_board[7] && m_board[7] == m_board[8])
		|| (m_board[0] == m_board[3] && m_board[3] == m_board[6])
		|| (m_board[1] == m_board[4] && m_board[4] == m_board[7])
		|| (m_board[2] == m_board[5] && m_board[5] == m_board[8])
		|| (m_board[0] == m_board[4] && m_board[4] == m_board[8])
		|| (m_board[2] == m_board[4] && m_board[4] == m_board[6]))
	{
		std::cout << "Player " << m_player << " wint!\n";
		return true;
	}
	else if(m_turn == 9)
	{
		std::cout << "The game has ended in a tie!\n";
	}
	else return false;
		
	
}

void TicTacToe::TakeTurn()
{
	int move = 0;
	bool validMove = false;
	while(!validMove)
	{
		std::cout << "Player " << m_player << " enter a move: ";
		std::cin >> move;
		if (move < 1 || move > 9)
		{
			std::cout << "Invalid move, try again.\n";
		}
		else if(m_board[move - 1] == 'X' || m_board[move - 1] == 'O')
		{
			std::cout << "That space is already taken, try again.\n";
		}
		else
		{
			m_board[move - 1] = (m_player == 1) ? 'X' : 'O';
			m_player = (m_player == 1) ? 2 : 1;
			m_turn++;
			validMove = true;
		}
	}
}

void TicTacToe::Display() const
{
	system("cls");
	std::cout << m_board[0] << " | " << m_board[1] << " | " << m_board[2] << "\n";
	std::cout << "---------\n";
	std::cout << m_board[3] << " | " << m_board[4] << " | " << m_board[5] << "\n";
	std::cout << "---------\n";
	std::cout << m_board[6] << " | " << m_board[7] << " | " << m_board[8] << "\n";
}