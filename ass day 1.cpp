#include<iostream>
#include<stdio.h>

 using namespace std;

 struct Time
 {
     int day;
     int mnth;
     int yr;
 };

 void printDateOnConsole(struct Time *ptrDate)
 {
     cout<<"day :"<<ptrDate->day<<endl;
     cout<<"Month :"<<ptrDate->mnth<<endl;
     cout<<"year :"<<ptrDate->yr<<endl;
 }
 void acceptDateOnConsole(struct Time *ptrDate)
 {
     cout<<"enter the day :"<<endl;
     cin>>ptrDate->day;
     cout<<"enter the Month :"<<endl;
     cin>>ptrDate->mnth;
     cout<<"enter the year :"<<endl;
     cin>>ptrDate->yr;
 }
     

     int main()
    {
        struct Time t1;
        acceptDateOnConsole(&t1);
        printDateOnConsole(&t1);
        return 0;
    }