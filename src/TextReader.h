#include <fstream>
#include <iostream>

const char* get_text(const std::string& path)
{
	std::ifstream file(path, std::ios::binary | std::ios::ate);
	if (!file)
	{
		std::cerr << "Unable to open file" << std::endl;
	}
	file.seekg(0, std::ios::end);
	std::streamsize fileSize = file.tellg();
	file.seekg(0, std::ios::beg);
	std::vector<char> buffer(fileSize);
	if (!file.read(buffer.data(), fileSize))
	{
		std::cerr << "Unable to read file" << std::endl;
		return nullptr;
	}
	buffer.push_back('\0');
	char* result = new char[buffer.size()];
	std::copy(buffer.begin(), buffer.end(), result);


	return result;
}