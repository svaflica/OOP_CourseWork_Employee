#pragma once
#include "Exception.h"
class ExceptionOutOfRange :
	public Exception
{
public:
	ExceptionOutOfRange();
	~ExceptionOutOfRange();
	const char* getMessage();
};