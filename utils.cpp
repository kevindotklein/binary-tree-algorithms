#include <iostream>
#include <queue>
#include <vector>

namespace utils{
  void print_queue(std::queue<Node<char>*> queue){
    std::queue<Node<char>*> tmp = queue;
    while(!tmp.empty()){
      std::cout << tmp.front()->getData() << std::endl;
      tmp.pop();
    }
  }

  void print_vector(std::vector<Node<char>*> vector){
    std::vector<Node<char>*> tmp = vector;
    while(!tmp.empty()){
      std::cout << tmp.front()->getData() << std::endl;
      tmp.erase(tmp.begin());
    }
  }
}
