#include <algorithm>
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

  elfCal.push_back({});
  while(std::getline(fs, temp, '\n')){
    std::cout << temp;
    if (temp == " "){
      elfCal.push_back({});
    } else {
      elfCal.back().push_back(std::stoi(temp));
    }

  }

  std::vector<int> answer{};
  std::transform(std::begin(elfCal), std::end(elfCal), std::begin(answer),
                 [] (std::vector<int> in){
                   return std::accumulate(std::begin(in), std::end(in), 0);
                 }
                 );

  std::cout << std::max_element(std::begin(answer), std::end(answer)) - std::begin(answer);
  return 0;
}
