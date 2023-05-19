#pragma once

#include <string>
#include <vector>
#include <Windows.h>

#include "InstalledFile.h"
#include "InstallerUtils.h"


INSTALLER_NAMESPACE_START

/**
 * @class DirectoryInstallation
 * @brief This class initializes and maintains an installation process given an installation path.
 */
class DirectoryInstallation {
public:


	/*
	 * @method DirectoryInstallation
	 * @FullMethod installer::DirectoryInstallation::DirectoryInstallation
	 * @access public 
	 * @throw InstallException, if unable to create a directory and not because it didn't exist.
	 * @parameter std::wstring directory_path - the path of installation
	 */
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
	// TODO: Document these data members in the README, and note that m_files_auto_cleanup appears before the vector.
	bool m_is_valid;
	bool m_files_auto_cleanup;
	bool m_directory_existed;
	std::wstring m_path;

	std::vector<InstalledFile> m_files; 

};

INSTALLER_NAMESPACE_END