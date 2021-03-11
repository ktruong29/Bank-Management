/******************************************************************************
 * AUTHOR		 : Kevin Truong
 * STUDENT ID	 : 1017195
 * ASSIGNMENT #6 : OOP - Saddleback Bank
 * CLASS		 : CS1B
 * SECTION		 : MW: 6:30pm
 * DUE DATE		 : 5/21/18
 ******************************************************************************/

#include "H1_MyHeader.h"

/******************************************************************************
* This function will receive the programmer's names, the assignment name,
* the assignment type, and the assignment number. It uses ostringstream to store
* output as a string. It will then output the appropriate assignment heading
* when called in main() - returns nothing
* -----------------------------------------------------------------------------
* PRE-CONDITIONS
* 	- programmer: Programmer's name must be previously defined.
* 	- asName	: Name of assignment must be previously defined.
* 	- asType	: Assignment type must be previously defined.
* 	- asNumb	: Assignment number must be previously defined.
*
* POST-CONDITIONS
* 	- This function will output the assignment heading.
* ****************************************************************************/
string PrintHeader(string programmer,   // IN - programmers' names
									 string asName,	    // IN - assignment name
									 char   asType, 	    // IN - assignment type
									 int    asNum)		// IN - assignment number

{
	ostringstream str;			//OUT: to store output as a string

	const char CLASS [5] 		= "CS1B";
	const char SECTION [25] 	= "M/W: 6:30-9:50PM";

	str << left;
	str << "**********************************************************";
	str << "\n*   PROGRAMMED BY : " << programmer;
	str << "\n*   " << setw(14) << "CLASS" << ": "   << CLASS;
	str << "\n*   " << setw(14) << "SECTION" << ": " << SECTION;

	if (toupper(asType) == 'L')
	{
		str << "\n*   LAB #" << setw(9);
	}
	else
	{
		str << "\n*   ASSIGNMENT #" << setw(2);
	}
	str << asNum << ": " << asName;
	str << "\n**********************************************************\n\n";
	str << right;

	return str.str();
}
