#pragma once

#include "InstallerUtils.h"
#include "AInstallerLogger.h"

INSTALLER_NAMESPACE_START

/**
 * @class ConsoleLogger
 * @brief A singleton logger implementation of the logger abstract class, which writes logs to console.
 */
class ConsoleLogger : public AInstallerLogger {

public:
	virtual void output_log(const std::string& message) const override;

	static ConsoleLogger& instance() {
		static ConsoleLogger m_instance;
		return m_instance;
	}

protected:
	ConsoleLogger() {}
};

INSTALLER_NAMESPACE_END