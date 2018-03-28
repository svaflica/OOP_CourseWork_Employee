#include "stdafx.h"
#include "ExceptionYear.h"


ExceptionInvalidYear::ExceptionInvalidYear()
{
}


ExceptionInvalidYear::~ExceptionInvalidYear()
{
}

const char* 
ExceptionInvalidYear::getMessage()
{
	return "Error: Year is invalid";
}