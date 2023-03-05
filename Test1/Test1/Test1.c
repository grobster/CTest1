// --------------------------------------------------------------------------------
// Name: Jeffery Quarles
// Class: SET-151-400
// Abstract: Homework Test 1
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes – built-in libraries of functions
// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------
const long lngARRAY_SIZE = 100;

// --------------------------------------------------------------------------------
// User Defined Types (UDT)
// --------------------------------------------------------------------------------
float sngAllEmployeesBeforeDiscountRunningTotal = 0.0f;
float sngAllEmployeesAfterDiscountRunningTotal = 0.0f;

// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
void EmptyStdin( );
int ValidateNumberOfYearsEmployed( );
float ValidateAmountOfPreviousPurchase( );
char ValidateEmployeeStatus( );
float ValidateAmountOfTodaysPurchase( );
void CalculateDiscountPercentage( float* psngDiscountPercentage, char chrEmployeeStatus, int intNumberOfYearsEmployed );
void CalculateYearToDateAmountOfDiscount( float* psngYearToDateAmountOfDiscount, float sngAmountPreviousPurchase, float sngDiscountPercentage );
void CalculateDiscountTodaysPurchase( float* psngAmountDiscountTodaysPurchase, float sngYearToDateAmountOfDiscount, float sngAmountTodaysPurchase, float sngDiscountPercentage );
void CalculateTotalWithDiscount( float* psngTotalWithDiscount, float sngAmountTodaysPurchase, float sngAmountDiscountTodaysPurchase );
void UpdateRunningTotals( float sngAmountTodaysPurchase, float sngTotalWithDiscount );
void DisplayEmployeeOutputs( float sngDiscountPercentage, float sngYearToDateAmountOfDiscount, float sngAmountTodaysPurchase, float sngAmountDiscountTodaysPurchase, float sngTotalWithDiscount );
char PromptAndValidateAnotherEmployee( int* pintHaveAnotherEmployee );
void DetermineToInputNextUser( char chrHaveAnotherEmployeeInput, int* pintHaveAnotherEmployee );
void DisplayAllEmployeesSummary( );


// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// --------------------------------------------------------------------------------
void main( )
{
	// declare variables
	int intNumberOfYearsEmployed = 0;
	float sngAmountPreviousPurchase = 0.0f;
	char chrEmployeeStatus = 0;
	float sngAmountTodaysPurchase = 0.0f;
	float sngDiscountPercentage = 0.0f;
	float sngYearToDateAmountOfDiscount = 0.0f;
	float sngAmountDiscountTodaysPurchase = 0.0f;
	float sngTotalWithDiscount = 0.0f;
	int intHaveAnotherEmployee = 1;
	char chrHaveAnotherEmployeeInput = 0;

	while ( intHaveAnotherEmployee )
	{
		// Get and Validate Inputs
		intNumberOfYearsEmployed = ValidateNumberOfYearsEmployed( );
		sngAmountPreviousPurchase = ValidateAmountOfPreviousPurchase( );
		chrEmployeeStatus = ValidateEmployeeStatus( );
		sngAmountTodaysPurchase = ValidateAmountOfTodaysPurchase( );

		// Perform Calculations
		CalculateDiscountPercentage( &sngDiscountPercentage, chrEmployeeStatus, intNumberOfYearsEmployed );
		CalculateYearToDateAmountOfDiscount( &sngYearToDateAmountOfDiscount, sngAmountPreviousPurchase, sngDiscountPercentage );
		CalculateDiscountTodaysPurchase( &sngAmountDiscountTodaysPurchase, sngYearToDateAmountOfDiscount, sngAmountTodaysPurchase, sngDiscountPercentage );
		CalculateTotalWithDiscount( &sngTotalWithDiscount, sngAmountTodaysPurchase, sngAmountDiscountTodaysPurchase );

		// Update all employees running totals
		UpdateRunningTotals( sngAmountTodaysPurchase, sngTotalWithDiscount );

		// Display Employee Summary
		DisplayEmployeeOutputs( sngDiscountPercentage, sngYearToDateAmountOfDiscount, sngAmountTodaysPurchase, sngAmountDiscountTodaysPurchase, sngTotalWithDiscount );

		// Get and Validate input for another user
		chrHaveAnotherEmployeeInput = PromptAndValidateAnotherEmployee( &intHaveAnotherEmployee );

		// Determine whether to break from main while loop or continue prompting for next employee's input
		DetermineToInputNextUser( chrHaveAnotherEmployeeInput, &intHaveAnotherEmployee );
	}

	// Display All Employees Summary
	DisplayAllEmployeesSummary( );

	system( "pause" );
}



