#include "DirectoryInstallation.h"

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
			m_directory_existed = true;
		}
		else {
			throw InstallException("Unable to create directory.");
		}
	}
}


DirectoryInstallation::~DirectoryInstallation()
{
	
	if (!m_is_valid) { // This means the installation went wrong		
		if (!m_directory_existed) {
			m_files_auto_cleanup = false; // delete this line
			// TODO: Call recursive_delete of directory...

		}
		else {
			m_files_auto_cleanup = true;
		}
	}
	else {
		// Nothing :)
	}
}

bool DirectoryInstallation::add_file(std::wstring source_path)
{
	try {
		m_files.emplace_back(m_path, source_path, m_files_auto_cleanup);
	}
	catch (...) { // TODO: Indicative
		m_is_valid = false; // Or m_is_valid
		throw; // TODO: Add to API 
	} 

	// TODO: Document return value
	return true;
}

INSTALLER_NAMESPACE_END