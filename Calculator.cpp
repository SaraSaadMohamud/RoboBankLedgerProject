/***************************************     include Part     ****************************** */
#include "Calculator.hpp"
#include <math.h>

/***********************************      Global Variable      ****************************** */
float fx_rate[4] ={1.0,1.185,1.36,48.08};
//                {USD,EUR,GBP,EGP};

/*********************************** Functions Definiton Part ****************************** */


/** 
 * This function takes the current balance and adds the specified deposit amount,
   then returns the new updated balance.

 * @brief        : Applies a deposit to the current account balance.

 * @param balance: The current account balance before the deposit (integer value).

 * @param amount : The amount of money to be deposited (integer value).

 * @return       : int The updated balance after the deposit (balance + amount).

 */
int Apply_Deposite(int balance, int amount)
{
    int Result = 0;
    Result = (balance + amount );

    return(Result);
}

/**
 * This function subtracts the specified withdrawal amount from the current balance
    and returns the new balance. It assumes sufficient funds are available.
    
 * @brief        : Applies a withdrawal from the current account balance.

 * @param balance: The current account balance before the withdrawal (integer value).

 * @param amount : The amount of money to withdraw (integer value).

 * @return       : int The updated balance after the withdrawal (balance - amount).

 */
int Apply_Withdrawal(int balance, int amount)
{
    int Subtraction = 0;

    Subtraction = balance - amount;

    return(Subtraction);
}

/**
 * Deducts a specified fee amount from the balance and returns the new balance.

 * @brief        : Applies a fee to the current account balance.

 * @param balance: The current account balance before the fee deduction (integer value).

 * @param fee    : The fee amount to be deducted (integer value).

 * @return       : int The updated balance after the fee is applied (balance - fee).

 */
int Apply_Fee(int balance, int fee)
{
    int Process = 0;

    Process = balance - fee;

    return(Process);
}

/**
 * Computes the total accrued amount (principal + interest) using simple interest formula.
   Assumes 'rate' is a percentage value (e.g., 5 for 5%).

 * @brief          : Calculates the total amount with simple interest.

 * @param principle: The initial amount of money (principal) (integer value).

 * @param rate     : The annual interest rate in percentage (integer value).

 * @param time     : The time period in years (integer value).

 * @return         : int The total amount after applying simple interest (likely rounded to integer).

 */
int Simple_Insert(int principle, int rate, int time)
{
    int Percentage = 0;
    Percentage = (principle * rate * time) / 100 ;

    return (Percentage);
}

/**
 * Computes the compound interest based on the principal, annual interest rate,
   investment duration, and the number of compounding periods per year.
 
 * @brief                   : Calculates the future value of an investment with compound interest.

 * @param principle         : The initial investment amount (integer value).

 * @param APR               : The annual percentage rate (as percentage, e.g., 5 for 5%) (integer value).

 * @param Years             : The number of years the money is invested (integer value).

 * @param compounds_per_year: The number of times interest is compounded per year (integer value).

 * @return                  : int The future compounded value (rounded/truncated to integer).

 */
int Compound_Amount(int principle,int APR, int Years, int compounds_per_year)
{
    double Process1 =( ( (APR / 100.0) / compounds_per_year) + 1 );
    double power = (Years * compounds_per_year);
    int Result = (std::pow(Process1,power) * principle);

    return(Result);
}

/**

 * Converts the given amount from the source currency to the target currency.

* @brief               : Converts an amount from one currency to another.

 * @param amount       : The amount of money to convert (integer value).

 * @param from_currency: The source currency code (e.g., "USD") as a string.

 * @param to_currency  : The target currency code (e.g., "EUR") as a string.

 * @return             : int The converted amount in the target currency (integer value).

 */
int Fx_Convert(int amount , std::string from_currency, std::string to_currency)
{
    int Result = 0;
    if(to_currency == "USD")
    {
        if(from_currency == "USD")
        {
            Result = amount;
        }
        else if(from_currency == "EUR")
        {
           Result = (amount * fx_rate[1]);
        }
        else if(from_currency == "GBP")
        {
            Result = (amount * fx_rate[2]);
        }
        else if(from_currency == "EGP")
        {
            Result = (amount / fx_rate[3]);
        }
        else
        {
            std::cout<<"The currency that you want to convert from is invalide!.\n";
        }
    }
    else if(to_currency == "EUR")
    {
        if(from_currency == "USD")
        {
            Result = amount / fx_rate[1];
        }
        else if(from_currency == "EUR")
        {
            Result = amount;
        }
        else if(from_currency == "GBP")
        {
            Result = amount * fx_rate[2];
            Result /= fx_rate[1];
        }
        else if(from_currency == "EGP")
        {
            Result = amount / fx_rate[3];
            Result /= fx_rate[1];
        }
        else
        {
            std::cout<<"The currency that you want to convert from is invalide!.\n";
        }       
    }
    else if(to_currency == "GBP")
    {
        if(from_currency == "USD")
        {
            Result = amount / fx_rate[2];
        }
        else if(from_currency == "EUR")
        {
            Result = amount / fx_rate[1];
            Result /= fx_rate[2];
        }
        else if(from_currency == "GBP")
        {
            Result = amount;

        }
        else if(from_currency == "EGP")
        {
            Result = amount / fx_rate[3];
            Result /= fx_rate[2];
        }
        else
        {
            std::cout<<"The currency that you want to convert from is invalide!.\n";
        }
    }
    else if(to_currency == "EGP")
    {
        if(from_currency == "USD")
        {
            Result = amount * fx_rate[3];
        }
        else if(from_currency == "EUR")
        {
            Result = amount * fx_rate[1];
            Result *=  fx_rate[3];
        }
        else if(from_currency == "GBP")
        {
            Result = amount * fx_rate[2];
            Result *=  fx_rate[3];
        }
        else if(from_currency == "EGP")
        {
            Result = amount;
        }
        else
        {
            std::cout<<"The currency that you want to convert from is invalide!.\n";
        }
    }
    else
    {
        std::cout<<"The currency that you want to convert to is invalide!.\n";
    }

    return(Result);
}

/**
 * Computes the portion of the original amount that corresponds to the given rate (percentage).
 
 * @brief       : Calculates a given percentage of a numeric value.

 * @param amount: The base value (e.g., total price, quantity) (double value).

 * @param rate  : The percentage rate to apply (e.g., 10 for 10%) (double value).

 * @return      : double The result of the percentage calculation (e.g., 10% of 200.0 = 20.0).

 */
double Percent_of(double amount, double rate)
{
    double Result =0 ;
    Result =  (amount *rate / 100);

    return(Result);
}