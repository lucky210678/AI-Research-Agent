#include "OpenReportAgent.h"
#include <fstream>

OpenReportAgent::OpenReportAgent()
    : Agent("Open Report Agent")
{
}

std::string OpenReportAgent::execute(std::string filename)
{
    std::ifstream file(
        "reports/" + filename);

    if (!file)
    {
        return "Report not found.";
    }

    std::string result;
    std::string line;

    while (getline(file, line))
    {
        result += line + "\n";
    }

    file.close();

    return result;
}