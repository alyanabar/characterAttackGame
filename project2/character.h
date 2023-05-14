/***********
Name: Alyana Barrera
Assignment: 3100 Project 2 - "Fight!"
Date: 16 September 2022

Description: This is the character.h file where we set private and pubic member data and
set a constructor and getters and setters. 
************/

#pragma once 
#include <string>

using namespace std;

class Character {
// private member data
private:
  string name;
  string role;
  int hitPoints;
  int attackBonus;
  int damageBonus;
  int armorClass;

public:
// declare constructor
Character();

// parameterize constructor
Character(string, string, int, int, int, int);

// pretty print
void print(ostream &);

// setter for name
void setName(string);

// for attacking
void attack(Character &otherCharacter);

// for finding damage
int damage(int);

// getter for name
string getName();

// getter for health of character
int getHealth();

// getter for role of character
string getRole();

// getter for hit points
int getHitPoints();
}
;