// --------------------------------------------------------------------------------
// Name: EmptyStdin( )
// Abstract: clears the stdin buffer
// --------------------------------------------------------------------------------
void EmptyStdin( )
{
	int intCharacter = getchar( );
	while ( intCharacter != '\n' && intCharacter != EOF )
	{
		intCharacter = getchar( );
	}
}



// --------------------------------------------------------------------------------
// Name: ValidateNumberOfYearsEmployed
// Abstract: Prompts and validates for integer of number of years employed.
// --------------------------------------------------------------------------------
int ValidateNumberOfYearsEmployed( )
{
	// declare variables
	int intNumberOfYearsEmployed = 0;
	int intResult = 0;

	do
	{
		printf( "Enter Number of Years Employed: ");
		intResult = scanf( "%d", &intNumberOfYearsEmployed );

		if ( intResult <= 0 )
		{
			printf( "Invalid Input - Enter Integer Numbers Only\n" );
			EmptyStdin( );
		}

	} while ( intNumberOfYearsEmployed <= 0 );

	return intNumberOfYearsEmployed;
}



// --------------------------------------------------------------------------------
// Name: ValidateAmountOfPreviousPurchase
// Abstract: Prompts and validates float for amount of previous purchase.
// --------------------------------------------------------------------------------
float ValidateAmountOfPreviousPurchase( )
{
	// declare variables
	float sngAmountOfPreviousPurchase = -1;
	int intResult = 0;

	do
	{
		printf( "Enter Amount of Previous Purchase: " );
		intResult = scanf( "%f", &sngAmountOfPreviousPurchase );

		if ( intResult <= 0 )
		{
			printf( "Invalid Input - Enter Floating Numbers Only (e.g. 12.50)\n" );
			EmptyStdin( );
		}

	} while ( sngAmountOfPreviousPurchase < 0 );

	return sngAmountOfPreviousPurchase;
}



// --------------------------------------------------------------------------------
// Name: ValidateEmployeeStatus
// Abstract: Prompts and validates float for amount of previous purchase.
// --------------------------------------------------------------------------------
char ValidateEmployeeStatus( )
{
	// declare variables
	char chrEmployeeStatus = 0;
	int intResult = 0;

	do
	{
		printf( "Enter Employee Status - Type 'M' for Management or 'H' for Hourly: \n" );
		intResult = scanf( " %c", &chrEmployeeStatus );
		if ( intResult <= 0 )
		{
			printf( "Invalid Input - Enter 'M' for Management or 'H' for Hourly Employee: \n" );
			EmptyStdin( );
		}

	} while ( chrEmployeeStatus != 'M' && chrEmployeeStatus != 'H' );

	return chrEmployeeStatus;
}



// --------------------------------------------------------------------------------
// Name: ValidateAmountOfTodaysPurchase
// Abstract: Prompts and validates float for amount of today's purchase.
// --------------------------------------------------------------------------------
float ValidateAmountOfTodaysPurchase( )
{
	// declare variables
	float sngAmountTodaysPurchase = -1;
	int intResult = 0;

	do
	{
		printf( "Enter Amount of Today's Purchase: " );
		intResult = scanf( "%f", &sngAmountTodaysPurchase );

		if ( intResult <= 0 )
		{
			printf( "Invalid Input - Enter Floating Numbers Only (e.g. 5.50)\n" );
			EmptyStdin( );
		}

	} while ( sngAmountTodaysPurchase < 0 );

	return sngAmountTodaysPurchase;
}



