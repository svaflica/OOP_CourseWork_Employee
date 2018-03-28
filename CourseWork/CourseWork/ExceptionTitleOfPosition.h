#pragma once
#include "Exception.h"
class ExceptionInvalidTitleOfPosition :
	public Exception
{
public:
	ExceptionInvalidTitleOfPosition();
	~ExceptionInvalidTitleOfPosition();
	const char* getMessage();
};

