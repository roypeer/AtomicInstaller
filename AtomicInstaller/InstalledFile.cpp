#include "InstalledFile.h"

#include <shlwapi.h>
#include <pathcch.h>

INSTALLER_NAMESPACE_START

InstalledFile::InstalledFile(std::wstring destination_directory, std::wstring source_path, 
	bool& const auto_cleanup): m_cleanup_handle(auto_cleanup)
{
	auto file_name = PathFindFileName(source_path.c_str());
	
	wchar_t installed_file_path[MAX_PATH];
	
	// TODO: Check return value
	PathCchCombine(installed_file_path, MAX_PATH, destination_directory.c_str(), file_name);
	
	m_path = installed_file_path;
	
	// TODO: Consider MAX_PATH

	// TODO: Check success and THROW respectively 
	CopyFileW(source_path.c_str(), installed_file_path, FALSE);
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