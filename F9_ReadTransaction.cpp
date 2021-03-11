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
* FUNCTION ReadTransaction
* ----------------------------------------------------------------------------
* This function receives a aBank object of type Bank class. This function will
* 		read transactions in the input file and output transactions results
* 		in the console
* 		==> returns nothing
* ----------------------------------------------------------------------------
* PRE-CONDITIONS
* 	None
*
* POST-CONDITIONS
* 	==> Returns nothing
******************************************************************************/
void ReadTransaction(Bank aBank) //IN - bank class object
{
	Date today;						//CALC - initialize date in Date class

	unsigned short month;					//IN - month of transaction
	unsigned short day;						//IN - day of transaction
	unsigned short year;					//IN - year of transaction
	int 		   		 acctNum;				//IN - account number
	int			   		 transfAcctNum;	//IN - transfer account number
	float 		   	 amount;				//IN - amount
	string 		   	 acctType;			//IN - account type

	ifstream fin;		//CALC - input file stream variable

	fin.open("Transaction.txt");

	while(!fin.eof())
	{
		fin >> month;
		fin >> day;
		fin >> year;
		today.SetDate(month, day, year);

		fin >> acctNum;
		fin >> amount;
		fin >> acctType;
		fin.ignore(numeric_limits<streamsize>::max(), '\n');

		if(acctType == "Deposit")
		{
			if(!aBank.Deposit(today, acctNum, amount))
			{
				cout << "\n**** CAN'T DEPOSIT FROM THIS ACCOUNT ****\n\n";
			}
		}
		else if(acctType == "Withdrawal")
		{
			if(!aBank.Withdrawal(today, acctNum, amount))
			{
				cout << "\n**** CAN'T WITHDRAW FROM THIS ACCOUNT ****\n\n";
			}
		}
		else if(acctType == "Transfer")
		{
			fin >> transfAcctNum;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');

			if(!aBank.Transfer(today, acctNum, amount, transfAcctNum))
			{
				if(acctNum != transfAcctNum)
				{
					cout << "\n*** TRANSFER FROM " << transfAcctNum << " TO "
						 	 << acctNum << " NOT ALLOWED! ***\n";
					cout << "***        DUE TO INSUFFICIENT FUNDS        ***\n\n";
				}
				else
				{
					cout << "\n*** ERROR - CAN'T TRANSFER INTO THE "
							"SAME ACCOUNT ***\n\n";
				}
			}
		}

	}//END while(!fin.eof())

	fin.close();
}
