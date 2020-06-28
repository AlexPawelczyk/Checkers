/*
 * FILE: stats_option.cpp
 * DESCRIPTION: Implementation of play_option class.
 * DATE: July 14th, 2019 
 */
#include "StatsOption.h"
//constructor
StatsOption::StatsOption(std::string name, int index) : MenuOption(name, index) 
{
	m_title = "*************** GLOBAL LEADERBOARD ***************";
}

//getters
std::string StatsOption::get_title() const
{
	return m_title;
}

//setters
void StatsOption::set_title(const std::string title) 
{
	m_title = title;
}
