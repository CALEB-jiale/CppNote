#include "oak.h"
#include "utils.h"
#include <iostream>
#include <cstring>

Oak::Oak(){
	std::cout << "Planting an Oak - at address : " << this <<std::endl;
	width = 8;
	height = 4;
	image = new Pixel[width*height];
	unsigned int texture[]={0,28,14,8};
	Pixel color = Pixel(alea(130,255),alea(50,78),0);
	buildImage(image,width,height,texture, color);
}

Oak::Oak(const Oak& e){
	std::cout << "Copy constructor of class Oak - at address : " << this <<std::endl;
	width = e.width;
	height = e.height;
	image = new Pixel[width*height];
	std::memcpy( image, e.image, width*height*sizeof(Pixel));

}

Oak& Oak::operator=(const Oak& e){
	std::cout << "Affectation operator of class Oak - at address : " << this<<std::endl;
	// protect against auto assignation 
	if (this == &e)
        return *this;
    /* If the images are not the same size (which should not happen in this example)
		- deallocate the image from the object
		- copy the new width and height of the image
		- reallocation of an image object (array of pixels) to the right size
    */
    if (width != e.width || height!=e.height){
    	delete image;
    	image = nullptr;
    	width = e.width;
    	height = e.height;
    	image = new Pixel[width*height];
    }
    std::memcpy( image, e.image, width*height*sizeof(Pixel));
    return *this;
}

Oak::~Oak(){
	std::cout << "Cutting down an Oak - at address : " << this <<std::endl;
	delete[] image;
}

void Oak::draw(){
	for (int i=0;i<width*height;i++){
        std::cout << image[i] ;
        if (i%width==0) {
			std::cout << std::endl;
		}
    }
    std::cout << "[0m"<< std::endl;
}

void Oak::info(){
	std::cout << "Oak address : " << this  << std::endl;
	std::cout << "Oak's image address : " << image << std::endl;
}