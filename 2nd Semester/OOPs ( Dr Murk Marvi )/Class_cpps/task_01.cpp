/***write a program in which a class named student has member variables: name, semester, rollNo, section create 5 objects of this class 
to store data of five different students now display the data of only those students who belong to section B***/

#include<iostream>
using namespace std;
class student{
	string name;
	char section;
	int rollNo,semester;
	public:
		student(){
		    name="";
		    rollNo=1;
		    section='A';
		    semester=1;
		}
		~student(){
			
		}
		char getsection(){
			return section;
		}
		void setAttributes(string n,char sec,int roll,int sem){
		    name=n;
			section=sec;
			rollNo=roll;
			semester=sem;	
		}
		void printDetails(){
		    cout<<"Name: "<<name<<endl;
		    cout<<"Section: "<<section<<endl;
		    cout<<"Semester: "<<semester<<endl;
		    cout<<"RollNo: "<<rollNo<<endl;
		}
};
int main(){
	student s[2];
	string n;
	char sec;
	int r, sem;
	for(int i=0; i<2;i++){
	cout<< "Enter name: ";
	cin>>n;
	cout<<"Enter roll no: ";
	cin>>r;
	cout<<"Enter semester: ";
	cin>>sem;
	cout<<"Enter section: ";
	cin>>sec;
	s[i].setAttributes(n,sec,r,sem);
}
cout<<"============================================================"<<endl;
for(int i=0; i<2; i++){
	if(tolower( s[i].getsection() )=='b'){
		s[i].printDetails();
	}
}
}
