#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::fstream fs{"input.txt"};
  std::string input{};
  int countP1 = 0;
  int countP2 = 0;
  while (std::getline(fs, input)) {

    auto itString1 = std::next(input.begin(), input.size()), itString2 = input.begin();
    int stringValue1 = -1, stringValue2 = -1;
    
    auto isnum = [](char c) { return std::isdigit(c); };
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
          std::distance(input.begin(), itString2) <= temp) {
        itString2 = std::next(input.begin(), temp);
        stringValue2 = i;
      }
    }

    auto itDigit1 = std::find_if(input.begin(), input.end(), isnum);
    auto itDigit2 = std::find_if(input.rbegin(), input.rend(), isnum);

    countP1 += 10 * (*itDigit1 - 48) + (*itDigit2 - 48);
    
    countP2 += (std::distance(input.begin(), itDigit1) <= std::distance(input.begin(), itString1) || stringValue1 == -1) ? 10 * (*itDigit1 - 48) : 10 * stringValue1;

    countP2 += (input.size() - std::distance(input.rbegin(), itDigit2) - 1 >= std::distance(input.begin(), itString2) || stringValue2 == -1) ? (*itDigit2 - 48) : stringValue2;

  }
  std::cout << "Part 1: " << countP1 << std::endl;
  std::cout << "Part 2: " << countP2 << std::endl;
}
