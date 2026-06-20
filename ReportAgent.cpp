#include "ReportAgent.h"
#include <fstream>

ReportAgent::ReportAgent()
    : Agent("Report Agent")
{
}

std::string ReportAgent::execute(std::string content)
{
    std::ofstream report("reports/report.txt");

    report << content;

    report.close();

    return "Report generated successfully.";
}