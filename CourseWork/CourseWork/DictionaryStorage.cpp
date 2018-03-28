#include "stdafx.h"
#include "DictionaryStorage.h"


DictionaryStorage::DictionaryStorage()
{
}


DictionaryStorage::~DictionaryStorage()
{
}


//Dictionary* 
//DictionaryStorage::getDictionary()
//{
//	return dictionaryOfProfessions_;
//}

Dictionary& 
DictionaryStorage::getDictionary()
{
	if (dictionaryOfProfessions_ == nullptr)
		dictionaryOfProfessions_ = new Dictionary();
	return *dictionaryOfProfessions_;
}