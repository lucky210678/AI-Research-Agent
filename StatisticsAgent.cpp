#include "StatisticsAgent.h"
#include <fstream>

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

    while (getline(searches, line))
    {
        searchCount++;
    }

    searches.close();

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

    return result;
}
