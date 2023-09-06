#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Functions.h"
using namespace std;

int Random(int min, int max) {

	return rand() % (max - min + 1) + min;
}

void DisplayMenu() {

	cout << "MAIN MENU" << endl;
	cout << "--------------------------" << endl;
	cout << "0. Quit" << endl;
	cout << "1. Character Hub" << endl;
	cout << "2. Battle" << endl;
	cout << "3. Save Data" << endl;
	cout << "4. Load Data" << endl;
	cout << "Enter choice here: ";


}

int GetChoice(int min, int max) {
	int userChoice;
	cout << "Enter a number from " << min << "-" << max << ": ";
	cin >> userChoice;

	while (userChoice < min || userChoice > max) {
		cout << "Invalid Choice. Try Again: ";
		cin >> userChoice;
	}

	return userChoice;
}

void GoToCharacterHub() {

	cout << "CHARACTER HUB" << endl;
	cout << "------------------" << endl;
	cout << "0. Quit" << endl;
	cout << "1. Set Player Name" << endl;
	cout << "2. Change Class" << endl;
	cout << "3. Go to Store" << endl;
	cout << "4. View all Details" << endl;
	cout << "Enter choice here: ";
}

string SetCharacterName() {
	string name;
	cout << "Enter a name for your player: ";
	cin.ignore();
	getline(cin, name);

	return name;
}

void ShowClasses(int numberOfStats, string playerStatNames[], int numberOfClasses, string classNames[], int classes[3][8]) {

	cout << "Classes Available: " << endl;
	cout << endl;
	cout << left << "		";
		for(int i = 0; i < numberOfStats; i++) {
			cout << setw(5) << playerStatNames[i];
		}
		cout << endl;

	//Display the stats for Each class
	for (int i = 0; i < numberOfClasses; i++) {
		cout << (i + 1) << ". " << classNames[i];
		cout << "	";
		cout << left << setw(5);

		for (int j = 0; j < numberOfStats; j++) {
			cout << setw(5) << classes[i][j];
		}
		cout << endl;
	}
}

void CopyStats(int numberOfStats, int currentPlayerClass, int playerStats[8], int classes[3][8]) {

	for (int i = 0; i < numberOfStats; i++) {
		playerStats[i] = classes[currentPlayerClass][i];
	}
}

void DisplayShop(int numOfWeaponsAndStats, string weaponStatNames[4], string weaponNames[4], int weapons[4][4], int numOfHealingItemsAndStats, string healingItemsStatNames[3], string healingItemNames[3],
	int healingItems[3][3]) {

	//Display Weapons
	cout << "Items Available: " << endl;
	cout << endl;
	cout << "Weapons: " << endl;
	cout << endl;
	cout << left << "		";
	for (int i = 0; i < numOfWeaponsAndStats; i++) {
		cout << setw(5) << weaponStatNames[i] << "	";
	}
	cout << endl;

	//Display stats for the weapons
	for (int i = 0; i < numOfWeaponsAndStats; i++) {
		cout << (i + 1) << ". " << weaponNames[i] << "	";
		cout << left << setw(8);

		for (int j = 0; j < numOfWeaponsAndStats; j++) {
			cout << setw(8) << weapons[i][j] << "	";
		}
		cout << endl;
	}

	//Display healing Items
	cout << endl;
	cout << "Healing Items: " << endl;
	cout << endl;
	cout << left << "		";
	for (int i = 0; i < numOfHealingItemsAndStats; i++) {
		cout << setw(5) << healingItemsStatNames[i] << "	";
	}
	cout << endl;

	//Display stats for the healing items
	for (int i = 0; i < numOfHealingItemsAndStats; i++) {
		cout << (i + 5) << ". " << healingItemNames[i] << "	";
		cout << left << setw(8);

		for (int j = 0; j < numOfHealingItemsAndStats; j++) {
			cout << setw(8) << healingItems[i][j] << "	";
		}
		cout << endl;
	}
}


bool CheckForSufficientFunds(int currentMoney, int priceOfItem) {
	if (priceOfItem < currentMoney) {
		return true;
	}
	else {
		cout << "Insufficient Funds. Cannot Purchase Item" << endl;
		return false;
	}
}

int PurchaseItem(int currentMoney, int priceOfItem, int typeOfItem, int itemCount, int itemInventory[]) {
	currentMoney -= priceOfItem;
	itemInventory[itemCount] = typeOfItem;
	return currentMoney;

}

