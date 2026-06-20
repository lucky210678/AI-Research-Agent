#ifndef REPORT_AGENT_H
#define REPORT_AGENT_H

#include "Agent.h"

class ReportAgent : public Agent
{
public:
    ReportAgent();

    std::string execute(std::string content) override;
};

#endif