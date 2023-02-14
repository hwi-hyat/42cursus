#include"PhoneBook.hpp"
#include"Contact.hpp"

int main(void) {
	PhoneBook pb;
	std::string str;

	pb.set_index(0);
	while(str != "EXIT") {
		std::cout << "Enter Command" << std::endl;
		std::getline(std::cin, str);
		
		if(str == "ADD") {
			pb.add();
		}
		else if(str == "SEARCH") {
			pb.search();
		}
		else if(str == "EXIT")  {
			break;
		}
	}
	return 0;
}