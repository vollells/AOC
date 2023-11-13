#include <utility>
#include <cmath>
#include <iostream>
#include <set>
#include <fstream>
#include <vector>

int dist(std::pair<int,int> p1, std::pair<int,int> p2) {
  int x = std::abs(p1.first - p2.first);
  int y = std::abs(p1.second - p2.second);
  return std::pow((x*x) + (y*y), 0.5);
}

std::pair<int,int> move(char dir, const std::pair<int,int>&  input) {
  std::pair<int,int> H = input;
  if (dir == 'U'){
    H.second++;
  } else if (dir == 'D'){
    H.second--;
  } else if (dir == 'R'){
    H.first++;
  } else if (dir == 'L'){
    H.first--;
  }
  return H;
}

int main() {
  std::vector<std::pair<int,int>> rope {10};
  std::vector<char> directions {'U','D','L','R'};
  std::set<std::pair<int, int>> visit {};

  std::fstream fs {"input_medium.txt"};
  char dir;
  int steps;
  while (fs >> dir >> steps ){
    for (int i = 0; i < steps; i++){
      rope[0] = move(dir, rope[0]);
      for (int i = 1; i < rope.size(); i++){
        if (dist(rope[i-1], rope[i]) > 1){
          std::pair<char, int> closestP = std::make_pair('U', 1000);
          for (char potDir : directions){
            int newDist = dist(move(potDir,rope[i-1]), rope[i]);
            if (newDist < closestP.second){
              closestP = std::make_pair(potDir,newDist);
            }
          }
          //Use closestp to determine the what point to move rope tail.
        }
      }
      visit.insert(rope.back());
    }
  }
  std::cout << visit.size();
  return 0;
}

  // std::pair<int,int> H = std::make_pair(0, 0);
  // std::pair<int,int> T = std::make_pair(0, 0);
  // std::set<std::pair<int, int>> visit {};

  // std::fstream fs {"input.txt"};
  // char dir;
  // int steps;
  // while (fs >> dir >> steps ){
  //   for (int i = 0; i < steps; i++){
  //     H = move(dir,H);
  //     if (dist(H, T) > 1){
  //       if (dir == 'U'){
  //         T = move('D', H);
  //       } else if (dir == 'D'){
  //         T = move('U', H);
  //       } else if (dir == 'R'){
  //         T = move('L', H);
  //       } else if (dir == 'L'){
  //         T = move('R', H);
  //       }
  //     }
  //     visit.insert(T);
  //   }
  // }
  // std::cout << visit.size();
  // return 0;
