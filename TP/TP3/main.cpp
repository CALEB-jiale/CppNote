#include "Tree.h"
#include <iostream>

int main(int argc, char* argv[]) {
	Tree t1;
	t1.draw();
	t1.info();
	std::cout << "Tree size: " << t1.getHeight() << std::endl;

	std::cout << std::endl;

	Tree* t2 = new Tree(5.5);
	t2->draw();
	t2->info();
	std::cout << "Tree size: " << t2->getHeight() << std::endl;
	delete t2;

	return 0;
}