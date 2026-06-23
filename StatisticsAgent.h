#ifndef STATISTICS_AGENT_H
#define STATISTICS_AGENT_H

#include "Agent.h"

class StatisticsAgent : public Agent
{
public:
    StatisticsAgent();

    std::string execute(std::string input) override;
};

#endif