// --------------------------------------------------------------------------------
// Name: CalculateDiscountPercentage
// Abstract: Prompts and validates float for amount of today's purchase.
// --------------------------------------------------------------------------------
void CalculateDiscountPercentage( float* psngDiscountPercentage, char chrEmployeeStatus, int intNumberOfYearsEmployed )
{
	// declare variables
	float sngTenPercent = 0.10;
	float sngFourteenPercent = 0.14;
	float sngTwentyPercent = 0.20;
	float sngTwentyFourPercent = 0.24;
	float sngTwentyFivePercent = 0.25;
	float sngThirtyPercent = 0.30;
	float sngThirtyFivePercent = 0.35;
	float sngFortyPercent = 0.40;
	
	if ( chrEmployeeStatus == 'M' )
	{
		if ( intNumberOfYearsEmployed >= 1 && intNumberOfYearsEmployed <= 3 )
		{
			*psngDiscountPercentage = sngTwentyPercent;
		}
		else if ( intNumberOfYearsEmployed >= 4 && intNumberOfYearsEmployed <= 6 )
		{
			*psngDiscountPercentage = sngTwentyFourPercent;
		}
		else if ( intNumberOfYearsEmployed >= 7 && intNumberOfYearsEmployed <= 10 )
		{
			*psngDiscountPercentage = sngThirtyPercent;
		}
		else if ( intNumberOfYearsEmployed >= 11 && intNumberOfYearsEmployed <= 15 )
		{
			*psngDiscountPercentage = sngThirtyFivePercent;
		}
		else
		{
			*psngDiscountPercentage = sngFortyPercent;
		}
	}
	else if ( chrEmployeeStatus == 'H' )
	{

		if ( intNumberOfYearsEmployed >= 1 && intNumberOfYearsEmployed <= 3 )
		{
			*psngDiscountPercentage = sngTenPercent;
		}
		else if ( intNumberOfYearsEmployed >= 4 && intNumberOfYearsEmployed <= 6 )
		{
			*psngDiscountPercentage = sngFourteenPercent;
		}
		else if ( intNumberOfYearsEmployed >= 7 && intNumberOfYearsEmployed <= 10 )
		{
			*psngDiscountPercentage = sngTwentyPercent;
		}
		else if ( intNumberOfYearsEmployed >= 11 && intNumberOfYearsEmployed <= 15 )
		{
			*psngDiscountPercentage = sngTwentyFivePercent;
		}
		else
		{
			*psngDiscountPercentage = sngThirtyPercent;
		}
	}
}



// --------------------------------------------------------------------------------
// Name: CalculateYearToDateAmountOfDiscount
// Abstract: Calculates the year-to-date amount of discount for an employee per year
// --------------------------------------------------------------------------------
void CalculateYearToDateAmountOfDiscount( float* psngYearToDateAmountOfDiscount, float sngAmountPreviousPurchase, float sngDiscountPercentage )
{
	*psngYearToDateAmountOfDiscount = sngAmountPreviousPurchase * sngDiscountPercentage;
}



// --------------------------------------------------------------------------------
// Name: CalculateDiscountTodaysPurchase
// Abstract: Calculates the amount of discount for today's purchase
// sngAmountDiscountTodaysPurchase
// --------------------------------------------------------------------------------
void CalculateDiscountTodaysPurchase( float* psngAmountDiscountTodaysPurchase, float sngYearToDateAmountOfDiscount, float sngAmountTodaysPurchase, float sngDiscountPercentage )
{
	// declare variables
	float sngMaximumDiscountAmount = 200;
	
	if ( sngYearToDateAmountOfDiscount > sngMaximumDiscountAmount )
	{
		*psngAmountDiscountTodaysPurchase = 0;
	}
	else
	{
		if ( sngYearToDateAmountOfDiscount + ( sngAmountTodaysPurchase * sngDiscountPercentage ) > sngMaximumDiscountAmount )
		{
			*psngAmountDiscountTodaysPurchase = sngMaximumDiscountAmount - sngYearToDateAmountOfDiscount;
		}
		else
		{
			*psngAmountDiscountTodaysPurchase = sngAmountTodaysPurchase * sngDiscountPercentage;
		}
	}
}



// --------------------------------------------------------------------------------
// Name: CalculateTotalWithDiscount
// Abstract: Calculates today's total with the discount subtracted from it.
// --------------------------------------------------------------------------------
void CalculateTotalWithDiscount( float* psngTotalWithDiscount, float sngAmountTodaysPurchase, float sngAmountDiscountTodaysPurchase )
{
	*psngTotalWithDiscount = sngAmountTodaysPurchase - sngAmountDiscountTodaysPurchase;
}



