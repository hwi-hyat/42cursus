#include "Data.h"

static uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

static Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main()
{
	Data        data = { 42, "Plenty of value" };
	Data*		ptr = &data;
	uintptr_t   serialized = serialize(ptr);
	Data*		ptr_after_all = deserialize(serialized);

	std::cout << "             key: " << data.key << std::endl;
	std::cout << "             str: " << data.value << std::endl;
	std::cout << "deserialized key: " << ptr_after_all->key << std::endl;
	std::cout << "deserialized str: " << ptr_after_all->value << std::endl << std::endl;
	
	std::cout << std::hex << "Serialized data is " << serialized << std::endl;

	return 0;
}