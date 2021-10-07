#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>

/*
	Binary Search Tree
*/

namespace ds 
{
	template <typename T>
	struct BSTNode {
		BSTNode(int key, T val) {
			_key = key;
			_val = val;
		}

		~BSTNode() {}

		int _key;
		T _val;
		std::shared_ptr<BSTNode<T>> _left = nullptr;
		std::shared_ptr<BSTNode<T>> _right = nullptr;
		std::shared_ptr<BSTNode<T>> _parent = nullptr;
	};

	template <class T>
	class BST {
	public:
		BST() {}
		~BST() {}

		inline void insert(int key, T val) {
			std::shared_ptr<BSTNode<T>> new_node = std::make_shared<BSTNode<T>>(key, val);
			if (_root == nullptr) {
				_root = new_node;
			}
			else {
				auto append_to = find(_root, key);

				if (append_to->_key == key) {
					std::cout << "Key already in BST!\n";
					return;
				}
				else {
					new_node->_parent = append_to;
					if (append_to->_key < key) {
						append_to->_right = new_node;
					}
					else {
						append_to->_left = new_node;
					}
				}
			}

			_size++;
		}

		inline std::shared_ptr<BSTNode<T>> find(std::shared_ptr<BSTNode<T>> node, int key) const {
			if (node->_left != nullptr && node->_right != nullptr) {
				if (key > node->_key) {
					return find(node->_right, key);
				}
				else if (key < node->_key) {
					return find(node->_left, key);
				}
				else if (key == node->_key) {
					return node;
				}
			}
			else {
				std::cout << "Node Was Null!\nReturning Good Position";
				return node;
			}

			return nullptr;
		}

		inline std::shared_ptr<BSTNode<T>> get_root() const {
			return _root;
		}

	private:
		inline int balance_factor(int key) const {
			if (_size > 0) {
				auto node = find(_root, key);
				if (node->_key != key) {

				}
				else {
					std::cout << "No node with key value!\n";
					return 0;
				}
			}
		}

		inline int get_height(int key) const {
			if (_size > 0) {
				auto node = find(_root, key);
				if (node->_key != key) {
					std::cerr << "node non existent\n";
					exit(-1);
				}
				else {
					if (node->_right != nullptr) {
						int height = 0;

						auto temp = node->right;
						while (temp != nullptr) {
							height++;
							temp = temp->right;
						}
					}
				}
			}
		}

	private:
		std::shared_ptr<BSTNode<T>> _root = nullptr;
		int _size = 0;
	};
}