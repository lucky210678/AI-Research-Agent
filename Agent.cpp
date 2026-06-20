#include "Agent.h"
#include <iostream>

Agent::Agent(std::string name)
{
    agentName = name;
}

void Agent::displayAgentInfo()
{
    std::cout << "Running Agent: "
              << agentName
              << std::endl;
}