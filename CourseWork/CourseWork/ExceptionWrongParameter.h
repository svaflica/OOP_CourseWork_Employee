#pragma once
#include "Exception.h"
class ExceptionWrongParameter :
	public Exception
{
public:
	ExceptionWrongParameter();
	~ExceptionWrongParameter();
	const char* getMessage();
};

