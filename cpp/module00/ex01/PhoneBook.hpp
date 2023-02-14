#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include"Contact.hpp"
#include<iostream>
#include<string>

class PhoneBook {
	private:
		Contact contacts_arr[8];
		int index;
		
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void insert_contact(Contact cont);

		void set_index(int n);
		int get_index(void);

		void add(void);
		void search(void);
		
};



#endif