/******************************************************************************
*
*  Soccer Card Game
*
*	v0.0 - bitnj
*
******************************************************************************/

#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h> //for rand, srand
#include <math.h> // for round
#include <time.h> // to randomize seed value of rand()
#include <my_global.h>
#include <mysql.h>
#include </store/mirrored/shared/projects/cpp/TextGame/Player.h>
//#include </home/bitnj/Programming/cpp/TextGame/Player.h>

using namespace std;

MYSQL_RES* result;
MYSQL_ROW row;

enum Leagues {PREMIER_LEAGUE, LA_LIGA, SERIE_A, BUNDESLIGA};
enum Teams {AFC_BOURNEMOUTH, ARSENAL};

/*-----------------------------------------------------------------------------
    - main

------------------------------------------------------------------------------*/
int main()
{
	 // seed the rand() function
    srand(time(0));
	
	cout << "Welcome to the Soccer Card game. \n\n";
	
    // initialize MySQL
	MYSQL* dbCon = mysql_init(NULL);
	if (dbCon == NULL)
	{
		cout << mysql_error(dbCon) << '\n';
		exit(1);
	}
	// connect
	if (mysql_real_connect(dbCon, "172.17.179.19", "devtest.full", "CAPtain116", "devtest", 0, NULL, 0) == NULL) 
    {
        exit(1);
    }
    
	// choose league
	cout << "Choose a league:" << '\n';
	if (mysql_query(dbCon, "SELECT * FROM League"))
	{
		exit(1);
	}
	result = mysql_store_result(dbCon);
	if (result == NULL)
	{
		exit(1);
	}
	while ((row = mysql_fetch_row(result))) 
    { 
        int columns = mysql_num_fields(result);
		for (int i = 0; i < columns; i++)
        {
			cout << row[i] << ' ';
		}
		cout << '\n';
    }
	
	// user enters choice of league
	string choice;
	cin >> choice;
    
    string qstring = "SELECT Name FROM Team WHERE LeagueID = " + choice;
    // query to the Team table based on the League selection   
    if (mysql_query(dbCon, qstring.c_str()))
    {
        exit(1);
    }
    result = mysql_store_result(dbCon);
    if (result == NULL) 
    {
        exit(1);
    }
    
    while ((row = mysql_fetch_row(result))) 
    { 
        int columns = mysql_num_fields(result);
		for (int i = 0; i < columns; i++)
        {
			cout << row[i] << ' ';
		}
		cout << '\n';
    }
   
   	cout << "Choose a Team:" << '\n';
   	cin >> choice;
   	
   	qstring = "SELECT FirstName, LastName FROM Player WHERE TeamID = " + choice;
    // query to the Player table based on the Team selection   
    if (mysql_query(dbCon, qstring.c_str()))
    {
        exit(1);
    }
    result = mysql_store_result(dbCon);
    if (result == NULL) 
    {
        exit(1);
    }
    
    while ((row = mysql_fetch_row(result))) 
    { 
        int columns = mysql_num_fields(result);
		for (int i = 0; i < columns; i++)
        {
			cout << row[i] << ' ';
		}
		cout << '\n';
    }
	
    // initialize player counts and randomly choose who goes first
	int pl_players = 11;
	int p2_players = 11;
	int player = round(rand() % 2 + 1);
	
	// loan teams
    
    
    while (pl_players != 0 && p2_players != 0)
	{
		// instantiate vector of Player objects for this round
        vector<Player> Players(2);

        cout << "Player " << player << ": Pick attack(1) or defend(2) \n";
	    int choice;
		cin >> choice;
        	
		Players[0].defAttrib.overall = (rand() % 100) + 1;
		Players[1].defAttrib.overall = (rand() % 100) + 1;
        cout << Players[0].defAttrib.overall << '\n';
		cout << Players[1].defAttrib.overall << '\n';
	
        /*switch(choice)
        {
            // current player chose attack
            case 1:
                Players[player - 1].overall > Players[player].overall
                break;     
            // current player chose defense
            case 2:
                Players[player - 1].overall > Players[player].overall
                break;     
        } */
        
		// see which player wins, decrement losers playercount
		if (Players[0].defAttrib.overall > Players[1].defAttrib.overall)
		{
			p2_players -= 1;
			cout << "Player one wins this round \n";
		}
		else
		{
			pl_players -= 1;
			cout << "Player two wins this round \n";
		}
		cout << "The score is p1: " << 11 - p2_players << " p2: " << 11 - pl_players << '\n';
	
		// switch players
		if (player == 1)
		{
			player = 2;
		}
		else
		{
			player = 1;
		}
	}

	//let the user know who won
	if (pl_players == 0)
	{
		cout << "Player 2 WINS!" << '\n';
	}
	else
	{
		cout << "Player 1 WINS!" << '\n';
	}
	return 0;
}

/*-----------------------------------------------------------------------------
    - LoadTeams - take a csv file of players

------------------------------------------------------------------------------*/
/*void LoadPlayers(Team& t)
{

}*/