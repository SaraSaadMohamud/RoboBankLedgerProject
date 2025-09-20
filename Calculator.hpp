#ifndef _CALCULATOR_HPP_
#define _CALCULATOR_HPP_

/********************** include Part ****************** */
#include <iostream>
#include <string>
/******************************** finctio Protoypes ********************* */
/** 
 * This function takes the current balance and adds the specified deposit amount,
   then returns the new updated balance.

 * @brief        : Applies a deposit to the current account balance.

 * @param balance: The current account balance before the deposit (integer value).

 * @param amount : The amount of money to be deposited (integer value).

 * @return       : int The updated balance after the deposit (balance + amount).

 */
int Apply_Deposite(int balance, int amount);

/**
 * This function subtracts the specified withdrawal amount from the current balance
    and returns the new balance. It assumes sufficient funds are available.
    
 * @brief        : Applies a withdrawal from the current account balance.

 * @param balance: The current account balance before the withdrawal (integer value).

 * @param amount : The amount of money to withdraw (integer value).

 * @return       : int The updated balance after the withdrawal (balance - amount).

 */
int Apply_Withdrawal(int balance, int amount);

/**
 * Deducts a specified fee amount from the balance and returns the new balance.

 * @brief        : Applies a fee to the current account balance.

 * @param balance: The current account balance before the fee deduction (integer value).

 * @param fee    : The fee amount to be deducted (integer value).

 * @return       : int The updated balance after the fee is applied (balance - fee).

 */
int Apply_Fee(int balance, int fee);

/**
 * Computes the total accrued amount (principal + interest) using simple interest formula.
    Assumes 'rate' is a percentage value (e.g., 5 for 5%).

 * @brief          : Calculates the total amount with simple interest.

 * @param principle: The initial amount of money (principal) (integer value).

 * @param rate     : The annual interest rate in percentage (integer value).

 * @param time     : The time period in years (integer value).

 * @return         : int The total amount after applying simple interest (likely rounded to integer).

 */
int Simple_Insert(int principle, int rate, int time);

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
int Compound_Amount(int principle,int APR, int Years, int compounds_per_year);

/**

 * Converts the given amount from the source currency to the target currency.

* @brief               : Converts an amount from one currency to another.

 * @param amount       : The amount of money to convert (integer value).

 * @param from_currency: The source currency code (e.g., "USD") as a string.

 * @param to_currency  : The target currency code (e.g., "EUR") as a string.

 * @return             : int The converted amount in the target currency (integer value).

 */
int Fx_Convert(int amount , std::string from_currency, std::string to_currency);

/**
 * Computes the portion of the original amount that corresponds to the given rate (percentage).
 
 * @brief       : Calculates a given percentage of a numeric value.

 * @param amount: The base value (e.g., total price, quantity) (double value).

 * @param rate  : The percentage rate to apply (e.g., 10 for 10%) (double value).

 * @return      : double The result of the percentage calculation (e.g., 10% of 200.0 = 20.0).

 */
double Percent_of(double amount, double rate);

#endif //_CALCULATOR_HPP_
