#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "mmsystem.h"

using namespace std;

class Item
{
private:
	string item_type;
	string equipment_slot;
	string item_name;
	string item_rarity;
	float attack_bonus = 0.0;
	float defense_bonus = 0.0;


public:
	Item(string type, string slot, string name, string rarity, float att, float def)
	{
		item_type = type;
		equipment_slot = slot;
		item_name = name;
		item_rarity = rarity;
		attack_bonus = att;
		defense_bonus = def;
	}

	string getItemType()
	{
		return item_type;
	}

	void setItemType(string type)
	{
		item_type = type;
	}

	string getEquipmentSlot()
	{
		return equipment_slot;
	}

	void setEquipmentSlot(string slot)
	{
		equipment_slot = slot;
	}

	string getItemName()
	{
		return item_name;
	}

	void setItemName(string name)
	{
		item_name = name;
	}

	string getItemRarity()
	{
		return item_rarity;
	}

	void setItemRarity(string rarity)
	{
		item_rarity = rarity;
	}

	float getAttackBonus()
	{
		return attack_bonus;
	}

	void setAttackBonus(float att)
	{
		attack_bonus = att;
	}

	float getDefenseBonus()
	{
		return defense_bonus;
	}

	void setDefenseBonus(float def)
	{
		defense_bonus = def;
	}
};
