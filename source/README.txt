*************** GROUP MEMBER CONTRIBUTIONS ************************************
Alex Pawelczyk (B00755840)
	- High-level domain model
	- Use case diagram
	- Class diagram
	- README.txt
	- Putting together report
	- main.cpp, main_menu.cpp, menu_option.cpp, play_option.cpp, stats_option.cpp
	  exit_option.cpp, Player.cpp, statKeeper.cpp
	- main_menu.h, menu_option.h, play_option.h, stats_option.h
	  exit_option.h, Player.h, statKeeper.h

Max
	- Class diagram
	- Board.cpp, Checkers.cpp, Piece.cpp
	- Board.h, Checkers.h, Piece.h

Liam
	- User description of game rules
	- Board.cpp, Checkers.cpp, Piece.cpp
	- Board.h, Checkers.h, Piece.h

Gobii Vivagananda
	- main.cpp, main_menu.cpp, menu_option.cpp, play_option.cpp, stats_option.cpp
	  exit_option.cpp, Player.cpp, statKeeper.cpp
	- main_menu.h, menu_option.h, play_option.h, stats_option.h
	  exit_option.h, Player.h, statKeeper.h
	- Putting together presentation

*************** INSTRUCTIONS FOR RUNNING THE PROGRAM ON BLUENOSE **************
1. Download our group's submission from Brightspace: group4-checkers.zip
2. Login to Bluenose
3. Copy group4-checkers.zip into your current working directory
4. Unzip group4-checkers.zip and enter the group4-checkers directory 
5. Compile the code using the following compilation string:
	g++ -std=c++11 -o checkers *.cpp 
6. Run the program using the following execution string:
	./checkers

*************** INSTRUCTIONS FOR PLAYING THE CHECKERS GAME ********************
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


****************************** REFERENCES ********************************************
1. https://www.youtube.com/watch?v=Asz5yHz8KiA
2. http://xoax.net/cpp/crs/console/lessons/Lesson43/
3. http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20

