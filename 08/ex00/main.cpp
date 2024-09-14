#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(8745);
	vec.push_back(7);
	vec.push_back(34);
	vec.push_back (435);
	try
	{
		easyfind(vec, 34);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}