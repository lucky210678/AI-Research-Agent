#ifndef SEARCH_AGENT_H
#define SEARCH_AGENT_H

#include "Agent.h"

class SearchAgent : public Agent
{
public:
    SearchAgent();

    std::string execute(std::string input) override;
};

#endif