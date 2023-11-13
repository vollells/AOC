#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::fstream fs{"input.txt"};
  std::pair<std::string, std::string> firstS, secondS;
  int symCounter = 0, inclCounter = 0;

  while (std::getline(fs, firstS.first, '-') &&
         std::getline(fs, firstS.second, ',') &&
         std::getline(fs, secondS.first, '-') &&
         std::getline(fs, secondS.second)) {
    std::vector<int> elf1, elf2;
    for (int i = std::stoi(firstS.first); i <= std::stoi(firstS.second); i++) {
      elf1.push_back(i);
    }
    for (int i = std::stoi(secondS.first); i <= std::stoi(secondS.second);
         i++) {
      elf2.push_back(i);
    }

    // part1
    inclCounter += std::includes(std::begin(elf1), std::end(elf1),
                                 std::begin(elf2), std::end(elf2)) ||
                   std::includes(std::begin(elf2), std::end(elf2),
                                 std::begin(elf1), std::end(elf1));

    // part2
    std::vector<int> result;
    std::set_intersection(std::begin(elf1), std::end(elf1), std::begin(elf2),
                          std::end(elf2), std::back_inserter(result));
    symCounter += (result.size() != 0);
  }
  std::cout << inclCounter << ' ' << symCounter << std::endl;
}
