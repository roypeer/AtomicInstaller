#pragma once

#include <Windows.h>
#include <string>

#include "InstallerUtils.h"

INSTALLER_NAMESPACE_START

/**
 * @class InstalledFile
 * @brief This class initializes (via copy) and maintains the presence of an installed file
 */
class InstalledFile {
public:

	/*
	 * @ctor InstalledFile
	 * @brief: Initiate an installed file in the destination directory, which knows to delete itself
	 *         if the installation goes wrong in a RAII-way. Note that the automatic cleanup is not always
	 *         required [FOR INTERVIEWER: Because despite this class not being 'aware' of it, the class orchestrating
	 *					the directory installation may simply delete the entire directory itself, had it not 
	 *					existed before the installation. Auto-cleanup is required when the directory is to remain 
	 *					there, and the installed files simply clean themselves.]
	 *
	 * @access public 
	 * @parameter std::wstring destination_directory
	 * @parameter std::wstring source_path
	 * @parameter bool& const installation_validity - a const reference (to a non-const bool) which specifies
		whether the installation was the successful, such that the termination of the InstalledFile knows whether to delete
		the put file.
	 */
	InstalledFile(std::wstring destination_directory, std::wstring source_path, bool& const auto_cleanup);


	/*
	 * @method ~InstalledFile
	 * @brief An InstalledFile dtor - Clean the presence of the installed file, unless not required.
	 * @FullMethod installer::InstalledFile::~InstalledFile
	 * @access virtual public 
	 */
	virtual ~InstalledFile();

private:
	std::wstring m_path;
	bool& const m_cleanup_handle;
};

INSTALLER_NAMESPACE_END