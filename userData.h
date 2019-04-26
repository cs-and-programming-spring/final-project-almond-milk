#pragma once
#include <iostream>
#include <string>

using namespace std;

class userData {
public:
	//variables
	string name;					//user's name
	int major;						//user's major
	int userStatus;					//user's current situation at college: graduated, attending, or about to attend
	int semesters;					//number of semesters the user has or will attend
	float totalCost;
	float grantsAndScholarships;
	bool commute;
	int years;

	string userLoanResponse;
	bool doesUserHaveLoans;
	int numPrivLoans;

	//get and set functions of the various information needed from the user

	//general information functions
	void setName();		
	string getName();

	void setMajor();
	int getMajor();

	void setCurrentStatus();
	int getCurrentStatus();

	void setNumSemesters();
	int getNumSemesters();

	void setCost();
	float getCost();

	void setGrantsAndScholarships();
	float getGrantsAndScholarships();

	//loan functions
	void setNumGovLoans();
	bool getNumGovLoans();

	void setNumPrivLoans();
	int getNumPrivLoans();

	void setTimeFrame();

private:

};

//sets the users name and stores it in a public variable
void userData::setName() {
	cout << "Hello! We are here to help you get a better idea of what your college education costs and provide some clarity to your loans!" << endl;
	cout << "Before we can help, we need a little bit of information about you!" << endl << endl;
	cout << "What is your name?" << endl;

	getline(cin, name);
}

//returns the users name
string userData::getName() {
	return name;
}

//sets the users major and stores it in a public variable
void userData::setMajor() {
	cout << "Enter the number associated with your major from the following list: " << endl;
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

	cin >> major;
}

//returns the users major
int userData::getMajor() {
	return major;
}

//sets the users collegiate status: attending, about to attend, or graduated
void userData::setCurrentStatus() {
	cout << "Please input the number of the status that matches your current situation:" << endl;
	cout << "1) I am about attend to or thinking about attending college." << endl;
	cout << "2) I am currently attending college." << endl;
	
	cin >> userStatus;
 }

//returns the users collegiate status
int userData::getCurrentStatus() {
	return userStatus;
}

//sets the number of semesters the student will attend or has attended based on their collegiate situation
void userData::setNumSemesters() {
	if (userStatus == 1) {
		cout << "Please input the number of semesters that you will be attending: " << endl;

		cin >> semesters;
	}
	else if (userStatus == 2) {
		cout << "Please input the sum of number of semesters that you have already attended and how many more you will be attending: ";

		cin >> semesters;
	}
}

//returns the number of semesters the user has or will attend
int userData::getNumSemesters() {
	return semesters;
}


void userData::setCost() {
	int commuteAnswer;
	
	float tuitionCost;
	float housingCost;

	cout << "Are you: 1)paying for on/off campus housing or 2) commuting? Enter 1 or 2: " << endl;
	cin >> commuteAnswer;
	cout << endl;

	if (commuteAnswer == 1) {
		commute = 0;
		cout << "Enter the cost of your room and board OR off campus housing per semester: " << endl;
		cout << "$";
		cin >> housingCost;
		cout << endl;		
	}
	else if (commuteAnswer == 2) {
		commute = 1;
		housingCost = 0;
	}
	
	cout << "Enter the cost for tuition at your school per semester: " << endl;
	cout << "$";
	cin >> tuitionCost;
	cout << endl;

	totalCost = tuitionCost + housingCost;
}

float userData::getCost() {
	return totalCost;
}

void userData::setGrantsAndScholarships() {
	cout << "Enter the amount of money you are recieving in a typical semester in the form of scholarships and grants: " << endl;
	cout << "$";
	cin >> grantsAndScholarships;
	cout << endl;
}

float userData::getGrantsAndScholarships() {
	return grantsAndScholarships;
}

//loan input functions
void userData::setNumGovLoans() {
	cout << "Have you/will you take out any government loans? Please type yes or no: ";
	
	cin.ignore();
	getline(cin, userLoanResponse);
	cout << endl;

	int z = userLoanResponse.length();

	if (z == 3) {
		doesUserHaveLoans = 1;
	}
	else if (z == 2) {
		doesUserHaveLoans = 0;
	}
}

bool userData::getNumGovLoans() {
	return doesUserHaveLoans;
}

void userData::setNumPrivLoans() {
	cout << "How many private loans will you/have you taken out?" << endl;
	cin >> numPrivLoans;
	cout << endl;
}

int userData::getNumPrivLoans() {
	return numPrivLoans;
}

//Gets input asking how long the user would like to take to pay off their loans
void userData::setTimeFrame() {
	cout << "Enter the number of years after graduation that you want all of your debt to be payed off: ";
	cin >> years;
}