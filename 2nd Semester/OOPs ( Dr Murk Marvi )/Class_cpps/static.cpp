#include<iostream>
#include<cstring>
using namespace std;
class student{
	char* name;
	int roll;
	int sem;
	char sec;
	static int count;
	public:
	student(const char* n=NULL,int r=1,int s=1,char se='A'){
		if(n!=NULL){
			name=new char[strlen(n)+1];
			if(name==NULL)
				exit(1);
			strcpy(name, n);
			}
		else{
			name=new char[6];
			name="Ahmed";
		}
		roll=r;
		sem=s;
		sec=se;
		count++;
	}
	static int getCount(){
		return count;
	}

	string getName(){
		return name;
	}
	~student(){
		delete[] name;
		count--;
	}
	
};
int student::count=0;
int main(){
	cout<<"Number of student objects created so far: "<<student::getCount()<<endl;
	student s1[4] = {student("Ali", 1, 1, 'A'),
					student("Ahmed", 2, 1, 'B'),
					student("Aliya", 3, 1, 'A'),
					student("Anus", 4, 1, 'B')};
    cout<<s1[0].getName()<<endl;
	cout<<"Number of student objects created so far: "<<student::getCount()<<endl;
	student* s2= new student("Aiman", 5, 2, 'A');
	cout<<"Number of student objects created so far: "<<student::getCount()<<endl;
	delete s2;
	cout<<"Number of student objects created so far: "<<student::getCount()<<endl;
}
