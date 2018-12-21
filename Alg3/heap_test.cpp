#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab_3.1/Heap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HeapTests
{
	TEST_CLASS(Contains_test)
	{
	public:

		TEST_METHOD(contains)
		{
			int * number = new int[10];
			size_t size = 10;

			for (size_t i = 0; i < size; ++i)
				number[i] = i;

			Heap heap(size, number);

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(heap.contains(i));
		}

		TEST_METHOD(contains_false)
		{
			int * number = new int[10];
			size_t size = 10;

			for (size_t i = 0; i < size; ++i)
				number[i] = i;

			Heap heap(size,number);

			for (size_t i = 10; i < size + 10; ++i)
				Assert::IsFalse(heap.contains(i));
		}

	};

	TEST_CLASS(Insert_test)
	{
	public:

	
		TEST_METHOD(max_insert)
		{
			size_t size = 5;
			int * number = new int[size - 1];

			for (size_t i = 0; i < size - 1; ++i)
				number[i] = i;

			Heap heap(size - 1, number);

			delete number;
			number = new int[size];

			number[0] = 4;
			number[1] = 3;
			number[2] = 2;
			number[3] = 0;
			number[4] = 1;

			heap.insert(4);

			Heap::Iterator * iterator = heap.createBFTIterator();

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(iterator->next() == number[i]);
		}

		TEST_METHOD(min_insert)
		{
			size_t size = 5;
			int * number = new int[size - 1];

			for (size_t i = 1; i < size; ++i)
				number[i - 1] = i;

			Heap heap(size - 1, number);

			delete number;
			number = new int[size];

			number[0] = 4;
			number[1] = 2;
			number[2] = 3;
			number[3] = 1;
			number[4] = 0;

			heap.insert(0);

			Heap::Iterator * iterator = heap.createBFTIterator();

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(iterator->next() == number[i]);
		}

		TEST_METHOD(insert)
		{
			size_t size = 5;
			int * number = new int[size - 1];

			for (size_t i = 0; i < size - 1; ++i)
				number[i] = i;

			Heap heap(size - 1, number);

			delete number;
			number = new int[size];

			number[0] = 3;
			number[1] = 2;
			number[2] = 2;
			number[3] = 0;
			number[4] = 1;

			heap.insert(2);

			Heap::Iterator * iterator = heap.createBFTIterator();

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(iterator->next() == number[i]);
		}

	};

	TEST_CLASS(Remove_test)
	{
	public:

		TEST_METHOD(remove_root)
		{
			Heap heap;
			size_t size = 10;

			for (size_t i = 0; i < size; ++i)
				heap.insert(i);

			heap.remove(0);

			Assert::IsFalse(heap.contains(0));
			for (size_t i = 1; i < size; ++i)
				Assert::IsTrue(heap.contains(i));
			Assert::IsTrue(heap.size() == size - 1);
		}

		TEST_METHOD(remove)
		{
			Heap heap;
			size_t size = 10;

			for (size_t i = 0; i < size; ++i)
				heap.insert(i);

			heap.remove(5);

			Assert::IsFalse(heap.contains(5));
			Assert::IsTrue(heap.size() == size - 1);
		}

		
		TEST_METHOD(remove_false)
		{
			Heap heap;
			size_t size = 10;

			for (size_t i = 0; i < size; ++i)
				heap.insert(i);

			try
			{
				heap.remove(size + 1);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "This item is not found");
			}
		}
	};

	TEST_CLASS(Iterators_test)
	{
	public:

		TEST_METHOD(DFTIterator)
		{
			
			size_t size = 10;
			int array[10] = { 0, 1, 3, 7, 8, 4, 9, 2, 5, 6};
			Heap heap(size, array);
			int result[10] = { 9, 8, 7, 2, 5, 6, 1, 4, 0, 3};

			Heap::Iterator * iterator = heap.createDFTIterator();

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(iterator->next() == result[i]);
		}

		TEST_METHOD(DFTIterator_oor)
		{
			Heap heap;
			size_t size = 10;

			for (size_t i = 0; i < size; ++i)
				heap.insert(i);

			Heap::Iterator * iterator = heap.createDFTIterator();

			for (size_t i = 0; i < size; ++i)
				iterator->next();

			try
			{
				iterator->next();

				Assert::IsTrue(false);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "OutOfRangeException");
			}
		}

		TEST_METHOD(BFTIterator)
		{
			Heap heap;
			size_t size = 5;
			int * result = new int[size];

			for (size_t i = 0; i < size; ++i)
				heap.insert(i);

			result[0] = 4;
			result[1] = 3;
			result[2] = 1;
			result[3] = 0;
			result[4] = 2;

			Heap::Iterator * iterator = heap.createBFTIterator();

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(iterator->next() == result[i]);
		}

		TEST_METHOD(BFTIterator_oor)
		{
			Heap heap;
			size_t size = 10;

			for (size_t i = 0; i < size; ++i)
				heap.insert(i);

			Heap::Iterator * iterator = heap.createBFTIterator();

			for (size_t i = 0; i < size; ++i)
				iterator->next();

			try
			{
				iterator->next();

				Assert::IsTrue(false);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "OutOfRangeException");
			}
		}

	};

	TEST_CLASS(Operator_test)
	{
	public:

		TEST_METHOD(Index_operator)
		{
			Heap heap;
			size_t size = 5;

			for (size_t i = 0; i < size; ++i)
				heap.insert(i);

			int * result = new int[size];
			result[0] = 4;
			result[1] = 3;
			result[2] = 1;
			result[3] = 0;
			result[4] = 2;

			for (size_t i = 0; i < size; ++i)
				Assert::IsTrue(result[i] == heap[i]);
		}

	};
}
