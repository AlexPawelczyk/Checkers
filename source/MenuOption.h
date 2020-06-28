/* 
 * File: menu_option.h 
 * Date: July 14th, 2019
 */
#pragma once
#include <string>
#include "statKeeper.h"

using namespace std;

class MenuOption 
{
private :
	std::string m_option_name;
	int m_option_index ;
public :
	//constructors
	MenuOption(std::string n="", int i=0);
	~MenuOption();

	//get methods
	std::string get_option_name();
	int get_option_index();

	//set methods
	void set_option_name(std::string n);
	void set_option_index(int i);

	//other methods
	void print_option();
};