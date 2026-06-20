#include <iostream>

#include "SearchAgent.h"
#include "ReportAgent.h"

int main()
{
    SearchAgent searchAgent;
    ReportAgent reportAgent;

    std::string topic;

    std::cout << "Enter topic: ";
    getline(std::cin, topic);

    std::string result =
        searchAgent.execute(topic);

    std::cout << result << std::endl;

    std::cout << "\nGenerating report...\n";

    std::cout
        << reportAgent.execute(result)
        << std::endl;

    return 0;
}