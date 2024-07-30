#include<iostream>
using namespace std;
 
class Stack{
        char *ptr;
        int top, size;
	public:
        Stack(int s=0){
			size=s;
			top=-1;
			ptr=new char[size];
			if(ptr==NULL){
				cout<<"out of memory"<<endl;
				exit(1);
				}
			}
		void resize(int s){
			size=s;
			char *ptr2=ptr;
			ptr=new char[size];
			if(ptr==NULL){
				cout<<"out of memory"<<endl;
				exit(1);
			}
			memcpy (ptr, ptr2, top+1);
			delete[] ptr2;
			
		}
		bool isEmpty(){
        	return top==-1;
		}
        bool isFull(){
        	return top==size-1;
		}
        int push(char c){
        	if(isFull()){ // in stack is full, double the size of the stack
        		resize(size*2);
			}
			ptr[++top]=c;
			return 0;
		}
        char pop(){
        	if(isEmpty()){
        		cout<<"Invalid, stack is empty"<<endl;
        		return ' ';
			}
			return ptr[top--];
		}
        
		~Stack(){
//			cout<<"destructor called"<<endl;
			delete[] ptr;
		}
};
 
int main(){
    Stack stk(2);
    //first test program
    string st="object";
    int i=0;
    while(st[i]!='\0'){
    	stk.push(st[i]);
    	i++;
	}
	while(!stk.isEmpty())
		cout<<stk.pop();
	cout<<endl;
	
	//second test code
	string st2="object oriented programming";
	i=0;
	while(st2[i]!='\0'){
		if(st2[i]==' '){
			while(!stk.isEmpty())
			     cout<<stk.pop();
		cout<<" ";
		}
		else{
			stk.push(st2[i]);
		}
		i++;
	}
	while(!stk.isEmpty())
		cout<<stk.pop();
     
    return 0;
     
}

