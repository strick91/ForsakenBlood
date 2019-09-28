
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

	if (new_game == "1")
	{
		PlaySound(TEXT("Opening.wav"), NULL, SND_ASYNC);
		
		cout << "Please enter a character name" << endl;
		string character_name;
		getline(cin, character_name);
		cout << "Welcome " << character_name << endl;
		cout << "Please choose a class from the following options" << endl;
		cout << "Knight or Mage?" << endl;
		string character_class;
		getline(cin, character_class);
		transform(character_class.begin(), character_class.end(), character_class.begin(), tolower);
		Player player1 = Player(character_name, character_class, 1);
		Game game(2, player1, 0, 0, 0, 0, 0);
		cout << player1.getName() << endl;
		cout << player1.getLevel() << endl;
		cout << player1.getClass() << endl;

		cout << "Press 1 to confirm your character" << endl;
		string confirm;
		getline(cin, confirm);
		if (confirm != "1")
		{
			cout << "Too bad" << endl;
		}
		PlaySound(NULL, 0, 0);
		game.playSong(game.getSongCount());

		cout << game.startDialogue(game.getDialogueCount());
		string confirm1;
		getline(cin, confirm1);
		PlaySound(NULL, 0, 0);

		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);
		cout << endl;
		game.playSong(game.getSongCount());

		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);

		Enemy penelope_attacker=Enemy("penelope_attacker", "knight", 1);
		cout << penelope_attacker.getName() << endl;
		cout << penelope_attacker.getClass() << endl;
		
		int j = 0;
		int enemy_health_temp = 0;
		int player_health_temp = 0;
		int player_orig_health = player1.getHealth();


		/*while ((player1.getHealth() > 0) && (penelope_attacker.enemy_health > 0))
		{
			cout << "Player health: " << player1.getHealth() << endl;
			cout << "Enemy health: " << penelope_attacker.enemy_health << endl;
			cout << "Would you like to attack or pass? Enter 1 to attack and 2 to pass." << endl;
			string move;
			getline(cin, move);
			transform(move.begin(), move.end(), move.begin(), tolower);
			if (move == "1")
			{
				cout << "Enter 1 to use a balanced attack, 2 to use a charged attack or 3 to use an area of effect attack." << endl;
				string ability;
				getline(cin, ability);
				if (ability == "1")
				{
					srand((unsigned)time(0));
					j = 0;
					j = (rand() % 99) + 1;
					player1.setHit((player1.player_vec[j]) * (player1.melee_rating));

					srand((unsigned)time(0));
					j = 0;
					j = (rand() % 99) + 1;
					penelope_attacker.enemy_block = (penelope_attacker.def_vec[j]) * (penelope_attacker.def_rating);

					if (penelope_attacker.enemy_block >= player1.player_hit)
					{
						player1.player_hit = 0;
					}

					else if (penelope_attacker.enemy_block < player1.player_hit)
					{
						player1.player_hit = (player1.player_hit) - (penelope_attacker.enemy_block);
					}

					enemy_health_temp = (penelope_attacker.enemy_health) - player1.player_hit;
					penelope_attacker.enemy_health = enemy_health_temp;
					cout << "You have dealt " << player1.player_hit << " damage!" << endl;
				}

				else if (ability == "2")
				{
					srand((unsigned)time(0));
					j = 0;
					j = (rand() % 99) + 1;
					player1.player_hit = (player1.charged_vec[j]) * (player1.melee_rating);

					srand((unsigned)time(0));
					j = 0;
					j = (rand() % 99) + 1;
					penelope_attacker.enemy_block = (penelope_attacker.def_vec[j]) * (penelope_attacker.def_rating);

					if (penelope_attacker.enemy_block >= player1.player_hit)
					{
						player1.player_hit = 0;
					}

					else if (penelope_attacker.enemy_block < player1.player_hit)
					{
						player1.player_hit = (player1.player_hit) - (penelope_attacker.enemy_block);
					}

					enemy_health_temp = (penelope_attacker.enemy_health) - player1.player_hit;
					penelope_attacker.enemy_health = enemy_health_temp;
					cout << "You have dealt " << player1.player_hit << " damage!" << endl;
				}

				else if (ability == "3")
				{
					srand((unsigned)time(0));
					j = 0;
					j = (rand() % 99) + 1;
					player1.player_hit = (player1.aoe_vec[j]) * (player1.melee_rating);

					srand((unsigned)time(0));
					j = 0;
					j = (rand() % 99) + 1;
					penelope_attacker.enemy_block = (penelope_attacker.def_vec[j]) * (penelope_attacker.def_rating);

					if (penelope_attacker.enemy_block >= player1.player_hit)
					{
						player1.player_hit = 0;
					}

					else if (penelope_attacker.enemy_block < player1.player_hit)
					{
						player1.player_hit = (player1.player_hit) - (penelope_attacker.enemy_block);
					}

					enemy_health_temp = (penelope_attacker.enemy_health) - player1.player_hit;
					penelope_attacker.enemy_health = enemy_health_temp;
					cout << "You have dealt " << player1.player_hit << " damage!" << endl;
				}

				else
				{
					cout << "That isn't an ability. Are you trying to cheat? You forfeit your turn. No mistakes allowed." << endl;
				}
			}

			if (penelope_attacker.enemy_health > 0)
			{
				cout << "Look out, the enemy is attacking!" << endl;
				srand((unsigned)time(0));
				j = 0;
				j = (rand() % 99) + 1;
				penelope_attacker.enemy_hit = (penelope_attacker.enemy_vec[j]) * (penelope_attacker.attack_rating);

				srand((unsigned)time(0));
				j = 0;
				j = (rand() % 99) + 1;
				player1.player_block = (player1.def_vec[j]) * (player1.def_rating);

				if (player1.player_block >= penelope_attacker.enemy_hit)
				{
					penelope_attacker.enemy_hit = 0;
				}

				else if (player1.player_block < penelope_attacker.enemy_hit)
				{
					penelope_attacker.enemy_hit = (penelope_attacker.enemy_hit) - (player1.player_block);
				}

				player_health_temp = (player1.player_health) - penelope_attacker.enemy_hit;
				player1.player_health = player_health_temp;
				cout << "You have been dealt " << penelope_attacker.enemy_hit << " damage!" << endl;
			}
		}

		if (player1.player_health == 0)
		{
			cout << "Really? The first encounter and you're already dead? Maybe you should go play something else..." << endl;
			return 0;
		}

		else if (penelope_attacker.enemy_health == 0)
		{
			player1.player_health = player_orig_health;
		}*/
		
		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);
		PlaySound(NULL, 0, 0);
		game.playSong(game.getSongCount());
	
		cout << game.startDialogue(game.getDialogueCount());
		confirm1 = "";
		getline(cin, confirm1);
		PlaySound(NULL, 0, 0);
	}
	
}
