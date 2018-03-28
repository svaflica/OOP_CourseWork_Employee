#include "stdafx.h"
#include "ExceptionLastNameAndInitials.h"


ExceptionInvalidLastNameAndInitials::ExceptionInvalidLastNameAndInitials()
{
}


ExceptionInvalidLastNameAndInitials::~ExceptionInvalidLastNameAndInitials()
{
}

const char* 
ExceptionInvalidLastNameAndInitials::getMessage()
{
	return "Error: LastNameAndInitials is invalid";
}