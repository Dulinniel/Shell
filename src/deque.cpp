#include <string>
#include <deque>

std::deque<std::string> split(std::string to_split, std::string delimiter = " ")
{
  std::string token;
  std::deque<std::string> splitted_string;
  size_t position = 0;
  while ((position = to_split.find(delimiter)) != std::string::npos) {
    token = to_split.substr(0, position);
    to_split.erase(0, position + delimiter.length());
    splitted_string.push_back(token);
  }
  splitted_string.push_back(to_split);

  return splitted_string;
}

std::string implode_deque(std::deque<std::string> command_content)
{
  command_content.pop_front();
  command_content.shrink_to_fit();
  std::string text = "";
  for ( size_t i = 0; i < command_content.size(); i++)
  {
    text += command_content[i];
    text += " ";
  }
  text.pop_back();
  command_content.clear();
  return text;
}