void DisplayCurrentDetails(string playerName, int gold, string playerStatNames[], int currentClass, string classNames[], int playerStats[], int numOfStats, string weaponNames[], int weaponInventory[], int weaponCount,
						   string healingItemNames[], int healingItemInventory[], int healingItemCount) {
	cout << "Player Name: " << playerName << endl;
	cout << endl;

	cout << "Gold: " << gold << "G" << endl;
	cout << endl;

	cout << "Current Class: " << classNames[currentClass];
	cout << endl;

	cout << "Stats: " << endl;
	cout << left << "		";
	for (int i = 0; i < numOfStats; i++) {
		cout << setw(5) << playerStatNames[i];
	}
	cout << endl;

	cout << "		";
	for (int i = 0; i < numOfStats; i++) {
		cout << setw(5) << playerStats[i];
	}
	cout << endl;
	cout << endl;

	cout << "Weapons in Inventory: " << endl;
	if (weaponCount == 0) {
		cout << "None" << endl;
	}
	else {
		for (int i = 0; i < weaponCount; i++) {
			cout << (i + 1) << ". " << weaponNames[weaponInventory[i]] << endl;
		}
	}
	cout << endl;

	cout << "Healing Items in Inventory: " << endl;
	if (healingItemCount == 0) {
		cout << "None" << endl;
	}
	else {
		for (int i = 0; i < healingItemCount; i++) {
			cout << (i + 1) << ". " << healingItemNames[healingItemInventory[i]] << endl;
		}
	}

}

string SetEnemyNameAndStats(int classes[3][8], int enemyStats[], int numOfStats) {
	int enemyClass = Random(0, 2);
	string enemyName;

	switch (enemyClass) {
	//Enemy Name will be slime and will be assigned to the Barbarian Class
	case 0: {
		enemyName = "Slime";
		for (int i = 0; i < numOfStats; i++) {
			enemyStats[i] = classes[enemyClass][i];
		}
	}
		  break;
	//Enemy name will be Treasure Hoarder and will be assigned to the rogue class
	case 1: {
		enemyName = "Treasure Hoarder";
		for (int i = 0; i < numOfStats; i++) {
			enemyStats[i] = classes[enemyClass][i];
		}
	}
		  break;
	//Enemy Name will be mage and will be assigned to the cleric class
	case 2: {
		enemyName = "Mage";
		for (int i = 0; i < numOfStats; i++) {
			enemyStats[i] = classes[enemyClass][i];
		}
	}
		  break;

	}

	return enemyName;


}

void DisplayBattleMenu(string playerName, string enemyName, int playerHP, int enemyHP) {
	cout << "Player: " << playerName << " HP:" << playerHP << endl;
	cout << "Enemy: " << enemyName << " HP:" << enemyHP << endl;
	cout << "------------------" << endl;
	cout << "1. Attack" << endl;
	cout << "2. Defend" << endl;
	cout << "3. Heal" << endl;
	cout << "What will you do? " << endl;
}

void DisplayWeapons(int weaponCount, string weaponNames[], int weaponInventory[]) {
	cout << "What will you attack with?" << endl;
	//The Deafult Attack will always be an option
	cout << "1. Regular Attack" << endl;
	for (int i = 0; i < weaponCount; i++) {
		cout << (i + 2) << ". " << weaponNames[weaponInventory[i]] << endl;
	}

}

int Attack(string attackingCharacter, string nonAttackingCharacter, int characterHP, int hitRate, int minDamage, int maxDamage, int characterStats[], bool& isDefending, int reducedDamage) {

	float hit = Random(1, 20 + hitRate);
	if (hit >= characterStats[6]/2) {
		float amountOfDamage = Random(minDamage, maxDamage);
		//Check to see if the enemy is defending
		if (isDefending) {
			amountOfDamage = abs(amountOfDamage - reducedDamage);
			characterHP = abs(characterHP) - amountOfDamage;
			cout << attackingCharacter << " Attacks But " << nonAttackingCharacter << " Defends, Only Inflicting " << amountOfDamage << " Damage" << endl;
			//cout << endl;
			isDefending = false;

		}
		else {
			characterHP = abs(characterHP) - amountOfDamage;
			cout << attackingCharacter << " Attacks " << nonAttackingCharacter << " For " << amountOfDamage << " Damage " << endl;
			//cout << endl;

		}

	}
	else {
		cout << attackingCharacter << " Attacks " << nonAttackingCharacter << " But Misses!" << endl;
		//cout << endl;


	}

	return characterHP;
}


