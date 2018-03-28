#pragma once
#ifndef EMPLOYEE
#define EMPLOYEE

#include <iostream>
#include <ctime>
//Exceptions
#include "ExceptionYear.h"
#include "ExceptionWrongParameter.h"
#include "ExceptionLastNameAndInitials.h"
#include "ExceptionTitleOfPosition.h"
#include "ExceptionWrongInput.h"
//Other classes, used there
#include "String.h"
#include "Date.h"
#include "Dictionary.h"
#include "DictionaryStorage.h"

typedef unsigned short int UnsignedShortInt;

using namespace std;

class Employee
{
public:
	//Constructors
	Employee();
	Employee(char* lastNameAndInitials, char* titleOfPosition,
		     const UnsignedShortInt yearOfBeginning, char* dateOfBirth);
	Employee(const Employee& employee);

	//Destructor
	~Employee();

	//Overloaded comparison operators
	bool operator>(const Employee& emp) const;
	bool operator>=(const Employee& emp) const;
	bool operator<(const Employee& emp) const;
	bool operator<=(const Employee& emp) const;
	bool operator==(const Employee& emp) const;

	//Overloaded operators
	Employee operator=(const Employee& emp);
	friend Employee operator+(const Employee& emp1);

	//Overloaded operators
	//of input and output
	friend ostream& operator<<(ostream& out, const Employee& emp);
	friend istream& operator>>(istream& in, Employee& emp);
	
	//Search maximal object from array of objects
	//by comparison of string "lastNameAndInitials
	Employee& maxObject(Employee* empArray, int length);

private:
	String lastNameAndInitials_;
	int numberOfProfessionInDictionary_;
	UnsignedShortInt yearOfBeginning_;
	UnsignedShortInt age_;
	Date dateOfBirth_;


	UnsignedShortInt calculateAge();

	//Enter value
	void enterLastNameAndInitials(istream& in);
	void enterTitleOfPosition(istream& in);
	void enterYearOfBeginning(istream& in);

	//Boolean verifications
	bool isLastNameAndInitialsValid();
	bool isLastNameAndInitialsValid(char* lastNameAndInitials);
	bool isTitleOfPositionValid(const char* titleOfPosition);
	bool isYearValid();
	bool isYearValid(unsigned char yearOfBeginning);

	//compare one object with other
	//by string "lastNameAndInitials"
	int compare(const Employee& emp1, const Employee& emp2) const;

	//Constants
	UnsignedShortInt minLengthTitleOfPosition() const;
	UnsignedShortInt minLengthLastNameAndInitials() const;
	UnsignedShortInt minYear() const;
	UnsignedShortInt maxYear() const;
};

#endif
