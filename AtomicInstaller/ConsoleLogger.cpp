#include "ConsoleLogger.h"

#include <iostream>

INSTALLER_NAMESPACE_START

void ConsoleLogger::output_log(std::string message) const
{
	std::cout << message << std::endl;
}


INSTALLER_NAMESPACE_END