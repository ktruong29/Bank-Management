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
 * Constructor Bank: Class Bank
 * ----------------------------------------------------------------------------
 * This constructor creates a bank object and initializes 2 attributes
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A new bank object is created
 *****************************************************************************/
Bank::Bank()
{
	head = NULL;
	numberOfAccts = 0;
}

/******************************************************************************
 * Destructor Bank: Class Bank
 * ----------------------------------------------------------------------------
 * This destructor deallocates memory by deleting a bank list object
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A bank object is deallocated
 *****************************************************************************/
Bank::~Bank()
{
	AccountList *ptr;	//CALC - deleting nodes

	ptr = head;

	while(ptr != NULL)
	{
		head = ptr->next;
		delete ptr;
		ptr = head;
		numberOfAccts--;
	}
}

/******************************************************************************
 * Method SetAllValues: Class MoneyMarket
 * ----------------------------------------------------------------------------
 * This method receives 1 parameter's value (pointer of type Account)
 * 		to add the new node into the linked list.
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		*newAcct	(Account)	//IN - account object
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Bank::OpenAccount(Account *newAcct)	//IN - account object
{
	AccountList *newAcctNode;	//CALC - adding new node to the list
	AccountList *tail;			//CALC - tracking the tail to add the new node

	newAcctNode = new AccountList;

	if(newAcctNode != NULL)
	{
		newAcctNode->customerAccount = newAcct;
		newAcctNode->next = NULL;

		//Adding to the tail
		if(head != NULL)
		{
			tail = head;

			while(tail->next != NULL)
			{
				tail = tail->next;
			}

			tail->next = newAcctNode;
		}
		else
		{
			head = newAcctNode;
		}
		numberOfAccts++;
	}
	else
	{
		cout << "\nOut of memory\n";
	}
}

/******************************************************************************
 * Method Deposit: Class Bank
 * ----------------------------------------------------------------------------
 * This method receives 3 parameters' values: transDate, acctNum, and
 * 		amount to evaluate whether the deposit can be made or not. This method
 * 		will use the acctNum to find the pointer associated with the node. This
 * 		method will return TRUE if deposit can be performed (when the pointer
 * 		!= NULL) and return FALSE if deposit can'be performed.
 * 	 Returns valid deposit (bool)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		transDate	(Date)	//IN - transaction date
 * 		acctNum		(int)	//IN - account's number
 * 		amount		(float)	//IN - deposit amount
 *
 * POST-CONDITIONS
 * 	 Returns valid deposit (bool)
 *****************************************************************************/
bool Bank::Deposit(Date 	transDate,	//IN - transaction date
								   int	    acctNum,	//IN - account's number
								   float	amount)			//IN - deposit amount
{
	Account		*foundAcct;		//CALC - found account pointer
	bool 		validDeposit;	//CALC - validating deposit

	validDeposit = false;

	foundAcct = FindAccountPtr(acctNum);

	if(foundAcct != NULL)
	{
		foundAcct->Deposit(transDate, amount);
		OutputAcctInfo("Deposit", transDate.DisplayDate(), acctNum,
					   				foundAcct->GetName(), amount, foundAcct->GetBalance());
		validDeposit = true;
	}

	return validDeposit;
}

/******************************************************************************
 * Method Withdrawal: Class Bank
 * ----------------------------------------------------------------------------
 * This method receives 3 parameters' values: transDate, acctNum, and
 * 		amount to evaluate whether withdrawal can be made or not. This method
 * 		will use the acctNum to find the pointer associated with the node. This
 * 		method will return TRUE if deposit can be performed (when the pointer
 * 		!= NULL) and return FALSE if deposit can'be performed.
 * 	 Returns valid withdraw (Bool)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		transDate	(Date)	//IN - transaction date
 * 		acctNum		(int)	//IN - account's number
 * 		amount		(float)	//IN - deposit amount
 *
 * POST-CONDITIONS
 * 	 Returns valid withdraw (Bool)
 *****************************************************************************/
bool Bank::Withdrawal(Date 	transDate,	//IN - transaction date
										  int	acctNum,	//IN - account's number
										  float	amount)		//IN - deposit amount
{
	Account	 	*foundAcct;		//CALC - found account pointer and uses Account
													//	   - class methods
	bool 		validWithdr;		//CALC - validating deposit

	validWithdr = false;
	foundAcct 	= FindAccountPtr(acctNum);

	if(foundAcct != NULL)
	{
		if(foundAcct->Withdrawal(transDate, amount))
		{
			OutputAcctInfo("Withdrawal", foundAcct->GetLastTransDate().DisplayDate(),
											acctNum, foundAcct->GetName(), amount,
											foundAcct->GetBalance());
			validWithdr = true;
		}
	}

	return validWithdr;
}

