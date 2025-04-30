#pragma once

/*
* This Node is the same as doubly node but for better understanding of tree I use leftChild and rightChild
* instead of previousNode and nextNode
*/

namespace SGT {

	template<typename _Type>
	struct Node {
		_Type data;
		Node<_Type>* leftChild;
		Node<_Type>* rightChild;

		Node()
		  :leftChild(nullptr), rightChild(nullptr) {}

		Node(const _Type& newData)
			:data(newData),leftChild(nullptr), rightChild(nullptr) {
		}
		~Node(){}
	};
}