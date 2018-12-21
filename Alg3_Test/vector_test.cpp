
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab_3.1/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTests
{
	TEST_CLASS(Operator_test)
	{
	public:

		TEST_METHOD(index_operator)
		{
			size_t size = 10;
			int * number = new int[size];

			for (size_t i = 0; i < size; ++i)
				number[i] = i;

			Vector vec(number, size);

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(vec[i] == i);
		}

		TEST_METHOD(assignment_operator)
		{
			Vector vec1, vec2;
			size_t size = 10;

			for (size_t i = 0; i < size; ++i)
				vec2.push_back(i);

			vec1 = vec2;

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(vec1[i] == i);
		}

	};

	TEST_CLASS(Push_back_test)
	{
	public:

		TEST_METHOD(push_back_empty_vec)
		{
			Vector vec;

			vec.push_back(1);

			Assert::IsTrue(vec[0] == 1 && vec.size() == 1);
		}

		TEST_METHOD(push_back)
		{
			Vector vec;
			size_t size = 10;

			for (int i = 0; i < size; ++i)
				vec.push_back(i);

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(vec[i] == i);
		}

	};


	TEST_CLASS(Size_test)
	{
		TEST_METHOD(size)
		{
			Vector vec;
			size_t size = 10;

			for (size_t i = 0; i < size; ++i)
				vec.push_back(i);

			Assert::IsTrue(vec.size() == size);
		}

		TEST_METHOD(size_empty)
		{
			Vector vec;

			Assert::IsTrue(vec.size() == 0);
		}
	};

	TEST_CLASS(Contains_test)
	{
		TEST_METHOD(contains)
		{
			int * number = new int[10];
			size_t size = 10;

			for (size_t i = 0; i < size; ++i)
				number[i] = i;

			Vector vec(number, size);

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(vec.contains(i) >= 0);
		}

		TEST_METHOD(contains_false)
		{
			int * number = new int[10];
			size_t size = 10;

			for (size_t i = 0; i < size; ++i)
				number[i] = i;

			Vector vec(number, size);

			for (size_t i = 10; i < size + 10; ++i)
				Assert::IsFalse(vec.contains(i) >= 0);
		}
	};
}