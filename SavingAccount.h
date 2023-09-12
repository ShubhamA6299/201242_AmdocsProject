#include<bits/stdc++.h>
using namespace std;

class SavingAccount : public BankAccount
    {
        int Saving_account_balance;
    public:
        SavingAccount(string acn,int sab):BankAccount(acn)
        {
            Saving_account_balance = sab;
        }
        int withdrawl(int amount)
        {
            if(amount<0)
            {
                cout<<"Wrong amount entered"<<endl;
                return 0;
            }
            if(Saving_account_balance-amount>=5000)
            {
                Saving_account_balance = Saving_account_balance - amount;
                cout<<"You have withdrawl "<<amount<<endl;
                cout<<"Saving Account balance is - "<<Saving_account_balance<<endl;
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
            Saving_account_balance = Saving_account_balance + amount;
            cout<<"You have depositted "<<amount<<endl;
            cout<<"Saving Account balance is - "<<Saving_account_balance<<endl;
        }
        int interest(int amount)
        {
            Saving_account_balance *= (1+amount/100);
            return Saving_account_balance;
        }
        int BalanceInquiry()
        {
            return Saving_account_balance;
        }
    };
