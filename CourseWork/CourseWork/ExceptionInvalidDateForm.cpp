#include "stdafx.h"
#include "ExceptionInvalidDateForm.h"


ExceptionInvalidDateForm::ExceptionInvalidDateForm()
{
}


ExceptionInvalidDateForm::~ExceptionInvalidDateForm()
{
}

const char* 
ExceptionInvalidDateForm::getMessage()
{
	return "Error: Invalid Entry Form Of Date";
}