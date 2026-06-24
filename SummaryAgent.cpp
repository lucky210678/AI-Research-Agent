#include "SummaryAgent.h"
#include <algorithm>

SummaryAgent::SummaryAgent()
    : Agent("Summary Agent")
{
}
std::string SummaryAgent::execute(std::string content)
{
    size_t topicPos =
        content.find("Topic:");

    size_t defPos =
        content.find("Definition:");

    size_t appPos =
        content.find("Applications:");

    if (topicPos == std::string::npos ||
        defPos == std::string::npos ||
        appPos == std::string::npos)
    {
        return "Could not generate summary.";
    }

    std::string topic =
        content.substr(
            topicPos + 6,
            defPos - (topicPos + 6));

    std::string definition =
        content.substr(
            defPos + 12,
            appPos - (defPos + 12));

    std::string applications =
        content.substr(
            appPos + 13);
            while (!topic.empty() &&
       (topic[0] == ' ' || topic[0] == '\n'))
{
    topic.erase(0, 1);
}

while (!definition.empty() &&
       (definition[0] == ' ' || definition[0] == '\n'))
{
    definition.erase(0, 1);
}

while (!applications.empty() &&
       (applications[0] == ' ' || applications[0] == '\n'))
{
    applications.erase(0, 1);
}

    std::string summary =
        "===== Summary =====\n\n";

    summary += topic;
    summary += " is ";
    summary += definition;
    summary += ". It is commonly used in ";
    summary += applications;
    summary += ".";

    return summary;
}