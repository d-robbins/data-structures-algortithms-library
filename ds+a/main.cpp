#include "data_structures.h"

#include <string>

void DLLTest() {
	ds::DLL<std::string> dll;	

	dll.push("David", true);
	dll.push("Sam", true);
	dll.push("Bob", true);
	dll.push("John", true);
	dll.push("Jeff", true);

	dll.print();

	dll.reverse();

	std::cout << "\n";

	dll.print();
}

void DSTTest() {
	ds::BST<int> tree;

	tree.insert(2, 10);

	tree.insert(3, 321);

	auto n = tree.find(tree.get_root(), 3);

	n->_key = 500;

	tree.insert(1, 321);

	tree.insert(4, 321);



	int x = 0;
}

void MatrixTest() {
	ds::Matrix<double, 2, 2> mat(1.0);
	ds::Matrix<double, 2, 3> mat2(1.0);

	mat(1, 0) = 2.0;
	mat(1, 1) = 3.0;

	mat2(0, 1) = 2.0;
	mat2(0, 2) = 3.0;

	mat2(1, 0) = 4.0;
	mat2(1, 1) = 5.0;
	mat2(1, 2) = 6.0;

	mat.display();
	mat2.display();

	auto mat3 = mat * mat2;

	mat3.display();

	std::cout << "\n";
}

int main() {
	//DLLTest();
	//DSTTest();
	
	MatrixTest();


	return 0;
}