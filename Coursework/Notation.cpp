#include "pch.h"
#include <vector>
#include <math.h>
#include "Notation.h"
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


Notation::Notation(const char * str, const size_t size)
{
	if (size == 0)
		throw out_of_range("String is empty");
	char symbol;
	bool is_binary = 0;
	for (iter = 0; iter < size; iter++) {
		symbol = str[iter];
		if (is_operator(symbol) == 0) {
			if (symbol == '.')
				digit.push_back(index * (-1));
			else if (isdigit(symbol)) {
				digit.push_back(static_cast<int>(symbol) - '0');
				index++;
			}
			else if (symbol != ' ')
				throw out_of_range("Incorrect input");
		}
		else if (is_operator(symbol) == 1) {
			union Element cons = { 0 };
			if (symbol == 'p' && str[iter + 1] == 'i') {
				cons.digit = PI;
				iter++;
			}
			else if (symbol == 'e')
				cons.digit = E;
			is_binary = 1;
			infix.push_back(cons);
		}
		else {
			if (digit.size() != 0) {
				union Element dig = { 0 };
				dig.digit = getnum(digit);
				infix.push_back(dig);
				digit.clear();
				is_binary = 1;
			}
			if (symbol == '(')
				plus_weight += 100;
			else if (symbol == ')')
				plus_weight -= 100;
			else {
				if (is_operator(symbol) == 2)
					symbol = get_op(str);
				if (is_binary == 1 && infix[infix.size() - 1].oper.is_bin == 1)
					throw out_of_range("There're two binary operations together");
				Operation op;
				op.sign = symbol;
				op.weight = priority(symbol) + plus_weight;
				op.is_bin = is_binary;
				op.is_op = 1;
				union Element opr = { op };
				infix.push_back(opr);
				is_binary = 0;
			}
		}
	}
	if (digit.size() != 0) {
		union Element dig = { 0 };
		dig.digit = getnum(digit);
		infix.push_back(dig);
	}
}

