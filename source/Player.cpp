/*  
 * FILE: Player.cpp
 * DESCRIPTION: Implementation of Player class
 * DATE: July 14th, 2019
 */
#include "Player.h"
#include <memory>
///////////////////// implementation of Player ///////////////////////

//default constructor 
Player::Player()
{
	m_name = "root";
	m_total_wins = 0;
	m_total_losses = 0;
	m_win_loss_ratio = 0;
}

//parametarized constructor
Player::Player(string player_name, string player_team, int num_win, int num_loss, float win_loss_ratio)
{
	m_name = player_name;
	m_team = player_team;
	m_total_wins = num_win;
	m_total_losses = num_loss;
	m_win_loss_ratio = win_loss_ratio;
}

//get methods
string Player::get_name() const{
	//this method returns the player name
	return m_name;
}

string Player::get_team() const{
	//this method returns the player name
	return m_team;
}

int Player::get_total_wins() const{
	//this method returns the number of wins
	return m_total_wins;
}

int Player::get_total_losses() const{
	//this method returns the number of losses
	return m_total_losses;
}

float Player::get_win_loss_ratio() const{
	//this method returns the number of losses
	return m_win_loss_ratio;
}

//set methods
void Player::set_name(const string player_name) {
	//this method sets the player name
	m_name = player_name;
}

void Player::set_team(const string player_team) {
	//this method sets the player name
	m_team = player_team;
}

void Player::set_total_wins(const int num_win) {
	//this method sets the number of wins
	m_total_wins = num_win;
}

void Player::set_total_losses(const int num_loss) {
	//this method sets the number of losses
	m_total_losses = num_loss;
}

void Player::set_win_loss_ratio(const float win_loss_ratio) {
	//this method sets the win loss ratio
	m_win_loss_ratio = win_loss_ratio;
}



/*
 * this method calculates the win loss ratio. 
 * if loss = 0 then we return the number of wins
 */
void Player::calc_win_loss_ratio() {
	if (m_total_losses > 0) {
	 	m_win_loss_ratio = (float)m_total_wins / (float)m_total_losses;
	} else {
		m_win_loss_ratio = (float)m_total_wins;
	}
}

/*
 * This method is used to find the index of the player in the passed in list
 */
int Player::find_player_index(vector<std::shared_ptr<Player>>& list, std::string target_name)
{
	int index = -1;
	for(size_t i = 0; i < list.size(); i++)
	{
		std::string curr_name = list[i]->get_name();
		if(curr_name.compare(target_name)==0) 
			return i;
	}
	return index;
}

/*
 * Used to format a player object for clean printing
 */
string Player::player_to_string() {
	//convert integers to strings so we can use string concatenation
	string win   = to_string(m_total_wins);
	string loss  = to_string(m_total_losses);
	string ratio = to_string(m_win_loss_ratio);

	//
	string player = "[name=" + m_name + 
					", wins=" + win + 
					", losses=" + loss + 
					", win/loss_ratio=" + ratio + "]";
	return player;
}
/*
int main(void)
{
	//std::shared_ptr<Player> p3 = std::make_shared<Player>("Charlie", "Red", 0, 0);
	Player* p1 = new Player("Alex", "White", 0, 0);
	Player* p2 = new Player("Bill", "Black", 0, 0);

	p1->print_player();
	p2->print_player();
	//p3->print_player(); 

	return 0;
}*/