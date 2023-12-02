#include <numeric>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {

  // RGB
  std::vector<int> colorMax = {12, 13, 14};
  int countP1 = 0, countP2 = 0;
  std::string inputLine = {};

  for (int i = 1; std::getline(std::cin, inputLine); i++) {
    std::istringstream ssics{inputLine};
    std::string inputClauses{};
    bool possible = true;
    std::vector<int> currColorMax{0, 0, 0};
    while (std::getline(ssics, inputClauses, ';')) {
      std::istringstream ssic{inputClauses};
      std::string inputClause{};
      while (std::getline(ssic, inputClause, ',')) {
        int num;
        std::string color{};
        std::istringstream{inputClause} >> num >> color;
        std::cout << num << ' ' << color << ' ';
        if (color == "red") {
          currColorMax[0] = std::max(num, currColorMax[0]);
          possible &= colorMax[0] >= num;
        } else if (color == "green") {
          currColorMax[1] = std::max(num, currColorMax[1]);
          possible &= colorMax[1] >= num;
        } else if (color == "blue") {
          currColorMax[2] = std::max(num, currColorMax[2]);
          possible &= colorMax[2] >= num;
        }
      }
      std::cout << possible << std::endl;
    }
    countP1 += possible ? i : 0;
    countP2 += std::accumulate(std::begin(currColorMax), std::end(currColorMax),
                               1, std::multiplies<int>());
  }
  std::cout << "Part 1: " << countP1 << std::endl;
  std::cout << "Part 2: " << countP2 << std::endl;

  return 0;
}
