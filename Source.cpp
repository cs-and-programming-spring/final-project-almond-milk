// studentLoan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>

#include "userData.h"
#include "governmentLoans.h"
#include "loans.h"
#include "suggestions.h"

using namespace std;
//variables 
float privateTotal;

//functions
//void privateLoanTotal(int, vector <privateLoans>, int);
float governmentLoanTotal(float, int);
float monthlyPrivCalculator(int, float);
float monthlyGovCalculator(int, float);
float monthlyPercentage(float, int, float);
float remainingMoney(int, int, float, float, int);

//salaries of top 10 starting salaries by major and average of all majors starting salary if choice differs
float salaries[11] = { 50400, 65900, 50000, 74200, 67000, 33500, 39000, 53400, 66640, 37800, 54000 };

int main() {
	//variables
	float govLoan;
	float totalPrivMonthlyPayment;
	float percentOfSalary;
	int averageExpenses = 3914;
	float totalDebt;

	
	//create user
	userData user1;

	//set users name
	user1.setName();

	//greet user
	cout << endl << "Hi " << user1.getName() << "! We're glad you're here!" << endl << endl;

	//set major
	user1.setMajor();
	int userMajor = user1.getMajor();
	cout << endl;

	//set current collegiate status
	user1.setCurrentStatus();
	cout << endl;

	//set number of semesters
	user1.setNumSemesters();
	cout << endl;

	//set collegiate costs
	user1.setCost();

	bool commute = user1.getCommute();
	float housingCosts = 0;
	housingCosts = user1.getHousingCost();

	//set grants or scholarships
	user1.setGrantsAndScholarships();
	cout << endl;

	//Obtain loan information
	cout << "*************************************************************************************************************" << endl;
	cout << "Almost ready to provide you clarity on your loans! We just need a little information about your current loans!" << endl;
	cout << "*************************************************************************************************************" << endl << endl;
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

	for (int i = 0; i < numPrivLoans; i++) {
		pLoans[i].setPrivateLoans();
		pLoans[i].setPrivateInterest();
	}
	
	//run calculations

	int numSemesters = user1.getNumSemesters();

	for (int j = 0; j < numPrivLoans; j++) {
		float tempValMoney = pLoans[j].getPrivateLoans();
		float tempValInterest = pLoans[j].getPrivateInterest();

		float inputtedVal = (tempValMoney* 2) * (((pow((1 + tempValInterest), (numSemesters/2))) - 1) / (tempValInterest));
		privateTotal = privateTotal + inputtedVal;
	}
	
	float governmentPrice = governmentLoanTotal(govLoan, numSemesters);		//total cost of government loans after graduation

	//Determine total debt
	totalDebt = privateTotal + governmentPrice;
	
	cout << "At the end of college your total debt will be: $" << totalDebt << "." << endl;

	//Determine the amount of time the user wants to have their debt paid off
	user1.setTimeFrame();

	int yearsTilPaid = user1.getTimeFrame();

	//run monthly payment caculations based on the users desired time frame
	totalPrivMonthlyPayment = monthlyPrivCalculator(yearsTilPaid, privateTotal);
	float monthlyGov = monthlyGovCalculator(yearsTilPaid, governmentPrice);
	percentOfSalary = monthlyPercentage(monthlyGov, userMajor, totalPrivMonthlyPayment);
	float remainingMonthlyAmount = remainingMoney(userMajor, averageExpenses, totalPrivMonthlyPayment, monthlyGov, yearsTilPaid);

	//Display Information to the user
	
	cout << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << "Your total monthly loan repayment in order to pay off your loans in " << yearsTilPaid << " years is: $" << (monthlyGov + totalPrivMonthlyPayment) << "." << endl <<endl;
	cout << "Based on your major, this will take up " << percentOfSalary << "% of your monthly after-tax salary." << endl << endl;
	cout << "Based on the national average expenses, this will leave you with $" << remainingMonthlyAmount << " each month." << endl;
	cout << "***********************************************************************************************************************" << endl;

	suggestions suggestion1;

	suggestion1.question(commute, numSemesters, housingCosts, userMajor, totalDebt, percentOfSalary, yearsTilPaid, privateTotal, governmentPrice);

}


//Functions

//Calculates the value of each government loan at the time of graduation
float governmentLoanTotal(float gLoanAmount, int sems) {
	float governmentPrice = gLoanAmount * sems;

	return governmentPrice;
}

//Calculates the required monthly payment to pay off a private loan in a given amount of years (converted to months)
float monthlyPrivCalculator(int yrs, float totalPrivPrice) {
	int months = yrs * 12;

	float monthlyPayment = totalPrivPrice / months;

	return monthlyPayment;
	
}

//Calculates the required monthly payment to pay off a government loan in a given amount of years (converted to months)
float monthlyGovCalculator(int yrs, float governmentPrice) {
	const float GOV_INTEREST = 0.0505;

	float govMonthlyPayment = governmentPrice * ((GOV_INTEREST * pow(1 + GOV_INTEREST, yrs)) / ((pow(1 + GOV_INTEREST, yrs)) - 1));
	
	govMonthlyPayment = govMonthlyPayment / 12;
	return govMonthlyPayment;
}


//Calculates the percentage of the person's monthly salary that loan payments will make up
float monthlyPercentage(float mGov, int major, float totalPrivMonthlyPayment) {
	
	float percentage = (mGov + totalPrivMonthlyPayment) / (salaries[major] / 12);
	percentage = percentage * 100;

	return percentage;
}


//Calcuates how much money the user will have left over based on their monthly salary, their monthly loan payments, and average cost of living
float remainingMoney(int major, int averageExpenses, float monthlyPriv, float monthlyGov, int yrs) {
	float remainder;
		
	remainder = (salaries[major] / 12) - monthlyPriv - monthlyGov - averageExpenses;

	return remainder;
}
