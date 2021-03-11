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
 * Constructor Date: Class Date
 * ----------------------------------------------------------------------------
 * This constructor creates a date object and initializes three attributes
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A new date object is created
 *****************************************************************************/
Date::Date()
{
	dateMonth = 0;
	dateDay	  = 0;
	dateYear  = 0;
}

/******************************************************************************
 * Constructor Date: Class Date
 * ----------------------------------------------------------------------------
 * This constructor creates a date object and initializes three attributes and
 * 		error checks the date
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 The following need to be defined previously:
 * 	 	month (unsigned short) //IN - month of the year
 * 		day	  (unsigned short) //IN - day of the year
 * 		year  (unsigned short) //IN - year
 *
 * POST-CONDITIONS
 * 	 A new date object is created
 *****************************************************************************/
Date::Date(unsigned short month,	//IN - month of the year
	   unsigned short day,		//IN - day of the year
     	   unsigned short year)		//IN - year
{
	if(!ValidateDate(month, day, year))
	{
		if(!ValidateMonth(month))
		{
			dateMonth = ValidateIntInput("Enter month: ", 1, 12);
		}
		else if(!ValidateDay(month, day, year))
		{
			dateDay = ValidateIntInput("Enter day: ", 1, GetDaysInMonth(month, year));
		}
		else
		{
			dateYear = ValidateIntInput("Enter day: ", 1900, CURRENT_YR);
		}
	}
	else
	{
		dateMonth = month;
		dateDay	  = day;
		dateYear  = year;
	}
}

/******************************************************************************
 * Destructor Date: Class Date
 * ----------------------------------------------------------------------------
 * This destructor deallocates memory by deleting a date object
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	 None
 *
 * POST-CONDITIONS
 * 	 A date object is deallocated
 *****************************************************************************/
Date::~Date(){};

//MUTATORS
/******************************************************************************
 * Method SetDate: Class Date
 * ----------------------------------------------------------------------------
 * This method receives 3 parameters' values to initialize and error checks the
 * 		3 attributes of a date object: dateMonth, dateDay, and dateYear.
 * 	 Returns nothing
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		month (unsigned short) //IN - month of the year
 * 		day	  (unsigned short) //IN - day of the year
 * 		year  (unsigned short) //IN - year
 *
 * POST-CONDITIONS
 * 	 Returns nothing
 *****************************************************************************/
void Date::SetDate(unsigned short month,	//IN - month of the year
		   unsigned short day,		//IN - day of the year
		   unsigned short year)		//IN - year
{
	bool validDate;	//CALC - checking for valid date input

	validDate = ValidateDate(month, day, year);

	if(!validDate)
	{
		while(!validDate)
		{
			if(!ValidateMonth(month))
			{
				cout << "\n*** INVALID MONTH ***\n";
				month = ValidateIntInput("Enter month: ", 1, 12);
			}
			else if(!ValidateDay(month, day, year))
			{
				cout << "\n*** INVALID DAY ***\n";
				day = ValidateIntInput("Enter day: ", 1, GetDaysInMonth(month, year));
			}
			else
			{
				cout << "\n*** INVALID YEAR ***\n";
				year   = ValidateIntInput("Enter year: ", 1900, CURRENT_YR);
			}
			//Chaning the LCV
			validDate = ValidateDate(month, day, year);
		}
	}//END if(!validDate)

	dateMonth = month;
	dateDay	  = day;
	dateYear  = year;
}

//ACCESSORS
/******************************************************************************
 * Method GetDate: Class Date
 * ----------------------------------------------------------------------------
 * This method retrieves the dateMonth, dateDay, and dateYear of a Date
 * 	 Returns date's month, day, and year
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * The following need to be defined previously
 * 		month (unsigned short) //IN - month of the year
 * 		day	  (unsigned short) //IN - day of the year
 * 		year  (unsigned short) //IN - year
 *
 * POST-CONDITIONS
 * 	 Returns date's month, day, and year
 *****************************************************************************/
void Date::GetDate(unsigned short &month,		//IN - month of the year
		   unsigned short &day,			//IN - day of the year
		   unsigned short &year) const	//IN - year
{
	month = dateMonth;
	day   = dateDay;
	year  = dateYear;
}

