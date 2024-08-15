#include<iostream>
using namespace std;

class Hero{
	private:
		// property
		int health;

		
	public:
		char level;
		void print(){
			cout << level << endl;
		}

		int getHealth(){
			return health;
		}
		char getLevel(){
			return level;
		}

		void setHealth(int h){
			health = h;
		}
		void setLevel(char ch){
			level = ch;
		}
};



int main(){


	// creation of object
	Hero ramu;

	// ramu.health = 70;
	ramu.level = 'A';

	cout << "Ramu's Health is : " << ramu.getHealth() << endl;

	// use setter
	ramu.setHealth(70);

	cout << "Health is : " << ramu.getHealth() << endl;
	cout << "Level is : " << ramu.level << endl;

	// cout << "Size : " << sizeof(h1) << endl;
}