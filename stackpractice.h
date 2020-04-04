#include <iostream>
using namespace std;

template <class V>
class GenStack{
  public:

    GenStack();
    GenStack(int maxsize);
    ~GenStack();
    void push(V w);
    void pop();
    //aux functions

    V peek();
    bool isEmpty();
    bool isFull();
    int size();
    V *myStack;
    //V *fullstack;
    //string toString();

    int mSize;
    int top;
    //bool isFull;


};

template <class V>
GenStack<V>::GenStack(){
  myStack = new V[200];
  mSize = 200;
  top = -1;
}
template <class V>
GenStack<V>::GenStack(int maxsize){
  myStack = new V[maxsize];
  mSize = maxsize;
  top = -1;
}

template <class V>
GenStack<V>::~GenStack(){
  delete myStack;
}
template <class V>
void GenStack<V>::push(V w){
  if(isFull()){

    V* fullstack = new V[mSize *= 2];

    for(int i = 0; i < mSize; ++i){
      fullstack[i] = myStack[i];
    }

    delete myStack;
    myStack = fullstack;
  }
    myStack[++top] = w;
}
template <class V>
void GenStack<V>::pop(){
  if(isEmpty()){
    cout << "Stack is empty" << endl;
    exit(1);
  }
  else{
    myStack[--top];
  }
}
template <class V>
V GenStack<V>::peek(){
  if(isEmpty()){
    cout << "Stack is empty, could not peek. " << endl;

  }
  else{
    return myStack[top];
  }
}
template <class V>
bool GenStack<V>::isEmpty(){
  return top == -1;
}
template <class V>
bool GenStack<V>::isFull(){
  return top == mSize-1;
}
template <class V>
int GenStack<V>::size(){
  return top + 1;
}
