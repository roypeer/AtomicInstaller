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
	 * @brief add a file to the installation - this instantiates an InstallFile, which copies and maintains
	 *  the file's presence
	 * @FullMethod installer::DirectoryInstallation::add_file
	 * @access public 
	 * @throw - May throw an InstallationException if the addition of a file ends.
	 * @return bool - whether succeeded 
	 * @parameter std::wstring source_path - the path of the file to add to the installtion
	 */
	bool add_file(std::wstring source_path);

	/*
	 * @method reserve
	 * @brief An efficiency function to prevent reallocations inside the managed vector
	 * @FullMethod installer::DirectoryInstallation::reserve
	 * @access public 
	 * @parameter size_t number_of_files - The approximated number of files
	 */
	void reserve(const size_t& number_of_files);

	/**
	 * [FOR INTERVIEWER] Rule of five tells us that definition of a custom destructor should be used
	   in conjunction with definition of custom copy/move constructor/assignment operators.

	   Here we want the move constructor to be default - because we don't want the directory to be re-deleted,
	   and we just want to move the data members describing the directory's presence.

	   The copy constructor, on the other hand, should indeed be deleted.
	 */
	DirectoryInstallation(const DirectoryInstallation& other) = delete;
	DirectoryInstallation& operator=(const DirectoryInstallation& other) = delete;
	DirectoryInstallation(DirectoryInstallation&& other) = default;
	DirectoryInstallation& operator=(DirectoryInstallation&& other) = default;

private:	

	bool m_is_valid;
	bool m_files_auto_cleanup;
	bool m_directory_existed;
	std::wstring m_path;
	std::vector<InstalledFile> m_files; 
};

INSTALLER_NAMESPACE_END