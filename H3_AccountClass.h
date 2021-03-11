/******************************************************************************
 * AUTHOR		 : Kevin Truong
 * STUDENT ID	 : 1017195
 * ASSIGNMENT #6 : OOP - Saddleback Bank
 * CLASS		 : CS1B
 * SECTION		 : MW: 6:30pm
 * DUE DATE		 : 5/21/18
 ******************************************************************************/

#ifndef H3_ACCOUNTCLASS_H_
#define H3_ACCOUNTCLASS_H_

#include <string>

class Account
{
	public:
		/*****************************
		 * CONSTRUCTORS & DESTRUCTOR *
		 ****************************/
		Account();
		Account(Date 	openingDate,
			string	name,
			int		accountNum,
			float	balance);
		virtual ~Account();

		/************
		 * MUTATORS *
		 ***********/
		void SetAllValues(Date 		openingDate,
				  string	name,
			    	  int		accountNum,
				  float		balance);
		void SetValue(string name);
		void SetValue(int	 accountNum);
		void SetValue(float	 balance);
		void SetValue(Date	 openingDate);

		/**********************************************************************
		 * Deposit
		 * --------------------------------------------------------------------
		 * Adds the amount into the account
		 *********************************************************************/
		virtual void Deposit(Date  today,
				     float amount);

		/**********************************************************************
		 * Withdrawal
		 * --------------------------------------------------------------------
		 * Deducts amount from account unless there are insufficient funds
		 * => Returns FALSE if withdrawal can't be performed
		 *********************************************************************/
		virtual bool Withdrawal(Date  today,
					float amount);

		/**********************************************************************
		 * TransferFunds
		 * --------------------------------------------------------------------
		 * Transfers amount from the transferAcct to this account
		 * (Withdrawal from transferAcct - Deposit to this Acct)
		 * => 	Returns FALSE if the transfer can't be performed either due to
		 * 		invalid account options or insufficient funds in the transferAcct.
		 * 		Returns TRUE if transfer is completed
		 *********************************************************************/
		virtual bool TransferFunds(Date 	  today,
					   Account	*transferAcct,
					   float	  amount);

		/**********************************************************************
		 * UpdateAcct
		 * --------------------------------------------------------------------
		 * Updates interest and overdraft charges based on the difference in
		 * 		months between the lastAccessDate and today
		 * 	This should be called with each transaction
		 *********************************************************************/
		virtual void UpdateAcct(Date today);

		/*************
		 * ACCESSORS *
		 ************/
		Date	GetOpenDate()	   	const;
		string	GetName()		const;
		int	GetAcctNum()	   	const;
		float	GetBalance()	   	const;
		Date	GetLastTransDate()	const;

	protected:
		string	clientName;
		int	acctNumber;
		float	currentBalance;
		Date	openDate;
		Date	lastAccessDate;
};
#endif /* H3_ACCOUNTCLASS_H_ */

/******************************************************************************
* Account Class
* 	This class represents an account object. It manages five attributes of an
* 		account: clientName, acctNumber, currentBalance, openDate, and
* 		lastAccesssDate.
* ****************************************************************************/

/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
* Account()
* 	Constructor; Initialize class attributes
* 	Parameters: none
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* Account(Date 		openingDate,
*		  string	name,
*		  int		accountNum,
*		  float		balance);
* 	Constructor; Initialize class attributes
* 	Parameters: openingDate (Date)		//IN - account's open date
* 				name		(string)	//IN - client's name
* 				accountNum	(integer)	//IN - account's number
* 				balance		(float)		//IN - account's balance
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* ~Account()
* 	Destructor; does not perform any specific function
* 	Parameters: none
* 	Return: none
* ****************************************************************************/

/**************
 ** MUTATORS **
 **************/

