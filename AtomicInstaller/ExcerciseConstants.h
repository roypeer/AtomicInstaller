#pragma once

#include <unordered_set>

#include "InstallerUtils.h"

INSTALLER_NAMESPACE_START

namespace ConstantPaths {
	
	const wchar_t* destination_directory = L"D:\\playground\\installation_dir";

	const std::unordered_set<const wchar_t*> files_to_install = { L"D:\\playground\\files\\file1.txt",
																  L"D:\\playground\\files\\file2.txt",
																  L"D:\\playground\\other_files\\file3.txt" };
}

INSTALLER_NAMESPACE_END