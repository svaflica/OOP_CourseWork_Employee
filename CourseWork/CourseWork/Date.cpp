#include "stdafx.h"
#include "Date.h"

//Constructors
Date::Date()
{
	makeAllFieldsEmpty();
}

Date::Date(Date& date)
{
	*this = date;
}

Date::Date(const char* date)
{
	*this = date;
}

Date::Date(UnsignedShortInt day, UnsignedShortInt month, UnsignedShortInt year)
{
	if (!setYear(year)) {
		makeMonthAndDayFieldsEmpty();
		return;
	}

	if (!setMonth(month)) {
		day_ = 0;
		return;
	}

	setDay(day);
}


//Destructor
Date::~Date()
{
}


//Get values
void 
Date::outDate(ostream& out) const
{
	if (day_ < 10)
		out << '0';
	out << day_ << '.';

	if (month_ < 10)
		out << '0';
	out << month_ << '.';
		
	out<< year_ << '\n';
}

UnsignedShortInt
Date::getDay() const
{
	if (isDayInDateValid())
		return day_;
	else
		cout << ExceptionInvalidDay().getMessage() << '\n';

	return NULL;
}

UnsignedShortInt
Date::getMonth() const
{
	if (isMonthValid(month_))
		return month_;
	else
		cout << ExceptionInvalidMonth().getMessage() << '\n';

	return NULL;
}

UnsignedShortInt 
Date::getYear() const
{
	if (isYearValid(year_))
		return year_;
	else
		cout << ExceptionInvalidYear().getMessage() << '\n';

	return NULL;
}

//unsigned char
//Date::getNumberOfDaysInMonthOfDate()
//{
//	if (is31DaysInMonthOfDate())
//		return 31;
//
//	if (is30DaysInMonthOfDate())
//		return 30;
//
//	if (is29DaysInMonthOfDate())
//		return 29;
//
//	return 28;
//}

UnsignedShortInt
Date::getNumberOfDaysInMonth(UnsignedShortInt month, UnsignedShortInt year) const
{
	if (is31DaysInMonth(month))
		return 31;

	if (is30DaysInMonth(month))
		return 30;

	if (is29DaysInMonth(month, year))
		return 29;

	return 28;
}

//int 
//Date::getDateForm(char* date)
//{
//	if (isDateInNumberForm(date))
//		return 1;
//	else if (isDateInWordForm())
//		return 2;
//	else return 0;
//}

//unsigned char 
//Date::getMonthFromDateOfWordForm(char* date)
//{
//	//Max length is for longest name:
//	//"february"
//	String month;
//
//	int length = strlen(date);
//	for (int i = 3; i < length - 4; i++)
//		month = month + (date[i]);
//
//
//}


//Set values
bool 
Date::setDay(UnsignedShortInt day)
{
	if (!isMonthValid(month_)) {
		cout << "You can't set the day because "
			<< ExceptionInvalidMonth().getMessage()
			<< '\n';

		day_ = 0;
		return false;
	}
	else if (!isDayValid(day, month_, year_)) {
		cout << "You can't set day because "
			 << ExceptionInvalidDay().getMessage() 
			 << '\n';

		day_ = 0;
		return false;
	}

	return true;
}

bool
Date::setMonth(UnsignedShortInt month)
{
	if (!isMonthValid(month)) {
		cout << "You can't set month because: "
			 << ExceptionInvalidMonth().getMessage() 
			 << '\n';

		month_ = 0;
		return false;
	}
	
	month_ = month;
	return true;
}

bool
Date::setYear(UnsignedShortInt year)
{
	if (!isYearValid(year)) {
		cout << "You can't set year because "
			 << ExceptionInvalidYear().getMessage() 
			 << '\n';

		year_ = 0;
		return false;
	}

	year_ = year;
	return true;
}


//Enter value
bool 
Date::enterDay(istream& in)
{
	in >> day_;

	if (!in || !isDayValid(day_, month_, year_)) {
		cout << ExceptionInvalidDay().getMessage() << '\n';
		day_ = 0;
		return false;
	}

	return true;
}

