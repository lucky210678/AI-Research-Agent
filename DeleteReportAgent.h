#ifndef DELETE_REPORT_AGENT_H
#define DELETE_REPORT_AGENT_H

#include "Agent.h"

class DeleteReportAgent : public Agent
{
public:
    DeleteReportAgent();

    std::string execute(std::string filename) override;
};

#endif