#ifndef KEYWORD_EXTRACTION_AGENT_H
#define KEYWORD_EXTRACTION_AGENT_H

#include "Agent.h"

class KeywordExtractionAgent : public Agent
{
public:
    KeywordExtractionAgent();

    std::string execute(std::string content) override;
};

#endif