#include <iostream>
#include <queue>
#include <stack>

namespace utils{
  void print_queue(std::queue<Node<char>*> queue){
    std::queue<Node<char>*> tmp = queue;
    while(!tmp.empty()){
      std::cout << tmp.front()->getData() << std::endl;
      tmp.pop();
    }
  }

  void print_stack(std::stack<Node<char>*> stack){
    std::stack<Node<char>*> tmp = stack;
    while(!tmp.empty()){
      std::cout << tmp.top()->getData() << std::endl;
      tmp.pop();
    }
  }
}
