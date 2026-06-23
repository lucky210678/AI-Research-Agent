#include "StatisticsAgent.h"
#include <fstream>
#include <map>
#include <string>

StatisticsAgent::StatisticsAgent()
    : Agent("Statistics Agent")
{
}

std::string StatisticsAgent::execute(std::string input)
{
    int searchCount = 0;
    int reportCount = 0;

    std::ifstream searches(
        "data/search_history.txt");

    std::string line;
    std::map<std::string, int> topicCount;

   while (getline(searches, line))
{
    searchCount++;
    topicCount[line]++;
}
    searches.close();
    std::string mostSearchedTopic = "None";
int maxCount = 0;

for (auto pair : topicCount)
{
    if (pair.second > maxCount)
    {
        maxCount = pair.second;
        mostSearchedTopic = pair.first;
    }
}

    std::ifstream reports(
        "reports/report_list.txt");

    while (getline(reports, line))
    {
        reportCount++;
    }

    reports.close();

    std::string result =
        "===== Statistics =====\n\n";

    result +=
        "Total Searches: "
        + std::to_string(searchCount)
        + "\n";

    result +=
        "Total Reports: "
        + std::to_string(reportCount)
        + "\n";
        result += "\nMost Searched Topic: ";

result += mostSearchedTopic;

result += " (" +
          std::to_string(maxCount) +
          " searches)\n";

    return result;
}
