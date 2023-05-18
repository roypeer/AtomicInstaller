#include <Windows.h>
#include <iostream>

int main() {
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