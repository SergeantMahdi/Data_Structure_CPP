#pragma once
#pragma once

namespace SGT {

	template <typename _Type>
	struct DoublyNode {
	
		_Type data;
		DoublyNode<_Type>* nextNode;
		DoublyNode<_Type>* previousNode;

	
		DoublyNode()
			:data(), nextNode(nullptr), previousNode(nullptr) {
		}
		DoublyNode(const _Type& data)
			:data(data), nextNode(nullptr), previousNode(nullptr) {
		}
	};

}