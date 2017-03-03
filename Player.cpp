/******************************************************************************
*
*  Player.cpp
*
*	v0.0 - bitnj
*
******************************************************************************/

#include <iostream>
#include <math>
//#include </home/bitnj/Programming/cpp/TextGame/DefensiveAttributes.h>
//#include </store/mirrored/shared/projects/cpp/TextGame/DefensiveAttributes.h>

using namespace std;

// ----------------------------------------------------------------------------
// Player constructor
// ----------------------------------------------------------------------------
Player::Player
{
	public:
		string name = "foo: " str(rand() % 100 + 1);
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