bool 
Date::enterMonth(istream& in)
{
	in >> month_;

	if (!in || !isMonthValid(month_)) {
		cout << ExceptionInvalidMonth().getMessage() << '\n';
		month_ = 0;
		return false;
	}

	return true;
}

bool
Date::enterYear(istream& in)
{
	in >> year_;

	if (!in || !isYearValid(year_)) {
		cout << ExceptionInvalidYear().getMessage() << '\n';
		year_ = 0;
		return false;
	}

	return true;
}


//Overloaded operators
Date& 
Date::operator=(Date& date)
{
	if (isYearValid(date.year_))
		year_ = date.year_;
	else {
		cout << ExceptionInvalidYear().getMessage() << '\n';

		makeAllFieldsEmpty();
		return *this;
	}

	if (isMonthValid(date.month_))
		month_ = date.month_;
	else {
		cout << ExceptionInvalidMonth().getMessage() << '\n';

		makeMonthAndDayFieldsEmpty();
		return *this;
	}

	if (isDayValid(date.day_, month_, year_))
		day_ = date.day_;
	else {
		cout << ExceptionInvalidDay().getMessage() << '\n';

		day_ = 0;
	}

	return *this;
}

Date& 
Date::operator=(const char* date)
{
	if (!isDateFormOfEntryValid(date)) {
		cout << "You can't assign value because "
			<< ExceptionInvalidDateForm().getMessage()
			<< '\n';

		makeAllFieldsEmpty();
		return *this;
	}

	int length = strlen(date);

	//"DD"
	year_ = (int)(date[length - 4] - '0') * 1000 +
		(int)(date[length - 3] - '0') * 100 +
		(int)(date[length - 2] - '0') * 10 +
		(int)(date[length - 1] - '0');

	if (!isYearInDateValid()) {
		cout << ExceptionInvalidYear().getMessage() << '\n';

		makeAllFieldsEmpty();
		return *this;
	}

	month_ = (int)(date[3] - '0') * 10 + (int)(date[4] - '0');

	if (!isMonthInDateValid()) {
		cout << ExceptionInvalidMonth().getMessage() << '\n';

		makeMonthAndDayFieldsEmpty();
		return *this;
	}

	day_ = (int)(date[0] - '0') * 10 + (int)(date[1] - '0');

	if (!isDayInDateValid()) {
		cout << ExceptionInvalidDay().getMessage() << '\n';

		day_ = 0;
	}

	return *this;
}

ostream& operator<<(ostream& out, Date& date)
{
	if (!date.isDayInDateValid()) {
		out << "You can't output date because "
			<< ExceptionInvalidDay().getMessage()
			<< '\n';
		return out;
	}

	if (!date.isMonthInDateValid()) {
		out << "You can't output date because "
			<< ExceptionInvalidMonth().getMessage()
			<< '\n';
		return out;
	}

	if (!date.isYearInDateValid()) {
		out << "You can't output date because "
			<< ExceptionInvalidYear().getMessage()
			<< '\n';
		return out;
	}

	date.outDate(out);

	return out;
}

istream& operator>>(istream& in, Date& date)
{
	cout << "Please, enter the year: ";
	if (!date.enterYear(in)) {
		date.makeAllFieldsEmpty();
		return in;
	}

	cout << "Please, enter the month: ";
	if (!date.enterMonth(in)) {
		date.makeMonthAndDayFieldsEmpty();
		return in;
	}

	cout << "Please, enter the day: ";
	date.enterDay(in);

	return in;
}

//Boolean verifications
bool 
Date::isDayInDateValid() const
{
	return (minDay() <= day_ && day_ <= getNumberOfDaysInMonth(month_, year_));
}

bool
Date::isMonthInDateValid() const
{
	return (maxMonth() >= month_ && month_ >= minMonth());
}

bool
Date::isYearInDateValid() const
{
	return (maxYear() >= year_ && year_ >= minYear());
}

bool 
Date::isDayValid(UnsignedShortInt day, UnsignedShortInt month, UnsignedShortInt year) const
{
	return (minDay() <= day && day <= getNumberOfDaysInMonth(month, year));
}

