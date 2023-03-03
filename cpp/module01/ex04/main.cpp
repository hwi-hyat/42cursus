#include<iostream>
#include<fstream>
#include<string>

void write(std::string buffer, std::string sfilename, std::string ss1, std::string ss2) {
	std::ofstream writefile;
	std::string newfilename;
	int index = 0;

	newfilename = sfilename + ".replace";
	writefile.open(newfilename);
	if(writefile.fail()) {
		std::cerr << "There is something wrong with generating file :(" << std::endl;
		std::exit(1);
	}
	while(1) {
		index = buffer.find(ss1);
		if(index == std::string::npos)
			break;
		//buffer.replace(index, ss1.length(), ss2);
		buffer.erase(index, ss1.length());
		buffer.insert(index, ss2);
	}
	writefile << buffer;
	writefile.close();
}

std::string read(std::string sfilename) {
	std::ifstream readfile;
	char char_buf;
	std::string buffer;

	readfile.open(sfilename);
	if(readfile.fail())	{
		std::cerr << "There is something wrong with file :(" << std::endl;
		std::exit(1);
	}
	while(!readfile.eof()) {
		readfile >> std::noskipws >> char_buf;
		buffer += char_buf;
	}
	readfile.close();
	return buffer;
}

int main(int argc, char **argv) {
	std::string buffer;
	std::string sfilename(argv[1]);
	std::string ss1(argv[2]);
	std::string ss2(argv[3]);

	if(argc != 4) {
		std::cerr << "Format error" << std::endl;
		return 1;
	}

	if(argv[2] == NULL || ss1.length() == 0) {
		std::cout << "s1 shouldn't be empty or NULL!" << std::endl;
		return 1;
	}

	buffer = read(sfilename);
	write(buffer, sfilename, ss1, ss2);
	return 0;
}