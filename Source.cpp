// studentLoan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>

#include "userData.h"
#include "governmentLoans.h"
#include "loans.h"

using namespace std;
//variables 
float privateTotal[23] = {};

//functions
void privateLoanTotal(int, vector <privateLoans>, int);
void governmentLoanTotal(float);

void monthlyPrivCalculator(int);
float monthlyGovCalculator(int);
float monthlyPercentage(float);
float remainingMoney();


int main() {
	//variables
	float govLoan;
	float totalPrivMonthlyPayment = 0;
	float percentOfSalary;
	int years;
	int averageExpenses = 3914;
	float totalDebt;
	float governmentPrice;

	//salaries of top 10 starting salaries by major and average of all majors starting salary if choice differs
	float salaries[11] = { 50400, 65900, 50000, 74200, 67000, 33500, 39000, 53400, 66640, 37800, 54000 };

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


	//run calculations
	int semesters = user1.getNumSemesters();

	for (int j = 0; j <= numPrivLoans; j++) {
		float tempValMoney = pLoans[j].getPrivateLoans();
		float tempValInterest = pLoans[j].getPrivateInterest();
		float inputtedVal = tempValMoney * ((pow((1 + tempValInterest), semesters) - 1) / tempValInterest);
		privateTotal = privateTotal + inputtedVal;
	}
	//privateLoanTotal(numPrivLoans, pLoans, semesters);			//total cost of private loans after graduation
	governmentLoanTotal(govLoan);					//total cost of government loans after graduation

	//Tell the user how much their debt will be at the end of college

	for (int z = 0; z <= numPrivLoans; z++) {
		totalDebt = totalDebt + privateTotal[z];
	}
	totalDebt = totalDebt + governmentPrice;

	cout << "At the end of college your total debt will be: $" << totalDebt << "." << endl;

	//Determine the amount of time the user wants to have their debt paid off
	user1.setTimeFrame();

	//run monthly payment caculations based on the users desired time frame
	monthlyPrivCalculator(years);
	float monthlyGov = monthlyGovCalculator(years);
	percentOfSalary = monthlyPercentage(monthlyGov);
	float remainingMonthlyAmount = remainingMoney();

	//Display Information to the user
	cout << "Your total monthly loan repayment in order to pay off your loans in " << years << "years is: $" << (monthlyGov + totalPrivMonthlyPayment) << "." << endl;
	cout << "Based on your major, this will take up " << percentOfSalary << "% of your monthly after-tax salary." << endl;
	cout << "Based on the national average expenses, this will leave you with $" << remainingMonthlyAmount << " each month." << endl << endl;

	cout << "If you feel this number is higher than you're comfortable with we have some suggestions to help you out!";
	cout << "Enter the number that corresponds to one of the options below options and we will show you a recalculated loan payment!" << endl;
	cout << "1) ";

}


//Functions


//Calculates the value of each private loan at the time of graduation
/*

void privateLoans::privateLoanTotal(int K, vector<privateLoans> privL, int sems) {
	for (int i = 0; i <= K; i++) {
		float pInterest = privL[i].getPrivateInterest;
		float pLoanAmount = privL[i].getPrivateLoans;


		privateTotal[i] = 
	}
}
*/

//Calculates the value of each government loan at the time of graduation
void governmentLoanTotal(float gLoanAmount) {

	const float GOV_INTEREST = 0.0505;
	governmentPrice = gLoanAmount * ((pow(1 + GOV_INTEREST, semesters) - 1) / GOV_INTEREST);

}

//Calculates the required monthly payment to pay off a private loan in a given amount of years (converted to months)
void monthlyPrivCalculator(int yrs) {
	for (int i = 0; i < K; i++) {
		float privInterest = pLoans[i].getPrivateInterest;
		yrs = yrs * 12;

		privMonthlyPayment[i] = privatePrice[i] * ((privInterest * pow(1 + privInterest, yrs)) / ((pow(1 + privInterest, yrs)) - 1));

		for (int j = 0; j < K; j++) {
			totalPrivMonthlyPayment += privMonthlyPayment[j];
		}

	}
}

//Calculates the required monthly payment to pay off a government loan in a given amount of years (converted to months)
float monthlyGovCalculator(int yrs) {
	const float govInterest = 0.0505;
	yrs = yrs * 12;

	float govMonthlyPayment = governmentPrice * ((govInterest * pow(1 + govInterest, yrs)) / ((pow(1 + govInterest, yrs)) - 1));

	return govMonthlyPayment;
}


//Calculates the percentage of the person's monthly salary that loan payments will make up
float monthlyPercentage(float mGov) {
	int i = user1.getMajor;

	percentage = (mGov + totalPrivMonthlyPayment) / (salaries[i] / 12);
	percentage = percentage * 100;

	return percentage;
}


//Calcuates how much money the user will have left over based on their monthly salary, their monthly loan payments, and average cost of living
float remainingMoney() {
	float remainder;
	int i = user1.getMajor;

	remainder = ((salaries[i] / 12) * (1 - percentage)) - averageExpenses;

	return remainder;
}



