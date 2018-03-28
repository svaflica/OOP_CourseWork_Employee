#include "stdafx.h"
#include "ExceptionTitleOfPosition.h"


ExceptionInvalidTitleOfPosition::ExceptionInvalidTitleOfPosition()
{
}


ExceptionInvalidTitleOfPosition::~ExceptionInvalidTitleOfPosition()
{
}


const char* 
ExceptionInvalidTitleOfPosition::getMessage()
{
	return "Error: Title of position is invalid";
}