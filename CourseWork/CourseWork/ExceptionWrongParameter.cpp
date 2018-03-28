#include "stdafx.h"
#include "ExceptionWrongParameter.h"


ExceptionWrongParameter::ExceptionWrongParameter()
{
}


ExceptionWrongParameter::~ExceptionWrongParameter()
{
}

const char* 
ExceptionWrongParameter::getMessage()
{
	return "You gave wrong parameter!";
}