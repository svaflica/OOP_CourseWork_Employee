#pragma once
#include "Exception.h"
class ExceptionWrongInput :
	public Exception
{
public:
	ExceptionWrongInput();
	~ExceptionWrongInput();
	const char* getMessage();
};

