/***********
Name: Alyana Barrera
Assignment: 3100 Project 2 - "Fight!"
Date: 1 Feb 2023

Description: This is the character c++ file that provides all the functions that the character may need.
This file also provides the empty character object for it to be filled in the main file. 
************/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "character.h"

using namespace std;

// global variable 
int damageResult;

// character traits for character object
Character::Character() {
  name = "";
  role = "";
  hitPoints = 0;
  attackBonus = 0;
  damageBonus = 0;
  armorClass = 0;
}

Character::Character(string newName, string newRole, int newHitPoints, int newAttackBonus, int newDamageBonus,int newArmorClass) {
  name = newName;
  role = newRole;
  this->hitPoints = newHitPoints; // will allow for hit points to be set by user input and stay the same for future purposes
  attackBonus = newAttackBonus;
  damageBonus = newDamageBonus;
  armorClass = newArmorClass;
}

/****
print function: prints character summary formatted after user input
****/
void Character::print(ostream& os) {
  os << "\nCharacter summary" << endl;
  os << "-----------------" << endl;
  os << name << " the " << role << endl;
  os << "HP: " << hitPoints << endl;
  os << "AB: " << attackBonus << endl;
  os << "DB: " << damageBonus << endl;
  os << "AC: " << armorClass << endl;
}

/****
attack: attacks other player. 
1. Picks random number from 1-20, then adds to attacking character's attack bonus.
2. If result equals greater than opponent's armor class, attack "hits" else it "misses."
3. If attack hits, random number generates from 1-10, then adds to attacking character's
damage bonus. The subtracts the resulting amount from opponent's hit points using damage() method.
(Reference: Paraphrased from assigment html)
****/
void Character::attack(Character& otherCharacter) {
  cout << "\n" << name << " attacks!" << endl; // prints who begins attack
  int randNum20 = 0, randNum10 = 0, attackResult, hitResult;

  randNum20 = (rand() % 20) + 1; // generates random number between 1-20
  attackResult = randNum20 + attackBonus; // attack result = random number + attack bonus
  cout << "Attack roll: " << randNum20 << " + " << attackBonus << " = "
       << attackResult; // prints equation

  if (attackResult >= otherCharacter.armorClass) { // if attack result is greater than or equal to opponent armor class, then hit
    cout << " --> HIT!" << endl;
    randNum10 = (rand() % 10) + 1; // random number 1-10
    hitResult = randNum10 + damageBonus; // hit result = random number + damage bonus
    cout << "Damage: " << randNum10 << " + " << damageBonus << " = "
         << hitResult << endl; // prints equation

    damageResult = otherCharacter.damage(hitResult); // calls damage function calculating how much damage resulted
    cout << otherCharacter.name << " has " << damageResult
         << " hit points remaining" << endl; // prints the amount of health other character still has

  } else { // when if statement is not true, it is a miss
    cout << " --> MISS!" << endl;
  }
}

/****
damage: calculates damage that the other character enacted from attack by subtracting the hit result from total character's hit points. if less than ot equal to zero return 0 else return number of hit ponts.

Returns: hitPoints (int)
Parameters: amount (int) - hit points result after random number 1-10 plus damage bonus
****/
// will calculate damage with hit and will return if after the hit is less than
// 0, 0 and if not, will return afterHit calculation
int Character::damage(int amount) {
  hitPoints = hitPoints - amount; // keeps hit points to deduct as attacks go on before hitting zero and once hit zero it will return 0 
  if (hitPoints <= 0) {
    return hitPoints = 0;
  } else {
    return hitPoints;
  }
}

// gets current number of hit points remaining
int Character::getHealth() { 
  return hitPoints; 
  }

// gets character name
string Character::getName() { 
  return name; 
  }

// gets character role
string Character::getRole() { 
  return role; 
  }



