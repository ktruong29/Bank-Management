/******************************************************************************
 * AUTHOR		 : Kevin Truong
 * STUDENT ID	 : 1017195
 * ASSIGNMENT #6 : OOP - Saddleback Bank
 * CLASS		 : CS1B
 * SECTION		 : MW: 6:30pm
 * DUE DATE		 : 5/21/18
 ******************************************************************************/

#ifndef H5_SAVINGSCLASS_H_
#define H5_SAVINGSCLASS_H_

#include "H3_AccountClass.h"

class Savings: public Account
{
	public:
		/*****************************
		 * CONSTRUCTORS & DESTRUCTOR *
		 ****************************/
		Savings();
		Savings(Date	openingDate,
			string	name,
			int	accountNum,
			float	balance,
			float	intRate);
		virtual ~Savings();

		/************
		 * MUTATORS *
		 ***********/
		void SetAllValues(Date 		openingDate,
				  string	name,
				  int		accountNum,
				  float		balance,
				  float		intRate);
		void SetInterestRate(float intRate);
		virtual bool Withdrawal(Date 	today,
					float	amount);
		virtual void UpdateAcct(Date today);

		/*************
		 * ACCESSORS *
		 ************/
		float GetInterestRate() const;

	protected:
		float interestRate;
};

/******************************************************************************
* Savings Class
* 	This class represents a savings object (derived from Account).
* 	It manages one attributes of a checking: interestRate
* ****************************************************************************/

/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
* Savings
* 	Constructor; Initialize class attributes
* 	Parameters: none
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* Savings(Date		openingDate,
*		  string	name,
*		  int		accountNum,
*		  float		balance,
*		  float		intRate);
* 	Constructor; Initialize class attributes
* 	Parameters: openingDate (Date)		//IN - account's open date
* 				name		(string)	//IN - client's name
* 				accountNum	(integer)	//IN - account's number
* 				balance		(float)		//IN - account's balance
* 				intRate		(float)		//IN - interest rate of savings account
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* ~Savings()
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
*					float	balance,
*					float	intRate);
*
* 	Mutator; This method receives 5 parameters' values to initialize the 6 attributes
* 		of a checking object: openDate, lastAccessDate, clientName, acctNumber,
* 		currentBalance, lastAccessDate, and interestRate.
* ----------------------------------------------------------------------------
* 	Parameters: openingDate (Date)		//IN - account's open date
* 				name		(string)	//IN - client's name
* 				accountNum	(integer)	//IN - account's number
* 				balance		(float)		//IN - account's balance
* 				intRate		(float)		//IN - interest rate of savings account
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* void SetInterestRate(float intRate);
*
* 	Mutator; This method receives 1 parameter's value to initialize 1 attribute
* 		of a savings object: interestRate
* ----------------------------------------------------------------------------
* 	Parameters:	intRate (float)	//IN - interest rate of savings account
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
* float GetInterestRate() const;
*
* 	Accessor; This method retrieves interestRate in Savings
* ----------------------------------------------------------------------------
* 	Parameter: None
* ----------------------------------------------------------------------------
* 	Return: openDate (Date)
* ****************************************************************************/

#endif /* H5_SAVINGSCLASS_H_ */
