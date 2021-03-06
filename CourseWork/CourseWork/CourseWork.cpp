// CourseWork.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Employee.h"
#include "ExceptionYear.h"
#include "ExceptionWrongParameter.h"
#include "Exception.h"
#include "String.h"
#include "ExceptionMemory.h"
#include "ExceptionLength.h"
#include "ExceptionOutOfRange.h"
#include "ExceptionReferToNullptr.h"


int main()
{

	try {

		//Correct
		/*{
			Date date("01.12.2000");
			Date date1;
			cin >> date1;
			cout << date1 << '\n';
			cout << date;
		}*/

		{
			Dictionary storage;

			storage.insertItem(String("Aline"));
			storage.insertItem(String("Bobby"));
			storage.insertItem(String("Lolly"));
			storage.insertItem(String("Centy"));
			storage.insertItem(String("Abobo"));
			storage.insertItem(String("Akoko"));

			storage.outAll();
		}

		return 0;
	}
	catch (ExceptionMemory& obj)
	{
		cout << obj.getMessage();
		return -1;
	}
	catch (ExceptionLength& obj)
	{
		cout << obj.getMessage();
		return -1;

	}
	catch (ExceptionOutOfRange& obj)
	{
		cout << obj.getMessage();
		return -1;

	}
	catch (ExceptionReferToNullptr& obj)
	{
		cout << obj.getMessage();
		return -1;

	}
	catch (ExceptionInvalidYear& obj)
	{
		cout << obj.getMessage();
		return -1;

	}
	catch (ExceptionWrongParameter& obj)
	{
		cout << obj.getMessage();
		return -1;
	}

}

