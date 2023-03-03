#include <iostream>
#include "utils.h"
#include "pine.h"
#include "oak.h"


int main(int argc, char** argv) {
	std::cout << "Launching the main program" << std::endl;

	// int a = 10;
	// int b = 100;

	// Pine a;
	// Pine b;
	// Oak b;

	// std::cout << "a size " << a.size() << " b size " << b.size() << std::endl;
	// std::cout << "Is a smaller than b ? " << smallerThan<Tree>(a, b) << std::endl;

	Pine p1;
	Pine p2;

	p1.info();
	p2.info();

	std::vector<Pine> forest;
	std::cout << "Created a forest" << std::endl;

	forest.push_back(p1);
	std::cout << "Pushed a tree" << std::endl;
	forest.push_back(p2);
	std::cout << "Pushed a tree" << std::endl;

	for(std::vector<Pine>::iterator it = forest.begin(); it != forest.end(); it++) {
		it -> info();
	}


	std::cout << "End of main program - destroying heap objects" << std::endl;
	std::cout << "End of main program - destroying stack objects" << std::endl;
	return 0;
}