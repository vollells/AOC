#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>


int main(){
  std::vector<std::vector<int>> elfCal {};

  std::fstream fs {"input.txt"};
  std::string temp {};

  elfCal.emplace_back();
  while(std::getline(fs, temp, '\n')){
    if (temp == ""){
      elfCal.emplace_back();
    } else {
      elfCal.back().push_back(std::stoi(temp));
    }
  }

  std::vector<int> answer{};
  std::transform(std::begin(elfCal), std::end(elfCal), std::back_inserter(answer),
                 [] (std::vector<int> in){
                   return std::accumulate(std::begin(in), std::end(in), 0);
                 }
                 );

  std::sort(std::begin(answer), std::end(answer), std::greater<int>());

  //std::cout << answer[0] << '\n';
  std::cout << answer[0] + answer[1] + answer[2] << '\n';

  return 0;
}
