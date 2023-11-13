#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>

void part1() {
  std::fstream fs {"input.txt"};
  std::string first, second;
  int prio = 0;

  while(std::getline(fs, first)){
    second = first.substr(first.length()/2,first.length());
    first = first.substr(0,first.length()/2);

    std::string result;
    std::sort(std::begin(first), std::end(first));
    std::sort(std::begin(second), std::end(second));
    std::set_intersection(std::begin(first),
                          std::end(first),
                          std::begin(second),
                          std::end(second),
                          std::back_inserter(result));

    char common = char(result[0]);

    if (common < 'a'){
      prio += common - 'A' + 27;
      // std::cout<< "Common: " << common << " Prio: " << common - 'A' + 27 << std::endl;
    } else {
      prio += common - 'a' + 1;
      // std::cout<< "Common: " << common << " Prio: " << common - 'a' + 1 << std::endl;
    }
  }
  std::cout << prio << std::endl;
}

void part2() {
  std::fstream fs {"input.txt"};
  std::vector<std::string> regS {3};

  int prio = 0;
  while (fs >> regS[0] >> regS[1] >> regS[2]){
    for (int i = 0; i < 3; i++){
      std::sort(std::begin(regS[i]), std::end(regS[i]));
    }

    std::string temp;
    std::set_intersection(std::begin(regS[0]),
                          std::end(regS[0]),
                          std::begin(regS[1]),
                          std::end(regS[1]),
                          std::back_inserter(temp));

    std::string res;
    std::set_intersection(std::begin(temp),
                          std::end(temp),
                          std::begin(regS[2]),
                          std::end(regS[2]),
                          std::back_inserter(res));
    char result = res[0];
    if (result < 'a'){
      prio += result - 'A' + 27;
      // std::cout<< "Result: " << result << " Prio: " << result - 'A' + 27 << std::endl;
    } else {
      prio += result - 'a' + 1;
      // std::cout<< "Result: " << result << " Prio: " << result - 'a' + 1 << std::endl;
    }
  }
  std::cout << prio << std::endl;
}

int main() {
  //part1();
  part2();
  return 0;
}
