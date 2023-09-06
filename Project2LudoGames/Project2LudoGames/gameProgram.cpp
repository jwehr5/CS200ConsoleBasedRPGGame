#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "Functions.h"
#include "Tests.h"
using namespace std;


int main()
{
	//Stat Names for the Player Stats
	const int MAX_NUM_STATS = 8;
	string playerStatNames[] = {"STR", "DEX", "CON", "INT", "WIS", "CHA", "AC", "HP"};

	//Names for the Classes
	const int MAX_NUM_CLASSES = 3;
	string classNames[] = { "Barbarian", "Rogue", "Cleric" };

	//Array of classes (Name of class, Stat Value)
	// 0 = Barbarian, 1 = Rogue, 2 = Cleric
	int currentPlayerClass = 0;
	int classes[MAX_NUM_CLASSES][MAX_NUM_STATS];
	
	//Stats for Barbarian Class
	classes[0][0] = 17; 
	classes[0][1] = 12; 
	classes[0][2] = 14; 
	classes[0][3] = 10; 
	classes[0][4] = 8; 
	classes[0][5] = 14; 
	classes[0][6] = 18; 
	classes[0][7] = 30;
	
	//Stats for Rogue Class
	classes[1][0] = 11;
	classes[1][1] = 17;
	classes[1][2] = 9;
	classes[1][3] = 14;
	classes[1][4] = 13;
	classes[1][5] = 8;
	classes[1][6] = 12;
	classes[1][7] = 23;

	//Stats for Cleric Class
	classes[2][0] = 15;
	classes[2][1] = 6;
	classes[2][2] = 14;
	classes[2][3] = 13;
	classes[2][4] = 18;
	classes[2][5] = 10;
	classes[2][6] = 19;
	classes[2][7] = 19;
	
	

	//Array to store the Player's stats
	int playerStats[MAX_NUM_STATS];

	//Array for the stats of Weapons
	const int WEAPON_STATS = 4;
	string weaponStatNames[] = { "Hit Rate", "Damage Min", "Damage Max", "Cost(G)" };

	//Array for the name of the Weapons
	const int WEAPON_NAMES = 4;
	string weaponNames[] = { "Dagger", "Shortbow", "Steel Mace", "Greatsword" };

	//Array of items and their stats
	int weapons[WEAPON_NAMES][WEAPON_STATS];

	//Stats for Dagger
	weapons[0][0] = 6;
	weapons[0][1] = 2;
	weapons[0][2] = 10;
	weapons[0][3] = 15;

	//Stats for Shortbow
	weapons[1][0] = 5;
	weapons[1][1] = 1;
	weapons[1][2] = 7;
	weapons[1][3] = 5;

	//Stats for Mace
	weapons[2][0] = 6;
	weapons[2][1] = 2;
	weapons[2][2] = 8;
	weapons[2][3] = 10;

	//Stats for Greatsword
	weapons[3][0] = 7;
	weapons[3][1] = 3;
	weapons[3][2] = 15;
	weapons[3][3] = 20;

	//Inventory array for storing Weapons
	// 0 = Dagger    1 = Shortbow   2 =  Steel Mace   3 = Greatsword
	const int MAX_WEAPON_INVENTORY = 4;
	int weaponInventory[MAX_WEAPON_INVENTORY];
	int weaponCount = 0;

	//Array for stats of healing items
	const int HEALING_ITEM_STATS = 3;
	string healingItemsStatNames[]{ "Heal Min", "Heal Max", "Cost(G)" };

	//Array for the names of the healing items
	const int HEALING_ITEM_NAMES = 3;
	string healingItemNames[]{ "Mint Donut", "Sandwich", "Steak" };

	//Array of healing items and their stats
	int healingItems[HEALING_ITEM_STATS][HEALING_ITEM_NAMES];

	//Stats for the Mint donut
	healingItems[0][0] = 5;
	healingItems[0][1] = 10;
	healingItems[0][2] = 10;

	//Stats for the Sandwich
	healingItems[1][0] = 10;
	healingItems[1][1] = 20;
	healingItems[1][2] = 12;

	//Stats for the Steak
	healingItems[2][0] = 20;
	healingItems[2][1] = 50;
	healingItems[2][2] = 20;

	//Inventory array for the Healing Items
	// 0 = Mint Donut  1 = Sandwich  2 = Steak
	const int MAX_HEALING_ITEM_INVENTORY = 5;
	int healingItemInventory[MAX_HEALING_ITEM_INVENTORY];
	int healingItemCount = 0;

	

	//Keep track of money. Player will start with 50G
	int gold = 50;

	//Character Name 
	string playerName;

	//Enemy Name
	string enemyName;
	
	//Array for the Enemy's Stats
	int enemyStats[MAX_NUM_STATS];

	//RunTests
	RunTests(classes);
	cout << "------------------------------------------------" << endl;

	srand(time(NULL)); // Set up rando mnumbers
	bool programDone = false;
	while (!programDone)
	{

		DisplayMenu();
		int menuChoice = GetChoice(0, 4);


		if (menuChoice == 0)
		{
			programDone = true;
		}
		else if (menuChoice == 1)
		{
			bool characterCreatorDone = false;
			while (!characterCreatorDone)
			{

				cout << endl;
				GoToCharacterHub();
				int characterCreatorChoice = GetChoice(0, 4);


				switch (characterCreatorChoice) {
				case 0: {
					characterCreatorDone = true;

				}
					  break;
					  //Enter Name
				case 1: {
					playerName = SetCharacterName();
					cout << endl;

				}
					  break;

				//Choose a class
				case 2: {

					cout << endl;
					ShowClasses(MAX_NUM_STATS, playerStatNames, MAX_NUM_CLASSES, classNames, classes);

					//Let the user select a class
					cout << "Type 0 to Go Back" << endl;
					int userClassChoice = GetChoice(0, 3);


					if (userClassChoice == 0) {
						break;
					}
					//Selected Barbarian Class
					else if (userClassChoice == 1) {
						currentPlayerClass = 0;
						cout << "You have selected the Barbarian Class." << endl;
						cout << "Stats have Been Updated" << endl;

						//Copy the stats of the Barbarian class into the player stats array
						CopyStats(MAX_NUM_STATS, currentPlayerClass, playerStats, classes);
					}
					//Selected Rogue Class
					else if (userClassChoice == 2) {
						currentPlayerClass = 1;
						cout << "You have selected the Rogue Class." << endl;
						cout << "Stats have Been Updated" << endl;

						//Copy the stats of the Rogue class into the player stats array
						CopyStats(MAX_NUM_STATS, currentPlayerClass, playerStats, classes);
					}
					//Selected Cleric Class
					else if (userClassChoice == 3) {
						currentPlayerClass = 2;
						cout << "You have selected the Cleric Class." << endl;
						cout << "Stats have Been Updated" << endl;

						//Copy the stats of the Cleric class into the player stats array
						CopyStats(MAX_NUM_STATS, currentPlayerClass, playerStats, classes);	

					}


					cout << endl;


				}
					break;

				//Go to the shop
				case 3: {

					cout << endl;
					DisplayShop(WEAPON_NAMES, weaponStatNames, weaponNames, weapons, HEALING_ITEM_NAMES, healingItemsStatNames, healingItemNames, healingItems);
					cout << endl;

					//Let the user Keep shopping until they type 0
					bool doneShopping = false;
					while (!doneShopping) {

						//Show the user's money
						cout << "Your Gold: " << gold << " G" << endl;
						cout << endl;

						//Let the user select an option as long as they have enough gold
						cout << "Type 0 to go back" << endl;
						int itemChoice = GetChoice(0, 7);

						if (itemChoice == 0) {
							doneShopping = true;
							
						}
						//Purchase Dagger
						else if (itemChoice == 1) {
							int priceOfWeapon = weapons[0][3];
							if (CheckForSufficientFunds(gold, priceOfWeapon)) {

								if (weaponCount == 4) {
									cout << "Weapon Inventory Full. Cannot Purchase Any More Weapons" << endl;
								}
								else {
									gold = PurchaseItem(gold, priceOfWeapon, 0, weaponCount, weaponInventory);
									weaponCount++;
									cout << "Dagger Purchased" << endl;
								}
							}

						}
						//Purchase Shortbow
						else if (itemChoice == 2) {
							int priceOfWeapon = weapons[1][3];
							if (CheckForSufficientFunds(gold, priceOfWeapon)) {

								if (weaponCount == 4) {
									cout << "Weapon Inventory Full. Cannot Purchase Any More Weapons" << endl;
								}
								else {
									gold = PurchaseItem(gold, priceOfWeapon, 1, weaponCount, weaponInventory);
									weaponCount++;
									cout << "Shortbow Purchased" << endl;
								}
							}

						}
						//Purchase Steel Mace
						else if (itemChoice == 3) {
							int priceOfWeapon = weapons[2][3];
							if (CheckForSufficientFunds(gold, priceOfWeapon)) {

								if (weaponCount == 4) {
									cout << "Weapon Inventory Full. Cannot Purchase Any More Weapons" << endl;
								}
								else {
									gold = PurchaseItem(gold, priceOfWeapon, 2, weaponCount, weaponInventory);
									weaponCount++;
									cout << "Steel Mace Purchased" << endl;
								}
							}

						}
						//Purchase Greatsword
						else if (itemChoice == 4) {
							int priceOfWeapon = weapons[3][3];
							if (CheckForSufficientFunds(gold, priceOfWeapon)) {

								if (weaponCount == 4) {
									cout << "Weapon Inventory Full. Cannot Purchase Any More Weapons" << endl;
								}
								else {
									gold = PurchaseItem(gold, priceOfWeapon, 3, weaponCount, weaponInventory);
									weaponCount++;
									cout << "Greatsword Purchased" << endl;
								}
							}
						}
						//Purchase Mint Donut
						else if (itemChoice == 5) {
							int priceOfHealingItem = healingItems[0][2];
							if (CheckForSufficientFunds(gold, priceOfHealingItem)) {

								if (healingItemCount == 5) {
									cout << "Item Inventory Full. Cannot Purchase Any More Items" << endl;
								}
								else {
									gold = PurchaseItem(gold, priceOfHealingItem, 0, healingItemCount, healingItemInventory);
									healingItemCount++;
									cout << "Mint Donut Purchased" << endl;
								}
							}
						}
						//Purchase Sandwich
						else if (itemChoice == 6) {
							int priceOfHealingItem = healingItems[1][2];
							if (CheckForSufficientFunds(gold, priceOfHealingItem)) {

								if (healingItemCount == 5) {
									cout << "Item Inventory Full. Cannot Purchase Any More Items" << endl;
								}
								else {
									gold = PurchaseItem(gold, priceOfHealingItem, 1, healingItemCount, healingItemInventory);
									healingItemCount++;
									cout << "Sandwich Purchased" << endl;
								}
							}
						}
						//Purchase Steak
						else if (itemChoice == 7) {
							int priceOfHealingItem = healingItems[2][2];
							if (CheckForSufficientFunds(gold, priceOfHealingItem)) {

								if (healingItemCount == 5) {
									cout << "Item Inventory Full. Cannot Purchase Any More Items" << endl;
								}
								else {
									gold = PurchaseItem(gold, priceOfHealingItem, 2, healingItemCount, healingItemInventory);
									healingItemCount++;
									cout << "Steak Purchased" << endl;
								}
							}
						}


					}// Shopping Loop

					
					

					cout << endl;
				}
					  break;

				//Display name, class, stats, and items in inventory
				case 4: {
					cout << endl;
					DisplayCurrentDetails(playerName, gold, playerStatNames, currentPlayerClass, classNames, playerStats, MAX_NUM_STATS, weaponNames, weaponInventory, weaponCount, healingItemNames, healingItemInventory,
						healingItemCount);
					cout << endl;
				}
					  break;

				default: {
					cout << "Invalid Choice. Try Again" << endl;
					cout << endl;
				}
					   break;
				}


				}
			}
		
		//Enter Battle
		else if (menuChoice == 2)
		{

		//Set the enemy's name and stats
		enemyName = SetEnemyNameAndStats(classes, enemyStats, MAX_NUM_STATS);

		bool battleDone = false;

		cout << endl;
		cout << "BATTLE START!" << endl;
		//These variables will check for if the player or enemy is defending during battle
		float reducedDamageForPlayer = 0;
		bool playerIsDefending = false;
		float reducedDamageForEnemy = 0;
		bool enemyIsDefending = false;

		int playerHP = playerStats[7];
		int maxPlayerHP = playerHP;
		int enemyHP = enemyStats[7];
		int maxEnemyHP = enemyHP;

		while (!battleDone) {

			//If the player accidently selects the heal option when they don't have any items, we'll make sure that they can select again
			bool readyForEnemyTurn = false;
			while (!readyForEnemyTurn) {
				DisplayBattleMenu(playerName, enemyName, playerHP, enemyHP);
				//cout << endl;

				int battleOption = GetChoice(1, 3);

				switch (battleOption) {
					//Player Chooses to Attack
				case 1: {
					readyForEnemyTurn = true;
					//Display list of the player's weapons.
					cout << endl;
					DisplayWeapons(weaponCount, weaponNames, weaponInventory);
					cout << endl;
					int weaponSelection = GetChoice(1, weaponCount + 1);
					cout << endl;

					//The Regular Attack
					int hitRate;
					int minDamage;
					int maxDamage;
					if (weaponSelection == 1) {
						//STR/2 will be used as the hit rate
						hitRate = playerStats[0] / 2;
						minDamage = hitRate / 2;
						maxDamage = hitRate * 2;
						enemyHP = Attack(playerName, enemyName, enemyHP, hitRate, minDamage, maxDamage, enemyStats, enemyIsDefending, reducedDamageForEnemy);

					}
					//First item in weaponInventory
					else if (weaponSelection == 2) {
						hitRate = weapons[weaponInventory[0]][0];
						minDamage = weapons[weaponInventory[0]][1];
						maxDamage = weapons[weaponInventory[0]][2];
						enemyHP = Attack(playerName, enemyName, enemyHP, hitRate, minDamage, maxDamage, enemyStats, enemyIsDefending, reducedDamageForEnemy);
					}
					//Second item in weaponInventory
					else if (weaponSelection == 3) {
						hitRate = weapons[weaponInventory[1]][0];
						minDamage = weapons[weaponInventory[1]][1];
						maxDamage = weapons[weaponInventory[1]][2];
						enemyHP = Attack(playerName, enemyName, enemyHP, hitRate, minDamage, maxDamage, enemyStats, enemyIsDefending, reducedDamageForEnemy);
					}
					//Third item in weaponInventory
					else if (weaponSelection == 4) {
						hitRate = weapons[weaponInventory[2]][0];
						minDamage = weapons[weaponInventory[2]][1];
						maxDamage = weapons[weaponInventory[2]][2];
						enemyHP = Attack(playerName, enemyName, enemyHP, hitRate, minDamage, maxDamage, enemyStats, enemyIsDefending, reducedDamageForEnemy);

					}
					//Fourth item in weaponInventory
					else if (weaponSelection == 5) {
						hitRate = weapons[weaponInventory[3]][0];
						minDamage = weapons[weaponInventory[3]][1];
						maxDamage = weapons[weaponInventory[3]][2];
						enemyHP = Attack(playerName, enemyName, enemyHP, hitRate, minDamage, maxDamage, enemyStats, enemyIsDefending, reducedDamageForEnemy);

					}

				}
					  break;

					  //Player chooses to Defend
				case 2: {
					readyForEnemyTurn = true;
					//Choose a random value from 2, player's AC/2
					reducedDamageForPlayer = Random(2, playerStats[6] / 2);
					cout << playerName << " Chooses to Defend" << endl;
					playerIsDefending = true;

				}
					  break;

					  //Player Chooses an Item
				case 3: {
					//Check to make sure they have items in their inventory
					if (healingItemCount == 0) {
						cout << "No Healing Items in Inventory" << endl;
						cout << endl;
					}
					//They don't need to heal if their HP is at max
					else if (playerHP == maxPlayerHP) {
						cout << "HP is at max. No need to use an item" << endl;
						cout << endl;
					}
					else {
						readyForEnemyTurn = true;
						cout << endl;
						DisplayHealingItems(healingItemCount, healingItemNames, healingItemInventory);
						cout << endl;
						int healingItemSelection = GetChoice(1, healingItemCount);

						int healMin;
						int healMax;
						//First item in healingItemInventory
						if (healingItemSelection == 1) {
							healMin = healingItems[healingItemInventory[0]][0];
							healMax = healingItems[healingItemInventory[0]][1];
							playerHP = Heal(playerName, playerHP, maxPlayerHP, healMin, healMax);

							//Remove Item from the inventory
							RemoveItemFromInventory(0, healingItemInventory, healingItemCount);


						}
						//Second item in healingItemInventory
						else if (healingItemSelection == 2) {
							healMin = healingItems[healingItemInventory[1]][0];
							healMax = healingItems[healingItemInventory[1]][1];
							playerHP = Heal(playerName, playerHP, maxPlayerHP, healMin, healMax);

							//Remove Item from the inventory
							RemoveItemFromInventory(1, healingItemInventory, healingItemCount);


						}
						//Third item in healingItemInventory
						else if (healingItemSelection == 3) {
							healMin = healingItems[healingItemInventory[2]][0];
							healMax = healingItems[healingItemInventory[2]][1];
							playerHP = Heal(playerName, playerHP, maxPlayerHP, healMin, healMax);

							//Remove Item from the inventory
							RemoveItemFromInventory(2, healingItemInventory, healingItemCount);
						}
						//Fourth item in healingItemInventory
						else if (healingItemSelection == 4) {
							healMin = healingItems[healingItemInventory[3]][0];
							healMax = healingItems[healingItemInventory[3]][1];
							playerHP = Heal(playerName, playerHP, maxPlayerHP, healMin, healMax);

							//Remove Item from the inventory
							RemoveItemFromInventory(3, healingItemInventory, healingItemCount);

						}
						//Fifth item in healingItemInventory
						else if (healingItemSelection == 5) {
							healMin = healingItems[healingItemInventory[4]][0];
							healMax = healingItems[healingItemInventory[4]][1];
							playerHP = Heal(playerName, playerHP, maxPlayerHP, healMin, healMax);

							//Remove Item from the inventory
							RemoveItemFromInventory(4, healingItemInventory, healingItemCount);

						}
					}
				}
					  break;

				}

			}// Ready For Enemy Turn Loop

				

			//Check to see if the enemy has been defeated
			if (CheckForVictoryOrDefeat(playerName, enemyName, enemyHP)) {
					battleDone = true;

				//Give some gold for winning
				int goldWon = Random(10, 50);
				gold += goldWon;
				cout << playerName << " Recieves " << goldWon << " Gold!" << endl;
			}

			//Enemy's Turn
			else {
				int enemyBattleOption = Random(1, 3);

				switch (enemyBattleOption) {

				//Enemy Attack
				case 1: {
					int hitRate;
					int minDamage;
					int maxDamage;
					//STR/2 will be used as the hitRate
					hitRate = enemyStats[0] / 2;
					minDamage = hitRate / 2;
					maxDamage = hitRate * 2;
					playerHP = Attack(enemyName, playerName, playerHP, hitRate, minDamage, maxDamage, playerStats, playerIsDefending, reducedDamageForPlayer);
					cout << endl;
				}
					  break;

				//Enemy Defends
				case 2: {
					reducedDamageForEnemy = Random(2, enemyStats[6]/2);
					cout << enemyName << " Decides to Defend" << endl;
					cout << endl;
					enemyIsDefending = true;
				}
					  break;

				//Enemy Heals
				case 3: {
					// 5 will be the heal min. Enemy's CHA will be used for heal max
					int healMin = 5;
					int healMax = enemyStats[5];
					enemyHP = Heal(enemyName, enemyHP, maxEnemyHP, healMin, healMax);
					cout << endl;

				}
					  break;
				}
			}

			//Check to see if the player has been Defeated
			if (CheckForVictoryOrDefeat(enemyName, playerName, playerHP)) {
				battleDone = true;
			}

			


		}//Battle Loop
		
			
		}
		//Save Data
		else if (menuChoice == 3) {
		SaveData(playerName, gold, currentPlayerClass, playerStats, MAX_NUM_STATS, weaponInventory, weaponCount, healingItemInventory, healingItemCount);
		cout << "Data has been saved" << endl;
		cout << endl;

		}
		//Load Data
		else if (menuChoice == 4) {
		LoadData(playerName, gold, currentPlayerClass, playerStats, MAX_NUM_STATS, weaponCount, weaponInventory, healingItemInventory, healingItemCount);
		cout << endl;
		}
	}

	// Program ends
	return 0;
}	
	
	
