/*
 * PhoneBook.cpp
 * Program to read and sort phone numbers from a file.
 *
 * File must contain phone number in the following format.
 * Richard,Ian 3322
 * There must be no space in the name or phone number
 *
 *  Created on: Nov 6, 2011
 *      Author: Koosie
 */

#include "PhoneBook.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Phone {
	string name;
	long phoneNumber;
};

bool numberComparator(const Phone& phone1, const Phone& phone2) {
	return phone1.phoneNumber > phone2.phoneNumber;
}

int main(int argc, char **argv) {
	cout << "PhoneBook application";

	ifstream in("phonebook.txt");

	if (!in) {
		cout << "Unable to open the phonebook.txt file";
		return -1;
	}

	vector<Phone> phoneNumbers;

	Phone phoneEntry;

	while (in >> phoneEntry.name >> phoneEntry.phoneNumber) {
		phoneNumbers.push_back(phoneEntry);
	}
	in.close();

	sort(phoneNumbers.begin(), phoneNumbers.end(), numberComparator);

	for (vector<Phone>::const_iterator it = phoneNumbers.begin();
			it != phoneNumbers.end(); it++) {
		cout << it->name << "=" << it->phoneNumber << endl;
	}

	return 0;
}

