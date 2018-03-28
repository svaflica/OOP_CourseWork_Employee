#include "stdafx.h"
#include "Employee.h"



Employee::Employee()
{
	yearOfBeginning_ = 0;
	numberOfProfessionInDictionary_ = 0;
	age_ = 0;
}


Employee::Employee(char* lastNameAndInitials, char* titleOfPosition, 
	               const UnsignedShortInt yearOfBeginning, char* dateOfBirth)
{
	if (!isLastNameAndInitialsValid(lastNameAndInitials)) {
		cout << ExceptionInvalidLastNameAndInitials().getMessage() << '\n';

		/*yearOfBeginning_ = 0;
		numberOfProfessionInDictionary_ = 0;
		age_ = 0;
		return;*/
	}

	lastNameAndInitials_ = lastNameAndInitials;

	if (!isTitleOfPositionValid(titleOfPosition)) {
		cout << ExceptionInvalidTitleOfPosition().getMessage() << '\n';		

		/*yearOfBeginning_ = 0;
		numberOfProfessionInDictionary_ = 0;
		age_ = 0;
		return;*/
	}

	String title(titleOfPosition);

	if (!DictionaryStorage::getDictionary().searchItem(title)) {
		DictionaryStorage::getDictionary().insertItem(title);
		numberOfProfessionInDictionary_ = DictionaryStorage::getDictionary().
											getNumberOfProfession(title);
	}
	else
		numberOfProfessionInDictionary_ = DictionaryStorage::getDictionary().
										    getNumberOfProfession(title);

	dateOfBirth_ = dateOfBirth;

	if (!isYearValid(yearOfBeginning)) {
		yearOfBeginning_ = 0;

		return;
	}

	yearOfBeginning_ = yearOfBeginning;

	age_ = calculateAge();
}


Employee::Employee(const Employee& employee)
{
	*this = employee;
}


Employee::~Employee()
{
	//ToDo: deleteValue in String.cpp
}


Employee 
Employee::operator=(const Employee& emp)
{
	lastNameAndInitials_ = emp.lastNameAndInitials_;
	numberOfProfessionInDictionary_ = emp.numberOfProfessionInDictionary_;
	yearOfBeginning_ = emp.yearOfBeginning_;

	return *this;
}


ostream& operator<<(ostream& out, const Employee& emp)
{

	out << "Worker's name:             " << emp.lastNameAndInitials_ << '\n'
		/*<< "Worker's position:         " << (*emp.dictionaryOfProfessions_).getItemNameOfProfession
											    (emp.numberOfProfessionInDictionary_)
										 << '\n'*/
		<< "Year of beginning working: " << emp.yearOfBeginning_ << '\n';

	return out;
}


istream& operator>>(istream& in, Employee& emp)
{
	emp.enterLastNameAndInitials(in);

	emp.enterTitleOfPosition(in);

	emp.enterYearOfBeginning(in);

	return in;
}


bool
Employee::operator>(const Employee& emp) const 
{
	return (compare(*this, emp) == -1);
}


bool
Employee::operator>=(const Employee& emp) const
{
	int check = compare(*this, emp);
	return (check == -1 || check == 0);
}


bool
Employee::operator<(const Employee& emp) const
{
	return (compare(*this, emp) == 1);
}


bool
Employee::operator<=(const Employee& emp) const
{
	int check = compare(*this, emp);
	return (check == 1 || check == 0);
}


bool
Employee::operator==(const Employee& emp) const
{
	return (compare(*this, emp) == 0);
}


Employee& 
Employee::maxObject(Employee* empArray, int length)
{
	int maxIndex = 0;

	for (int i = 1; i < length; i++)
		if (empArray[i] > empArray[maxIndex])
			maxIndex = i;

	return empArray[maxIndex];
}


//compare in vocabulary order lastNameAndInitials
int 
Employee::compare(const Employee& emp1, const Employee& emp2) const
{
	if (emp2.lastNameAndInitials_ > emp1.lastNameAndInitials_)
		return 1;
	if (emp2.lastNameAndInitials_ < emp1.lastNameAndInitials_)
		return -1;

	return 0;
}


UnsignedShortInt
Employee::calculateAge()
{
	if (dateOfBirth_.getYear() == 0 || dateOfBirth_.getDay() == 0
		|| dateOfBirth_.getMonth() == 0)
		return 0;

	time_t rawTime;
	struct tm timeInfo;
	time(&rawTime);

	localtime_s(&timeInfo, &rawTime);

	if (timeInfo.tm_mon > dateOfBirth_.getMonth() ||
	   (timeInfo.tm_mon == dateOfBirth_.getMonth() && timeInfo.tm_mday >= dateOfBirth_.getDay()))
		return timeInfo.tm_year + 1900 - dateOfBirth_.getYear();


	return timeInfo.tm_year + 1900 - dateOfBirth_.getYear() - 1;
}


void
Employee::enterLastNameAndInitials(istream& in)
{
	cout << "Please, enter first the name and then initials of employee :\n";
	in >> lastNameAndInitials_;

	if (!in) {
		ExceptionWrongInput obj;
		cout << obj.getMessage() << '\n';
	}

	if (!isLastNameAndInitialsValid()) {
		ExceptionInvalidLastNameAndInitials obj;
		cout << obj.getMessage() << '\n';
	}

}


