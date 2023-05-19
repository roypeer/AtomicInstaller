#pragma once

#include "InstallerUtils.h"
#include "AInstallerLogger.h"

INSTALLER_NAMESPACE_START

class ConsoleLogger : public AInstallerLogger {
	virtual void output_log(std::string message) const override;
};

INSTALLER_NAMESPACE_END