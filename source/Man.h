#include "Piece.h"

class Man : public Piece
{
public:
	Man( char cColor );
	~Man() = default;

private:
	virtual char GetPiece() override;
	bool AreSquaresLegal(const Move& move, const Field88& field) override;
};