Notation::~Notation()
{
	digit.clear();
	infix.clear();
	prefix.clear();
}
//приоритет операций
int Notation::priority(char symbol) { 
	if (symbol == '+' || symbol == '-')
		return 2;
	else if (symbol == '*' || symbol == '/')
		return 4;
	else if (symbol == '^')
		return 6;
	else if (symbol == SIN || symbol == COS || symbol == TG || symbol == CTG || symbol == SQRT || symbol == LN || symbol == LG || symbol == ARCSIN || symbol == ARCCOS || symbol == ARCTG || symbol == ARCCTG)
		return 8;
	else if (symbol == '(' || symbol == ')')
		return 1;
	else return 0;
}
//является ли оператором
int Notation::is_operator(char symbol) {
	switch (symbol) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '(':
	case ')':
		return 3;
		break;
	case 'a':
	case 'c':
	case 's':
	case 't':
	case 'l':
		return 2;
		break;
	case 'p':
		return 1;
	case 'e':
		return 1;
	default:
		return 0;
	}
}
//получение числа double из char
double Notation::getnum(vector <int> digit) {
	double num = 0;
	index = 0;
	size_t size = digit.size(), dot = 0;
	for (size_t k = digit.size(); k > 0; k--) {
		if (digit[k - 1] < 0) {
			dot = digit[k - 1] * (-1);
			digit.pop_back();
			size--;
		}
		else {
			num += digit[k - 1] * pow(10, (size - k));
			digit.pop_back();
		}
	}
	if (dot != 0)
		num /= pow(10, (size - dot));
	return num;
}
//перевод в польскую запись
void Notation::infixtoprefix() {

	vector <union Element> temp;
	for (int j = infix.size() - 1; j >= 0; j--) {
		if (infix[j].oper.is_op != 1)
			prefix.push_back(infix[j]);
		else {
			if (temp.size() == 0)
				temp.push_back(infix[j]);
			else {
				while (temp.size() != 0 && (infix[j].oper.weight < temp[temp.size() - 1].oper.weight)) {
					prefix.push_back(temp[temp.size() - 1]);
					temp.pop_back();
				}
				temp.push_back(infix[j]);
			}
		}
	}
	while (temp.size() != 0) {
		prefix.push_back(temp[temp.size() - 1]);
		temp.pop_back();
	}
	cout << "\nPolish notation: ";
	for (int k = prefix.size() - 1; k >= 0; k--) {
		if (prefix[k].oper.is_op == 1)
			print(prefix[k].oper.sign);
		else {
			if (prefix[k].digit == PI)
				cout << "pi ";
			else if (prefix[k].digit == E)
				cout << "e ";
			else cout << prefix[k].digit << " ";
		}
	}
}
//вычисление выражения
double Notation::Calculator(){
	while (prefix.size() != 1) {
		for (int k = prefix.size() - 1; k >= 0; k--) {
			double second = 0;
			if (prefix[k].oper.is_op == 1 && prefix[k - 1].oper.is_op == 0) {
				if (prefix[k].oper.is_bin == 1 && prefix[k - 2].oper.is_op == 0) {
					second = prefix[k - 2].digit;
					remove(k - 2);
					k--;
					prefix[k - 1].digit = calculate(prefix[k - 1].digit, second, prefix[k].oper.sign);
					remove(k);
					k--;
				}
				else if (prefix[k].oper.is_bin == 0) {
					if (prefix[k].oper.sign == '-')
						second = prefix[k - 1].digit * 2;
					prefix[k - 1].digit = calculate(prefix[k - 1].digit, second, prefix[k].oper.sign);
					remove(k);
					k--;
				}
			}
		}
	}
	return prefix[0].digit;
	
}
void Notation::print(char operation) {
	if (operation == SIN)
		cout << "sin ";
	else if (operation == COS)
		cout << "cos ";
	else if (operation == TG)
		cout << "tg ";
	else if (operation == CTG)
		cout << "ctg ";
	else if (operation == ARCSIN)
		cout << "arcsin ";
	else if (operation == ARCCOS)
		cout << "arccos ";
	else if (operation == ARCTG)
		cout << "arctg ";
	else if (operation == ARCCTG)
		cout << "arcctg ";
	else if (operation == SQRT)
		cout << "sqrt ";
	else if (operation == LN)
		cout << "ln ";
	else if (operation == LG)
		cout << "lg ";
	else cout << operation << " ";
}
void Notation::remove(int index) {
	vector <union Element> temp;
	for (size_t i = 0; i < index; i++) 
		temp.push_back(prefix[i]);
	for (size_t j = index + 1; j < prefix.size(); j++)
		temp.push_back(prefix[j]);
	prefix.clear();
	prefix = temp;
}
double Notation::calculate(double first, double second, char operation) {
	switch (operation) {
	case '+':
		return first + second;
	case '-':
		return first - second;
	case '*':
		return first * second;
	case '/':
		if (second != 0)
			return first / second;
		else throw out_of_range("Delenie na nol'");
	case '^':
		return pow(first, second);
	case SIN:
		return sin(first);
	case COS:
		return cos(first);
	case TG:
		return tan(first);
	case CTG:
		return 1 / tan(first);
	case ARCSIN:
		return asin(first);
	case ARCCOS:
		return acos(first);
	case ARCTG:
		return atan(first);
	case ARCCTG:
		return (PI / 2 - atan(first));
	case SQRT:
		return sqrt(first);
	case LN:
		return log(first);
	case LG:
		return log10(first);
	default: return 0;
	}
}
char Notation::get_op(const char * str) {
	if (str[iter] == 'c') {
		if (str[iter + 1] == 'o' && str[iter + 2] == 's') {
			iter += 2;
			return COS;
		}
		if (str[iter + 1] == 't' && str[iter + 2] == 'g') {
			iter += 2;
			return CTG;
		}
		else throw out_of_range("Incorrect input");
	}
	if (str[iter] == 's') {
		if (str[iter + 1] == 'i' && str[iter + 2] == 'n') {
			iter += 2;
			return SIN;
		}
		if (str[iter + 1] == 'q' && str[iter + 2] == 'r' && str[iter + 3] == 't') {
			iter += 3;
			return SQRT;
		}
		else throw out_of_range("Incorrect input");
	}
	if (str[iter] == 't')
		if (str[iter + 1] == 'g') {
			iter += 1;
			return TG;
		}
		else throw out_of_range("Incorrect input");
	if (str[iter] == 'l') {
		if (str[iter + 1] == 'g') {
			iter += 1;
			return LG;
		}
		if (str[iter + 1] == 'n') {
			iter += 1;
			return LN;
		}
		else throw out_of_range("Incorrect input");
	}
	if (str[iter] == 'a' && str[iter + 1] == 'r' && str[iter + 2] == 'c') {
		if (str[iter + 3] == 's' && str[iter + 4] == 'i' && str[iter + 5] == 'n') {
			iter += 5;
			return ARCSIN;
		}
		if (str[iter + 3] == 'c' && str[iter + 4] == 'o' && str[iter + 5] == 's') {
			iter += 5;
			return ARCCOS;
		}
		if (str[iter + 3] == 'c' && str[iter + 4] == 't' && str[iter + 5] == 'g') {
			iter += 5;
			return ARCCTG;
		}
		if (str[iter + 3] == 't' && str[iter + 4] == 'g') {
			iter += 4;
			return ARCTG;
		}
		else throw out_of_range("Incorrect input");
	}
}

bool is_equal(vector <union Element> first, vector <union Element> second) {
	bool is_eq = 0;
	if (first.size() != second.size())
		return is_eq;
	for (size_t i = 0; i < first.size(); i++) {
		if (first[i].oper.is_op == 1) {
			if (first[i].oper.sign == second[i].oper.sign && first[i].oper.weight == second[i].oper.weight && first[i].oper.is_bin == second[i].oper.is_bin && first[i].oper.is_op == second[i].oper.is_op)
					is_eq = 1;
			else is_eq = 0;
		}
		else if (first[i].digit == second[i].digit)
			is_eq = 1;
		else is_eq = 0;
	}
	return is_eq;
}
vector <union Element> Notation::get_infix() {
	return infix;
}
vector <union Element> Notation::get_prefix() {
	return prefix;
}