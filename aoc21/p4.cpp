#include <iostream>
#include <fstream>
#include <string>

int main() {

  long horz = 0;
  long vert = 0;
  long aim = 0;

  std::string fname = "p3.txt";
  std::ifstream inpf;

  inpf.open(fname);

  if(inpf.is_open()) {
    std::string ln;

    while(inpf) {
      getline(inpf, ln);
      if(ln.find("forward") != std::string::npos) {
        std::string str = ln.substr(8,2);
        horz += std::stoi(str);
        vert += aim * std::stoi(str);
      }
      else if(ln.find("up") != std::string::npos) {
        std::string str = ln.substr(3,2);
        aim -= std::stoi(str);
      }
      else if(ln.find("down") != std::string::npos) {
        std::string str = ln.substr(5,2);
        aim += std::stoi(str);
      }
      else if(ln == "") {
        std::cout << "EOF reached!" << std::endl;
      }
      else {
        std::cout << "Command error! " << ln << " is not a valid command!" << std::endl;
      }
    }
    inpf.close();
  }

  std::cout << horz * vert << std::endl;

  return 0;
}
