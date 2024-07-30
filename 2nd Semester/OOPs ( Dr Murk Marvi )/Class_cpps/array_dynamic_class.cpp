#include<iostream>
using namespace std;

class Array{
	private:
		int size, *ptr, index;
		void copy(const Array& ob){
			for(int i=0; i<size;i++){
				ptr[i]=ob.ptr[i];
			}
		}
		void resize(){
			int* temp = new int[size*2];
			for(int i=0;i<size;i++)
				temp[i]=ptr[i];
			index=size;
			size*=2;
			delete[] ptr;
			ptr=temp;
		}
	public:
		Array(int s=0){
			size=(s > 0 ? s : 2);
			index=size;
			ptr=new int[size];
			for(int i=0;i<size;i++){
				ptr[i]=0;
			}
		}
		Array(const Array& ob){// copy constructor
			size=ob.size;
			index=size;
			ptr=new int[size];
			copy(ob);
		}
		~Array(){
			delete[] ptr;
		}
		int getSize(){
			return index;
		}
		int getMaxSize(){
			return size;
		}
		Array& operator=(const Array& ob){// overloaded assignment operator
			if(this != &ob){
				if(size != ob.size){
					delete[] ptr;
					size=ob.size;
					ptr=new int[size];
					copy(ob);
				}
			}
			return *this;
		}
		int& operator[](int i){// overloaded indexing operator and bound checking for safe Arrays
			if(i>=0 && i<index)
				return ptr[i];
			else{
				cerr<<"Error: Subscript "<<i<<" out of range!"<<endl;
				exit(1);
			}
		}
		Array operator+(const Array& ob){
			if(size==ob.size){
				Array temp(size);
				for(int i=0;i<size;i++){
					temp[i]=ptr[i]+ob.ptr[i];
				}
				return temp;
			}
			else{
				cerr<<"Size mismatch - addition can not be performed!"<<endl;
				exit(1);
			}
		}
		void push(int a){
			if(index==size)
				resize();
			ptr[index]=a;
			index++;
		}
		void pop(){
			index--;
			if(index<0){
				cerr<<"Array is empty"<<endl;
				}
			else
				ptr[index]=0;
		}
		
		
};
int main(){
	Array ob1(10), ob2;
	cout<<"Size of object 1: "<<ob1.getSize()<<endl;
	cout<<"Size of object 2: "<<ob2.getSize()<<endl;
	ob2[0]=50;
	ob2[1]=10;
	for(int i=0;i<ob2.getSize();i++){
		cout<<ob2[i]<<"  ";
	}
	cout<<endl;
//	ob1=ob2;
//	ob1[0]=100;
	ob2.push(1000);
	ob2.push(10);
	ob2.pop();
//	ob1[2]=ob2[4];
	for(int i=0;i<ob2.getSize();i++){
		cout<<ob2[i]<<"  ";
	}
	cout<<endl<<ob2.getMaxSize()<<endl;
}
