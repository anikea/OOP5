#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


class Library {
public:

	virtual void sayHelloLibrary() const {
		cout << "Hello Library from yourself" << '\n';
	}

	string LibraryName = "OpenBook";
	string LibraryAdress = "Bibliotechna 17";
	bool isOpen = false;


	void setLibrary(string lib_name, string lib_addres, bool _isOpen = false);
	void showLibrary();
	void closeLibrary();
	void openLibrary();
	void isLibraryOpen();

	virtual void showStaff() {
		cout << "I am from Library" << '\n';
	}

	// add Virtual
	//  ~Library() {
	//	cout << "Library Destructor" << '\n';
	//}
};

class User : public Library {
public:
	 void sayHelloLibrary() const override {
		cout << "Hello Library from User" << '\n';
	}

	User(){}

	User(const User &other) {
		this->name = other.name;
		this->surname = other.surname;
		this->age = other.age;
		this->isBlocked = other.isBlocked;
	}

	User(string _name, string _surname, int _age, bool _isBlocked = false)
		: Library(), name(_name), surname(_surname), age(_age), isBlocked(_isBlocked) {}

	void setUser(string _name, string _surname, int _age, bool _isBlocked = false);
	void showUser();
	void checkUser();
	void showAge();
	void clearUser();

	void write(const std::string& filename) const {
		std::ofstream file(filename);
		if (file.is_open()) {
			file << "Name: " << name << '\n';
			file << "Surname: " << surname << '\n';
			file << "Age: " << age << '\n';
			file << "Blocked: " << (isBlocked ? "true" : "false") << '\n';

			file.close();
		}
		else {
			std::cerr << "Unable to create file: " << filename << std::endl;
		}
	}

	void read(const std::string& filename) {
		std::ifstream file(filename);
		if (file.is_open()) {
			std::string line;

			// „итаЇмо Name
			std::getline(file, line);
			name = line.substr(line.find(":") + 2);

			// „итаЇмо Surname
			std::getline(file, line);
			surname = line.substr(line.find(":") + 2);

			// „итаЇмо Age
			std::getline(file, line);
			istringstream iss(line.substr(line.find(":") + 2));
			iss >> age;

			// „итаЇмо Blocked
			std::getline(file, line);
			isBlocked = (line.substr(line.find(":") + 2) == "true") ? true : false;

			file.close();

			cout << "Readed: " << '\n';

			cout << "Name - " << name << '\n';
			cout << "Surname - " << surname << '\n';
			cout << "Age - " << age << '\n';
			cout << "Blocked - " << (isBlocked ? "true" : "false") << '\n';
		}
		else {
			std::cerr << "Unable to open file: " << filename << std::endl;
		}
	}

	static void manageUsers(vector<User>& users, int count) {
		if (!users.empty()) {
			if (count <= 0) {
				count = users.size();
			}

			cout << "List of Users:" << endl;
			for (int i = 0; i < count; i++) {
				users[i].showUser();
			}
		}
		else {
			cout << "No users found." << endl;
		}
	}

	//~User() {
	//	cout << "Destructor USER" << '\n';
	//}

	void showStaff() override{
		cout << "I am from User" << '\n';
	}

private:
	string name = "";
	string surname = "";
	int age = -1;
	bool isBlocked = false;

protected:
	void setIsBlocked(bool blocked) {
		isBlocked = blocked;
	}
};

inline void Service(User user, string filename) {
	try {
		user.write(filename);
		user.read(filename);
	}
	catch (...) {
		cerr << "Got some problem" << '\n';
	}
}

class Admin : virtual protected User {
public:

	void sayHelloLibrary() const override {
		cout << "Hello Library from Admin" << '\n';
	}

	Admin() {}
	Admin(const Admin& other) {
		this->login = other.login;
	}

	Admin(string _login) {
		login = _login;
	}
	
	void ban();
	void setLogin(string _login);
	void unBan();
	void showAdmin();
	void setWork(bool status);
	void deleteAdmin();

	void showStaff() override {
		cout << "I am from Admin" << '\n';
	}

private:
	string login = "";
	bool isWork = false;
};

class Book : public Library {
public:

	void sayHelloLibrary() const override {
		cout << "Hello Library from Book" << '\n';
	}

	Book() {}
	Book(const Book &other) {
		this->title = other.title;
		this->author = other.author;
		this->isAvailable = other.isAvailable;
	}

	Book(string _title, string _author, bool _isAvailable = false) {
		title = _title;
		author = _author;
		isAvailable = _isAvailable;
	}

	void setBook(string _title, string _author, bool _isAvailable = false);
	void showBook();
	void setAvailable(bool status);
	void checkAvailable();
	void clearBook();

	void showStaff() override {
		cout << "I am from Book" << '\n';
	}

	//~Book() {
	//	cout << "Destructor BOOK" << '\n';
	//}

private:
	string title = "";
	string author = "";
	bool isAvailable = false;
};