/******************************************************************************
 * Method GetYear: Class Date
 * ----------------------------------------------------------------------------
 * This method retrieves the dateYear of a Date
 * 	 Returns date's year
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The following need to be defined previously
 * 		year  (unsigned short) //IN - year
 *
 * POST-CONDITIONS
 * 	 Returns date's year
 *****************************************************************************/
unsigned short Date::GetYear() const
{
	return dateYear;
}

/******************************************************************************
 * Method GetMonth: Class Date
 * ----------------------------------------------------------------------------
 * This method retrieves the dateMonth of a Date
 * 	 Returns date's month
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The following need to be defined previously
 * 		month (unsigned short) //IN - month of the year
 *
 * POST-CONDITIONS
 * 	 Returns date's month
 *****************************************************************************/
unsigned short Date::GetMonth() const
{
	return dateMonth;
}

/******************************************************************************
 * Method GetDay: Class Date
 * ----------------------------------------------------------------------------
 * This method retrieves the dateDay of a Date
 * 	 Returns date's day
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The following need to be defined previously
 * 		day	  (unsigned short) //IN - day of the year
 *
 * POST-CONDITIONS
 * 	 Returns date's day
 *****************************************************************************/
unsigned short Date::GetDay() const
{
	return dateDay;
}

/******************************************************************************
 * Method DisplayDate: Class Date
 * ----------------------------------------------------------------------------
 * This method retrieves the dateMonth, dateDay, and dateYear of a Date
 * 	 Returns date's month, day, and year as type string
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The following need to be defined previously
 * 		month (unsigned short) //IN - month of the year
 * 		day	  (unsigned short) //IN - day of the year
 * 		year  (unsigned short) //IN - year
 *
 * POST-CONDITIONS
 * 	 Returns date's month, day, and year as type string
 *****************************************************************************/
string Date::DisplayDate() const
{
	ostringstream output;	//CALC - converting to type string

	output << dateMonth << '/' << dateDay << '/' << dateYear;

	return output.str();
}

/******************************************************************************
 * Method GetDaysInMonth: Class Date
 * ----------------------------------------------------------------------------
 * This method receives month and year to calculate the correct number
 * 		of days associated with each particular month. This will return the
 * 		number of days.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The following need to be defined previously
 * 		month (unsigned short) //IN - date's month
 * 		year  (unsigned short) //IN - date's year
 *
 * POST-CONDITIONS
 * 	 Returns days
 *****************************************************************************/
unsigned short Date::GetDaysInMonth(unsigned short month,	//IN - date's month
				    unsigned short year) const	//IN - date's year
{
	unsigned short days;	//CALC - days in a month

	if((month == 1 || month == 3 || month == 5 || month == 7 ||
	    month == 8 || month == 10 || month == 12))
	{
		days = 31;
	}
	else if((month == 4 || month == 6 || month == 9 || month == 11))
	{
		days = 30;
	}
	else if(month == 2 && IsLeapYear(year))
	{
		days = 29;
	}
	else
	{
		days = 28;
	}

	return days;
}

/******************************************************************************
 * Method IsLeapYear: Class Date
 * ----------------------------------------------------------------------------
 * This method receives a year and calculating the leap year. This
 * 		method will return TRUE if it's a leap year and return FALSE if it's
 * 		not a leap year
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The following need to be defined previously
 * 		year  (unsigned short) //IN - date's year
 *
 * POST-CONDITIONS
 * 	 Returns valid leap year (bool)
 *****************************************************************************/
bool Date::IsLeapYear(unsigned short year) const //IN - date's year
{
	const int LEAP_COND1 = 4;
	const int LEAP_COND2 = 400;

	bool validLeapYr;	//CALC - validating leap year

	validLeapYr = false;
	if(year % LEAP_COND1 == 0 || year % LEAP_COND2 == 0)
	{
		validLeapYr = true;
	}

	return validLeapYr;
}

/******************************************************************************
 * Method ValidateMonth: Class Date
 * ----------------------------------------------------------------------------
 * This method receives month to validate the month. This method will
 * 		return TRUE if the month entered is valid and return FALSE will the
 * 		month entered is invalid
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The following need to be defined previously
 * 		month (unsigned short)  //IN - date's month
 *
 * POST-CONDITIONS
 * 	 Returns valid month (bool)
 *****************************************************************************/
