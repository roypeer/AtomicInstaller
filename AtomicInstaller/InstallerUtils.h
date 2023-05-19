#pragma once

#include <string>
#include <exception>


/*
* Following a general large-projects convention where you have your macros (including 
* consistent namespace declarations) and certain utils in dedicated headers.
*/

#define INSTALLER_NAMESPACE_START namespace installer {

#define INSTALLER_NAMESPACE_END }

#define USE_INSTALLER_NAMESPACE using namespace installer;


namespace RETURN_CODES {
	static constexpr int SUCCESS = 0;
	static constexpr int INSTALLATION_ERROR = 1;
	static constexpr int UNKNOWN_ERROR = 2;
}


class InstallException : public std::exception {

public:
	InstallException(std::string info): m_info(info) {}

	const char* what() const throw() {
		return m_info.c_str();
	}

private:
	std::string m_info;
};



