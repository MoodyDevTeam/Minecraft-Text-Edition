#include <iostream>
#include <array>
#include <fstream>
#include <cstring>
#include <chrono>
#include <thread>
#include "unistd.h"

using namespace std;
using namespace std::this_thread;
using Time = chrono::milliseconds;


#define BLUE cout << "\033[0;34m";
#define RED cout << "\033[0;31m";
#define CYAN cout << "\033[0;36m";
#define YELLOW cout << "\033[0;33m";
#define PURPLE cout << "\033[0;35m";
#define WHITE cout << "\033[0;37m";

void slowPrint(string word)
{
  for (char c: word)
  {
    sleep_for(Time(15));
    cout << c << flush;
  }
}

// Game variables
int health = 100;
int food = 100;
int player;
string inventory[5] = {"[1] Wooden Sword(s)", "[3] Water Bottle", "[12] Apple", "[64] Dark Oak Planks", "[4] Torch"};
string character;
string loadStr;
string lsCs100_1, lsCs100_2, lsCa100_1, lsCa100_2;
int q1, q2, q3, q4, q5;

//Functions declarations
void setPlayer();
void playerStats();
void getLoadStr();
void configureLoadStr();
void deathCheck();
void buildHouse();
void ans_check1();
void ans_check2();

int main() {

  int choice;
  
  WHITE
  cout << "(1) Play \n";
  cout << "(2) Load Game \n";
  cin >> choice;

  if (choice == 1) {



  } else if (choice == 2) {

    getLoadStr();
    cout << "Load String: ";
    cin >> loadStr;
    configureLoadStr();
    ans_check1();

  }

  WHITE
  cout << "Minecraft - Text Adventure Edition \n";
  cout << "By Moody DevTeam Studios  \n";
  cout << "Select your character <1/2> : \n";
  cout << "1. Steve \n";
  cout << "2. Alex \n";
  cin >> player;
  setPlayer();
  cout << "You spawn in the middle of the forest and it is morning! \n";
  cout << "1. Build a house \n";
  cout << "2. Dig a hole and stay there until next morning \n";
  cin >> q1;
  ans_check1();

}

void setPlayer() {

  if (player == 1) {

    character = "Steve";

  } else if (player == 2) {

    character = "Alex";

  } else {

    RED
    cout << "Invalid Option! \a \n";
    exit(0);

  }

}

void playerStats() {
  
  
  cout << "<- - - Inventory - - - >\n";
  PURPLE
  cout << "1. " << inventory[0] << endl;
  cout << "2. " << inventory[1] << endl;
  cout << "3. " << inventory[2] << endl;
  cout << "4. " << inventory[3] << endl;
  cout << "5. " << inventory[4] << endl;
  YELLOW
  cout << "<- - - Statistics - - - > \n";
  RED
  cout << "Health: ";
 
  cout << health << endl;
  CYAN
  cout << "Food Level: "; 
  
  cout << food << endl;
  WHITE
    
} 

void buildHouse() {

  BLUE
  slowPrint("                            ///             \n");
  slowPrint("                           \\\             \n");
  slowPrint("                           ====             \n");
  slowPrint("                           ||||             \n");
  slowPrint("          ==========================        \n");
  slowPrint("        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%      \n");
  slowPrint("       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   \n");
  slowPrint("     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n");
  slowPrint("      ||      _____          _____    ||    \n");
  slowPrint("      ||      | | |          | | |    ||    \n");
  slowPrint("      ||      |-|-|          |-|-|    ||    \n");
  slowPrint("      ||      #####          #####    ||    \n");
  slowPrint("      ||                              ||    \n");
  slowPrint("      ||      _____   ____   _____    ||    \n");
  slowPrint("      ||      | | |   [][]   | | |    ||    \n");
  slowPrint("      ||      |-|-|   [][]   |-|-|    ||    \n");
  slowPrint("      ||      #####   [][]   #####    ||    \n");
  slowPrint("      ||              [][]            ||    \n");
  slowPrint("    ******************____****************  \n");
  slowPrint("    **************************************  \n");

}

void getLoadStr() {

  ifstream read("ls.dat");
  getline(read, lsCs100_1);
  getline(read, lsCs100_2);
  getline(read, lsCa100_1);
  getline(read, lsCa100_2);

}

void configureLoadStr() {

  if (loadStr == lsCs100_1) {

    character = "Steve";
    health = 100;
    q1 = 1; 
    
  } else if (loadStr == lsCs100_2) {

    character = "Steve";
    health = 100;
    q1 = 2; 

  } 

  if (loadStr == lsCa100_1) {

    character = "Alex";
    health = 100;
    q1 = 1; 
    
  } else if (loadStr == lsCa100_2) {

    character = "Alex";
    health = 100;
    q1 = 2; 

  }

}

void deathCheck() {

  if (health == 0) {
     
    RED
    slowPrint("You Died! \a \n");
    exit(0);

  }

}

void ans_check1() {

  if (q1 == 1) {

    cout << "You start building a house... \n";
    buildHouse();
    inventory[3] = "[0] None";
    deathCheck();
    playerStats();
    cout << "You have no wood and you want to restock. \n";
    cout << "1. Collect Birch wood planks \n";
    cout << "2. Apply some final touches to your newly built home \n";
    cin >> q2;

  } else if (q1 == 2) {

    cout << "You dig a hole and stay there until the sun rises... \n";
    if (q2 == 2) {
    
      food = 80;

    } else {

      food = 90;

    }

    deathCheck();
    playerStats();
    cout << "You now plan to build a wooden cabin \n";
    cout << "1. Build a wooden cabin \n";
    cout << "2. Go out mining \n";
    cin >> q2;

    if (q2 == 1) {

      q1 = 1;
      ans_check1();

    } else if (q2 == 2) {

      q1 = 2;
       
			string wood_count = inventory[3];
      cout << "You do not have a pickaxe to go mining!";
			if (wood_count == "[64] Dark Oak Planks") {

				cout << "1. Craft a wooden pickaxe \n";
        cout << "2. Swim in a nearby lake";
				cin >> q3; 
				ans_check2();

			}


    }

  } else {
 
    RED
    cout << "Invalid Option! \n";
    cout << "Please restart Mincecraft Text Adventure Edition. \n";
    exit(0);

  }

}

void ans_check2() {

	if (q3 == 1) {

		cout << "You craft two sticks and use wood to make a wooden pickaxe! \n";
		inventory[3] = "[64] Dark Oak Planks \n";
    inventory[4] = "[1] Wooden Pickaxe \n";

	}

}
  
