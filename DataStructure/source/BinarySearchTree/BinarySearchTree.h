#pragma once
#include "../Node/TreeDoublyNode.h"
#include "../Stack/Stack.h"
#include "../Queue/Queue.h"


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


		~BinarySearchTree() {
			if (!m_root) return;

			SGT::Stack<Node*> stack1;
			SGT::Stack<Node*> stack2;
			stack1.push(m_root);

			while (!stack1.isEmpty()) {
				Node* current = stack1.top();
				stack1.pop();

				stack2.push(current);

				if (current->leftChild) {
					stack1.push(current->leftChild);
				}

				if (current->rightChild) {
					stack1.push(current->rightChild);
				}
			}

			while (!stack2.isEmpty()) {
				delete stack2.top();
				stack2.pop();
			}
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

		void remove(const _Type& targetValue) {

			Node* currentNode = m_root;
			Node* currentNodeParent;

			while (currentNode) {
				currentNodeParent = currentNode;

				if (currentNode->data > targetValue) {
					currentNode = currentNode->leftChild;
				}
				else if (currentNode->data < targetValue) {
					currentNode = currentNode->rightChild;
				}
				else
					break;
			}

			if (!currentNode) {
				std::cout << targetValue << " doesn't exist in the tree\n";
				return;
			}

			//if the node has more than 1 child
			if (currentNode->leftChild && currentNode->rightChild) {
				Node* successor = currentNode->rightChild;
				Node* successorParent;

				while (successor->leftChild) {
					successorParent = successor;
					successor = successor->leftChild;
				}

				currentNode->data = successor->data;

				//check if the successor has right child to avoid memory leak and data lost
				if (successor->rightChild) {
					successorParent->leftChild = successor->rightChild;
				}
				delete successor;
				return;
			}

			//if the node as 1 or no child
			Node* child = currentNode->leftChild ? currentNode->leftChild : currentNode->rightChild;
			if (currentNodeParent->leftChild == currentNode) {
				currentNodeParent->leftChild = child;
			}
			else {
				currentNodeParent->rightChild = child;
			}

			delete currentNode;
				
		}


		void traverseInOrder() {
			// You can Use loop and recursion

			/* RECURSION
			if (!root) return;
			traverseInOrder(root->leftChild);
			std::cout << "[Data]: " << root->data;
			raverseInOrder(root->rightChild);
			*/

			SGT::Stack<Node*> stack;
			Node* currentNode = m_root;

			while (currentNode || !stack.isEmpty()) {
				if (currentNode) {
					while (currentNode) {
						stack.push(currentNode);
						currentNode = currentNode->leftChild;
					}
				}

				currentNode = stack.top();
				stack.pop();

				std::cout << "[InOrder]: " << currentNode->data << std::endl;

				currentNode = currentNode->rightChild;

			}


		}

		void traversePostOrder() {

			/* RECURSION
			if (!root) return;
			traversePostOrder(root->leftChild);
			traversePostOrder(root->rightChild);
			std::cout << "[Data]: " << root->data;
			*/

			SGT::Stack<Node*> stack1;
			SGT::Stack<Node*> stack2;
			stack1.push(m_root);

			while (!stack1.isEmpty()) {
				Node* current = stack1.top();
				stack1.pop();

				stack2.push(current);

				if (current->leftChild) {
					stack1.push(current->leftChild);
				}

				if (current->rightChild) {
					stack1.push(current->rightChild);
				}
			}

			while (!stack2.isEmpty()) {
				Node* node = stack2.top();
				stack2.pop();
				std::cout << "[PostOrder]: " << node->data << std::endl;
			}

		}

		void traversePreOrder() {

			/* RECURSION
		if (!root) return;
		std::cout << "[Data]: " << root->data;
		traversePreOrder(root->leftChild);
		traversePreOrder(root->rightChild);
		*/

			SGT::Stack<Node*> stack;
			stack.push(m_root);

			while (!stack.isEmpty()) {
				Node* current = stack.top();
				stack.pop();

				std::cout << "[PreOrder]: " << current->data << std::endl;

				if (current->rightChild) {
					stack.push(current->rightChild);
				}

				if (current->leftChild) {
					stack.push(current->leftChild);
				}
			}

		}

		void traverseLevelOrder() {
			SGT::Queue<Node*> queue;

			queue.push(m_root);

			while (!queue.isEmpty()) {
				Node* current = queue.front();
				queue.pop();

				if (current->leftChild) {
					queue.push(current->leftChild);
				}
				if (current->rightChild) {
					queue.push(current->rightChild);
				}

				std::cout << "[LevelOrder]: " << current->data << std::endl;
			}
		}

	};
}