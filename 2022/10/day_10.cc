#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::fstream fs{"input.txt"};

  std::vector<bool> screen(6 * 40, false);

  int lastReadTime = 1, x = 1, sigStrength = 0, sigCount = 0, temp = 0,
      line = 0;
  std::string instr = "noop";
  for (int i = 1; i <= 240; i++) {
    // Start of cycle
    bool read = true && !(instr == "addx" && i - lastReadTime <= 1);
    if (read) {
      fs >> instr;
      if (instr == "addx") {
        fs >> temp;
      }
      lastReadTime = i;
    }

    // During cycle
    int pos = i - (line * 40) - 1;
    screen[i - 1] =
        screen[i - 1] || ((pos == x - 1) || (pos == x) || (pos == x + 1));
    if (i == (40 + line * 40)) {
      line++;
    }
    if (i == (20 + sigCount * 40)) {
      sigStrength += i * x;
      sigCount++;
    }

    // End of cycle
    if ((i - lastReadTime == 1) && (instr == "addx")) {
      x += temp;
    }
  }

  std::cout << "Part 1: " << sigStrength << std::endl;
  std::cout << "Part 2: " << std::endl;
  for (int i = 0; i < 240; i++) {
    if (i != 0 && i % 40 == 0) {
      std::cout << std::endl;
    }
    if (screen[i]) {
      std::cout << '#' << ' ';
    } else {
      std::cout << '.' << ' ';
    }
  }
  std::cout << std::endl;
}
