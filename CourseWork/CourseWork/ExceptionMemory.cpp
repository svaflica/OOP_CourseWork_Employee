#include "stdafx.h"
#include "ExceptionMemory.h"


ExceptionMemory::ExceptionMemory()
{
}


ExceptionMemory::~ExceptionMemory()
{
}


const char*
ExceptionMemory::getMessage()
{
	return "Memory_Exception: memory is full. Please, free some space.";
}