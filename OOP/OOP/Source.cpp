#include <iostream>
#include <string>
#include <vector>
#include <memory> // ��� ������������� shared_ptr

using namespace std;

// ������ ��� ��������� ������� �������� �������� ������ � ��� ����������
struct Logger {

	Logger(string name) : n(name) {
		cout << "+ " << name << endl;
	}

	~Logger() {
		cout << "- " << n << endl;
	}

	string n;
};


class Fruit {
public:
	Fruit(const string& t = "Fruit") : type(t), health(55) { // �������� ������� �������������		
	}
	int health = 5;
	const string type;

	int GetValue() { // ������������ (��������)
		return _sale;
	}

	void IncrementSale() {		
		_sale++;
	}

	void DecrementSale() {
		_sale--;
	}

private:
	int _sale = 55;
};

class Apple : public Fruit { // ��������� ������������
public:
	Apple() : Fruit("Apple") { // ����� ������������ �������� ������ � ������� �����������
		health = 10;
		//type = "Apple";		
	}
};

class Orange : public Fruit {
public:
	Orange() : Fruit("Orange") {
		health = 15;
		//type = "Orange";
	}
};

class PineApple : public Fruit
{
public:
	PineApple() : Fruit("PineApple"){
		health = 20;
		//type = "pine apple";
	}
};

class Animal {
public:
	string type = "Animal";

	void EatFruit(const Fruit& f) {
		cout << type << " eats " << f.type << ". " << f.health << " hp;" << endl;
	}

	virtual void Voice() const {
		cout << "Im base class" << endl;
	} //= 0; // ��������� ����������� ����� (������� ��������������� � ������ ����������)!
};

class Cat : public Animal {
public:
	Cat() {
		type = "cat";
	}

	void Voice() const override {
		cout << "meow!" << endl;
	}
};

class Dog : public Animal {
public:
	Dog() {
		type = "dog";
	}	

	void Voice() const override {
		cout << "gafff!" << endl;
	}
};

class Parrot : public Animal {
public:
	Parrot(const string& name) : _name(name){
		type = "parrot";
	}

	void Voice() const override {
		cout << _name << " is pirat!" << endl;
	}
private:
	const string _name;
};

class Horse : public Animal {
public:
	Horse() {
		type = "horse";
	}

	void Voice() const {
		cout << "horse is silent" << endl;
	}
};

void Fit(Animal& a, const Fruit& f) {
	a.EatFruit(f);
}

void MakeSound(const Animal& a) { // ��� ������������� ������������ �� ��� ������� ����� ���������� ��������� �� ������! (����� ����� ������� ����� � ����� �������� ������)
	a.Voice();
}

int main() {
	vector<shared_ptr<Animal>> zoo; // ��� �������� ������� � ������������ ����������� ������� ����� ������������ ��������� �� ��� (� ������ ����� - shared_ptr). 
	// �� ���������� ����� ��������� ����(�) ! :)

	shared_ptr<Animal> catPtr = make_shared<Cat>();
	shared_ptr<Animal> dogPtr = make_shared<Dog>();
	shared_ptr<Animal> parPtr = make_shared<Parrot>("Kesha");
	shared_ptr<Animal> horPtr = make_shared<Horse>();
	
	zoo.push_back(catPtr);
	zoo.push_back(dogPtr);
	zoo.push_back(parPtr);
	zoo.push_back(horPtr);

	for (auto an : zoo) {
		MakeSound(*an);
	}

	for (auto an : zoo) {
		an->Voice();
	}

	/*Orange orange;
	PineApple pa;

	cout << apple.GetPrivateInt() << endl;
	apple.IncrementPrivateInt();
	apple.IncrementPrivateInt();
	cout << apple.GetPrivateInt() << endl;

	Cat cat;
	Dog dog;

	Fit(cat, apple);
	Fit(cat, pa);
	Fit(dog, orange);
	Fit(dog, apple);*/

	system("pause");
	return 0;
}