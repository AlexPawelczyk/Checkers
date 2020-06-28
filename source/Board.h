/*  
 * FILE: Board.h
 * DATE: July 14th, 2019
 */
#pragma once
#include <memory>
#include <array>
#include "Piece.h"

using namespace std;

 // Forward declaration
class Piece;
using Field88 = std::array<std::array<std::shared_ptr<Piece>, 8>, 8>;

class Board
{
public:
	Board();
	~Board() = default;

	Field88& GetField() { return m_Field; }

	void Print();
private:
	Field88 m_Field;
};

