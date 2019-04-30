#pragma once


#include <iostream>
#include "loans.h"
#include "governmentLoans.h"
#include "userData.h"


using namespace std;


class suggestions
{
public:
	int choice;
	int choice2;
	void question(bool, int, float, int, float, float, int, float, float);
	void comSuggestion(bool, int, float, int, float, float, int, float, float);
	void suggestion(bool, int, float, int, float, float, int, float, float);
	float salaries[11] = { 50400, 65900, 50000, 74200, 67000, 33500, 39000, 53400, 66640, 37800, 54000 };
	int averageExpenses = 3914;
private:
	
};

void suggestions::question(bool commute, int numSemesters, float housingCost, int major, float totalCost, float percentage, int years, float privTot, float govTot) {
	cout << "Would you like suggestions on how to reduce your monthly payments?" << endl;
	cout << "Enter '1' for yes and '2' to exit the program" << endl;
	cin >> choice;

	//Commuting/not commuting, attending community college for 2 years, 'see percentage of my income if I switch majors', extend loan payment time 

	if (choice == 1) {
		if (commute == true) {
			comSuggestion(commute, numSemesters, housingCost, major, totalCost, percentage, years, privTot, govTot);
		}
		else {
			suggestion(commute, numSemesters, housingCost, major, totalCost, percentage, years, privTot, govTot);
		}
	}
	else if (choice == 2) {
		cout << "Good luck paying your loans lol";
		exit(0);
	}
	else {
		cout << "Please input either '1' or '2'";
		question(commute, numSemesters, housingCost, major, totalCost, percentage, years, privTot, govTot);
	}

}



void suggestions::comSuggestion(bool commute, int numSemesters, float housingCost, int major, float totalCost, float percentage, int years, float privTot, float govTot) {
	cout << endl;
	cout << "How would you like to reduce your monthly payments?" << endl;
	cout << "1. Attend a community college for 2 years" << endl;
	cout << "2. Switch majors to raise your monthly income" << endl;
	cout << "3. Extend the payment time of your loan" << endl;

	cin >> choice2;

	if ((choice2 <= 0) || (choice2 >= 4)) {
		cout << "Please enter a valid option";
		cin >> choice2;
	}
	else if (choice2 == 1) {
		float communityTuition = (4834 * 2);
				
		float sems = numSemesters - 4.0;
		float ratio = sems / numSemesters;
		
		float communityMonthly;

		communityMonthly = (communityTuition + (totalCost * ratio)) / (years * 12);
	
		cout << "Your monthly loan payments if you go to community college will be $" << communityMonthly << endl;

		question(commute, numSemesters, housingCost, major, totalCost, percentage, years, privTot, govTot);

	}
	else if (choice2 == 2) {
		float newRemainder;
		int newMajor;

		cout << endl;
		cout << "Enter the number of the major you would like to change to: " << endl;
		cout << "1. Computer Science" << endl;
		cout << "2. Business" << endl;
		cout << "3. Engineering" << endl;
		cout << "4. Biology" << endl;
		cout << "5. Psychology" << endl;
		cout << "6. Political Science" << endl;
		cout << "7. Marketing" << endl;
		cout << "8. Nursing" << endl;
		cout << "9. Elementary Education" << endl;
		cout << "10. Criminal Justice" << endl;
		cout << "0. My major is not listed (An average of all salaries will be used)" << endl;

		cin >> newMajor;

		newRemainder = (salaries[newMajor] / 12) - (privTot + govTot) - averageExpenses;
		float remainingMonthly = (salaries[major] / 12) - (privTot + govTot) - averageExpenses;

		cout << "Changing your major will not lower your payments," << endl; 
		cout << "but it will change your leftover money at the end of each month to $" << (newRemainder - remainingMonthly) << endl << endl;

		question(commute, numSemesters, housingCost, major, totalCost, percentage, years, privTot, govTot);
	}
	else {
		float newYears;
		float newMonthlyPayment;

		cout << "How many years would you like to extend your payment plan to?" << endl;
		cin >> newYears;


		newMonthlyPayment = (totalCost) / (newYears * 12);

			cout << "Your new monthly payment for loans will be $" << newMonthlyPayment << "." << endl;

		question(commute, numSemesters, housingCost, major, totalCost, percentage, years, privTot, govTot);
	}
}

	void suggestions::suggestion(bool commute, int numSemesters, float housingCost, int major, float totalCost, float percentage, int years, float privTot, float govTot) {
		cout << "How would you like to reduce your monthly payments?" << endl;
		cout << "1. Commute" << endl;
		cout << "2. Attend a community college for 2 years" << endl;
		cout << "3. Switch majors to raise your monthly income" << endl;
		cout << "4. Extend the payment time of your loan" << endl;

		cin >> choice2;

		if (choice2 <= 0 || choice2 > 4) {
			cout << "Please enter a valid option";
			cin >> choice2;
		}

		if (choice2 == 1) {
			float commuteTime;
			

			cout << "How many semesters do you think you would commute for?" << endl;
			cin >> commuteTime;

			float monthlyPay = ((privTot + govTot) - (commuteTime * housingCost) )/ (years * 12); 
			
			cout << endl << "Commuting for " << commuteTime << " semesters would make your monthly loan payments $" << monthlyPay << endl;

			question(commute, numSemesters, housingCost, major, totalCost, percentage, years, privTot, govTot);
		}
		else if (choice2 == 2) {
			float communityTuition = (4834 * 2);
			
			float sems = numSemesters - 4.0;
			float ratio = sems / numSemesters;
			float communityMonthly;

			communityMonthly = (communityTuition + (totalCost * ratio)) / (years * 12);
			
			cout << "Your monthly loan payments if you go to community college will be $" << communityMonthly << endl;

			question(commute, numSemesters, housingCost, major, totalCost, percentage, years, privTot, govTot);
		}
		else if (choice2 == 3) {
			float newRemainder;
			int newMajor;

			cout << "Enter the number of the major you would like to change to: " << endl;
			cout << "1. Computer Science" << endl;
			cout << "2. Business" << endl;
			cout << "3. Engineering" << endl;
			cout << "4. Biology" << endl;
			cout << "5. Psychology" << endl;
			cout << "6. Political Science" << endl;
			cout << "7. Marketing" << endl;
			cout << "8. Nursing" << endl;
			cout << "9. Elementary Education" << endl;
			cout << "10. Criminal Justice" << endl;
			cout << "0. My major is not listed (An average of all salaries will be used)" << endl;

			cin >> newMajor;

			float totalMon = (privTot + govTot) / (years * 12);
			newRemainder = (salaries[newMajor] / 12) - totalMon - averageExpenses;
			float remainingMonthly = (salaries[major] / 12) - totalMon - averageExpenses;

			cout << "Changing your major will not lower your payments," << endl;
			cout << "but it will change your leftover money at the end of each month to $" << (newRemainder - remainingMonthly) << endl << endl;

			question(commute, numSemesters, housingCost, major, totalCost, percentage, years, privTot, govTot);
		}
		else {
			float newYears;
			float newMonthlyPayment;


			cout << "How many years would you like to extend your payment plan to?" << endl;
			cin >> newYears;

			newMonthlyPayment = (totalCost) / (newYears * 12);
		
			cout << "Your new monthly payment for loans will be $" << newMonthlyPayment << "." << endl;

			question(commute, numSemesters, housingCost, major, totalCost, percentage, years, privTot, govTot);
		}
		choice2 = choice2 + 1;
		
	}
