//Design Linked List

//leetcode submission id: https://leetcode.com/submissions/detail/1329604218/

class Node{
public:
	int val;
	Node* next;
	Node(int data,Node* next=nullptr){
		val=data;
		this->next=next;
	}
};
class MyLinkedList {
private:
	Node* head;
	int size;
public:
    MyLinkedList() {
        head=nullptr;
        size=0;
    }
    
    int get(int index) {
        if (index<0 || index>=size){
            return -1;
        }
        if(index==0){
            return head->val;
        }
        Node* trev=head;
        while(index){
            trev=trev->next;
            index--;
        }
        return trev->val;
    }
    
    void addAtHead(int data) {
        Node* newnode=new Node(data,head);
		head=newnode;
		size++;
    }
    
    void addAtTail(int data) {
        Node* newnode=new Node(data);
		if(size==0) {
			head=newnode;
		}else{
			Node* last=head;
			while(last->next!=nullptr){
				last=last->next;
			}
			last->next=newnode;
		}
		size++;
    }
    
    void addAtIndex(int index, int data) {
        if(index<0 || index>size){
			return;
		}
		Node* newnode=new Node(data);
		if(index==0){
			addAtHead(data);
		}else if(index == size){
			addAtTail(data);
		}else{
			Node* pos=head;
			for(int i=0;i<index-1;i++){
				pos=pos->next;
			}
			Node* nextpos=pos->next;
			pos->next=newnode;
			newnode->next=nextpos;
			size++;
		}
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
			return;
		}
		else if(index==0){
			Node* nexthead = head->next;
            delete head;
            head = nexthead;
		}else{
			Node* current=head;
			for(int i=0;i<index-1;i++){
				current=current->next;
			}
			Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
		}
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */