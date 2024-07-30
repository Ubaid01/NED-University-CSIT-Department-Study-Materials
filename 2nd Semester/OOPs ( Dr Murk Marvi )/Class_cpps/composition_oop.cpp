//Composition Example
#include<iostream>
using namespace std;
class Address{
	public:
	int no;
	string colony, city, province;
	public:
		Address(int no, string c, string city, string p){
			this->no=no;
			colony=c;
			this->city=city;
			province=p;
		}
};
class Person{
	string name;
	Address *add;
	public:
	Person(string n, Address *a){
		name=n;
		add=a;
	}
	void display(){
		cout<<name<<"\t"<<add->colony<<"\t"<<add->city<<"\t"<<add->province<<endl;
	}
};

int main(){
	Address add(12,"gulshan","karachi","sindh");
	Person p("Ahmed",&add);
	p.display();
	
}
