#include<bits/stdc++.h>
using namespace std;

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
