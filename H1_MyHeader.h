/******************************************************************************
 * AUTHOR		 : Kevin Truong
 * STUDENT ID	 : 1017195
 * ASSIGNMENT #6 : OOP - Saddleback Bank
 * CLASS		 : CS1B
 * SECTION		 : MW: 6:30pm
 * DUE DATE		 : 5/21/18
 ******************************************************************************/
#ifndef H1_MYHEADER_H_
#define H1_MYHEADER_H_

//Preprocessor directives
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
#include <ios>

#include "H2_DateClass.h"
#include "H3_AccountClass.h"
#include "H4_CheckingClass.h"
#include "H5_SavingsClass.h"
#include "H6_MoneyMarketClass.h"
#include "H7_BankClass.h"

using namespace std;

/******************************************************************************
* GLOBAL CONSTANTS
* ----------------------------------------------------------------------------
* USED FOR OUTPUT FORMATTING
* ----------------------------------------------------------------------------
* TRANS_COL			: transaction type column
* DATE_COL			: date of transaction column
* ACCT_COL			: account number column
* NAME_COL			: name column
* AMOUNT_COL		: amount before transaction column
* BAL_COL			: balance after transaction column
* FR_ACCT_COL		: from account column
* FR_ACCT_BAL_COL	: from account balance column
* ----------------------------------------------------------------------------
* USED FOR PROCESSING
* ----------------------------------------------------------------------------
* SAVINGS_INTRST	: savings interest rate
* MONEY_M_INTRST	: money market interest rate
* MM_WTHDRW_FEE		: money market withdrawal penalty fee
* CHKG_OVERDR_FEE	: checking overdraft fee
******************************************************************************/
const float SAVINGS_INTRST  = 0.1;
const float MONEY_M_INTRST  = 0.2;
const float MM_WTHDRW_FEE	= 1.50;
const float CHKG_OVERDR_FEE = 20.00;

const int TRANS_COL			= 19;
const int DATE_COL   		= 13;
const int ACCT_COL   		= 8;
const int NAME_COL   		= 23;
const int AMOUNT_COL 		= 10;
const int BAL_COL    		= 13;
const int FR_ACCT_COL 		= 10;
const int FR_ACCT_BAL_COL 	= 13;

//Function Prototypes
/******************************************************************************
* F0_PrintHeader
* ----------------------------------------------------------------------------
* This function will receive the programmer's names, the assignment name,
* the assignment type, and the assignment number. It uses ostringstream to store
* output as a string. It will then output the appropriate assignment heading
* when called in main() - returns nothing
* ****************************************************************************/
string PrintHeader(string programmer,   // IN - programmers' names
	           string asName,	// IN - assignment name
		   char   asType, 	// IN - assignment type
		   int    asNum);	// IN - assignment number

/******************************************************************************
 * F2_ValidateIntInput
 * 	This function receives a prompt, a minimum value, and a maximum value to
 * 		validate integer input from the user. This will check for invalid
 * 		characters and invalid range. If the invalid characters are in the
 * 		input buffer, the function will reset the fail state and flush the
 * 		buffer. If the number is within the invalid range, prompt the user to
 * 		input again.
 * 		==> returns the valid integer input from the user of type unsigned short
 *****************************************************************************/
unsigned short ValidateIntInput(string 	       prompt,  // IN - prompt to output
																											//	  - to console
				unsigned short minNum,	// IN - min number to
							//	  - error check input
				unsigned short maxNum);	// IN - max number to
																												//	  - error check input

/******************************************************************************
 * F8_ReadInput
 * 	This function receives a aBank object of type Bank class. This function will
 * 		read input from the input file and store the account's information into
 * 		a linked list in Bank class.
 * 		==> returns nothing
 *****************************************************************************/
void ReadInput(Bank &aBank);	//IN - bank class object to store accounts in list

/******************************************************************************
 * F9_ReadTransaction
 * 	This function receives a aBank object of type Bank class. This function will
 * 		read transactions in the input file and output transactions results
 * 		in the console
 * 		==> returns nothing
 *****************************************************************************/
void ReadTransaction(Bank aBank);	//IN - bank class object

/******************************************************************************
 * F9-1_OutputTableFormat
 * 	This function will output the table format to the console
 * 		==> returns nothing
 *****************************************************************************/
void OutputTableFormat();

/******************************************************************************
 * F9-2_OutputAcctInfo
 * 	This function will output the account's information: opening account info,
 * 		deposit, and withdrawal info.
 * 		==> returns nothing
 *****************************************************************************/
void OutputAcctInfo(string transType,	//IN - transaction type
		    string date,	//IN - date of transaction
		    int	   acctNum,	//IN - account number
		    string name,	//IN - client's name
		    float  amount,	//IN - amount of transaction
		    float  balance);	//IN - balance after each transaction

/******************************************************************************
 * F9-3_OutputTransfAcctInfo
 * 	This function will output the account's information: opening account info,
 * 		deposit, and withdrawal info. This will also add the transfer account
 * 		number and transfer account balance.
 * 		==> returns nothing
 *****************************************************************************/
void OutputTransfAcctInfo(string transType,	//IN - transaction type
			  string date,		//IN - date of transaction
			  int	 acctNum,	//IN - account number
			  string name,		//IN - client's name
			  float  amount,	//IN - amount of transaction
			  float  balance,	//IN - balance after each transaction
			  int    transfAcctNum,	//IN - transfer account number
			  float  transfAcctBal);//IN - transfer account balance

#endif /* H1_MYHEADER_H_ */
