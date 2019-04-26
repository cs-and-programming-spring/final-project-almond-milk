#pragma once

#include "pch.h"
#include <iostream>
#include "privateLoans.h"
#include "governmentLoans.h"
#include "userData.h"


using namespace std;


class suggestions
{
public:
	suggestions();
	~suggestions();
	int choice;

private:
	void suggestion();



	void suggestion() {
		cout << "Would you like suggestions on how to reduce your monthly payments?" << endl;
		cout << "Enter '1' for yes and '2' for no" << endl;
		cin >> choice;


		if (choice == 1) {
			if (commute == true) {

			}
		}
		else if (choice == 2) {
			cout << "Good luck paying your loans lol";
		}
		else {
			cout << "Please input either '1' or '2'";
			suggestion();
		}

	}


};

