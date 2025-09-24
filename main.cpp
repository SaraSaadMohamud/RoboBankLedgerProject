/**********************************   Include Part    ********************************** */
#include <iostream>
#include <cstdlib>
#include <chrono> 
#include <thread>
#include <memory>  
#include <string>    
#include <cstring>
#include "Calculator.hpp"
#include "robo_ledger.hpp"

/***************************************   Global Variables Part  ****************************** */
auto Accounts_IDs     = std::shared_ptr<char[][20]>(new char[MAX_ACCOUNTS][20]);
auto Balance          = std::shared_ptr<int[]>(new int[MAX_ACCOUNTS]);

int  Current_Accounts = 5;

auto TX_ACccounts_ID  = std::shared_ptr<char[][20]>(new char[MAX_Transaction][20]);
auto TX_Types_        = std::shared_ptr<char[]>(new char[MAX_Transaction]);
auto TX_Ammount_Cents = std::shared_ptr<int[]>(new int[MAX_Transaction]);

 int tx_count=0;

/******************************** Function Prototypes ******************************** */
static void Show(int count);

/********************************    Main function    **********************************/
int main()
{
    int User_Choice = 0;
    char ID[20];
    int Out =0;
    char action = 0;
    char Tx_Types=0;
    int Exit = 0;
    int amount = 0;
    int balance_of_ = 0;
    int i=0;
    int Ret = E_OK;

    
    strcpy(Accounts_IDs.get()[0], "CHK-001");
    strcpy(Accounts_IDs.get()[1], "SAV-010");
    strcpy(Accounts_IDs.get()[2], "CHK-002");
    strcpy(Accounts_IDs.get()[3], "cv-100");
    strcpy(Accounts_IDs.get()[4], "CV-100");

    Balance.get()[0] = 10000;
    Balance.get()[1] = 20000;
    Balance.get()[2] = 30000;
    Balance.get()[3] = 1000;
    Balance.get()[4] = 5000;

    std::cout<<"\t\t\tRoboLedger "<<std::endl;
    do
    {
        std::cout<<"Main Menu";
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
            Ret = find_account_index(Accounts_IDs.get(), ID, Current_Accounts, &Out);
            std::cout<<Out<<std::endl;

            case 2:
            std::cout<<"Enter The Account ID: ";
            std::cin>>ID;
            Ret = get_or_create_account(Accounts_IDs.get(), Balance.get(), &Current_Accounts, ID, &Out);
            std::cout<<Out<<std::endl;

            case 3:
            std::cout<<"Enter The Account ID: ";
            std::cin>>ID;
            std::cout<<"Tx Types\n0:Deposit\n1:Withdrawal\n2:Fee\n3:Interest\n4:TransferIn\n5:TransferOut\n";
            std::cin>>Tx_Types;
            std::cout<<"Enter Amount: ";
            std::cin>>amount;
            apply_one(Accounts_IDs.get(), Balance.get(), Current_Accounts, ID, Tx_Types, amount);
            break;

            case 4:
            for(i=0 ; i>=0 ; i++)
            {
                std::cout<<"Enter ID: ";
                std::cin>> TX_ACccounts_ID.get()[i];
                std::cout<<"Enter Tx_Type: ";
                std::cin>>TX_Types_.get()[i];
                std::cout<<"Enter Amount: ";
                std::cin>>TX_Ammount_Cents.get()[i];
                tx_count++;
                std::cout<<"Enter[1] to Add Another Transaction: ";
                std::cin>>Exit;
                if(!Exit)break;   
            }
            apply_all(Accounts_IDs.get(), TX_Types_.get(), TX_Ammount_Cents.get(), tx_count,
                            Current_Accounts, Balance.get(), TX_ACccounts_ID.get());
            break;

            case 5:
            std::cout<<"Enter Your Account ID: ";
            std::cin>>ID;
            balance_of(Accounts_IDs.get(), Balance.get(), ID, Current_Accounts, &balance_of_);
            std::cout<<balance_of_<<std::endl;
            break;

            case 6:
            bank_summary(Accounts_IDs.get(), Balance.get(), TX_Types_.get(), TX_Ammount_Cents.get(),
                   Current_Accounts, TX_ACccounts_ID.get());
            break;

            case 7:
            exit(1);
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
