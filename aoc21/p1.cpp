#include <iostream>
#include <fstream>
#include <vector>

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

    int n = 0;
    for(std::vector<int>::iterator it = vct.begin() + 1; it != vct.end() - 1; it++) {
      //std::cout << *it << std::endl;
      if(*it > *(it - 1)) n += 1;
    }

    std::cout << n << std::endl;
  } else {
    std::cout << "Cannot open file: " << fname << std::endl;
  }

  return 0;
}
