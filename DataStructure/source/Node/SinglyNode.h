#pragma once
 
namespace SGT {

	template <typename _Type>
	class SinglyNode {
		_Type m_data;
		SinglyNode* m_nextNode;

	public:
		SinglyNode()
			:m_data(nullptr),m_nextNode(nullptr){}
		SinglyNode(const _Type& data)
			:m_data(data), m_nextNode(nullptr) {
		}
	};

}