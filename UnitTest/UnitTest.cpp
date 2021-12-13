#include "pch.h"
#include "CppUnitTest.h"
#include"..\ISD_Lab3_Sem3\BinaryHeap.h"
#include"..\ISD_Lab3_Sem3\iterators.h"
#include"..\ISD_Lab3_Sem3\Queue.h"
#include"..\ISD_Lab3_Sem3\stack.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(test_iterators_dft_bft)
		{
			Heap heap(1);
			Iterator* dft, * bft;
			heap.insert(1);
			heap.insert(2);
			heap.insert(3);
			heap.insert(4);
			heap.insert(700);
			heap.insert(4);
			heap.insert(15);
			heap.insert(7);
			int arrayDfs[9], i = 0;
			dft = heap.create_dft();
			bft = heap.create_bft();
			if (dft->has_next()) {
				while (dft->has_next()) { arrayDfs[i++] = dft->next(); }
			}
			int arrayBfs[9]; i = 0;
			if (bft->has_next()) {
				while (bft->has_next()) { arrayBfs[i++] = bft->next(); }
			}
			Assert::AreEqual(700, arrayDfs[0]);
			Assert::AreEqual(15, arrayDfs[1]);
			Assert::AreEqual(7, arrayDfs[2]);
			Assert::AreEqual(1, arrayDfs[3]);
			Assert::AreEqual(3, arrayDfs[4]);
			Assert::AreEqual(2, arrayDfs[5]);
			Assert::AreEqual(4, arrayDfs[6]);
			Assert::AreEqual(1, arrayDfs[7]);
			Assert::AreEqual(4, arrayDfs[8]);

			Assert::AreEqual(700, arrayBfs[0]);
			Assert::AreEqual(15, arrayBfs[1]);
			Assert::AreEqual(4, arrayBfs[2]);
			Assert::AreEqual(7, arrayBfs[3]);
			Assert::AreEqual(2, arrayBfs[4]);
			Assert::AreEqual(1, arrayBfs[5]);
			Assert::AreEqual(4, arrayBfs[6]);
			Assert::AreEqual(1, arrayBfs[7]);
			Assert::AreEqual(3, arrayBfs[8]);
			delete dft, bft;
		}
		TEST_METHOD(test_contains)
		{
			Heap heap(1), empyHeap;
			heap.insert(1);
			heap.insert(2);
			heap.insert(3);
			heap.insert(4);
			heap.insert(700);
			heap.insert(4);
			heap.insert(15);
		
			Assert::IsFalse(heap.contains(7));
			Assert::IsTrue(heap.contains(700));
			
		}

		TEST_METHOD(test_insert)
		{
			Heap heap(1), empyHeap;
			
			heap.insert(700);
			Assert::IsTrue(heap.contains(700));
		}

		TEST_METHOD(test_remove)
		{
			Heap heap(1), empyHeap;
			heap.insert(1);
			heap.insert(2);
			heap.insert(3);
			heap.insert(4);
			heap.insert(700);

			heap.remove(3);
			Assert::IsFalse(heap.contains(3));
		}
		
	};
}
