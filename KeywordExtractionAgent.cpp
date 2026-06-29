#include "KeywordExtractionAgent.h"
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
KeywordExtractionAgent::KeywordExtractionAgent()
    : Agent("Keyword Extraction Agent")
{
}
std::string KeywordExtractionAgent::execute(std::string content)
{
    std::stringstream ss(content);

    std::string word;

    std::map<std::string, int> keywords;

    std::set<std::string> stopWords =
    {
        "the","and","is","are","of",
        "to","in","on","for","with",
        "used","using","that","this",
        "from","into","result","research",
        "topic","definition","applications"
    };

    while (ss >> word)
    {
        word.erase(
            std::remove_if(
                word.begin(),
                word.end(),
                ::ispunct),
            word.end());

        std::transform(
            word.begin(),
            word.end(),
            word.begin(),
            ::tolower);

        if (word.length() > 4 &&
            stopWords.find(word) == stopWords.end())
        {
            keywords[word]++;
        }
    }

    std::string result =
        "===== Keywords =====\n\n";

    for (const auto& item : keywords)
{
    result += item.first;
    result += " : ";
    result += std::to_string(item.second);
    result += "\n";
}

    return result;
}