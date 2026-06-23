#include "ReportViewerAgent.h"
#include <fstream>

ReportViewerAgent::ReportViewerAgent()
    : Agent("Report Viewer Agent")
{
}

std::string ReportViewerAgent::execute(std::string input)
{
    std::ifstream file(
        "reports/report_list.txt");

    if (!file)
    {
        return "No reports found.";
    }

    std::string result =
        "Available Reports\n"
        "====================\n";

    std::string line;
    int count = 0;

    while (getline(file, line))
    {
        result +=
            std::to_string(++count)
            + ". "
            + line
            + "\n";
    }

    if (count == 0)
    {
        result += "No reports found.\n";
    }

    return result;
}