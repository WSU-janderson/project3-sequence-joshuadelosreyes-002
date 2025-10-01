#include <string>

class SequenceNode {
	public:

		/**
		 *	Pointer to the next Node.
		 *	If node is the tail, `next` is `nullptr`.
		 */
		SequenceNode *next;

		/**
		 *	Pointer to the previous Node.
		 *	If node is the head, `prev` is `nullptr`.
		 */
		SequenceNode *prev;

		/**
		 *	The element being stored in the node.
		 */
		std::string item;

		/**
		 *	Default constructor; ensure `next` and `prev` are `nullptr`.
		 */
		SequenceNode() : next(nullptr), prev(nullptr) {}

		/**
		 *	Parameterized constructor, `next` and `prev` are set to `nullptr` and the
		 *	node's element is set to the given value.
		 *	@param item An element to be stored in the node.
		 */
		SequenceNode(std::string item) : next(nullptr), prev(nullptr), item(item) {}
};
