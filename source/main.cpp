/*
 * FILE: main.cpp
 * DESCRIPTION: Driver program for the checkers application
 * DATE: July 14th, 2019 
 */
#include <iostream>
#include "MainMenu.h"
#include "MenuOption.h"
#include "StatsOption.h"
#include "PlayOption.h"
#include "ExitOption.h"
#include "Player.h"
#include "statKeeper.h"

int main()
{
	StatKeeper statty;
	statty.read_leaderboard("leaderboard.txt");

	//Create a copy of statty's vector which contains pointers to Player objects
	vector<std::shared_ptr<Player>> copy_list;
	for (size_t i = 0; i < statty.get_player_list().size(); i++)
		copy_list.push_back(statty.get_player_list()[i]);

	//Create and print the main menu (i.e. title + user options)
	//m1(1) ==> game is on && m1(0) ==> game is off 
	MainMenu m1(1);

	//main loop for running the entire application (breaks if user selects exit_game option)
	while (m1.get_is_running() == 1)
		m1.set_is_running(m1.process_user_selection(m1.get_user_selection(), statty, copy_list));

	//Update statty's list and save the latest edition of the leaderboard
	statty.set_player_list(copy_list);
	statty.save_leaderboard();

	return 0;
}