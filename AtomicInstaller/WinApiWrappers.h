#pragma once

#include "InstallerUtils.h"

INSTALLER_NAMESPACE_START

class WinApiWrappers {

public:
	/*
	 * @method delete_directory_recursively
	 * @brief A wrapper for the Windows SHFileOperation that deletes a directory recursively
	 * @FullMethod installer::DirectoryInstallation::delete_directory_recursively
	 * @access private static
	 * @return bool - whether succeeded
	 * @parameter const std::wstring & directory_path - The path of the directory to delete
	 */
	static bool delete_directory_recursively(const std::wstring& directory_path);

};

INSTALLER_NAMESPACE_END
