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
#include "Item.h"

using namespace std;

class Boss: public Enemy
{
public:

	Boss(string name, string class_type, int level, int health, float attack_rating, float defense_rating) : Enemy(name, class_type, level, health, attack_rating, defense_rating)
	{
		
	}
};