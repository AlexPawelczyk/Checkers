/*
 * FILE: menu_option.cpp
 * DESCRIPTION: Implementation of menu_option class
 * DATE: July 14th, 2019 
 */
#include "MenuOption.h"
#include <iostream>
///////////////// Member functions of menu_option /////////////////////////////
//constructor
MenuOption::MenuOption(std::string n, int i) {
	m_option_name = n;
	m_option_index = i;
}

//destructor
MenuOption::~MenuOption()
{}

//get methods
std::string MenuOption::get_option_name() {
	//this method returns the option name
	return m_option_name;
}

int MenuOption::get_option_index() {
	//this method returns the option index
	return m_option_index;
}

//set methods
void MenuOption::set_option_name(std::string n) {
	//this method sets the option name
	m_option_name = n;
}

void MenuOption::set_option_index(int i) {
	//this method sets the option index
	m_option_index = i;
}

//other methods
void MenuOption::print_option() {
	std::cout << "==============================================================" << std::endl;
	std::cout << m_option_index << ") " << m_option_name << std::endl;
	std::cout << "==============================================================" << std::endl;
}
