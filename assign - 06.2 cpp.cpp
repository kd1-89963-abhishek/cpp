/*
*  Assignment - 6

*  Q2. Implement following classes. 
*  Test all functionalities in main() of each created class. 
*  Note that employee is inherited into manager and salesman. 

*/

#include <iostream> 
using namespace std; 


class Employee  {
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
        cout << "Enter Salary : "; 
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
        cout << "Enter bonus : "; 
        cin >> bonus; 
    }
    void display() {
        Employee::display(); 
        cout << "Bonus : " << bonus << endl;
    }

protected : 
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
    void display() {
        Employee::display(); 
        displaySalesman();
    }

protected : 
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
    SalesManager(int id, double salary, double bonus, double commission)  {
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

void case1() {
    Employee e;
    e.accept();
    e.display();  
}

void case2() {
    Manager m;
    m.accept();
    m.display();
}

void case3() {
    Salesman s; 
    s.accept();
    s.display();
}

void case4() {
    SalesManager sm; 
    sm.accept();
    sm.display();
}

void case5() {
    Employee *eptr = new Employee();
    eptr -> accept(); 
    eptr -> display();
    
    delete eptr;
    eptr = NULL; 
}

void case6() {
    Employee *eptr = new Manager();
    eptr -> accept(); 
    eptr -> display();
    
    delete eptr;
    eptr = NULL; 
}

void case7() {
    Employee *eptr = new Salesman();
    eptr -> accept();
    eptr -> display(); 
    
    delete eptr; 
    eptr = NULL;
}

void case8() {
    Employee *eptr = new SalesManager();
    eptr -> accept(); 
    eptr -> display();

    delete eptr;
    eptr = NULL;
}


int main() {
    // case1();
    // case2();
    // case3();
    // case4();
    // case5();
    // case6();
    // case7();
    case8();

    return 0; 
}
