
#include "stdafx.h"
#include "ExceptionLength.h"


ExceptionLength::ExceptionLength()
{
}


ExceptionLength::~ExceptionLength()
{
}


const char*
ExceptionLength::getMessage()
{
	return "Length_Exception: length should be positive and less than upper bound";
}