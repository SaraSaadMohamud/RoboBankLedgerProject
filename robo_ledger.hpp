#ifndef _REBO_LEDGER_HPP_
#define _REBO_LEDGER_HPP_

/***************************************        Include Part       ****************************** */
#include"Calculator.hpp"

/***************************************         Macros Part      ****************************** */
#define MAX_ACCOUNTS      100
#define MAX_Transaction  100

#define E_OK              1
#define E_NOK             0

#define TX_DEPOSITE       0
#define TX_WITHDRAWAL     1
#define TX_FEE            2
#define TX_INTEREST       3
#define TX_TRANSFERIN     4
#define TX_TRANSFEROUT    5

/***************************************      Data Types Part     ****************************** */
typedef char              STD_Return_Type;

/*************************************** Function Prototypes Part ****************************** */
/**
 * Searches for a specific account ID within the accounts array and returns its index.
 *
 * @brief         : Finds the index of an account by its ID.
 *
 * @param Accounts: A 2D array containing account IDs (each ID is up to 20 characters).
 *
 * @param ID      : The account ID to search for (string).
 *
 * @param Accounts_Num: The total number of accounts in the array.
 *
 * @param ret     : Pointer to an integer where the found index will be stored. 
 *                  If not found, it should be set to -1.
 *
 * @return       : STD_Return_Type indicating success or failure of the operation.
 */
STD_Return_Type find_account_index(char Accounts[][20], char ID[], size_t Accounts_Num, int *ret);


/**
 * Retrieves the index of an existing account by ID, or creates a new account if not found.
 *
 * @brief                        : Gets an existing account or creates a new one if it doesn't exist.
 *
 * @param Accounts               : A 2D array that holds all account IDs.
 *
 * @param Balance                : An array holding the balance of each account.
 *
 * @param Allocated_Accounts_Num : Pointer to an integer representing the number of active accounts.
 *                                 This will be incremented if a new account is created.
 *
 * @param ID                     : The account ID to look for or create.
 *
 * @param index                  : Pointer to an integer where the account index will be stored.
 *
 * @return                       : STD_Return_Type indicating whether the operation was successful.
 */

STD_Return_Type get_or_create_account(char Accounts[][20], int Balance[MAX_ACCOUNTS], int *Allocated_Accounts_Num, char ID[], int *index);


/**
 * Applies a single transaction (deposit or withdrawal) to a specific account.
 *
 * @brief                        : Processes a single financial transaction on an account.
 *
 * @param Accounts               : A 2D array containing all account IDs.
 *
 * @param Balance                : An array containing the balance of each account.
 *
 * @param Allocated_Accounts_Num : The total number of active accounts currently allocated.
 *
 * @param ID                     : The account ID to apply the transaction to.
 *
 * @param tx_type                : The type of transaction ('D' for Deposit, 'W' for Withdrawal, etc.).
 *
 * @param amount                 : The amount to deposit or withdraw.
 *
 * @return       : STD_Return_Type indicating success or failure of the transaction.
 */
STD_Return_Type apply_one(char Accounts[][20], int Balance[], int Allocated_Accounts_Num, char ID[], char tx_type, int amount);


/**
 * Applies a batch of transactions to their respective accounts.
 *
 * @brief        : Processes multiple transactions in one call.
 *
 * @param Accounts             : A 2D array of all account IDs.
 *
 * @param tx_type              : An array of transaction types for each transaction.
 *
 * @param tx_amout             : An array of transaction amounts (Note: likely a typo, should be tx_amount[]).
 *
 * @param tx_count             : The number of transactions to process.
 *
 * @param Current_Accounts_Num : The current number of active accounts.
 *
 * @param Balance              : An array holding the balance of each account.
 *
 * @param tx_accounts_id       : A 2D array containing the account IDs involved in each transaction.
 *
 * @return                     : STD_Return_Type indicating the overall result of applying the transactions.
 */
STD_Return_Type apply_all(char Accounts[][20], char tx_type[MAX_Transaction], int tx_amout[], int tx_count, int Current_Accounts_Num,
                         int Balance[], char tx_accounts_id[][20]);


/**
 * Retrieves the balance of a specific account by its ID.
 *
 * @brief                      : Gets the current balance of an account.
 *
 * @param Accounts             : A 2D array containing all account IDs.
 * 
 * @param Balance              : An array containing the balance of each account.
 *
 * @param ID                   : The account ID to look up.
 *
 * @param Current_Accounts_Num : The total number of accounts available.
 *
 * @param Amount               : Pointer to an integer where the retrieved balance will be stored.
 *
 * @return                      : STD_Return_Type indicating whether the account was found and balance retrieved.
 */
STD_Return_Type  balance_of(char Accounts[][20], int Balance[],char ID[],int Current_Accounts_Num,int *Amount);



/**
 * Generates a summary of the bank's accounts and transactions.
 *
 * @brief                      : Provides a summary related to the bank accounts and their transactions.
 *
 * @param Array                : (Possibly intended to be Accounts[][]) - Array of account IDs (clarify usage).
 *
 * @param Balance              : An array containing the balance of each account.
 *
 * @param tx_type              : (Possibly unused) The type of transaction or filter (clarify purpose).
 *
 * @param tx_amout             : (Possibly unused) Array of transaction amounts (clarify usage).
 *
 * @param tx_count             : The number of transactions involved (if applicable).
 *
 * @param Current_Accounts_Num : The total number of active accounts.
 *
 * @param current_ID           : The ID of a specific account to focus on in the summary (optional).
 *
 * @return                     : STD_Return_Type indicating the success of generating the summary.
 */
STD_Return_Type bank_summary(char Accounts[][20], int Balance[], char tx_type[MAX_Transaction], int tx_amout[],
                             int Current_Accounts_Num, char tx_accounts_id[][20]);
                             
/*************************************** Function Prototypes Part ****************************** */


#endif //_REBO_LEDGER_HPP_
