#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "mmsystem.h"
#include "Item.h"

using namespace std;

//base class for all characters in the game
class Character
{
private:
	//private data members to hold character name, class, combat vectors, level, hit, block, health, max health, attack rating and defense rating
	string character_name;
	string character_class;
	vector<int> character_vec;
	vector<int> def_vec;
	vector<int> charged_vec;
	int character_level;
	int character_hit;
	int character_block;
	int character_health;
	int character_max_health;
	float attack_rating;
	float defense_rating;
public:
	//constructor for character class
	Character(string name, string class_type, int level)
	{
		character_name = name;
		character_class = class_type;
		character_level = level;
		character_hit = 0;
		character_block = 0;
		character_health = 0;
		character_max_health = 0;
		attack_rating = 0;
		defense_rating = 0;

		fillVectors();
	}

	//setters and getters for private data members
	string getName()
	{
		return character_name;
	}

	void setName(string name)
	{
		character_name = name;
	}

	string getClass()
	{
		return character_class;
	}

	void setClass(string class_str)
	{
		character_class = class_str;
	}

	int getLevel()
	{
		return character_level;
	}

	void setLevel(int lvl)
	{
		character_level = lvl;
	}

	int getHit()
	{
		return character_hit;
	}

	int getNewBalancedHit(int i)
	{
		character_hit = character_vec[i] * attack_rating;
		return character_hit;
	}

	int getNewChargedHit(int i)
	{
		character_hit = charged_vec[i] * attack_rating;
		return character_hit;
	}

	void setHit(int i)
	{
		character_hit = i;
	}

	int getBlock()
	{
		return character_block;
	}

	int getNewBlock(int i)
	{
		character_block = def_vec[i] * defense_rating;
		return character_block;
	}

	void setBlock(int i)
	{
		character_block = i;
	}

	int getHealth()
	{
		return character_health;
	}

	int getMaxHealth()
	{
		return character_max_health;
	}

	void setHealth(int i)
	{
		character_health = i;
	}

	void setMaxHealth(int i)
	{
		character_max_health = i;
	}

	float getAttackRating()
	{
		return attack_rating;
	}

	void setAttackRating(float f)
	{
		attack_rating = f;
	}

	float getDefenseRating()
	{
		return defense_rating;
	}

	void setDefenseRating(float f)
	{
		defense_rating = f;
	}

	//fills the combat vectors with values so that a RNG value can determine the hit or block during combat phase
	void fillVectors()
	{
		character_vec.resize(100);
		def_vec.resize(100);
		charged_vec.resize(100);
		int i = 0;
		while (i < (character_vec.size()))
		{
			if (i < 20)
			{
				character_vec[i] = 0;
			}

			else if (i < 50)
			{
				character_vec[i] = 1;
			}

			else if (i < 80)
			{
				character_vec[i] = 2;
			}

			else if (i < 90)
			{
				character_vec[i] = 3;
			}

			else if (i < 99)
			{
				character_vec[i] = 4;
			}

			else if (i == 99)
			{
				character_vec[i] = 6;
			}

			i++;
		}

		i = 0;

		while (i < (def_vec.size()))
		{
			if (i < 60)
			{
				def_vec[i] = .2;
			}

			else if (i < 80)
			{
				def_vec[i] = .4;
			}

			else if (i < 95)
			{
				def_vec[i] = .8;
			}

			else if (i < 100)
			{
				def_vec[i] = 1;
			}
			i++;
		}

		i = 0;

		while (i < (charged_vec.size()))
		{
			if (i < 40)
			{
				charged_vec[i] = 0;
			}

			else if (i < 70)
			{
				charged_vec[i] = 3;
			}

			else if (i < 80)
			{
				charged_vec[i] = 4;
			}

			else if (i < 90)
			{
				charged_vec[i] = 5;
			}

			else if (i < 99)
			{
				charged_vec[i] = 6;
			}

			else if (i == 99)
			{
				charged_vec[i] = 8;
			}
			i++;
		}
	}
};
