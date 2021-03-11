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
 * Constructor Savings: Class Savings
 * ----------------------------------------------------------------------------
 * This constructor creates a savings object and initializes one attribute
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A new savings object is created
 *****************************************************************************/
Savings::Savings()
{
	interestRate = 0.0;
}

/******************************************************************************
 * Constructor Savings: Class Savings
 * ----------------------------------------------------------------------------
 * This constructor creates a savings object and initializes five attributes
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 The following need to be defined previously
 * 	 	openingDate (Date)		//IN - account's open date
 * 		name		(string)	//IN - client's name
 * 		accountNum	(integer)	//IN - account's number
 * 		balance		(float)		//IN - account's balance
 * 		intRate		(float)		//IN - interest rate of savings account
 *
 * POST-CONDITIONS
 * 	 A new savings object is created
 *****************************************************************************/
Savings::Savings(Date	openingDate,	//IN - account's open date
				  	  	 string	name,			//IN - client's name
								 int	accountNum,		//IN - account's number
								 float	balance,		//IN - account's balance
								 float	intRate)		//IN - interest rate of savings account
{
	Account::SetAllValues(openingDate, name, accountNum, balance);
	interestRate	 = intRate;
}

/******************************************************************************
 * Destructor Savings: Class Savings
 * ----------------------------------------------------------------------------
 * This destructor deallocates memory by deleting a savings object
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A savings object is deallocated
 *****************************************************************************/
Savings::~Savings(){}

/******************************************************************************
 * Method SetAllValues: Class Savings
 * ----------------------------------------------------------------------------
 * This method receives 5 parameters' values to initialize the 6 attributes
 * 		of a checking object: openDate, lastAccessDate, clientName, acctNumber,
 * 		currentBalance, lastAccessDate, and interestRate.
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		openingDate (Date)		//IN - account's open date
 * 		name		(string)	//IN - client's name
 * 		accountNum	(integer)	//IN - account's number
 * 		balance		(float)		//IN - account's balance
 * 		intRate		(float)		//IN - interest rate of savings account
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Savings::SetAllValues(Date 	openingDate,	//IN - account's open date
												   string	name,			//IN - client's name
												   int		accountNum,		//IN - account's number
												   float	balance,		//IN - account's balance
												   float	intRate)		//IN - interest rate of savings
{
	Account::SetAllValues(openingDate, name, accountNum, balance);
	interestRate	 = intRate;
}

/******************************************************************************
 * Method SetInterestRate: Class Savings
 * ----------------------------------------------------------------------------
 * This method receives 1 parameter's value to initialize 1 attribute
 * 		of a savings object: interestRate
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		intRate (float)	//IN - interest rate of savings account
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Savings::SetInterestRate(float intRate)	//IN - interest rate of savings
{
	interestRate	 = intRate;
}

/******************************************************************************
 * Method Withdrawal: Class Savings
 * ----------------------------------------------------------------------------
 * This method receives 2 parameters' values: today and amount to
 * 		to validate whether one's account can be withdrawn or not. This method
 * 		will return TRUE if the withdrawal is possible or return FALSE if the
 * 		withdrawal is impossible
 * 	 Returns valid withdraw (Bool)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		today  (Date)	//IN - date of transaction
 * 		amount (float)	//IN - amount to deposit
 *
 * POST-CONDITIONS
 * 	 Returns valid withdraw (Bool)
 *****************************************************************************/
bool Savings::Withdrawal(Date 	today,	//IN - date of transaction
						 						 float	amount)	//IN - amount to deposit
{
	bool validWithdraw;	//CALC - validating withdrawal

	UpdateAcct(today);

	validWithdraw = currentBalance - amount >= 0;

	if(validWithdraw)
	{
		currentBalance -= amount;
	}
	return validWithdraw;
}

/******************************************************************************
 * Method UpdateAcct: Class Savings
 * ----------------------------------------------------------------------------
 * This method receives today as a parameter's value to update account
 * 		information. This method updates interest and overdraft charges based on
 * 		the difference in months between the lastAccessDate and today.
 * 	This should be called with each transaction
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		today  (Date)	//IN - date of transaction
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Savings::UpdateAcct(Date today)	//IN - date of transaction
{
	unsigned short totalMonths;	//CALC - total months to calc interest
	//Calculating interest
	totalMonths = today.GetMonth() - lastAccessDate.GetMonth();

	currentBalance = ((currentBalance * interestRate) * totalMonths) + currentBalance;

	lastAccessDate = today;
}

/******************************************************************************
 * Method GetInterestRate: Class Savings
 * ----------------------------------------------------------------------------
 * This method retrieves interestRate in Savings
 * 	 Returns interestRate (float)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		interestRate  (float)	//IN - interest rate of savings
 *
 * POST-CONDITIONS
 * 	  Returns interestRate (float)
 *****************************************************************************/
float Savings::GetInterestRate() const
{
	return interestRate;
}
