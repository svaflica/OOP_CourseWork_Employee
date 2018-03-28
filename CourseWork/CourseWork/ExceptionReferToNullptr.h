#pragma once
#include "Exception.h"
class ExceptionReferToNullptr :
	public Exception
{
public:
	ExceptionReferToNullptr();
	~ExceptionReferToNullptr();
	const char* getMessage();
};