#ifndef AGENT_H
#define AGENT_H

#include <string>

class Agent
{
protected:
    std::string agentName;

public:
    Agent(std::string name);

    void displayAgentInfo();

    virtual std::string execute(std::string input) = 0;

    virtual ~Agent() {}
};

#endif