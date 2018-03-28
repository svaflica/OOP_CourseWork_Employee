#pragma once
#include "Exception.h"
class ExceptionInvalidYear :
	public Exception
{
public:
	ExceptionInvalidYear();
	~ExceptionInvalidYear();
	const char* getMessage();
};

