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
#include "Item.h"
#include "Enemy.h"
#include "Boss.h"
#include "Merchant.h"


using namespace std;

//game class that acts as the game object in which the whole game is based
class Game
{
private:
	//private data members for states of the game, counts for dialogue, songs, fights, states and fight turns, the player object, all items in the game, all enemy objects in the game and the merchant object
	int INVALID = 0;
	int NEWGAME = -1;
	int DIALOGUE = -2;
	int FIGHT = -3;
	int BOSSFIGHT = -4;
	int ENDGAME = -5;
	int state = Game::INVALID;
	int dialogue_count = 0;
	int song_count = 0;
	int fight_count = 0;
	int bossfight_count = 0;
	int checkpoint = 0;
	int state_count = 0;
	int fight_turn_count = 0;
	Player main_player = Player("default", "default", 0);
	vector<wstring> Songs{ L"FirstScene.wav", L"FirstFight.wav", L"AfterFirstFight.wav", L"SecondFight.wav", L"AfterSecondFight.wav", L"ThirdFight.wav", L"FinalFight.wav", L"AfterFinalFight.wav" };
	string dialogue1 = "\nA blood moon illuminates the night sky, tinting it red like the blood about to be spilt.\nYou: Mommy?\nMother: Shhhhh... Be very quiet ok? Just stay here until I come back to get you, ok?\nYou: Ok...\n*The sound of wood splintering as the door explodes.*\nMother: No! Please don't! Why are you doing this?!\nMurderer: Shut up and stop begging. There's nothing you can do or say that is going to save your life, so just save your breath.\n*The sound of a sharp blade slicing across flesh*\nThrough a crack in the door you see a mist of blood that for a split moment combines with the crimson sky as one. In this split moment, time ceases to flow and the murderer's eyes meet your gaze through the crack in the door.\nThe moment passes and the blood mist falls back to Earth, spraying across the ground in an intricate pattern. The murderer hears the sound of scurrying behind him and leaves the area.\nYou slightly crack the door to peak out at your mother, but all you see is your mother laying face down in a pool of blood, the crimson liquid flowing from her neck and engulfing her face.\nYou quickly close the door and fade out of conciousness.\nPress enter to continue\n";
	string dialogue2 = "\n20 years later\nYour entire birth family has been slaughtered, but you have survived. You are the only surviving member of the royal bloodline that once ruled the nation, only you're completely unaware.\nThe woman you now call your mother and have been calling your mother for the past 20 years is not your real mother. She was a servant to your family. A maid that once looked after you when your family was too preoccupied with royal duties.\nThis woman's name is Penelope. As long as you can remember you've called her Mom and she has always treated as if you were her own child.\nStrangely no matter how hard you try, you can never remember life as a small child. You brush it off as being too young to remember, but have heard others talk about memories from such ages.\nIt's as if the memories just no longer exist. As if that section of your brain has been erased. Exterminated.\nYou have been training to join the military force and you're the most impressive recruit they have ever seen. Your physical strength and prowess in combat is better than almost all the active members.\nPenelope has worked as a maid for another family ever since she took you on as her own. The life she has been able to provide has been less than lavish and that of a commoner. A life far less luxorious than you were born into\nTraining ran late today. Walking home, exhausted, muscles aching, you walk past the home Penelope works at. The moon is a blood red color, so much so you stare at it, waiting for blood to drip from the edges. You suddenly feel anxious. You don't know why, but the crimson sky is unearthing all kinds of emotions. You approach the door to knock and see if she is nearly done. As you raise your fist to knock the door opens.\nPress enter to continue\n";
	string dialogue3 = "\nSurprised at the door opening and unaware of what has been happening inside, you are an easy target.One swift blow to the forehead with the hilt of a sword is enough to knock you out.\nWhen you come to, you are unable to move, under the effect of a binding spell. Penelope screams and goes to run out the front door when she is sliced across the back with the sharp blade of the sword.\nShe lets out a scream and falls to the floor. She continues to make her way toward the street, blundering around on the floor and eventually making her way outside. All you can do is watch as her attacker follows her to the street.\nShe turns around and begins begging for her life. For your life. The attacker just smirks and delivers a swift blow across her throat. The red mist spraying toward the sky. In that moment, as the blood and the red sky begin to mix, the memory of that night begins to flood back into your brain.\nThe barrier blocking off that section of your brain comes crashing down. You know Penelope wasn't your mother. You remember what happened to your family. You remember who you are. What you are. The one true ruler of this nation.\nThis revelation combined with the immense rage coarsing through your veins grants you the strength to shatter the shackles of the spell. Now free to move as you please, you face the attacker that murdered Penelope.\nPress enter to enter the combat phase\n";
	string dialogue4 = "\nYou stand over your murderous foe.\nYou: Why did you kill her you sick bastard?!\nHe gives you a sickly grin, his blood stained teeth gleaming in the moonlit night.\nInfuriated you put both hands on either side of his head and smash the back of his skull into the cobblestone paved road until blood and brains begin to gush out the back of his head.\nAs you continue smashing skull against stone, more and more blood and brain matter splatter across your face with each blow.\nAfter you purge the rage from your body, you look over and see the lifeless body of Penelope sprawled across the road. Tears begin to blur your vision as you stand and walk toward her corpse.\nYou stand over her only briefly, wishing you had done more before gently lifting her body from the bloodied cobblestone and into your arms. A trail of blood follows you as you carry her home.\nPress enter to continue\n";
	string dialogue5 = "\n24 hours later\nWhile going through Penelope's personal items, you find an envelope with your name written on the front of it. You open the envelope and find a letter written to you from Penelope.\nUpon reading the letter, you learn the details about yourself and what exactly had happened to your family. Someone wanted the power and wealth your family held and so they decided to forcibly take it,\nBut who would have that kind of power and ability to do such a thing? To overthrow the royal family. All one needs to do is look at who is in power now. The king currently ruling is no other than the general that had led the military sworn to protect the kingdom and the royal family.\nYour only goal in life now is to exact vengence on those that had taken your family from you and taken away what was rightfully yours.\nPress enter to continue\n";
	string dialogue6 = "\nThe next day you head to the army headquarters to try to gather some information about the general, Egal.\nYou walk around the building looking for any location where any sensitive documents could be stored. You find the location, but it's under lock and key. Trying to get in now would be too risky, so you decide to come back later that night.\nPress enter to continue\n";
	string dialogue7 = "\nLater that night\nYou sneak into the building from the back and head towards the records room. There are still people in the building, so you still have to be careful not to alert anyone. You don't know how to pick a lock, so you go to find the key.\nAt the front desk, there's a large collection of keys. You find the correct key and head back to the records room. You open the door and walk into the room. There are many cabinets of documents. They seem to be sorted by year, so you look for the year in which the murders took place.\nYou find the correct cabinet but as you're going through the documents, you can't seem to find anything at all regarding to the murders. The room may be under lock and key, but they wouldn't be wanting anyone other than those directly involved to know anything about it. The only person you know for certain that had to be involved would be Egal. He must have some information, but just asking him directly would surely get you killed.\nSneaking into his residence would be nearly impossible, due to the immense security. You'll just have to do the next best thing and sneak into his right hand man's residence.\nPress enter to continue";
	string dialogue8 = "\nThe next night\nYou sneak into the Egal's right hand man's residence and begin looking for any information relating to the murders. As you're going though his desk, you see a shadow darken the floorboards near the doorway. You know that at this point it's too late to hide, as they'll hear you anyways. You stand up and stare at the doorway, waiting for the person to walk in.\nIt's the generals right hand man, Tobias.\nTobias: I knew you would begin snooping around eventually. I'm honestly surprised it took you so long.\nWhen he begins speaking, his voice immediately takes you back to that night.\nYou: I knew you would've been involved.\nTobias: If you don't know the extent of my involvement by now, you must be stupid. *he says while grinning*\nYou: So it was you! You're the one who killed my mother?!\nTobias:  *laughs* Yes, it was me.\nYou: So you had to have known I was hiding in the closet then… Why didn't you just kill me too?\nTobias: I wish I would have, it would've made everything so much simplier, but I wasn't allowed to.\nYou: You weren't allowed to? Why would Egal not allow you to kill me too? Why would he care?\nTobias: I'm done answering your questions, dead men shouldn't worry about such things.\nPress enter to continue\n";
	string dialogue9 = "\nIn one swift blow, you sever both of Tobia's legs. He screams out in agony as his body hits the floor.\nYou: Tell me why Egal wouldn't let you kill me!\nTobias: It wasn't Egal... *He whispers softly as he dies*\nIt wasn't Egal? What could that mean?\nPress enter to continue\n";
	string dialogue10 = "\nAfter searching through Tobias's belongings, you find a letter to Tobias from Egal. It reads\nTobias,\nMeet me in the old field at midnight, we have to discuss what to do about him.\nEgal\nYou know where Egal will be in a couple hours. Your only option is to go confront him. This will be your only chance, as he'll likely be alone.\nPress enter to continue\n";
	string dialogue11 = "\nA couple hours later\nYou get to the field 30 minutes early and stay hidden behind a tree. You see someone walking in the field. As they approach the edge of the field, nearest the tree you step out from behind the tree. Egal quickly realizes you're not Tobias.\nEgal: Who are you and why are you here?\nYou: I'm certain you know who I am and why I'm here. *You say as you remove your hood*\nEgal: I see… So you've killed Tobias, have you? It's to be expected, he was only ever good at killing woman and children. He wasn't very skilled in combat, but he had no heart, which made him useful in other ways.\nYou: I understand why you would want to kill my family and take control of the kingdom, but why tell Tobias not to kill me?\nEgal: I never order such a thing. If it were up to me, I would've killed you as well.\nYou: If it were up to you?\nEgal: I've said too much already.\nPress enter to continue\n";
	string dialogue12 = "\nYou thrust your blade through Egal's chest.\nEgal: No matter what you do now, your family is gone, your life is ruined and you won't be walking out of this field alive.\nYou: What are you talking about, you and I are the only two here and you're seconds from taking your final breath.\nEgal: This meeting wasn't supposed to be between just Tobias and I…\nEgal takes his final breath and spurts blood from his mouth with your blood still deep inside his chest.\nAs you look to your right, you see another figure walk out from behind a tree.\nFigure: I got here before you did, you know.\nYou: Who are you?\nAs the figure approaches, you can see their face begin to become illuminated by the moonlight. At first you don't recognize them, as their much, much older than the last time you saw them. But that voice and that face… It has to be… But it couldn't be…\nFigure: I'm your father.\nYour whole world stops. You tell yourself this must be some nightmare that you're about to wake from, but it's not.\nYou: Why? Why would you do all this?\nFather: I never cared much for a family in the first place, but it wasn't just about killing my family. Even though everyone thought the royal family to be dead, I still ruled the kingdom from the shadows.\nYou: Why not just rule the kingdom as king and not slaughter your own family? Didn't you want a heir? Is that why you didn't have me killed as well?\nFather: I didn't want some brat to take over the kingdom. I saw how spoiled and lazy you were becoming. So long as you were raised as the royal heir, you would never be worthy of taking the title.\nYou: So you slaughtered our entire family just to teach me a lesson?!\nFather: That was part of it. I wanted you to become the king, but through your own means and with your own ability. But molding you into a fit king wasn't the only reason. Having such an incident occur gave off the appearance of vulnerability to our neighboring kingdoms.\nYou: So you wanted to kingdoms to attack after the murders?\nFather: They attacked thinking we were weak, but in fact we've never been stronger. We crushed them and took their resources and kingdoms from them.\nYou: So this was a means of expanding the kingdom?\nFather: I expanded the kingdom greatly and created a heir worthy of inheriting it. I've done my duty as king.\nYou: You may think you've been the greatest king you could be, but you've failed miserably at being a husband and father. How could this all be worth it?\nFather: I won't have failed as a father if you can defeat me, here and now.\nPress enter to continue\n";
	string dialogue13 = "\nYou slay your father. Once the dust settles you sit there thinking. Thinking about what the whole point of it all was. Where can you go from here? All you wanted was to live with Penelope in peace. You never wanted to inherit the kingdom. You never wanted to play king. But she's gone and you no longer have a purpose.\nPress enter to continue\n";
	string dialogue14 = "\nThanks for playing! This game was created by Jesse Stricklin and all songs used for the sound track were created by 8 Bit Universe. The link to their youtube channel is here -> https://www.youtube.com/user/8BitUniverseMusic\n";
	vector<string> Dialogue{dialogue1, dialogue2, dialogue3, dialogue4, dialogue5, dialogue6, dialogue7, dialogue8, dialogue9, dialogue10, dialogue11, dialogue12, dialogue13, dialogue14};
	Item Merchant_voucher = Item("Voucher", "Inventory", "Merchant Voucher", "Common", 0.0, 0.0, 100, 50);
	Item Iron_helmet = Item("Armor", "Head_slot", "Iron Helmet", "Common", 0.0, 0.1, 40, 20);
	Item Iron_platebody = Item("Armor", "Body_slot", "Iron Platebody", "Common", 0.0, 0.3, 100, 50);
	Item Iron_platelegs = Item("Armor", "Legs_slot", "Iron Platelegs", "Common", 0.0, 0.2, 75, 30);
	Item Iron_greatsword = Item("Weapon", "Weapon_slot", "Iron Greatsword", "Common", 0.4, 0.0, 125, 75);
	Item Leather_hood = Item("Armor", "Head_slot", "Leather Hood", "Common", 0.0, 0.0, 40, 20);
	Item Leather_body = Item("Armor", "Body_slot", "Leather Body", "Common", 0.0, 0.2, 100, 50);
	Item Leather_legs = Item("Armor", "Legs_slot", "Leather Legs", "Common", 0.0, 0.1, 75, 30);
	Item Iron_twinswords = Item("Weapon", "Weapon_slot", "Iron Twinswords", "Common", 0.5, 0.0, 125, 75);
	Item Steel_helmet = Item("Armor", "Head_slot", "Steel Helmet", "Uncommon", 0.0, 0.2, 60, 40);
	Item Steel_platebody = Item("Armor", "Body_slot", "Steel Platebody", "Uncommon", 0.0, 0.5, 150, 75);
	Item Steel_platelegs = Item("Armor", "Legs_slot", "Steel Platelegs", "Uncommon", 0.0, 0.4, 100, 50);
	Item Steel_greatsword = Item("Weapon", "Weapon_slot", "Steel Greatsword", "Uncommon", 0.6, 0.0, 175, 95);
	Item Hardened_leather_hood = Item("Armor", "Head_slot", "Hardened Leather Hood", "Uncommon", 0.0, 0.1, 60, 30);
	Item Hardened_leather_body = Item("Armor", "Body_slot", "Hardened Leather Body", "Uncommon", 0.0, 0.3, 125, 75);
	Item Hardened_leather_legs = Item("Armor", "Legs_slot", "Hardened Leather Legs", "Uncommon", 0.0, 0.2, 100, 50);
	Item Steel_twinswords = Item("Weapon", "Weapon_slot", "Steel Twinswords", "Uncommon", 0.7, 0.0, 175, 95);
	Item Fire_infused_greatsword = Item("Weapon", "Weapon_slot", "Fire Infused Greatsword", "Rare", 0.8, 0.0, 300, 150);
	Item Lightning_infused_twinswords = Item("Weapon", "Weapon_slot", "Lightning Infused Twinswords", "Rare", 0.9, 0.0, 350, 175);
	Item Stamina_potion = Item("Consumable", "Inventory", "Stamina Potion", "Rare", 0.0, 0.0, 225, 120);
	Item Health_potion = Item("Consumable", "Inventory", "Health Potion", "Rare", 0.0, 0.0, 275, 150);
	Item Guts_greatsword = Item("Weapon", "Weapon_slot", "Gut's Greatsword", "Legendary", 1.8, 0.0, 1200, 600);
	Item Minato_twinswords = Item("Weapon", "Weapon_slot", "Minato Twinswords", "Legendary", 2.0, 0.0, 1500, 750);
	Item Phoenix_potion = Item("Consumable", "Inventory", "Phoenix Potion", "Legendary", 0.0, 0.0, 1000, 500);
	Enemy Penelope_murderer = Enemy("Penelope's murderer", "Knight", 3, 12, 1.0, 1.0);
	Enemy Tobias = Enemy("Tobias", "Assassin", 5, 16, 1.2, 1.2);
	Enemy Egal = Enemy("Egal", "Knight", 7, 20, 1.4, 1.4);
	Enemy Father = Enemy("Father", "Knight", 12, 28, 2.0, 2.0);
	vector<Item> Merchant_inventory;
	Merchant Game_merchant = Merchant("Game Merchant", "Knight", 1, Merchant_inventory);
	vector<Enemy> Fights{Penelope_murderer, Tobias, Egal, Father};
	vector<string> States;
	vector<Item> knight1{ Iron_helmet, Iron_platebody, Iron_platelegs, Iron_greatsword, Health_potion, Stamina_potion, Phoenix_potion };
	vector<Item> knight2{ Steel_helmet, Steel_platebody, Steel_platelegs, Steel_greatsword, Health_potion, Stamina_potion, Phoenix_potion };
	vector<Item> knight3{ Fire_infused_greatsword, Health_potion, Stamina_potion };
	vector<Item> knight4{ Guts_greatsword, Health_potion, Stamina_potion };
	vector<Item> knight5{};
	vector<vector<Item>> knight_merchant_inventory{knight1, knight2, knight3, knight4, knight5};
	vector<Item> assassin1{ Leather_hood, Leather_body, Leather_legs, Iron_twinswords, Health_potion, Stamina_potion, Phoenix_potion };
	vector<Item> assassin2{ Hardened_leather_hood, Hardened_leather_body, Hardened_leather_legs, Steel_twinswords, Health_potion, Stamina_potion, Phoenix_potion };
	vector<Item> assassin3{ Lightning_infused_twinswords, Health_potion, Stamina_potion };
	vector<Item> assassin4{ Minato_twinswords, Health_potion, Stamina_potion };
	vector<Item> assassin5{};
	vector<vector<Item>> assassin_merchant_inventory{ assassin1, assassin2, assassin3, assassin4, assassin5 };


public:
	//game constructor
	Game(int game_state, Player user, int game_checkpoint, int game_state_count, int count_dialogue, int count_fight, int count_bossfight)
	{
		state = game_state;
		string name = user.getName();
		string class_type = user.getClass();
		int level = user.getLevel();
		main_player.setName(name);
		main_player.setClass(class_type);
		main_player.setLevel(level);
		checkpoint = game_checkpoint;
		state_count = game_state_count;
		dialogue_count = count_dialogue;
		fight_count = count_fight;
		bossfight_count = count_bossfight;

		//sets the drop tables according to what the player class is
		if (class_type == "knight")
		{
			Penelope_murderer.setItemDropTable(Merchant_voucher, Steel_platebody, Stamina_potion, Phoenix_potion);
			Tobias.setItemDropTable(Merchant_voucher, Steel_platebody, Fire_infused_greatsword, Phoenix_potion);
			Egal.setItemDropTable(Merchant_voucher, Steel_platebody, Fire_infused_greatsword, Guts_greatsword);
			Father.setItemDropTable(Merchant_voucher, Steel_platebody, Fire_infused_greatsword, Guts_greatsword);
			vector<Item> Merchant_inventory{ Iron_helmet, Iron_platebody, Iron_platelegs, Iron_greatsword, Health_potion, Stamina_potion, Phoenix_potion };
			Game_merchant.setInventory(Merchant_inventory);
		}

		else if (class_type == "assassin")
		{
			Penelope_murderer.setItemDropTable(Merchant_voucher, Hardened_leather_body, Stamina_potion, Phoenix_potion);
			Tobias.setItemDropTable(Merchant_voucher, Hardened_leather_body, Stamina_potion, Phoenix_potion);
			Egal.setItemDropTable(Merchant_voucher, Hardened_leather_body, Lightning_infused_twinswords, Minato_twinswords);
			Father.setItemDropTable(Merchant_voucher, Hardened_leather_body, Lightning_infused_twinswords, Minato_twinswords);
			vector<Item> Merchant_inventory{ Leather_hood, Leather_body, Leather_legs, Iron_twinswords, Health_potion, Stamina_potion, Phoenix_potion };
			Game_merchant.setInventory(Merchant_inventory);
		}

		Penelope_murderer.setGoldDropTable(50, 100, 200, 400);
		Tobias.setGoldDropTable(100, 200, 400, 800);
		Egal.setGoldDropTable(200, 400, 800, 1600);
		Father.setGoldDropTable(400, 800, 1600, 3200);
		Fights[0] = Penelope_murderer;
		Fights[1] = Tobias;
		Fights[2] = Egal;
		Fights[3] = Father;
	}

