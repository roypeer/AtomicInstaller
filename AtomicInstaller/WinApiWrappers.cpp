#include "WinApiWrappers.h"

#include <vector>
#include <Shlwapi.h>

INSTALLER_NAMESPACE_START

bool WinApiWrappers::delete_directory_recursively(const std::wstring& directory_path)
{
	// MSDN says that .pFrom should be double null-terminated, so let's make sure it is exactly that.
	std::vector<wchar_t> double_terminated_path(directory_path.begin(), directory_path.end());
	double_terminated_path.emplace_back(L'\0');
	double_terminated_path.emplace_back(L'\0');

	SHFILEOPSTRUCT file_operation = {};
	file_operation.wFunc = FO_DELETE;
	file_operation.pFrom = double_terminated_path.data();
	file_operation.fFlags = FOF_NO_UI | FOF_SILENT | FOF_NOCONFIRMATION;

	if (0 == SHFileOperation(&file_operation)) {
		return true;
	}

	return false;
}

INSTALLER_NAMESPACE_END