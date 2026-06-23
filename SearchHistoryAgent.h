#ifndef SEARCH_HISTORY_AGENT_H
#define SEARCH_HISTORY_AGENT_H

#include "Agent.h"

class SearchHistoryAgent : public Agent
{
public:
    SearchHistoryAgent();

    std::string execute(std::string input) override;
};

#endif