#include <iostream>
#include <deque>
#include <unordered_map>
#include <string>

class Echo : public Command 
{
public:
  void execute(const std::deque<std::string>& args, [[maybe_unused]] const std::unordered_map<std::string, std::string>& known_commands) override 
  {
    std::string text = implode_deque(args);
    std::cout << text << std::endl;
  }
};