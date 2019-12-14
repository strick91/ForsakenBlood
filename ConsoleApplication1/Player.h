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

//Player class (inherits from character base class). This class acts as the class for player characters.
class Player: public Character
{
private:
	//private data members for player inventory, equipment, player lives, stamina, max stamina, gold balance and equipment attack and defense bonuses
	vector<Item> inventory;
	vector<Item> equipment;
	int player_lives = 0;
	int player_stamina = 0;
	int max_player_stamina = 100;
	int gold = 50;
	float equipment_attack_bonus = 0.0;
	float equipment_defense_bonus = 0.0;

public:
	//Player class constructor
	Player(string name, string class_type, int level) : Character(name,class_type,level)
	{
		//if the chosen class is knight, it describes the class and special attack to player
		if (class_type == "knight")
		{
			cout << "You have chosen a heavily armored melee character" << endl;
			cout << "The special attack for this character is a stun, combined with a charged attack. This makes the enemy unable to block any damage at all" << endl;
		}

		//if the chosen class is assassin, it describes the class and special attack to player
		else if (class_type == "assassin")
		{
			cout << "You have chosen a light armored, fast melee character" << endl;
			cout << "The special attack for this character is a double attack" << endl;
		}

		player_lives = 3;
	}

	//sets up the player object for a new game. Gives the player a health and stamina potion and the proper equipment depending on the class
	void setUp()
	{
		Item Health_potion = Item("Consumable", "Inventory", "Health Potion", "Rare", 0.0, 0.0, 275, 150);
		Item Stamina_potion = Item("Consumable", "Inventory", "Stamina Potion", "Rare", 0.0, 0.0, 225, 120);
		string health_name = Health_potion.getItemName();
		string stamina_name = Stamina_potion.getItemName();
		inventory.push_back(Health_potion);
		inventory.push_back(Stamina_potion);

		if (getClass() == "knight")
		{
			setClass("knight");
			setHealth(12);
			setMaxHealth(12);
			setPlayerStamina(100);
			setAttackRating(1.2);
			setDefenseRating(1.2);
			Item Iron_helmet = Item("Armor", "Head_slot", "Iron Helmet", "Common", 0.0, 0.1, 40, 20);
			equipment.push_back(Iron_helmet);
			Item Iron_platebody = Item("Armor", "Body_slot", "Iron Platebody", "Common", 0.0, 0.3, 100, 50);
			equipment.push_back(Iron_platebody);
			Item Iron_platelegs = Item("Armor", "Legs_slot", "Iron Platelegs", "Common", 0.0, 0.2, 75, 30);
			equipment.push_back(Iron_platelegs);
			Item Iron_greatsword = Item("Weapon", "Weapon_slot", "Iron Greatsword", "Common", 0.4, 0.0, 125, 75);
			equipment.push_back(Iron_greatsword);
		}

		else if (getClass() == "assassin")
		{
			setClass("assassin");
			setHealth(10);
			setMaxHealth(10);
			setPlayerStamina(100);
			setAttackRating(1.5);
			setDefenseRating(1.0);
			Item Leather_hood = Item("Armor", "Head_slot", "Leather Hood", "Common", 0.0, 0.0, 40, 20);
			equipment.push_back(Leather_hood);
			Item Leather_body = Item("Armor", "Body_slot", "Leather Body", "Common", 0.0, 0.2, 100, 50);
			equipment.push_back(Leather_body);
			Item Leather_legs = Item("Armor", "Legs_slot", "Leather Legs", "Common", 0.0, 0.1, 75, 30);
			equipment.push_back(Leather_legs);
			Item Iron_twinswords = Item("Weapon", "Weapon_slot", "Iron Twinswords", "Common", 0.5, 0.0, 125, 75);
			equipment.push_back(Iron_twinswords);
		}
		getPlayerAttackBonus();
		getPlayerDefenseBonus();
	}

	//getters and setters for player lives
	int getPlayerLives()
	{
		return player_lives;
	}

	void setPlayerLives(int i)
	{
		player_lives = i;
	}

