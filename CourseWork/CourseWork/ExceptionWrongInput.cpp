#include "stdafx.h"
#include "ExceptionWrongInput.h"


ExceptionWrongInput::ExceptionWrongInput()
{
}


ExceptionWrongInput::~ExceptionWrongInput()
{
}

const char* 
ExceptionWrongInput::getMessage()
{
	return "Error: Invalid Input!";
}