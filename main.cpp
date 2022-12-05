#include "PngSave.hpp"
int main() {
  std::vector<int> row(1000, 0);
  std::vector<std::vector<int>> test(1000);
  for (auto& item : test) {
    item = row;
  }
  noise::PngSave("Test.png", test);
  return 0;
}