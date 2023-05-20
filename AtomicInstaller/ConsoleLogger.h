#pragma once

#include "InstallerUtils.h"
#include "AInstallerLogger.h"

INSTALLER_NAMESPACE_START

/**
 * @class ConsoleLogger
 * @brief A singleton logger implementation of the logger abstract class, which writes logs to console.
 */
class ConsoleLogger final : public AInstallerLogger {

public:
	
	static ConsoleLogger& instance() {
		static ConsoleLogger m_instance;
		return m_instance;
	}

protected:
	ConsoleLogger() {}

	virtual void output_log(const std::string& message) const override;
};

INSTALLER_NAMESPACE_END