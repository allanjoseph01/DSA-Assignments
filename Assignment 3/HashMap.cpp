#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int key;
    int value;
    Node* next;
    
    Node(int key,int value){
    	this->key=key;
    	this->value=value;
    	this->next=nullptr;
	}
};
class HashMap{
public:
    int size;
    vector<Node*>arr;
    HashMap(int size=10){
        this->size=size;
        for(int i=0;i<size;i++){
            arr.push_back(nullptr);
        }
    }
    int hash(int key){
        return key%size;
    }
    bool find(int key){
        int index=hash(key);
        Node* node=arr[index];
        while(node!=nullptr){
            if(node->key==key){
                return true;
            }
            node=node->next;
        }
        return false;
    }

    void insert(int key,int value){
        int index=hash(key);
        Node* node=arr[index];
        Node* trev=nullptr;

        while(node!=nullptr){
            if(node->key==key){
                node->value=value;
                return;
            }
            trev=node;
            node=node->next;
        }
        Node* newNode=new Node(key,value);
        if(trev==nullptr){
            arr[index]=newNode;
        }else{
            trev->next=newNode;
        }
    }

    void remove(int key){
        int index=hash(key);
        Node* node=arr[index];
        Node* trev=nullptr;

        while(node!=nullptr && node->key!=key){
            trev=node;
            node=node->next;
        }
        if(node==nullptr){
        	return ;
		}
        if(trev==nullptr){
            arr[index]=node->next;
        }else{
            trev->next=node->next;
        }
        delete node;
    }
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	HashMap hm;
	hm.insert(1,10);
	hm.insert(3,30);
	if(hm.find(1)){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}