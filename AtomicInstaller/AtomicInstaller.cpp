#include <Windows.h>

#include "ExcerciseConstants.h"
#include "InstalledFile.h"
#include "DirectoryInstallation.h"
#include "ConsoleLogger.h"

int main() {

	USE_INSTALLER_NAMESPACE

	AInstallerLogger& logger = ConsoleLogger::instance();

	try {
		auto installation = DirectoryInstallation(ConstantPaths::destination_directory);
		
		// For maximum efficiency 
		installation.reserve(ConstantPaths::files_to_install.size());

		for (const auto& file : ConstantPaths::files_to_install) {
			installation.add_file(file);
		}
	}
	catch (const InstallException& exception) {
		logger.installation_log(exception.what());
		logger.installation_log("Installation failed.");
		
		return RETURN_CODES::INSTALLATION_ERROR;
	}
	catch (...)
	{
		logger.installation_log("An unexpected error has occurred.");
		
		return RETURN_CODES::UNKNOWN_ERROR;
	}

	logger.installation_log("Installation performed successfully!");
	
	return RETURN_CODES::SUCCESS;
}