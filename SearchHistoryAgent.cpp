#include "SearchHistoryAgent.h"
#include <fstream>

SearchHistoryAgent::SearchHistoryAgent()
    : Agent("Search History Agent")
{
}

std::string SearchHistoryAgent::execute(std::string input)
{
    std::ifstream history(
        "data/search_history.txt");

    if (!history)
    {
        return "No search history found.";
    }

    std::string result =
        "===== Search History =====\n\n";

    std::string line;
    int count = 0;

    while (getline(history, line))
    {
        result +=
            std::to_string(++count)
            + ". "
            + line
            + "\n";
    }

    history.close();

    if (count == 0)
    {
        result += "No searches recorded.\n";
    }

    return result;
}