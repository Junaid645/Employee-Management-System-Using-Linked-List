#include<iostream>
#include<string>
using namespace std;

// class to represent Employee as Node
class Employee {
    public:
       Employee* next;
       int id;
       string name;
       long long contact_no;
       int age;
       float salary;
       string marital_status;
    
    Employee(int employee_id, string emp_name, long long emp_contact_no, int emp_age, float emp_salary, string emp_marital_status){
        id = employee_id;
        name = emp_name;
        contact_no = emp_contact_no;
        age = emp_age;
        salary = emp_salary;
        marital_status = emp_marital_status;
        next = nullptr;

    }


};

// class to represent Linked List
class LinkedList {
private:
    Employee* head;

public:
    LinkedList() {
        head = nullptr;
    }

void add_employee(int employee_id, string emp_name, long long emp_contact_no, int emp_age, float emp_salary, string emp_marital_status){

    Employee* NewEmployee = new Employee(employee_id, emp_name, emp_contact_no, emp_age, emp_salary, emp_marital_status);
    NewEmployee -> next = head;
    head = NewEmployee;
    cout << "Employee added successfully." << endl;

}

// function to remove employee from the list
void Remove_employee(int employee_id) {
        if (head == nullptr) {
            cout << "No Employee in the List." << endl;
            return;
        }

        Employee* temp = head;
        Employee* prev = nullptr;

        if (temp != nullptr && temp->id == employee_id) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->id != employee_id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Employee with Employee_ID " << employee_id << " not found." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "\nEmployee with ID "<< employee_id << " removed." << endl;
    }

// function to update the information of employee
void update_employee_info(int employee_id, string updated_name, long long updated_contact_no, int updated_age, float updated_salary, string updated_marital_status) {
        if (head == nullptr) {
            cout << "No Employee in the List." << endl;
            return;
        }
        Employee* temp = head;

        while (temp != nullptr && temp->id != employee_id) {
            temp = temp->next;
        }
        
        temp->name = updated_name;
        temp->contact_no = updated_contact_no;
        temp->age = updated_age;
        temp->salary = updated_salary;
        temp->marital_status = updated_marital_status;
            
        cout << "\nInformation of Employee with ID: " << employee_id << " updated." << endl;
        
}
// function to display the employees list
void List_of_employees() {
        cout << "\nHere is the Employees List: " << endl;
        Employee* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Contact: " << temp->contact_no << ", Age: " << temp->age << ", Salary: " << temp->salary << ", Marital Status: " << temp->marital_status << endl;
            temp = temp->next;
        }
    }

};

// main starts here
int main() {
    LinkedList myList;
    int choice;
    int id;
    string name;
    long long contact;
    int age;
    float salary;
    string marital_status;

    do {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Remove Employee\n";
        cout << "3. Update Employee Information\n";
        cout << "4. Display List of Employees\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Employee Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Contact Number: ";
                cin >> contact;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Salary: ";
                cin >> salary;
                cout << "Enter Marital Status: ";
                cin >> marital_status;
                myList.add_employee(id, name, contact, age, salary, marital_status);
                break;
            case 2:
                cout << "Enter Employee ID to Remove: ";
                cin >> id;
                myList.Remove_employee(id);
                break;
            case 3:
                cout << "Enter Employee ID to Update: ";
                cin >> id;
                cout << "Enter Updated Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Updated Contact Number: ";
                cin >> contact;
                cout << "Enter Updated Age: ";
                cin >> age;
                cout << "Enter Updated Salary: ";
                cin >> salary;
                cout << "Enter Updated Marital Status: ";
                cin >> marital_status;
                myList.update_employee_info(id, name, contact, age, salary, marital_status);
                break;
            case 4:
                myList.List_of_employees();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
