#pragma once
#include "Exception.h"
class ExceptionMemory :
	public Exception
{
public:
	ExceptionMemory();
	~ExceptionMemory();
	const char* getMessage();
};