/**********************************   Include Part    ********************************** */
#include <iostream>
#include <cstdlib>
#include <chrono> 
#include <thread>
#include "Calculator.hpp"
#include "robo_ledger.hpp"

/***************************************   Global Variables Part  ****************************** */

char Accounts_IDs[MAX_ACCOUNTS][20] = {"CHK-001", "SAV-010", "CHK-002","cv-100","CV-100"};
int  Balance[MAX_ACCOUNTS] = {10000,20000,30000,1000,5000};
int Current_Accounts = 5;

char TX_ACccounts_ID[MAX_Transaction][20];
char TX_Types_[MAX_Transaction];
int  TX_Ammount_Cents[MAX_Transaction];

int balance,amount,Time, fee,rate,years,compounds_per_year;
double money,percent;

/******************************** Function Prototypes ******************************** */
static void Show(int count);

/********************************    Main function    **********************************/
int main()
{
    int User_Choice = 0;
    char ID[20];
    int Out =0;
    int Balance_;
    char action = 0;
    char Tx_Types=0;
    int tx_count=0;
    int Exit = 0;
    int amount = 0;
    int balance_of_ = 0;
    int i=0;
    int Ret = E_OK;

    std::cout<<"\t\t\tRoboLedger "<<std::endl;
    do
    {
        
        std::cout<<"Main Manue";
        Show(10);
        std::cout<<"\n1: find_account_index\n";
        std::cout<<"2: get_or_create_account\n";
        std::cout<<"3: apply_one\n";
        std::cout<<"4: apply_all\n";
        std::cout<<"5: balance_of\n";
        std::cout<<"6: bank_summary\n";
        std::cout<<"7: Exit\n";

        std::cout<<"Enter Your Choice: ";
        std::cin>>User_Choice;

        std::cout<<"Wait";
        Show(25);
        system("cls");

        switch(User_Choice)
        {
            case 1:
            std::cout<<"Enter Your Account ID: ";
            std::cin>>ID;
            Ret = find_account_index(Accounts_IDs,ID, Current_Accounts,&Out);
            if(Ret)
            {
                std::cout<<Out<<std::endl;
            }
            else
            {
                std::cout<<"-1\n";
            }
            
            Show(50);
            system("cls");
            break;

            case 2:
            std::cout<<"Enter The Account ID: ";
            std::cin>>ID;
            Ret = get_or_create_account(Accounts_IDs,Balance,&Current_Accounts,ID,&Out);
            if(Ret)
            {
                std::cout<<Out<<std::endl;
            }
            else
            {
                std::cout<<"-1\n";
            }
            break;

            case 3:
            std::cout<<"Enter The Account ID: ";
            std::cin>>ID;
            std::cout<<"Tx Types";
            Show(10);
            std::cout<<"\n0:Deposit.\n";
            std::cout<<"1:Withdrawal.\n";
            std::cout<<"2:Fee.\n";
            std::cout<<"3:Interest.\n";
            std::cout<<"4:TransferIn.\n";
            std::cout<<"5:TransferOut.\n";
            std::cout<<"Enter Your Choice: ";
            std::cin>>Tx_Types;
            std::cout<<"Enter Amount: ";
            std::cin>>amount;
            Show(25);
            system("cls");
            
            Ret = apply_one(Accounts_IDs,Balance,Current_Accounts,ID,Tx_Types,amount);
            break;

            case 4:
            
            for( i=0 ; i>=0 ; i++)
            {
                std::cout<<"Enter ID: ";
                std::cin>> TX_ACccounts_ID[i];
                std::cout<<"Enter Tx_Type: ";
                std::cin>>TX_Types_[i];
                std::cout<<"Enter Amount: ";
                std::cin>>TX_Ammount_Cents[i];
                tx_count++;
                std::cout<<"Enter[1] to Add Another Transaction: ";
                std::cin>>Exit;
                if(!Exit)break;   
            }
            Show(25);
            system("cls");
            Ret = apply_all(Accounts_IDs,TX_Types_,TX_Ammount_Cents,tx_count,Current_Accounts,Balance,TX_ACccounts_ID);
            Show(50);
            system("cls");
            break;

            case 5:
            std::cout<<"Enter Your Account ID: ";
            std::cin>>ID;

            Ret = balance_of(Accounts_IDs,Balance,ID,Current_Accounts,&balance_of_);
            std::cout<<balance_of_<<std::endl;
            Show(50);
            system("cls");

            break;

            case 6:
            std::cout<<"I Will Add it Soon!.\n";
            Show(50);
            system("cls");
            break;

            case 7:
            exit(1);
            break;

            default:
            break;
        }

        std::cout<<"Enter [1] to Exit: ";
        std::cin>>action;

    } while (action != '1');
    
    
    return(0);
}
/*********************************** Static Function ************************************ */
static void Show(int count)
{
    for(int i = 0 ;i<count ; i++)
    {
        std::cout<<".";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}