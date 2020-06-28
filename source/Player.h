/* 
 * File: Player.h 
 * Date: July 14th, 2019
 */
#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Player 
{
private:
	//member variables
	string m_name;
	string m_team;
	int m_total_wins;
	int m_total_losses;
	float m_win_loss_ratio;
public:
	//constructors
	Player();
	Player(string player_name, string player_team, int num_win, int num_loss, float win_loss_ratio);

	//destructor
	~Player() = default;

	//get methods
	string get_name() const;
	string get_team() const;
	int get_total_wins() const;
	int get_total_losses() const; 
	float get_win_loss_ratio() const; 

	//set methods
	void set_name(const string player_name);
	void set_team(const string player_name);
	void set_total_wins(const int num_win);
	void set_total_losses(const int num_loss);
	void set_win_loss_ratio(const float win_loss_ratio); 

	void calc_win_loss_ratio();
	static int find_player_index(vector<std::shared_ptr<Player>>& list, std::string curr_name);

	//toString method
	string player_to_string();
};