/*
 * FILE: exit_option.cpp
 * DESCRIPTION: Implementation of exit_option class
 * DATE: July 14th, 2019 
 */
#include "ExitOption.h"
//constructors
ExitOption::ExitOption(std::string name, int index) : MenuOption(name, index) 
{
	m_title = "*************** SAVING GAME ***************";
}

//getters
std::string ExitOption::get_title() const
{
	return m_title;
}

//setters
void ExitOption::set_title(const std::string title) 
{
	m_title = title;
}
