/* 
 * File: statKeeper.h 
 * Date: July 14th, 2019
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Player.h"
#include <memory>

class StatKeeper
{
private:
	vector<std::shared_ptr<Player>> m_player_list;
public:
	StatKeeper();
	~StatKeeper();
	vector<std::shared_ptr<Player>> get_player_list();
	void set_player_list(vector<std::shared_ptr<Player>> const& player_list);

	void read_leaderboard(std::string file_name);
	void print_leaderboard();
	void save_leaderboard();
	void process_line(std::ifstream& in_file, std::string curr_line);
	std::string find_next_token(std::ifstream& in_file, std::string& curr_line, 
		char first_delimiter, char second_delimeter);

};