#pragma once
#include <array>
#include <optional>
#include <string>
#include <vector>

int version();

class Ip_v4 {
public:
  explicit Ip_v4(const std::string &adress);
  Ip_v4(const Ip_v4 &other);
  Ip_v4(Ip_v4 &&other);
  Ip_v4 &operator=(const Ip_v4 &other);
  Ip_v4 &operator=(Ip_v4 &&other);

  bool is_valid() { return valid; }
  std::optional<int> get_part(int index) {
    std::optional<int> result;
    if (index >= 0 || index <= number_of_parts) {
      result.emplace(parts[index]);
    }
    return result;
  }

  static const int number_of_parts = 4;

private:
  std::array<int, number_of_parts> parts;
  bool is_valid_part(int p) { return p >= 0 && p <= max_value; }
  bool valid;
  const int max_value = 255;
};

std::vector<std::string> split(const std::string &str, char d);