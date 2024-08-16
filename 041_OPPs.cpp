#include<iostream>
#include<string.h>
using namespace std;

class Hero{
	private:
		// property
		int health;


	public:
		char level;
		char *name;

		static int timeToComplete;

		Hero(){
			cout << "Constructor Called" << endl;
			name = new char[100];
		}

		// Parameterized constructor
		Hero(int health){
			this->health = health;
		}

		Hero(int health, char level){
			this->level = level;
			this->health = health;
		}

		// copy constructor
		Hero(Hero &temp){

			char *ch = new char[strlen(temp.name)+1];
			strcpy(ch, temp.name);
			this->name = ch;

			cout << "Copy constructor called"<<endl;
			this->health = temp.health;
			this->level = temp.level;
		}


		void print(){
			cout << endl;
			cout << "Name : " << this->name <<", ";
			cout <<"Health : " << this->health <<", ";
			cout <<"level : " << this->level ;
			cout << endl;
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

		void setName(char name[]){
			strcpy(this->name, name);
		}

		static int random(){
			return timeToComplete;
		}


		// Destructor
		~Hero(){
			cout << "Destructor called "<< endl;
		}
};

int Hero::timeToComplete = 5;

int main(){


	// static function
	cout << Hero::random() <<endl;


	// static keyword value access
	// cout << Hero::timeToComplete << endl;
	// Hero a;
	// cout << a.timeToComplete << endl;
	// Hero b;
	// b.timeToComplete = 10;
	// cout << a.timeToComplete << endl;
	// cout << b.timeToComplete << endl;


/*

	// statically
	Hero a;

	// dynamically 
	Hero *b = new Hero();

	// manual destructor call
	delete b;
*/



/*
	Hero hero1;
	hero1.setHealth(12);
	hero1.setLevel('D');
	char name[9] = "Devendra";
	hero1.setName(name);

	// hero1.print();

	// use default copy constructor
	Hero hero2(hero1);
	// hero2.print();

	hero1.name[0] = 'R';
	hero1.print();
	hero2.print();

	hero1 = hero2;

	hero1.print();
	hero2.print();



	// Hero S(70,'C');
	// S.print();


	// // copy constructor
	// Hero R(S);
	// R.print();
*/



/*
	// object created statically
	Hero raju(10);
	// cout << "Address of raju " << &raju << endl;
	raju.print();

	// dynamically
	Hero *h = new Hero(11);
	h->print();

	Hero temp(22,'B');
	temp.print();
*/


/*
	// static allocation
	Hero a;
	a.setHealth(50);
	a.setLevel('C');
	cout << "level is : " << a.level << endl;
	cout << "health is : " << a.getHealth() << endl;
	

	//dynamically 
	Hero *b = new Hero;
	b->setHealth(70);
	b->setLevel('A');
	cout << "level is : "<< (*b).level << endl;
	cout << "health is : "<< (*b).getHealth() << endl;

	cout << "level is : "<< b->level << endl;
	cout << "health is : "<< b->getHealth() << endl;

*/


	// // creation of object
	// Hero ramu;

	// // ramu.health = 70;
	// ramu.level = 'A';

	// cout << "Ramu's Health is : " << ramu.getHealth() << endl;

	// // use setter
	// ramu.setHealth(70);

	// cout << "Health is : " << ramu.getHealth() << endl;
	// cout << "Level is : " << ramu.level << endl;

	// // cout << "Size : " << sizeof(h1) << endl;
}