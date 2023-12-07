#include "class_ini.h"
#include <iostream>
#include <fstream>

// Library

void Library::setLibrary(string lib_name, string lib_addres, bool _isOpen) {
	LibraryName = lib_name;
	LibraryAdress = lib_addres;
	isOpen = _isOpen;
}

void Library::showLibrary() {
	cout << "Назва - " << LibraryName << '\n';
	cout << "Адреса - " << LibraryAdress << '\n';
	if (isOpen)
		cout << "Чи відкрита - Так" << '\n';
	else
		cout << "Чи відкрита - Ні" << '\n';
}

void Library::closeLibrary() {
	isOpen = false;
}

void Library::openLibrary() {
	isOpen = true;
}

void Library::isLibraryOpen() {
	if (isOpen)
		cout << "Відчинена" << '\n';
	else
		cout << "Зачинена" << '\n';
}

// User

void User::setUser(string _name, string _surname, int _age, bool _isBlocked) {
	name = _name;
	surname = _surname;
	age = _age;
	isBlocked = _isBlocked;
}

void User::showUser() {
	cout << "Iм'я - " << name << '\n';
	cout << "Прiзвище - " << surname << '\n';
	cout << "Вiк - " << age << '\n';

	if(!isBlocked)
		cout << "Не в чорному списку" << '\n';
	else
		cout << "В чорному списку" << '\n';
}

void User::checkUser() {
	if (!isBlocked)
		cout << "Не в чорному списку" << '\n';
	else
		cout << "В чорному списку" << '\n';
}

void User::showAge() {
	cout << "Вік - " << age << '\n';
}

void User::clearUser() {
	name = "";
	surname = "";
	age = -1;
	isBlocked = false;
}


// Admin


void Admin::ban() {
	setIsBlocked(true);
}

void Admin::unBan() {
	setIsBlocked(false);
}

void Admin::setLogin(string _login) {
	login = _login;
}

void Admin::showAdmin() {
	cout << "Логін - " << '\n';
	if (isWork)
		cout << "На робочому місці" << '\n';
	else
		cout << "Не на робочому місці" << '\n';
}

void Admin::setWork(bool status) {
	isWork = status;
}

void Admin::deleteAdmin() {
	login = "";
	isWork = false;
}


// Book

void Book::setBook(string _title, string _author, bool _isAvailable) {
	title = _title;
	author = _author;
	isAvailable = _isAvailable;
}

void Book::showBook() {
	cout << "Назва - " << title << '\n';
	cout << "Автор - " << author << '\n';

	if(isAvailable)
		cout << "Є в наявності" << '\n';
	else
		cout << "Немає в наявності" << '\n';	
}

void Book::setAvailable(bool status) {
	isAvailable = status;
}

void Book::checkAvailable() {
	if (isAvailable)
		cout << "Є в наявності" << '\n';
	else
		cout << "Немає в наявності" << '\n';
}

void Book::clearBook() {
	title = "";
	author = "";
	isAvailable = false;
}

