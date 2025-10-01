#include <exception>
#include "Sequence.h"

/**
 *	Returns the first element in the sequence.
 *	@throw `std::exception` - If the sequence is empty.
 */
std::string Sequence::front() const {
	if (this->empty()) {throw std::exception();}
	return this->head->item;
}

/**
 *	Returns the last element in the sequence.
 *	@throw `std::exception` - If the sequence is empty.
 */
std::string Sequence::back() const {
	if (this->empty()) {throw std::exception();}
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


