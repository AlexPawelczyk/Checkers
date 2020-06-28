# Checkers
Console-based version of the classic game of checkers

# Instructions for Compiling and Running the Game
1. Copy group4-checkers.zip into your current working directory

2. Unzip group4-checkers.zip and enter the source directory 

3. Compile the code using the following compilation string:
	g++ Board.cpp Checkers.cpp ExitOption.cpp main.cpp MainMenu.cpp Man.cpp MenuOption.cpp Piece.cpp Player.cpp PlayOption.cpp statKeeper.cpp StatsOption.cpp -o checkers 
  
4. Run the program using the following execution string:
	./checkers

# Instructions for Playing the Game
I.  APPLICATION START-UP

    Once the application is started the user is presented with three options: 
    	1. START GAME 
      	2. VIEW STATS
      	3. CLOSE APP

II. User is asked to enter their selection from the above menu

	   	- Entering '1' ==> picking the START GAME option 
	   	- Entering '2' ==> picking the VIEW STATS option
	   	- Entering '3' ==> picking the CLOSE APP option  

III. NECESSARY INSTRUCTIONS FOR PLAYING CHECKERS

		- Players alternate turns, moving 1 piece per turn
			* To move a piece, the system asks the user to...
				- Enter the ROW# of piece that user wants to move
				- Enter the COLUMN# of piece that user wants to move
				- Enter the ROW# of the TARGET square that user wants to move to
				- Enter the COLUMN# of the TARGET square that user wants to move to
			* IF the move is valid
				THEN we switch to the other player
			* ELSE IF user is in a capture chain (i.e. can capture multiple pieces in one turn)
				- Enter the ROW# of the TARGET square that user wants to move to
				- Enter the COLUMN# of the TARGET square that user wants to move to
			* ELSE the current player re-tries their move
			* We repeat these steps until there is a winner, or the user quits (enters 'q')

		- Understanding the checkerboard
			* ROW#s are displayed vertically along the left side of the board
			* COLUMN#s are displayed horizontally along the bottom of the board
			* BM ==> Man for the black team
			* WM ==> Man for the white team

							---    ****    ****    ****    ****
							-8-    *BM*    *BM*    *BM*    *BM*
							---    ****    ****    ****    ****
							---****    ****    ****    ****    
							-7-*BM*    *BM*    *BM*    *BM*    
							---****    ****    ****    ****    
							---    ****    ****    ****    ****
							-6-    *BM*    *BM*    *BM*    *BM*
							---    ****    ****    ****    ****
							---****    ****    ****    ****    
							-5-****    ****    ****    ****    
							---****    ****    ****    ****    
							---    ****    ****    ****    ****
							-4-    ****    ****    ****    ****
							---    ****    ****    ****    ****
							---****    ****    ****    ****    
							-3-*WM*    *WM*    *WM*    *WM*    
							---****    ****    ****    ****    
							---    ****    ****    ****    ****
							-2-    *WM*    *WM*    *WM*    *WM*
							---    ****    ****    ****    ****
							---****    ****    ****    ****    
							-1-*WM*    *WM*    *WM*    *WM*    
							---****    ****    ****    ****    
							-----------------------------------
							----1---2---3---4---5---6---7---8--
							-----------------------------------

			* Here is an example of how to move the top-left white piece (Row 3, Col 1)

							White's Move
							Enter your row (q for exit): 3
							Enter your column (q for exit): 1
							To
							Enter target row (q for exit): 4
							Enter target column (q for exit): 2
							---    ****    ****    ****    ****
							-8-    *BM*    *BM*    *BM*    *BM*
							---    ****    ****    ****    ****
							---****    ****    ****    ****    
							-7-*BM*    *BM*    *BM*    *BM*    
							---****    ****    ****    ****    
							---    ****    ****    ****    ****
							-6-    *BM*    *BM*    *BM*    *BM*
							---    ****    ****    ****    ****
							---****    ****    ****    ****    
							-5-****    ****    ****    ****    
							---****    ****    ****    ****    
							---    ****    ****    ****    ****
							-4-    *WM*    ****    ****    ****
							---    ****    ****    ****    ****
							---****    ****    ****    ****    
							-3-****    *WM*    *WM*    *WM*    
							---****    ****    ****    ****    
							---    ****    ****    ****    ****
							-2-    *WM*    *WM*    *WM*    *WM*
							---    ****    ****    ****    ****
							---****    ****    ****    ****    
							-1-*WM*    *WM*    *WM*    *WM*    
							---****    ****    ****    ****    
							-----------------------------------
							----1---2---3---4---5---6---7---8--
							-----------------------------------


# REFERENCES
1. https://www.youtube.com/watch?v=Asz5yHz8KiA

2. http://xoax.net/cpp/crs/console/lessons/Lesson43/

3. http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
