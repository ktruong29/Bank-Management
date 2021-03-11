/******************************************************************************
 * AUTHOR		 : Kevin Truong
 * STUDENT ID	 : 1017195
 * ASSIGNMENT #6 : OOP - Saddleback Bank
 * CLASS		 : CS1B
 * SECTION		 : MW: 6:30pm
 * DUE DATE		 : 5/21/18
 ******************************************************************************/

#ifndef H4_CHECKINGCLASS_H_
#define H4_CHECKINGCLASS_H_

#include "H3_AccountClass.h"

class Checking: public Account
{
	public:
		/*****************************
		 * CONSTRUCTORS & DESTRUCTOR *
		 ****************************/
		Checking();
		Checking(Date	openingDate,
			 string	name,
			 int	accountNum,
			 float	balance,
			 float	overdraftFee);
		virtual ~Checking();

		/************
		 * MUTATORS *
		 ***********/
		void SetAllValues(Date 		openingDate,
				  string	name,
				  int		accountNum,
				  float		balance,
				  float		overdraftFee);
		void SetOverdraftFee(float overdraftFee);
		virtual bool Withdrawal(Date 	today,
					float	amount);
		virtual void UpdateAcct(Date today);

		/*************
		 * ACCESSORS *
		 ************/
		float GetOverdraftFee() const;

	protected:
		float overdraftPenalty;

};

/******************************************************************************
* Checking Class
* 	This class represents a checking object (derived from Account).
* 	It manages one attributes of a checking: overdraftPenalty
* ****************************************************************************/

/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
* Checking
* 	Constructor; Initialize class attributes
* 	Parameters: none
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* Checking(Date		openingDate,
*		   string	name,
*		   int		accountNum,
*		   float	balance,
*		   float	overdraftFee);
* 	Constructor; Initialize class attributes
* 	Parameters: openingDate (Date)		//IN - account's open date
* 				name		(string)	//IN - client's name
* 				accountNum	(integer)	//IN - account's number
* 				balance		(float)		//IN - account's balance
* 				overdraftFee(float)		//IN - overdraft penalty fee
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* ~Checking()
* 	Destructor; does not perform any specific function
* 	Parameters: none
* 	Return: none
* ****************************************************************************/

/**************
 ** MUTATORS **
 **************/

/******************************************************************************
* void SetAllValues(Date 	openingDate,
*		    string	name,
*		    int		accountNum,
*		    float	balance,
*		    float	overdraftFee);
*
* 	Mutator; This method receives 5 parameters' values to initialize the 5 attributes
* 		of a checking object: openDate, lastAccessDate, clientName, acctNumber,
* 		currentBalance, and overdraftPenalty.
* ----------------------------------------------------------------------------
* 	Parameters: openingDate (Date)		//IN - account's open date
* 				name		(string)	//IN - client's name
* 				accountNum	(integer)	//IN - account's number
* 				balance		(float)		//IN - account's balance
* 				overdraftFee(float)		//IN - overdraft penalty fee
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* void SetOverdraftFee(float overdraftFee);
*
* 	Mutator; This method receives 1 parameter's value to initialize 1 attribute
* 		of a checking object: overdraftFee
* ----------------------------------------------------------------------------
* 	Parameters:	overdraftFee (string)	//IN - overdraft penalty fee
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

/***************
 ** ACCESSORS **
 **************/

/******************************************************************************
* float GetOverdraftFee() const;
*
* 	Accessor; This method retrieves overdraftPenalty in Checking
* ----------------------------------------------------------------------------
* 	Parameter: None
* ----------------------------------------------------------------------------
* 	Return: openDate (Date)
* ****************************************************************************/

#endif /* H4_CHECKINGCLASS_H_ */
