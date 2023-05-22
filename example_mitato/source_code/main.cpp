// main.cpp
// feeding the mitato animals

#include <iostream>
#include <vector>
#include "animal.h"
#include "feed_pigs.h"
#include "feed_sheep.h"
#include "feed_goats.h"
#include <stdlib.h> // system("cls");

extern int feeding_turn; // it is the variable also located in <feeder*.h> files

using namespace std;

int main()
{
	int option = 2;

	// the groups of animal-entities
	vector<Animal> pig_team;
	vector<Animal> sheep_team;
	vector<Animal> goat_team;
	/* ***************************
	
	... add more animal teams ...
	
	* ************************* */


	// creating animal-entities
	Animal pig01(1, 'p', 50.5);
	Animal pig02(2, 'p', 62.3);
	Animal sheep01(3, 's', 40.0);
	Animal sheep02(4, 's', 70.0);
	Animal goat01(5, 'g', 30.0);
	Animal goat02(6, 'g', 15.5);
	Animal goat03(7, 'g', 20.1);
	/* ***************************

	   ... add more animals ...

	* ************************* */


	// animal-entities entering the appropriate vector/team
	pig_team.push_back(pig01);
	pig_team.push_back(pig02);
	sheep_team.push_back(sheep01);
	sheep_team.push_back(sheep02);
	goat_team.push_back(goat01);
	goat_team.push_back(goat02);
	goat_team.push_back(goat03);
	/* **************************

	  add animals to mitato teams

	* ************************* */



	// activating and setting the feeder objects for pigs
	feed_pigs p_mam;
	p_mam.set_team(pig_team);
	
	// activating and setting the feeder objects for sheep
	feed_sheep s_mam;
	s_mam.set_team(sheep_team);

	// activating and setting the feeder objects for goats
	feed_goats g_mam;
	g_mam.set_team(goat_team);
	
	/* ***************************

	   ... animal feed check ...

	* ************************* */



	// the menu
	while (option != 0) {
		
		cout << "\nGive 1 to check" << endl;
		cout << "Give 0 to exit" << endl;
		cin >> option;

		system("cls"); // clear screen

		switch (option) {
			case 0: 
				break;
			case 1:
				cout << endl << "- --------------------- -" << endl;
				p_mam.feed_alarm(); // check pigs for feeding
				s_mam.feed_alarm(); // check sheep for feeding
				g_mam.feed_alarm(); // check goats for feeding
				cout << endl << "- --------------------- -" << endl;
				feeding_turn++;
				break;
			default:
				cout << "\nWrong input my friend\n";
		}

	}

	return 0;
}
