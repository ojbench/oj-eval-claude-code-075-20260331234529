#include "str.hpp"
#include <iostream>
#include <vector>

int main()
{
	// Test default constructor
	str s1;
	std::cout << "s1 length: " << s1.len() << std::endl;

	// Test char constructor
	str s2('a');
	std::cout << "s2: " << s2[0] << ", length: " << s2.len() << std::endl;

	// Test char* constructor
	str s3("hello");
	std::cout << "s3: ";
	for (size_t i = 0; i < s3.len(); i++)
	{
		std::cout << s3[i];
	}
	std::cout << ", length: " << s3.len() << std::endl;

	// Test copy constructor
	str s4(s3);
	std::cout << "s4: ";
	for (size_t i = 0; i < s4.len(); i++)
	{
		std::cout << s4[i];
	}
	std::cout << ", length: " << s4.len() << std::endl;

	// Test assignment operator
	str s5;
	s5 = s3;
	std::cout << "s5: ";
	for (size_t i = 0; i < s5.len(); i++)
	{
		std::cout << s5[i];
	}
	std::cout << ", length: " << s5.len() << std::endl;

	// Test slice
	str s6 = s3.slice(0, 2);
	std::cout << "s6 (slice 0-2): ";
	for (size_t i = 0; i < s6.len(); i++)
	{
		std::cout << s6[i];
	}
	std::cout << ", length: " << s6.len() << std::endl;

	// Test join
	std::vector<str> vec;
	vec.push_back(str("1"));
	vec.push_back(str("2"));
	vec.push_back(str("3"));
	str separator(", ");
	str joined = separator.join(vec);
	std::cout << "joined: ";
	for (size_t i = 0; i < joined.len(); i++)
	{
		std::cout << joined[i];
	}
	std::cout << ", length: " << joined.len() << std::endl;

	return 0;
}
