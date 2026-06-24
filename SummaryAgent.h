#ifndef SUMMARY_AGENT_H
#define SUMMARY_AGENT_H

#include "Agent.h"

class SummaryAgent : public Agent
{
public:
    SummaryAgent();

    std::string execute(std::string content) override;
};

#endif