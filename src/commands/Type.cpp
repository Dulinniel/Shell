#include <iostream>
#include <string>
#include <deque>
#include <unordered_map>

class Type : public Command 
{
public:
  void execute(const std::deque<std::string>& args, const std::unordered_map<std::string, std::string>& known_commands) override {
    auto parameter = known_commands.find(args[1]);
    if (parameter == known_commands.end()) 
    {
      std::string directory = check_env(args[1]);
      if (directory.empty()) std::cout << args[1] << ": not found" << std::endl;
      else std::cout << args[1] << " is " << directory << std::endl;
    } else std::cout << parameter->second << std::endl;
  }
};