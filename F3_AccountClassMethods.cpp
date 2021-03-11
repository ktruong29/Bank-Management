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
 * Constructor Account: Class Account
 * ----------------------------------------------------------------------------
 * This constructor creates an account object and initializes three attributes
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A new account object is created
 *****************************************************************************/
Account::Account()
{
	clientName.clear();
	acctNumber = 0;
	currentBalance = 0.0;
}

/******************************************************************************
 * Constructor Account: Class Account
 * ----------------------------------------------------------------------------
 * This constructor creates an account object and initializes five attributes
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A new account object is created
 *****************************************************************************/
Account::Account(Date 	openingDate,	//IN - account's open date
								 string	name,			//IN - client's name
								 int	accountNum,		//IN - account's number
								 float	balance)		//IN - account's balance
{
	openDate  	   = openingDate;
	lastAccessDate = openingDate;
	clientName 	   = name;
	acctNumber 	   = accountNum;
	currentBalance = balance;
}

/******************************************************************************
 * Destructor Account: Class Account
 * ----------------------------------------------------------------------------
 * This destructor deallocates memory by deleting an account object
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 An account object is deallocated
 *****************************************************************************/
Account::~Account(){}

/************
 * MUTATORS *
 ***********/
/******************************************************************************
 * Method SetAllValues: Class Account
 * ----------------------------------------------------------------------------
 * This method receives 4 parameters' values to initialize the 5 attributes
 * 		of an account object: openDate, lastAccessDate, clientName, acctNumber,
 * 		and currentBalance.
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		openingDate (Date)		//IN - account's open date
 * 		name		(string)	//IN - client's name
 * 		accountNum	(integer)	//IN - account's number
 * 		balance		(float)		//IN - account's balance
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Account::SetAllValues(Date 	openingDate,	//IN - account's open date
												   string	name,			//IN - client's name
												   int		accountNum,		//IN - account's number
												   float	balance)		//IN - account's balance
{
	openDate  	   = openingDate;
	lastAccessDate = openingDate;
	clientName 	   = name;
	acctNumber 	   = accountNum;
	currentBalance = balance;
}

/******************************************************************************
 * Method SetValue: Class Account
 * ----------------------------------------------------------------------------
 * This method receives 1 parameter's value to initialize 1 attribute
 * 		of an account object: clientName
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		name (string)	//IN - client's name
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Account::SetValue(string name)	//IN - client's name
{
	clientName = name;
}

/******************************************************************************
 * Method SetValue: Class Account
 * ----------------------------------------------------------------------------
 * This method receives 1 parameter's value to initialize 1 attribute
 * 		of an account object: acctNumber
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		accountNum	(integer)	//IN - account's number
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Account::SetValue(int accountNum)	//IN - account's number
{
	acctNumber = accountNum;
}

/******************************************************************************
 * Method SetValue: Class Account
 * ----------------------------------------------------------------------------
 * This method receives 1 parameter's value to initialize 1 attribute
 * 		of an account object: currentBalance
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		balance	(float)		//IN - account's balance
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Account::SetValue(float balance)	//IN - account's balance
{
	currentBalance = balance;
}

/******************************************************************************
 * Method SetValue: Class Account
 * ----------------------------------------------------------------------------
 * This method receives 1 parameter's value to initialize 1 attribute
 * 		of an account object: openDate
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		openingDate (Date)	//IN - account's open date
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Account::SetValue(Date openingDate)	//IN - account's open date
{
	openDate = openingDate;
}

/******************************************************************************
 * Method Deposit: Class Account
 * ----------------------------------------------------------------------------
 * This method receives 2 parameters' values: today and amount to
 * 		calculate the amount of deposit. After calculating the amount of deposit,
 * 		the method will update the currentBalance of the account.
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		today  (Date)	//IN - date of transaction
 * 		amount (float)	//IN - amount to deposit
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Account::Deposit(Date  today,	//IN - date of transaction
					  					float amount)	//IN - amount to deposit
{
	UpdateAcct(today);
	currentBalance += amount;
}

/******************************************************************************
 * Method Withdrawal: Class Account
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
bool Account::Withdrawal(Date  today,	//IN - date of transaction
						 						 float amount)	//IN - amount to deposit
{
	bool validWD;	//CALC - validating withdrawal

	validWD = false;

	UpdateAcct(today);
	if(amount <= currentBalance)
	{
		validWD = true;
		currentBalance -= amount;
	}

	return validWD;
}

/******************************************************************************
 * Method TransferFunds: Class Account
 * ----------------------------------------------------------------------------
 * This method receives 3 parameters' values: today, transferAcct and
 * 		amount to validate transfer activity. This method will use transferAcct's
 * 		methods to check whether that account has sufficient funds to withdraw
 * 		or not (can't withdraw if the account has negative balance). Transfer
 * 		will also can't be made when the account numbers are identical. This
 * 		method will return TRUE if the transfer can be made and update the
 * 		currentBalance or return FALSE if the transfer can't be made.
 * 	 Returns valid transfer (Bool)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		today  (Date)			//IN - date of transaction
 * 		*transferAcct (Account)	//IN - transfer account's pointer
 * 		amount (float)			//IN - amount to withdraw
 *
 * POST-CONDITIONS
 * 	 Returns valid transfer (Bool)
 *****************************************************************************/
