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
 * Constructor Checking: Class Checking
 * ----------------------------------------------------------------------------
 * This constructor creates a checking object and initializes one attribute
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A new checking object is created
 *****************************************************************************/
Checking::Checking()
{
	overdraftPenalty = 0.0;
}

/******************************************************************************
 * Constructor Checking: Class Checking
 * ----------------------------------------------------------------------------
 * This constructor creates a checking object and initializes five attributes
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 The following need to be defined previously
 * 	 	openingDate (Date)		//IN - account's open date
 * 		name		(string)	//IN - client's name
 * 		accountNum	(integer)	//IN - account's number
 * 		balance		(float)		//IN - account's balance
 * 		overdraftFee(float)		//IN - overdraft penalty fee
 *
 * POST-CONDITIONS
 * 	 A new checking object is created
 *****************************************************************************/
Checking::Checking(Date		openingDate,	//IN - account's open date
								   string	name,			//IN - client's name
								   int		accountNum,		//IN - account's number
								   float	balance,		//IN - account's balance
								   float	overdraftFee)	//IN - overdraft penalty fee
{
	Account::SetAllValues(openingDate, name, accountNum, balance);
	overdraftPenalty = overdraftFee;
}

/******************************************************************************
 * Destructor Checking: Class Checking
 * ----------------------------------------------------------------------------
 * This destructor deallocates memory by deleting a checking object
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A checking object is deallocated
 *****************************************************************************/
Checking::~Checking(){}

/******************************************************************************
 * Method SetAllValues: Class Checking
 * ----------------------------------------------------------------------------
 * This method receives 5 parameters' values to initialize the 6 attributes
 * 		of an account object: openDate, lastAccessDate, clientName, acctNumber,
 * 		currentBalance, and overdraftPenalty.
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		openingDate (Date)		//IN - account's open date
 * 		name		(string)	//IN - client's name
 * 		accountNum	(integer)	//IN - account's number
 * 		balance		(float)		//IN - account's balance
 * 		overdraftFee(float)		//IN - overdraft penalty fee
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Checking::SetAllValues(Date 	openingDate,	//IN - account's open date
												    string	name,			//IN - client's name
												    int		accountNum,		//IN - account's number
												    float	balance,		//IN - account's balance
												    float	overdraftFee)	//IN - overdraft penalty fee
{
	Account::SetAllValues(openingDate, name, accountNum, balance);
	overdraftPenalty = overdraftFee;
}

/******************************************************************************
 * Method SetOverdraftFee: Class Checking
 * ----------------------------------------------------------------------------
 * This method receives 1 parameter's value to initialize 1 attribute
 * 		of a checking object: overdraftFee
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		overdraftFee (string)	//IN - overdraft penalty fee
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Checking::SetOverdraftFee(float overdraftFee)	//IN - overdraft penalty fee
{
	overdraftPenalty = overdraftFee;
}

/******************************************************************************
 * Method Withdrawal: Class Checking
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
bool Checking::Withdrawal(Date 	today,	//IN - date of transaction
						  						float	amount)	//IN - amount to deposit
{
	const float MAX_WITHDRAW = -200.00;

	bool validWithdraw;		//CALC - validating withdrawal

	validWithdraw = (currentBalance - amount > 0 ||
					 				 currentBalance - amount > MAX_WITHDRAW);

	if(validWithdraw)
	{
		currentBalance -= amount;
		UpdateAcct(today);
	}

	return validWithdraw;
}

/******************************************************************************
 * Method UpdateAcct: Class Checking
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
void Checking::UpdateAcct(Date today) //IN - date of transaction
{
	unsigned short totalMonths;

	totalMonths = today.GetMonth() - lastAccessDate.GetMonth();

	if(currentBalance < 0)
	{
		currentBalance = currentBalance - (totalMonths * overdraftPenalty);
	}
	lastAccessDate = today;
}

/******************************************************************************
 * Method GetOverdraftFee: Class Checking
 * ----------------------------------------------------------------------------
 * This method retrieves overdraftPenalty in Checking
 * 	 Returns overdraftPenalty (float)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		overdraftPenalty  (float)	//IN - overdraft fee
 *
 * POST-CONDITIONS
 * 	  Returns overdraftPenalty (float)
 *****************************************************************************/
float Checking::GetOverdraftFee() const
{
	return overdraftPenalty;
}
