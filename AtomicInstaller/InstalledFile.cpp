#include "InstalledFile.h"

#include <shlwapi.h>
#include <pathcch.h>

INSTALLER_NAMESPACE_START

InstalledFile::InstalledFile(std::wstring destination_directory, std::wstring source_path, 
	bool& const auto_cleanup): m_cleanup_handle(auto_cleanup)
{
	auto file_name = PathFindFileName(source_path.c_str());
	
	wchar_t installed_file_path[MAX_PATH];
	
	if (S_OK != PathCchCombine(installed_file_path, MAX_PATH, destination_directory.c_str(), file_name)) {
		throw InstallException("Construction of the new file path failed.");
	}
	
	m_path = installed_file_path;
	
	if (!CopyFileW(source_path.c_str(), installed_file_path, FALSE)) {
		throw InstallException("Failed to copy file to the new destination.");
	}
}

InstalledFile::~InstalledFile()
{
	if (m_cleanup_handle) {
		// Installation went wrong, and installation directory wasn't removed recursively (probably 
		// because it already existed), so each file cleans itself up
		DeleteFile(m_path.c_str());
	}
}

INSTALLER_NAMESPACE_END