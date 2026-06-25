#ifndef SAVE_SUMMARY_AGENT_H
#define SAVE_SUMMARY_AGENT_H

#include "Agent.h"

class SaveSummaryAgent : public Agent
{
public:
    SaveSummaryAgent();

    std::string execute(std::string content) override;
};

#endif