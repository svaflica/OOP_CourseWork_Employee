#include "stdafx.h"
#include "ExceptionInvalidDay.h"


ExceptionInvalidDay::ExceptionInvalidDay()
{
}


ExceptionInvalidDay::~ExceptionInvalidDay()
{
}


const char* 
ExceptionInvalidDay::getMessage()
{
	return "Error: Day is invalid!";
}