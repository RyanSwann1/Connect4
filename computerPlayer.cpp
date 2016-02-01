#include "stdafx.h"
#include "computerPlayer.h"
#include "Board.h"




void computerPlayer::getPosition(Board& board, int& row, int& col)
{
	//Get all possible movement positions
	searchPositions(board);

	//Get random position to spawn on
	int spawnPos = selectSpawnPos();


	row = m_RowPositions[spawnPos];
	col = m_ColPositions[spawnPos];


	//Reset all 
	m_RowPositions.clear();
	m_ColPositions.clear();
	m_AvailablePositions = 0;
}



int computerPlayer::selectSpawnPos()
{
	//Change number depending on how many columns arent full 
	int randPos = rand() %  m_AvailablePositions;

	return randPos;
}

void computerPlayer::searchPositions(Board& board)
{
	for (int col = 1; col < Board::COLUMNS - 1; col++)
	{
		for (int row = Board::ROWS - 2; row > 0; row--)
		{
				if (board.getPosition(row, col) == Board::EMPTY)
				{
					m_RowPositions.push_back(row);
					m_ColPositions.push_back(col);
					m_AvailablePositions++;
					break; //Move onto next col
				}
		}
	}
}
