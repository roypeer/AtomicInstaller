#pragma once

#include <Windows.h>
#include <string>

class InstalledFile {
public:

	
	/*
	 * @ctor InstalledFile
	 * @brief: Initiate an installed file in the destination directory, which knows to delete itself
	 *         if the installation goes wrong in a RAII-way. 
	 * @access public 
	 * @parameter std::wstring destination_directory
	 * @parameter std::wstring source_path
	 * @parameter bool& const installation_validity - a const reference (to a non-const bool) which specifies
		whether the installation was the successful, such that the termination of the InstalledFile knows whether to delete
		the put file.
	 */
	InstalledFile(std::wstring destination_directory, std::wstring source_path, bool& const installation_validity);

	virtual ~InstalledFile();

private:
	std::wstring m_path;
	bool& const m_validity_handle;
};
