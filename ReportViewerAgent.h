#ifndef REPORT_VIEWER_AGENT_H
#define REPORT_VIEWER_AGENT_H

#include "Agent.h"

class ReportViewerAgent : public Agent
{
public:
    ReportViewerAgent();

    std::string execute(std::string input) override;
};

#endif