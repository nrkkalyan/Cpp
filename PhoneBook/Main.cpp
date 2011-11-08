/*
 * Main.cpp
 *
 *  Created on: Nov 8, 2011
 *      Author: Koosie
 */

#include <iostream>
#include "phonebook.h"
#include "phonelookup.h"

using namespace std;

int main(int argc, char **argv) {
	cout << "Welcome to Phone application" << endl;
	cout << "Please enter your choice" << endl;
	cout << "1 Phonebook " << endl << "2 Phonelookup" << endl;

	int choice;

	cin >> choice;
	phonebook *pb = new phonebook();
	phonelookup *pl = new phonelookup();
	switch (choice) {
		case 1: {
			pb->createPhoneBook();
			break;
		}
		case 2: {
			pl->findPersonByPhone();
			break;
		}
		}

	return 0;
}
