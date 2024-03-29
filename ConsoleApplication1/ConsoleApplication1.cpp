
#include "pch.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "mmsystem.h"
#include "Item.h"
#pragma comment(lib, "winmm.lib")

using namespace std;

int main()
{
	cout << "--------------------------" << endl;
	cout << "Welcome to Forsaken Blood!" << endl;
	cout << "--------------------------" << endl;
	cout << endl;
	cout << "Press 1 to begin a new game" << endl;
	string new_game;
	getline(cin, new_game);
	transform(new_game.begin(), new_game.end(), new_game.begin(), tolower);
	srand(time(NULL));

	if (new_game == "1")
	{
		PlaySound(TEXT("Opening.wav"), NULL, SND_ASYNC);
		
		cout << "Please enter a character name" << endl;
		string character_name;
		getline(cin, character_name);
		cout << "Welcome " << character_name << endl;
		cout << "Please choose a class from the following options" << endl;
		cout << "1 [Knight] | 2 [Assassin]" << endl;
		string character_class;
		getline(cin, character_class);
		transform(character_class.begin(), character_class.end(), character_class.begin(), tolower);
		if (character_class != "1" && character_class != "2")
		{
			bool valid_class = false;
			while (valid_class == false)
			{
				cout << "Enter a valid command" << endl;
				getline(cin, character_class);
				transform(character_class.begin(), character_class.end(), character_class.begin(), tolower);
				if (character_class == "1" || character_class == "2")
				{
					valid_class = true;
				}
			}
		}
		if (character_class == "1")
		{
			character_class = "knight";
		}
		else if (character_class == "2")
		{
			character_class = "assassin";
		}
		Player player1 = Player(character_name, character_class, 1);
		Game game(2, player1, 0, 0, 0, 0, 0);

		cout << "Press enter to confirm your character" << endl;
		string confirm;
		getline(cin, confirm);
		player1.setUp();
		game.setPlayer(player1);
		PlaySound(NULL, 0, 0);
		game.playSong(game.getSongCount());

		cout << game.startDialogue(game.getDialogueCount());
		string confirm1;
		getline(cin, confirm1);

		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);
		cout << endl;
		PlaySound(NULL, 0, 0);
		game.playSong(game.getSongCount());

		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);

		game.startFight(game.getFightCount());

		if (game.isEndGame())
		{
			cout << "GAME OVER" << endl;
			return 0;
		}

		cout << "Before and after each merchant interaction and before each fight, you will be able to manage your inventory" << endl;
		game.manageInventory();
		cout << "After each fight you will be able to buy or sell items using a merchant" << endl;
		game.interactMerchant();
		game.manageInventory();
		
		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);
		PlaySound(NULL, 0, 0);
		game.playSong(game.getSongCount());
	
		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);

		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);

		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);

		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);
		PlaySound(NULL, 0, 0);
		game.playSong(game.getSongCount());

		game.manageInventory();
		game.startFight(game.getFightCount());

		if (game.isEndGame())
		{
			cout << "GAME OVER" << endl;
			return 0;
		}

		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);
		PlaySound(NULL, 0, 0);
		game.playSong(game.getSongCount());

		game.manageInventory();
		game.interactMerchant();
		game.manageInventory();

		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);

		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);
		PlaySound(NULL, 0, 0);
		game.playSong(game.getSongCount());

		game.manageInventory();
		game.startFight(game.getFightCount());

		if (game.isEndGame())
		{
			cout << "GAME OVER" << endl;
			return 0;
		}

		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);
		PlaySound(NULL, 0, 0);
		game.playSong(game.getSongCount());

		game.manageInventory();
		game.interactMerchant();
		game.manageInventory();
		game.startFight(game.getFightCount());

		if (game.isEndGame())
		{
			cout << "GAME OVER" << endl;
			return 0;
		}

		PlaySound(NULL, 0, 0);
		game.playSong(game.getSongCount());
		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);

		cout << game.startDialogue(game.getDialogueCount());
		
		cout << "Press enter to end the game" << endl;
		confirm1 = "";
		getline(cin, confirm1);
		return 0;
	}

	else if (new_game != "1")
	{
		cout << "You don't follow directions very well. Go play something else." << endl;
		return 0;
	}
	
}
