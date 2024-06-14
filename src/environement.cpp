#include <string>
#include <filesystem>

#include "deque.cpp"

std::string check_env(std::string command)
{
  bool in_env = false;
  const std::string PATH = std::getenv("PATH");
  std::string directory = "";
  std::deque<std::string> path = split(PATH, ":");
  size_t i = 0;
  while ( !in_env && i != path.size() )
  {
    directory = path.at(i) + "/" + command;
    if ( std::filesystem::exists(directory) ) in_env = true;
    else directory = "";
    i++;
  }

  return directory;
}
