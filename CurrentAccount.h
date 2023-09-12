#include<bits/stdc++.h>

using namespace std;


    class CurrentAccount : public BankAccount
    {
        int current_account_balance;
    public:
        CurrentAccount(string acn,int cab):BankAccount(acn)
        {
            current_account_balance = 0;
        }
        int withdrawl(int amount)
        {
            if(amount<0)
            {
                cout<<"Wrong amount entered"<<endl;
                return 0;
            }
            if(current_account_balance-amount>=5000)
            {
                current_account_balance = current_account_balance - amount;
                cout<<"You have withdrawl "<<amount<<endl;
                cout<<"Current Account balance is - "<<current_account_balance<<endl;
                return 1;
            }
            cout<<"Insufficient balance"<<endl;
            return 0;

        }
        void deposit(int amount)
        {
            if(amount<0)
            {
                cout<<"Wrong amount entered"<<endl;
                return ;
            }
            current_account_balance = current_account_balance + amount;
            cout<<"You have depositted "<<amount<<endl;
            cout<<"Current Account balance is "<<current_account_balance<<endl;
        }

        int BalanceInquiry()
        {
            return current_account_balance;
        }
    };
