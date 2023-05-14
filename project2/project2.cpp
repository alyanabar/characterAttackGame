/***********
Name: Alyana Barrera
Assignment: 3100 Project 2 - "Fight!"
Date: 16 September 2022

Description: This is the main c++ file where it gathers all character information from user
and forms character objects to proceed with the fighting game. It asks for user input for 
2 characters both including each name, role, hit points, attack bonus, damage bonus, and 
armor class. After each input it will share character summaries and then will proceed with
combat simulation where each character attacks until one of their hit points turn to zero.
First character that recieves a zero in hit points/health will lose and other character wins.
************/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include "character.h"

using namespace std;

int main() {
  // declare variables for character 1 and 2
  string name1, name2, role1, role2;
  int hitPoints1, attackBonus1, damageBonus1, armorClass1;
  int hitPoints2, attackBonus2, damageBonus2, armorClass2;

  // get info for character 1 from user input
  cout << "\nFirst character name? " << endl;
  cin >> name1;
  cout << "\n" << name1 << "'s role?" << endl;
  cin >> role1;
  cout << "\n" << name1 << " the " << role1 << "'s hit points?" << endl;
  cin >> hitPoints1;
  cout << "\n" << name1 << " the " << role1 << "'s attack bonus?" << endl;
  cin >> attackBonus1;
  cout << "\n" << name1 << " the " << role1 << "'s damage bonus?" << endl;
  cin >> damageBonus1;
  cout << "\n" << name1 << " the " << role1 << "'s armor class?" << endl;
  cin >> armorClass1;

  // create a character object for character1
  Character character1(name1, role1, hitPoints1, attackBonus1, damageBonus1, armorClass1);

  // print out character1 summary
  character1.print(cout);

  // get info for character 2 from user input
  cout << "\nSecond character name? " << endl;
  cin >> name2;
  cout << "\n" << name2 << "'s role?" << endl;
  cin >> role2;
  cout << "\n" << name2 << " the " << role2 << "'s hit points?" << endl;
  cin >> hitPoints2;
  cout << "\n" << name2 << " the " << role2 << "'s attack bonus?" << endl;
  cin >> attackBonus2;
  cout << "\n" << name2 << " the " << role2 << "'s damage bonus?" << endl;
  cin >> damageBonus2;
  cout << "\n" << name2 << " the " << role2 << "'s armor class?" << endl;
  cin >> armorClass2;

  // create character object for character 2
  Character character2(name2, role2, hitPoints2, attackBonus2, damageBonus2, armorClass2);

  // print out character2 summary
  character2.print(cout);

  // start combat simulation 
  cout << "\nSimulated Combat: " << endl;
  srand(time(0)); // starts random number generator at 0 in attack function so that it can be different each run

  // while loop: if character 1 and character 2's health (hit points) are greater than or equal to -1 then continue the loop
  while (character1.getHealth() >= -1 && character2.getHealth() >= -1) {
    character1.attack(character2); // start character 1 attack
    if (character2.getHealth() == 0) { // if character 2's health (hit points) after attack is equal to 0, then print that character 1 has won and break the loop to end program/game
      cout << "\n" << character1.getName() << " wins!" << endl;
      break;
    } else { // else start character 2's attack
      character2.attack(character1);
      if (character1.getHealth() == 0) { // if character 1's health (hit points) after attack is equal to 0, then print that character 2 has won and break the loop to end program/game
        cout << "\n" << character2.getName() << " wins!" << endl;
        break;
      }
    }
  }
}
    
  
  