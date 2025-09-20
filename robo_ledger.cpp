/***************************************        Include Part       ****************************** */
#include "robo_ledger.hpp"
#include <string.h>

/*************************************** Function Definiton Part ****************************** */
extern int Balance;
STD_Return_Type find_account_index(char Accounts[][20],char ID[], size_t Accounts_Num,int *ret)
{
    STD_Return_Type RET = E_OK;
    int flag = 0;

    if((nullptr == ret) || (nullptr == ID) || (Accounts == nullptr))
    {
        RET = E_NOK;
    }
    else
    {
        for(int i=0 ; i<Accounts_Num ; i++)
        {
            if(strcmp(Accounts[i],ID) == 0)
            {
                *ret = i;
                flag=1;
                break;
            }
        }

        if(flag == 0)
        {
            *ret = -1;
        }
    }

    return(RET);
}


STD_Return_Type get_or_create_account(char Accounts[][20], int Balance[MAX_ACCOUNTS],int *Allocated_Accounts_Num,char ID[],int *index)
{
    STD_Return_Type RET = E_OK;
    int flag =0;
    int i = 0;

    if((nullptr == Accounts) || (nullptr == Balance) || (nullptr == index))
    {
        RET = E_NOK;
    }
    else
    {
        for(i=0 ; i< *Allocated_Accounts_Num ; i++)
        {
            if(strcmp(ID,Accounts[i]) == 0)
            {
                flag=1;
                *index = i;
                break;
            }
            else
            {
                
            }

        }
        if(!flag)
        {
            if(i < MAX_ACCOUNTS)
            {
                *index = i;
                strcpy(Accounts[i],ID);
                Balance[i] = 0;
                ++(*Allocated_Accounts_Num); 
            }
        }
    }

    return(RET);
}    


STD_Return_Type apply_one(char Accounts[][20], int Balance[],int Allocated_Accounts_Num, char ID[], char tx_type, int amount)
{
    STD_Return_Type RET = E_OK;
    int index = 0;
    int Choice=0;
    int Check=0;
    int Percente, time,compounds_per_year;

    if((nullptr == Accounts) || (nullptr == Balance))
    {
        RET = E_NOK;
    }
    else
    {
        RET = get_or_create_account(Accounts,Balance,&Allocated_Accounts_Num,ID,&index);
        Check = Balance[index];
        switch(tx_type)
        {
            case '0':
            Balance[index] = Apply_Deposite(Balance[index],amount);
            std::cout<<"Balance Before: "<<Check<<std::endl;
            std::cout<<"Balance After: "<<Balance[index]<<std::endl;
            break;

            case '1':
            Balance[index] = Apply_Withdrawal(Balance[index],amount);
            std::cout<<"Balance Before: "<<Check<<std::endl;
            std::cout<<"Balance After: "<<Balance[index]<<std::endl;
            break;

            case '2':
            Balance[index] = Apply_Fee(Balance[index],amount);
            std::cout<<"Balance Before: "<<Check<<std::endl;
            std::cout<<"Balance After: "<<Balance[index]<<std::endl;
            break;

            case '3':
            do
            {
                std::cout<<"1: Simple Insert.\n";
                std::cout<<"2: Compound Insert.\n";
                std::cout<<"3:Exit.\n";
                std::cout<<"Enter Your Choice: ";
                std::cin>>Choice;

                switch(Choice)
                {
                    case 1:
                    std::cout<<"Enter The Time: ";
                    std::cin>>time;
                    Balance[index] = Simple_Insert(Balance[index],amount,time);
                    std::cout<<"Balance Before: "<<Check<<std::endl;
                    std::cout<<"Balance After: "<<Balance[index]<<std::endl;
                    break;

                    case 2:
                    std::cout<<"Enter The Time: ";
                    std::cin>>time;
                    std::cout<<"Enter the compounds_per_year: ";
                    std::cin>>compounds_per_year;
                    Balance[index] = Compound_Amount(Balance[index],amount,time,compounds_per_year);
                    std::cout<<"Balance Before: "<<Check<<std::endl;
                    std::cout<<"Balance After: "<<Balance[index]<<std::endl;
                    break;

                    case 3:
                    exit(1);
                    break;
                    defualt:
                    std::cout<<"Invalid Input!."<<std::endl;
                    Choice = -1;
                    break;
                }

            } while(Choice == -1);
            break;

            case '4':
            Balance[index] = Apply_Deposite(Balance[index],amount);
            std::cout<<"Balance Before: "<<Check<<std::endl;
            std::cout<<"Balance After: "<<Balance[index]<<std::endl;
            break;

            case '5':
            Balance[index] = Apply_Withdrawal(Balance[index],amount);
            std::cout<<"Balance Before: "<<Check<<std::endl;
            std::cout<<"Balance After: "<<Balance[index]<<std::endl;
            break;
        }
    }

    return(RET);
}

STD_Return_Type apply_all(char Accounts[][20], char tx_type[MAX_Transaction],int tx_amout[], int tx_count, int Current_Accounts_Num,\
                           int Balance[],char tx_accounts_id[][20]) 
{
    STD_Return_Type   RET = E_OK;
    
    if((nullptr == Accounts) || (tx_type == nullptr) || (tx_accounts_id == nullptr) || (nullptr == Balance) || (nullptr == tx_amout))
    {
        RET = E_NOK;
    }
    else
    {
        for(int i=0 ; i< tx_count ; i++)
        {
            RET |= apply_one(Accounts,Balance,Current_Accounts_Num,tx_accounts_id[i],tx_type[i],tx_amout[i]);
        }
    }

    return(RET);
}

STD_Return_Type  balance_of(char Accounts[][20], int Balance[],char ID[],int Current_Accounts_Num, int *Amount)
{
    STD_Return_Type RET = E_OK;
    int index = 0;

    if((nullptr == Accounts) || (nullptr == Balance) || (nullptr == ID))
    {
        RET = E_NOK;
    }
    else
    {
        find_account_index(Accounts,ID,Current_Accounts_Num,&index);
        *Amount = Balance[index];

    }

    return(RET);
}