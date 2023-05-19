#include <Windows.h>
#include <iostream>

#include "ExcerciseConstants.h"
#include "InstalledFile.h"
#include "DirectoryInstallation.h"


int fun() {
	const wchar_t* sourceFilePath = L"C:\\path\\to\\source\\file.txt";
	const wchar_t* destinationFilePath = L"C:\\path\\to\\destination\\file.txt";


	// CopyFileW is CopyFile for unicode.. the latter is an alias. 

	if (CopyFileW(sourceFilePath, destinationFilePath, FALSE)) {
		std::cout << "File copied successfully." << std::endl;
	}
	else {
		std::cout << "Failed to copy file. Error code: " << GetLastError() << std::endl;
	}

	return 0;
}


int main() {
	// bool good = false;
	//auto my_file = InstalledFile(L"D:\\playground\\nice", L"D:\\playground\\cool.txt", good);
	USE_INSTALLER_NAMESPACE

	try {
		auto installation = DirectoryInstallation(ExcrConstants::destination_directory);
		installation.add_file(ExcrConstants::file1_path);
	}
	catch (...) // TODO: indicative.. 
	{
		return 0; // TODO: change error code
	}

	return 0;
}