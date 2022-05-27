#include "ProducerConsumer.hpp"
#include <iostream>
using namespace std;
ProducerConsumer::ProducerConsumer(){
  queueFront = 0;
  queueEnd = 0;
  counter = 0;
}
bool ProducerConsumer::isEmpty(){
  if((getQueueFront() == getQueueEnd()) && counter == 0 ){
    return true;
  }
  else{
    return false;
  }
}
bool ProducerConsumer::isFull(){
  if((getQueueFront() == getQueueEnd()) && counter == SIZE){
    return true;
  }
  else{
    return false;
  }
}
void ProducerConsumer::enqueue(std::string item){
  if(isFull() == true){
    cout << "Queue full, cannot add new item"<< endl;

  }
  else{
    queue[getQueueEnd()] = item;
    counter++;
    if(getQueueEnd() == (SIZE - 1)){
      queueEnd = 0;
    }
    else{
        queueEnd++;
    }
  }
}
void ProducerConsumer::dequeue(){
  if(isEmpty() == true){
    cout <<"Queue empty, cannot dequeue an item" << endl;
  }

  else{
    string out;
    out = queue[getQueueFront()];
    counter--;

    if(getQueueFront() == (SIZE - 1)){
      queueFront = 0;
    }
    else{
        queueFront++;
  }
  }
}
std::string ProducerConsumer::peek(){
  if(isEmpty() == true){
    string empty = "";
    cout <<"Queue empty, cannot peek"<<endl;
    return empty;
  }
  else{
    return queue[getQueueFront()];

  }
}
int ProducerConsumer::queueSize(){
  return counter;
}    //changed