/******************************************************************************
* void SetAllValues(Date 	openingDate,
*					string	name,
*					int		accountNum,
*					float	balance);
*
* 	Mutator; This method receives 4 parameters' values to initialize the 5 attributes
* 		of an account object: openDate, lastAccessDate, clientName, acctNumber,
* 		and currentBalance.
* ----------------------------------------------------------------------------
* 	Parameters: openingDate (Date)		//IN - account's open date
* 				name		(string)	//IN - client's name
* 				accountNum	(integer)	//IN - account's number
* 				balance		(float)		//IN - account's balance
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* void SetValue(string name);
*
* 	Mutator; This method receives 1 parameter's value to initialize 1 attribute
* 		of an account object: clientName
* ----------------------------------------------------------------------------
* 	Parameters:	name (string)	//IN - client's name
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* void SetValue(int accountNum);
*
* 	Mutator; This method receives 1 parameter's value to initialize 1 attribute
* 		of an account object: acctNumber
* ----------------------------------------------------------------------------
* 	Parameters:	accountNum	(integer)	//IN - account's number
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* void SetValue(float balance);
*
* 	Mutator; This method receives 1 parameter's value to initialize 1 attribute
* 		of an account object: currentBalance
* ----------------------------------------------------------------------------
* 	Parameters:	balance	(float)		//IN - account's balance
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* void SetValue(Date openingDate);
*
* 	Mutator; This method receives 1 parameter's value to initialize 1 attribute
* 		of an account object: openDate
* ----------------------------------------------------------------------------
* 	Parameters:	openingDate (Date)	//IN - account's open date
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* virtual void Deposit(Date  today,
*		   			   float amount);
*
* 	Mutator; This method receives 2 parameters' values: today and amount to
* 		calculate the amount of deposit. After calculating the amount of deposit,
* 		the method will update the currentBalance of the account.
* ----------------------------------------------------------------------------
* 	Parameters:	today  (Date)	//IN - date of transaction
* 				amount (float)	//IN - amount to deposit
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* virtual bool Withdrawal(Date  today,
*						  float amount);
*
* 	Mutator; This method receives 2 parameters' values: today and amount to
* 		to validate whether one's account can be withdrawn or not. This method
* 		will return TRUE if the withdrawal is possible or return FALSE if the
* 		withdrawal is impossible
* ----------------------------------------------------------------------------
* 	Parameters:	today  (Date)	//IN - date of transaction
* 				amount (float)	//IN - amount to withdraw
* ----------------------------------------------------------------------------
* 	Return: valid withdraw (Bool)
* ****************************************************************************/

/******************************************************************************
* virtual bool TransferFunds(Date 		today,
*							 Account	*transferAcct,
*							 float		amount);
*
* 	Mutator; This method receives 3 parameters' values: today, transferAcct and
* 		amount to validate transfer activity. This method will use transferAcct's
* 		methods to check whether that account has sufficient funds to withdraw
* 		or not (can't withdraw if the account has negative balance). Transfer
* 		will also can't be made when the account numbers are identical. This
* 		method will return TRUE if the transfer can be made and update the
* 		currentBalance or return FALSE if the transfer can't be made.
* ----------------------------------------------------------------------------
* 	Parameters:	today  (Date)			//IN - date of transaction
* 				*transferAcct (Account)	//IN - transfer account's pointer
* 				amount (float)			//IN - amount to withdraw
* ----------------------------------------------------------------------------
* 	Return: valid transfer (Bool)
* ****************************************************************************/

/******************************************************************************
* virtual void UpdateAcct(Date today);
*
* 	Mutator; This method receives today as a parameter's value to update account
* 		information. This method updates interest and overdraft charges based on
* 		the difference in months between the lastAccessDate and today.
* 	This should be called with each transaction
* ----------------------------------------------------------------------------
* 	Parameters:	today  (Date)	//IN - date of transaction
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/**************
 ** ACCESSORS **
 **************/

/******************************************************************************
* Date	GetOpenDate()	   const;
*
* 	Accessor; This method retrieves openDate in Account
* ----------------------------------------------------------------------------
* 	Parameter: None
* ----------------------------------------------------------------------------
* 	Return: openDate (Date)
* ****************************************************************************/

/******************************************************************************
* string   GetName()		   const;
*
* 	Accessor; This method retrieves clientName in Account
* ----------------------------------------------------------------------------
* 	Parameter: none
* ----------------------------------------------------------------------------
* 	Return: clientName (string)
* ****************************************************************************/

/******************************************************************************
* int	GetAcctNum()	   const;
*
* 	Accessor; This method retrieves acctNumber in Account
* ----------------------------------------------------------------------------
* 	Parameter: none
* ----------------------------------------------------------------------------
* 	Return: acctNum (integer)
* ****************************************************************************/


/******************************************************************************
* float	GetBalance()	   const;
*
* 	Accessor; This method retrieves currentBalance in Account
* ----------------------------------------------------------------------------
* 	Parameter: none
* ----------------------------------------------------------------------------
* 	Return: currentBalance (float)
* ****************************************************************************/

/******************************************************************************
* Date	GetLastTransDate() const;
*
* 	Accessor; This method retrieves lastAccessDate in Account
* ----------------------------------------------------------------------------
* 	Parameter: none
* ----------------------------------------------------------------------------
* 	Return: lastAccessDate (Date)
* ****************************************************************************/