	//incrementing and decrementing of player lives for gameplay uses
	void incrementPlayerLives()
	{
		player_lives++;
	}

	void decrementPlayerLives()
	{
		player_lives--;
	}

	//getters and setters for stamina
	int getPlayerStamina()
	{
		return player_stamina;
	}

	void setPlayerStamina(int i)
	{
		if (i > 100)
		{
			player_stamina = 100;
		}

		else
		{
			player_stamina = i;
		}
	}

	int getMaxPlayerStamina()
	{
		return max_player_stamina;
	}

	//getters for potions
	int getNumberHealthPotions()
	{
		int count = 0;
		for (int i = 0; i < inventory.size(); i++)
		{
			if (inventory[i].getItemName() == "Health Potion")
			{
				count++;
			}
		}
		return count;
	}

	int getNumberStaminaPotions()
	{
		int count = 0;
		for (int i = 0; i < inventory.size(); i++)
		{
			if (inventory[i].getItemName() == "Stamina Potion")
			{
				count++;
			}
		}
		return count;
	}

	int getNumberPhoenixPotions()
	{
		int count = 0;
		for (int i = 0; i < inventory.size(); i++)
		{
			if (inventory[i].getItemName() == "Phoenix Potion")
			{
				count++;
			}
		}
		return count;
	}

	//loops the player inventory searching for an item with the same name as the consumed item. If it finds it, it consumes the item and then displays the number remaining
	void consumeItem(string name)
	{
		bool found_item = false;
		for (int i = 0; i < inventory.size(); i++)
		{
			if (inventory[i].getItemName() == name)
			{
				if (name == "Health Potion")
				{
					found_item = true;
					setHealth(getMaxHealth());
					inventory.erase(inventory.begin() + i);
					cout << "You used a Health Potion. You have " << getNumberHealthPotions() << " left" << endl;
					break;
				}
				else if (name == "Stamina Potion")
				{
					found_item = true;
					player_stamina = max_player_stamina;
					inventory.erase(inventory.begin() + i);
					cout << "You used a Stamina Potion. You have " << getNumberStaminaPotions() << " left" << endl;
					break;
				}
				else if (name == "Phoenix Potion")
				{
					found_item = true;
					inventory.erase(inventory.begin() + i);
					cout << "You used a Phoenix Potion. You have " << getNumberPhoenixPotions() << " left" << endl;
					break;
				}
			}
		}
		if (found_item == false)
		{
			cout << "You don't have any " << name << "s left." << endl;
		}
	}

	//getters for combat bonuses
	float getPlayerAttackBonus()
	{
		float att_bonus = 0.0;
		for (int i = 0; i < equipment.size(); i++)
		{
			att_bonus += equipment[i].getAttackBonus();
		}
		equipment_attack_bonus = att_bonus;
		return equipment_attack_bonus;
	}

	float getPlayerDefenseBonus()
	{
		float def_bonus = 0.0;
		for (int i = 0; i < equipment.size(); i++)
		{
			def_bonus += equipment[i].getDefenseBonus();
		}
		equipment_defense_bonus = def_bonus;
		return equipment_defense_bonus;
	}

	//getters for player combat vectors
	int getNewBalancedHitPlayer(int i)
	{
		setHit(round(getNewBalancedHit(i) + equipment_attack_bonus));
		return getHit();
	}

	int getNewChargedHitPlayer(int i)
	{
		setHit(round(getNewChargedHit(i) + equipment_attack_bonus));
		return getHit();
	}

	int getNewBlockPlayer(int i)
	{
		setBlock(round(getNewBlock(i) + equipment_defense_bonus));
		return getBlock();
	}

	//levels up player. Increments player level, increases player max health by 2 and increases attack and defense rating by .2
	void levelUp()
	{
		setLevel(getLevel() + 1);
		setMaxHealth(getMaxHealth() + 2);
		setAttackRating(getAttackRating() + .2);
		setDefenseRating(getDefenseRating() + .2);
	}

	//adds item to inventory
	void addItem(Item item)
	{
		inventory.push_back(item);
	}

