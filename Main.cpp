// Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include "humanPlayer.h"
#include "GameLogic.h"
#include "computerPlayer.h";

#include <iostream>
#include <vector>
#include <ctime>


int main()
{
	Board board;
	computerPlayer computer;
	humanPlayer player1, player2;
	GameLogic gameLogic;
	
	srand(time(NULL)); 

	gameLogic.game(board, player1, player2, computer, gameLogic);


	char c;
	std::cin >> c;
}

