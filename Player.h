/******************************************************************************
*
*  Player.h
*
*	v0.0 - bitnj
*
******************************************************************************/

#include <iostream>
//#include </home/bitnj/Programming/cpp/TextGame/DefensiveAttributes.h>

using namespace std;

// ----------------------------------------------------------------------------
// Player class
// ----------------------------------------------------------------------------
class Player 
{
	public:
		string name;
		string team;
        string position;
		int stars;
		float marketvalue;
		bool isAvail;
        
		struct DefensiveAttributes
        {
            int speed;
            int tackle;
            int power;
            int overall;
        } defAttrib;
};


