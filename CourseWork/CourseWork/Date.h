#pragma once
#ifndef DATE
#define DATE

#include <ctime>
#include "String.h"
#include "ExceptionInvalidDateForm.h"
#include "ExceptionInvalidMonth.h"
#include "ExceptionInvalidDay.h"
#include "ExceptionYear.h"
#include <iostream>

typedef unsigned short int UnsignedShortInt;

using namespace std;

class Date
{
public:
	//Constructors
	Date();
	Date(Date& date);
	Date(const char* date);
	Date(UnsignedShortInt day, UnsignedShortInt month, UnsignedShortInt year);

	//Destructor
	~Date();

	//Get value
	UnsignedShortInt getDay() const;
	UnsignedShortInt getMonth() const;
	UnsignedShortInt getYear() const;

	//Overloaded operators
	Date& operator=(Date& date);
	Date& operator=(const char* date);

	friend ostream& operator<<(ostream& out, Date& date);
	friend istream& operator>>(istream& in, Date& date);

private:
	UnsignedShortInt day_;
	UnsignedShortInt month_;
	UnsignedShortInt year_;

	void outDate(ostream& out) const;

	//Set value
	bool setDay(UnsignedShortInt day);
	bool setMonth(UnsignedShortInt month);
	bool setYear(UnsignedShortInt year);

	bool enterDay(istream& in);
	bool enterMonth(istream& in);
	bool enterYear(istream& in);

	//Get value 
	UnsignedShortInt getNumberOfDaysInMonth(UnsignedShortInt month, UnsignedShortInt year) const;
	UnsignedShortInt getNumberOfDaysInMonthOfDate();
	int getDateForm(char* date);
	UnsignedShortInt getMonthFromDateOfWordForm(char* date);

	//Make empty fields
	void makeAllFieldsEmpty();
	void makeMonthAndDayFieldsEmpty();

	//Boolean verifications
	bool isDayInDateValid() const;
	bool isMonthInDateValid() const;
	bool isYearInDateValid() const;

	bool isDayValid(UnsignedShortInt day, UnsignedShortInt month, UnsignedShortInt year) const;
	bool isMonthValid(UnsignedShortInt month) const;
	bool isYearValid(UnsignedShortInt year) const;

	bool is31DaysInMonthOfDate() const;
	bool is30DaysInMonthOfDate() const;
	bool is29DaysInMonthOfDate() const;
	bool is28DaysInMonthOfDate() const;

	bool is31DaysInMonth(UnsignedShortInt month) const;
	bool is30DaysInMonth(UnsignedShortInt month) const;
	bool is29DaysInMonth(UnsignedShortInt month, UnsignedShortInt year) const;
	bool is28DaysInMonth(UnsignedShortInt month, UnsignedShortInt year) const;

	bool isDateFormOfEntryValid(const char* date);
	bool isDateInNumberForm(const char* date);
	bool isDateInWordForm(char* date);

	//Constants
	UnsignedShortInt maxDay() const;
	UnsignedShortInt minDay() const;
	UnsignedShortInt maxMonth() const;
	UnsignedShortInt minMonth() const;
	UnsignedShortInt maxYear() const;
	UnsignedShortInt minYear() const;
	UnsignedShortInt lengthCharFormEntry() const;
	/*UnsignedShortInt maxLengthCharFormEntry() const;*/
};

#endif