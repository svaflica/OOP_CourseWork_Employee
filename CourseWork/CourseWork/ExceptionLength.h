#pragma once
#include "Exception.h"
class ExceptionLength :
	public Exception
{
public:
	ExceptionLength();
	ExceptionLength(int check);
	~ExceptionLength();
	const char* getMessage();
};
