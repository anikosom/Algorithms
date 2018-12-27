#pragma once
#include <iostream>
#include <iomanip>
#define PI 3.14159265358979323846
#define E  2.71828182845904523536
#define COS 'c'
#define SIN 's'
#define TG 't'
#define CTG 'g'
#define LN 'l'
#define LG 'o'
#define SQRT 'q'
#define ARCCOS 'a'
#define ARCSIN 'r'
#define ARCTG 'x'
#define ARCCTG 'n'
using namespace std;

struct Operation {
	char sign;
	int weight = 0;
	bool is_bin;
	bool is_op;
};
union Element {
	struct Operation oper;
	double digit;
};
class Notation
{
	size_t iter = 0;
	int index = 0;
	int plus_weight = 0;
	vector <int> digit;
	vector <union Element> infix;
	vector <union Element> prefix;
	double calculate(double first, double second, char operation);
	void print(char operation);
	int is_operator(char symbol);
	void remove(int index);
	char get_op(const char * str);
	double getnum(vector <int> digit);
	int priority(char symbol);

public:
	Notation(const char *, const size_t);
	~Notation();
	void infixtoprefix();
	double Calculator();
	vector <union Element> get_infix();
	vector <union Element> get_prefix();
};
bool is_equal(vector <union Element> first, vector <union Element> second);