/******************************************************************************
 * Method Transfer: Class Bank
 * ----------------------------------------------------------------------------
 * This method receives 4 parameters' values: transDate, acctNum,
 * 		amount, and transFromAcctNum to evaluate whether transfer can be made.
 * 		This method will use the acctNum to find the pointer associated with
 * 		the node. Then it will use the method Deposit in Account class. It also
 * 		uses the transFromAcctNum to find the pointer associated with the node.
 * 		This pointer will then use the Account method to check whether this
 * 		account can be withdrawn successfully or not (not allowed to have negative
 * 		balance) This method will return TRUE if deposit can be performed
 * 		and return FALSE if deposit can'be performed.
 * 	 Returns valid transfer (Bool)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		transDate			(Date)	//IN - transaction date
 * 		acctNum				(int)	//IN - account's number
 * 		amount				(float)	//IN - deposit amount
 * 		transFromAcctNum 	(float)	//IN - transfer account number
 *
 * POST-CONDITIONS
 * 	 Returns valid transfer (Bool)
 *****************************************************************************/
bool Bank::Transfer(Date 	transDate,				//IN - transaction date
								    int		acctNum,					//IN - account's number
								    float	amount,						//IN - deposit amount
										int		transFromAcctNum)	//IN - transfer account number
{
	Account 	*depositAcctPtr;	//CALC - deposit account pointer
	Account	  *transAcctPtr;		//CALC - transfer account pointer
	bool 			validTransf;		//CALC - validating transfer

	validTransf = false;

	depositAcctPtr = FindAccountPtr(acctNum);

	transAcctPtr   = FindAccountPtr(transFromAcctNum);

	if(depositAcctPtr != NULL && transAcctPtr != NULL)
	{
		if(depositAcctPtr->TransferFunds(transDate, transAcctPtr, amount))
		{
			OutputTransfAcctInfo("Transfer",
								 depositAcctPtr->GetLastTransDate().DisplayDate(),
								 depositAcctPtr->GetAcctNum(),
								 depositAcctPtr->GetName(), amount,
								 depositAcctPtr->GetBalance(),
								 transAcctPtr->GetAcctNum(), transAcctPtr->GetBalance());
			validTransf = true;
		}

	}
	return validTransf;
}

/******************************************************************************
 * Method OutputList: Class Bank
 * ----------------------------------------------------------------------------
 * This method outputs account's information in MoneyMarket
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		head (AccountList)	//CALC - head of the list
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Bank::OutputList() const
{
	AccountList *ptr;	//CALC - a pointer to tranverse the list

	ptr = head;

	while(ptr != NULL)
	{
		cout << ptr->customerAccount->GetAcctNum() << endl;
		cout << ptr->customerAccount->GetBalance() << endl;
		cout << ptr->customerAccount->GetName()    <<  endl << endl;

		ptr = ptr->next;
	}
}

/******************************************************************************
 * Method OutputList: Class Bank
 * ----------------------------------------------------------------------------
 * This method receives an account number to look for the correct
 * 		account in the list. This will use sequential search to look for the
 * 		correct node that has the correct account number. This method will return
 * 		the pointer associated with the account number.
 * 	 Returns node associated with the account number (Account)
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		acctNum		(int)	//IN - account's number
 *
 * POST-CONDITIONS
 * 	 Returns node associated with the account number (Account)
 *****************************************************************************/
Account *Bank::FindAccountPtr(int acctNum)	//IN - account's number
{
	AccountList *searchPtr;	//CALC - searching the pointer with correct acct's num
	Account			*acctPtr;	//CALC - returning the found account's pointer
	bool				found;		//CALC - used in sequential search

	searchPtr   = head;
	found 		= false;

	while(searchPtr != NULL && !found)
	{
		if(searchPtr->customerAccount->GetAcctNum() == acctNum)
		{
			found = true;
		}
		else
		{
			searchPtr = searchPtr->next;
		}
	}

	if(found)
	{
		acctPtr = searchPtr->customerAccount;
	}
	else
	{
		acctPtr = NULL;
	}

	return acctPtr;
}