// --------------------------------------------------------------------------------
// Name: UpdateRunningTotals
// Abstract: Add Totals before discount to All Employees before discount total
// Add Totals after discount to All Employees after discount total
// --------------------------------------------------------------------------------
void UpdateRunningTotals( float sngAmountTodaysPurchase, float sngTotalWithDiscount )
{
	// add Todays total amount to sngAllEmployeesBeforeDiscountRunningTotal
	sngAllEmployeesBeforeDiscountRunningTotal += sngAmountTodaysPurchase;

	// add Today's total with discount to sngAllEmployeesAfterDiscountRunningTotal
	sngAllEmployeesAfterDiscountRunningTotal += sngTotalWithDiscount;
}



// --------------------------------------------------------------------------------
// Name: DisplayEmployeeOutputs
// Abstract: Displays outputs for each employee
// --------------------------------------------------------------------------------
void DisplayEmployeeOutputs( float sngDiscountPercentage, float sngYearToDateAmountOfDiscount, float sngAmountTodaysPurchase, float sngAmountDiscountTodaysPurchase, float sngTotalWithDiscount )
{
	// declare variables
	float sngDiscountPercentageMultipliedBy100 = 0;
		
	sngDiscountPercentageMultipliedBy100 = sngDiscountPercentage * 100;
	
	// Display outputs
	printf( "\n" );
	printf( "---------------------------------------------------------\n" );
	printf( "\t\tEmployee Discount Summary\n");
	printf( "---------------------------------------------------------\n" );
	printf( "Discount Percentage: \t\t%.0f%%\n", sngDiscountPercentageMultipliedBy100 );
	printf( "Year to date discount: \t\t$%.2f\n", sngYearToDateAmountOfDiscount );
	printf( "Total of Today's Purchase: \t$%.2f\n", sngAmountTodaysPurchase );
	printf( "Discount this Purchase: \t$%.2f\n", sngAmountDiscountTodaysPurchase );
	printf( "Total with Discount: \t\t$%.2f\n", sngTotalWithDiscount );
	printf( "---------------------------------------------------------\n" );
	printf( "\n" );
}



// --------------------------------------------------------------------------------
// Name: PromptAndValidateAnotherEmployee
// Abstract: Prompts uers to enter 'Y' for Yes or 'N' for No to determine if
// user has another employee
// --------------------------------------------------------------------------------
char PromptAndValidateAnotherEmployee ( int* pintHaveAnotherEmployee )
{
	// declare variables
	char chrHaveAnotherEmployeeInput = 0;

	do
	{
		printf( "Have another employee? ( Type 'Y' for Yes or 'N' for No ): \n" );
		scanf( " %c", &chrHaveAnotherEmployeeInput );
	} while ( chrHaveAnotherEmployeeInput != 'Y' && chrHaveAnotherEmployeeInput != 'N' );

	return chrHaveAnotherEmployeeInput;
}



// --------------------------------------------------------------------------------
// Name: DetermineToInputNextUser
// Abstract: Determine whether to break from main loop or continue and prompt
// for the next user's data.
// --------------------------------------------------------------------------------
void DetermineToInputNextUser( char chrHaveAnotherEmployeeInput, int* pintHaveAnotherEmployee )
{
	// Display outputs
	switch ( chrHaveAnotherEmployeeInput )
	{
	case 'Y':
		*pintHaveAnotherEmployee = 1;
		break;
	case 'N':
		*pintHaveAnotherEmployee = 0;
		break;
	}
}



// --------------------------------------------------------------------------------
// Name: DisplayAllEmployeesSummary
// Abstract: Displays the running totals for all employees
// --------------------------------------------------------------------------------
void DisplayAllEmployeesSummary( )
{
	// Display outputs
	printf( "\n" );
	printf( "---------------------------------------------------------\n" );
	printf( "\t\tAll Employees Discount Summary\n");
	printf("---------------------------------------------------------\n" );
	printf( "All Employees Total Before Discount: \t\t$%.2f\n", sngAllEmployeesBeforeDiscountRunningTotal );
	printf( "All Employees Total After Discount: \t\t$%.2f\n", sngAllEmployeesAfterDiscountRunningTotal );
	printf( "---------------------------------------------------------\n" );
	printf( "\n" );
}
