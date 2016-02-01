#pragma once
#include "Player.h"

#include <vector>

class Board;
class computerPlayer :
	public Player
{
private:
	std::vector<int> m_RowPositions;
	std::vector<int> m_ColPositions;


	int m_AvailablePositions = 0;


	int selectSpawnPos();
	void searchPositions(Board& board);

public:
	void getPosition(Board& board, int& row, int& col);
};