void DisplayHealingItems(int healingItemCount, string healingItemNames[], int healingItemInventory[]) {
	cout << "What item will you use?" << endl;
	for (int i = 0; i < healingItemCount; i++) {
		cout << (i + 1) << ". " << healingItemNames[healingItemInventory[i]] << endl;
	}

}

int Heal(string name, int currentHP, int maxHP, int healMin, int healMax) {
	int healAmount = Random(healMin, healMax);
	currentHP += healAmount;
	if (currentHP > maxHP) {
		currentHP = maxHP;
	}
	cout << name << " Recovered " << healAmount << " HP" << endl;

	return currentHP;

}

void RemoveItemFromInventory(int indexOfElementToRemove, int healingItemInventory[], int& healingItemCount) {
	for (int i = indexOfElementToRemove; i < healingItemCount - 1; i++) {
		healingItemInventory[i] = healingItemInventory[i + 1];
	}

	healingItemCount--;

}

bool CheckForVictoryOrDefeat(string playerName, string enemyName, int hp) {
	if (hp <= 0) {
		cout << playerName << " Has Defeated " << enemyName << "!" << endl;
		cout << playerName << " Wins!" << endl;
		cout << endl;

		return true;
	}
	else {
		return false;
	}
	
	
}


void SaveData(string playerName, int gold, int currentPlayerClass, int playerStats[], int numOfStats, int weaponInventory[], int weaponCount, int healingItemInventory[], 
	          int healingItemCount) {

	//Ouput in this order: player name, gold, class name, stats, weapons, and healing items
	ofstream output;
	output.open("playerInformation.txt");

	output << playerName << endl;
	output << gold << endl;
	output << currentPlayerClass << endl;
	for (int i = 0; i < numOfStats; i++) {
		output << playerStats[i] << " ";
	}
	output << endl;
	
	for (int i = 0; i < weaponCount; i++) {
		output << weaponInventory[i] << " ";
	}
	output << endl;

	for (int i = 0; i < healingItemCount; i++) {
		output << healingItemInventory[i] << " ";
	}
	output << endl;
	

	output.close();
}

void LoadData(string& playerName, int& gold, int& currentPlayerClass, int playerStats[], int numOfStats, int& weaponCount, int weaponInventory[], int healingItemInventory[], int& healingItemCount) {

	//Check to see if the save file exists
	ifstream input;
	input.open("playerInformation.txt");
	if (input.fail()) {
		cout << "No save file detected. Create your player first and then save." << endl;	

	}
	else {
		//Get the player name
		string buffer;
		getline(input, buffer);
		playerName = buffer;

		//Get the amount of gold. Read it in as a string then convert it to an int
		string strGold;
		getline(input, strGold);
		stringstream ss;
		ss << strGold;
		ss >> gold;

		//Get the player class number. Read it in as a string then convert it to an int
		string strCurrentPlayerClass;
		getline(input, strCurrentPlayerClass);
		ss.clear();
		ss << strCurrentPlayerClass;
		ss >> currentPlayerClass;
		

		//Read in all the stats as single string, then take each individual number, convert to an int, and store it in the array
		string strStat;
		getline(input, strStat);

		stringstream ss2(strStat);
		int i = 0;
		do {
			string tempNum;
			ss2 >> tempNum;
			stringstream ss;
			ss << tempNum;
			ss >> playerStats[i];
			i++;

		} while (ss2);

		//If the player has weapons, get that information
		if (!input.eof()) {
			string strWeapons;
			getline(input, strWeapons);
			

			stringstream ss3(strWeapons);
			int numOfWeapons = 0;
			string tempNum;
			while (ss3 >> tempNum) {
				stringstream ss;
				ss << tempNum;
				ss >> weaponInventory[numOfWeapons];
				numOfWeapons++;
			}

			weaponCount = numOfWeapons;
		}

		
		//If the player has healing items, get that information
		if (!input.eof()) {
			string strHealingItems;
			getline(input, strHealingItems);


			stringstream ss4(strHealingItems);
			int numOfHealingItems = 0;
			string tempNum;
			while (ss4 >> tempNum) {
				stringstream ss;
				ss << tempNum;
				ss >> healingItemInventory[numOfHealingItems];
				numOfHealingItems++;
			}

			healingItemCount = numOfHealingItems;
			
		}

		cout << "Previous save file has been loaded" << endl;
		
		

	}

	input.close();
}

