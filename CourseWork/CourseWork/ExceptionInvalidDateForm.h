#pragma once
#include "Exception.h"
class ExceptionInvalidDateForm :
	public Exception
{
public:
	ExceptionInvalidDateForm();
	~ExceptionInvalidDateForm();
	const char* getMessage();

};

