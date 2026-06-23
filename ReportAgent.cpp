#include "ReportAgent.h"
#include <fstream>
#include <algorithm>

ReportAgent::ReportAgent()
    : Agent("Report Agent")
{
}
std::string ReportAgent::execute(std::string content)
{
    std::string filename = content;

    size_t topicPos = content.find("Topic: ");

    if (topicPos != std::string::npos)
    {
        size_t start = topicPos + 7;
        size_t end = content.find('\n', start);

        filename = content.substr(start, end - start);

        std::replace(filename.begin(),
                     filename.end(),
                     ' ',
                     '_');
    }
    else
    {
        filename = "Unknown";
    }

    std::ofstream report(
        "reports/" + filename + "_Report.txt");

    report << content;

    report.close();

    std::ofstream listFile(
        "reports/report_list.txt",
        std::ios::app);

    listFile
        << filename
        << "_Report.txt"
        << std::endl;

    listFile.close();

    return "Report generated: " +
           filename +
           "_Report.txt";
}