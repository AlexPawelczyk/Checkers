/*
 * FILE: play_option.cpp
 * DESCRIPTION: Implementation of play_option class.
 * DATE: July 14th, 2019 
 */
#include "PlayOption.h"
//constructors
PlayOption::PlayOption(std::string name, int index) : MenuOption(name, index) 
{
	m_title = "*************** CHECKERS GAME ***************";
}

//getters
std::string PlayOption::get_title() const
{
	return m_title;
}

//setters
void PlayOption::set_title(const std::string title) 
{
	m_title = title;
}
