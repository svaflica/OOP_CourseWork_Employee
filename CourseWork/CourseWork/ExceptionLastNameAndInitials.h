#pragma once
#include "Exception.h"
class ExceptionInvalidLastNameAndInitials :
	public Exception
{
public:
	ExceptionInvalidLastNameAndInitials();
	~ExceptionInvalidLastNameAndInitials();
	const char* getMessage();
};

