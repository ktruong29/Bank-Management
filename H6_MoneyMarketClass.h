/******************************************************************************
 * AUTHOR		 : Kevin Truong
 * STUDENT ID	 : 1017195
 * ASSIGNMENT #6 : OOP - Saddleback Bank
 * CLASS		 : CS1B
 * SECTION		 : MW: 6:30pm
 * DUE DATE		 : 5/21/18
 ******************************************************************************/

#ifndef H6_MONEYMARKETCLASS_H_
#define H6_MONEYMARKETCLASS_H_

#include "H5_SavingsClass.h"

class MoneyMarket: public Savings
{
	public:
		/*****************************
		 * CONSTRUCTORS & DESTRUCTOR *
		 ****************************/
		MoneyMarket();
		MoneyMarket(Date	openingDate,
			    string	name,
			    int		accountNum,
			    float	balance,
			    float	intRate,
			    float	withdrPenalty);
		virtual ~MoneyMarket();

		/************
		 * MUTATORS *
		 ***********/
		void SetAllValues(Date		openingDate,
				  string	name,
				  int		accountNum,
				  float		balance,
				  float		intRate,
				  float		withdrPenalty);
		void SetWithdrawalPenalty(float withdrPenalty);
		virtual bool Withdrawal(Date 	today,
					float	amount);

		/*************
		 * ACCESSORS *
		 ************/
		float GetWithdrawalPenalty() const;

	protected:
		float withdrawalPenalty;
};

/******************************************************************************
* MoneyMarket Class
* 	This class represents a money market object (derived from Savings).
* 	It manages one attributes of a money market: withdrawalPenalty
* ****************************************************************************/

/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
* MoneyMarket
* 	Constructor; Initialize class attributes
* 	Parameters: none
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* MoneyMarket(Date		openingDate,
*	      string		name,
*	      int		accountNum,
*	      float		balance,
*	      float		intRate,
*	      float		withdrPenalty);
* 	Constructor; Initialize class attributes
* 	Parameters: openingDate (Date)		//IN - account's open date
* 				name		(string)	//IN - client's name
* 				accountNum	(integer)	//IN - account's number
* 				balance		(float)		//IN - account's balance
* 				withdrPenalty(float)	//IN - withdraw penalty fee
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* ~MoneyMarket()
* 	Destructor; does not perform any specific function
* 	Parameters: none
* 	Return: none
* ****************************************************************************/

/**************
 ** MUTATORS **
 **************/

/******************************************************************************
* void SetAllValues(Date	openingDate,
*		    string	name,
*		    int		accountNum,
*		    float	balance,
*		    float	intRate,
*		    float	withdrPenalty);
*
* 	Mutator; This method receives 6 parameters' values to initialize the 7 attributes
* 		of a checking object: openDate, lastAccessDate, clientName, acctNumber,
* 		currentBalance, interestRate, and withdrawalPenalty.
* ----------------------------------------------------------------------------
* 	Parameters: openingDate  (Date)		//IN - account's open date
* 		    name	(string)	//IN - client's name
* 		    accountNum	 (integer)	//IN - account's number
* 		    balance	(float)		//IN - account's balance
* 		    intRate	(float)		//IN - interest rate of money market
* 		    withdrPenalty(float)	//IN - MM withdrawal penalty
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* void SetWithdrawalPenalty(float withdrPenalty);
*
* 	Mutator; This method receives 1 parameter's value to initialize 1 attribute
* 		of a checking object: withdrawalPenalty
* ----------------------------------------------------------------------------
* 	Parameters:	withdrawalPenalty (float)	//IN - MM withdrawal penalty
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* virtual bool Withdrawal(Date  today,
*			  float amount);
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

/***************
 ** ACCESSORS **
 **************/

/******************************************************************************
* float GetWithdrawalPenalty() const;
*
* 	Accessor; This method retrieves withdrawalPenalty in MoneyMarket
* ----------------------------------------------------------------------------
* 	Parameter: None
* ----------------------------------------------------------------------------
* 	Return: withdrawalPenalty (float)
* ****************************************************************************/

#endif /* H6_MONEYMARKETCLASS_H_ */