	void setPlayer(Player player)
	{
		main_player = player;
	}

	int getState()
	{
		return state;
	}

	//checking states of the game
	bool isEndGame()
	{
		if (state == Game::ENDGAME)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isNewGame()
	{
		if (state == Game::NEWGAME)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isFight()
	{
		if (state == Game::FIGHT)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isDialogue()
	{
		if (state == Game::DIALOGUE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isInvalid()
	{
		if (state == Game::INVALID)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//getters and setters for data members
	int getDialogueCount()
	{
		return dialogue_count;
	}

	int getSongCount()
	{
		return song_count;
	}

	int getFightCount()
	{
		return fight_count;
	}

	int getFightTurnCount()
	{
		return fight_turn_count;
	}

	int getBossFightCount()
	{
		return bossfight_count;
	}

	int getCheckpoint()
	{
		return checkpoint;
	}
	
	Player getPlayer()
	{
		return main_player;
	}

	void setState(int game_state)
	{
		state = game_state;
	}

	void incrementDialogueCount()
	{
		dialogue_count++;
	}

	void incrementSongCount()
	{
		song_count++;
	}

	void incrementFightCount()
	{
		fight_count++;
	}

	void incrementBossFightCount()
	{
		bossfight_count++;
	}

	void incrementCheckpoint()
	{
		checkpoint++;
	}

	//plays song in song vector
	void playSong(int i)
	{
		PlaySound(Songs[i].c_str(), NULL, SND_ASYNC);
		incrementSongCount();
	}

	//outputs dialogue in dialogue vector
	string startDialogue(int i)
	{
		state = Game::DIALOGUE;
		incrementDialogueCount();
		return Dialogue[i];
	}

	//the fight function for the combat phase
	void startFight(int i)
	{
		//sets game state to fight and gets enemy from enemy vector. Sets player health and stamina to max and fight count to 0.
		state = Game::FIGHT;
		Enemy enemy = Fights[i];
		main_player.setHealth(main_player.getMaxHealth());
		main_player.setPlayerStamina(main_player.getMaxPlayerStamina());
		fight_turn_count = 0;
		//while the player and enemy are alive, displays player potions and asks if they want to use one
		while (main_player.getHealth() > 0 && enemy.getHealth() > 0)
		{
			int j = 0;
			int health_potions = main_player.getNumberHealthPotions();
			int stamina_potions = main_player.getNumberStaminaPotions();
			float att_bonus = main_player.getPlayerAttackBonus();
			float def_bonus = main_player.getPlayerDefenseBonus();
			cout << endl;
			cout << "Player health: " << main_player.getHealth() << " | Player stamina : " << main_player.getPlayerStamina() << " | Enemy health: " << enemy.getHealth() << endl;
			cout << "1 [Use health potion] [" << health_potions << " left] | 2 [Use stamina potion] [" << stamina_potions <<  " left] | enter [Skip potion usage]" << endl;
			string potion_usage;
			getline(cin, potion_usage);
			transform(potion_usage.begin(), potion_usage.end(), potion_usage.begin(), tolower);
			//uses health potion
			if (potion_usage == "1")
			{
				cout << endl;
				main_player.consumeItem("Health Potion");
				cout << "Player health: " << main_player.getHealth() << " | Player stamina : " << main_player.getPlayerStamina() << " | Enemy health: " << enemy.getHealth() << endl;
			}
			//uses stamina potion
			else if (potion_usage == "2")
			{
				cout << endl;
				main_player.consumeItem("Stamina Potion");
				cout << "Player health: " << main_player.getHealth() << " | Player stamina : " << main_player.getPlayerStamina() << " | Enemy health: " << enemy.getHealth() << endl;
			}
			cout << endl;
			//player chooses to either attack or pass
			cout << "Would you like to attack or pass?" << endl;
			cout << "1 [Attack] | 2 [Pass]" << endl;
			string move;
			getline(cin, move);
			bool valid_move = true;
			transform(move.begin(), move.end(), move.begin(), tolower);
			//checks for valid input
			if (move != "1" && move != "2")
			{
				valid_move = false;
				while (valid_move == false)
				{
					cout << endl;
					cout << "enter a valid command" << endl;
					getline(cin, move);
					transform(move.begin(), move.end(), move.begin(), tolower);
					if (move == "1" || move == "2")
					{
						valid_move = true;
					}
				}
			}
			//has player choose what kind of attack they would like to use and calculates the player hit and enemy block to find the final value of the player hit
			if (move == "1" && main_player.getPlayerStamina() >= 10)
			{
				cout << endl;
				cout << "Would you like to use a balanced attack, charged attack or special attack?" << endl;
				cout << "1 [balanced attack - 10 stamina] | 2 [charged attack - 30 stamina] | 3 [special attack - 90 stamina]" << endl;
				string attack_type;
				getline(cin, attack_type);
				transform(attack_type.begin(), attack_type.end(), attack_type.begin(), tolower);
				j = (rand() % 99) + 1;
				bool valid_attack = true;
				if (attack_type != "1" && attack_type != "2" && attack_type != "3")
				{
					valid_attack = false;
					while (valid_attack == false)
					{
						cout << endl;
						cout << "Choose an attack that you have enough stamina to perform" << endl;
						cout << "1 [balanced attack - 10 stamina] | 2 [charged attack - 30 stamina] | 3 [special attack - 90 stamina]" << endl;
						getline(cin, attack_type);
						transform(attack_type.begin(), attack_type.end(), attack_type.begin(), tolower);
						if (attack_type == "1" && main_player.getPlayerStamina() >= 10 || attack_type == "2" && main_player.getPlayerStamina() >= 30 || attack_type == "3" && main_player.getPlayerStamina() >= 90)
						{
							valid_attack = true;
						}
					}
				}
				if (attack_type == "1" && main_player.getPlayerStamina() < 10 || attack_type == "2" && main_player.getPlayerStamina() < 30 || attack_type == "3" && main_player.getPlayerStamina() < 90)
				{
					valid_attack = false;
					while (valid_attack == false)
					{
						cout << endl;
						cout << "Choose an attack that you have enough stamina to perform" << endl;
						cout << "1 [balanced attack - 10 stamina] | 2 [charged attack - 30 stamina] | 3 [special attack - 90 stamina]" << endl;
						getline(cin, attack_type);
						transform(attack_type.begin(), attack_type.end(), attack_type.begin(), tolower);
						if (attack_type == "1" && main_player.getPlayerStamina() >= 10 || attack_type == "2" && main_player.getPlayerStamina() >= 30 || attack_type == "3" && main_player.getPlayerStamina() >= 90)
						{
							valid_attack = true;
						}
					}
				}
				if (attack_type == "1" && main_player.getPlayerStamina() >= 10)
				{
					main_player.getNewBalancedHitPlayer(j);
					j = (rand() % 99) + 1;
					enemy.getNewBlock(j);
					int final_hit = 0;
					if (main_player.getHit() <= enemy.getBlock())
						final_hit = 0;
					else if (main_player.getHit() > enemy.getBlock())
						final_hit = main_player.getHit() - enemy.getBlock();
					enemy.setHealth(enemy.getHealth() - final_hit);
					main_player.setPlayerStamina(main_player.getPlayerStamina() - 10);
					cout << endl;
					cout << "You hit a " << final_hit << endl;
				}
				else if (attack_type == "2" && main_player.getPlayerStamina() >= 30)
				{
					main_player.getNewChargedHitPlayer(j);
					j = (rand() % 99) + 1;
					enemy.getNewBlock(j);
					int final_hit = 0;
					if (main_player.getHit() <= enemy.getBlock())
						final_hit = 0;
					else if (main_player.getHit() > enemy.getBlock())
						final_hit = main_player.getHit() - enemy.getBlock();
					enemy.setHealth(enemy.getHealth() - final_hit);
					main_player.setPlayerStamina(main_player.getPlayerStamina() - 30);
					cout << endl;
					cout << "You hit a " << final_hit << endl;
				}
				else if (attack_type == "3" && main_player.getPlayerStamina() >= 90)
					if (main_player.getClass() == "assassin")
					{
						main_player.getNewBalancedHitPlayer(j);
						j = (rand() % 99) + 1;
						enemy.getNewBlock(j);
						int final_hit = 0;
						if (main_player.getHit() <= enemy.getBlock())
							final_hit = 0;
						else if (main_player.getHit() > enemy.getBlock())
							final_hit = main_player.getHit() - enemy.getBlock();
						enemy.setHealth(enemy.getHealth() - final_hit);
						cout << endl;
						cout << "You hit a " << final_hit << endl;
						j = (rand() % 99) + 1;
						main_player.getNewBalancedHitPlayer(j);
						j = (rand() % 99) + 1;
						enemy.getNewBlock(j);
						final_hit = 0;
						if (main_player.getHit() <= enemy.getBlock())
							final_hit = 0;
						else if (main_player.getHit() > enemy.getBlock())
							final_hit = main_player.getHit() - enemy.getBlock();
						enemy.setHealth(enemy.getHealth() - final_hit);
						main_player.setPlayerStamina(main_player.getPlayerStamina() - 90);
						cout << endl;
						cout << "You hit a " << final_hit << endl;
					}
					else if (main_player.getClass() == "knight")
					{
						main_player.getNewChargedHitPlayer(j);
						int final_hit = 0;
						final_hit = main_player.getHit();
						enemy.setHealth(enemy.getHealth() - final_hit);
						main_player.setPlayerStamina(main_player.getPlayerStamina() - 90);
						cout << endl;
						cout << "You hit a " << final_hit << endl;
					}
			}

			//player passes and gains 20 stamina
			else if (move == "2")
			{
				main_player.setPlayerStamina(main_player.getPlayerStamina() + 20);
				cout << endl;
				cout << "You have passed a turn and gained +20 stamina" << endl;
			}

			//makes player pass and gain 20 stamina
			else if (main_player.getPlayerStamina() < 10)
			{
				cout << endl;
				cout << "You don't have enough stamina to perform an attack" << endl;
				main_player.setPlayerStamina(main_player.getPlayerStamina() + 20);
				cout << "You have passed a turn and gained +20 stamina" << endl;
			}

			//calculates player block and enemy hit and finds final enemy hit value
			j = (rand() % 99) + 1;
			int enemy_hit = 0;
			enemy.getNewBalancedHit(j);
			j = (rand() % 99) + 1;
			main_player.getNewBlockPlayer(j);
			if (enemy.getHit() <= main_player.getBlock())
				enemy_hit = 0;
			else if (enemy.getHit() > main_player.getBlock())
				enemy_hit = enemy.getHit() - main_player.getBlock();
			main_player.setHealth(main_player.getHealth() - enemy_hit);
			cout << endl;
			cout << "The enemy has dealt " << enemy_hit << " damage to you" << endl;
			fight_turn_count++;
		}

		//player dies
		if (main_player.getHealth() <= 0)
		{
			//if players has lives remaining, they can use a life and continue
			if (main_player.getPlayerLives() > 0)
			{
				cout << endl;
				cout << "You died. You have " << main_player.getPlayerLives() << " lives left. Would you like to continue?" << endl;
				cout << "1 [continue] | 2 [quit]" << endl;
				string continue_game;
				getline(cin, continue_game);
				transform(continue_game.begin(), continue_game.end(), continue_game.begin(), tolower);
				if (continue_game != "1" && continue_game != "2")
				{
					bool valid_continue = false;
					while (valid_continue == false)
					{
						cout << endl;
						cout << "Enter a valid command" << endl;
						getline(cin, continue_game);
						transform(continue_game.begin(), continue_game.end(), continue_game.begin(), tolower);
						if (continue_game == "1" || continue_game == "2")
						{
							valid_continue = true;
						}
					}
				}

				if (continue_game == "1")
				{
					main_player.decrementPlayerLives();
					cout << endl;
					cout << "You have used a life. You have " << main_player.getPlayerLives() << " left" << endl;
					startFight(fight_count);
				}

				else
				{
					state = Game::ENDGAME;
				}
			}
			//if the player has any phoenix potions, they can use one and continue
			else if (main_player.getNumberPhoenixPotions() > 0)
			{
				cout << endl;
				cout << "You have " << main_player.getNumberPhoenixPotions() << " Phoenix potions remaining. Would you like to use one and continue?" << endl;
				cout << "1 [continue] | 2 [quit]" << endl;
				string continue_game;
				getline(cin, continue_game);
				transform(continue_game.begin(), continue_game.end(), continue_game.begin(), tolower);
				if (continue_game != "1" && continue_game != "2")
				{
					bool valid_continue = false;
					while (valid_continue == false)
					{
						cout << endl;
						cout << "Enter a valid command" << endl;
						getline(cin, continue_game);
						transform(continue_game.begin(), continue_game.end(), continue_game.begin(), tolower);
						if (continue_game == "1" || continue_game == "2")
						{
							valid_continue = true;
						}
					}
				}

				if (continue_game == "1")
				{
					main_player.consumeItem("Phoenix Potion");
					startFight(fight_count);
				}

				else
				{
					state = Game::ENDGAME;
				}
			}
			//else, the game is over
			else
			{
				state = Game::ENDGAME;
			}
		}

		//if the player wins the fight, it increments the fight count, levels the player up and gives the player the item and gold drop. Updates merchant inventory with better items.
		else
		{
			incrementFightCount();
			cout << endl;
			main_player.levelUp();
			cout << "You have leveled up to level " << main_player.getLevel() << "!" << endl;
			Item item_drop = enemy.getItemDrop();
			int gold_drop = enemy.getGoldDrop(fight_turn_count);
			if (item_drop.getItemName() != "nothing")
			{
				main_player.addItem(item_drop);
			}
			main_player.addGold(gold_drop);
			cout << "You have received " << item_drop.getItemName() << " as an item drop and " << gold_drop << " gold" << endl;
			if (main_player.getClass() == "knight")
			{
				Game_merchant.addInventory(knight_merchant_inventory[getFightCount()]);
			}
			else if (main_player.getClass() == "assassin")
			{
				Game_merchant.addInventory(assassin_merchant_inventory[getFightCount()]);
			}
		}
	}

	//getters for songs, dialogue, fights and states
	wstring getSongs(int i)
	{
		return Songs[i];
	}

	string getDialogue(int i)
	{
		return Dialogue[i];
	}

	Enemy getFights(int i)
	{
		return Fights[i];
	}

	string getStates(int i)
	{
		return States[i];
	}

	//function for player merchant interaction
	void interactMerchant()
	{
		//the player chooses to buy or sell an item
		cout << endl;
		cout << "Merchant interaction" << endl;
		cout << "buy [1] | sell [2] | exit [3]" << endl;
		string input;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), tolower);

		while (input != "3")
		{
			if (input != "1" && input != "2")
			{
				bool valid_input = false;
				while (valid_input == false)
				{
					cout << endl;
					cout << "Enter a valid command" << endl;
					getline(cin, input);
					transform(input.begin(), input.end(), input.begin(), tolower);
					if (input == "1" || input == "2" || input == "3")
					{
						valid_input = true;
					}
				}
			}

			//if the player chooses to buy, it displays the merchant inventory and asks the player to choose an item to buy. If they have enough gold, the item is taken from the merchant inventory
			//and placed in the player inventory. The gold is then transferred accordingly
			if (input == "1")
			{
				Game_merchant.displayInventory();
				cout << endl;
				cout << "Select the item you would like to buy " << "Player gold [" << main_player.getGold() << "] " << "| Merchant gold [" << Game_merchant.getGold() << "] " << endl;
				string buy_input;
				getline(cin, buy_input);
				transform(buy_input.begin(), buy_input.end(), buy_input.begin(), tolower);
				if (stoi(buy_input) != Game_merchant.inventorySize() && stoi(buy_input) < 0 || stoi(buy_input) > Game_merchant.inventorySize())
				{
					bool valid_buy_input = false;
					while (valid_buy_input == false)
					{
						cout << endl;
						cout << "Enter a valid command" << endl;
						getline(cin, buy_input);
						transform(buy_input.begin(), buy_input.end(), buy_input.begin(), tolower);
						if (stoi(buy_input) == Game_merchant.inventorySize() || stoi(buy_input) >= 0 && stoi(buy_input) < Game_merchant.inventorySize())
						{
							valid_buy_input = true;
						}
					}
				}

				if (stoi(buy_input) != Game_merchant.inventorySize())
				{
					Item buy_item = Game_merchant.sellItem(stoi(buy_input));
					main_player.buyItem(buy_item);
				}
			}

			//if the player chooses to sell an item, the player inventory is then displayed and the player is prompted to choose an item to sell. If the merchant has enough gold to buy the item
			//the item is taken from the player inventory and placed in the merchant inventory. The gold is then transferred accordingly
			else if (input == "2")
			{
				main_player.displayInventory();
				cout << endl;
				cout << "Select the item you would like to sell " << "Player gold [" << main_player.getGold() << "] " << "| Merchant gold [" << Game_merchant.getGold() << "] "  << endl;
				string sell_input;
				getline(cin, sell_input);
				transform(sell_input.begin(), sell_input.end(), sell_input.begin(), tolower);
				if (stoi(sell_input) != main_player.inventorySize() && stoi(sell_input) < 0 || stoi(sell_input) > main_player.inventorySize())
				{
					bool valid_sell_input = false;
					while (valid_sell_input == false)
					{
						cout << endl;
						cout << "Enter a valid command" << endl;
						getline(cin, sell_input);
						transform(sell_input.begin(), sell_input.end(), sell_input.begin(), tolower);
						if (stoi(sell_input) == main_player.inventorySize() || stoi(sell_input) >= 0 && stoi(sell_input) < main_player.inventorySize())
						{
							valid_sell_input = true;
						}
					}
				}

				if (stoi(sell_input) != main_player.inventorySize())
				{
					Item buy_item = main_player.sellItem(stoi(sell_input));
					Game_merchant.buyItem(buy_item);
				}
			}

			else if (input == "3")
			{
				break;
			}
			cout << endl;
			cout << "buy [1] | sell [2] | exit [3]" << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), tolower);
		}
	}

	//allows player to equip and unequip items from the player inventory
	void manageInventory()
	{
		cout << endl;
		cout << "Inventory management" << endl;
		cout << "equip item [1] | unequip item [2] | exit [3]" << endl;
		string input;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), tolower);

		while (input != "3")
		{
			if (input != "1" && input != "2")
			{
				bool valid_input = false;
				while (valid_input == false)
				{
					cout << endl;
					cout << "Enter a valid command" << endl;
					getline(cin, input);
					transform(input.begin(), input.end(), input.begin(), tolower);
					if (input == "1" || input == "2" || input == "3")
					{
						valid_input = true;
					}
				}
			}

			if (input == "1")
			{
				main_player.displayInventory();
				cout << endl;
				cout << "Select the item you would like equip " << endl;
				string equip_input;
				getline(cin, equip_input);
				transform(equip_input.begin(), equip_input.end(), equip_input.begin(), tolower);
				if (stoi(equip_input) != main_player.inventorySize() && stoi(equip_input) < 0 || stoi(equip_input) > main_player.inventorySize())
				{
					bool valid_equip_input = false;
					while (valid_equip_input == false)
					{
						cout << endl;
						cout << "Enter a valid command" << endl;
						getline(cin, equip_input);
						transform(equip_input.begin(), equip_input.end(), equip_input.begin(), tolower);
						if (stoi(equip_input) == main_player.inventorySize() || stoi(equip_input) >= 0 && stoi(equip_input) < main_player.inventorySize())
						{
							valid_equip_input = true;
						}
					}
				}

				if (stoi(equip_input) != main_player.inventorySize())
				{
					main_player.equipItem(stoi(equip_input));
				}
			}

			else if (input == "2")
			{
				main_player.displayEquipment();
				cout << endl;
				cout << "Select the item you would like unequip " << endl;
				string unequip_input;
				getline(cin, unequip_input);
				transform(unequip_input.begin(), unequip_input.end(), unequip_input.begin(), tolower);
				if (stoi(unequip_input) != 4 && stoi(unequip_input) < 0 || stoi(unequip_input) > 4)
				{
					bool valid_unequip_input = false;
					while (valid_unequip_input == false)
					{
						cout << endl;
						cout << "Enter a valid command" << endl;
						getline(cin, unequip_input);
						transform(unequip_input.begin(), unequip_input.end(), unequip_input.begin(), tolower);
						if (stoi(unequip_input) == 4 || stoi(unequip_input) >= 0 && stoi(unequip_input) < 4)
						{
							valid_unequip_input = true;
						}
					}
				}

				if (stoi(unequip_input) != 4)
				{
					main_player.unequipItem(stoi(unequip_input));
				}
			}

			else if (input == "3")
			{
				break;
			}
			cout << endl;
			cout << "equip item [1] | unequip item [2] | exit [3]" << endl;
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), tolower);
		}
	}
};