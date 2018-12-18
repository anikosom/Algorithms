#include "stdafx.h"
#include "CppUnitTest.h"
#include "/Users/Foxys/source/repos/Lab_1/Lab_1/Array_functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Lab_1_Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(is_eq_equal_arrays)
		{
			
			const size_t rows = 3;
			const size_t columns = 2;
			int **arr1 = new int*[rows];
			arr1[0] = new int[columns]{ -5, -4 };
			arr1[1] = new int[columns]{ -3, -2 };
			arr1[2] = new int[columns]{ -1, 0 };
			int **arr2 = new int*[rows];
			arr2[0] = new int[columns]{ -5, -4 };
			arr2[1] = new int[columns]{ -3, -2 };
			arr2[2] = new int[columns]{ -1, 0 };
			Assert::IsTrue(is_equal(arr1, rows, columns, arr2, rows, columns));
			delete[] arr1;
			delete[] arr2;
		}
		TEST_METHOD(is_eq_dif_size_arrays)
		{
			
			const size_t rows1 = 3;
			const size_t rows2 = 5;
			const size_t columns = 2;
			int **arr1 = new int*[rows1];
			arr1[0] = new int[columns] { -5, -4 };
			arr1[1] = new int[columns] { -3, -2 };
			arr1[2] = new int[columns] { -1, 0 };
			int **arr2 = new int*[rows2];
			arr2[0] = new int[columns] { -6, -4 };
			arr2[1] = new int[columns] { -3, -2 };
			arr2[2] = new int[columns] { -1, 0 };
			arr2[2] = new int[columns] { -1, 0 };
			arr2[2] = new int[columns] { -1, 0 };
			Assert::IsFalse(is_equal(arr1, rows1, columns, arr2, rows2, columns));
			delete[] arr1;
			delete[] arr2;
		}
		TEST_METHOD(is_eq_dif_arr)
		{

			const size_t rows = 3;
			const size_t columns = 2;
			int **arr1 = new int*[rows];
			arr1[0] = new int[columns] { -5, -4 };
			arr1[1] = new int[columns] { -3, -2 };
			arr1[2] = new int[columns] { -1, 0 };
			int **arr2 = new int*[rows];
			arr2[0] = new int[columns] { -6, -4 };
			arr2[1] = new int[columns] { -3, -2 };
			arr2[2] = new int[columns] { -1, 0 };
			Assert::IsFalse(is_equal(arr1, rows, columns, arr2, rows, columns));
			delete[] arr1;
			delete[] arr2;
		}
		TEST_METHOD(fill_arr_test)
		{
			
			const size_t rows = 4;
			const size_t columns = 2;
			int **arr1 = new int*[rows];
			arr1[0] = new int[columns] { -5, -4 };
			arr1[1] = new int[columns] { -3, -2 };
			arr1[2] = new int[columns] { -1, 0 };
			arr1[3] = new int[columns] { 1, 2 };
			int **arr2 = new int*[rows];
			arr2[0] = new int[columns];
			arr2[1] = new int[columns];
			arr2[2] = new int[columns];
			arr2[3] = new int[columns];
			fill_array(arr2, rows, columns, -5);
			Assert::IsTrue(is_equal(arr1, rows, columns, arr2, rows, columns));
			delete[] arr1;
			delete[] arr2;
		}
		TEST_METHOD(fill_arr_size1x1)
		{
			const size_t rows = 1;
			const size_t columns = 1;
			int **arr1 = new int*[rows];
			arr1[0] = new int[columns] { 290 };
			int **arr2 = new int*[rows];
			arr2[0] = new int[columns];
			fill_array(arr2, rows, columns, 290);
			Assert::IsTrue(is_equal(arr1, rows, columns, arr2, rows, columns));
			delete[] arr1;
			delete[] arr2;
		}
		TEST_METHOD(fill_arr_size1x7)
		{
			const size_t rows = 1;
			const size_t columns = 7;
			int **arr1 = new int*[rows];
			arr1[0] = new int[columns] { 2, 3, 4, 5, 6, 7, 8};
			int **arr2 = new int*[rows];
			arr2[0] = new int[columns];
			fill_array(arr2, rows, columns, 2);
			Assert::IsTrue(is_equal(arr1, rows, columns, arr2, rows, columns));
			delete[] arr1;
			delete[] arr2;
		}
		TEST_METHOD(fill_arr_size5x1)
		{
			const size_t rows = 5;
			const size_t columns = 1;
			int **arr1 = new int*[rows];
			arr1[0] = new int[columns] { -50  };
			arr1[1] = new int[columns] { -49  };
			arr1[2] = new int[columns] { -48  };
			arr1[3] = new int[columns] { -47  };
			arr1[4] = new int[columns] { -46  };
			int **arr2 = new int*[rows];
			for (size_t i = 0; i < rows; i++)
				arr2[i] = new int[columns];
			fill_array(arr2, rows, columns, -50);
			Assert::IsTrue(is_equal(arr1, rows, columns, arr2, rows, columns));
			delete[] arr1;
			delete[] arr2;
		}
	};
}