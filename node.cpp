template<typename T>
class Node{
private:
  T data;
public:
  Node *left;
  Node *right;
  
  Node<T>(T data)
    : data(data), left(nullptr), right(nullptr){}
  
  T getData(){
    return this->data;
  }
    
};
