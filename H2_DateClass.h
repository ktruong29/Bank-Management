/******************************************************************************
 * AUTHOR		 : Kevin Truong
 * STUDENT ID	 : 1017195
 * ASSIGNMENT #6 : OOP - Saddleback Bank
 * CLASS		 : CS1B
 * SECTION		 : MW: 6:30pm
 * DUE DATE		 : 5/21/18
 ******************************************************************************/

#ifndef H2_DATECLASS_H_
#define H2_DATECLASS_H_


#include <string>
using namespace std;

//Global constants
const unsigned short CURRENT_YR = 2018;

class Date
{
	public:
		/******************************************************************
					CONSTRUCTORS	&	DESTRUCTOR
		 ******************************************************************/
		Date();
		//uses private utility methods
		Date(unsigned short month,
		     unsigned short day,
		     unsigned short year);
		~Date();
		/*****************************************************************
						MUTATORS
		 *****************************************************************/
		//uses private utility methods
		void SetDate(unsigned short month,
			     unsigned short day,
			     unsigned short year);
		/*****************************************************************
						ACCESSORS
		 *****************************************************************/
		void GetDate(unsigned short &month,
			     unsigned short &day,
			     unsigned short &year) const;
		unsigned short GetYear()	const;
		unsigned short GetMonth()	const;
		unsigned short GetDay()		const;
		// Displays	in MM/DD/YYYY format
		string	DisplayDate()	const;

	private:
			/******************************************************************
					 UTILITIES	METHODS
			*******************************************************************/
		unsigned short GetDaysInMonth(unsigned short month,
					      unsigned short year) const;
		bool IsLeapYear(unsigned short year) const;
			/******************************************************************
							VALIDATE	METHODS
			 ******************************************************************/
		 //	Validates the month
		bool ValidateMonth(unsigned	short month) const;
		//	Checks if the day is valid takes leap year into consideration
		bool ValidateDay(unsigned short month,
				 unsigned short day,
				 unsigned short year) const;
		//	Validates the year is between 1900 and the current year
		bool ValidateYear(unsigned short year) const;
		//	Uses methods above to validate a given date	- checks against current day
		bool ValidateDate(unsigned short month,
				  unsigned short day,
				  unsigned short year) const;

			/*****************************************************************
							ATTRIBUTES
			*****************************************************************/
		unsigned short dateMonth;	//IN, CALC & OUT - date's month
		unsigned short dateDay;		//IN, CALC & OUT - date's day
		unsigned short dateYear;	//IN, CALC & OUT - date's year
};

/******************************************************************************
* Date Class
* 	This class represents a date object. It manages three attributes of a
* 		date: dateMonth, dateDay, dateYear.
* ****************************************************************************/

/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
* Date()
* 	Constructor; Initialize class attributes
* 	Parameters: none
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* Date(unsigned short month,
*	   unsigned short day,
*	   unsigned short year);
* 	Constructor; Initialize class attributes
* 	Parameters: month (unsigned short) //IN - month of the year
* 				day	  (unsigned short) //IN - day of the year
* 				year  (unsigned short) //IN - year
* 	Return: none
* ****************************************************************************/

/******************************************************************************
* ~Date()
* 	Destructor; does not perform any specific function
* 	Parameters: none
* 	Return: none
* ****************************************************************************/

/**************
 ** MUTATORS **
 **************/

/******************************************************************************
* void SetDate(unsigned short month,
*			   unsigned short day,
*			   unsigned short year)
*
* 	Mutator; This method receives 3 parameters' values to initialize and error
* 		checks the  3 attributes of a date object: dateMonth, dateDay, and dateYear.
* ----------------------------------------------------------------------------
* 	Parameters: month (unsigned short) //IN - month of the year
* 				day	  (unsigned short) //IN - day of the year
* 				year  (unsigned short) //IN - year
* ----------------------------------------------------------------------------
* 	Return: none
* ****************************************************************************/

/**************
 ** ACCESSORS **
 **************/

/******************************************************************************
* void GetDate(unsigned short &month,
*			   unsigned short &day,
*			   unsigned short &year)	const;
*
* 	Accessor; This method first will get the month, date, and year; then it
* 		returns those 3 attributes (passed by reference) back to main
* ----------------------------------------------------------------------------
* 	Parameter: month (unsigned short)  //IN - month of the year
* 			   day	  (unsigned short) //IN - day of the year
* 			   year  (unsigned short)  //IN - year
* ----------------------------------------------------------------------------
* 	Return: date's month, day, and year (unsigned short)
* ****************************************************************************/

