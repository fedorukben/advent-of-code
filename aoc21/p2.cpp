#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

int main() {

  std::ifstream inpf;
  std::string fname = "p1.txt";

  inpf.open(fname);

  if(inpf.is_open()) {
    std::string ln;
    std::vector<int> vct;

    while(inpf) {
      getline(inpf, ln);
      vct.push_back(std::atoi(ln.c_str()));
    }

    std::vector<std::tuple<int, int, int>> tpls;
    int n = 0;
    for(std::vector<int>::iterator it = vct.begin() + 2; it != vct.end() - 1; it++) {
      tpls.push_back(std::make_tuple(*(it - 2), *(it - 1), *it));
    }

    std::vector<int> sums;
    for(std::vector<std::tuple<int, int, int>>::iterator it = tpls.begin(); it != tpls.end() - 1; it++) {
      int sum = std::get<0>(*it);
      sum += std::get<1>(*it);
      sum += std::get<2>(*it);
      sums.push_back(sum);
    }

    for(std::vector<int>::iterator it = sums.begin() + 1; it != sums.end() - 1; it++) {
      if(*it > *(it - 1)) n += 1;
    }

    std::cout << n << std::endl;
  } else {
    std::cout << "Cannot open file: " << fname << std::endl;
  }

  return 0;
}
