#include<bits/stdc++.h>
using namespace std;

class Node{	
public:
	int key;
	int height,size;
	Node* left;
	Node* right;
	Node(int val){
		key=val;
		left=nullptr;
		right=nullptr;
		height=1;
		size=1;
	}
};

class AVLTree{
public:
	Node* root;
	AVLTree(){
		root=nullptr;
	}
	int getheight(Node* node){
		if(node){
			return node->height;
		}
		return 0;
	}
	
	int getsize(Node* node){
		if(node){
			return node->size;
		}
		return 0;
	}
	
	int balance(Node* node){
		if(!node){
			return 0;
		}
		return getheight(node->	left)-getheight(node->right);
	}
	
	Node* leftrotate(Node* trev){
		Node* trev2=trev->right;
		Node* temp=trev->left;
		trev2->left=trev;
		trev->right=temp;
		trev->height=1+max(getheight(trev->left),getheight(trev->right));
		trev2->height=1+max(getheight(trev2->left),getheight(trev2->right));
		trev->size=1+(getsize(trev->left))+getsize(trev->right);
		trev2->size=1+getsize(trev2->left)+getsize(trev2->right);
		
		return trev2;
	}
	
	Node* rightrotate(Node* trev){
		Node* trev2=trev->left;
		Node* temp=trev2->right;
		trev2->right=trev;
		trev->left=temp;
		trev->height=1+max(getheight(trev->left),getheight(trev->right));
		trev2->height=1+max(getheight(trev2->left),getheight(trev2->right));
		trev->size=1+getsize(trev->left)+getsize(trev->right);
		trev2->size=1+getsize(trev2->left)+getsize(trev2->right);
		
		return trev2;
	}
	
	Node* insert(Node* node,int key){
		if(!node){
			return new Node(key);
		}
		if(key<node->key){
			node->left=insert(node->left,key);
		}else{
			node->right=insert(node->right,key);
		}
		
		node->height=1+max(getheight(node->left),getheight(node->right));
		node->size=1+getsize(node->left)+getsize(node->right);
		
		int b=balance(node);
		if(b>1 && balance(node->left)>=0){
			return leftrotate(node);
		}
		if(b<-1 && balance(node->right)>=0){
			return rightrotate(node);
		}
		if(b>1 && balance(node->left)<0){
			node->left=leftrotate(node->left);
			return rightrotate(node);
		}
		if(b<-1 && balance(node->right)<0){
			node->right=rightrotate(node->right);
			return leftrotate(node);
		}
		return node;
	}
	
	bool find(Node* node,int key){
		if(!node){
			return false;
		}
		if(node->key==key){
			return true;
		}
		if(node->key<key){
			find(node->right,key);
		}else{
			find(node->left,key);
		}
	}
	
	Node* min(Node* node){
        Node* current=node;
        while(current->left!=nullptr)
            current=current->left;
        return current;
    }
    
	Node* deletenode(Node* node,int key){
		if(!node){
			return node;
		}
		if(key<node->key){
			node->left=deletenode(node->left,key);
		}else if(key>node->key){
			node->right=deletenode(node->right,key);
		}else{
			if(!node->left){
				Node* temp=node->right;
                delete node;
                return temp;
			}
			if(!node->right){
				Node* temp=node->left;
                delete node;
                return temp;
			}
			Node* temp=min(node->right);
            node->key=temp->key;
            node->right=deletenode(node->right,temp->key);
		}
		if(!node){
			return node;
		}
        node->height=max(getheight(node->left), getheight(node->right))+1;
        node->size=getsize(node->left)+getsize(node->right)+1;

        int b=balance(node);
        if(b>1 && balance(node->left)>=0){
        	return rightrotate(root);
		}
        if(b>1 && balance(node->left)<0){
            node->left=leftrotate(node->left);
            return rightrotate(node);
        }
		if(b<-1 && balance(node->right)>=0){
			return rightrotate(node);
		}
		if(b<-1 && balance(node->right)<0){
			node->right=rightrotate(node->right);
			return leftrotate(node);
		}
        return node;
    }
    
    int orderOfKey(Node* node, int key){
        if(!node){
        	return 0;
		}      
        if(key<node->key){
        	return orderOfKey(node->left,key);
		}    
        else if(key>node->key){
        	return 1+getsize(node->left)+orderOfKey(node->right,key);
		}       
        else{
        	return getsize(node->left);
		}        
    }
    
    int getByOrder(Node* node,int k){
        if(!node){
        	return -1;
		}     
        int left=getsize(node->left);
        if(k<left){
        	return getByOrder(node->left,k);
		}  
        else if(k>left){
        	return getByOrder(node->right,k-left-1);
		}  
        else{
        	return node->key;
		}
    }
    
    void insert(int key){
        root=insert(root,key);
    }
    void deletenode(int key){
        root=deletenode(root,key);
	}
    bool find(int key){
        return find(root,key);
    }
    int orderOfKey(int key){
        return orderOfKey(root,key);
    }
    int getByOrder(int k){
        return getByOrder(root,k-1);
    }
};

int main(){
	AVLTree tree;
	tree.insert(30);
	tree.insert(20);
	tree.insert(10);
	tree.insert(40);
	cout << tree.getByOrder(3);
}