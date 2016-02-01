#include "stdafx.h"
#include "humanPlayer.h"
#include "Board.h"


int humanPlayer::getPosition(const std::string direction, int size) const
{
	bool positionAllowed = false;
	int pos = 0;
	std::cout << "Enter " << direction << ".";
	while (!positionAllowed)
	{
		std::cin >> pos;
		if (direction == "Row")
		{
			if (pos > 0 && pos < size - 1)
				positionAllowed = true;
			else
				std::cout << "Position is out of bounds.";
		}
		else
		{
			if (pos > 0 && pos < size - 1)
				positionAllowed = true;
			else
				std::cout << "Position is out of bounds.";
		}

	}

	return pos;
}
