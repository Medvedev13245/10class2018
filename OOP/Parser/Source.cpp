
// В зависимости от введенного значения переменной x вывести то или иное значение

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Node {
public:
	virtual int Evaluate() = 0;
};

class Number : public Node {
public:
	Number(int number) : _number(number) {

	}

	int Evaluate() override{
		return _number;
	}
private:
	int _number;
};

class Variable : public Node {
public:
	Variable(const int& x) : _x(x) {

	}

	int Evaluate() override {
		return _x;
	}

private:
	const int& _x;
};

class Operation : public Node { 
public:
	Operation(char op, shared_ptr<Node> left, shared_ptr<Node> right) : _op(op), _left(left), _right(right) {

	}

	int Evaluate() override {
		if (_op == '*') {
			return _left->Evaluate() * _right->Evaluate();
		}
		if (_op == '+') {
			return _left->Evaluate() + _right->Evaluate();
		}
		if (_op == '-') {
			return _left->Evaluate() - _right->Evaluate();
		}
		return 1;
	}
private:
	const char _op;
	shared_ptr<Node> _left, _right;
};

//Node Parse(const string& tokens, int& x) {
//	
//}

int main() {
	// Необходимо написать парсер для вычисления выражения 12+55-x*x+2*x
	int x;

	shared_ptr<Number> num12 = make_shared<Number>(12);
	shared_ptr<Number> num55 = make_shared<Number>(55);
	shared_ptr<Operation> op1 = make_shared<Operation>('+', num12, num55);

	shared_ptr<Variable> var1 = make_shared<Variable>(x);
	shared_ptr<Operation> op2 = make_shared<Operation>('*', var1, var1);

	shared_ptr<Operation> op3 = make_shared<Operation>('-', op1, op2);

	shared_ptr<Number> num2 = make_shared<Number>(2);
	shared_ptr<Operation> op4 = make_shared<Operation>('*', num2, var1);

	shared_ptr<Operation> op5 = make_shared<Operation>('+', op3, op4);

	cout << "Input x" << endl;
	while (cin >> x) {
		cout << "Operation = " << op5->Evaluate() << endl;
		cout << "Input x" << endl;
	}
	

	/*string tokens;
	cout << "Enter expression: ";
	cin >> tokens;

	int x;
	
	auto expr = Parse(tokens, x);
	
	cout << "Enter x: ";
	while (cin >> x) {		
		int value = expr->Evaluate();
		cout << "Expression value = " << value << endl;
		cout << "Enter x: ";
	}
	*/
	system("pause");
	return 0;
}