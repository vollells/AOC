#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::fstream fs {"input.txt"};

  std::string input;
  std::getline(fs, input);

  for (int i = 4; i <= input.length(); i++){
    std::string subStr = input.substr(i-4, 4);
    bool res = true;
    for (int j = 0; j < subStr.length(); j++){
      for (int k = 0; k < subStr.length(); k++){
        if(j != k){
          res &= (subStr[j] != subStr[k]);
        }
      }
    }
    if (res) {
      std::cout << "Day 1: "<< i << std::endl;
      break;
    }
  }

  for (int i = 14; i <= input.length(); i++){
    std::string subStr = input.substr(i-14, 14);
    bool res = true;
    for (int j = 0; j < subStr.length(); j++){
      for (int k = j; k < subStr.length(); k++){
        if(j != k){
          res &= (subStr[j] != subStr[k]);
        }
      }
    }
    if (res) {
      std::cout << "Day 2: " << i << std::endl;
      break;
    }
  }
}
