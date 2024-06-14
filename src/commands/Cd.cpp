#include <iostream>
#include <filesystem>
#include <deque>
#include <unordered_map>
#include <string>

class Cd : public Command 
{
public:
  void execute(const std::deque<std::string>& args, [[maybe_unused]] const std::unordered_map<std::string, std::string>& known_commands) override 
  {
    std::string path = args[1];
    if (path == "~") path = std::getenv("HOME");
    if (std::filesystem::exists(path)) std::filesystem::current_path(path);
    else std::cout << path << ": No such file or directory" << std::endl;
  }
};