#include <iostream>
#include <fstream>

std::string replaceOccurrences(const std::string &content, const std::string &s1, const std::string &s2)
{
    if (s1.empty())
        return content;

    std::string modifiedContent = content;
    size_t pos = 0;

    while ((pos = modifiedContent.find(s1, pos)) != std::string::npos)
    {
        modifiedContent.erase(pos, s1.length());
        modifiedContent.insert(pos, s2);
        pos += s2.length();
    }

    return modifiedContent;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Couldn't open the file" << filename << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(inputFile, line))
    {
        content += line;
        if (!inputFile.eof())
            content += "\n";
    }
    inputFile.close();

    std::string modifiedContent = replaceOccurrences(content, s1, s2);

    std::ofstream outputFile(filename + ".replace");
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Couldn't create the file" << filename << ".replace" << std::endl;
        return 1;
    }

    outputFile << modifiedContent;
    outputFile.close();

    std::cout << "File " << filename << ".replace created successfully." << std::endl;
    return 0;
}