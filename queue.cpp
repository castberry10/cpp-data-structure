#include "queue.h"

// TODO: Queue 클래스 구현 작성

void Queue::push(int data){
    LinkedList::insert(LinkedList::size_, data);
}

int Queue::pop(){
    int i = LinkedList::get(0);
    LinkedList::remove(0);
    return i;
}

int Queue::peek(){
    return LinkedList::get(0);
}

void Queue::operator+=(int i){
    this->push(i);
    return;
}