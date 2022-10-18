#include <iostream>
#include <queue>
#include <stack>
#include "node.cpp"

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

  bool tree_includes(Node<char> *root, char target){
    if(root->getData() == target) return true;
    if(root == nullptr) return false;
    return tree_includes(root->left, target) || tree_includes(root->right, target);
  }
}
