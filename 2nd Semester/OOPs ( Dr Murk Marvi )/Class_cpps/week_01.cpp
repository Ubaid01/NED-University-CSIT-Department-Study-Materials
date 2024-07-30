#include<iostream>
using namespace std;
class circle{
	float radius;
	public:
		circle(float r=0):radius(r){
			cout<<"The parametrized constructor is invoked"<<endl;
		}
		~circle(){
			cout<<"Destructor is invoked"<<endl;
		}
	float getRadius(){
		return radius;
	}	
	float Area(){
		return 3.14*radius*radius;
	}
	float circumference(){
		return 2*3.14*radius;
	}
};

int main(){
	circle c1;
	cout<<"Radius is : "<<c1.getRadius()<<endl;
	cout<<"The area of the circle is : "<<c1.Area()<<endl;
	circle c2(10);
}
