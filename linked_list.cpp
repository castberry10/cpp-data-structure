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
        cur = cur->next_;
    }
    std::cout << std::endl;
}

// index 위치에 노드를 삽입한다
void LinkedList::insert(int index, int value){
    if (index < 0 || index > size_) { // 여길 지나는 순간 범위는 SAFE
        throw std::out_of_range("범위 체크");
    }
    
    // 객체 생성
    Node* newNode = new Node(value);
    
    // 처음에 넣기 
    if (index == 0) { 
        newNode->next_ = head_;
        head_ = newNode;
    } else {  // 중간이나 마지막 
        Node* cur = head_;
        for (int i = 0; i < index - 1; ++i) {
            cur = cur->next_;
        }
        
        newNode->next_ = cur->next_;
        cur->next_ = newNode;
    }
    ++size_; // 사이즈 추가
    
}

// index에 위치한 노드의 값을 반환한다.
int LinkedList::get(int index){
    if (index < 0 || index >= size_) {
        throw std::out_of_range("범위 체크");
    }
    Node* cur = head_;
    for (int i = 0; i < index; ++i) {
        cur = cur->next_;
    }
    return cur->value_;
}

 // index에 위치한 노드를 제거하고 메모리 상에서 해제한다.
void LinkedList::remove(int index){
    if (index < 0 || index >= size_) {
        throw std::out_of_range("범위 체크");
    }
    
    Node** cur = &head_;
    for (int i = 0; i < index; ++i) {
        cur = &((*cur)->next_);
    }
    --size_;

    Node* tempNode = *cur;

    *cur = (*cur)->next_;

    delete tempNode;
    
}