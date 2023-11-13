#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::fstream fs{"input.txt"};
  std::vector<std::vector<int>> forest{};

  std::string input;
  while (std::getline(fs, input)) {
    forest.emplace_back();
    for (char c : input) {
      forest.back().push_back(c);
    }
  }

  std::vector<std::vector<bool>> visForest(
      forest.size(), std::vector<bool>(forest[0].size(), false));

  int tallestTree = -1;
  for(int y = 0; y < forest.size(); y++){
    tallestTree = 0;
    for(int x = 0; x < forest[0].size(); x++){
      if (forest[y][x] > tallestTree){
        visForest[y][x] = true;
        tallestTree = forest[y][x];
        if(tallestTree == 9){
          break;
        }
      } 
    }
    tallestTree = 0;
    for(int x = forest[0].size()-1; x >= 0; x--){
      if (forest[y][x] > tallestTree){
        visForest[y][x] = true;
        tallestTree = forest[y][x];
        if(tallestTree == 9){
          break;
        }
      } 
    }
  }
  for(int x = 0; x < forest[0].size(); x++){
    tallestTree = 0;
    for(int y = 0; y < forest.size(); y++){
      if (forest[y][x] > tallestTree){
        visForest[y][x] = true;
        tallestTree = forest[y][x];
        if(tallestTree == 9){
          break;
        }
      } 
    }
    tallestTree = 0;
    for(int y = forest.size() -1; y >= 0; y--){
      if (forest[y][x] > tallestTree){
        visForest[y][x] = true;
        tallestTree = forest[y][x];
        if(tallestTree == 9){
          break;
        }
      } 
    }
  }

  std::vector<std::vector<int>> pointForest(
      forest.size(), std::vector<int>(forest[0].size(), 1));
  
  int counter = 0;
  for (int y = 0; y < forest.size(); y++){
    for (int x = 0; x < forest[0].size(); x++){
      if (visForest[y][x]){
        std::cout << 'x' << ' '; 
        counter++;
      } else {
        std::cout << '.' << ' ';
      }
    }
    std::cout << '\n';
  }
  std::cout << "part1: " << counter << std::endl;
  
  int biggestPoint = 0;
  for (int y = 0; y < forest.size(); y++){
    for (int x = 0; x < forest[0].size(); x++){
      int counter = 0;
      for (int k = x+1; k < forest[0].size(); k++){
        counter++;
        if (forest[y][x] <= forest[y][k]){
          break;
        } 
      }
      pointForest[y][x] *= counter;
      counter = 0;
      for (int k = x-1; k >= 0; k--){
        counter++;
        if (forest[y][x] <= forest[y][k]){
          break;
        }
      }
      pointForest[y][x] *= counter;
      counter = 0;
      for (int k = y+1; k < forest.size(); k++){
        counter++;
        if (forest[y][x] <= forest[k][x]){
          break;
        }
      }
      pointForest[y][x] *= counter;
      counter = 0;
      for (int k = y-1; k >= 0; k--){
        counter++;
        if (forest[y][x] <= forest[k][x]){
          break;
        }
      }
      pointForest[y][x] *= counter;
      biggestPoint = std::max(pointForest[y][x], biggestPoint);
    }
  }

  std::cout << "part2: " << biggestPoint << std::endl;
  return 0;
}
