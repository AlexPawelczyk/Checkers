/*  
 * FILE: Checkers.cpp
 * DESCRIPTION: Implementation of Checkers class
 * DATE: July 14th, 2019
 * REFERENCES: 	https://www.youtube.com/watch?v=Asz5yHz8KiA
 *	  		   	http://xoax.net/cpp/crs/console/lessons/Lesson43/
 */
#include "Checkers.h"
#include <iostream>
#include "Move.h"
#include <string>

Checkers::Checkers()
	: m_PlayerTurn('W')
	, mExitRequested(false)
{}

std::string Checkers::Start()
{
    bool isCapture = false;
	do {
		//Get and perform next move. Find out if capture chain available.
		isCapture = GetNextMove( mqGameBoard.GetField(), isCapture);

		if (mExitRequested) break;

		//Do not give turn to opposite color if capture chain is available.
		if(!isCapture) AlternateTurn();
	} while ( !IsGameOver() );
	
	if (mExitRequested) return "q";

	mqGameBoard.Print();

	return std::string(1,m_PlayerTurn);
}

/**
 * Gets and implements move from user if valid.
 * @param field  - Game board
 * @return bool: If move was a capture
 */
bool Checkers::GetNextMove(Field88& field, bool isCapture)
{
	bool bValidMove = false;
	bool chainCapture = false;
	int num = 0;

	do
	{
		mqGameBoard.Print();
		if(num > 0) { cout << "Invalid Move!" << endl; }
		// Get input and convert to coordinates
		if ( m_PlayerTurn == 'W')
			cout << "White's Move\n";
		else
			cout << "Black's Move\n";

		Move move;
		bool isOk = false;
		if(!isCapture)
		{
			isOk = RequestInput("Enter your row (q for exit): ", move.StartRow);
			if (!isOk) return false;
			move.StartRow--;

			isOk = RequestInput("Enter your column (q for exit): ", move.StartCol);
			if (!isOk) return false;
			move.StartCol--;
		} else
		{
			move.StartRow = capRow;
			move.StartCol = capCol;
		}

		if(!isCapture) cout << "To\n";
		else cout << "Capture Chain!\n";

		isOk = RequestInput("Enter target row (q for exit): ", move.EndRow);
		if (!isOk) return false;
		move.EndRow--;

		isOk = RequestInput("Enter target column (q for exit): ", move.EndCol);
		if (!isOk) return false;
		move.EndCol--;

		// Check that the indices are in range
		// and that the source and destination are different
		if ( (move.StartRow >= 0 && move.StartRow <= 7) &&
			(move.StartCol >= 0 && move.StartCol <= 7) &&
			(move.EndRow >= 0 && move.EndRow <= 7) &&
			(move.EndCol >= 0 && move.EndCol <= 7) )
		{
			// Additional checks in here
			std::shared_ptr<Piece> qpCurrPiece = field[move.StartRow][move.StartCol];
			// Check that the piece is the correct color
			if ( (qpCurrPiece != 0) && (qpCurrPiece->GetColor() == m_PlayerTurn) )
			{
				// Check that the destination is a valid destination
				if ( qpCurrPiece->IsLegalMove(move, field ) )
				{
					// Make the move
					field[move.EndRow][move.EndCol] = field[move.StartRow][move.StartCol];
					field[move.StartRow][move.StartCol] = 0;

					//If piece captured, remove that piece from board
					if(abs(move.StartRow - move.EndRow) == 2){
					    isCapture = true;
					    capRow = move.EndRow;
					    capCol = move.EndCol;
						field[(move.StartRow+ move.EndRow)/2][(move.StartCol+ move.EndCol)/2] = 0;

						//Reduce opponent's pieces remaining by one
						DecrementPieces();
					}

					//Check for promotion and if so king piece
					qpCurrPiece->CheckKing(move.EndRow);
					//If move was a capture, check if another capture is possible
					if(isCapture) chainCapture = ChainCapture(field, qpCurrPiece, move.EndRow, move.EndCol);
					bValidMove = true;
			}
			}
		}
		if ( !bValidMove )
		{
			num = num + 1;
		}
	} while ( !bValidMove );

	return chainCapture;
}

