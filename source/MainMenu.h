/*  
 * File: Player.h 
 * Date: July 14th, 2019
 */
#pragma once
#include "statKeeper.h"

class Player;

class MainMenu
{
private:
	int m_is_running;	//1 if app is on, 0 if app is off
public:
	//constructors
	MainMenu();
	MainMenu(int is_running);

	//destructor
	~MainMenu() = default;

	//getters and settes
	int get_is_running() const;
	void set_is_running(const int is_running);

	//functions for printing menu and getting user selection
	void print_title();
	void print_menu();
	int get_user_selection();
	int process_user_selection(int user_input, StatKeeper& stats, vector<std::shared_ptr<Player>>& list);
	
};