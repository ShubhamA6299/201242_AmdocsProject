#include<bits/stdc++.h>


using namespace std;



class validation
{
    public:
    bool check_name(string name)
    {
        if(name[0]<65 || name[0]>90)
        {
            return 0;
        }
        for(int i=1;i<name.length();i++)
        {
            if(name[i]<97 || name[i]>122)
            {
                return 0;
            }
        }
        return 1;
    }
    bool check_mobile(string mb)
    {
        if(mb.length()!=10)
        {
            return 0;
        }
        for(auto &c:mb)
        {
            if(c<48 || c>57)
            {
                return 0;
            }
        }
        return 1;
    }
    bool check_Aadhar(string adh)
    {
        if(adh.length()!=12)
        {
            return 0;
        }
        for(auto &c:adh)
        {
            if(c<48 || c>57)
            {
                return 0;
            }
        }
        return 1;
    }
    bool check_pan(string pan)
    {
        string s1 = pan.substr(0,5);
        string s2 = pan.substr(5,4);

        for(auto &c:s1)
        {
            if(c<65 || c>90)
            {
                return 0;
            }
        }
        for(auto &c:s2)
        {
            if(c<48 || c>57)
            {
                return 0;
            }
        }
        if(pan[pan.length()-1]<65 || pan[pan.length()-1]>90)
        {
            return 0;
        }
        return 1;
    }
};



class BankAccount
{
protected:
    string Account_Numbers;
    string fname,lname,pan,aadhar,mobile_no;
public:
    validation v;
    BankAccount(string AC_NO)
    {
        Account_Numbers = AC_NO;
        cout<<endl;
        while(1)
        {
            cout<<"Enter your first name: ";
            cin>>fname;
            if(v.check_name(fname)==1)
            {
                break;
            }
            else
            {
                cout<<"Wrong name, must have first Capital letter then lowercase letters"<<endl;
            }
        }
        cout<<endl;

        while(1)
        {
            cout<<"Enter your last name: ";
            cin>>lname;
            if(v.check_name(lname)==1)
            {
                break;
            }
            else
            {
                cout<<"Wrong name, must have first Capital letter then lowercase letters"<<endl;
            }
        }
        cout<<endl;

        while(1)
        {
            cout<<"Enter your PAN Card Number: ";
            cin>>pan;
            if(v.check_pan(pan)==1)
            {
                break;
            }
            else
            {
                cout<<"Wrong PAN Number"<<endl;
            }
        }
        cout<<endl;

        while(1)
        {
            cout<<"Enter Your Aadhar Card Number: ";
            cin>>aadhar;
            if(v.check_Aadhar(aadhar)==1)
            {
                break;
            }
            else
            {
                cout<<"Wrong Aadhar Number, must have 12 digits"<<endl;
            }
        }
        cout<<endl;

        while(1)
        {
            cout<<"Enter Your Mobile Number: ";
            cin>>mobile_no;
            if(v.check_mobile(mobile_no)==1)
            {
                break;
            }
            else
            {
                cout<<"Wrong Mobile Number !!!"<<endl;
            }

            cout<<endl<<endl;
        }
        cout<<endl;
        cout<<"Name - "<<fname<<" "<<lname<<endl;
        cout<<"PAN Number - "<<pan<<endl;
        cout<<"Aadhar Number - "<<aadhar<<endl;
        cout<<"Mobile Number - "<<mobile_no<<endl;
    }
};



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
