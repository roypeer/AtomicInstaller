#pragma once

#include "InstallerUtils.h"

// TODO: change to std::unordered_set, iterate with const auto& in main..

INSTALLER_NAMESPACE_START

namespace ExcrConstants {
	const wchar_t* file1_path = L"D:\\playground\\files\\file1.txt";
	const wchar_t* file2_path = L"D:\\playground\\files\\file2.txt";
	const wchar_t* file3_path = L"D:\\playground\\files\\file3.txt";

	const wchar_t* destination_directory = L"D:\\playground\\some_dir";
}

INSTALLER_NAMESPACE_END