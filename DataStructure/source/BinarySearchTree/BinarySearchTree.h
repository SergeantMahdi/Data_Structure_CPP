#pragma once
#include "../Node/TreeDoublyNode.h"
#include "../Stack/Stack.h"

namespace SGT {

	template<typename _Type>
	class BinarySearchTree {
	private:

		using Node = SGT::Node<_Type>;

	private:

		Node* m_root;
		size_t m_size;

	public:

		BinarySearchTree()
			:m_root(nullptr), m_size(0) {}

		BinarySearchTree(const _Type& data)
			:m_root(nullptr), m_size(0) {
			push(data);
		}

		~BinarySearchTree() {

		}

		void push(const _Type& data) {

			Node* newNode = new Node(data);
			Node* tail = m_root;
			Node* parent;

			if (!m_root) {
				m_root = newNode;
				m_size++;
				return;
			}


			while (tail) {

				parent = tail;

				if (tail->data == data) {
					std::cerr << "Cannot push duplicate data\n";
					return;
				}
				else if (tail->data > data) {
					tail = tail->leftChild;
				}
				else if (tail->data < data) {
					tail = tail->rightChild;
				}
			}

			if (data < parent->data) {
				parent->leftChild = newNode;
			}
			else {
				parent->rightChild = newNode;
			}
			m_size++;
		}

		void traverseInOrder() {
			// You can Use loop and recursion

			/* RECURSION
			traverseInOrder(root->leftChild);
			std::cout << "[Data]: " << root->data;
			raverseInOrder(root->rightChild);
			*/

			SGT::Stack<Node*> stack;
			Node* currentNode = m_root;

			while (currentNode || !stack.isEmpty()) {
				while (currentNode) {
					stack.push(currentNode);
					currentNode = currentNode->leftChild;
				}

				currentNode = stack.top();
				stack.pop();

				std::cout << "[Data]: " << currentNode->data << std::endl;

				currentNode = currentNode->rightChild;

			}

		}


	};
}