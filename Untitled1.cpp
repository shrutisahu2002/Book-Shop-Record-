// Test change for Git
#include<iostream>
#include<fstream>
using namespace std;

class temp {
    string visitorName, emailId, password;
    string searchName, searchPass, searchEmailId;
    fstream file;

public:
    void login();
    void signUp();
    void forgot();
} obj;

int main() {
    char choice;
    cout << "-------------------BOOK STORE VISITORS-------------------" << endl;
    cout << "\n1.  SIGN-UP";
    cout << "\n2.  LOGIN";
    cout << "\n3.  FORGOT PASSWORD";
    cout << "\n -- EXIT --";
    cout << "\nEnter Your Choice:: ";
    cin >> choice;
    cin.ignore();  // clear newline from buffer

    switch (choice) {
        case '1':
            obj.signUp();
            break;
        case '2':
            obj.login();
            break;
        case '3':
            obj.forgot();
            break;
        default:
            cout << "Invalid selection";
    }

    return 0;
}

void temp::signUp() {
    cout << "Enter Your Visitor Name: ";
    getline(cin, visitorName);
    cout << "Enter Your Email Id: ";
    getline(cin, emailId);
    cout << "Enter Your Password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << visitorName << "*" << emailId << "*" << password << endl;
    file.close();
    cout << "Sign-Up Successfully!" << endl;
}

void temp::login() {
    bool found = false;
    cout << "-------LOGIN--------" << endl;
    cout << "Enter Visitor Name: ";
    getline(cin, searchName);
    cout << "Enter Your Password: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    while (getline(file, visitorName, '*')) {
        getline(file, emailId, '*');
        getline(file, password);

        if (visitorName == searchName) {
            found = true;
            if (password == searchPass) {
                cout << "\nAccount Login Successfully" << endl;
                cout << "Visitor Name: " << visitorName << endl;
                cout << "Visitor Email: " << emailId << endl;
            } else {
                cout << "\nIncorrect Password" << endl;
            }
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "\nVisitor Name Not Found" << endl;
    }
}

void temp::forgot() {
    bool found = false;
    cout << "Enter Your Visitor Name: ";
    getline(cin, searchName);
    cout << "Enter Your Email Id: ";
    getline(cin, searchEmailId);

    file.open("loginData.txt", ios::in);
    while (getline(file, visitorName, '*')) {
        getline(file, emailId, '*');
        getline(file, password);

        if (visitorName == searchName && emailId == searchEmailId) {
            found = true;
            cout << "\nAccount Found..." << endl;
            cout << "Visitor Name: " << visitorName << endl;
            cout << "Visitor Email: " << emailId << endl;
            cout << "Password: " << password << endl;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "\nAccount Not Found with Provided Details" << endl;
    }
}

