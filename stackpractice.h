#include <iostream>
using namespace std;

template <class V>
class GenStack{
  public:
//establishs methods & variables
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


    int mSize;
    int top;



};
//default constructor
template <class V>
GenStack<V>::GenStack(){
  myStack = new V[200];
  mSize = 200;
  top = -1;
}
//overload conversation
template <class V>
GenStack<V>::GenStack(int maxsize){
  myStack = new V[maxsize];
  mSize = maxsize;
  top = -1;
}
//destructor
template <class V>
GenStack<V>::~GenStack(){
  delete myStack;
}
//push to stack
template <class V>
void GenStack<V>::push(V w){
//create new stack if stack is full
  if(isFull()){

    V* fullstack = new V[mSize * 2];

    for(int i = 0; i < mSize; ++i){
      fullstack[i] = myStack[i];
    }
//clear stack and set it equal to other stack
    delete myStack;
    myStack = fullstack;
//double max size for new array
    mSize = mSize * 2;
  }
  //add variable to stack
    myStack[++top] = w;
}
//pop top of stack
template <class V>
void GenStack<V>::pop(){
//exit it empty
  if(isEmpty()){
    cout << "Stack is empty" << endl;
    exit(1);
  }
  else{
    myStack[--top];
  }
}
//peek at top of stack
template <class V>
V GenStack<V>::peek(){
  //exit it empty
  if(isEmpty()){
    cout << "Nothing here" << endl;
    exit(1);
  }
  else{
    return myStack[top];
  }
}
//check if is empty
template <class V>
bool GenStack<V>::isEmpty(){
  return top == -1;
}
//check if full
template <class V>
bool GenStack<V>::isFull(){
  return top == mSize-1;
}
//get size
template <class V>
int GenStack<V>::size(){
  return top + 1;
}
