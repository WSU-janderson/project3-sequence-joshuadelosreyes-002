/**
 *	Sequence.h
 *	Project 3
 *	CS 3100
 *
 *	The Sequence class is implemented as a double-linked list. Because it is a linked list,
 *	it contains objects from another class called nodes, which hold an element of type
 *	std::string.
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "SequenceNode.cpp"

class Sequence {
	public:
		Sequence(size_t size = 0);
		Sequence(const Sequence &s);
		~Sequence();

		Sequence & operator=(const Sequence &s);
		std::string & operator[](size_t position);

		void push_back(std::string item);
		void pop_back();
		void insert(size_t position, std::string item);

		std::string front() const;
		std::string back() const;

		bool empty() const;
		size_t size() const;
		void clear();

		void erase(size_t position);
		void erase(size_t position, size_t count);

		friend std::ostream & operator<<(std::ostream &os, const Sequence &s);

	private:

		/**
		 *	First node in the linked list.
		 */
		SequenceNode *head;

		/**
		 *	Last node in the linked list.
		 */
		SequenceNode *tail;

		/**
		 *	Number of elements in this Sequence.
		 */
		size_t length;

		void check_empty() const;
		void check_index(size_t index) const;
		SequenceNode * node_at(size_t index) const;
};

#endif
