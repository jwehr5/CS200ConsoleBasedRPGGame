#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "Tests.h"
#include "Functions.h"
using namespace std;

void RunTests(int classes[3][8]) {

    Test_CopyStats(classes);
    Test_CheckForSufficientFunds();
    Test_PurchaseItem();
    Test_SetEnemyNameAndStats(classes);
    Test_Attack();
    Test_Heal();
    Test_RemoveItemFromInventory();
    Test_CheckForVictoryOrDefeat();

}

void Test_CopyStats(int classes[3][8]) {
    cout << endl
        << "------------------------------------------------"
        << endl << "TEST: CopyStats" << endl;

    int numOfStats = 8;
    int currentPlayerClass = 1; //Rogue Class
    string playerClassName = "Rogue";
    int test_playerStats[8];

    CopyStats(numOfStats, currentPlayerClass, test_playerStats, classes);

    int numOfMatchingItems = 0;
    for (int i = 0; i < numOfStats; i++) {
        if (test_playerStats[i] == classes[currentPlayerClass][i]) {
            numOfMatchingItems++;
        }

    }

    if (numOfMatchingItems == 8)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }
    cout << "*Player Class: " << playerClassName << endl;
    cout << "* Class Stats: ";
    for (int i = 0; i < numOfStats; i++) {
        cout << classes[currentPlayerClass][i] << " ";

    }
    cout << endl;
    cout << "* Player Stats: ";
    for (int i = 0; i < numOfStats; i++) {
        cout << test_playerStats[i] << " ";

    }
    cout << endl;
    cout << endl;

}

void Test_CheckForSufficientFunds() {
    cout << endl
        << "------------------------------------------------"
        << endl << "TEST: CheckForSufficientFunds" << endl;
    cout << "* TEST 1... " << endl << endl;

    int currentMoney = 45;
    int priceOfItem = 55;
    bool expectedOutput = false;
    bool actualOutput;

    actualOutput = CheckForSufficientFunds(currentMoney, priceOfItem);

    if (actualOutput == expectedOutput)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }
    cout << "*Current Money:    " << currentMoney << endl;
    cout << "*Price Of Item:    " << priceOfItem << endl;
    cout << "* expectedOutput:  " << expectedOutput << endl;
    cout << "* actualOutput:    " << actualOutput << endl;
    cout << endl;

    cout << "* TEST 2... " << endl << endl;

     currentMoney = 45;
     priceOfItem = 35;
     expectedOutput = true;
     actualOutput;

    actualOutput = CheckForSufficientFunds(currentMoney, priceOfItem);

    if (actualOutput == expectedOutput)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }
    cout << "*Current Money:    " << currentMoney << endl;
    cout << "*Price Of Item:    " << priceOfItem << endl;
    cout << "* expectedOutput:  " << expectedOutput << endl;
    cout << "* actualOutput:    " << actualOutput << endl;
    cout << endl;

}

void Test_PurchaseItem() {
    cout << endl
        << "------------------------------------------------"
        << endl << "TEST: PurchaseItem" << endl;

    int currentMoney = 50;
    int priceOfItem = 10;
    int typeOfItem = 1;
    int itemCount = 0;
    int itemInventory[4];
    int expectedOutput = 40;
    int actualOutput;

    actualOutput = PurchaseItem(currentMoney, priceOfItem, typeOfItem, itemCount, itemInventory);

    if ((actualOutput == expectedOutput) && (itemInventory[itemCount] == typeOfItem)) {
        cout << "PASS" << endl;
    }
    else {
        cout << "FAIL" << endl;
    }
    cout << "*Current Money:    " << currentMoney << endl;
    cout << "*Price Of Item:    " << priceOfItem << endl;
    cout << "*Type of Item:     " << typeOfItem << endl;
    cout << "* Item at index 0: " << itemInventory[0] << endl;
    cout << "* expectedOutput:  " << expectedOutput << endl;
    cout << "* actualOutput:    " << actualOutput << endl;
    cout << endl;


}

void Test_SetEnemyNameAndStats(int classes[3][8]) {
    cout << endl
        << "------------------------------------------------"
        << endl << "TEST: SetEnemyNameAndStats" << endl;

    int numOfStats = 8;
    int test_EnemyStats[8];
    int typeOfClass;
    string enemyName;

    enemyName = SetEnemyNameAndStats(classes, test_EnemyStats, numOfStats);

    int numOfMatchingElements = 0;
    if (enemyName == "Slime") {
        typeOfClass = 0;
        for (int i = 0; i < numOfStats; i++) {
            if (test_EnemyStats[i] == classes[0][i]) {
                numOfMatchingElements++;
            }
        }
    }
    else if (enemyName == "Treasure Hoarder") {
        typeOfClass = 1;
        for (int i = 0; i < numOfStats; i++) {
            if (test_EnemyStats[i] == classes[1][i]) {
                numOfMatchingElements++;
            }
        }
    }
    else if (enemyName == "Mage") {
        typeOfClass = 2;
        for (int i = 0; i < numOfStats; i++) {
            if (test_EnemyStats[i] == classes[2][i]) {
                numOfMatchingElements++;
            }
        }
    }

    if (numOfMatchingElements == 8) {
        cout << "PASS" << endl;
    }
    else {
        cout << "FAIL" << endl;
    }
    cout << "*Enemy Name:    " << enemyName << endl;
    cout << "*Stats:  ";
    for (int i = 0; i < numOfStats; i++) {
        cout << classes[typeOfClass][i] << " ";
        }
    cout << endl;
    cout << endl;
    
}

