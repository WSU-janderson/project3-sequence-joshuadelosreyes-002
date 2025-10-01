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
 *	@throw `std::exception` - If this method is called with an invalid exception.
 */
void Sequence::erase(size_t position) {this->erase(position, 1);}

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
		SequenceNode *newElem = new SequenceNode(current->item);
		if (this->tail) {
			this->tail->next = newElem;
			newElem->prev = this->tail;
		} else {
			this->head = newElem;
		}
		this->tail = newElem;
		++this->length;
		current = current->next;
	}
}

/**
 *	Destroys all items in the sequence and release the memory
 *	associated with the sequence.
 */
Sequence::~Sequence() {this->clear();}
