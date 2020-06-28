/*  
 * FILE: Board.cpp
 * DESCRIPTION: Implementation of Board class
 * DATE: July 14th, 2019
 * REFERENCES: 	https://www.youtube.com/watch?v=Asz5yHz8KiA
 *	  		   	http://xoax.net/cpp/crs/console/lessons/Lesson43/
 */
#include "Board.h"
#include <iostream>
#include <string>
#include "Man.h"

/*
 * DESCRIPTION: Allocates pieces onto the checkerboard.
 */
Board::Board()
{
	for ( int iRow = 0; iRow < 8; ++iRow )
	{
		for ( int iCol = 0; iCol < 8; ++iCol )
		{
			m_Field[iRow][iCol] = nullptr;
		}
	}
	// Allocate and place black pieces
	for ( int iCol = 0; iCol < 8; ++iCol )
	{
		if ( iCol % 2 != 0 )
		{
			m_Field[7][iCol] = std::make_shared<Man>( 'B' );
			m_Field[5][iCol] = std::make_shared<Man>( 'B' );
			m_Field[1][iCol] = std::make_shared<Man>( 'W' );
		}
	}
	
	// Allocate and place white pieces
	for ( int iCol = 0; iCol < 8; ++iCol )
	{
		if ( iCol % 2 == 0 )
		{
			m_Field[0][iCol] = std::make_shared<Man>( 'W' );
			m_Field[2][iCol] = std::make_shared<Man>( 'W' );
			m_Field[6][iCol] = std::make_shared<Man>( 'B' );

		}
	}
}

/*
 * DESCRIPTION: Prints a checkerboard to the standard output.
 */
void Board::Print()
{
	const int kiSquareWidth = 4;
	const int kiSquareHeight = 3;
	for ( int iRow = 0; iRow < 8 * kiSquareHeight; ++iRow )
	{
		int iSquareRow = iRow / kiSquareHeight;
		// Print the side border with numbering
		if ( iRow % 3 == 1 )
		{
			cout << '-' << (char)('1' + 7 - iSquareRow) << '-';
		}
		else
		{
			cout << "---";
		}
		// Print the checkerboard board
		for ( int iCol = 0; iCol < 8 * kiSquareWidth; ++iCol )
		{
			int iSquareCol = iCol / kiSquareWidth;
			if ( ((iRow % 3) == 1) && ((iCol % 4) == 1 || (iCol % 4) == 2) && m_Field[7 - iSquareRow][iSquareCol] != nullptr )
			{
				if ( (iCol % 4) == 1 )
				{
					cout << m_Field[7 - iSquareRow][iSquareCol]->GetColor();
				}
				else
				{
					cout << m_Field[7 - iSquareRow][iSquareCol]->GetPiece();
				}
			}
			else
			{
				if ( (iSquareRow + iSquareCol) % 2 == 1 )
				{
					cout << '*';
				}
				else
				{
					cout << ' ';
				}
			}
		}
		cout << endl;
	}
	// Print the bottom border with numbers
	for ( int iRow = 0; iRow < kiSquareHeight; ++iRow )
	{
		if ( iRow % 3 == 1 )
		{
			cout << "---";
			for ( int iCol = 0; iCol < 8 * kiSquareWidth; ++iCol )
			{
				int iSquareCol = iCol / kiSquareWidth;
				if ( (iCol % 4) == 1 )
				{
					cout << (iSquareCol + 1);
				}
				else
				{
					cout << '-';
				}
			}
			cout << endl;
		}
		else
		{
			for ( int iCol = 1; iCol < 9 * kiSquareWidth; ++iCol )
			{
				cout << '-';
			}
			cout << endl;
		}
	}
}