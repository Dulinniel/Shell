#include "../environement.cpp"

class Command 
{
public:
	virtual void execute([[maybe_unused]] const std::deque<std::string>& args, [[maybe_unused]] const std::unordered_map<std::string, std::string>& known_commands) = 0;
	virtual ~Command() = default;
};
