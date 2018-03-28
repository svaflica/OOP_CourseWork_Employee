#pragma once
#ifndef STRING
#define STRING

#include <iostream>

using namespace std;

class String
{
private:
	char* value_;
	int length_;

	int cmp(const String& string) const;
	int cmp(const char *string) const;

	int maxLength() const;

public:
	//
	String();
	String(const char* value);
	String(int length, char symbol);
	String(const String& string);

	~String();

	String& operator=(const String& string);

	friend String operator+(const String& string, const String& string2);
	friend String operator*(String& str, int N);

	bool operator==(const String& string) const;
	bool operator==(const char *string) const;
	bool operator!=(const String& string) const;
	bool operator<=(const String& string) const;
	bool operator<=(const char *string) const;
	bool operator>=(const String& string) const;
	bool operator>=(const char *string) const;
	bool operator>(const String& string) const;
	bool operator>(const char *string) const;
	bool operator<(const String& string) const;
	bool operator<(const char *string) const;

	char& operator[](int N);

	void* operator new[](size_t N);

	friend String& invert(String& string);
	friend ostream& operator<<(ostream& out, const String& string);
	friend istream& operator>>(istream& in, String& string);

	int getLength();
	int getIndexOfSymbol(char symbol);
	int getIndexOfWord(String& string);

	String& toLower();
	static char& alphaToLower(char& symbol);
	String& toUpper();
	static char& alphaToUpper(char& symbol);
	static bool isAlpha(const char symbol);
	static bool isLower(const char symbol);
	static bool isUpper(const char symbol);
};

#endif