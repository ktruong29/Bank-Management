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
 * Constructor MoneyMarket: Class MoneyMarket
 * ----------------------------------------------------------------------------
 * This constructor creates a money market object and initializes one attribute
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A new money market object is created
 *****************************************************************************/
MoneyMarket::MoneyMarket()
{
	withdrawalPenalty = 0.0;
}

/******************************************************************************
 * Constructor MoneyMarket: Class MoneyMarket
 * ----------------------------------------------------------------------------
 * This constructor creates a money market object and initializes 7 attributes
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 The following need to be defined previously
 * 	 	openingDate  (Date)		//IN - account's open date
 * 		name		 (string)	//IN - client's name
 * 		accountNum	 (integer)	//IN - account's number
 * 		balance		 (float)	//IN - account's balance
 * 		intRate		 (float)	//IN - interest rate of MM account
 * 		withdrPenalty(float)	//IN - withdraw penalty fee
 *
 * POST-CONDITIONS
 * 	 A new money market object is created
 *****************************************************************************/
MoneyMarket::MoneyMarket(Date	openingDate,	//IN - account's open date
												 string	name,			//IN - client's name
												 int	accountNum,		//IN - account's number
												 float	balance,		//IN - account's balance
												 float	intRate,		//IN - interest rate of MM account
												 float	withdrPenalty)	//IN - withdraw penalty fee
{
	Savings::SetAllValues(openingDate, name, accountNum, balance, intRate);
	withdrawalPenalty = withdrPenalty;
}

/******************************************************************************
 * Destructor MoneyMarket: Class MoneyMarket
 * ----------------------------------------------------------------------------
 * This destructor deallocates memory by deleting a money market object
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A money market object is deallocated
 *****************************************************************************/
MoneyMarket::~MoneyMarket(){}

/******************************************************************************
 * Method SetAllValues: Class MoneyMarket
 * ----------------------------------------------------------------------------
 * This method receives 6 parameters' values to initialize the 7 attributes
 * 		of a checking object: openDate, lastAccessDate, clientName, acctNumber,
 * 		currentBalance, interestRate, and withdrawalPenalty.
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		openingDate  (Date)		//IN - account's open date
 * 		name		 (string)	//IN - client's name
 * 		accountNum	 (integer)	//IN - account's number
 * 		balance		 (float)	//IN - account's balance
 * 		intRate		 (float)	//IN - interest rate of MM account
 * 		withdrPenalty(float)	//IN - withdraw penalty fee
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void MoneyMarket::SetAllValues(Date		openingDate,	//IN - account's open date
									 	 	 	 	 	   string	name,			//IN - client's name
														   int		accountNum,		//IN - account's number
														   float	balance,		//IN - account's balance
														   float	intRate,		//IN - interest rate of MM
														   float	withdrPenalty)	//IN - withdraw penalty fee
{
	Savings::SetAllValues(openingDate, name, accountNum, balance, intRate);
	withdrawalPenalty = withdrPenalty;
}

/******************************************************************************
 * Method SetWithdrawalPenalty: Class moneyMarket
 * ----------------------------------------------------------------------------
 * This method receives 1 parameter's value to initialize 1 attribute
 * 		of a savings object: withdrawalPenalty
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		withdrPenalty (float)	//IN - withdraw penalty fee
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void MoneyMarket::SetWithdrawalPenalty(float withdrPenalty) //IN - withdraw penalty fee
{
	withdrawalPenalty = withdrPenalty;
}

/******************************************************************************
 * Method Withdrawal: Class MoneyMarket
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
bool MoneyMarket::Withdrawal(Date 	today,	//IN - date of transaction
							 							 float	amount)	//IN - amount to deposit
{
	bool validWithdraw;	//CALC - validating withdrawal

	UpdateAcct(today);

	validWithdraw = currentBalance - amount - withdrawalPenalty >= 0;

	if(validWithdraw)
	{
		currentBalance = currentBalance - amount - withdrawalPenalty;
	}

	return validWithdraw;
}

/******************************************************************************
 * Method GetWithdrawalPenalty: Class MoneyMarket
 * ----------------------------------------------------------------------------
 * This method retrieves withdrawalPenalty in Savings
 * 	 Returns withdrawalPenalty (float)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		withdrawalPenalty  (float)	//IN - withdrawal penalty
 *
 * POST-CONDITIONS
 * 	  Returns withdrawalPenalty (float)
 *****************************************************************************/
float MoneyMarket::GetWithdrawalPenalty() const
{
	return withdrawalPenalty;
}
