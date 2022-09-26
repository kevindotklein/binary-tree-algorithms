#include <iostream>
#include <typeinfo>
#include <queue>
#include "node.cpp"
#include "utils.cpp"

std::queue<Node<char>*> breadthFirst(Node<char> *root);

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

  std::cout << "final queue: " << std::endl;
  std::queue<Node<char>*> result = breadthFirst(a);
  utils::print_queue(result);
  
  return 0;
}

std::queue<Node<char>*> breadthFirst(Node<char> *root){
  std::queue<Node<char>*> queue;
  std::queue<Node<char>*> result;
  if(root == nullptr) return queue;
  queue.push(root);
  while(!queue.empty()){
    Node<char> *curr = queue.front();
    result.push(queue.front());
    queue.pop();

    if(curr->left != nullptr) queue.push(curr->left);
    if(curr->right != nullptr) queue.push(curr->right);
  }
  return result;
}
