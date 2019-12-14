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

//class for all items in the game
class Item
{
private:
	//private data members for item type, equipment slot, item name, item rarity, attack bonus, defense bonus and player/merchant value
	string item_type;
	string equipment_slot;
	string item_name;
	string item_rarity;
	float attack_bonus = 0.0;
	float defense_bonus = 0.0;
	int merchant_value = 0;
	int player_value = 0;


public:
	//item constructor
	Item(string type, string slot, string name, string rarity, float att, float def, int merchant_val, int player_val)
	{
		item_type = type;
		equipment_slot = slot;
		item_name = name;
		item_rarity = rarity;
		attack_bonus = att;
		defense_bonus = def;
		merchant_value = merchant_val;
		player_value = player_val;
	}

	Item()
	{

	}

	//getters and setters for data members
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

	int getMerchantValue()
	{
		return merchant_value;
	}

	void setMerchantValue(int val)
	{
		merchant_value = val;
	}

	int getPlayerValue()
	{
		return player_value;
	}

	void setPlayerValue(int val)
	{
		player_value = val;
	}
};
