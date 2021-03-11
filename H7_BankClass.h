/******************************************************************************
 * AUTHOR		 : Kevin Truong
 * STUDENT ID	 : 1017195
 * ASSIGNMENT #6 : OOP - Saddleback Bank
 * CLASS		 : CS1B
 * SECTION		 : MW: 6:30pm
 * DUE DATE		 : 5/21/18
 ******************************************************************************/

#ifndef H7_BANKCLASS_H_
#define H7_BANKCLASS_H_

#include <string>

class Bank
{
	public:
		/*****************************
		 * CONSTRUCTORS & DESTRUCTOR *
		 ****************************/
		Bank();
		~Bank();

		/************
		 * MUTATORS *
		 ***********/
		void OpenAccount(Account *newAcct);
		bool Deposit(Date 	transDate,
			     int	acctNum,
			     float	amount);
		bool Withdrawal(Date 	transDate,
				int		acctNum,
				float	amount);
		bool Transfer(Date 	transDate,
			      int	acctNum,
			      float	amount,
			      int	transFromAcctNum);

		/*************
		 * ACCESSORS *
		 ************/
		void OutputList() const;

	protected:
		//Returns a pointer to an account
		Account *FindAccountPtr(int acctNum);

	private:
		struct AccountList
		{
			Account		*customerAccount;	//IN   		 - account's pointer
			AccountList	*next;			//CALC 		 - points to the next node
		};
		AccountList *head;				//CALC 		 - head of the list
		int 		numberOfAccts;			//CALC & OUT - total number of accounts
};

/******************************************************************************
* Bank Class
* 	This class represents a bank object).
* 	It manages three attributes of a bank: AccountList, head, and numberOfAccts.
* ****************************************************************************/

/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
* Class
* 	Constructor; Initialize class attributes
* 	Parameters: none
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* ~Class()
* 	Destructor; dynamically deallocates memory of the linked list
* 	Parameters: none
* 	Return: none
* ****************************************************************************/

/**************
 ** MUTATORS **
 **************/

/******************************************************************************
* void OpenAccount(Account *newAcct);
*
* 	Mutator; This method receives 1 parameter's value (pointer of type Account)
* 		to add the new node into the linked list.
* ----------------------------------------------------------------------------
* 	Parameters: *newAcct	(Account)	//IN - account object
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* bool Deposit(Date 	transDate,
*			   int		acctNum,
*			   float	amount);
*
* 	Mutator; This method receives 3 parameters' values: transDate, acctNum, and
* 		amount to evaluate whether the deposit can be made or not. This method
* 		will use the acctNum to find the pointer associated with the node. This
* 		method will return TRUE if deposit can be performed (when the pointer
* 		!= NULL) and return FALSE if deposit can'be performed.
* ----------------------------------------------------------------------------
* 	Parameters:	transDate	(Date)	//IN - transaction date
* 				acctNum		(int)	//IN - account's number
* 				amount		(float)	//IN - deposit amount
* ----------------------------------------------------------------------------
* 	Return: valid deposit (bool)
* ****************************************************************************/

/******************************************************************************
* bool Withdrawal(Date 	transDate,
*				  int	acctNum,
*			      float	amount);
*
* 	Mutator; This method receives 3 parameters' values: transDate, acctNum, and
* 		amount to evaluate whether withdrawal can be made or not. This method
* 		will use the acctNum to find the pointer associated with the node. This
* 		method will return TRUE if deposit can be performed (when the pointer
* 		!= NULL) and return FALSE if deposit can'be performed.
* ----------------------------------------------------------------------------
* 	Parameters:	transDate	(Date)	//IN - transaction date
* 				acctNum		(int)	//IN - account's number
* 				amount		(float)	//IN - deposit amount
* ----------------------------------------------------------------------------
* 	Return: valid withdraw (Bool)
* ****************************************************************************/

/******************************************************************************
* bool Transfer(Date 	transDate,
*				int		acctNum,
*				float	amount,
*				int		transFromAcctNum);
*
* 	Mutator; This method receives 4 parameters' values: transDate, acctNum,
* 		amount, and transFromAcctNum to evaluate whether transfer can be made.
* 		This method will use the acctNum to find the pointer associated with
* 		the node. Then it will use the method Deposit in Account class. It also
* 		uses the transFromAcctNum to find the pointer associated with the node.
* 		This pointer will then use the Account method to check whether this
* 		account can be withdrawn successfully or not (not allowed to have negative
* 		balance) This method will return TRUE if deposit can be performed
* 		and return FALSE if deposit can'be performed.
* ----------------------------------------------------------------------------
* 	Parameters:	transDate			(Date)	//IN - transaction date
* 				acctNum				(int)	//IN - account's number
* 				amount				(float)	//IN - deposit amount
* 				transFromAcctNum 	(float)	//IN - transfer account number
* ----------------------------------------------------------------------------
* 	Return: valid transfer (Bool)
* ****************************************************************************/

/***************
 ** ACCESSORS **
 **************/

/******************************************************************************
* void OutputList() const;
*
* 	Accessor; This method outputs account's information in MoneyMarket
* ----------------------------------------------------------------------------
* 	Parameter: None
* ----------------------------------------------------------------------------
* 	Return: None
* ****************************************************************************/

/******************************************************************************
* Account *FindAccountPtr(int acctNum);
*
* 	Mutator; This method receives an account number to look for the correct
* 		account in the list. This will use sequential search to look for the
* 		correct node that has the correct account number. This method will return
* 		the pointer associated with the account number.
* ----------------------------------------------------------------------------
* 	Parameters:	acctNum		(int)	//IN - account's number
* ----------------------------------------------------------------------------
* 	Return: node associated with the account number (Account)
* ****************************************************************************/

#endif /* H7_BANKCLASS_H_ */
