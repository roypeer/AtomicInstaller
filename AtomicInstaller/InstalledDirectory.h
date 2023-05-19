#pragma once

#include <string>
#include <vector>
#include <Windows.h>

#include "InstalledFile.h"
#include "InstallerUtils.h"


INSTALLER_NAMESPACE_START

// Mmmmm name?
class DirectoryInstallation {
public:

	DirectoryInstallation(std::wstring directory_path);

	virtual ~DirectoryInstallation();


	/*
	 * @method add_file
	 * @brief add a file to the installation
	 * @FullMethod installer::DirectoryInstallation::add_file
	 * @access public 
	 * @return bool - whether succeeded 
	 * @parameter std::wstring source_path - the path of the file to add to the installtion
	 */
	bool add_file(std::wstring source_path);

private:
	bool m_is_valid;
	bool m_directory_existed;
	std::wstring m_path;

	std::vector<InstalledFile> m_files; 

};

INSTALLER_NAMESPACE_END