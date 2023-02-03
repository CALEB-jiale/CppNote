#include "Tree.h"

int main(int argc, char* argv[]) {
	Tree t1;
	t1.draw();
	t1.info();

	Tree* t2 = new Tree();
	t2->draw();
	t2->info();
	delete t2;

	return 0;
}