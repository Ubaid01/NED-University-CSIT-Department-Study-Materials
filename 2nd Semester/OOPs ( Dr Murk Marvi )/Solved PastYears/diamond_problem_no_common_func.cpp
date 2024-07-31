/* 
Yes, the diamond problem can still occur even if the parent and child classes contain only variables and no functions. The diamond problem primarily arises due to the ambiguity in the inheritance hierarchy when multiple paths lead to the same base class.  

    Diamond Structure:
B and C each have their own copy of data_A. When D inherits from both B and C, it contains two distinct instances of data_A (one from B::A and one from C::A).

Ambiguity:
When accessing data_A from D, there is ambiguity unless explicitly qualified (B::data_A or C::data_A).*/

#include<iostream>
using namespace std ;

class A {
public:
    int data_A;
};

class B : public A {
public:
    int data_B;
};

class C : public A {
public:
    int data_C;
};

class D : public B, public C {
public:
    int data_D;
};

int main() {
    D d;
    d.B::data_A = 10;  // Accessing data_A from B ( used "scope resolution operator" to tackle ambiguity )
    d.C::data_A = 20; 

    // int value = d.data_A;  // This line will cause compilation error due to ambiguity

    cout << "data_A from B: " << d.B::data_A << endl;
    cout << "data_A from C: " << d.C::data_A << endl;

    return 0;
}
