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
* FUNCTION OutputAcctInfo
* ----------------------------------------------------------------------------
* This function will output the account's information: opening account info,
* 		deposit, and withdrawal info. This will also add the transfer account
* 		number and transfer account balance.
* 		==> returns nothing
* ----------------------------------------------------------------------------
* PRE-CONDITIONS
* 	None
*
* POST-CONDITIONS
* 	==> Returns nothing
******************************************************************************/
void OutputTransfAcctInfo(string transType,		//IN - transaction type
			  string date,			//IN - date of transaction
			  int	 acctNum,		//IN - account number
			  string name,			//IN - client's name
			  float  amount,		//IN - amount of transaction
			  float  balance,		//IN - balance after each transaction
			  int    transfAcctNum,		//IN - transfer account number
			  float  transfAcctBal)		//IN - transfer account balance
{
	cout << left  << setw(TRANS_COL)	<< transType
		      << setw(DATE_COL)   	<< date
		      << setw(ACCT_COL)	  	<< acctNum
		      << setw(NAME_COL)   	<< name	 << '$';

	cout << setprecision(2) << fixed;

	cout << right << setw(AMOUNT_COL - 1) 	<< amount   << "   " << '$'
		      << setw(BAL_COL - 1 )	<< balance  << "     ";
	cout << setprecision(6);
	cout.unsetf(ios::fixed);

	cout	      << setw(FR_ACCT_COL - 5)	<< transfAcctNum
		      << setw(10) << ' ' << '$';

	cout << setprecision(2) << fixed;
	cout	     << setw(FR_ACCT_BAL_COL - 3) 	<< transfAcctBal << endl;
	cout << setprecision(6);
	cout.unsetf(ios::fixed);
}
