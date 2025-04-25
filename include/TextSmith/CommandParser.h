#pragma once
#include <map>
#include <string>

class CommandParser {
public:
    CommandParser();
    void help();

    void parseCommand(std::string command);

private:
    std::map<std::string, void (CommandParser::*)()> allowedCommands;
};
