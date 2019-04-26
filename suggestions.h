#pragma once

#include "pch.h"
#include <iostream>
#include "privateLoans.h"
#include "governmentLoans.h"
#include "userData.h"
#include "Calculator.h"


using namespace std;


class suggestions
{
public:
	suggestions();
	~suggestions();
	int choice;
	int choice2

private:
	void question();
	void comSuggestion();
	void suggestion();
	void decision();
	void commuterChoice();
	void communityCollege();
	void majorChange();
	void paymentExtension();



	void question() {
		cout << "Would you like suggestions on how to reduce your monthly payments?" << endl;
		cout << "Enter '1' for yes and '2' for no" << endl;
		cin >> choice;

		//Commuting/ not commuting, attending community college for 2 years, 'see percentage of my income if I switch majors', extend loan payment time 

		if (choice == 1) {
			if (commute == true) {
				comSuggestion();
			}
		}
		else {
			suggestion();
		}

		else if (choice == 2) {
		cout << "Good luck paying your loans lol";
		}
		else {
		cout << "Please input either '1' or '2'";
		question();
		}

	}


	void comSuggestion() {
		cout << "How would you like to reduce your monthly payments?" << endl;
		cout << "1. Commute to eliminate the cost of room and board" << endl;
		cout << "2. Attend a community college for 2 years" << endl;
		cout << "3. Switch majors to raise your monthly income" << endl;
		cout << "4. Extend the payment time of your loan" << endl;

		cin >> choice2;

		if (choice2 !> 0 || choice2 !< 5) {
			cout << "Please enter a valid option";
			cin >> choice2;
		}

		decision();
	}


	void suggestion() {
		cout << "How would you like to reduce your monthly payments?" << endl;
		cout << "1. Attend a community college for 2 years";
		cout << "2. Switch majors to raise your monthly income";
		cout << "3. Extend the payment time of your loan";

		cin >> choice2;

		if (choice2 !> 0 || choice2 !< 4) {
			cout << "Please enter a valid option";
			cin >> choice2;
		}

		choice2 = choice2 + 1;
		decision();
	}


	void decision() {
		if (choice2 == 1) {
			commuterChoice();
		}
		else if (choice2 == 2) {
			communityCollege();
		}
		else if (choice2 == 3) {
			majorChange();
		}
		else {
			paymentExtension();
		}
	}


	void commuterChoice() {
		int commuteTime;
		float semesterRatio;
		float priceRatio;
		float newPercentage;
		float extraMoney;

		cout << "How many semesters do you think you would commute for?" << endl;
		cin >> commuteTime;

		semesterRatio = commuteTime / user1.getNumSemesters;
		priceRatio = housingCost / totalCost;

		newPercentage = percentage - (percentage * priceRatio * semesterRatio);

		extraMoney = salaries[major] * ((newPercentage - percentage) / 100);


		cout << "Commuting for " << commuteTime << " would make your loan payments " << newPercentage << "% of your monthly income";
		cout << " rather than " << percentage << "% of your monthly income." << endl;

		cout << "This would leave you with " << extraMoney << " more dollars per month than before." << endl;

		question();
	}


	void communityCollege() {
		float communityTuition = (4834 * 2);
		float communityPercentage

			communityPercentage = (percentage / 2) + (((communityTuition / (years * 12)) / (salaries[major] / 12)) * 100);

		cout << "Your loan payemnts will now make up " << communityPercentage << "% of your monthly income."

			question();
	}


	void majorChange() {
		float newRemainder;
		float privAmount;
		float govAmount;
		float newMonthlyPayment;

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
		cout << "0. My major is not listed (An average of all graduate salaries will be used)" << endl;

		cin >> newMajor;

		privAmount = monthlyPrivCalculator(years);
		govAmount = monthlyGovCalculator(years);
		newMonthlyPayment = privAmount + govAmount;

		newRemainder = (salaries[newMajor] / 12) - newMonthlyPayment - averageExpenses;

		cout << "Changing your major will leave you with $" << newRemainder << " left over at the end of each month.";

		question();
	}


	void paymentExtension() {
		float newYears;
		float privAmount;
		float govAmount;
		float newMonthlyPayment;
		float newRemainder;

		cout << "How many years would you like to extend your payment plan to?" << endl;
		cin >> newYears;

		privAmount = monthlyPrivCalculator(newYears);
		govAmount = monthlyGovCalculator(newYears);

		newMonthlyPayment = privAmount + govAmount;

		newRemainder = (salaries[major] / 12) - newMonthlyPayment - averageExpenses;

		cout << "Your new monthly payment for loans will be $" << newMonthlyPayment << "." << endl;
		cout << "This will leave you with $" << newRemainder << "left over at the end of each month." << endl;

		question();
	}

};