/******************************************************************************
* unsigned short GetYear()	const;
*
* 	Accessor; This method will get the year and return dateYear
* ----------------------------------------------------------------------------
* 	Parameter: none
* ----------------------------------------------------------------------------
* 	Return: date's year (unsigned short)
* ****************************************************************************/

/******************************************************************************
* unsigned short GetMonth()	const;
*
* 	Accessor; This method will get the month and return dateMonth.
* ----------------------------------------------------------------------------
* 	Parameter: none
* ----------------------------------------------------------------------------
* 	Return: date's month (unsigned short)
* ****************************************************************************/

/******************************************************************************
* unsigned short GetDay()		const;
*
* 	Accessor; This method will get the day and return dateDay
* ----------------------------------------------------------------------------
* 	Parameter: none
* ----------------------------------------------------------------------------
* 	Return: dte's day (unsigned short)
* ****************************************************************************/

/******************************************************************************
* string	DisplayDate()	const;
*
* 	Accessor; This method will get the day, month, year, and return the string
* 		of the format as follows : MM/DD/YYYY
* ----------------------------------------------------------------------------
* 	Parameter: none
* ----------------------------------------------------------------------------
* 	Return: date string
* ****************************************************************************/

/******************************************************************************
* unsigned short GetDaysInMonth(unsigned short month,
*								unsigned short year) const;
*
* 	Accessor; This method receives month and year to calculate the correct number
* 		of days associated with each particular month. This will return the
* 		number of days.
* ----------------------------------------------------------------------------
* 	Parameter: month (unsigned short)  //IN - month to calc days
* 			   year  (unsigned short)  //IN - year to calc days
* ----------------------------------------------------------------------------
* 	Return: days
* ****************************************************************************/

/******************************************************************************
* bool IsLeapYear(unsigned short year) const;
*
* 	Accessor; This method receives a year and calculating the leap year. This
* 		method will return TRUE if it's a leap year and return FALSE if it's
* 		not a leap year
* ----------------------------------------------------------------------------
* 	Parameter:	year  (unsigned short)  //IN - year to calc days
* ----------------------------------------------------------------------------
* 	Return: validLeapYr (Bool)
* ****************************************************************************/

/******************************************************************************
* bool ValidateMonth(unsigned short month) const;
*
* 	Accessor; This method receives month to validate the month. This method will
* 		return TRUE if the month entered is valid and return FALSE will the
* 		month entered is invalid
* ----------------------------------------------------------------------------
* 	Parameter: month (unsigned short)  //IN - month to calc days
* ----------------------------------------------------------------------------
* 	Return: validMonth (Bool)
* ****************************************************************************/

/******************************************************************************
* bool ValidateDay(unsigned short month,
* 				   unsigned short day,
*				   unsigned short year) const;
*
* 	Accessor; This method receives month, day, and year to check whether if the
* 		month and year entered have the valid days for that particular month
* 		and year. It also will use the method IsLeapYear to check whether the days
* 		entered for February is valid or not. This will return TRUE if the days
* 		are valid and return FALSE if the days are invalid.
* ----------------------------------------------------------------------------
* 	Parameter: month (unsigned short)  //IN - month to validate day
* 			   day	 (unsigned short)  //IN - day to validate day
* 			   year  (unsigned short)  //IN - year to validate day
* ----------------------------------------------------------------------------
* 	Return: validDay (Bool)
* ****************************************************************************/

/******************************************************************************
* bool ValidateYear(unsigned short year) const;
*
* 	Accessor; This method receives a year to check for valid year. The valid year
* 		is between 1900 and the current year. This method will return TRUE if
* 		the year is valid and return FALSE with the year in invalid.
* ----------------------------------------------------------------------------
* 	Parameter: year (unsigned short)  //IN - year to validate year
* ----------------------------------------------------------------------------
* 	Return: validYear (Bool)
* ****************************************************************************/

/******************************************************************************
* bool ValidateDate(unsigned short month,
*					unsigned short day,
*					unsigned short year) const;
*
* 	Accessor; This method receives a year, day, and month to validate date. This
* 		method also uses the previous methods to check for date. Those methods
* 		include ValidateMonth, ValidateDay, and ValidateYear. This will return
* 		TRUE if the date is valid and return FALSE if it's invalid
* ----------------------------------------------------------------------------
* 	Parameter: month (unsigned short)  //IN - month to validate date
* 			   day	 (unsigned short)  //IN - day to validate date
* 			   year  (unsigned short)  //IN - year to validate date
* ----------------------------------------------------------------------------
* 	Return: validDate (Bool)
* ****************************************************************************/

#endif /* H2_DATECLASS_H_ */
