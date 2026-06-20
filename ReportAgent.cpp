#include "ReportAgent.h"
#include <fstream>

ReportAgent::ReportAgent()
    : Agent("Report Agent")
{
}

std::string ReportAgent::execute(std::string input)
{
    std::ofstream report("reports/report.txt");

    report << "Research Report\n";
    report << "=====================\n";
    report << "Topic: " << input << "\n";

    report.close();

    return "Report generated successfully.";
}