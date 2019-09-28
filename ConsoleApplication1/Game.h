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


using namespace std;

class Game
{
private:
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
	Player main_player = Player("default", "default", 0);
	vector<wstring> Songs{ L"FirstScene.wav", L"FirstFight.wav", L"AfterFirstFight.wav" };
	string dialogue1 = "\nA blood moon illuminates the night sky, tinting it red like the blood about to be spilt.\nYou: Mommy?\nMother: Shhhhh... Be very quiet ok? Just stay here until I come back to get you, ok?\nYou: Ok...\n*The sound of wood splintering as the door explodes.*\nMother: No! Please don't! Why are you doing this?!\nMurderer: Shut up and stop begging. There's nothing you can do or say that is going to save your life, so just save your breath.\n*The sound of a sharp blade slicing across flesh*\nThrough a crack in the door you see a mist of blood that for a split moment combines with the crimson sky as one. In this split moment, time ceases to flow and the murderer's eyes meet your gaze through the crack in the door.\nThe moment passes and the blood mist falls back to Earth, spraying across the ground in an intricate pattern. The murderer hears the sound of scurrying behind him and leaves the area.\nYou slightly crack the door to peak out at your mother, but all you see is your mother laying face down in a pool of blood, the crimson liquid flowing from her neck and engulfing her face.\nYou quickly close the door and fade out of conciousness.\nPress 1 to continue\n";
	string dialogue2 = "\n20 years later\nYour entire birth family has been slaughtered, but you have survived. You are the only surviving member of the royal bloodline that once ruled the nation, only you're completely unaware.\nThe woman you now call your mother and have been calling your mother for the past 20 years is not your real mother. She was a servant to your family. A maid that once looked after you when your family was too preoccupied with royal duties.\nThis woman's name is Penelope. As long as you can remember you've called her Mom and she has always treated as if you were her own child.\nStrangely no matter how hard you try, you can never remember life as a small child. You brush it off as being too young to remember, but have heard others talk about memories from such ages.\nIt's as if the memories just no longer exist. As if that section of your brain has been erased. Exterminated.\nYou have been training to join the military force and you're the most impressive recruit they have ever seen. Your physical strength and prowess in combat is better than almost all the active members.\nPenelope has worked as a maid for another family ever since she took you on as her own. The life she has been able to provide has been less than lavish and that of a commoner. A life far less luxorious than you were born into\nTraining ran late today. Walking home, exhausted, muscles aching, you walk past the home Penelope works at. The moon is a blood red color, so much so you stare at it, waiting for blood to drip from the edges. You suddenly feel anxious. You don't know why, but the crimson sky is unearthing all kinds of emotions. You approach the door to knock and see if she is nearly done. As you raise your fist to knock the door opens.\nPress 1 to continue\n";
	string dialogue3 = "\nSurprised at the door opening and unaware of what has been happening inside, you are an easy target.One swift blow to the forehead with the hilt of a sword is enough to knock you out.\nWhen you come to, you are unable to move, under the effect of a binding spell. Penelope screams and goes to run out the front door when she is sliced across the back with the sharp blade of the sword.\nShe lets out a scream and falls to the floor. She continues to make her way toward the street, blundering around on the floor and eventually making her way outside. All you can do is watch as her attacker follows her to the street.\nShe turns around and begins begging for her life. For your life. The attacker just smirks and delivers a swift blow across her throat. The red mist spraying toward the sky. In that moment, as the blood and the red sky begin to mix, the memory of that night begins to flood back into your brain.\nThe barrier blocking off that section of your brain comes crashing down. You know Penelope wasn't your mother. You remember what happened to your family. You remember who you are. What you are. The one true ruler of this nation.\nThis revelation combined with the immense rage coarsing through your veins grants you the strength to shatter the shackles of the spell. Now free to move as you please, you face the attacker that murdered Penelope.\nPress 1 to enter the combat phase\n";
	string dialogue4 = "\nYou stand over your murderous foe.\nYou: Why did you kill her you sick fuck?!\nHe gives you a sickly grin, his blood stained teeth gleaming in the moonlit night.\nInfuriated you put both hands on either side of his head and smash the back of his skull into the cobblestone paved road until blood and brains begin to gush out the back of his head.\nAs you continue smashing skull against stone, more and more blood and brain matter splatter across your face with each blow.\nAfter you purge the rage from your body, you look over and see the lifeless body of Penelope sprawled across the road. Tears begin to blur your vision as you stand and walk toward her corpse.\nYou stand over her only briefly, wishing you had done more before gently lifting her body from the bloodied cobblestone and into your arms. A trail of blood follows you as you carry her home.\nPress 1 to continue\n";
	string dialogue5 = "\n24 hours later\nWhile going through Penelope's personal items, you find an envelope with your name written on the front of it. You open the envelope and find a letter written to you from Penelope.\nUpon reading the letter, you learn the details about yourself and what exactly had happened to your family. Someone wanted the power and wealth your family held and so they decided to forcibly take it,\nBut who would have that kind of power and ability to do such a thing? To overthrow the royal family. All one needs to do is look at who is in power now. The king currently ruling is no other than the general that had led the military sworn to protect the kingdom and the royal family.\nYour only goal in life now is to exact vengence on those that had taken your family from you and taken away what was rightfully yours.\nPress 1 to continue\n";
	vector<string> Dialogue{ dialogue1, dialogue2, dialogue3, dialogue4, dialogue5 };
	vector<string> Fights;
	vector<string> BossFights;
	vector<string> States;



public:
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
	}

	int getState()
	{
		return state;
	}

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

	void playSong(int i)
	{
		PlaySound(Songs[i].c_str(), NULL, SND_ASYNC);
		incrementSongCount();
	}

	string startDialogue(int i)
	{
		incrementDialogueCount();
		return Dialogue[i];
	}

	void startFight(int i)
	{

	}

	wstring getSongs(int i)
	{
		return Songs[i];
	}

	string getDialogue(int i)
	{
		return Dialogue[i];
	}

	string getFights(int i)
	{
		return Fights[i];
	}

	string getBossFights(int i)
	{
		return BossFights[i];
	}

	string getStates(int i)
	{
		return States[i];
	}
};