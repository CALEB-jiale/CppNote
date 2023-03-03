#ifndef SAPIN
#define SAPIN

#include "tree.h"
#include "pixel.h"

class Pine : public Tree {
private:
	int width;
	int height;
	Pixel *image;
public:
	//Default constructor and destructor
	Pine();
	Pine(const Pine& s);
	~Pine();
	
	//Pine methods
	void draw() override final;
	void info() override final;
	Pine& operator=(const Pine& s);
};

#endif