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
	Sequence s1, s2, s3;

	cout << "Uninitialized Sequence s1:\n";
	cout << "Size: " << s1.size() << "\n";
	cout << "Contents: " << s1 << "\n\n";

	cout << "Creating empty Sequence and replacing s1...\n\n";
	s1 = Sequence(0);
	cout << "Initialized Sequence s1 to empty Sequence:\n";
	cout << "Size: " << s1.size() << "\n";
	cout << "Contents: " << s1 << "\n\n";

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

	cout << "\nContents of s2:\n" << s2 << "\n";
	cout << "Size: " << s2.size() << "\n";
	cout << "Inserting an element...\n";
	s2.insert(2, "inserted something");
	cout << "\nContents of s2:\n" << s2 << "\n";
	cout << "Size: " << s2.size() << "\n";
	cout << "Appending an element...\n";
	s2.push_back("end");
	cout << "\nContents of s2:\n" << s2 << "\n";
	cout << "Size: " << s2.size() << "\n";

	cout << "Exiting main method should remove the Sequence objects on the stack.\n";
	return 0;
}
