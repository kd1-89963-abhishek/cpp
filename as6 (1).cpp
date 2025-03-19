#include<iostream>
using namespace std;

class product
{

    int id;
    char title[20];
    public:

    virtual void inputData()
    {
        cout<<"Enter the id = ";
        cin>>id;
       
        cout<<"Enter the title of product = ";
        cin>>title;
        
    }
   virtual void dispData()
    {
        cout<<"The product id = "<<id<<endl;
        cout<<"The product title is = "<<title<<endl;
    }


};

class book: public product
{

    char author[20];
    float price,bill;
    public:
    void inputData()
    {
        cout<<"Enter the authors name = ";
        cin>>author;
        cout<<"Enter price of the product is = ";
        cin>>price;
        product::inputData();
    }
    void calc()
    {
        
        cout<<"The bill is "<<(price-(price*0.05))<<endl;

    }

    void dispData()
    {
        cout<<"The authors name = "<<author<<endl;
        product::dispData();
        cout<<"The product price is = "<<price<<endl;
        calc();
        
    }
};

class tape: public product
{
    char artist[20];
    float price;
    public:
    void inputData()
    {
        cout<<"Enter the artists name = ";
        cin>>artist;
        cout<<"Enter price of the product is = ";
        cin>>price;
        product::inputData();

    }
    void calc()
    {
        
        cout<<"The bill is = "<<(price-(price*0.1))<<endl;

    }
    void dispData()
    {
        cout<<"The artists name is = "<<artist<<endl;
        product::dispData();
        cout<<"The product price is = "<<price<<endl;
        calc();
    }

};

int main()
{

    int choice;
    int index=0;
    product *ptr[3];
    do
    {

    cout<<"0 to exit--------------------->>"<<endl;
    cout<<"1. Enter the book data-------->>"<<endl;
    cout<<"2. Enter the tape data-------->>"<<endl;
    cout<<"3. display the total bill----->>"<<endl;
    cout<<"Enter the input--------------->>"<<endl;
    cin>>choice;

    switch (choice)
    {
    case 1:
    if(index<3)
    {
        ptr[index] = new book();
        ptr[index]->inputData();
        index++;
    }
    else 
    cout<<"Index if full"<<endl;
    break;
    case 2:
    if(index<3)
    {
        ptr[index] = new tape();
        ptr[index]->inputData();
        index++;
    }
    else
    cout<<"Index if full"<<endl;
        break;

    case 3:
     {
        for(int i=0;i<3;i++)
        {
        ptr[i]->dispData();
        }
     }
        break;
    case 0:
        cout<<"Exit...........>>>>>>"<<endl;
        break;
    default:
        cout<<"Wrong input--------->>>";
    }
    }
    while(choice!=0);

    delete[] ptr;
    ptr[3]=NULL;
    
    return 0;
}