void
Employee::enterTitleOfPosition(istream& in)
{
	//
	char* titleOfPosition = new char[40];

	cout << "Please, title of position of employee     :\n";
	in >> titleOfPosition;

	if (!in) {
		cout << ExceptionWrongInput().getMessage() << '\n';

		return;
	}

	if (!isTitleOfPositionValid(titleOfPosition)) {
		cout << ExceptionInvalidTitleOfPosition().getMessage() << '\n';

		return;
	}

	if (!DictionaryStorage::getDictionary().searchItem(String(titleOfPosition))) {
		 DictionaryStorage::getDictionary().insertItem(String(titleOfPosition));
		 numberOfProfessionInDictionary_ = DictionaryStorage::getDictionary().
											getNumberOfProfession(String(titleOfPosition));
	}
	else
		numberOfProfessionInDictionary_ = DictionaryStorage::getDictionary().
											getNumberOfProfession(String(titleOfPosition));

}


void
Employee::enterYearOfBeginning(istream& in)
{
	cout << "Please, enter year of beginning of employee     :\n";
	in >> yearOfBeginning_;
	
	if (!in) {
		yearOfBeginning_ = 0;

		ExceptionWrongInput obj;
		cout << obj.getMessage() << '\n';
	}
	
	if (!isYearValid()) {
		yearOfBeginning_ = 0;

		ExceptionInvalidYear obj;
		cout << obj.getMessage() << '\n';
	}
}


//Boolean function of validation
bool
Employee::isLastNameAndInitialsValid()
{
	int length = lastNameAndInitials_.getLength();
	if (length < minLengthLastNameAndInitials())
		return false;

	int checkHyphen = 0;
	bool isLastNAmeAndInitialsHyphen;

	if (String::isAlpha(lastNameAndInitials_[0]))
		String::alphaToUpper(lastNameAndInitials_[0]);
	else
		return false;

	for (int i = 1; i < length - 3; i++)
	{
		isLastNAmeAndInitialsHyphen = lastNameAndInitials_[i] == '-';

		if (String::isAlpha(lastNameAndInitials_[i]))
			String::alphaToLower(lastNameAndInitials_[i]);
		else if (isLastNAmeAndInitialsHyphen && checkHyphen < 2)
			checkHyphen++;
		else
			return false;
	}

	if (lastNameAndInitials_[length - 3] == ' ')
		for (int i = length - 2; i<length; i++)
			if (String::isAlpha(lastNameAndInitials_[i]))
				String::alphaToUpper(lastNameAndInitials_[i]);
			else return false;
	else return false;

	return true;
}

bool 
Employee::isLastNameAndInitialsValid(char* lastNameAndInitials)
{
	int length = strlen(lastNameAndInitials);
	if (length < minLengthLastNameAndInitials())
		return false;

	int checkHyphen = 0;
	bool isLastNAmeAndInitialsHyphen;

	if (String::isAlpha(lastNameAndInitials[0]))
		String::alphaToUpper(lastNameAndInitials[0]);
	else
		return false;

	for (int i = 1; i < length - 3; i++)
	{
		isLastNAmeAndInitialsHyphen = lastNameAndInitials[i] == '-';

		if (String::isAlpha(lastNameAndInitials[i]))
			String::alphaToLower(lastNameAndInitials[i]);
		else if (isLastNAmeAndInitialsHyphen && checkHyphen < 2)
			checkHyphen++;
		else
			return false;
	}

	if (lastNameAndInitials[length - 3] == ' ')
		for (int i = length - 2; i<length; i++)
			if (String::isAlpha(lastNameAndInitials[i]))
				String::alphaToUpper(lastNameAndInitials[i]);
			else return false;
	else return false;

	return true;

}

bool
Employee::isTitleOfPositionValid(const char* titleOfPosition)
{
	int length = strlen(titleOfPosition);
	if (length < minLengthTitleOfPosition())
		return false;

	bool isLastCharHyphen = false;

	if (isalpha(titleOfPosition[0]))
		toupper(titleOfPosition[0]);
	else
		return false;

	for (int i = 1; i < length - 1; i++)
	{
		if (isalpha(titleOfPosition[i]))
			tolower(titleOfPosition[i]);
		else if (!isdigit(titleOfPosition[i])) {
			if (titleOfPosition[i] == '-')
				if (isLastCharHyphen)
					return false;
				else
					isLastCharHyphen = true;
			else
				return false;
		}
	}

	return (isdigit(titleOfPosition[length - 1]) || 
		    isalpha(titleOfPosition[length - 1]));
}

bool 
Employee::isYearValid()
{
	return (yearOfBeginning_ <= maxYear() || yearOfBeginning_ >= minYear()
		    && yearOfBeginning_ > dateOfBirth_.getYear());
}

bool 
Employee::isYearValid(unsigned char yearOfBeginning)
{
	return (yearOfBeginning <= maxYear() || yearOfBeginning >= minYear());
}


//Constants
//Returns minimal acceptable value of yearOfBeginning
UnsignedShortInt
Employee::minYear() const
{
	return 1900;
}

//returns system year that is now
UnsignedShortInt
Employee::maxYear() const
{
	time_t rawTime;
	struct tm timeInfo;
	time(&rawTime);

	localtime_s(&timeInfo, &rawTime);

	return timeInfo.tm_year + 1900;
}


UnsignedShortInt
Employee::minLengthTitleOfPosition() const
{
	return 1;
}


UnsignedShortInt
Employee::minLengthLastNameAndInitials() const
{
	return 4;
}
