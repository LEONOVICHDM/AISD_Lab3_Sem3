#include <iostream>
#include "BinaryHeap.h"
#include"iterators.h"
#include "Queue.h"
#include"stack.h"

using namespace std;

int main()
{
	Heap heap(1);
	Iterator* bft_1, * bft_2, * dft_1, * dft_2;
	heap.insert(1);				
	heap.insert(2);
	heap.insert(3);
	heap.insert(4);
	heap.insert(700);
	heap.insert(4);
	heap.insert(15);
	heap.insert(7);
	/*
					700
				  /		\
				 15		 4
			   /   \   /   \
			  7     2  1    4
			/  \
	       1    3
	*/
	
	bft_1 = heap.create_dft();
	dft_1 = heap.create_bft();

	cout << "depth-first traverse and breadth-first traverse: \n";
	if (bft_1->has_next()) {
		while (bft_1->has_next()) { cout << bft_1->next() << endl; }
	}
	cout << endl;

	if (dft_1->has_next()) {
		while (dft_1->has_next()) { cout << dft_1->next() << endl; }
	}
	cout << endl;

	heap.remove(4);

	bft_2 = heap.create_dft();
	dft_2 = heap.create_bft();

	cout << "depth-first traverse and breadth-first traverse after remove element with key 4: \n";
	if (dft_2->has_next()) {
		while (dft_2->has_next()) { cout << dft_2->next() << endl; }
	}
	cout << endl;

	if (bft_2->has_next()) {
		while (bft_2->has_next()) { cout << bft_2->next() << endl; }
	}
	cout << endl;

	delete bft_1, bft_2, dft_1, dft_2;
}