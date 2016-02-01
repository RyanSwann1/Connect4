#pragma once

#include <iostream>
#include <vector>

enum class Directions
{
	Horizontal,
	Vertical,
	RightDiagonal,  
	LeftDiagonal 
};

class GameLogic;
class Board
{
private:
	std::vector<std::vector<char>> m_Board;
	char m_winningGamePiece = ' ';

	void initBoard();
	bool searchForWinner(Directions direction, GameLogic& gameLogic, const char gamePiece);

public:
	static const int ROWS = 9;
	static const int COLUMNS = 9;

	static const char X = 'X';
	static const char O = 'O';
	static const char EMPTY = ' ';

	Board();

	void displayBoard();
	bool isMoveLegal(const int row, const int col) const;
	char getPosition(const int row, const int col) const;
	void addGamePiece(const int row, const int col, const char gamePiece);
	bool checkForWinner(GameLogic& gameLogic, const char gamePiece);
	char getWinningPiece() const;
};

