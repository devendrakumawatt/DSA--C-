#include<iostream>
using namespace std;

class A{
public:
	void func(){
		cout << " i am A" << endl;
	}
};

class B{
public:
	void func(){
		cout << "i am B" << endl;
	}
};

class C: public A, public B{

};



// // Hierarcial Inheritance
// class A{

// public:
// 	void func1(){
// 		cout << "Inside Function 1" << endl;
// 	}
// };

// class B: public A{
// public:
// 	void func2(){
// 		cout << "Inside Function 2" << endl;
// 	}
// };

// class C: public A{
// public:
// 	void func3(){
// 		cout << "Inside Function 3" << endl;
// 	}
// };





// class A{
// public:
// 	int age;
// 	int weight;

// public:
// 	void bark(){
// 		cout << "Barking" << endl;
// 	}
// };

// class B {
// public:
// 	string color;

// public:
// 	void speak(){
// 		cout << "speaking" << endl;
// 	}
// };

// 	// Multiple Inheritance
// class Hybrid: public A, public B{

// };




// class Animal{
// public:
// 	int age;
// 	int weight;

// public:
// 	void speak(){
// 		cout << "Speaking" << endl;
// 	}
// };

	// single Inheritance
// class Dog: public Animal{

// };
	
	// Multi-level Inheritance
// class germanSphepard: public Dog{

// };


// class Student{
// 	private:
// 		string name;
// 		int age;
// 		int height;

// 	public:
// 		int getAge(){
// 			return this->age;
// 		}
// };


// class Human{
// 	public:
// 		int height;
// 		int weight;

// 	private:
// 		int age;

// 	public:
// 		int getAge(){
// 			return this->age;
// 		}

// 		void setWeight(int w){
// 			this->weight = w;
// 		}
// };

// class Male : public Human{
// 	public:
// 		string color;

// 		void sleep(){
// 			cout << "Male sleeping" << endl;
// 		}

// };


int main(){


	C obj;
	obj.A::func();
	obj.B::func();



	// // Hierarcial Inheritance
	// A obj1;
	// obj1.func1();

	// B obj2;
	// obj2.func2();

	// C obj3;
	// obj3.func1();
	// obj3.func3();




	// // Multiple Inheritance
	// Hybrid obj1;
	// obj1.speak();
	// obj1.bark();



	// // Multilevel Inheritance
	// germanSphepard g;
	// g.speak();


	// Single Inheritance
	// Dog d;
	// d.speak();
	// cout << d.age << endl;





	// Male object1;
	// // cout << object1.age << endl;
	// cout << object1.weight << endl;
	// cout << object1.height << endl;

	// cout << object1.color << endl;
	// object1.setWeight(84);
	// cout << object1.weight << endl;
	// object1.sleep();




	// Student first;
	// cout << "All Good " << endl;


}