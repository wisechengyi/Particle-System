#ifndef VERTEX_H
#define VERTEX_H

#include "vector.h"

class Vertex
{
	public:
	Vertex();
	Vertex(float xx, float yy, float zz);
	
	const Vertex & operator=(Vertex const & other);
	const Vertex & operator+(Vertex const & other) const;
	const Vertex & operator*(float const t) const;
	
	Point3D co; //coordinate x,y,z	
	float r,g,b;
	float norm[3];
	
	
	private:


};




#endif
