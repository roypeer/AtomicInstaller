#pragma once

#include <string>
#include "InstallerUtils.h"

INSTALLER_NAMESPACE_START

static const auto& INSTALLATION_LOG_PREFIX = "|Installation Log| ";

/**
 * @class AInstallerLogger
 * @brief an interface for a logger used in the installation process
 * [FOR INTERVIEWER: Because simply calling std::cout in main feels too bad, even in an excercise. 
    We shall implement this interface and a console logger will print to console. A file or syslog loggers
    may be added in the future].

   [FOR INTERVIEWER #2: In one of the teams I worked, ASomething stands for Abstract class, same as ISomething
    for interfaces. But I am open to other conventions obviously... ;) ]
 */
class AInstallerLogger {

public:
    AInstallerLogger() {}

    virtual ~AInstallerLogger() {}

    void installation_log(const std::string& message) const {
        output_log(INSTALLATION_LOG_PREFIX + message);
    }

protected:

    /*
     * @method output_log
     * @brief implementation of the actual outputting of a given string to the log medium.
     * @FullMethod AInstallerLogger::output_log
     * @access virtual protected 
     * @parameter std::string message
     */
    virtual void output_log(std::string message) const = 0;
};

INSTALLER_NAMESPACE_END