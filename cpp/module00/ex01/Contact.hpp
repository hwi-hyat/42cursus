#ifndef CONTACT_H
# define CONTACT_H

#include<iostream>
#include<string>

class Contact {
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string number;
		std::string secret;
	public:
		Contact(void);
		~Contact(void);
		void set_firstname(std::string str);
		void set_lastname(std::string str);
		void set_nickname(std::string str);
		void set_number(std::string str);
		void set_secret(std::string str);

		std::string get_firstname(void);
		std::string get_lastname(void);
		std::string get_nickname(void);
		std::string get_number(void);
		std::string get_secret(void);
		
};

#endif