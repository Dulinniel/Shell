#include <deque>
#include <unordered_map>
#include <string>

class Exit : public Command 
{
public:
  void execute(const std::deque<std::string>& args, [[maybe_unused]] const std::unordered_map<std::string, std::string>& known_commands) override 
  {
    int status = std::stoi(args[1]);
    std::exit(status);
  }
};