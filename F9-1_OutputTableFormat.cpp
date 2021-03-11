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
* FUNCTION OutputTableFormat
* ----------------------------------------------------------------------------
* This function will output the table format to the console
* 		==> returns nothing
* ----------------------------------------------------------------------------
* PRE-CONDITIONS
* 	None
*
* POST-CONDITIONS
* 	==> Returns nothing
******************************************************************************/
void OutputTableFormat()
{
	cout << left  << setw(TRANS_COL)		<< "TRANSACTION"
							  << setw(DATE_COL)   	<< "DATE"
							  << setw(ACCT_COL)	  	<< "ACCT #"
							  << setw(NAME_COL)   	<< "ACCT NAME"
		 	<< right  << setw(AMOUNT_COL) 	<< "AMOUNT" 	<< "   "
					 	 	  << setw(BAL_COL)	  			<< "BALANCE"	<< "     "
						    << setw(FR_ACCT_COL)			<< "FROM ACCT#"	<< "     "
							  << setw(FR_ACCT_BAL_COL) 	<< "FROM ACCT BAL" << endl;

	cout << left  << setfill('-') << setw(TRANS_COL - 7) 	<< '-' << "       "
											 	 	 	 	  << setw(DATE_COL - 3)  	<< '-' << "   "
															  << setw(ACCT_COL - 3)	 	<< '-' << "   "
															  << setw(NAME_COL - 3)  	<< '-' << "   "
		 << right 				  				<< setw(AMOUNT_COL)	 	<<'-' << "   "
									 	 	 	 	 	 	  << setw(BAL_COL)		 	<< '-' << "     "
															  << setw(FR_ACCT_COL)	  	<< '-'	<< "     "
															  << setw(FR_ACCT_BAL_COL)	<< '-' << endl;
	cout << setfill(' ');

}
