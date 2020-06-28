/*
 * FILE: main_menu.cpp
 * DESCRIPTION: Implementation of main_menu class
 * DATE: July 14th, 2019 
 */
#include "MainMenu.h"
#include "MenuOption.h"
#include "StatsOption.h"
#include "PlayOption.h"
#include "ExitOption.h"
#include "Checkers.h"
#include <iostream>

//default constructor
MainMenu::MainMenu()
{
	print_title();
	print_menu();
}

//parameterized constructor
MainMenu::MainMenu(int n)
{
	m_is_running=n;
	print_title();
	print_menu();
}

//getters and setters for member variables
int MainMenu::get_is_running() const
{
	return m_is_running;
}
void MainMenu::set_is_running(const int is_running)
{
	m_is_running = is_running;
}


//prints the title in a cool font
//source: http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
void MainMenu::print_title()
{
	std::cout << "" << std::endl;
	std::cout << "            )                     )         (      (     " << std::endl;
	std::cout << "   (     ( /(           (      ( /(         )\\ )   )\\ )  " << std::endl;
	std::cout << "   )\\    )\\())  (       )\\     )\\())  (    (()/(  (()/(  " << std::endl;
	std::cout << " (((_)  ((_)\\   )\\    (((_)  |((_)\\   )\\    /(_))  /(_)) " << std::endl;
	std::cout << " )\\___   _((_) ((_)   )\\___  |_ ((_) ((_)  (_))   (_))   " << std::endl;
	std::cout << "((/ __| | || | | __| ((/ __| | |/ /  | __| | _ \\  / __|  " << std::endl;
	std::cout << " | (__  | __ | | _|   | (__    ' <   | _|  |   /  \\__ \\  " << std::endl;
	std::cout << "  \\___| |_||_| |___|   \\___|  _|\\_\\  |___| |_|_\\  |___/  " << std::endl;
	std::cout << "" << std::endl;
	std::cout << "==============================================================" << std::endl;
	std::cout << "==============================================================" << std::endl;
	std::cout << std::endl;
}

//displys the three menu options: start_game, view_stats, exit_game
void MainMenu::print_menu()
{
	PlayOption option1("Play Checkers", 1);
	StatsOption option2("View Stats", 2);
	ExitOption option3("Exit Game", 3);
	option1.print_option();
	option2.print_option();
	option3.print_option();
}

//returns an integer representing the correspnding menu option
//1 ==> start_game ; 2 ==> view_stats ; 3 ==> exit_game
int MainMenu::get_user_selection() {
	std::cout << "Select an option from the menu: ";
	std::string user_input;
	std::cin >> user_input;
	int result;

	try {
    	return std::stoi(user_input);
	}
	catch (...) {
    	return 4;
	}
}

//this method is used to process the user's selection
//IF the user inputted 1, then the checkers game will be started
//IF the user inputted 2, then the leaderboard will be showed
//IF the user inputted 3, then the leaderboard will be saved and app is closed
int MainMenu::process_user_selection(int user_input, StatKeeper& stats, vector<std::shared_ptr<Player>>& list) {
	//start_game option
	if(user_input==1)		{
		std::cout<<"Option 1 selected.\n";
		std::string name1;
		std::string name2;
		std::cout<<"Player 1, enter your name: ";
		std::cin >> name1;
		std::cout<<"Player 2, enter your name: ";
		std::cin >> name2;
		std::cout<<"\n";

		//check if the players already exist in the leaderboard
		int index1 = Player::find_player_index(list, name1);
		int index2 = Player::find_player_index(list, name2);

		//create pointers to player objects for current game
		std::shared_ptr<Player> player1;
		std::shared_ptr<Player> player2;

		//if player 1 does not exist
		if(index1 < 0)
		{
			//create a new player and add to list of all players
			player1 = std::make_shared<Player>(name1, "W", 0, 0, 0);			//assign player1 to team W
			list.push_back(player1);
			index1 = list.size()-1;;
		}
		else //player 1 exists
		{
			player1 = list[index1];
			player1->set_team("W");								//assign player1 to team W
		}
		
	
		//if player 2 does not exist
		if(index2 < 0)
		{
			//create a new player and add to list of all players
			player2 = std::make_shared<Player>(name2, "B", 0, 0, 0);			//assign player2 to team B
			list.push_back(player2);
			index2 = list.size()-1;
		}
		else //player 2 exists
		{
			player2 = list[index2];
			player2->set_team("B");								//assign player2 to team B
		}
		std::cout << "********** Current Stats for Players 1 and 2 ************************\n";
		std::cout<< "P1: " << player1->player_to_string() << " Team: " << player1->get_team() << "\n";
		std::cout<< "P2: " << player2->player_to_string() << " Team: " << player2->get_team() << "\n\n";


		std::cout<<"********** START OF GAME **********\n"; 
		std::string winner = "";
		
		// Start the game
		// NOTE: Checkers is a singletone
		// result: winner or Q if exit requested
		Checkers::GetInstance().ResetGame();
		winner = Checkers::GetInstance().Start();

		//IF player 1 is the winner
		if(player1->get_team().compare(winner) == 0)
		{
			player1->set_total_wins(player1->get_total_wins() + 1);
			player2->set_total_losses(player2->get_total_losses() + 1);
			std::cout<<"Player 1 Wins!\n"; 
		}
		//IF player 2 is the winner
		else if(player2->get_team().compare(winner) == 0)
		{
			player2->set_total_wins(player2->get_total_wins() + 1);
			player1->set_total_losses(player1->get_total_losses() + 1);
			std::cout<<"Player 2 Wins!\n"; 
		}
		//IF someone quit before the game
		else
		{
			std::cout << "Quiting the match... Nobody wins!\n";
		}

		//update statistics of the players that just played a match
		list[index1]->calc_win_loss_ratio();
		list[index2]->calc_win_loss_ratio();
		std::cout << "********** Updated Stats for Players 1 and 2 ************************\n";
		std::cout << list[index1]->player_to_string() << endl; 
		std::cout << list[index2]->player_to_string() << endl; 
		
		//wait for user to enter any character before returning to main menu
		std::cout<<"Enter any character to return to the main menu: ";
		getchar();
		MainMenu::print_title();
		MainMenu::print_menu();
		
		stats.set_player_list(list);
		stats.save_leaderboard();

		return 1;
	}
	//view_stats option
	else if(user_input==2)
	{
		std::cout<<"Option 2 selected.\n";
		std::cout<<"*************** GLOBAL LEADERBOARD ***************************\n";
		stats.print_leaderboard();
		//wait for user to enter any character before returning to main menu
		std::cout<<"Enter any character to return to the main menu: ";
		std::string dummy;
		std::cin>> dummy;
		MainMenu::print_title();
		MainMenu::print_menu();
		return 1;
	}
	//exit_option
	else if(user_input==3)
	{
		std::cout<<"Option 3 selected.. Saving the game\n";
		return 0;//this will break the loop in testMenu.cpp and close the application
	}
	//invalid option (neither 1, 2, or 3)
	else
	{
		std::cout<<"Invalid option selected.. try again\n";
		return 1;
	}
}
