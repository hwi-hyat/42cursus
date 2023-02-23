#include<iostream>
#include<fstream>
#include<string>

void write(std::string buffer, char *filename, char *s1, char *s2) {
	std::ofstream writefile;
	std::string newfilename;
	std::string sfilename(filename);
	std::string ss1(s1);
	std::string ss2(s2);
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

std::string read(char *filename) {
	std::ifstream readfile;
	char char_buf;
	std::string buffer;

	readfile.open(filename);
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

	if(argc != 4) {
		std::cerr << "Format error" << std::endl;
		return 1;
	}

	buffer = read(argv[1]);
	write(buffer, argv[1], argv[2], argv[3]);
	return 0;
}