	//gets item in inventory
	Item getItem(int i)
	{
		return inventory[i];
	}

	//finds item in inventory, then equips item to correct equipment slot.
	void equipItem(int i)
	{
		Item item = inventory[i];
		string slot = item.getEquipmentSlot();
		if (slot == "Head_slot")
		{
			if (equipment[0].getItemName() != "empty")
			{
				inventory.push_back(equipment[0]);
			}
			equipment[0] = item;
			inventory.erase(inventory.begin() + i);
		}

		else if (slot == "Body_slot")
		{
			if (equipment[1].getItemName() != "empty")
			{
				inventory.push_back(equipment[1]);
			}
			equipment[1] = item;
			inventory.erase(inventory.begin() + i);
		}

		else if (slot == "Legs_slot")
		{
			if (equipment[2].getItemName() != "empty")
			{
				inventory.push_back(equipment[2]);
			}
			equipment[2] = item;
			inventory.erase(inventory.begin() + i);
		}

		else if (slot == "Weapon_slot")
		{
			if (equipment[3].getItemName() != "empty")
			{
				inventory.push_back(equipment[3]);
			}
			equipment[3] = item;
			inventory.erase(inventory.begin() + i);
		}

		else
		{
			cout << "You cannot equip that item" << endl;
		}
	}

	//unequips item currently equipped and places it in player inventory
	void unequipItem(int i)
	{
		Item item = equipment[i];
		Item empty_item = Item("default", "default", "empty", "default", 0, 0, 0, 0);
		if (i == 0)
		{
			if (item.getItemName() != "empty")
			{
				inventory.push_back(equipment[0]);
			}
			equipment[0] = empty_item;
		}

		else if (i == 1)
		{
			if (item.getItemName() != "empty")
			{
				inventory.push_back(equipment[1]);
			}
			equipment[1] = empty_item;
		}

		else if (i == 2)
		{
			if (item.getItemName() != "empty")
			{
				inventory.push_back(equipment[2]);
			}
			equipment[2] = empty_item;
		}

		else if (i == 3)
		{
			if (item.getItemName() != "empty")
			{
				inventory.push_back(equipment[3]);
			}
			equipment[3] = empty_item;
		}
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

	//adds to gold balance
	void addGold(int i)
	{
		gold = gold += i;
	}

	//subtracts from gold balance
	void subGold(int i)
	{
		gold = gold -= i;
	}


	//displays player inventory for selling of items and equipping items.
	void displayInventory()
	{
		int exit = 0;
		cout << endl;
		for (int i = 0; i < inventory.size(); i++)
		{
			cout << "[" << i << "] " << inventory[i].getItemName() << " [" << inventory[i].getPlayerValue() << " gold]" << endl;
			exit = i;
		}
		if (inventory.size() != 0)
		{
			exit++;
		}

		else if (inventory.size() == 0)
		{
			cout << "Your inventory is empty" << endl;
		}
		cout << "[" << exit << "] exit" << endl;
	}

	//displays equipment for equipping and unequipping of items
	void displayEquipment()
	{
		cout << endl;
		for (int i = 0; i < equipment.size(); i++)
		{
			cout << "[" << i << "] " << equipment[i].getItemName() << " [" << equipment[i].getPlayerValue() << " gold]" << endl;
		}
		cout << "[4] exit" << endl;
	}

	//returns inventory size
	int inventorySize()
	{
		return inventory.size();
	}

	//sells item in player inventory and adds to player gold balance
	Item sellItem(int i)
	{
		Item item = inventory[i];
		gold += item.getPlayerValue();
		inventory.erase(inventory.begin() + i);
		return item;
	}

	//if player has enough gold, buys item, adds item to inventory and subtracts from player gold balance
	void buyItem(Item item)
	{
		if (gold >= item.getMerchantValue())
		{
			gold = gold - item.getMerchantValue();
			inventory.push_back(item);
		}
		else
		{
			cout << "You don't have enough gold to buy that item" << endl;
		}
	}
};