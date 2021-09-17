#include <string>
#include <vector>

#include "lib.h"
#include "version.h"

int version() { return PROJECT_VERSION_PATCH; }

Ip_v4::Ip_v4(const std::string &adress) : valid(true) {
  for (const std::string &part : split(adress, '.')) {
    int int_part = std::stoi(part);
    if (is_valid_part(int_part)) {
      parts.push_back(int_part);
    } else {
      valid = false;
    }
  }
}

std::vector<std::string> split(const std::string &str, char d) {
  std::vector<std::string> r;

  std::string::size_type start = 0;
  std::string::size_type stop = str.find_first_of(d);
  while (stop != std::string::npos) {
    r.push_back(str.substr(start, stop - start));

    start = stop + 1;
    stop = str.find_first_of(d, start);
  }

  r.push_back(str.substr(start));

  return r;
}