#pragma once

#include "pch.h"
#include <iostream>
#include "privateLoans.h"
#include "governmentLoans.h"
#include "userData.h"


using namespace std;

int semesters = 8;
int n = 2; // Every new object will increment n by 1
int const K = 5;
privateLoans pLoans[K] = {};
float privatePrice[K] = {};
governmentLoans gLoans;
float governmentPrice = 0;
float privMonthlyPayment[K] = {};

userData user1;

class Calculator
{
public:
	Calculator();
	~Calculator();

	float totalPrivMonthlyPayment = 0;
	float percentage;
	int years;
	int averageExpenses = 3914;

	float salaries[11] = { 65900, 50000, 74200, 67000, 33500, 39000, 53400, 66640, 37800, 54000, 50400 };

private:
	//All function declarations
	void privateLoanTotal();
	void governmentLoanTotal();
	void setTimeFrame();
	void monthlyPrivCalculator(int);
	float monthlyGovCalculator(int);
	float monthlyPercentage();
	float remainingMoney();


	//Calculates the value of each private loan at the time of graduation
	void privateLoanTotal() {
		for (int i = 0; i < K; i++) {
			float pInterest = pLoans[i].getPrivateInterest;
			float pLoanAmount = pLoans[i].getPrivateLoans;


			privatePrice[i] = pLoanAmount * ((pow(1 + pInterest, semesters) - 1) / pInterest);
		}
	}


	//Calculates the value of each government loan at the time of graduation
	void governmentLoanTotal() {

		float gInterest = 0.0505;
		float gLoanAmount = gLoans.getGovernmentLoans;


		governmentPrice = gLoanAmount * ((pow(1 + gInterest, semesters) - 1) / gInterest);

	}

	//Gets input asking how long the user would like to take to pay off their loans
	void setTimeFrame() {
		cout << "How many years would you like to pay your loans off in? " << endl;
		cin >> years;
	}

	//Calculates the required monthly payment to pay off a private loan in a given amount of years (converted to months months)
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
	float monthlyPercentage() {
		int i = user1.getMajor;

		percentage = (monthlyGovCalculator(years) + totalPrivMonthlyPayment) / (salaries[i] / 12);
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



};

