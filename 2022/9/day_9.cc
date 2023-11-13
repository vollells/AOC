#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int dist(std::pair<int, int> p1, std::pair<int, int> p2) {
  int x = std::abs(p1.first - p2.first);
  int y = std::abs(p1.second - p2.second);
  return std::pow((x * x) + (y * y), 0.5);
}

std::pair<int, int> move(char dir, const std::pair<int, int> &input) {
  std::pair<int, int> H = input;
  if (dir == 'U') {
    H.second++;
  } else if (dir == 'D') {
    H.second--;
  } else if (dir == 'R') {
    H.first++;
  } else if (dir == 'L') {
    H.first--;
  }
  return H;
}

void moveDiag(std::pair<int, int> &rope, std::pair<int, int> &H) {
  if (rope.first < H.first) {
    rope = move('R', rope);
  } else {
    rope = move('L', rope);
  }
  if (rope.second < H.second) {
    rope = move('U', rope);
  } else {
    rope = move('D', rope);
  }
}

bool moveStr(std::pair<int, int> &rope, std::pair<int, int> &H) {
  bool res = false;
  if (rope.first == H.first && rope.second < H.second) {
    rope = move('U', rope);
    res = true;
  } else if (rope.first == H.first && rope.second >= H.second) {
    rope = move('D', rope);
    res = true;
  } else if (rope.second == H.second && rope.first < H.first) {
    rope = move('R', rope);
    res = true;
  } else if (rope.second == H.second && rope.first >= H.first) {
    rope = move('L', rope);
    res = true;
  }
  return res;
}

int main() {
  std::vector<std::pair<int, int>> rope{10};
  std::set<std::pair<int, int>> visitp1{};
  std::set<std::pair<int, int>> visitp2{};

  std::fstream fs{"input.txt"};
  char dir;
  int steps;
  while (fs >> dir >> steps) {
    for (int i = 0; i < steps; i++) {
      // Move Head
      rope[0] = move(dir, rope[0]);

      // Move Body
      for (int j = 1; j < rope.size(); j++) {
        if (dist(rope[j - 1], rope[j]) > 1) {
          bool moved = moveStr(rope[j], rope[j - 1]);
          if (!moved) {
            moveDiag(rope[j], rope[j - 1]);
          }
        }
      }

      // Print result
      visitp2.insert(rope.back());
      visitp1.insert(rope[1]);
    }
  }

  std::cout << "Part 1: " << visitp1.size() << '\n';
  std::cout << "Part 2: " << visitp2.size() << '\n';
  return 0;
}
