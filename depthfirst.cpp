#include <iostream>
#include <typeinfo>
#include <vector>
#include "node.cpp"

void depthFirstIterative(Node<char> *root);
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

  depthFirstIterative(a);
  std::cout << '\n';
  std::vector<Node<char>*> resultRecursive = depthFirstRecursive(a);
  while(!resultRecursive.empty()){
    std::cout << resultRecursive.front()->getData() << std::endl;
    resultRecursive.erase(resultRecursive.begin());
  }
  
  return 0;
}

void depthFirstIterative(Node<char> *root){
  std::vector<Node<char>*> stack;
  if(root == nullptr) return;
  stack.push_back(root);
  while(!stack.empty()){
    Node<char> *curr = stack.back();
    stack.pop_back();
    std::cout << curr->getData() << std::endl;

    if(curr->right != nullptr) stack.push_back(curr->right);
    if(curr->left != nullptr) stack.push_back(curr->left);
  }
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
