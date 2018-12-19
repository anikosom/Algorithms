#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\Foxys\source\repos\Lab_4\Lab_4\Array_functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(is_equal_arrays)
		{
			int mass[10] = { 6, 24, 234, 54, 734, 4, 5 , 64, 22, 344 };
			Array arr(10);
			arr.array = mass;
			int mass2[10] = { 6, 24, 234, 54, 734, 4, 5 , 64, 22, 344 };
			Array arr2(10);
			arr2.array = mass2;
			Assert::IsTrue(arr.is_equal(&arr2));
		}
		TEST_METHOD(is_equal_char_arrays)
		{
			char mass[10] = { 6, 24, 24, 54, 74, 4, 5 , 64, 22, 44 };
			Array arr(10);
			arr.char_array = mass;
			char mass2[10] = { 6, 24, 24, 54, 74, 4, 5 , 64, 22, 44 };
			Array arr2(10);
			arr2.char_array = mass2;
			Assert::IsTrue(arr.is_equal_char(&arr2));
		}
		TEST_METHOD(binary_search) {
			int mass[10] = { 6, 24, 234, 54, 734, 4, 5 , 64, 22, 344 };
			Array arr(10);
			arr.array = mass;
			Assert::IsTrue(arr.BinarySearch(234) == 2);
		}
		TEST_METHOD(binary_empty_search) {
			char error;
			try {
				Array arr(0);
				arr.BinarySearch(4);
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Array is empty", error.what());
			}
		}
		TEST_METHOD(quick_sort_oor) {
			char error;
		try {
			int mass[10] = { 6, 24, 234, 54, 734, 4, 5 , 64, 22, 344 };
			Array arr(10);
			arr.array = mass;
			arr.QuickSort(0, 11);
		}
		catch (const std::out_of_range& error) {
			Assert::AreEqual("Incorrect input", error.what());
		}
		}
		TEST_METHOD(quick_empty_sort) {
			char error;
			try {
				Array arr(0);
				arr.QuickSort(0, 0);
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Array is empty", error.what());
			}
		}
		TEST_METHOD(quick_sort) {
			int mass[10] = { 6, 24, 234, 54, 734, 4, 5 , 64, 22, 344 };
			Array arr(10);
			arr.array = mass;
			int mass2[10] = { 4, 5, 6, 22, 24, 54, 64, 234, 344, 734};
			Array arr2(10);
			arr2.array = mass2;
			arr.QuickSort(0, arr.get_size() - 1);
			Assert::IsTrue(arr.is_equal(&arr2));
		}
		TEST_METHOD(bubble_sort) {
			int mass[10] = { 6, 24, 234, 54, 734, 4, 5 , 64, 22, 344 };
			Array arr(10);
			arr.array = mass;
			int mass2[10] = { 4, 5, 6, 22, 24, 54, 64, 234, 344, 734 };
			Array arr2(10);
			arr2.array = mass2;
			arr.BubbleSort();
			Assert::IsTrue(arr.is_equal(&arr2));
		}
		TEST_METHOD(bubble_empty_sort) {
			char error;
			try {
				Array arr(0);
				arr.BubbleSort();
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Array is empty", error.what());
			}
		}
		TEST_METHOD(heap_sort) {
			int mass[10] = { 6, 24, 234, 54, 734, 4, 5 , 64, 22, 344 };
			Array arr(10);
			arr.array = mass;
			int mass2[10] = { 4, 5, 6, 22, 24, 54, 64, 234, 344, 734 };
			Array arr2(10);
			arr2.array = mass2;
			arr.HeapSort();
			Assert::IsTrue(arr.is_equal(&arr2));
		}
		TEST_METHOD(heap_empty_sort) {
			char error;
			try {
				Array arr(0);
				arr.HeapSort();
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Array is empty", error.what());
			}
		}
		TEST_METHOD(bogo_sort) {
			int mass[10] = { 6, 24, 234, 54, 734, 4, 5 , 64, 22, 344 };
			Array arr(10);
			arr.array = mass;
			int mass2[10] = { 4, 5, 6, 22, 24, 54, 64, 234, 344, 734 };
			Array arr2(10);
			arr2.array = mass2;
			arr.BogoSort();
			Assert::IsTrue(arr.is_equal(&arr2));
		}
		TEST_METHOD(bogo_empty_sort) {
			char error;
			try {
				Array arr(0);
				arr.BogoSort();
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Array is empty", error.what());
			}
		}
		TEST_METHOD(counting_sort) {
			char mass[10] = { 6, 24, 24, 54, 74, 4, 5 , 64, 22, 44 };
			Array arr(10);
			arr.char_array = mass;
			char mass2[10] = { 4, 5, 6, 22, 24, 24, 44, 54, 64, 74 };
			Array arr2(10);
			arr2.char_array = mass2;
			arr.CountingSort();
			Assert::IsTrue(arr.is_equal_char(&arr2));
		}
		TEST_METHOD(counting_empty_sort) {
			char error;
			try {
				Array arr(0);
				arr.CountingSort();
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Array is empty", error.what());
			}
		}
	};
}
