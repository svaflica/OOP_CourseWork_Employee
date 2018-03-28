#include "stdafx.h"
#include "ExceptionOutOfRange.h"


ExceptionOutOfRange::ExceptionOutOfRange()
{
}


ExceptionOutOfRange::~ExceptionOutOfRange()
{
}


const char*
ExceptionOutOfRange::getMessage()
{
	return "Out_Of_Range: index should be greater than bottom bound of array and lower than upper bound of array.";
}