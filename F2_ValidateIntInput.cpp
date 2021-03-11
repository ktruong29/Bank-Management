/******************************************************************************
 * AUTHOR		 : Kevin Truong
 * STUDENT ID	 : 1017195
 * ASSIGNMENT #6 : OOP - Saddleback Bank
 * CLASS		 : CS1B
 * SECTION		 : MW: 6:30pm
 * DUE DATE		 : 5/21/18
 ******************************************************************************/
#include "H1_MyHeader.h"

/*****************************************************************************
* FUNCTION ValidateIntInput
* ----------------------------------------------------------------------------
* This function will validate the input until the user enter the correct
* integer response (an integer within a specified range)
* 	Returns an integer
* ----------------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be defined previously:
* 	 - prompt				: the input prompt for the user
* 	 - minNum				: the lower limit of the range
* 	 - maxNum				: the upper limit of the range
*
* POST-CONDITIONS
* 	- This function will return an integer
******************************************************************************/
unsigned short ValidateIntInput(string prompt,			//IN- the prompt
				unsigned short minNum,	//IN- the lower range
				unsigned short maxNum)	//IN- the upper range
{
	bool 		invalid;	//PROC- True when user's input is invalid
	unsigned short	num;		//IN & PROC-the integer input from user

	do
	{
		invalid = true;
		cout << left;
		cout << prompt;

		//Validate if the input is an integer
		if(!(cin >> num))
		{
			cout << "\n**** Please input a NUMBER between " << minNum << " and "
			     << maxNum << " ****\n\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		//Validate if the input integer is within range
		else if(num < minNum || num > maxNum)
		{
			cout << "\n**** The number " << num << " is an invalid entry";
			if(num > 9 || num < 0)
			{
				cout << setw(5) << ' ' << "****\n";
			}
			else
			{
				cout << setw(6) << ' ' << "****\n";
			}
			cout << "**** Please input a number between " << minNum << " and "
				 << maxNum << " ****\n\n";

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			invalid = false;
		}
	}while(invalid);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << right;

	return num;
}
