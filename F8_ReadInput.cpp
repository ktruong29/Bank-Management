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
* FUNCTION ReadInput
* ----------------------------------------------------------------------------
* This function receives a aBank object of type Bank class. This function will
* 		read input from the input file and store the account's information into
* 		a linked list in Bank class.
* 		==> returns nothing
* ----------------------------------------------------------------------------
* PRE-CONDITIONS
* 	None
*
* POST-CONDITIONS
* 	==> Returns nothing
******************************************************************************/
void ReadInput(Bank &aBank) //IN - bank class object to store accounts in list
{
	Account *checking;	//CALC - dynamically allocates class Checking
	Account *savings;	//CALC - dynamically allocates class Savings
	Account *moneyM;	//CALC - dynamically allocates class MoneyMarket

	Date today;			//CALC - initialize date in Date class

	unsigned short month;	//IN - month of transaction
	unsigned short day;		//IN - day of transaction
	unsigned short year;	//IN - year of transaction
	int 	acctNum;		//IN - account number
	string 	acctType;		//IN - account type
	float 	bal;			//IN - account balance
	string 	name;			//IN - client's name

	ifstream fin;			//CALC - input file stream variable

	fin.open("AcctFile.txt");

	while(!fin.eof())
	{
		fin >> month;
		fin >> day;
		fin >> year;
		today.SetDate(month, day, year);

		fin >> acctNum;
		fin >> acctType;
		fin >> bal;
		getline(fin, name);

		if(acctType == "Checking")
		{
			checking = new Checking(today, name, acctNum, bal, CHKG_OVERDR_FEE);
			aBank.OpenAccount(checking);
			OutputAcctInfo("OPEN CHECKING", today.DisplayDate(), acctNum,
											name, bal, bal);
		}
		else if(acctType == "Savings")
		{
			savings = new Savings(today, name, acctNum, bal, SAVINGS_INTRST);
			aBank.OpenAccount(savings);
			OutputAcctInfo("OPEN SAVINGS", today.DisplayDate(), acctNum,
											name, bal, bal);
		}
		else if(acctType == "MM")
		{
			moneyM = new MoneyMarket(today, name, acctNum, bal, MONEY_M_INTRST,
									 						 MM_WTHDRW_FEE);
			aBank.OpenAccount(moneyM);
			OutputAcctInfo("OPEN Money Market", today.DisplayDate(), acctNum,
							name, bal, bal);
		}

	}
	fin.close();
	cout << endl;
}
