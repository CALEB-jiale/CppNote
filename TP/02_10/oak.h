#ifndef OAK
#define OAK

#include "tree.h"
#include "pixel.h"

class Oak : public Tree {
private:
	int width;
	int height;
	Pixel *image;	
public:
	//Default constructor and destructor
	Oak();
	~Oak();

	//Copy constructor
	Oak(const Oak& s);

	//Affectation operator
	Oak& operator=(const Oak& s);
	
	//Oak methods
	void draw() override final;
	void info() override final;
};

#endif