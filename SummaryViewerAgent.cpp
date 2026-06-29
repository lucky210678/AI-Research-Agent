#include "SummaryViewerAgent.h"
#include <fstream>

SummaryViewerAgent::SummaryViewerAgent()
    : Agent("Summary Viewer Agent")
{
}

std::string SummaryViewerAgent::execute(std::string input)
{
    std::ifstream file(
        "summaries/summary_list.txt");

    if (!file)
    {
        return "No summaries found.";
    }

    std::string line;

    std::string result =
        "Available Summaries\n"
        "====================\n";

    int count = 1;

    while (getline(file, line))
    {
        result +=
            std::to_string(count)
            + ". "
            + line
            + "\n";

        count++;
    }

    file.close();

    return result;
}