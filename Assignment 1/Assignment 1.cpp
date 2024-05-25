#include<bits/stdc++.h>
using namespace std;
template <typename T>
class DynamicArray{
private:
	T* arr;
	int size;
	int capacity;
	float resizeFactor;
	
	void resize(int newsize){
		T* newlst=new T[newsize];
        for (int i=0;i<size;i++) {
            newlst[i]=arr[i];
        }
        delete[] arr;
        arr=newlst;
        capacity=newsize;
	}
public:
	DynamicArray(int initialCapacity=2, float resizeFactor=2.0){
		capacity=initialCapacity;
		size=0;
		this->resizeFactor=resizeFactor;
		arr=new T[capacity];
		for(int i=0;i<capacity;i++){
			arr[i]=0;
		}
	}
	int getsize(){
		return size;
	}
	bool isEmpty(){
        return size==0;
    }
    void insert(int index,const T& element){
        if(index<0 || index>size){
            throw out_of_range("Index out of range");
        }
        if(size==capacity){
            resize(static_cast<int>(capacity * resizeFactor));
        }
        for (int i=size;i>index;i--){
            arr[i]=arr[i-1];
        }
        arr[index]=element;
        size++;
    }
    void remove(int index) {
        if(index< 0 || index>=size){
            throw out_of_range("Index out of range");
        }
        for (int i=index;i<size-1;i++){
            arr[i]=arr[i+1];
        }
        size--;
    }
    void append(const T& element){
        insert(size,element);
    }
    void prepend(const T& element){
        insert(0,element);
    }
    void rotate(int k){
        if (size == 0) return;
        k=k%size;
        vector<T>temp(arr,arr+size);
        int j=0;
        for(int i=(size-k);i<size;i++){
        	arr[j]=temp[i];
        	j+=1;
		}
		for(int h=0;h<(size-k);h++){
			arr[j]=temp[h];
		}
    }
    void reverse(){
    	int l=size-1;
    	for(int i=0;i<(size/2);i++){
    		T temp;
    		arr[i]=temp;
    		arr[i]=arr[l];
    		arr[l]=temp;
    		l-=1;
		}
	}
	T middle(){
		if(size==0){
            throw out_of_range("Array is empty");
        }
		return arr[size/2];
	}
	int first(T data){
		for(int i=0;i<size;i++){
			if(arr[i]==data){
				return i;
			}
		}
		return -1;
	}
	void setResizeFactor(float num){
        if(num<=1.0){
            throw invalid_argument("Resize factor must be greater than 1");
        }
        resizeFactor=num;
    }
    DynamicArray* merge(const DynamicArray& arr1,const DynamicArray& arr2){
        DynamicArray* merged(arr1.size+arr2.size);
        int i=0;
        int j=0;
        int h=0;
        while(i!=arr1.size && j!=arr2.size){
        	if(arr1[i]<=arr2[j]){
        		merged[h]=arr1[i];
        		i+=1;
        		h+=1;
			}else if(arr1[i]>arr2[j]){
				merged[h]=arr2[j];
				j+=1;
				h+=1;
			}
		}
		if(i==arr1.size && h<(arr1.size+arr2.size)){
			while(j!=arr2.size){
				merged[h]=arr2[j];
				h+=1;
				j+=1;
			}
		}else if(j==arr1.size && h<(arr1.size+arr2.size)){
			while(i!=arr1.size){
				merged[h]=arr1[i];
				h+=1;
				i+=1;
			}
		}
		return merged;
    }
    DynamicArray* interleave(const DynamicArray& arr1,const DynamicArray& arr2){
        DynamicArray* ans(arr1.size+arr2.size);
        int i=0;
        int j=0;
        int h=0;
        while(i!=arr1.size || j!=arr2.size){
        	ans[h]=arr1[i];
        	ans[h+1]=arr2[j];
        	i+=1;
        	j+=1;
        	h+=2;
		}
		if(i==arr1.size && h<(arr1.size+arr2.size)){
			while(j!=arr2.size){
				ans[h]=arr2[j];
				h+=1;
				j+=1;
			}
		}else if(j==arr1.size && h<(arr1.size+arr2.size)){
			while(i!=arr1.size){
				ans[h]=arr1[i];
				h+=1;
				i+=1;
			}
		}
		return ans;
    }
    pair<DynamicArray,DynamicArray>splitArray(int index){
        if(index<0 || index>size){
            throw out_of_range("Index out of range");
        }
        DynamicArray left(index);
        DynamicArray right(size-index);
        int h=0;
        int y=0;
        for(int i=0;i<index;i++){
            left[h]=arr[i];
            h++;
        }
        for(int i=index;i<size;i++) {
            right[y]=arr[i];
            y++;
        }
        return {left, right};
    }
    void printArray(){
    	for(int i=0;i<size;i++){
    		cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main(){
	DynamicArray<int> lst;
	lst.append(1);
	lst.append(2);
	cout << lst.getsize() << endl;
	lst.middle();
	lst.prepend(0);
	lst.printArray();
	lst.remove(1);
	lst.printArray();
	lst.insert(1,1);
	lst.reverse();
	lst.printArray();
}