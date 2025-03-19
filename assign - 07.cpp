/*
*  Assignment - 7

*  Q1. Provide menu driven code for the functionalities: 
*    1. Add Manager 
*    2. Add Salesman 
*    3. Add Salesmanager 
*    4. Display the count of all employees with respect to designation 
*    5. Display All Managers 
*    6. Display All Salesman 
*    7. Display All SalesManagers 
*/


#include <iostream> 
using namespace std; 

class Employee {
    int id; 
    double salary; 

public : 
    Employee() {

    }
    Employee(int id, double salary) {
        this->id = id; 
        this->salary = salary; 
    }
    void setId(int id) {
        this->id = id;
    }
    int getId() {
        return id;
    }
    void setSalary(double salary) {
        this->salary = salary; 
    }
    double getSalary() {
        return salary; 
    }
    virtual void accept() {
        cout << "Enter ID : "; 
        cin >> id; 
        cout << "Enter salary : "; 
        cin >> salary; 
    }
    virtual void display() {
        cout << "ID : " << id << endl;
        cout << "Salary : " << salary << endl;
    }
};



class Manager : virtual public Employee {
    double bonus; 

public : 
    Manager() {

    }
    Manager(int id, double salary, double bonus) : Employee(id, salary) {
        this->bonus = bonus; 
    }
    void setBonus(double bonus) {
        this->bonus = bonus; 
    }
    double getBonus() {
        return bonus; 
    }
    void accept() {
        Employee::accept(); 
        acceptManager();
    }
    void display() {
        Employee::display();
        displayManager();
    }
    void acceptManager() {
        cout << "Enter bonus : ";
        cin >> bonus; 
    }
    void displayManager() {
        cout << "Bonus : " << bonus << endl;
    }
};



class Salesman : virtual public Employee {
    double commission; 

public : 
    Salesman() {

    }
    Salesman(int id, double salary, double commission) : Employee(id, salary) {
        this->commission = commission; 
    }
    void setCommission(double commission) {
        this->commission = commission; 
    }
    double getCommission() {
        return commission; 
    }
    void accept() {
        Employee::accept();  
        acceptSalesman();
    }
    void display(){
        Employee::display(); 
        displaySalesman(); 
    }
    void acceptSalesman() {
        cout << "Enter commission : "; 
        cin >> commission;
    }
    void displaySalesman() {
        cout << "Commission : " << commission << endl;
    }
};



class SalesManager : public Manager, public Salesman {
public : 
    SalesManager() {

    }
    SalesManager(int id, double salary, double bonus, double commission) {
        Employee::setId(id); 
        Employee::setSalary(salary);
        Manager::setBonus(bonus);
        Salesman::setCommission(commission);
    }
    void accept() {
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }
    void display() {
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};



int menu() {
    int choice; 
    cout << "**************************************************" << endl; 
    cout << "0. Exit" << endl;
    cout << "1. Add Manager" << endl; 
    cout << "2. Add Salesman" << endl; 
    cout << "3. Add Salesmanager" << endl;
    cout << "4. Display the count of all employees with respect to designation" << endl;
    cout << "5. Display all Managers" << endl;
    cout << "6. Display all Salesman" << endl; 
    cout << "7. Display all SalesManagers" << endl; 
    cout << "Enter choice : "; 
    cin >> choice; 
    cout << "**************************************************" << endl; 
    return choice;
}

int main() {
    int choice; 
    int index = 0; 
    int mgrCount = 0;
    int sCount = 0;
    int smCount = 0;
    Employee *employeeList[5]; 

    while((choice=menu()) != 0) {
        switch(choice) {
            case 1 :
                if (index < 5) {
                    employeeList[index] = new Manager();
                    employeeList[index] -> accept(); 
                    index++; 
                }
                else {
                    cout << "Array got full ..." << endl;
                }
                break;

            case 2 : 
                if (index < 5) {
                    employeeList[index] = new Salesman();
                    employeeList[index] -> accept(); 
                    index++; 
                }
                else {
                    cout << "Array got full ..." << endl;
                }
                break;

            case 3 : 
                if (index < 5) {
                    employeeList[index] = new SalesManager();
                    employeeList[index] -> accept(); 
                    index++; 
                }
                else {
                    cout << "Array got full ..." << endl;
                }
                break; 

            case 4 : 
                for(int i=0; i<index; i++) {
                    if(typeid(*employeeList[i]) == typeid(Manager)) {
                        mgrCount++;
                    }
                    if(typeid(*employeeList[i]) == typeid(Salesman)) {
                        sCount++;
                    }
                    if(typeid(*employeeList[i]) == typeid(SalesManager)) {
                        smCount++;
                    }
                }
                cout << "Number of Managers = " << mgrCount << endl; 
                cout << "Number of Salesmen = " << sCount << endl; 
                cout << "Number of Sales Managers = " << smCount << endl; 
                break;

            case 5 : 
                for(int i=0; i<index; i++) {
                    if(typeid(*employeeList[i]) == typeid(Manager)) {
                        employeeList[i] -> display(); 
                    }
                }
                break;
                
            case 6 : 
                for(int i=0; i<index; i++) {
                    if(typeid(*employeeList[i]) == typeid(Salesman)) {
                        employeeList[i] -> display(); 
                    }
                }
                break;
            
            case 7 : 
                for(int i=0; i<index; i++) {
                    if(typeid(*employeeList[i]) == typeid(SalesManager)) {
                        employeeList[i] -> display(); 
                    }
                }
                break;

            default : 
                cout << "Wrong choice !" << endl;
            
        }
    }
    for(int i=0; i<index; i++) {
        delete employeeList[i]; 
        employeeList[i] = NULL; 
    }

    return 0; 
}
