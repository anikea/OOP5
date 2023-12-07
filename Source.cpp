#include "class_ini.h"
#include <iostream>
#include <locale>

using namespace std;

void showMenu() {
    cout << "1. Create User" << endl;
    cout << "2. Delete User" << endl;
    cout << "3. Create Admin" << endl;
    cout << "4. Delete Admin" << endl;
    cout << "5. Create Book" << endl;
    cout << "6. Delete Book" << endl;
    cout << "7. Exit" << endl;
}


int main()
{
    setlocale(LC_ALL, "ukr");

    // Demo of virtual and default destructor
    Library* l1b = new User;
    delete l1b;

    User user;

    cout << '\n';

    try {
        User staticArray[5];

        User* dynamicArray = new User[5];

        // Звернення до елементу за межами масиву для генерації виключення
        std::cout << "Accessing out-of-bounds element in dynamic array" << std::endl;
        dynamicArray[10]; // Генерація виключення

        delete[] dynamicArray;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    cout << '\n';

    User test;

    test.setUser("david", "shexovcov", 18, false);

    Service(test, "text.txt");

    cout << '\n';

    vector<User> users1;

    User us1("John", "Doe", 30);
    User us2("Anna", "Doe", 29);
    User us3("David", "Doe", 28);

    users1.push_back(us1);
    users1.push_back(us2);
    users1.push_back(us3);

    User::manageUsers(users1, 1);

    vector<User> users;
    vector<Admin> admins;
    vector<Book> books;

    

    int choice;
    do {
        cout << '\n';
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        cout << '\n';

        switch (choice) {
        case 1: {
            // Create User
            string name, surname;
            int age;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter surname: ";
            cin >> surname;
            cout << "Enter age: ";
            cin >> age;
            users.emplace_back(name, surname, age);

            cout << "User Added." << '\n';

            break;
        }
        case 2: {
            // Delete User

            for (int i = 0; i < users.size(); i++) {
                users[i].clearUser();
            }
            
            cout << "successful deleted." << '\n';
             
            break;
        }
        case 3: {
            // Create Admin
            string login;
            cout << "Enter admin login: ";
            cin >> login;
            admins.emplace_back(login);

            cout << "Admin Added." << '\n';

            break;
        }
        case 4: {
            // Delete Admin
            
            for (int i = 0; i < admins.size(); i++) {
                admins[i].deleteAdmin();
            }

            cout << "successful deleted." << '\n';

            break;
        }
        case 5: {
            // Create Book
            string title, author;
            cout << "Enter book title: ";
            cin.ignore(); // to clear input buffer
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            books.emplace_back(title, author);

            cout << "Book Added." << '\n';

            break;
        }
        case 6: {
            // Delete Book
            
            for (int i = 0; i < books.size(); i++) {
                books[i].clearBook();
            }

            cout << "successful deleted." << '\n';

            break;
        }
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    } while (choice != 7);

    User userStaff;
    Admin adminStaff;
    Book bookStaff;

    userStaff.showStaff();
    adminStaff.showStaff();
    bookStaff.showStaff();

    return 0;
}


