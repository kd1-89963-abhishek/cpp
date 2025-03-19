#include<iostream>
using namespace std;

class date
{

int day, month, year;

public :

date(){}

void acceptdate()
{
    cout<<"= ";
    cin>>day>>month>>year;
}

void dispDate()
{
    cout<<"= "<<day<<"/"<<month<<"/"<<year<<endl;
}

};

class person
{
char name[10];
char address[20];
date d3;

public :

void enterpdata()
{
    cout<<"Enter the name = ";
    cin>>name;
    cout<<"Enter the address = ";
    cin>>address;
    cout<<"Enter the Date of birth (dd/mm/yyyy)";
    d3.acceptdate();
   

}

void displpdata()
{
    cout<<"The person name = "<<name<<endl;
    cout<<"The address = "<<address<<endl;
    cout<<"The date of birth is";
    d3.dispDate();

}

};


class student
{
int id, marks ;
char course[10];
date d1;
date d2;

public :


void acceptdata()
{
    cout<<"Enter the id : ";
    cin>>id;
    cout<<"Enter the marks : ";
    cin>>marks;
    cout<<"Enter the course :";
    cin>>course;
    cout<<"Enter the joining date (dd/mm/yyy)";
    d1.acceptdate();
    cout<<"Enter the ending date (dd/mm/yyyy)";
    d2.acceptdate();

}
void displaydata()
{
    cout<<"The student id = "<<id<<endl;
    cout<<"The marks is = "<<marks<<endl;
    cout<<"The choosen course is = "<<course<<endl;
    cout<<"The join date ";
    d1.dispDate();
    cout<<"The end date ";
    d2.dispDate();

}

};

int main()
{
    
    student s1;
    person p1;
    int a=0;
do
   {
  cout<<"enter 0 to exit"<<endl;
  cout<<"enter 1 to accept Student data"<<endl;
  cout<<"enter 2 to display student data"<<endl;
  cout<<"Enter 3 to accept person data"<<endl;
  cout<<"Enter 4 to display person data"<<endl;
  cout<<"please enter the input"<<endl;
  cin>>a;
    if(a==1)
    {
    s1.acceptdata();
    //  break;
    }
    else if (a==2)
    {
    s1.displaydata();
    }
    else if(a==3)
    {
        p1.enterpdata();
    }
    else if(a==4)
    {
        p1.displpdata();
    }
    else if(a==0)
    {
        cout<<"Exit------"<<endl;
    }
    else
    cout<<"wrong input---------!!!"<<endl;
   }while (a!=0);
   cout<<"thanks for choosing us-----------"<<endl;

   return 0;
}