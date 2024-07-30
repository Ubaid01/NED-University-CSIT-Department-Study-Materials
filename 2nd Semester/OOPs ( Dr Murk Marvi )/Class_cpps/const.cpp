#include <iostream>
using namespace std;
class dist{
	int inch, feet;
	public:
	dist(int ft=0, int in=0):feet(ft), inch(in){
		set(ft, in);
	}
	void set(int ft, int in){
		if (ft<0 || inch<0)
		exit(1);
		if(inch>=12){
			feet+= inch/12;
			inch=inch%12;
		}
	}
	float get_ft() const{
		float temp=feet+inch/12;
		return temp;
	}
	
	float get_in() const{
		int temp=feet*12+inch;
		return temp;
	}
	
	dist add(const dist &ob2){
		dist temp(feet+ob2.feet, inch+ob2.inch);
		return temp;
		
	}
	
	void display(){
		cout<<feet<<" feet and "<<inch<<" inches"<<endl;
	}
	
	~dist(){
	}
	
};

main(){
	dist ob1(5,25), ob2(1, 9);
	ob1.display();
//	float temp = ob1.get_ft();
//	cout<<temp<<" feets"<<endl;
//	temp=ob1.get_in();
//	cout<<temp<<" inches"<<endl;
	dist ob3 = ob1.add(ob2);
	ob3.display();
}
