#include <TextSmith/CommandParser.h>
#include <iostream>

CommandParser::CommandParser() {
    allowedCommands["help"] = &CommandParser::help;
}

void CommandParser::help() {
    std::cout << "Available commands:\n";
    for (const auto& cmd : allowedCommands) {
        std::cout << "- " << cmd.first << "\n";
    }
}


void CommandParser::parseCommand(std::string command) {
    auto it = allowedCommands.find(command);
    if (it != allowedCommands.end()) {
        (this->*(it->second))();
    } else {
        std::cout << "unknow command" << command << "\n";
    }
}
