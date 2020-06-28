/*  
 * FILE: statKeeper.cpp
 * DESCRIPTION: Implementation of Player class  
 * DATE: July 14th, 2019
 */

#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "statKeeper.h"

//default constructor initializes vector to size 0
StatKeeper::StatKeeper(): m_player_list() { }

StatKeeper::~StatKeeper()
{}
//returns the vector of pointers to all players in the leaderboard
vector<std::shared_ptr<Player>> StatKeeper::get_player_list()
{
	return m_player_list;
}

//setter
void StatKeeper::set_player_list(vector<std::shared_ptr<Player>> const& p_list)
{
	m_player_list = p_list;
}

//used to find the next token when reading from a text file
std::string StatKeeper::find_next_token(std::ifstream& in_file, std::string& curr_token,
										char first_delimiter, char second_delimeter)
{
	//parse until reaching first_delimiter (ignoring all characters)
	getline(in_file, curr_token, first_delimiter);	
	
	//parse until reaching second_delimiter (storing all characters in curr_token)
	getline(in_file, curr_token, second_delimeter);

	//return the current token
	return "" + curr_token;			//token
}

//used to process a current line of input from a text file
void StatKeeper::process_line(std::ifstream& in_file, std::string curr_line)
{
	std::string name   = StatKeeper::find_next_token(in_file, curr_line, '=', ',');	//find name
	std::string wins   = StatKeeper::find_next_token(in_file, curr_line, '=', ',');	//find total_wins
	std::string losses = StatKeeper::find_next_token(in_file, curr_line, '=', ',');	//find total_losses
	std::string ratio  = StatKeeper::find_next_token(in_file, curr_line, '=', ']');	//find w/l_ratio
	getline(in_file, curr_line); 													//ignore the rest of the line

	//create the player object for the current line of input
	std::shared_ptr<Player> p1 = std::make_shared<Player>(name, "---", std::stoi(wins), std::stoi(losses), std::stof(ratio));

	//add the player to this statkeeper's list of players
	m_player_list.push_back(p1);
}

//used to read a list of players from the passed in file
void StatKeeper::read_leaderboard(std::string file_name)
{
	
	ifstream inFile(file_name);	//reading input from this leaderboard file
	std::string currLine;		//initialize current line 
	if(inFile.is_open())
	{
		while(!inFile.eof())
		{
			//process the current line from the txt file
			StatKeeper::process_line(inFile, currLine);
		}
		inFile.close();
	}
}

//prints the leaderboard to the console
void StatKeeper::print_leaderboard()
{
	vector<std::shared_ptr<Player>> playerList = m_player_list;
	for(size_t i = 0; i < m_player_list.size(); i++)
	{
		std::cout<< m_player_list[i]->player_to_string() << endl;
	}
}

//used to save the state of the leaderboard everytime the game is closed
void StatKeeper::save_leaderboard()
{
	ofstream outFile("leaderboard.txt");
	if(outFile.is_open())
	{
		for(size_t i = 0; i < m_player_list.size(); i++)
		{
			if(i!=m_player_list.size()-1)
			{
				//print newline character if this is NOT the last player
				outFile << m_player_list[i]->player_to_string() << "\n";
			}
			else
			{
				//DO NOT print newline character if this is the last player
				outFile << m_player_list[i]->player_to_string(); 
			}
		}
		outFile.close();
		std::cout<<"Leaderboard was successfully saved."<<std::endl;
	}
}