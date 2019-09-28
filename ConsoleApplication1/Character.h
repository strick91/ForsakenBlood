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

class Character
{
private:
	string character_name;
	string character_class;
	vector<int> character_vec;
	vector<int> def_vec;
	vector<int> aoe_vec;
	vector<int> charged_vec;
	vector<string> inventory;
	vector<string> equipment;
	int character_level;
	int character_hit;
	int character_block;
	int character_health;
	float attack_rating;
	float defense_rating;
public:
	Character(string name, string class_type, int level)
	{
		character_name = name;
		character_class = class_type;
		character_level = level;
		character_hit = 0;
		character_block = 0;
		character_health = 0;
		attack_rating = 0;
		defense_rating = 0;

		setUp();
	}

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

	void setHit(int i)
	{
		character_hit = i;
	}

	int getBlock()
	{
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

	void setHealth(int i)
	{
		character_health = i;
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

	void setUp()
	{
		character_vec.resize(100);
		def_vec.resize(100);
		aoe_vec.resize(100);
		charged_vec.resize(100);
		equipment.resize(10);
		inventory.resize(20);

		int i = 0;
		while (i < (inventory.size()))
		{
			inventory[i] = "empty";
			i++;
		}

		if (character_class == "knight")
		{
			character_class = "knight";
			character_health = 12;
			attack_rating = 1.2;
			defense_rating = 1.2;
			equipment[0] = "Iron Helmet";
			equipment[1] = "Iron Platebody";
			equipment[2] = "Iron Platelegs";
			equipment[3] = "Iron Boots";
			equipment[4] = "Iron Gauntlets";
			equipment[5] = "Iron Sword";
			equipment[6] = "Iron Shield";
			equipment[7] = "empty";
			equipment[8] = "empty";
			equipment[9] = "empty";
		}

		else if (character_class == "mage")
		{
			character_class = "mage";
			character_health = 10;
			attack_rating = 1.5;
			defense_rating = 1;
			equipment[0] = "Mage Hood";
			equipment[1] = "Mage Robetop";
			equipment[2] = "Mage Robebottom";
			equipment[3] = "Mage Boots";
			equipment[4] = "Mage Gloves";
			equipment[5] = "Battlestaff";
			equipment[6] = "empty";
			equipment[7] = "empty";
			equipment[8] = "empty";
			equipment[9] = "empty";
		}
	}

	void fillVectors(int mult)
	{
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

		while (i < (aoe_vec.size()))
		{
			if (i < 20)
			{
				aoe_vec[i] = 0;
			}

			else if (i < 60)
			{
				aoe_vec[i] = 1;
			}

			else if (i < 90)
			{
				aoe_vec[i] = 2;
			}

			else if (i < 99)
			{
				aoe_vec[i] = 3;
			}

			else if (i == 99)
			{
				aoe_vec[i] = 4;
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
