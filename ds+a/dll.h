#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

namespace ds
{
	template <typename T>
	struct Node {
		Node(T val, std::shared_ptr<Node<T>> prev = nullptr, std::shared_ptr<Node<T>> next = nullptr) {
			_value = val;
			_prev = prev;
			_next = next;
		}
		Node() {}
		T _value;
		std::shared_ptr<Node<T>> _next = nullptr;
		std::shared_ptr<Node<T>> _prev = nullptr;
	};

	/// <summary>
	/// Double Linked List
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template <class T>
	class DLL
	{
	public:
		DLL() {
			_head = nullptr;
			_tail = nullptr;
			_head = _tail;

		}
		~DLL() {
		
		}

		inline bool empty() {
			return (_size == 0);
		}
	
		inline void push(T val, bool back) {
			std::shared_ptr<Node<T>> n = std::make_shared<Node<T>>(val, nullptr, nullptr);
			if (_size == 0) {
				_head = n;
				_tail = n;
			} else if (back) {
				n->_prev = _tail;
				_tail->_next = n;
				_tail = n;
			} else if (!back) {
				n->_next = _head;
				_head->_prev = n;
				_head = n;
			}
			_size++;
		}

		inline void pop_front() {
			if (_size >= 1) {
				_head = _head->_next;
				_head->_prev = nullptr;
				_size--;
			}
		}
	
		inline void pop_back() {
			if (_size >= 1) {
				_tail = _tail->_prev;
				_tail->_next = nullptr;
				_size--;
			}
		}

		inline std::shared_ptr<Node<T>> find(T val) {
			if (!empty()) {
				auto temp = _head;
				while (temp != nullptr) {
					if (temp->_value == val) {
						return temp;
					}
					else {
						temp = temp->_next;
					}
				}
			}

			return nullptr;
		}

		inline std::vector<std::shared_ptr<Node<T>>> find_all(T val) {
			if (!empty()) {
			std::vector<Node<T>*> ret;
				auto temp = _head;
				while (temp != nullptr) {
					if (temp->_value == val) {
						ret.push_back(temp);
					}
					temp = temp->_next;
				}
				return ret;
			}
			return std::vector<Node<T>*>();
		}

		inline void _delete(T val) {
			if (!empty()) {
				auto n = find(val);
				if (n != nullptr) {				
					if (n == _head) {
						pop_front();
					}
					else if (n == _tail) {
						pop_back();
					}
					else {
						n->_next->_prev = n->_prev;
						n->_prev->_next = n->_next;
					}
					_size--;
				}
			}
		}

		inline void reverse() {
			if (_size >= 1) {
				auto first = _head;
				auto second = _head->_next;

				first->_next = nullptr;
				first->_prev = second;
				while (second != nullptr) {
					second->_prev = second->_next;
					second->_next = first;
					first = second;
					second = second->_prev;
				}

				_tail = _head;
				_head = first;
			}
		}

		inline void print() {
			if (_size >= 1) {
				auto current = _head;
				while (current != nullptr) {
					std::cout << current->_value << " ";
					current = current->_next;
				}
			}
		}

	private:
		int _size = 0;
		std::shared_ptr<Node<T>> _head = nullptr;
		std::shared_ptr<Node<T>> _tail = nullptr;
	};
}


