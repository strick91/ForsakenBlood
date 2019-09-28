#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "mmsystem.h"
#include "Character.h"

using namespace std;

class Player: public Character
{

public:
	Player(string name, string class_type, int level) : Character(name,class_type,level)
	{
		if (class_type == "knight")
		{
			cout << "You have chosen a heavily armored melee character" << endl;
		}

		else if (class_type == "mage")
		{
			cout << "You have chosen a light armored magic character" << endl;
		}
	}
};