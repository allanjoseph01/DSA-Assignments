//Leetcode Submission Id:  https://leetcode.com/submissions/detail/1361273307/


#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
class Node {
public:
    int keyval;
    Node* next;
    Node* prev;
    Node(int key) {
        keyval = key;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int size;
    map<int,int> isthere;
    Node* head;
    map<int,Node*> dir;
    LRUCache(int capacity) {
        this->size=capacity;
        this->head=nullptr;
    }
    
    int get(int key){
        if(isthere.find(key)==isthere.end()){
            return -1;
        }
        if(head->keyval==key){
            return isthere[key];
        }
        Node* curr=dir[key];
        Node* prev=curr->prev;
        if(prev){
            prev->next=curr->next;
            if(curr->next){
                curr->next->prev=prev;
            }
        }
        curr->next=head;
        curr->prev=nullptr;
        if(head){
            head->prev=curr;
        }
        head=curr;
        return isthere[key];
    }
    
    void put(int key, int value) { 
        if(isthere.find(key)==isthere.end()){
            Node* temp=new Node(key);
            Node* trev=temp;
            trev->next=head;
            if(head){
                head->prev=temp;
            }
            head=trev;
            dir[key]=head;
            int siz=1;
            while(siz<size && trev->next!=nullptr){
                siz++;
                trev=trev->next;
            }
            if(trev->next!=nullptr){
                Node* trev2=trev->next;
                trev->next=nullptr;
                isthere.erase(trev2->keyval);
                delete trev2;  
            }
        }else{
            int ans=get(key);
        }
        isthere[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
