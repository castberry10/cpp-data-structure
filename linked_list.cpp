#include "linked_list.h"
#include <iostream>

 // 멤버 변수를 초기화한다
LinkedList::LinkedList(){
    head_ = nullptr;
    size_ = 0;
}

// 메모리를 적절히 해제한다
LinkedList::~LinkedList(){
    Node* cur = head_;
    Node* nextcur = nullptr;
    while(cur != nullptr){
        nextcur = cur->next_;
        delete cur;
        cur = nextcur;
    }
}

 // head 부터 순서대로 노드를 출력한다
void LinkedList::print(){
    Node* cur = head_;
    while(cur != nullptr){
        std::cout << cur->value_ << " ";
    }
    std::cout << std::endl;
}

// index 위치에 노드를 삽입한다
void LinkedList::insert(int index, int value){
    Node ** cur = &head_;
    Node* newNode = new Node(value);
    int index_ = 0;
    
    /*
    인덱스 0
    0을 근데 ? 
    while 마지막에 일단 i ++ 두고 
    index_ +1 했을때 조건이 맞다면
    
    [a] -> [b] -> [c] -> [d]
    인데 c자리에 f를 넣을껀데
    난 지금 b자리니까 
        cur의 next next를 임시로 저장하고 
        cur의 next next를 cur의 next로 바꾸고 ([c]의 next가 [c])
        f의 next를 임시 저장한 노드를 넣는다. 
        cur의 next를 f로 한다.
    
    */
    if(index_ = 0){
        head_ = newNode;
        return;
    }else if(index_ = 1){
        head_->next_ = newNode;
    }
    while(1){
        if(index_+1 == index){
            Node* tempNode = (*cur)->next_->next_;
            (*cur)->next_->next_ = (*cur)->next_;
            newNode->next_ = tempNode;
            (*cur)->next_ = newNode;
        }
        ++index_;
    }
}

// index에 위치한 노드의 값을 반환한다.
int LinkedList::get(int index){
    Node ** cur = &head_;
    int index_ = 0;
    while(*cur != nullptr){
        if(index_ == index){
            return (*cur)->value_;
        }
        *cur = (*cur)->next_; 
        ++index_;
    }
}

 // index에 위치한 노드를 제거하고 메모리 상에서 해제한다.
void LinkedList::remove(int index){
    Node ** cur = &head_;
    int index_ = 0;
    if(index = 0){
        delete *cur;
    }
    while(*cur != nullptr){
        if(index_ + 1 == index)
        *cur = (*cur)->next_; 
        ++index_;
    }
}