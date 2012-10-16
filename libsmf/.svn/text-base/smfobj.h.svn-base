#ifndef SmfObj_H
#define SmfObj_H

#include <vector>
#include <fstream> 
#include <sstream>
#include <map>

#include "vertex.h"
#include "vector.h"
using namespace std;

class SmfObj
{
	public:
	SmfObj();
	~SmfObj();
	SmfObj(char const * const filename);		//read file to construct
	int ObjRead(char  const * const filename);	//read a file
	
	
	vector< Vertex * > vertices; 			//vertices information, each index consists of x,y,z cordinates
	vector< vector<unsigned> * > triangles; //stores the triangle faces information, each face consists of exactly 3 vertex indices
	vector< vector<unsigned> * > quads;	//stores the quad faces information, each face consists of exactly 4 vertex indices
	
	
	
	
	vector< Vector3D > triNorms;	//stores normal for every triangle
	vector< Vector3D > quadNorms;	//stores normal for every quad
	
	void printQuads();
	
	void divide();


	
	
	vector< Vector3D> vertexNorms;	//stores normal for every vertex
	
	bool enableRGB;
	bool enableVectexNorm;
	bool enableFaceNorm;
	bool enableVertexNorm;
	
	void draw();
	
	void getFaceNormals();
	void getVertexNormals();
	
	//****debug
	void printQuadCentroids();
	

	
	
	private:
	
//**************Catmull Clark Subdivision	
	
	vector< Point3D  > quadCentroids;//stores centroid for every quad
	void getQuadCentroid();
	
	// map every edge (represented 2 vertex indices, in small to large order) to 2 quad indices, so the vector size MUST be 2
	map< pair<int,int> , vector<int> > edgeToFace; 
	void getEdgeToFace();
	
	//map every edge (represented 2 vertex indices, in small to large order) to a edge point calcuated by averaging 
	//the two vertices of the edge and the centroids of the faces the edge belongs to. 
	//page 3 http://www.cs.ucr.edu/~vbz/resources/Catmull-Clark.pdf
	map< pair<int,int> , Point3D > edgeToEdgePoint;	
	void getEdgePoints();
	
	
	//map every vertex to all the faces it connects to
	//IMPORTANT: only quad vertices are collected
	map<int, vector<int> > vertexToFace;
	void getVertexToFace();
	
	
	//New vertex position = (1/valence) x sum of…
		//Average of neighboring face points
		//2 x average of neighboring edge points
		//(valence – 3) x original vertex position
	float valence_n;	
	vector< Vertex * > newVerticesBuffer; 
	vector< vector<unsigned> * > newQuadsBuffer;	
	map<int, int> centroidToVertexBuffer; //map a centroid index to an index in newVerticesBuffer
	map< pair<int, int>, int> edgeToVertexBuffer; //map an edge index to an index in newVerticesBuffer
	
	void getNewVertex();
	
	
//***************END Catmull Clark Subdivision	
	
	
	
	vector<int>  tempVertexNormalCount;
	void readSmf(std::ifstream  *  const input);
	void readPly(std::ifstream  * const input);
};








#endif
