#ifndef SUMMARY_VIEWER_AGENT_H
#define SUMMARY_VIEWER_AGENT_H

#include "Agent.h"

class SummaryViewerAgent : public Agent
{
public:
    SummaryViewerAgent();

    std::string execute(std::string input) override;
};

#endif