bool Date::ValidateMonth(unsigned short month) const
{
	const int MIN_MONTH = 1;
	const int MAX_MONTH = 12;

	bool validMonth;	//CALC - calculating valid month

	validMonth = true;
	if(month < MIN_MONTH || month > MAX_MONTH)
	{
		validMonth = false;
	}

	return validMonth;
}

/******************************************************************************
 * Method ValidateDay: Class Date
 * ----------------------------------------------------------------------------
 * This method receives month, day, and year to check whether if the
 * 		month and year entered have the valid days for that particular month
 * 		and year. It also will use the method IsLeapYear to check whether the days
 * 		entered for February is valid or not. This will return TRUE if the days
 * 		are valid and return FALSE if the days are invalid.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The following need to be defined previously
 * 		month (unsigned short)  //IN - month to validate day
 * 		day	  (unsigned short)  //IN - day to validate day
 * 		year  (unsigned short)  //IN - year to validate day
 *
 * POST-CONDITIONS
 * 	 Returns valid day (bool)
 *****************************************************************************/
bool Date::ValidateDay(unsigned short month,		//IN - month to validate day
		       unsigned short day,		//IN - day to validate day
		       unsigned short year) const	//IN - year to validate day
{
	bool valid31Days;	//CALC - validating months having 31 days
	bool valid30Days;	//CALC - validating months having 30 days
	bool validFebDays;	//CALC - validating months having 28 or 29 days
	bool validDay;		//CALC - validating day

	//Checking for months that have 31 days
	valid31Days = ((month == 1 || month == 3 || month == 5 || month == 7 ||
			month == 8 || month == 10 || month == 12)	     &&
	 		(day >= 1 && day <= 31));

	//Checking for months that have 30 days
	valid30Days = ((month == 4 || month == 6 || month == 9 || month == 11) &&
		       (day >= 1 && day <= 30));

	//Checking for leap year
	validFebDays = ((IsLeapYear(year)  && (day >= 1 && day <= 29)) ||
			(!IsLeapYear(year) && (day >= 1 && day <= 28)));

	validDay = valid31Days || valid30Days || validFebDays;

	return validDay;
}

/******************************************************************************
 * Method ValidateYear: Class Date
 * ----------------------------------------------------------------------------
 * This method receives a year to check for valid year. The valid year
 * 		is between 1900 and the current year. This method will return TRUE if
 * 		the year is valid and return FALSE with the year in invalid.
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The following need to be defined previously
 * 		year  (unsigned short)  //IN - year to validate year
 *
 * POST-CONDITIONS
 * 	 Returns valid year (bool)
 *****************************************************************************/
bool Date::ValidateYear(unsigned short year) const //IN - year to validate year
{
	const unsigned short MIN_YR 	= 1900;

	bool validYr;	//CALC - validating year

	validYr = true;
	if(year < MIN_YR || year > CURRENT_YR)
	{
		validYr = false;
	}

	return validYr;
}

/******************************************************************************
 * Method ValidateDate: Class Date
 * ----------------------------------------------------------------------------
 * This method receives a year, day, and month to validate date. This
 * 		method also uses the previous methods to check for date. Those methods
 * 		include ValidateMonth, ValidateDay, and ValidateYear. This will return
 * 		TRUE if the date is valid and return FALSE if it's invalid
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The following need to be defined previously
 * 		month (unsigned short)  //IN - month to validate date
 * 		day	  (unsigned short)  //IN - day to validate date
 * 		year  (unsigned short)  //IN - year to validate date
 *
 * POST-CONDITIONS
 * 	 Returns valid date (bool)
 *****************************************************************************/
bool Date::ValidateDate(unsigned short month,		//IN - month to validate date
			unsigned short day,		//IN - day to validate date
			unsigned short year) const	//IN - year to validate date
{
	bool validDate;	//CALC - validating date

	validDate = (ValidateMonth(month) 	   &&
		     ValidateDay(month, day, year) &&
		     ValidateYear(year));

	return validDate;
}
