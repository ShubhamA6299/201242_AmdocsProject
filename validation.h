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
