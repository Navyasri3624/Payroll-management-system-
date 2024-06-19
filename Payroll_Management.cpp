
//Include All Header files.
#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
int adi=1;
using namespace std;
class Payroll_management
{
private:
    // Variables for employee details
    char name[30];
    char id[5];
    char designation[10];
    int age;
    float ctc;
    char experience[20];
    int pay;
public:
    void menu();
    void waitForEnter();
    void insert();
    void display();
    void modify();
    void search();
    void payslip();
    void deleted();
};
void Payroll_management::payslip(){
    system("cls");
    fstream file;
    float hra=800,da,intax,netsalary;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Payslip Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    char checkid[5];
    cout << "\nEnter employee id: ";
    cin >> checkid;
    if(!file){
        cout << "\n\t\t\tNo Data is Present... ";
    }
    else{
        file >> name >> id >> designation >> age >> ctc >> experience;
       while(!file.eof()){
            if(strcmp(checkid,id)==0){
               netsalary=ctc+hra+0.25*(float)ctc-0.15*(float)ctc;
               cout<<"Hra           :"<<hra<<endl;
               cout<<"Da            :"<<0.25*(float)ctc<<endl;
               cout<<"Income Tax    :"<<0.15*(float)ctc<<endl;
               cout<<"Net Salary    :"<<netsalary<<endl;
               break;
            }
            else{
                cout<< "\n\n\tEmployee ID Not matched"<<endl;

            }
            file >> name >> id >> designation >> age >> ctc >> experience;
       }

    }
    file.close();
    waitForEnter();

}
void Payroll_management::menu() //Project Menu
{
    int password_user(); //login declaration
    password_user();
    //login screen
    while (true)
    {
        int choice;
        char x; // Options to choose an action
        system("cls");
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t-> PAYROLL MANAGEMENT SYSTEM <-" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1) Enter new Employee Record" << endl;
        cout << "\t\t\t\t\t 2) Display list of Employee Record" << endl;
        cout << "\t\t\t\t\t 3) Modify Employee Record" << endl;
        cout << "\t\t\t\t\t 4) Search Employee Record" << endl;
        cout << "\t\t\t\t\t 5) Delete Employee Record" << endl;
        cout << "\t\t\t\t\t 6) Display Employee Payslip" << endl;
        cout << "\t\t\t\t\t 7) Exit" << endl;

        cout << "\t\t\t\t\t......................................" << endl;
        cout << "\t\t\t\t\t-> Choice Options: [1|2|3|4|5|6|7] <-" << endl;
        cout << "\t\t\t\t\t......................................" << endl;
        cout << " Enter Your Choice: "; // Taking the action input
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 1:
            do
            {
                insert();
                cout << "\n\n\t\t\t Add Another Employe Record Press (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            waitForEnter();
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
            break;
        case 6:
            payslip();
            break;
        case 7:
            system("cls");
            Sleep(10);
            cout << "\n\t\t\t\tPAYROLL MANAGEMENT SYSTEM BY CSE-F:";
            cout << "\n\t\t\t\t\tNavyasri\n\t\t\t\t\tThank You........";
            exit(0);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
        getch();
    }
}

void Payroll_management::insert() // add data of employe
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Insert Data -------------------------------------------" << endl;
    cout << "\n Enter Name of Employee: ";
    cin >> name;
    cout << "\n Enter Employee ID [max 4 digits]: ";
    cin >> id;
    cout << "\n Enter Designation: ";
    cin >> designation;
    cout << "\n Enter Employee Age: ";
    cin >> age;
    cout << "\n Enter Employee Salary: ";
    cin >> ctc;
    cout << "\n Enter Employee Experience: ";
    cin >> experience;
    file.open("Employee_Record.txt", ios::app | ios::out);
    file << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
    file.close();
}

void Payroll_management::display() // Display data of employee
{
    system("cls");
    int total = 1;
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Record Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    //checking for file is present or not
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> ctc >> experience;
        cout << "\n -------------------------------------------------------------------------------------------------";
        cout << "\n||    NAME    ||    ID    ||    DESIGNATION    ||    AGE    ||      SALARY      ||    EXPERIENCE    ||";
        cout << "\n -------------------------------------------------------------------------------------------------";
        while (!file.eof())
        {
            cout << "\n";
            cout << total++ << ". " << name << "\t  " << id << "\t\t  " << designation << "\t\t" << age << "\t\t" << ctc << "\t\t" << experience;
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
    }
    file.close();
    waitForEnter();
}

