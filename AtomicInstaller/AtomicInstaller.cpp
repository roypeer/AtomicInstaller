#include <Windows.h>
#include <iostream>

#include "ExcerciseConstants.h"
#include "InstalledFile.h"
#include "DirectoryInstallation.h"
#include "ConsoleLogger.h"

int main() {

	USE_INSTALLER_NAMESPACE

		
	try {
		auto installation = DirectoryInstallation(ConstantPaths::destination_directory);
		
		for (const auto& file : ConstantPaths::files_to_install) {
			installation.add_file(file);
		}
	}
	catch (const InstallException& exception) {
		ConsoleLogger().installation_log(exception.what());
		ConsoleLogger().installation_log("Installation failed.");
		return RETURN_CODES::INSTALLATION_ERROR;
	}
	catch (...)
	{
		ConsoleLogger().installation_log("An unexpected error has occurred.");
		return RETURN_CODES::UNKNOWN_ERROR;
	}

	ConsoleLogger().installation_log("Installation performed successfully!");
	return RETURN_CODES::SUCCESS;
}