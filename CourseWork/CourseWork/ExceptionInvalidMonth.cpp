#include "stdafx.h"
#include "ExceptionInvalidMonth.h"


ExceptionInvalidMonth::ExceptionInvalidMonth()
{
}


ExceptionInvalidMonth::~ExceptionInvalidMonth()
{
}


const char*
ExceptionInvalidMonth::getMessage()
{
	return "Error: Month is invalid!";
}