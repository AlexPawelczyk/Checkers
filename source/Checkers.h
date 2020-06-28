/*  
 * FILE: Checkers.h
 * DATE: July 14th, 2019
 */
#pragma once
#include "Board.h"
#include <string>
#include <memory>

using namespace std;

class Checkers
{
public:
	// Delete copy ctr
	Checkers(const Checkers&) = delete;
	// Delete assign operator
	Checkers& operator=(const Checkers&) = delete;

	// Return instance of the class
	static Checkers& GetInstance()
	{
		static Checkers instance;
		return instance;
	}

	std::string Start();
	bool GetNextMove(Field88& field, bool isCapture);
	void AlternateTurn();
	bool IsGameOver();
	bool ChainCapture(const Field88& field, std::shared_ptr<Piece> qpCurrPiece, int row, int col);
	bool RequestInput(std::string msg, int& value);
	void ResetGame();

private:
	// Private default ctr
	Checkers();
	// Private dctr
	~Checkers() = default;
	
	Board mqGameBoard;
	char m_PlayerTurn;

	void DecrementPieces();

	bool mExitRequested;

	int capRow = 0;
	int capCol = 0;
	int bLeft = 12;
	int wLeft = 12;
};


