/**
 *	Sequence.cpp
 *	Project 3
 *	CS 3100
 *
 *	Definition of all methods belonging to the Sequence class.
 */

#include <exception>
#include "Sequence.h"

/**
 *	@throw `std::exception` - If the sequence is empty.
 */
void Sequence::check_empty() const {
	if (this->empty()) {throw std::exception();}
}

/**
 *	@throw `std::exception` - If the index is out of bounds of the sequence.
 */
void Sequence::check_index(size_t index) const {
	if (index >= this->length) {throw std::exception();}
}

/**
 *	Returns a node located at `index`.
 *
 *	The traversion through nodes should take at most `length / 2` steps.
 *	@throw `std::exception` - If this method is called with an invalid position.
 */
SequenceNode * Sequence::node_at(size_t index) const {
	this->check_index(index);

	SequenceNode *current;
	size_t currentIndex;

	if (index < (this->length / 2)) {
		current = this->head;
		currentIndex = 0;
		while (current) {
			if (currentIndex == index) {return current;}
			else {current = current->next; ++currentIndex;}
		}
	} else {
		current = this->tail;
		currentIndex = this->length - 1;
		while (current) {
			if (currentIndex == index) {return current;}
			else {current = current->prev; --currentIndex;}
		}
	}
}

/**
 *	Returns the first element in the sequence.
 *	@throw `std::exception` - If the sequence is empty.
 */
std::string Sequence::front() const {
	this->check_empty();
	return this->head->item;
}

/**
 *	Returns the last element in the sequence.
 *	@throw `std::exception` - If the sequence is empty.
 */
std::string Sequence::back() const {
	this->check_empty();
	return this->tail->item;
}

/**
 *	Returns `true` if the sequence has no elements, otherwise `false`.
 */
bool Sequence::empty() const {return this->length == 0;}

/**
 *	Returns the number of elements in the sequence.
 */
size_t Sequence::size() const {return this->length;}

/**
 *	All items in the sequence are deleted and the memory associated with the
 *	sequence is released, resetting the sequence to an empty state that can have
 *	items re-inserted.
 */
void Sequence::clear() {
	try {
		this->erase(0, this->size());
	} catch (std::exception e) {return;}
}

/**
 *	The item is removed from the sequence, and the memory is released.
 *	@param position An index to remove an item at that position.
 *	@throw `std::exception` - If this method is called with an invalid position.
 */
void Sequence::erase(size_t position) {this->erase(position, 1);}

/**
 *	The items in the sequence from indices `position` to `position + (count - 1)` are
 *	deleted and their memory released.
 *	@param position An index to remove an item at that position.
 *	@param count Number of elements to remove from this sequence.
 *	@throw `std::exception` - If `position` or `position + (count - 1)` resolves to an
 *		invalid index.
 */
void Sequence::erase(size_t position, size_t count) {
	this->check_index(position);
	this->check_index(position + (count - 1));

	SequenceNode *current = this->node_at(position + (count - 1));
	size_t currentIndex = position + (count - 1);

	while ((position <= currentIndex) && (currentIndex < this->length) && current) {
		SequenceNode *prev = current->prev;
		SequenceNode *next = current->next;
		if (current == this->tail) {
			this->pop_back();
		} else {
			if (next) {next->prev = prev;}
			if (prev) {prev->next = next;}
			if (current == this->head) {this->head = prev;}
			delete current;
			--this->length;
		}
		current = prev;
		--currentIndex;
	}

	return;
}

/**
 *	Creates an empty sequence (`size = 0`) or a sequence of `size` items
 *	indexed from `0` to `size - 1`.
 *	@param size Number of elements to create in a sequence.
 */
Sequence::Sequence(size_t size = 0) {
	this->length = 0;
	while (this->length < size) {
		SequenceNode *newElem = new SequenceNode();
		if (this->tail) {
			this->tail->next = newElem;
			newElem->prev = this->tail;
		} else {
			this->head = newElem;
		}
		this->tail = newElem;
		++this->length;
	}
}

/**
 *	Creates a (deep) copy of sequence `s`.
 */
Sequence::Sequence(const Sequence &s) {
	this->length = 0;
	SequenceNode *current = s.head;
	while (current) {
		this->push_back(current->item);
		current = current->next;
	}
}

/**
 *	Destroys all items in the sequence and release the memory
 *	associated with the sequence.
 */
Sequence::~Sequence() {this->clear();}

/**
 *	The value of `item` is appended to the sequence.
 */
void Sequence::push_back(std::string item) {
	SequenceNode *newElem = new SequenceNode(item);
	if (this->tail) {
		this->tail->next = newElem;
		newElem->prev = this->tail;
	} else {
		this->head = newElem;
	}
	this->tail = newElem;
	++this->length;
}

/**
 *	The item at the end of the sequence is deleted and the size of the sequence is
 *	reduced by one.
 *	@throw `std::exception` - If the sequence is empty.
 */
void Sequence::pop_back() {
	this->check_empty();
	SequenceNode *prev = this->tail->prev;
	if (prev) {prev->next = nullptr;}
	delete this->tail;
	this->tail = prev;
	--this->length;
	if (this->empty()) {this->head = nullptr;}
}

/**
 *	The position must be between `0` and `size() - 1`.
 *
 *	The value of `item` is inserted at `position` and the size of the sequence is
 *	increased by one.
 *	@throw `std::exception` - If the position is outside the bounds of the sequence.
 */
void Sequence::insert(size_t position, std::string item) {
	this->check_index(position);
	SequenceNode *newNode = new SequenceNode(item);
	if (position == 0) {
		newNode->next = this->head;
		this->head->prev = newNode;
		this->head = newNode;
	} else {
		SequenceNode *current = this->node_at(position);
		newNode->next = current;
		newNode->prev = current->prev;
		current->prev->next = newNode;
		current->next->prev = newNode;
	}
	++this->length;
}

/**
 *	The current sequence is released and replaced by a (deep) copy of
 *	sequence `s`.
 *	@return `*this`
 */
Sequence & Sequence::operator=(const Sequence &s) {
	if (this != &s) {
		this->clear();
		Sequence ss = Sequence(s);
		this->length = ss.length;
		this->head = ss.head;
		this->tail = ss.tail;
	}

	return *this;
}

/**
 *	The position must be between `0` and `size() - 1`.
 *
 *	Returns a reference to an item at index `position` in the sequence.
 *	@throw `std::exception` - If the position is outside the bounds of the sequence.
 */
std::string & Sequence::operator[](size_t position) {
	return this->node_at(position)->item;
}

/**
 *	Outputs a string representation of this sequence in the form:
 *	`<s[0], s[1], ..., s[size() - 1]>`
 */
std::ostream & operator<<(std::ostream &os, const Sequence &s) {
	os << std::string{"<"};
	for (SequenceNode *current = s.head; current; current = current->next) {
		os << current->item;
		if (current->next) {os << std::string{", "};}
	}
	os << std::string{">"};
	return os;
}
