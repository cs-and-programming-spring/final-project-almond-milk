#pragma once
#include <iostream>
#include <string>

using namespace std;

class governmentLoans
{
public:
	//variables
	float governmentLoan;

	//functions
	void setGovernmentLoans();
	float getGovernmentLoans();

private: 
	
};

void governmentLoans::setGovernmentLoans() {
	cout << "Please enter the amount of financial aid you are recieving in the form of Government loans per semester: " << endl;
	cout << "$";
	cin >> governmentLoan;
	cout << endl;
}

float governmentLoans::getGovernmentLoans() {
	return governmentLoan;
}