bool 
Date::isMonthValid(UnsignedShortInt month) const
{
	return (maxMonth() >= month && month >= minMonth());
}

bool 
Date::isYearValid(UnsignedShortInt year) const
{
	return (maxYear() >= year && year >= minYear());
}

bool 
Date::is31DaysInMonthOfDate() const
{
	return (month_ == 1 || month_ == 3  ||
			month_ == 5 || month_ == 7  ||
			month_ == 8 || month_ == 10 ||
			month_ == 12);
}

bool 
Date::is30DaysInMonthOfDate() const
{
	return (month_ == 4 || month_ == 6 ||
			month_ == 9 || month_ == 11);
}

bool 
Date::is29DaysInMonthOfDate() const
{
	return (!(year_ % 400 == 0) && month_ == 2);
}

bool 
Date::is28DaysInMonthOfDate() const
{
	return ((year_ % 400 == 0) && month_ == 2);
}

bool 
Date::is31DaysInMonth(UnsignedShortInt month) const
{
	return (month == 1 || month == 3 ||
		    month == 5 || month == 7 ||
		    month == 8 || month == 10 ||
		    month == 12);

}

bool 
Date::is30DaysInMonth(UnsignedShortInt month) const
{
	return (month == 4 || month == 6 ||
		    month == 9 || month == 11);
}

bool 
Date::is29DaysInMonth(UnsignedShortInt month, UnsignedShortInt year) const
{
	return (!(year % 400 == 0) && month == 2);
}

bool 
Date::is28DaysInMonth(UnsignedShortInt month, UnsignedShortInt year) const
{
	return ((year % 400 == 0) && month == 2);
}

bool 
Date::isDateFormOfEntryValid(const char* date)
{
	int length = strlen(date);

	//"DD.MM.YYYY"
	if (length == lengthCharFormEntry())
		return isDateInNumberForm(date);

	////"DD "/month by word/" YYYY"
	//if (lengthCharFormEntry() < length && length <= maxLengthCharFormEntry())
	//	return isDateInWordForm(date);

	return false;
}

//"DD.MM.YYYY"
bool 
Date::isDateInNumberForm(const char* date)
{           //"DD"
	return (isdigit(date[0]) && isdigit(date[1]) &&
			//'.'
			date[2] == '.' &&
			//"MM"
		    isdigit(date[3]) && isdigit(date[4]) &&
			//'.'
			date[5] == '.' &&
			//"YYYY"
		    isdigit(date[6]) && isdigit(date[7]) &&
		    isdigit(date[8]) && isdigit(date[9]));
}

////"DD "/month by word/" YYYY"
//bool 
//Date::isDateInWordForm(char* date)
//{
//	    //"DD"
//	if (isdigit(date[0]) && isdigit(date[1]) &&
//		//' '
//		date[2] == ' ') {
//
//		int length = strlen(date);
//		//Month by word
//		for (int i = 3; i < length - 5; i++)
//			if (!isalpha(date[i]))
//				return false;
//
//		   //' '
//		if (date[length - 5] == ' ' &&
//			//"YYYY"
//			isdigit(date[length - 4]) && isdigit(date[length - 3]) &&
//			isdigit(date[length - 2]) && isdigit(date[length - 1]))
//			return true;
//	}
//
//	return false;
//}


//Make empty fields
void 
Date::makeAllFieldsEmpty()
{
	year_ = 0;
	month_ = 0;
	day_ = 0;
}

void 
Date::makeMonthAndDayFieldsEmpty()
{
	month_ = 0;
	day_ = 0;
}


//Constants
UnsignedShortInt
Date::minDay() const
{
	return 1;
}

UnsignedShortInt
Date::maxMonth() const
{
	return 12;
}

UnsignedShortInt
Date::minMonth() const
{
	return 1;
}

UnsignedShortInt
Date::maxYear() const
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);

	localtime_s(&timeinfo, &rawtime);

	return timeinfo.tm_year + 1900;
}

UnsignedShortInt
Date::minYear() const
{
	return 1900;
}

//In form :
//"DD.MM.YYYY"
UnsignedShortInt
Date::lengthCharFormEntry() const
{
	return 10;
}
