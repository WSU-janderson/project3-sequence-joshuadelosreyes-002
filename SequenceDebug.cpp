/**
 *	SequenceDebug.cpp
 *	Project 3
 *	CS 3100
 *
 *	In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 *	SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness.
 */

#include "Sequence.h"
#include <iostream>

using namespace std;

int main() {
	/*
	 *	Creating 3 Sequences in the stack.
	 */
	Sequence s1, s2, s3;

	cout << "Uninitialized Sequence s1:\n";
	cout << "Size: " << s1.size() << "\n";
	cout << "Contents: " << s1 << "\n\n";

	/*
	 *	Assigning a new Sequence to an existing Sequence.
	 */
	cout << "Creating empty Sequence and replacing s1...\n\n";
	s1 = Sequence(0);
	cout << "Initialized Sequence s1 to empty Sequence:\n";
	cout << "Size: " << s1.size() << "\n";
	cout << "Contents: " << s1 << "\n\n";

	/*
	 *	Accessing first and last item, and removing the last item from an empty Sequence.
	 */
	try {
		cout << "Getting first item on s1...\n";
		cout << s1.front() << "\n";
		cout << "s1 is not empty.\n";
	} catch (exception e) {
		cout << "But s1 is empty.\n";
	} try {
		cout << "Getting last item on s1...\n";
		cout << s1.back() << "\n";
		cout << "s1 is not empty.\n";
	} catch (exception e) {
		cout << "But s1 is empty.\n";
	} try {
		cout << "Removing the last item on s1...\n";
		s1.pop_back();
		cout << "s1 was not empty; new size: " << s1.size() << "\n";
	} catch (exception e) {
		cout << "But s1 is empty.\n";
	}

	/*
	 *	Sequence of nonzero length with nonzero length initialization, then
	 *	accessing indices to modify content inside the Sequence.
	 */
	cout << "Creating Sequence s2 with length 5...\n\n";
	s2 = Sequence(5);
	cout << "Size: " << s2.size() << "\n\n";
	cout << "Assigning new strings into existing elements in s2...\n\n";
	s2[0] = "first";
	s2[3] = "a multiword element";
	s2[4] = "last";
	for (size_t i = 0; i < 11; ++i) {
		try {
			cout << "s2[" << i << "] = ";
			cout << s2[i] << "\n";
		} catch (exception e) {
			cout << "\ns2[" << i << "] does not exist.\n";
		}
	}

	/*
	 *	Insertion at an index, and adding and removing items at the end of the
	 *	Sequence.
	 */
	cout << "\nContents of s2:\n" << s2 << "\n";
	cout << "Size: " << s2.size() << "\n\n";
	cout << "Inserting an element...\n";
	s2.insert(2, "inserted something");
	try {
		s2.insert(s2.size(), "inserted another");
		cout << "Insertion exists at index equal to size or greater.\n";
	} catch (exception e) {
		cout << "Cannot insert at indices >= size().\n";
	}
	cout << "\nContents of s2:\n" << s2 << "\n";
	cout << "Size: " << s2.size() << "\n\n";
	cout << "Appending an element...\n";
	s2.push_back("end");
	cout << "\nContents of s2:\n" << s2 << "\n";
	cout << "Size: " << s2.size() << "\n\n";
	cout << "Removing last element of s2...\n";
	s2.pop_back();
	cout << "\nContents of s2:\n" << s2 << "\n";
	cout << "Size: " << s2.size() << "\n\n";

	/*
	 *	Creating another Sequence, as a copy of an existing Sequence.
	 *	The `=` operator first performs deallocation of the current Sequence before
	 *	calling the copy constructor on a temporary Sequence in a new stack frame, then
	 *	copying parameters to the current Sequence.
	 */
	s3 = s2;
	cout << "Contents of s2: " << s2 << "\n";
	cout << "Size: " << s2.size() << "\n";
	cout << "Contents of s3: " << s3 << "\n";
	cout << "Size: " << s3.size() << "\n\n";

	/*
	 *	Modifying s3 through single element deletion.
	 *	Deleting an element should release the memory taken by an old element,
	 *	as each element is contained by only one Sequence.
	 *	If s2 and s3 have different content output, then these Sequences are
	 *	independent to each other, satisfying the criteria of deep copying.
	 */
	s3.erase(0);
	cout << "Erased first element in s3.\n";
	cout << "Contents of s2: " << s2 << "\n";
	cout << "Size: " << s2.size() << "\n";
	cout << "Contents of s3: " << s3 << "\n";
	cout << "Size: " << s3.size() << "\n\n";

	/*
	 *	Starting multielement deletion.
	 */
	cout << "Starting multielement deletion.\n";
	s3.push_back("trying");
	s3.push_back("to");
	s3.push_back("extend");
	s3.push_back("this");
	cout << "Contents of s3: " << s3 << "\n";
	cout << "Size: " << s3.size() << "\n\n";
	try {
		cout << "Erasing 5 elements starting at index 8.\n";
		s3.erase(8, 5);
		cout << "Contents of s3: " << s3 << "\n";
		cout << "Size: " << s3.size() << "\n\n";
	} catch (exception e) {
		cout << "Attempting to erase elements of nonexistent indices.\n\n";
	}
	cout << "Erasing 3 elements starting at index 3.\n";
	s3.erase(3, 3);
	cout << "Contents of s3: " << s3 << "\n";
	cout << "Size: " << s3.size() << "\n\n";

	/*
	 *	Clearing s1. If s1 has any elements, all content in the Sequence is removed.
	 *	Clearing requires deletion from index 0 with length equal to size, which passes the bounds check.
	 *	If the Sequence is already empty, no exception should be thrown.
	 *	Clone Sequence s2 of length 1000, to s1, then clearing s1. Repeat this 10000 times.
	 */
	cout << "Before clearing:\n";
	cout << "Contents of s1: " << s1 << "\n";
	cout << "Size: " << s1.size() << "\n\n";
	s1.clear();
	cout << "After clearing:\n";
	cout << "Contents of s1: " << s1 << "\n";
	cout << "Size: " << s1.size() << "\n\n";

	s2 = Sequence(1000);
	for (unsigned int i = 0; i < 10000; ++i) {
		s1 = s2;
		s1.clear();
	}

	cout << "Exiting main method should remove the Sequence objects on the stack.\n";
	return 0;
}
