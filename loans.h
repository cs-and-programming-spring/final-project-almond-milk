#pragma once
#include <iostream>

using namespace std;

class privateLoans
{
public:
	//variables
	float privateLoan;
	float privateInterest;

	//functions
	void setPrivateLoans();
	float getPrivateLoans();

	void setPrivateInterest();
	float getPrivateInterest();

	void privateLoanTotal();

};

void privateLoans::setPrivateLoans() {
	cout << "Enter the per semester cost of your private loan: " << endl;
	cout << "$";
	cin >> privateLoan;
}

float privateLoans::getPrivateLoans() {
	return privateLoan;
}

void privateLoans::setPrivateInterest() {
	cout << "Enter the interest rate of the private loan as a percent(ex. for 5% interest enter 5): ";
	cin >> privateInterest;
	privateInterest = privateInterest / 100;
	cout << endl;
}

float privateLoans::getPrivateInterest() {
	return privateInterest;
}


