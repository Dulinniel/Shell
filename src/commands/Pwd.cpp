#include <iostream>
#include <filesystem>
#include <deque>
#include <unordered_map>
#include <string>

class Pwd: public Command 
{
public:
  void execute([[maybe_unused]] const std::deque<std::string>& args, [[maybe_unused]] const std::unordered_map<std::string, std::string>& known_commands = {}) override 
  {
    std::cout << std::filesystem::current_path().string() << std::endl;
  }
};