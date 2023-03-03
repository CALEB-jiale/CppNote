#include "Tree.h"
#include <iostream>

Tree::Tree() {
	this->height = 10.0;
	this->evergreen = false;
	std::cout << "Construct!" << std::endl;
}

Tree::Tree(double height) {
	this->height = height;
	this->evergreen = false;
	std::cout << "Construct with defaut hgeight." << std::endl;
}

Tree::~Tree() {
	std::cout << "Destruct!" << std::endl;
}

void Tree::draw() {
	std::cout << "Drawing tree" << std::endl;
};

void Tree::info() {
	std::cout << "The tree is planted at address " << this << std::endl;
}

void Tree::setHeight(double height) {
	this->height = height;
}

void Tree::setEvergreen(bool isEvergreen) {
	this->evergreen = isEvergreen;
}