#include <cctype>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

int main() {
  std::fstream fs{"input.txt"};

  std::vector<std::stack<char>> stacks{9};
  std::vector<std::string> inputStr{};
  std::string input;
  while (std::getline(fs, input)) {
    if (input == " 1   2   3   4   5   6   7   8   9 ") {
      break;
    }
    inputStr.push_back(input);
  }

  for (int i = inputStr.size() - 1; i >= 0; i--) {
    for (int j = 1, q = 0; j < input.length(); j += 4, q++) {
      if (inputStr[i][j] != ' ') {
        stacks[q].push(inputStr[i][j]);
      }
    }
  }

  std::getline(fs, input);

  while (std::getline(fs, input)) {
    std::stringstream ss{input};
    std::string input2;
    std::vector<int> params(3, 0);
    std::vector<std::string> strParams{};

    while (std::getline(ss, input2, ' ')) {
      strParams.push_back(input2);
    }
    for (int i = 1, p = 0; i < strParams.size(); i += 2, p += 1) {
      params[p] = std::stoi(strParams[i]);
    }

    // Remove lifo for part 1
    std::stack<char> lifo{};
    for (int i = 0; i < params[0]; i++) {
      lifo.push(stacks[params[1] - 1].top());
      stacks[params[1] - 1].pop();
    }
    for (int i = 0; i < params[0]; i++) {
      stacks[params[2] - 1].push(lifo.top());
      lifo.pop();
    }
  }

  for (std::stack<char> stack : stacks) {

    if (!stack.empty()) {
      std::cout << stack.top();
    } else {
      std::cout << ' ';
    }
  }
  std::cout << std::endl;
  return 0;
}
