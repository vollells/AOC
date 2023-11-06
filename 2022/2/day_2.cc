#include <cstddef>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

char modify(char enemey, int offset) {
  //returns winning char from enemy
  char output = enemey + offset;
  if (output > 'C') {
    output = 'A';
  } else if (output < 'A') {
    output = 'C';
  }
  return output;
}

void part2() {
    std::fstream fs {"input.txt"};
  std::string temp {};

  int points = 0;
  while(std::getline(fs, temp, '\n')){
    std::stringstream ss {temp};
    char enemy, me;
    ss >> enemy >> me;
    int offset = me - 'Y';
    me = modify(enemy, offset);

    if (me == enemy){
      points += 3 + me - 'A' + 1;
    } else if (me == modify(enemy, 1)){
      points += 6 + me - 'A' + 1;
    } else {
      points += me - 'A' + 1;
    }
  }

  std::cout << points << '\n';
}

void part1 (){
  std::fstream fs {"input.txt"};
  std::string temp {};

  int points = 0;
  while(std::getline(fs, temp, '\n')){
    std::stringstream ss {temp};
    char enemy, me;
    ss >> enemy >> me;
    me = me - ('X' - 'A');

    if (me == enemy){
      points += 3 + me - 'A' + 1;
    } else if (me == modify(enemy, 1)){
      points += 6 + me - 'A' + 1;
    } else {
      points += me - 'A' + 1;
    }
  }

  std::cout << points << '\n';
}

int main(){
  part1();
  part2();
}
