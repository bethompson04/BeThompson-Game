#include "FileIO.h"

namespace MEN
{
	std::string getFilePath()
	{
		return std::filesystem::current_path().string();;
	}
}
