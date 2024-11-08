#pragma once

#include "Game.h"

class TicTacToe : public Game
{
private:

	char m_board[9] = {'1','2','3','4','5','6','7','8','9'};
	int m_player = 1;
	int m_turn = 1;

public:

	TicTacToe(){}
	~TicTacToe(){}

	virtual bool IsGameOver() const;
	virtual void TakeTurn();
	virtual void Display() const;
};