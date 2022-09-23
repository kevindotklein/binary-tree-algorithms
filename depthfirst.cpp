#include <iostream>
#include <typeinfo>
#include <vector>
#include "node.cpp"
#include "utils.cpp"

std::vector<Node<char>*> depthFirstIterative(Node<char> *root);
std::vector<Node<char>*> depthFirstRecursive(Node<char> *root);

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

  std::vector<Node<char>*> resultInterative = depthFirstIterative(a);
  utils::print_vector(resultInterative);
  std::cout << '\n';
  std::vector<Node<char>*> resultRecursive = depthFirstRecursive(a);
  utils::print_vector(resultRecursive);
  
  return 0;
}

std::vector<Node<char>*> depthFirstIterative(Node<char> *root){
  std::vector<Node<char>*> stack;
  std::vector<Node<char>*> result;
  if(root == nullptr) return stack;
  stack.push_back(root);
  while(!stack.empty()){
    Node<char> *curr = stack.back();
    result.push_back(stack.back());
    stack.pop_back();

    if(curr->right != nullptr){
      stack.push_back(curr->right);
    }
    if(curr->left != nullptr){
      stack.push_back(curr->left);
    }
  }
  return result;
}

std::vector<Node<char>*> depthFirstRecursive(Node<char> *root){
  std::vector<Node<char>*> stack;
  if(root == nullptr) return stack;

  std::vector<Node<char>*> left = depthFirstRecursive(root->left);
  std::vector<Node<char>*> right = depthFirstRecursive(root->right);

  std::vector<Node<char>*> resultStack;
  resultStack.push_back(root);
  resultStack.insert(resultStack.begin()+1, left.begin(), left.end());
  resultStack.insert(resultStack.end(), right.begin(), right.end());
  return resultStack;
}
