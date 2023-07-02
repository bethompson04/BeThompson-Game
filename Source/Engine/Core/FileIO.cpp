#include "FileIO.h"
#include <fstream>

namespace MEN
{
	std::string getFilePath()
	{
		return std::filesystem::current_path().string();;
	}

	bool setFilePath(const std::filesystem::path& filePath)
	{
		std::error_code ec;
		std::filesystem::current_path(filePath, ec);

		return ec.value() == 0;
	}

	bool fileExists(const std::filesystem::path& filePath)
	{
		return std::filesystem::exists(filePath);
	}

	bool getFileSize(const std::filesystem::path& filePath, size_t& fileSize)
	{
		std::error_code ec;
		fileSize = std::filesystem::file_size(filePath, ec);

		return ec.value() == 0;
	}

	bool readFile(const std::filesystem::path& filePath, std::string& buffer)
	{

		if (!fileExists(filePath)) return false;

		size_t size;
		if (!getFileSize(filePath, size)) return false;

		buffer.resize(size);
		std::ifstream stream(filePath);

		stream.read(buffer.data(), size);
		stream.close();

 		return true;
	}
}
