/* 
 * File: Piece.h 
 * Date: July 14th, 2019
 */
#pragma once
#include <memory>
#include "Move.h"
#include "Board.h"

using namespace std;

// Forward declaration
class Piece;
using Field88 = std::array<std::array<std::shared_ptr<Piece>, 8>, 8>;

class Piece
{
public:
	Piece( char cColor );
	virtual ~Piece();

	virtual char GetPiece() = 0;

	char GetColor();
	bool GetKing();
	void CheckKing(int iDestRow);
	bool IsLegalMove(const Move& move, const Field88& field);

private:
	virtual bool AreSquaresLegal(const Move& move, const Field88& field) = 0;
	char mcColor;
	bool king;
};



