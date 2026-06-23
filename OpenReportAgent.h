#ifndef OPEN_REPORT_AGENT_H
#define OPEN_REPORT_AGENT_H

#include "Agent.h"

class OpenReportAgent : public Agent
{
public:
    OpenReportAgent();

    std::string execute(std::string filename) override;
};

#endif