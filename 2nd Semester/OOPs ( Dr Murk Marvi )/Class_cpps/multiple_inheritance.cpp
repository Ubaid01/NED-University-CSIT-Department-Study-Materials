#include<iostream>
using namespace std;
class Person{
	string Name;
	int Age;
	public:
		Person(){
			cout<<"Person default constructor called"<<endl;
		}
	Person(string n, int a):Name(n),Age(a){
		cout<<"Person Parametrized constructor called"<<endl;
	}
};
class Student:virtual  public Person{
	float cgpa;
	public:
		Student(){
			cout<<"Student default constructor called"<<endl;
		}
		Student(string n, int a, float c):Person(n,a), cgpa(c){
			cout<<"Student Parametrized constructor called"<<endl;
		}
};


class Faculty:virtual public Person{
	string desig;
	public:
		Faculty(){
			cout<<"Faculty default constructor called"<<endl;
		}
		Faculty(string n, int a, string d):Person(n,a), desig(d){
		cout<<"Faculty Parametrized constructor called"<<endl;
		}
};

class TA: public Faculty, public Student{
	string course;
	public:
		TA(){
			cout<<"TA default constructor called"<<endl;
		}
		TA(string n, int a, string co, string d, float c):Student(n,a,c),Faculty(n,a,d), Person(n,a), course(co){
		cout<<"TA Parametrized constructor called"<<endl;
		}
};
int main(){
	TA t("Ali", 18, "OOP", "TA", 3.5);
}
