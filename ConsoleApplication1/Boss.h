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

class Boss: public Character
{
public:

	Boss(string name, string class_type, int level) : Character(name,class_type,level)
	{
		
	}
};