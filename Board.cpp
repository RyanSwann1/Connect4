#include "stdafx.h"
#include "Board.h"
#include "GameLogic.h"


Board::Board()
{
	initBoard();
}

void Board::initBoard()
{
	std::vector<char> rows(ROWS, EMPTY);
	m_Board = std::vector<std::vector<char>>(COLUMNS, rows);
}

void Board::displayBoard()
{
	int rowText = 1;
	std::cout << "\n";
	std::cout << "\t  ";
	//Display The column Text
	for (int colText = 1; colText < COLUMNS - 1; colText++)
	{
		std::cout << colText << "  ";
	}
	std::cout << "\n";
	//Display the board
	for (int row = 1; row < ROWS - 1; row++)
	{
		std::cout << "\t";
		std::cout << rowText; //Display the row text
		rowText++;

		for (int col = 1; col < COLUMNS - 1; col++)
		{
			std::cout << "|" << m_Board[row][col] << "|";
		}
		std::cout << "\n";
	}
}

bool Board::isMoveLegal(const int row, const int col) const
{
	std::vector<int> fullRow;
	if (getPosition(row, col) == EMPTY)
	{
		//if (row == 1)
		//{
		//	//Search through row, if its full then Game Over - Draw
		//	int row = 0;
		//	int i = 0;
		//	for (int col = 1; col < COLUMNS - 2; col++)
		//	{
		//		if (getPosition(row, col) != EMPTY)
		//		{
		//			i++;
		//		}

		//		if (i == 7)
		//		{
		//			return false;
		//		}
		//	}
		//}

		if (row == ROWS - 2) //If requested move is on the bottom row
			return true;

		else
		{
			//Check to see whether or not the square underneath requested move is not empty
			int tempRow = row;
			tempRow++;
			if (getPosition(tempRow, col) != EMPTY)
				return true;

			else {
				return false;
			}
				
		}
	}

	else {
		return false;
	}
		
	
}

char Board::getPosition(const int row, const int col) const
{
	return m_Board[row][col];
}

void Board::addGamePiece(const int row, const int col, const char gamePiece)
{
	m_Board[row][col] = gamePiece;
}

bool Board::checkForWinner(GameLogic& gameLogic, const char gamePiece)
{
	return 
		searchForWinner(Directions::Horizontal, gameLogic, gamePiece) ||
		searchForWinner(Directions::Vertical, gameLogic, gamePiece) ||
		searchForWinner(Directions::RightDiagonal, gameLogic, gamePiece) || 
		searchForWinner(Directions::LeftDiagonal, gameLogic, gamePiece);
}

char Board::getWinningPiece() const
{
	return m_winningGamePiece;
}

bool Board::searchForWinner(Directions direction, GameLogic& gamelogic, const char gamePiece)
{
	if (!gamelogic.foundWinner())
	{
		int i = 0; //Number of concurrent gamePieces that are being counted to win
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 1; col < COLUMNS; col++)
			{
				//std::cout << "Row: " << row << ". Col: " << col << "\n";
				while (m_Board[row][col] == gamePiece && !gamelogic.foundWinner())
				{
					i++; //Counts game pieces

					//Checks in horizontal direction
					if (direction == Directions::Horizontal)
						col++;

					//Checks in vertical direction
					if (direction == Directions::Vertical)
						row++;

					//Checks in Diagonal direction
					if (direction == Directions::RightDiagonal)
					{
						row++;
						col--;
					}

					if (direction == Directions::LeftDiagonal)
					{
						row++;
						col++;
					}

					if (i == gamelogic.WINNING_ROW)
					{
						m_winningGamePiece = gamePiece;
						return true;
					}

				}
				i = 0; //Reset when on blank square
			}
		}
	}

	//If winner has already been found
	else if (gamelogic.foundWinner())
		return true;

	//If winning row hasn't been found
	return false; 

}
