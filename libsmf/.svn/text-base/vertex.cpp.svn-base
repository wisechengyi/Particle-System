#include "vertex.h"
#include <iostream> 
using namespace std;


Vertex::Vertex()
{
//	x=0;
//	y=0;
//	z=0;
co[0]=0;
co[1]=0;
co[2]=0;
	r=-1;
	g=-1;
	b=-1;
}


Vertex::Vertex(float xx, float yy, float zz)
{
//	cout<<"not implemented yet"<<endl;
co[0]=xx;
co[1]=yy;
co[2]=zz;
}


const Vertex & Vertex::operator=(Vertex const & other) 
{
	if (this==&other)
	{
		return *this;
	}
	
	this->co[0]=other.co[0];
	this->co[1]=other.co[1];
	this->co[2]=other.co[2];

	return *this;
}

const Vertex & Vertex::operator+(Vertex const & other)  const
{	
	Vertex * v = new Vertex;
	
	v->co[0]=this->co[0]+other.co[0];
	v->co[1]=this->co[1]+other.co[1];
	v->co[2]=this->co[2]+other.co[2];

	return *v;
}


const Vertex & Vertex::operator*(float const t) const 
{

	Vertex * v = new Vertex;
	
	v->co[0]=this->co[0]*t;
	v->co[1]=this->co[1]*t;
	v->co[2]=this->co[2]*t;
	
	return *v;
}


