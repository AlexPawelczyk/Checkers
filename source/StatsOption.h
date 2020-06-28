/* 
 * File: stats_option.h 
 * Date: July 14th, 2019
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "statKeeper.h"
#include "MenuOption.h"
#include "MainMenu.h"

class StatsOption : public MenuOption 
{
private:
	std::string m_title;
public :
	//constructors
	StatsOption(std::string name="", int index=0);

	//getter and setter
	string get_title() const;
	void set_title(const string title);
};