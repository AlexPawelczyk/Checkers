/*  
 * FILE: Piece.cpp
 * DESCRIPTION: Implementation of Piece class
 * DATE: July 14th, 2019
 * REFERENCES:  https://www.youtube.com/watch?v=Asz5yHz8KiA
 *	  		   	http://xoax.net/cpp/crs/console/lessons/Lesson43/
 */
#include "Piece.h"

Piece::Piece( char cColor ) : mcColor( cColor )
{
	king = false;
}

Piece::~Piece() 
{}

char Piece::GetColor()
{
	return mcColor;
}

bool Piece::GetKing(){
	return king;
}

void Piece::CheckKing(int iDestRow){
	if(mcColor == 'W' && iDestRow == 7) king = true;
	else if(mcColor == 'B' && iDestRow == 0) king = true;
}

bool Piece::IsLegalMove(const Move& move, const Field88& field)
{
	std::shared_ptr<Piece> qpDest = field[move.EndRow][move.EndCol];
	if ( (qpDest == 0) || (mcColor != qpDest->GetColor()) )
	{
		return AreSquaresLegal( move, field );
	}
	return false;
}


