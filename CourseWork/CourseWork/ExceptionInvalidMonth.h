#pragma once
#include "Exception.h"
class ExceptionInvalidMonth :
	public Exception
{
public:
	ExceptionInvalidMonth();
	~ExceptionInvalidMonth();
	const char* getMessage();
};