/**
 * @method ChainCapture
 * @param field - Game board
 * @param qpCurrPiece - User's current piece
 * @param row  - Current row of piece
 * @param col  - Current column of piece
 * @return true if piece can capture another piece in a chain combo.
 */
bool Checkers::ChainCapture(const Field88& field, std::shared_ptr<Piece> qpCurrPiece, int row, int col){


	//First Element: Upper Left
	//Second Element: Upper Right
	//Third Element: Lower Left
	//Fourth Element: Lower Right
	bool adjEnemies [4] = {false};
	char color = qpCurrPiece->GetColor();
	bool isChain = false;

	//Check if adjacent square not out of bounds
	if(row + 1 <= 7 && col - 1 >= 0){
		//Check that there is a piece there and it is an enemy piece
		if(field[row + 1][col - 1] != 0 && field[row + 1][col - 1]->GetColor() != color){
			if(row + 2 <= 7 && col - 2 >= 0){
				//Check there is an empty square after enemy piece to land on
				if(field[row + 2][col - 2] == 0){
					//Chain capture is available. Mark true.
					adjEnemies[0] = true;
				}
			}
		}
	}

	if(row + 1 <= 7 && col + 1 <= 7){
		if(field[row + 1][col + 1] != 0 && field[row + 1][col + 1]->GetColor() != color){
			if(row + 2 <= 7 && col + 2 <= 7){
				if(field[row + 2][col + 2] == 0){
					adjEnemies[1] = true;
				}
			}
		}
	}
	if(row - 1 >= 0 && col - 1 >= 0){
		if(field[row - 1][col - 1] != 0 && field[row - 1][col - 1]->GetColor() != color){
			if(row - 2 >= 0 && col - 2 >= 0){
				if(field[row - 2][col - 2] == 0){
					adjEnemies[2] = true;
				}
			}
		}
	}
	if(row - 1 >= 0 && col + 1 <= 7){
		if(field[row - 1][col + 1] != 0 && field[row - 1][col + 1]->GetColor() != color){
			if(row - 2 >= 0 && col + 2 <= 7){
				if(field[row - 2][col + 2] == 0){
					adjEnemies[3] = true;
				}
			}
		}
	}

	//Determine if chain is available
	//If white piece
	if(color == 'W'){
		if(qpCurrPiece->GetKing()){
			isChain = adjEnemies[2] || adjEnemies [3];
		}
		isChain = isChain || adjEnemies[0] || adjEnemies[1];
	} else{		//Black piece
		if(qpCurrPiece->GetKing()){
			isChain = adjEnemies[0] || adjEnemies [1];
		}
		isChain = isChain || adjEnemies[2] || adjEnemies[3];
	}

    return isChain;
}

bool Checkers::RequestInput(std::string msg, int& value)
{
	cout << msg;
	std::string input;

	std::cin >> input;
	if (input == "q")
	{
		mExitRequested = true;
		return false;
	}
	
	value = std::stoi(input);

	return true;
}

void Checkers::ResetGame()
{
	m_PlayerTurn = 'W';
	mExitRequested = false;
	capRow = 0;
	capCol = 0;
	bLeft = 12;
	wLeft = 12;
	mqGameBoard = Board();
}

void Checkers::AlternateTurn()
{
	m_PlayerTurn = (m_PlayerTurn == 'W') ? 'B' : 'W';
}

bool Checkers::IsGameOver()
{
	if(wLeft == 0 || bLeft == 0) return true;
	return false;
}

//Decrement opponent player's piece count when their piece captured
void Checkers::DecrementPieces(){
	if(m_PlayerTurn == 'W') bLeft--;
	else wLeft--;
}