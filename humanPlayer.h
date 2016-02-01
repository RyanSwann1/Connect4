#pragma once
#include "Player.h"

#include <string>

class Board;
class humanPlayer :
	public Player
{
public:

	int getPosition(const std::string direction, int size) const;
};

