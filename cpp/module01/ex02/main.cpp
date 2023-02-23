#include<iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* str_ptr;

	str_ptr = &str;
	std::string& str_ref = str;

	std::cout << "string: " << str << std::endl;
	std::cout << "string address: " << &str << std::endl;
	std::cout << "string pointer: " << str_ptr << std::endl;
	std::cout << "string reference: " << str_ref << std::endl;
	std::cout << "string reference address: " << &str_ref << std::endl;

	return 0;
}