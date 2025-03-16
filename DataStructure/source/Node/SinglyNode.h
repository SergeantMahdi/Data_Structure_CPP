#pragma once
 
namespace SGT {

	template <typename _Type>
	struct SinglyNode {
		_Type data;
		SinglyNode<_Type>* nextNode;

		SinglyNode()
			:data(),nextNode(nullptr){}
		SinglyNode(const _Type& data)
			:data(data), nextNode(nullptr) {
		}
	};

}