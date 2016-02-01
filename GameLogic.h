#pragma once

#include <string>

class Board;
class humanPlayer;
class computerPlayer;

class GameLogic
{
private:
	bool m_IsComputerInPlay = false;
	bool m_FoundWinner = false;
	char m_Turn = 'X'; //Starts as 'X' - it being the first turn


	void askFirstTurn(humanPlayer& player1, humanPlayer& player2, computerPlayer& computer);
	void allocateGamePieces(humanPlayer& player1, humanPlayer& player2, computerPlayer& computer, bool firstTurn);
	char changeTurn(char turn);
	bool determineOpponent();
	void announceTurn(const std::string whichPlayer);
	void announceWinner(const humanPlayer& player1, const humanPlayer& player2, const computerPlayer& computer, const Board& board);
	

public:
	static const int WINNING_ROW = 4; //How many of the same game pieces must be aligned to win the game

	void game(Board& board, humanPlayer& player1, humanPlayer& player2, computerPlayer& computer, GameLogic& gameLogic); //Game Loop

	bool isComputerInPlay() const;
	bool foundWinner() const;

};

