#pragma once
#ifndef DICTIONARY_STORAGE
#define DICTIONARY_STORAGE

#include "Dictionary.h"

static class DictionaryStorage
{
public:

	static Dictionary& getDictionary();

private:
	static Dictionary* dictionaryOfProfessions_;

	DictionaryStorage();
	~DictionaryStorage();
};

#endif