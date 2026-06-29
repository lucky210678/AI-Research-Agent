#include "SaveSummaryAgent.h"
#include <fstream>
#include <algorithm>

SaveSummaryAgent::SaveSummaryAgent()
    : Agent("Save Summary Agent")
{
}

std::string SaveSummaryAgent::execute(std::string content)
{
    size_t topicPos =
        content.find("Topic:");

    size_t defPos =
        content.find("Definition:");

    if (topicPos == std::string::npos ||
        defPos == std::string::npos)
    {
        return "Could not save summary.";
    }

    std::string topic =
        content.substr(
            topicPos + 6,
            defPos - (topicPos + 6));
while (!topic.empty() &&
       (topic[0] == ' ' || topic[0] == '\n'))
{
    topic.erase(0, 1);
}

while (!topic.empty() &&
       (topic[topic.size() - 1] == ' ' ||
        topic[topic.size() - 1] == '\n' ||
        topic[topic.size() - 1] == '\r'))
{
    topic.pop_back();
}
std::replace(
    topic.begin(),
    topic.end(),
    ' ',
    '_');
    while (!topic.empty() &&
           (topic[0] == ' ' ||
            topic[0] == '\n'))
    {
        topic.erase(0, 1);
    }

    std::replace(
        topic.begin(),
        topic.end(),
        ' ',
        '_');

    std::ofstream file(
    "summaries/" +
    topic +
    "_Summary.txt");
    if (!file)
{
    return "Could not create summary file.";
}

    file << content;

    file.close();
    std::ofstream listFile(
    "summaries/summary_list.txt",
    std::ios::app);

listFile
    << topic
    << "_Summary.txt"
    << std::endl;

listFile.close();

    return "Summary saved: "
           + topic +
           "_Summary.txt";
}