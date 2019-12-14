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

//Enemy class (inherits from character base class). Acts as class for all enemies in the game
class Enemy: public Character
{
private:
	//private data members for enemy drop table, gold drop table, the chosen item drop, chosen gold drop, and number of turns to determine what the gold drop will be
	vector<Item> item_drop_table;
	vector<int> gold_drop_table;
	Item item_drop = Item("default", "default", "nothing", "default", 0, 0, 0, 0);
	int gold_drop;
	int common_turns = 8;
	int uncommon_turns = 6;
	int rare_turns = 4;
	int legendary_turns = 2;

public:
	//enemy constructor
	Enemy(string name, string class_type, int level, int health, float attack_rating, float defense_rating) : Character(name, class_type, level)
	{
		setHealth(health);
		setAttackRating(attack_rating);
		setDefenseRating(defense_rating);
	}

	//sets item drop table to items passed into function
	void setItemDropTable(Item common, Item uncommon, Item rare, Item legendary)
	{
		item_drop_table.resize(4);
		item_drop_table[0] = common;
		item_drop_table[1] = uncommon;
		item_drop_table[2] = rare;
		item_drop_table[3] = legendary;
	}

	//sets gold drop table to values passed into function
	void setGoldDropTable(int common_gold, int uncommon_gold, int rare_gold, int legendary_gold)
	{
		gold_drop_table.resize(4);
		gold_drop_table[0] = common_gold;
		gold_drop_table[1] = uncommon_gold;
		gold_drop_table[2] = rare_gold;
		gold_drop_table[3] = legendary_gold;
	}

	//Uses RNG to get item from item drop table
	Item getItemDrop()
	{
		int j = 0;
		j = (rand() % 99) + 1;
		if (j > 29 && j < 70)
		{
			item_drop = item_drop_table[0];
			return item_drop;
		}
		else if (j >= 70 && j < 90)
		{
			item_drop = item_drop_table[1];
			return item_drop;
		}
		else if (j >= 90 && j < 97)
		{
			item_drop = item_drop_table[2];
			return item_drop;
		}
		else if (j >= 97 && j < 100)
		{
			item_drop = item_drop_table[3];
			return item_drop;
		}
		else
		{
			return Item("default", "default", "nothing", "default", 0, 0, 0, 0);
		}
	}

	//gets gold drop based on amount of turns the fight took
	int getGoldDrop(int fight_turns)
	{
		if (fight_turns < legendary_turns)
		{
			return gold_drop_table[3];
		}
		else if (fight_turns < rare_turns)
		{
			return gold_drop_table[2];
		}
		else if (fight_turns < uncommon_turns)
		{
			return gold_drop_table[1];
		}
		else
		{
			return gold_drop_table[0];
		}
	}

	//setter for item drop
	void setItemDrop(Item set_drop)
	{
		item_drop = set_drop;
	}
};
