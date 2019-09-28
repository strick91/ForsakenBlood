
#include "pch.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "mmsystem.h"
#pragma comment(lib, "winmm.lib")



using namespace std;

int main()
{
	cout << "--------------------------" << endl;
	cout << "Welcome to Forsaken Blood!" << endl;
	cout << "--------------------------" << endl;
	cout << endl;
	cout << "Would you like to start a new game?" << endl;
	string new_game;
	getline(cin, new_game);
	transform(new_game.begin(), new_game.end(), new_game.begin(), tolower);

	/*struct Player
	{
		string player_name = " ";
		string player_class = " ";
		vector<int> player_vec;
		vector<int> def_vec;
		vector<int> aoe_vec;
		vector<int> charged_vec;
		vector<string> inventory;
		vector<string> equipment;
		int player_level = 0;
		int player_hit = 0;
		int player_block = 0;
		int player_health = 0;
		int player_defense = 0;
		int player_strength = 0;
		float melee_rating = 0;
		float magic_rating = 0;
		float attack_rating = 0;
		float melee_defense_rating = 0;
		float magic_defense_rating = 0;
		float def_rating = 0;
	};*/

	struct Boss
	{
		string boss_class = " ";
		string boss_name = " ";
		vector<int> boss_vec;
		vector<int> def_vec;
		int boss_hit = 0;
		int boss_block = 0;
		int boss_health = 0;
		int boss_defense = 0;
		int boss_strength = 0;
		float melee_rating = 0;
		float magic_rating = 0;
		float attack_rating = 0;
		float melee_defense_rating = 0;
		float magic_defense_rating = 0;
		float def_rating = 0;
	};

	struct Enemy
	{
		string enemy_class = " ";
		string enemy_name = " ";
		vector<int> enemy_vec;
		vector<int> def_vec;
		int enemy_hit = 0;
		int enemy_block = 0;
		int enemy_health = 0;
		int enemy_defense = 0;
		int enemy_strength = 0;
		float melee_rating = 0;
		float magic_rating = 0;
		float attack_rating = 0;
		float melee_defense_rating = 0;
		float magic_defense_rating = 0;
		float def_rating = 0;
	};

	//Player player1;

	if (new_game == "yes" || new_game == "yep" || new_game == "sure" || new_game == "ye" || new_game == "yea" || new_game == "yeah" || new_game == "yeah buddy!" || new_game == "yeah buddy")
	{
		PlaySound(TEXT("Opening.wav"), NULL, SND_ASYNC);
		cout << "Please enter a character name" << endl;
		string character_name;
		getline(cin, character_name);
		//player1.player_name = character_name;
		cout << "Welcome " << character_name << endl;
		cout << "Please choose a class from the following options" << endl;
		cout << "Knight or Mage?" << endl;
		string character_class;
		getline(cin, character_class);
		transform(character_class.begin(), character_class.end(), character_class.begin(), tolower);
		Player player1 = Player(character_name, character_class, 1);
		cout << player1.getName() << endl;

		cout << "Press 1 to confirm your character" << endl;
		string confirm;
		getline(cin, confirm);
		if (confirm != "1")
		{
			cout << "Too bad" << endl;
		}
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("FirstScene.wav"), NULL, SND_ASYNC);

		cout << endl;
		cout << "A blood moon illuminates the night sky, tinting it red like the blood about to be spilt." << endl;
		cout << character_name << ": Mommy?" << endl;
		cout << "Mother: Shhhhh... Be very quiet ok? Just stay here until I come back to get you, ok?" << endl;
		cout << character_name << ": Ok..." << endl;
		cout << "*The sound of wood splintering as the door explodes.*" << endl;
		cout << "Mother: No! Please don't! Why are you doing this?!" << endl;
		cout << "Murderer: Shut up and stop begging. There's nothing you can do or say that is going to save your life, so just save your breath." << endl;
		cout << "*The sound of a sharp blade slicing across flesh*" << endl;
		cout << "Through a crack in the door you see a mist of blood that for a split moment combines with the crimson sky as one. In this split moment, time ceases to flow and the murderer's eyes meet your gaze through the crack in the door." << endl;
		cout << "The moment passes and the blood mist falls back to Earth, spraying across the ground in an intricate pattern. The murderer hears the sound of scurrying behind him and leaves the area." << endl;
		cout << "You slightly crack the door to peak out at your mother, but all you see is your mother laying face down in a pool of blood, the crimson liquid flowing from her neck and engulfing her face." << endl;
		cout << "You quickly close the door and fade out of conciousness." << endl;
		cout << "Press 1 to continue" << endl;
		string confirm1;
		getline(cin, confirm1);
		PlaySound(NULL, 0, 0);

		cout << endl;
		cout << "20 years later" << endl;
		cout << endl;
		cout << "Your entire birth family has been slaughtered, but you have survived. You are the only surviving member of the royal bloodline that once ruled the nation, only you're completely unaware." << endl;
		cout << "The woman you now call your mother and have been calling your mother for the past 20 years is not your real mother. She was a servant to your family. A maid that once looked after you when your family was too preoccupied with royal duties." << endl;
		cout << "This woman's name is Penelope. As long as you can remember you've called her Mom and she has always treated as if you were her own child." << endl;
		cout << "Strangely no matter how hard you try, you can never remember life as a small child. You brush it off as being too young to remember, but have heard others talk about memories from such ages." << endl;
		cout << "It's as if the memories just no longer exist. As if that section of your brain has been erased. Exterminated." << endl;
		cout << "You have been training to join the military force and you're the most impressive recruit they have ever seen. Your physical strength and prowess in combat is better than almost all the active members." << endl;
		cout << "Penelope has worked as a maid for another family ever since she took you on as her own. The life she has been able to provide has been less than lavish and that of a commoner. A life far less luxorious than you were born into" << endl;
		cout << "Training ran late today. Walking home, exhausted, muscles aching, you walk past the home Penelope works at. The moon is a blood red color, so much so you stare at it, waiting for blood to drip from the edges. You suddenly feel anxious. You don't know why, but the crimson sky is unearthing all kinds of emotions. You approach the door to knock and see if she is nearly done. As you raise your fist to knock the door opens." << endl;
		cout << "Press 1 to continue" << endl;
		confirm1 = "";
		getline(cin, confirm1);
		cout << endl;
		PlaySound(TEXT("FirstFight.wav"), NULL, SND_ASYNC);
		cout << "Surprised at the door opening and unaware of what has been happening inside, you are an easy target. One swift blow to the forehead with the hilt of a sword is enough to knock you out." << endl;
		cout << "When you come to, you are unable to move, under the effect of a binding spell. Penelope screams and goes to run out the front door when she is sliced across the back with the sharp blade of the sword." << endl;
		cout << "She lets out a scream and falls to the floor. She continues to make her way toward the street, blundering around on the floor and eventually making her way outside. All you can do is watch as her attacker follows her to the street." << endl;
		cout << "She turns around and begins begging for her life. For your life. The attacker just smirks and delivers a swift blow across her throat. The red mist spraying toward the sky. In that moment, as the blood and the red sky begin to mix, the memory of that night begins to flood back into your brain." << endl;
		cout << "The barrier blocking off that section of your brain comes crashing down. You know Penelope wasn't your mother. You remember what happened to your family. You remember who you are. What you are. The one true ruler of this nation." << endl;
		cout << "This revelation combined with the immense rage coarsing through your veins grants you the strength to shatter the shackles of the spell. Now free to move as you please, you face the attacker that murdered Penelope." << endl;
		cout << endl;
		cout << "Press 1 to enter the combat phase" << endl;
		confirm1 = "";
		getline(cin, confirm1);

		Enemy penelope_attacker;
		penelope_attacker.enemy_vec.resize(100);
		penelope_attacker.def_vec.resize(100);
		penelope_attacker.enemy_class = "knight";
		penelope_attacker.enemy_health = 8;
		penelope_attacker.enemy_defense = 1;
		penelope_attacker.enemy_strength = 1;
		penelope_attacker.magic_defense_rating = 1;
		penelope_attacker.magic_rating = 1;
		penelope_attacker.melee_defense_rating = 1;
		penelope_attacker.melee_rating = 1;
		penelope_attacker.attack_rating = 1;
		penelope_attacker.def_rating = 1;

		int i = 0;

		i = 0;
		while (i < (penelope_attacker.enemy_vec.size()))
		{
			if (i < 30)
			{
				penelope_attacker.enemy_vec[i] = 0;
			}

			else if (i < 70)
			{
				penelope_attacker.enemy_vec[i] = 1;
			}

			else if (i < 90)
			{
				penelope_attacker.enemy_vec[i] = 2;
			}

			else if (i < 95)
			{
				penelope_attacker.enemy_vec[i] = 3;
			}

			else if (i < 99)
			{
				penelope_attacker.enemy_vec[i] = 4;
			}

			else if (i == 99)
			{
				penelope_attacker.enemy_vec[i] = 6;
			}

			i++;
		}

		//i = 0;
		
		while (i < (penelope_attacker.def_vec.size()))
		{
			if (i < 60)
			{
				penelope_attacker.def_vec[i] = 0;
			}

			else if (i < 80)
			{
				penelope_attacker.def_vec[i] = 1;
			}

			else if (i < 95)
			{
				penelope_attacker.def_vec[i] = 2;
			}

			else if (i < 100)
			{
				penelope_attacker.def_vec[i] = 3;
			}
			i++;
		}
		
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
		
		cout << endl;
		cout << "You stand over your murderous foe." << endl;
		cout << character_name << ": Why did you kill her you sick fuck?!" << endl;
		cout << "He gives you a sickly grin, his blood stained teeth gleaming in the moonlit night." << endl;
		cout << "Infuriated you put both hands on either side of his head and smash the back of his skull into the cobblestone paved road until blood and brains begin to gush out the back of his head." << endl;
		cout << "As you continue smashing skull against stone, more and more blood and brain matter splatter across your face with each blow." << endl;
		cout << "After you purge the rage from your body, you look over and see the lifeless body of Penelope sprawled across the road. Tears begin to blur your vision as you stand and walk toward her corpse." << endl;
		cout << "You stand over her only briefly, wishing you had done more before you gently lift her body from the bloodied cobblestone and into your arms. A trail of blood follows you as you carry her home." << endl;
		cout << endl;
		cout << "Press 1 to continue" << endl;
		confirm1 = "";
		getline(cin, confirm1);
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("AfterFirstFight.wav"), NULL, SND_ASYNC);
		cout << "24 hours later" << endl;
		cout << endl;
		cout << "While going through Penelope's personal items, you find an envelope with your name written on the front of it. You open the envelope and find a letter written to you from Penelope." << endl;
		cout << "Upon reading the letter, you learn the details about yourself and what exactly had happened to your family. Someone wanted the power and wealth your family held and so they decided to forcibly take it." << endl;
		cout << "But who would have that kind of power and ability to do such a thing? To overthrow the royal family. All one needs to do is look at who is in power now. The king currently ruling is no other than the general that had led the military sworn to protect the kingdom and the royal family." << endl;
		cout << "Your only goal in life now is to exact vengence on those that had taken your family from you and taken away what was rightfully yours." << endl;
		cout << "Press 1 to continue" << endl;
		confirm1 = "";
		getline(cin, confirm1);
		PlaySound(NULL, 0, 0);
	}
	
}
