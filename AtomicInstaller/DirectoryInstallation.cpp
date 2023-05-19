#include "DirectoryInstallation.h"

#include "ConsoleLogger.h"
#include "WinApiWrappers.h"

INSTALLER_NAMESPACE_START

DirectoryInstallation::DirectoryInstallation(std::wstring directory_path): m_is_valid(true),
																		   m_files_auto_cleanup(false),
																		   m_path(directory_path)
{
	if (CreateDirectory(directory_path.c_str(), NULL)) {
		m_directory_existed = false;
	}
	else {
		auto error_code = GetLastError();
		if (ERROR_ALREADY_EXISTS == error_code) {
			ConsoleLogger().installation_log("Notice: directory already existed");
			m_directory_existed = true;
		}
		else {
			throw InstallException("Unable to create directory.");
		}
	}
}


DirectoryInstallation::~DirectoryInstallation()
{
	if (!m_is_valid) { // The installation went wrong		
		if (!m_directory_existed) {
			m_files_auto_cleanup = false;
			WinApiWrappers::delete_directory_recursively(m_path);
		}
		else {
			m_files_auto_cleanup = true;
		}
	}
}

bool DirectoryInstallation::add_file(std::wstring source_path)
{
	try {
		m_files.emplace_back(m_path, source_path, m_files_auto_cleanup);
	}
	catch (const InstallException& exception) {
		m_is_valid = false; 
		throw InstallException(std::string("Failed adding a file: ") + exception.what()); 
	} 

	return true;
}

void DirectoryInstallation::reserve(const size_t& number_of_files)
{
	m_files.reserve(number_of_files);
}


INSTALLER_NAMESPACE_END