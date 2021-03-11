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
 * OOP - Saddleback Bank
 * ----------------------------------------------------------------------------
 * This program will use object oriented programming to represent baking accounts
 * 		and manage banking activities. This will also represent the use of
 * 		inheritance and polymorphism in object oriented programming. This program
 * 		will have a total of 6 different classes: bank class, account class,
 * 		checking and savings are derived from account class, money market class
 * 		derived from the savings class, and a date class to manage the date
 * 		of transactions.
 * 	The Account class is the base class for all accounts, which has the following
 * 		attributes: account owner's name, account number, account opening date
 * 		and account balance; and methods for getting, setting, and display name,
 * 		number, date, and balance; depositing, withdrawing, and transferring funds.
 * 	The Account class has two derived classes, Checking and Savings accounts.
 * 		The Savings account has an attribute interestRate, which is currently 10%.
 * 		The Savings account has a derived class MoneyMarket that also has an
 * 		interestRate attribute, which is currently 20%.
 * 	The main program will use the class defined above and process a number of
 * 		account transactions from an input file. Each transaction will include
 * 		the account number, transaction date and amount. It also will output all
 * 		transactions and account balances in a output file.
 *
 * -----------------------------------------------------------------------------
 * 	INPUT:
 *
 *
 * 	OUTPUT:
 *
 *****************************************************************************/

int main()
{
	Bank collegeBank;	//CALC - bank class object


	//OUTPUT - Class heading to the console
	cout << PrintHeader("Kevin Truong", "OOP - Saddleback Bank", 'A', 6);

	OutputTableFormat();

	ReadInput(collegeBank);

	ReadTransaction(collegeBank);

	return 0;
}
