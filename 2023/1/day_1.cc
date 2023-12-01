#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::fstream fs{"input_small_2.txt"};
  std::string input{};
  int countP1 = 0;
  int countP2 = 0;
  while (std::getline(fs, input)) {

    auto isnum = [](char c) { return std::isdigit(c); };

    // Pos, value
    auto itString1 = input.begin();
    int stringValue1 = -1;
    auto itString2 = input.rbegin();
    int stringValue2 = -1;
    std::vector<std::string> values = {"one", "two",   "three", "four", "five",
                                       "six", "seven", "eight", "nine"};

    for (int i = 1; i <= values.size(); i++) {
      auto temp = input.find(values[i - 1]);
      if (temp != input.npos &&
          std::distance(input.begin(), itString1) >= temp) {
        itString1 = std::next(input.begin(), temp);
        stringValue1 = i;
      }
      temp = input.rfind(values[i - 1]);
      if (temp != input.npos &&
          std::distance(input.rbegin(), itString2) >= temp) {
        itString2 = std::next(input.rbegin(), temp);
        stringValue2 = i;
      }
    }

    auto itDigit1 = std::find_if(input.begin(), input.end(), isnum);
    auto itDigit2 = std::find_if(input.rbegin(), input.rend(), isnum);

    std::cout << stringValue1 << ' ';
    std::cout << stringValue2 << std::endl;

    std::string numberP1{};
    numberP1.push_back(*itDigit1);
    numberP1.push_back(*itDigit2);
    std::string numberP2{};

    countP1 += std::stoi(numberP1);
  }
  std::cout << "Part 1: " << countP1 << std::endl;
}
