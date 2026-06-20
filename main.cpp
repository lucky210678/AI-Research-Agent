#include <iostream>
#include "ReportAgent.h"

int main()
{
    ReportAgent reportAgent;

    std::string topic;

    std::cout << "Enter topic: ";
    getline(std::cin, topic);

    std::cout << reportAgent.execute(topic);

    return 0;
}