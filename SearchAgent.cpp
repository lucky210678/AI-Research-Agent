#include "SearchAgent.h"
#include <fstream>
#include <string>

SearchAgent::SearchAgent()
    : Agent("Search Agent")
{
}

std::string SearchAgent::execute(std::string input)
{
    std::ifstream file("data/research.txt");

    if (!file)
    {
        return "Could not open file.";
    }

    std::string line;

    while (getline(file, line))
    {
        size_t firstPipe = line.find('|');

        if (firstPipe != std::string::npos)
        {
            size_t secondPipe = line.find('|', firstPipe + 1);

            if (secondPipe != std::string::npos)
            {
                std::string topic = line.substr(0, firstPipe);

                std::string definition =
                    line.substr(firstPipe + 1,
                                secondPipe - firstPipe - 1);

                std::string applications =
                    line.substr(secondPipe + 1);

                if (topic == input)
                {
                    return
                        "Research Result\n"
                        "-------------------------\n"
                        "Topic: " + topic +
                        "\n\nDefinition:\n" + definition +
                        "\n\nApplications:\n" + applications;
                }
            }
        }
    }

    return "Topic not found.";
}