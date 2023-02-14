#include"PhoneBook.hpp"
#include"Contact.hpp"

PhoneBook::PhoneBook(void) {
	
}

PhoneBook::~PhoneBook(void) {
	
}

void PhoneBook::set_index(int n) {
	this->index = n;
}

int PhoneBook::get_index(void) {
	return this->index;
}

void PhoneBook::add(void) {
	Contact cont;
	std::string str;
	int index = this->get_index();

	std::cout << "Enter firstname of contact : ";
	std::getline(std::cin, str);
	cont.set_firstname(str);
	std::cout << "Enter lastname of contact : ";
	std::getline(std::cin, str);
	cont.set_lastname(str);
	std::cout << "Enter nickname of contact : ";
	std::getline(std::cin, str);
	cont.set_nickname(str);
	std::cout << "Enter number of contact : ";
	std::getline(std::cin, str);
	cont.set_number(str);
	std::cout << "Enter secret of contact : ";
	std::getline(std::cin, str);
	cont.set_secret(str);

	if(index == 8) {
		for(int i = 1; i < 8; i++)
			this->contacts_arr[i - 1] = this->contacts_arr[i];
		this->contacts_arr[7] = cont;
	}
	else {
		this->contacts_arr[index] = cont;
		set_index(index + 1);
	}
	std::cout << std::endl;
}

std::string trimmer(std::string str) {
	std::string ret = "          ";
	int size = str.size();

	if (size == 0) {
		return "          ";
	}
	if(size < 10) {
		ret.replace(10 - size, size, str);
		return ret;
	}
	else if(size == 10) {
		return str;
	}
	else {
		ret.replace(0, 9, str);
		ret.replace(9, 1, ".");
		ret.resize(10);
		return ret;
	}
}

void PhoneBook::search(void) {

	int index = this->get_index();
	
	if(index == 0) {
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}
	else {
		std::cout << "|     index|First name| Last name|  nickname|" << std::endl;
		for(int i = 0; i < index; i++) {
			char l_index[11] = "          ";
			std::string l_firstname;
			std::string l_lastname;
			std::string l_nickname;

			l_index[9] = i + 48;
			l_firstname = trimmer(this->contacts_arr[i].get_firstname());
			l_lastname = trimmer(this->contacts_arr[i].get_lastname());
			l_nickname = trimmer(this->contacts_arr[i].get_nickname());
			std::cout << "|" << l_index << "|" << l_firstname << "|" << l_lastname << "|" << l_nickname << "|" << std::endl;
		}
	}
}