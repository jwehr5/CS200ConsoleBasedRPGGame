#pragma once
#ifndef _TESTS_H
#define _TESTS_H

void RunTests(int classes[3][8]);

void Test_CopyStats(int classes[3][8]);

void Test_CheckForSufficientFunds();

void Test_PurchaseItem();

void Test_SetEnemyNameAndStats(int classes[3][8]);

void Test_Attack();

void Test_Heal();

void Test_RemoveItemFromInventory();

void Test_CheckForVictoryOrDefeat();

#endif 
