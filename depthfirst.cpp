#include <iostream>
#include <typeinfo>
#include <stack>
#include "node.cpp"
#include "utils.cpp"

std::stack<Node<char>*> depthFirst(Node<char> *root);

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

  std::stack<Node<char>*> result = depthFirst(a);
  std::cout << "final stack: " << std::endl;
  utils::print_stack(result);
  
  return 0;
}

std::stack<Node<char>*> depthFirst(Node<char> *root){
  std::stack<Node<char>*> stack;
  std::stack<Node<char>*> result;
  if(root == nullptr) return stack;
  stack.push(root);
  while(!stack.empty()){
    Node<char> *curr = stack.top();
    result.push(stack.top());
    stack.pop();

    if(curr->right != nullptr){
      stack.push(curr->right);
    }
    if(curr->left != nullptr){
      stack.push(curr->left);
    }
  }
  return result;
}

