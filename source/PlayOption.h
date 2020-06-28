/* 
 * File: play_option.h 
 * Date: July 14th, 2019
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "statKeeper.h"
#include "MenuOption.h"

class PlayOption : public MenuOption 
{
private:
	std::string m_title;
public :
   	//constructors
	PlayOption(std::string name, int index);

	string get_title() const;
	void set_title(const string title);
};