/*
 * PhoneLookUp.cpp
 *
 *  Created on: Nov 8, 2011
 *      Author: Koosie
 */

#include "phonelookup.h"
#include "iostream"
#include <fstream>
#include <map>

using namespace std;

phonelookup::phonelookup() {
	// TODO Auto-generated constructor stub

}

phonelookup::~phonelookup() {
	// TODO Auto-generated destructor stub
}

int phonelookup::findPersonByPhone() {
	cout << "Phone Lookup application";

	fstream in("phonebook.txt");
	if (!in) {
		cout << "Could not able to read the file";
	}

	map<long, string> phoneLookup;
	long number;
	string name;

	while (in >> name >> number) {
		phoneLookup[number] = name;
	}

	in.close();

	map<long, string>::const_iterator it;

	while (true) {
		cout << "Please enter the phone number" << endl;
		cin >> number;

		if (number == 0) {
			cout << "Exit";
			break;
		}
		it = phoneLookup.find(number);
		if (it == phoneLookup.end()) {
			cout << "No persons found for that phone number" << endl;
		} else {

			int pos = it->second.find(',');

			cout << "Phone number " << number << " belongs to "
					<< it->second.substr(pos + 1) << " "
					<< it->second.substr(0, pos) << endl;
		}
	}

	return 0;
}

