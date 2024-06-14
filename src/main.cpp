#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>
#include <cstdlib>
#include <filesystem>
#include <memory>

#include "./commands/Command.cpp"
#include "./commands/Echo.cpp"
#include "./commands/Exit.cpp"
#include "./commands/Pwd.cpp"
#include "./commands/Cd.cpp"
#include "./commands/Type.cpp"

// Fonction pour exécuter les commandes
void execute_command(const std::deque<std::string> &command_content, const std::unordered_map<std::string, std::string> &known_commands, const std::unordered_map<std::string, std::shared_ptr<Command>> &command_map)
{
  if (command_content.empty()) return;

  auto it = command_map.find(command_content[0]);
  if (it != command_map.end()) it->second->execute(command_content, known_commands);
  else std::cout << "Unknown command: " << command_content[0] << std::endl;
}

void execute_from_path(std::string command)
{
  std::string parameters;
  std::deque command_content = split(command);
  std::string found_command = check_env(command_content[0]);
  if ( found_command != "" )
  { 
    if ( command_content.size() > 1 ) parameters = implode_deque(command_content);
    else parameters = "";
    std::string full_command = found_command + " " + parameters;
    system(full_command.c_str());
  } else std::cout << command << ": not found" << std::endl;
}

std::unordered_map<std::string, std::string> create_commands()
{
  std::unordered_map<std::string, std::string> commands;
  commands.insert({
      {"exit", "exit is a shell builtin"},
      {"echo", "echo is a shell builtin"},
      {"type", "type is a shell builtin"},
      {"pwd", "pwd is a shell builtin"},
      {"cd", "cd is a shell builtin"}
    });

  return commands;
}

bool validate_command(std::string command, std::unordered_map<std::string, std::string> known_commands)
{
  bool validate = true;
  if ( known_commands.count(command) <= 0 ) validate = false;
  return validate;
}

int main() {

  std::unordered_map<std::string, std::shared_ptr<Command>> command_map = {
    {"exit", std::make_shared<Exit>()},
    {"echo", std::make_shared<Echo>()},
    {"type", std::make_shared<Type>()},
    {"pwd", std::make_shared<Pwd>()},
    {"cd", std::make_shared<Cd>()}
  };

  std::unordered_map<std::string, std::string> commands = create_commands();

  while ( true )
  {

    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    std::cout << std::filesystem::current_path().string() << " " << "$ ";

    std::string input;
    std::getline(std::cin, input);

    std::deque<std::string> command_content = split(input);
    bool isCommandValidate = validate_command(command_content[0], commands);

    if ( isCommandValidate ) execute_command(command_content, commands, command_map);
    else execute_from_path(input);

  }

  return 0;
}
