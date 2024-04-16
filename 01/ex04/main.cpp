#include <iostream>
#include <fstream>


int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Need 3 parameters!!" << std::endl;
		return (1);
	}
	size_t pos = 0;
	std::string text;
	std::ifstream readfile(argv[1]);
	if (!readfile.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	std::string outfile(argv[1]);
	outfile = outfile.substr(0, outfile.find_last_of('.')) + ".replace";
	std::ofstream newfile(outfile);
	if (!newfile.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	while (getline(readfile, text))
	{
		while ((pos = text.find(argv[2], pos)) != std::string::npos)
		{
			text.erase(pos, strlen(argv[2]));
			text.insert(pos, argv[3]);
			pos += strlen(argv[3]);
		}
		newfile << text << std::endl;
		pos = 0;
	}
	readfile.close();
	newfile.close();
}