void Test_Attack() {
    cout << endl
        << "------------------------------------------------"
        << endl << "TEST: ATTACK" << endl;

    string player = "Player";
    string enemy = "Enemy";
    int originalEnemyHP = 25;
    int enemyHP = 25;
    int hitRate = 6;
    int minDamage = 3;
    int maxDamage = 7;
    int test_EnemyStats[] = { 17,12,14,10,8,14,18,30 };
    bool isDefending = false;
    int reducedDamage = 0;

    enemyHP = Attack(player, enemy, enemyHP, hitRate, minDamage, maxDamage, test_EnemyStats, isDefending, reducedDamage);

    //Because its by random chance that the player may or may not attack the enemy, as long as the enemy's HP doesn't increase, we can say that this test passes
    if (enemyHP <= originalEnemyHP) {
        cout << "PASS" << endl;
    }
    else {
        cout << "FAIL" << endl;
    }
    cout << "*Original Enemy HP: " << originalEnemyHP << endl;
    cout << "*Current Enemy HP:  " << enemyHP << endl;
    cout << endl;



}

void Test_Heal() {
    cout << endl
        << "------------------------------------------------"
        << endl << "TEST: HEAL" << endl;
    cout << "* TEST 1... " << endl << endl;

    string name = "Player";
    int initialHP = 20;
    int maxHP = 30;
    int healMin = 5;
    int healMax = 10;
    int currentHP;

    currentHP = Heal(name, initialHP, maxHP, healMin, healMax);

    if (currentHP > initialHP && currentHP <= maxHP) {
        cout << "PASS" << endl;
    }
    else {
        cout << "FAIL" << endl;
    }
    cout << "*Initial HP: " << initialHP << endl;
    cout << "*Max HP:     " << maxHP << endl;
    cout << "*Heal Min:   " <<  healMin << endl;
    cout << "*Heal Max:   " << healMax << endl;
    cout << "*Current HP: " << currentHP << endl;
    cout << endl;

    cout << "* TEST 2... " << endl << endl;

    initialHP = 10;
     maxHP = 30;
     healMin = 10;
     healMax = 20;

    currentHP = Heal(name, initialHP, maxHP, healMin, healMax);

    if (currentHP > initialHP && currentHP <= maxHP) {
        cout << "PASS" << endl;
    }
    else {
        cout << "FAIL" << endl;
    }
    cout << "*Initial HP: " << initialHP << endl;
    cout << "*Max HP:     " << maxHP << endl;
    cout << "*Heal Min:   " << healMin << endl;
    cout << "*Heal Max:   " << healMax << endl;
    cout << "*Current HP: " << currentHP << endl;
    cout << endl;


}

void Test_RemoveItemFromInventory() {
    cout << endl
        << "------------------------------------------------"
        << endl << "TEST: RemoveItemFromInventory" << endl;
    cout << "* TEST 1... " << endl << endl;
    
    int originalArr[] = { 1,5,6 };
    int originalArrSize = 3;

    int indexToRemove = 1;
    int arr[] = { 1,5,6 };
    int elementCount = 3;
    int expectedArr[] = { 1,6 };
    int expectedArrSize = 2;

    RemoveItemFromInventory(indexToRemove, arr, elementCount);

    int numOfMatchingElements = 0;
    for (int i = 0; i < elementCount; i++) {
        if (arr[i] == expectedArr[i]) {
            numOfMatchingElements++;
        }
    }
    if (numOfMatchingElements == 2) {
        cout << "PASS" << endl;
    }
    else {
        cout << "Fail" << endl;
    }
    cout << "*Original Array: ";
    for (int i = 0; i < originalArrSize; i++) {
        cout << originalArr[i] << " ";
    }
    cout << endl;
    cout << "Index to Remove: " << indexToRemove << endl;
    cout << "*Modified Array: ";
    for (int i = 0; i < elementCount; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "*Expected Array: ";
    for (int i = 0; i < expectedArrSize; i++) {
        cout << expectedArr[i] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "* TEST 2... " << endl << endl;

     indexToRemove = 2;
    int arr2[] = { 1,5,6 };
    int expectedArr2[] = { 1,5 };
    elementCount = 3;

    RemoveItemFromInventory(indexToRemove, arr, elementCount);

    numOfMatchingElements = 0;
    for (int i = 0; i < elementCount; i++) {
        if (arr[i] == expectedArr[i]) {
            numOfMatchingElements++;
        }
    }
    if (numOfMatchingElements == 2) {
        cout << "PASS" << endl;
    }
    else {
        cout << "Fail" << endl;
    }
    cout << "*Original Array: ";
    for (int i = 0; i < originalArrSize; i++) {
        cout << originalArr[i] << " ";
    }
    cout << endl;
    cout << "Index to Remove: " << indexToRemove << endl;
    cout << "*Modified Array: ";
    for (int i = 0; i < elementCount; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "*Expected Array: ";
    for (int i = 0; i < expectedArrSize; i++) {
        cout << expectedArr[i] << " ";
    }
    cout << endl;
    cout << endl;


}

void Test_CheckForVictoryOrDefeat() {
    cout << endl
        << "------------------------------------------------"
        << endl << "TEST: CheckForVictoryOrDefeat" << endl;

    string player = "Player";
    string enemy = "Enemy";
    int hp = 0;
    bool expectedOutput = true;
    bool actualOutput;

    actualOutput = CheckForVictoryOrDefeat(player, enemy, hp);

    if (expectedOutput == actualOutput) {
        cout << "PASS" << endl;
    }
    else {
        cout << "FAIL" << endl;
    }
    cout << "*HP:              " << hp << endl;
    cout << "*Expected Output: " << expectedOutput << endl;
    cout << "*Actual Output:   " << actualOutput << endl;
    cout << endl;


}