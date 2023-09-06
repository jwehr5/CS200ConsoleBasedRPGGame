#pragma once
#include <string>
#include <iostream>
using namespace std;
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H


int Random(int min, int max);

//Displays the main menu
void DisplayMenu();

//Validates user input
int GetChoice(int min, int max);

//Displays the character hub menu
void GoToCharacterHub();

//Sets the Player's name
string SetCharacterName();

//Displays the classes
void ShowClasses(int numberOfStats, string playerStatNames[], int numberOfClasses, string classNames[], int classes[3][8]);

//Copys a certain class's stats to the player's own stats
void CopyStats(int numberOfStats, int currentPlayerClass, int playerStats[8], int classes[3][8]);

//Displays the shop and all the items
void DisplayShop(int numOfWeapons, string weaponStatNames[4], string weaponNames[4], int weapons[4][4], int numOfHealingItems, string healingItemsStatNames[3], string healingItemNames[3],
					int healingItems[3][3]);

//Checks to make sure the user has enough money before purchasing something
bool CheckForSufficientFunds(int currentMoney, int priceOfItem);

//Let's the user purchase an item
int PurchaseItem(int currentMoney, int priceOfItem, int typeOfItem, int itemCount, int itemInventory[]);

//Displays all the information about the player: name, gold, class, stats, and items
void DisplayCurrentDetails(string playerName, int gold, string playerStatNames[], int currentClass, string classNames[], int playerStats[], int numOfStats, string weaponNames[], int weaponInventory[], int weaponItemCount, 
						   string healingItemNames[], int healingItemInventory[], int healingItemCount);

//Initializes stats for the enemy
string SetEnemyNameAndStats(int classes[3][8], int enemyStats[], int numOfStats);

//Displays the battle menu
void DisplayBattleMenu(string playerName, string enemyName, int playerHP, int enemyHP);

//Display the weapons that the user can use during battle
void DisplayWeapons(int weaponCount, string weaponNames[], int weaponInventory[]);

//Let's the user or enemy attack
int Attack(string attackingCharacter, string nonAttackingCharacter, int characterHP, int hitRate, int minDamage, int maxDamage, int characterStats[], bool& isDefending, int reducedDamage);

//Displays the healing items that the user has
void DisplayHealingItems(int healingItemCount, string healingItemNames[], int healingItemInventory[]);

//Lets the user or enemy heal
int Heal(string name, int currentHP, int maxHP, int healMin, int healMax);

//Removes a healing item after using it
void RemoveItemFromInventory(int indexOfElementToRemove, int healinItemInventory[], int& healingItemCount);

//Checks if the player or enemy has been defeated
bool CheckForVictoryOrDefeat(string playerName, string enemyName, int hp);

//Saves all of the player's information onto a file
void SaveData(string playerName, int gold, int currentPlayerClass, int playerStats[], int numOfStats, int weaponInventory[], int weaponCount, 
	           int healingItemInventory[], int healingItemCount);

//Loads all of the player's information from the save file
void LoadData(string& playerName, int& gold, int& currentPlayerClass, int playerStats[], int numOfStats, int& weaponCount, int weaponInventory[], int healingItemInventory[], int& healingItemCount);






#endif 
