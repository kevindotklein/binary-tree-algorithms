#include <iostream>
#include <typeinfo>
#include <vector>
#include "node.cpp"

std::vector<Node<char>*> depthFirst(Node<char> *root);

int main(void){
  Node<char> *a = new Node<char>('a');
  Node<char> *b = new Node<char>('b');
  Node<char> *c = new Node<char>('c');
  Node<char> *d = new Node<char>('d');
  Node<char> *e = new Node<char>('e');
  Node<char> *f = new Node<char>('f');

  a->left = b;
  b->left = d;
  b->right = e;
  a->right = c;
  c->right = f;
  
  std::vector<Node<char>*> result = depthFirst(a);
  if(result.empty()) std::cout << "ok" << std::endl;
  else std::cout << "error" << std::endl;
  return 0;
}

std::vector<Node<char>*> depthFirst(Node<char> *root){
  std::vector<Node<char>*> stack;
  stack.push_back(root);
  while(!stack.empty()){
    Node<char> *curr = stack.back();
    stack.pop_back();
    std::cout << curr->getData() << std::endl;

    if(curr->right != nullptr) stack.push_back(curr->right);
    if(curr->left != nullptr) stack.push_back(curr->left);
  }
  return stack;
}

