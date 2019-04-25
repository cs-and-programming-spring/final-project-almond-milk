// studentLoan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "userData.h"
#include "governmentLoans.h"
#include "loans.h"

using namespace std;

int main() {
	//variables
	float govLoan;

	//create user
	userData user1;

	//set users name
	user1.setName();

	//greet user
	cout << endl << "Hi " << user1.getName() << "! We're glad you're here!" << endl << endl;

	//set major
	user1.setMajor();
	cout << endl;

	//set current collegiate status
	user1.setCurrentStatus();
	cout << endl;

	//set number of semesters
	user1.setNumSemesters();
	cout << endl;

	//set collegiate costs
	user1.setCost();

	//set grants or scholarships
	user1.setGrantsAndScholarships();
	cout << endl;

	//Obtain loan information

	//Number of government loans
	user1.setNumGovLoans();

	//get cost of government loans
	governmentLoans loan1;

	bool hasGov = user1.getNumGovLoans();

	if (hasGov == 1) {
		loan1.setGovernmentLoans();
		govLoan = loan1.getGovernmentLoans();
	}
	else if (hasGov == 0) {
		govLoan = 0;
	}

	//Number of private loans
	user1.setNumPrivLoans();

	//get cost of private loans
	int numPrivLoans = user1.getNumPrivLoans();

	vector<privateLoans> pLoans(numPrivLoans);

	for (int i = 0; i <= numPrivLoans; i++) {
		pLoans[i].setPrivateLoans();
		pLoans[i].setPrivateInterest();
	}
}