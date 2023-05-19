#include "InstalledDirectory.h"

INSTALLER_NAMESPACE_START

DirectoryInstallation::DirectoryInstallation(std::wstring directory_path): m_is_valid(true), 
																		   m_path(directory_path)
{
	// Let's create the directory if it doesn't exist
	// TODO: consider the security attributes
	if (CreateDirectory(directory_path.c_str(), NULL)) {
		m_directory_existed = false;
	}
	else {
		auto error_code = GetLastError();
		if (ERROR_ALREADY_EXISTS == error_code) {
			m_directory_existed = true;
		}
		else {
			// TODO: THROW EXCEPTION! Make it indicative 
			throw;
		}
	}
}


DirectoryInstallation::~DirectoryInstallation()
{
	// Remove the directory (if needed!), but first you need to make sure the file's dtors are called
}

bool DirectoryInstallation::add_file(std::wstring source_path)
{
	try {
		m_files.emplace_back(m_path, source_path, m_is_valid);
	}
	catch (...) { // TODO: Indicative
		m_is_valid = false;
		throw; // TODO: Add to API 
	} 

	// TODO: Document return value
	return true;
}

INSTALLER_NAMESPACE_END