#include <iostream>
#include<fstream>
#include "SearchAgent.h"
#include "ReportAgent.h"
#include "ReportViewerAgent.h"
#include "OpenReportAgent.h"
#include "StatisticsAgent.h"
int main()
{
    SearchAgent searchAgent;
    ReportAgent reportAgent;
    ReportViewerAgent viewerAgent;
    OpenReportAgent openReportAgent; 
    StatisticsAgent statsAgent;
    int choice;

    do
    {
        std::cout << "\n===== AI Research Agent =====\n";
        std::cout << "1. Search Topic\n";
        std::cout << "2. Generate Report\n";
        std::cout << "3. View Reports\n";
        std::cout << "4. Open Report\n";
        std::cout << "5. Statistics\n";
        std::cout << "6. Exit\n";

        std::cout << "Enter Choice: ";

        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1)
        {
           std::string topic;

std::cout << "Enter Topic: ";
getline(std::cin, topic);

std::ofstream history(
    "data/search_history.txt",
    std::ios::app);

history << topic << std::endl;

history.close();

std::cout << searchAgent.execute(topic)
          << std::endl;
        }

        else if (choice == 2)
        {
            std::string topic;

            std::cout << "Enter Topic: ";
            getline(std::cin, topic);
            std::ofstream history (
    "data/search_history.txt",
    std::ios::app);

history << topic << std::endl;

history.close();

            std::string result =
                searchAgent.execute(topic);

            std::cout
                << reportAgent.execute(result)
                << std::endl;
        }

    else if (choice == 3)
{
    std::cout
        << viewerAgent.execute("")
        << std::endl;
}
else if (choice == 4)
{
    std::string filename;

    std::cout
        << "Enter Report Filename: ";

    getline(std::cin, filename);

    std::cout
        << openReportAgent.execute(filename)
        << std::endl;
}
else if (choice == 5)
{
    std::cout
        << statsAgent.execute("")
        << std::endl;

}
    } while(choice != 6);

    std::cout << "Goodbye!\n";
    return 0;
}