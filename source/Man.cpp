#include "Man.h"

Man::Man( char cColor ) : Piece( cColor ) {}

char Man::GetPiece()
{
	return GetKing() ? 'K' : 'M';
}

bool Man::AreSquaresLegal(const Move& move, const Field88& field)
{
	std::shared_ptr<Piece> qpDest = field[move.EndRow][move.EndCol];
	bool captureMove = false;

	//Check if move is a capture move
	if(abs(move.EndCol - move.StartCol) == 2 && abs(move.EndRow - move.StartRow) == 2){
		//Check intermediate space between source and destination has piece of opposite color
		std::shared_ptr<Piece> capturePiece = field[(move.EndRow + move.StartRow)/2][(move.EndCol + move.StartCol) / 2];
		//Check intermediate space is not empty
		if( capturePiece != 0){
			//Check piece in intermediate space is enemy piece
			if( capturePiece->GetColor() != field[move.StartRow][move.StartCol]->GetColor()) captureMove = true;
		}
	}

	if ( qpDest == 0 )
	{
		//Two possibilities - Normal move or capturing move.

		//Capturing Move
		if(captureMove == true){
			if ( (move.StartCol + 2) == move.EndCol || (move.StartCol - 2) == move.EndCol)
			{
				if ( GetColor() == 'W' )
				{
					if( GetKing() && abs(move.EndRow - move.StartRow) == 2) return true;
					else if ( move.EndRow == move.StartRow + 2 ) return true;
				}
				else
				{
					if( GetKing() && abs(move.EndRow - move.StartRow) == 2) return true;
					else if ( move.EndRow == move.StartRow - 2 ) return true;
				}
			}
		}

		// Normal Move
		// Destination square is unoccupied
		else if ( (move.StartCol + 1) == move.EndCol || (move.StartCol - 1) == move.EndCol)
		{
			if ( GetColor() == 'W' )
			{
				if( GetKing() && abs(move.EndRow - move.StartRow) == 1) return true;
				else if ( move.EndRow == move.StartRow + 1 ) return true;
			}
			else
			{
				if( GetKing() && abs(move.EndRow - move.StartRow) == 1) return true;
				else if ( move.EndRow == move.StartRow - 1 ) return true;
			}
		}
	}
	
	return false;
}
