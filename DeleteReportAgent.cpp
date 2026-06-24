#include "DeleteReportAgent.h"
#include <cstdio>
#include <fstream>
#include <string>

DeleteReportAgent::DeleteReportAgent()
    : Agent("Delete Report Agent")
{
}
std::string DeleteReportAgent::execute(std::string filename)
{
    std::string path =
        "reports/" + filename;

    if (std::remove(path.c_str()) != 0)
    {
        return "Report not found.";
    }

    std::ifstream input(
        "reports/report_list.txt");

    std::ofstream temp(
        "reports/temp.txt");

    std::string line;

    while (getline(input, line))
    {
        if (line != filename)
        {
            temp << line << std::endl;
        }
    }

    input.close();
    temp.close();

    std::remove(
        "reports/report_list.txt");

    std::rename(
        "reports/temp.txt",
        "reports/report_list.txt");

    return "Report deleted successfully.";
}