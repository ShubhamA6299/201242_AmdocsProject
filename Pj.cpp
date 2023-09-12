#include<bits/stdc++.h>
#include "validation.h"
#include "BankAccount.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"

using namespace std;


    int main()
    {
        cout<<"Hello, Welcome to MyBank"<<endl;

        vector<SavingAccount> a1;
        vector<CurrentAccount> a2;
        map<string,int> mp1;
        map<string,int> mp2;


        SavingAccount sa1("SA101", 5000);

        a1.push_back(sa1);
        mp1["SA101"]=0;
        // SavingAccount sa2("SA102", 5000);
        // SavingAccount sa3("SA103",5000);
        // SavingAccount sa4("SA104", 5000);
        // SavingAccount sa5("SA105", 5000);


        CurrentAccount ca1("CA101", 0);
        a2.push_back(ca1);
        mp2["CA101"]=0;

        //mp2["CA101"]=ca1;
        // CurrentAccount ca2("CA102", 0);
        // CurrentAccount ca3 ("CA103",e);
        // CurrentAccount ca4("CA184",e);
        // CurrentAccount ca5("CA185", 0);
        //cal.deposite (5000);
        //cal.withdrawl(2300);

        int n;

        string accNo,ac2;
        cout<<"Enter your Account Number"<<endl;
        cin>>accNo;

        int money;

        if(mp1.find(accNo)==mp1.end() && mp2.find(accNo)==mp2.end())
        {
            cout<<"Wrong account number"<<endl;
        }
        if(mp1.find(accNo)!=mp1.end())
        {
            while(1)
            {
                cout<<"Select from the following options for banking operations"<<endl;
                cout<<"1. Withdraw Money"<<endl;
                cout<<"2. Deposit Money"<<endl;
                cout<<"3. Bank Transfer"<<endl;
                cout<<"4. Interest amount"<<endl;
                cout<<"5. Check Balance"<<endl;
                cout<<"0. Exit "<<endl;
                cin>>n;
                if(n==0)
                {
                    break;
                }
                switch(n)
                {
                case 1:
                    cout<<"Enter money to be withdrawn"<<endl;
                    cin>>money;
                    a1[mp1[accNo]].withdrawl(money);
                    //mp1[accNo].BalanceInquiry();
                    break;

                case 2:
                    cout<<"Enter money to be deposited"<<endl;
                    cin>>money;
                    a1[mp1[accNo]].deposit(money);
                    //mp1[accNo].BalanceInquiry();
                    break;

                case 3:
                    cout<<"Enter account in which you want to transfer"<<endl;
                    cin>>ac2;
                    if(mp1.find(ac2)==mp1.end()&& mp2.find(ac2)==mp2.end())
                    {
                        cout<<"Wrong account number"<<endl;
                    }
                    else
                    {
                        if(mp1.find(ac2)!=mp1.end())
                        {
                            cout<<"Enter amount to be transferred"<<endl;
                            cin>>money;
                            int f = a1[mp1[accNo]].withdrawl(money);
                            if (f==1)
                            {
                                a1[mp1[ac2]].deposit(money);
                            }
                        }
                        else if(mp2.find(ac2)!=mp2.end())
                        {
                            cout<<"Enter amount to be transferred"<<endl;
                            cin>>money;
                            int f = a1[mp1[accNo]].withdrawl(money);
                            if (f==1)
                            {
                                a2[mp2[ac2]].deposit(money);
                            }
                        }
                    }
                    break;
                case 4:
                    cout<<"Balance after interest "<<a1[mp1[accNo]].interest(12)<<endl;
                    break;
                case 5:
                    cout<<"Current balance is "<<a1[mp1[accNo]].BalanceInquiry()<<endl;
                    break;
                case 0:
                    break;
                default:
                    cout<<"Wrong input"<<endl;
                    break;
                }
            }

        }
        else
        {
            while(1)
            {
                cout<<"Select from the following options for banking operations"<<endl;
                cout<<"1. Withdraw Money"<<endl;
                cout<<"2. Deposit Money"<<endl;
                cout<<"3. Bank Transfer"<<endl;
                cout<<"4. Check Balance"<<endl;
                cout<<"0. Exit "<<endl;
                cin>>n;
                if(n==0)
                {
                    break;
                }
                switch(n)
                {
                case 1:
                    cout<<"Enter money to be withdrawn"<<endl;
                    cin>>money;
                    a2[mp2[accNo]].withdrawl(money);
                    //mp1[accNo].BalanceInquiry();
                    break;

                case 2:
                    cout<<"Enter money to be deposited"<<endl;
                    cin>>money;
                    a2[mp2[accNo]].deposit(money);
                    //mp1[accNo].BalanceInquiry();
                    break;

                case 3:
                    cout<<"Enter account in which you want to transfer"<<endl;
                    cin>>ac2;
                    if(mp2.find(ac2)==mp2.end() && mp1.find(ac2)==mp1.end())
                    {
                        cout<<"Wrong account number"<<endl;
                    }
                    else
                    {
                        if(mp1.find(ac2)!=mp1.end())
                        {
                            cout<<"Enter amount to be transferred"<<endl;
                            cin>>money;
                            int f = a1[mp1[accNo]].withdrawl(money);
                            if (f==1)
                            {
                                a1[mp1[ac2]].deposit(money);
                            }
                        }
                        else if(mp2.find(ac2)!=mp2.end())
                        {
                            cout<<"Enter amount to be transferred"<<endl;
                            cin>>money;
                            int f = a2[mp2[accNo]].withdrawl(money);
                            if (f==1)
                            {
                                a2[mp2[ac2]].deposit(money);
                            }
                        }
                    }
                    break;
                case 4:
                    cout<<"Current balance is "<<a2[mp2[accNo]].BalanceInquiry()<<endl;
                    break;
                case 0:

                    break;
                default:
                    cout<<"Wrong input"<<endl;
                    break;
                }
            }

        }



    }
