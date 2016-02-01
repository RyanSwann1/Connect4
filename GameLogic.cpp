#include "stdafx.h"
#include "GameLogic.h"
#include "Board.h"
#include "humanPlayer.h"
#include "computerPlayer.h"


bool GameLogic::isComputerInPlay() const
{
	return m_IsComputerInPlay;
}

bool GameLogic::foundWinner() const
{
	return m_FoundWinner;
}


void GameLogic::askFirstTurn(humanPlayer & player1, humanPlayer & player2, computerPlayer& computer)
{
	bool decided = false,
		firstTurn = false;
	char choice = ' ';
	std::cout << "Would you like to go first? 'y' - Yes. 'n' - No. ";
	while (!decided)
	{
		std::cin >> choice;
		if (choice == 'y' || choice == 'n')
			decided = true;
		else
			std::cout << "Please enter correct information.";
	}

	if (choice == 'y')
		firstTurn = true;

	allocateGamePieces(player1, player2, computer, firstTurn);
}

void GameLogic::allocateGamePieces(humanPlayer & player1, humanPlayer & player2, computerPlayer& computer, bool firstTurn)
{
	if (isComputerInPlay())
	{
		if (firstTurn)
		{
			player1.setGamePiece(Board::X);
			computer.setGamePiece(Board::O);
		}
		else
		{
			player1.setGamePiece(Board::O);
			computer.setGamePiece(Board::X);
		}
	}

	else
	{
		if (firstTurn)
		{
			player1.setGamePiece(Board::X);
			player2.setGamePiece(Board::O);
		}
		else
		{
			player1.setGamePiece(Board::O);
			player2.setGamePiece(Board::X);
		}
	}
}

void GameLogic::game(Board & board, humanPlayer & player1, humanPlayer & player2, computerPlayer& computer, GameLogic& gameLogic)
{
	//Game loop
	m_IsComputerInPlay = determineOpponent();
	askFirstTurn(player1, player2, computer);
	board.displayBoard();

	while(!foundWinner())
	{
		//Player 1's turn
		if (m_Turn == player1.getGamePiece())
		{
			announceTurn("Player 1");
			player1.takeTurn(player1, board, gameLogic, computer, "Player");
			board.displayBoard();
			m_FoundWinner = board.checkForWinner(gameLogic, player1.getGamePiece());
			m_Turn = changeTurn(player1.getGamePiece());
		}

		if (!foundWinner())
		{
			//Computers turn
			if (isComputerInPlay())
			{
				computer.takeTurn(player1, board, gameLogic, computer, "Computer");
				board.displayBoard();
				m_FoundWinner = board.checkForWinner(gameLogic, computer.getGamePiece());
				m_Turn = changeTurn(computer.getGamePiece());

			}

			//Player 2 turn
			else
			{
				announceTurn("Player 2");
				player2.takeTurn(player2, board, gameLogic, computer, "Player");
				board.displayBoard();
				m_FoundWinner = board.checkForWinner(gameLogic, player2.getGamePiece());
				m_Turn = changeTurn(player2.getGamePiece());
			}
		}
	}

	announceWinner(player1, player2, computer, board);
}

char GameLogic::changeTurn(char turn)
{
	if (turn == Board::X)
		return Board::O;

	else
		return Board::X;
}

bool GameLogic::determineOpponent()
{
	bool decided = false;
	char choice = ' ';
	std::cout << "Would you like to face a computer? 'y' - Yes. 'n' - No.";
	while (!decided)
	{
		std::cin >> choice;

		if (choice == 'y' || choice == 'n')
			decided = true;
		else
			std::cout << "Wrong information entered.";
	}

	if (choice == 'y')
		return true;
	else
		return false;

}

void GameLogic::announceTurn(const std::string whichPlayer)
{
	std::cout << whichPlayer << "'s move.\n";
}

void GameLogic::announceWinner(const humanPlayer & player1, const humanPlayer & player2, const computerPlayer & computer, const Board& board)
{
	if (board.getWinningPiece() == player1.getGamePiece()) {
		std::cout << "\nPlayer1 wins the game!";
	}

	if (board.getWinningPiece() == player2.getGamePiece()) {
		std::cout << "\nPlayer2 wins the game!";
	}

	if (board.getWinningPiece() == computer.getGamePiece()) {
		std::cout << "\nThe computer wins the game.";
	}
}


