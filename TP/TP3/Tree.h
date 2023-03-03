#ifndef Tree_h
#define Tree_h

class Tree {
public:
	Tree();
	Tree(double height);
	
	~Tree();

	void draw();
	void info();
	void setHeight(double height);
	void setEvergreen(bool isEvergreen);
	double getHeight() const {return height;};
	bool isEvergreen() const {return evergreen;};

private:
	double height;
	bool evergreen;
};

#endif