#include "InstalledFile.h"

#include <shlwapi.h>
#include <pathcch.h>

InstalledFile::InstalledFile(std::wstring destination_directory, std::wstring source_path, 
	bool& const installation_validity): m_validity_handle(installation_validity)
{
	auto file_name = PathFindFileName(source_path.c_str());
	
	wchar_t installed_file_path[MAX_PATH];
	
	// TODO: Check return value
	PathCchCombine(installed_file_path, MAX_PATH, destination_directory.c_str(), file_name);
	
	m_path = installed_file_path;
	
	// TODO: Consider MAX_PATH

	// TODO: Check success
	CopyFileW(source_path.c_str(), installed_file_path, FALSE);
}

InstalledFile::~InstalledFile()
{
	if (!m_validity_handle) {
		// Installation went wrong
		DeleteFile(m_path.c_str());
	}

}
