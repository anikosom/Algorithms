#include "pch.h"
#include <iostream>
#include <math.h>
# include <stdio.h>
# include <string.h>
#include <vector>
#include "Notation.h"
using namespace std;

int main() {
	char string[100];
	printf("Enter infix expression: ");
	gets_s(string);
	Notation expression(string, strlen(string));
	expression.infixtoprefix();
	cout << "\n\nResult: ";
	cout << expression.Calculator();
}
