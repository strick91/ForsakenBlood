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
#include "Player.h"
#include <map>
#include "Item.h"

using namespace std;

//Merchant class (inherits from character base class). This class is for a character to act as the game merchant, for player interaction (buying and selling items).
class Merchant : public Character
{
private:
	//private data members to hold a vector of items for the merchant inventory and the gold balance for the merchant
	vector<Item> inventory;
	int gold = 100000;

public:
	//merchant constructor
	Merchant(string name, string class_type, int level, vector<Item> inv) : Character(name, class_type, level)
	{
		inventory = inv;
	}

	//dds item to merchant inventory. Needed for the buying and selling of items.
	void addItem(Item item)
	{
		inventory.push_back(item);
	}

	//getter and setter for gold balance
	int getGold()
	{
		return gold;
	}

	int setGold(int i)
	{
		gold = i;
	}

	//adds to merchant gold balance
	void addGold(int i)
	{
		gold = gold += i;
	}

	//subtracts from merchant gold balance
	void subGold(int i)
	{
		gold = gold -= i;
	}

	//displays the merchants inventory. Needed for allowing the player to choose which items they would like to buy.
	void displayInventory()
	{
		cout << endl;
		int exit = 0;
		//loops through the inventory and displays the index of the item next to the item name
		for (int i = 0; i < inventory.size(); i++)
		{
			cout << "[" << i << "] " << inventory[i].getItemName() << " [" << inventory[i].getMerchantValue() << " gold]" << endl;
			exit = i;
		}
		//if the inventory is not empty, it will add 1 to the inventory size and display the exit command as that number
		if (inventory.size() != 0)
		{
			exit++;
		}
		//if the inventory is empty, it just notifies the player the inventory is empty
		else if (inventory.size() == 0)
		{
			cout << "The merchant's inventory is empty" << endl;
		}
		cout << "[" << exit << "] exit" << endl;
	}

	//Finds the item in the inventory, adds the gold to the merchant gold balance and erases the item from the merchant inventory. Returns the item so it can be added to to the player inventory
	Item sellItem(int i)
	{
		Item item = inventory[i];
		gold += item.getMerchantValue();
		inventory.erase(inventory.begin() + i);
		return item;
	}

	//checks if the merchant has enough gold to buy the item, if so it subtracts the gold from the gold balance and adds the item to the inventory
	void buyItem(Item item)
	{
		if (gold >= item.getPlayerValue())
		{
			gold = gold - item.getPlayerValue();
			inventory.push_back(item);
		}
		else
		{
			cout << "The merchant doesn't have enough gold to buy that item" << endl;
		}
	}

	//sets inventory to vector of items
	void setInventory(vector<Item> inv)
	{
		inventory = inv;
	}

	//adds another vector of items to the existing inventory
	void addInventory(vector<Item> inv)
	{
		for (int i = 0; i < inv.size(); i++)
		{
			inventory.push_back(inv[i]);
		}
	}

	//returns inventory size
	int inventorySize()
	{
		return inventory.size();
	}
};
