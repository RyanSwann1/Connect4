#pragma once
#include <string>

class Board;
class humanPlayer;
class GameLogic;
class computerPlayer;

class Player
{
private:
	char m_GamePiece = ' ';
	int m_Score = 0;

public:

	void takeTurn(humanPlayer& humanPlayer, Board& board, GameLogic& gameLogic, computerPlayer& computer, std::string turn);
	void setGamePiece(const char gamePiece);
	void setScore(const int score);

	int getScore() const;
	char getGamePiece() const;

};

