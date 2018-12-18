#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\Foxys\source\repos\Lab_2.3\Lab_2.3\List_functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest23
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		TEST_METHOD(is_equal_lists)
		{
			int mass_1[4] = { 70, 58 , 28, 23 };
			List DLL(mass_1, 4);

			int mass_2[4] = { 70, 58 , 28, 23 };
			List DLL2(mass_2, 4);
			Assert::IsTrue(DLL.is_equal(&DLL2));
			
		}
		TEST_METHOD(is_empty)
		{
			List list;
			Assert::IsTrue(list.isEmpty());
		}
		TEST_METHOD(get_size)
		{
			int mass_2[4] = { 70, 58 , 28, 23 };
			List list(mass_2, 4);
			Assert::IsTrue(list.get_size() == 4);
		}
		TEST_METHOD(push_back)
		{
			int mass_1[4] = { 70, 35 , 28, 23 };
			List list_1(mass_1, 4);

			int mass_2[5] = { 70, 35 , 28, 23 , 12 };
			List list_2(mass_2, 5);
			list_1.push_back(12);
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(push_front)
		{
		
			int mass_1[3] = { 5, 6, 2 };
			List list_1(mass_1, 3);
			
			int mass_2[4] = { 45, 5, 6, 2 };
			List list_2(mass_2, 4);
			list_1.push_front(45);
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(pop_back)
		{
			
			int mass_1[3] = { 44, -7, 6 };
			List list_1(mass_1, 3);
		
			int mass_2[4] = { 44, -7, 6, 2 };
			List list_2(mass_2, 4);
			list_2.pop_back();
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(pop_front)
		{
			
			int mass_1[3] = { 44, -2, 6 };
			List list_1(mass_1, 3);
			
			int mass_2[4] = { 23, 44, -2, 6 };
			List list_2(mass_2, 4);
			list_2.pop_front();
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(insert)
		{
			
			int mass_1[3] = { 4, 34, 65 };
			List list_1(mass_1, 3);
			
			int mass_2[4] = { 4, 34, 3, 65 };
			List list_2(mass_2, 4);
			list_1.insert(3, 2);
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(at)
		{
		
			int mass_1[3] = { -23, 56, 67 };
			List list_1(mass_1, 3);
			Assert::IsTrue(list_1.at(0) == -23);
		}
		TEST_METHOD(remove)
		{
			
			int mass_1[6] = { 3453, 45, 7, 8, 2, 2 };
			List list_1(mass_1, 6);
			
			int mass_2[5] = { 3453, 45, 7, 2, 2 };
			List list_2(mass_2, 5);
			list_1.remove(3);
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(set)
		{
			
			int mass_1[6] = { 54, 23, 6, 4, 5, 42 };
			List list_1(mass_1, 6);
			
			int mass_2[6] = { 54, 23, 34, 4, 5, 42 };
			List list_2(mass_2, 6);
			list_1.set(34, 2);
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(find_last)
		{
			
			int mass_1[10] = { 12, 34, 23, 23, 47, 12, 34, 23, 4, 65 };
			List list_1(mass_1, 10);
			
			int mass_2[3] = { 12, 34, 23 };
			List list_2(mass_2, 3);
			Assert::IsTrue(list_1.find_last(&list_2) == 5);
		}
		TEST_METHOD(push_back_empty_list)
		{
			List list_1;
			list_1.push_back(54);
			
			int mass_2[1] = { 54 };
			List list_2(mass_2, 1);
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(push_front_empty_list)
		{
			List list_1;
			list_1.push_front(23);
			
			int mass_2[1] = { 23 };
			List list_2(mass_2, 1);
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(get_size_empty_list)
		{
			List list_1;
			Assert::IsTrue(list_1.get_size() == 0);
		}
		TEST_METHOD(insert_head)
		{
			
			int mass_1[6] = { 54, 23, 6, 4, 5, 42 };
			List list_1(mass_1, 6);
			
			int mass_2[7] = { 15, 54, 23, 6, 4, 5, 42 };
			List list_2(mass_2, 7);
			list_1.insert(15, 0);
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(remove_head)
		{
			
			int mass_1[6] = { 54, 23, 6, 4, 5, 42 };
			List list_1(mass_1, 6);
			
			int mass_2[7] = { 15, 54, 23, 6, 4, 5, 42 };
			List list_2(mass_2, 7);
			list_2.remove(0);
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(remove_tail)
		{
			
			int mass_1[6] = { 54, 23, 6, 4, 5, 42 };
			List list_1(mass_1, 6);
			
			int mass_2[7] = { 54, 23, 6, 4, 5, 42, 4 };
			List list_2(mass_2, 7);
			list_2.remove(6);
			Assert::IsTrue(list_1.is_equal(&list_2));
		}
		TEST_METHOD(set_oor)
		{
			
			int mass_1[6] = { 54, 23, 6, 4, 5, 42 };
			List list_1(mass_1, 6);
			try {
				list_1.set(50, 10);
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Index is greater or smaller than list size", error.what());
			}
		}
		TEST_METHOD(check_index) {
			try {
				List list_1;
				list_1.check_index(5);
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Index is greater than list size", error.what());
			}
		}
		TEST_METHOD(find_last_empty_list)
		{
			
			int mass_1[6] = { 54, 23, 6, 4, 5, 42 };
			List list_1(mass_1, 6);
			List list_2;
			try {
				list_1.find_last(&list_2);
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("There's an empty list", error.what());
			}
		}
		TEST_METHOD(find_last_from_empty_list)
		{
			
			int mass_1[6] = { 54, 23, 6, 4, 5, 42 };
			List list_1(mass_1, 6);
			List list_2;
			try {
				list_2.find_last(&list_1);
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("There's an empty list", error.what());
			}
		}

	};
}