bool Account::TransferFunds(Date 	today,						//IN - date of transaction
														Account	*transferAcct,	//IN - transfer account's pointer
														float	amount)						//IN - amount to withdraw
{
	bool validTransf;	//CALC - validating transfer

	transferAcct->UpdateAcct(today);
	validTransf = (transferAcct->acctNumber != acctNumber &&
				   			 transferAcct->GetBalance() > amount);

	if(validTransf && transferAcct->Withdrawal(today, amount))
	{
		currentBalance += amount;
	}

	return validTransf;
}

/******************************************************************************
 * Method UpdateAcct: Class Account
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
void Account::UpdateAcct(Date today)	//IN - date of transaction
{
	lastAccessDate = today;
}

/*************
 * ACCESSORS *
 ************/
/******************************************************************************
 * Method GetOpenDate: Class Account
 * ----------------------------------------------------------------------------
 * This method retrieves openDate in Account
 * 	 Returns openDate (Date)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	None
 *
 * POST-CONDITIONS
 * 	 Returns openDate (Date)
 *****************************************************************************/
Date Account::GetOpenDate()const
{
	return openDate;
}

/******************************************************************************
 * Method GetName: Class Account
 * ----------------------------------------------------------------------------
 * This method retrieves clientName in Account
 * 	 Returns clientName (string)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	None
 *
 * POST-CONDITIONS
 * 	 Returns clientName (string)
 *****************************************************************************/
string Account::GetName() const
{
	return clientName;
}

/******************************************************************************
 * Method GetAcctNum: Class Account
 * ----------------------------------------------------------------------------
 * This method retrieves acctNumber in Account
 * 	 Returns acctNum (integer)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	None
 *
 * POST-CONDITIONS
 * 	 Returns acctNum (integer)
 *****************************************************************************/
int Account::GetAcctNum() const
{
	return acctNumber;
}

/******************************************************************************
 * Method GetBalance: Class Account
 * ----------------------------------------------------------------------------
 * This method retrieves currentBalance in Account
 * 	 Returns currentBalance (float)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	None
 *
 * POST-CONDITIONS
 * 	 Returns currentBalance (float)
 *****************************************************************************/
float Account::GetBalance() const
{
	return currentBalance;
}

/******************************************************************************
 * Method etLastTransDate: Class Account
 * ----------------------------------------------------------------------------
 * This method retrieves lastAccessDate in Account
 * 	 Returns lastAccessDate (Date)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	None
 *
 * POST-CONDITIONS
 * 	 Returns lastAccessDate (Date)
 *****************************************************************************/
Date Account::GetLastTransDate() const
{
	return lastAccessDate;
}