void Payroll_management::modify() // Modify data of employee
{
    system("cls");
    char checkId[5];
    int found = 0;
    fstream file, file1;
    cout << "\n---------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Data Modification ------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter employee id: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n Enter Name of Employee: ";
                cin >> name;
                cout << "\n Enter Employee ID [max 4 digits]: ";
                cin >> id;
                cout << "\n Enter Designation: ";
                cin >> designation;
                cout << "\n Enter Employee Age: ";
                cin >> age;
                cout << "\n Enter Employee Salary: ";
                cin >> ctc;
                cout << "\n Enter Employee Experience: ";
                cin >> experience;
                cout << "\n\nSuccessfully Modify Details Of Employee";
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
                found++;
            }
            else
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
        if (found == 0)
        {

           cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
    }
    waitForEnter();
}

void Payroll_management::search() // Search data of employe
{                                  //Displays all details according to Employee's id
    system("cls");
    fstream file;
    char checkId[5];
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Search Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    cout << "\n\nEnter Employee ID: ";
    cin >> checkId;
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n---------------------\n";
                cout << "Employee Name: " << name << "\n";
                cout << "Employee ID.: " << id << "\n";
                cout << "Employee Designation: " << designation << "\n";
                cout << "Employee Age: " << age << "\n";
                cout << "Employee Salary: " << ctc << "\n";
                cout << "Employee Experience: " << experience << "\n";
                cout << "---------------------\n";
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
    }
    file.close();
    waitForEnter();
}

void Payroll_management::deleted() // Delete data of employe
{
    system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Data ------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee Id To Remove Data: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) != 0)
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
        waitForEnter();
    }
}

void Payroll_management::waitForEnter()
{
    cout << "\n\nPress enter to go back: ";
    cin.get();
}

int password_user() // Employee Authentication
{
    string pass_reg = "";
    string name_reg = "";
    string pass = "";
    string name = "";
    fstream file;
    char ch;
    system("cls");
    cout << "\n\t\t\t.............................................";
    cout << "\n\t\t\t->  WELCOME TO PAYROLL MANAGEMENT SYSTEM  <-";
    cout << "\n\t\t\t.............................................";
    cout << "\n\n\t\t\t   [ Press: (1) Register & (2) Login  ]";
    int selection;
    cout << "\n\nPlease Enter Value: ";
    cin >> selection;
    // if user press [1], then it would lead them to register.
    if (selection == 1)
    {
        system("cls");
        cout << "\n\t\t\t\t\t.........................";
        cout << "\n\t\t\t\t\t-> REGISTER AS ADMIN  <-";
        cout << "\n\t\t\t\t\t.........................";
        cout << "\n\n\t\t\t\t\tEnter Username: ";
        cin >> name_reg;
        cout << "\n\t\t\t\t\tEnter Password: ";
        cin>>pass_reg;
        file.open("Ep_data.txt");
        file << " " << name_reg << " " << pass_reg << "\n";
        file.close();
        cout << "\nRegistred Succesfully ";
        getch();
        password_user();
    }
    // if user press [2], then it would lead them to login.
    else if (selection == 2)
    {
        system("cls");
        file.open("Ep_data.txt", ios::in);
        cout << "\n\t\t\t\t\t------------------";
        cout << "\n\t\t\t\t\t-> ADMIN LOGIN <-";
        cout << "\n\t\t\t\t\t------------------";
        cout << "\n\n\t\t\t\t\tEnter Username: ";
        cin >> name;
        cout << "\n\t\t\t\t\tEnter Password: ";
        cin>>pass;
        file >> name_reg >> pass_reg;
        while (!file.eof())
        {
            if (pass == pass_reg && name == name_reg)
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying Crendintials |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Granted..\n\n";
                system("PAUSE");
                system("cls");
            }
            else
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying Credintials |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Aborted...\n\n";
                system("PAUSE");
                system("cls");
                password_user();
            }
            file >> name_reg >> pass_reg;
        }
        file.close();
    }
    else
    {
        cout << "\nInvalid Input.. Please Try Again..";
        password_user();
    }
    return 0;
}
int main()
{
    Payroll_management P_m;
    P_m.menu();
    return 0;
}
