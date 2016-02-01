#include "stdafx.h"
#include "Player.h"
#include "humanPlayer.h"
#include "Board.h"
#include "GameLogic.h"
#include "computerPlayer.h"


void Player::takeTurn(humanPlayer& humanPlayer, Board& board, GameLogic& gameLogic, computerPlayer& computer, std::string turn)
{
	bool moveComplete = false;
	int row = 0;
	int col = 0;

	while (!moveComplete)
	{
		if (turn == "Computer")
		{
			computer.getPosition(board, row, col);
		}

		else
		{
			row = humanPlayer.getPosition("Row", Board::ROWS);
			col = humanPlayer.getPosition("Colum", Board::COLUMNS);
		}

		//Place on board
		if (board.isMoveLegal(row, col))
		{
			board.addGamePiece(row, col, getGamePiece());
			moveComplete = true;

		}
			
		else
			std::cout << "You cannot move there.";
	}

}

char Player::getGamePiece() const
{
	return m_GamePiece;
}

void Player::setGamePiece(const char gamePiece)
{
	m_GamePiece = gamePiece;
}
