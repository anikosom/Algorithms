#include "stdafx.h"
#include <vector>
#include "CppUnitTest.h"
#include "..\Cursach\Notation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(Is_equal)
	{
	public:
		
		TEST_METHOD(is_equal_dig_true)
		{
			vector <union Element> first;
			union Element dig = { 0 };
			for (double i = 12.5; i < 120; i += 10.5) {
				dig.digit = i;
				first.push_back(dig);
			}
			vector <union Element> second;
			union Element dig2 = { 0 };
			for (double i = 12.5; i < 120; i += 10.5) {
				dig2.digit = i;
				second.push_back(dig2);
			}
			Assert::IsTrue(is_equal(first, second));
		
		}
		TEST_METHOD(is_equal_dig_false)
		{
			vector <union Element> first;
			union Element dig = { 0 };
			for (double i = 12.5; i < 120; i += 10.5) {
				dig.digit = i;
				first.push_back(dig);
			}
			vector <union Element> second;
			union Element dig2 = { 0 };
			for (double i = 0; i < 100; i += 10.5) {
				dig2.digit = i;
				second.push_back(dig2);
			}
			Assert::IsFalse(is_equal(first, second));

		}
		TEST_METHOD(is_equal_oper_true)
		{
			vector <union Element> first;
			union Element oper = { '*', 10, 0, 1 };
			first.push_back(oper);
			first.push_back(oper);
			vector <union Element> second;
			union Element oper2 = { '*', 10, 0, 1 };
			second.push_back(oper2);
			second.push_back(oper2);
			Assert::IsTrue(is_equal(first, second));
		}
		TEST_METHOD(is_equal_oper_false)
		{
			vector <union Element> first;
			union Element oper = { '*', 10, 0, 1 };
			first.push_back(oper);
			first.push_back(oper);
			vector <union Element> second;
			union Element oper2 = { '/', 12, 0, 1 };
			second.push_back(oper2);
			second.push_back(oper2);
			Assert::IsFalse(is_equal(first, second));
		}
		TEST_METHOD(is_equal_oper_and_dig)
		{
			vector <union Element> first;
			union Element oper = { '*', 10, 0, 1 };
			union Element dig = { 0 };
			dig.digit = { -12.345 };
			first.push_back(oper);
			first.push_back(dig);
			vector <union Element> second;
			union Element oper2 = { '*', 10, 0, 1 };
			union Element dig2 = { 0 };
			dig2.digit = { -12.345 };
			second.push_back(oper2);
			second.push_back(dig2);
			Assert::IsTrue(is_equal(first, second));
		}
	};
	TEST_CLASS(Create_notation)
	{
	public:
		TEST_METHOD(create_empty_notation)
		{
			try {
				char * string = "";
				Notation infix(string, strlen(string));
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("String is empty", error.what());
			}
		}
		TEST_METHOD(create_infix_notation)
		{
			char string[] = "5.2*2^(sin(3))";
			Notation not(string, strlen(string));
			vector <union Element> second;
			union Element oper1 = { '*', 10, 1, 1 }, oper2 = { '^', 10, 1, 1 }, oper3 = { SIN, 108, 0, 1 };
			union Element dig1 = { 0 }, dig2 = { 0 }, dig3 = { 0 };
			dig1.digit = { 5.2 };
			dig2.digit = { 2 };
			dig3.digit = { 3 };
			second.push_back(oper1);
			second.push_back(dig1);
			second.push_back(oper2);
			second.push_back(dig2);
			second.push_back(oper3);
			second.push_back(dig3);
			Assert::IsTrue(is_equal(not.get_infix() , second));
		}
		TEST_METHOD(create_incorrect_notation)
		{
			try {
				char string[] = "5.2*2gdf^(sin(3))";
				Notation not(string, strlen(string));
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Incorrect input", error.what());
			}
		}
		TEST_METHOD(create_incorrect_op_notation)
		{
			try {
				char string[] = "5.2*-2^(sin(3))";
				Notation not(string, strlen(string));
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("There're two binary operations together", error.what());
			}
		}
	};
	TEST_CLASS(Infix_to_prefix)
	{
	public:
		TEST_METHOD(get_prefix)
		{
			char string[] = "arctg(pi)-12.3^e";
			Notation not(string, strlen(string));
			not.infixtoprefix();
			vector <union Element> second;
			union Element oper1 = { ARCTG, 8, 0, 1 }, oper2 = { '-', 2, 1, 1 }, oper3 = { '^', 6, 1, 1 };
			union Element dig1 = { 0 }, dig2 = { 0 }, dig3 = { 0 };
			dig1.digit = { PI };
			dig2.digit = { 12.3 };
			dig3.digit = { E };
			second.push_back(dig3);
			second.push_back(dig2);
			second.push_back(oper3);
			second.push_back(dig1);
			second.push_back(oper1);
			second.push_back(oper2);

			Assert::IsTrue(is_equal(not.get_prefix(), second));
		}

	};
	TEST_CLASS(Calculator)
	{
	public:
		TEST_METHOD(check_result)
		{
			char string[] = "(sqrt(144)-13)*(-2)";
			Notation not(string, strlen(string));
			not.infixtoprefix();
			Assert::AreEqual(not.Calculator(), 2.0);
		}
	};
}
