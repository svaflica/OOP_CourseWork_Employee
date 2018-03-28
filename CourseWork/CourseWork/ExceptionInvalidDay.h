#pragma once
#include "Exception.h"
class ExceptionInvalidDay :
	public Exception
{
public:
	ExceptionInvalidDay();
	~ExceptionInvalidDay();
	const char* getMessage();
};

