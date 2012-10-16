#include <iostream> 


#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "smfobj.h"
#include "vertex.h"
#include <fstream> 
#include <sstream>
#include <iostream>


#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif




//constructor
SmfObj::SmfObj()
{
enableRGB = false;
enableVectexNorm= false;
enableFaceNorm=false;
enableVertexNorm=false;
//do nothing
//triangles = NULL;
//quads = NULL;
//vertices = NULL;


}

//destructor


SmfObj::SmfObj(char const *  const filename)
{
	
	ObjRead(filename);
}

SmfObj::~SmfObj()
{
	cout<<"SmfObj Destructor"<<endl;
	for (unsigned i=0; i < triangles.size();i++)
	{	
		if (triangles[i]!=NULL)
		{
			delete triangles[i];
		}
	}
	triangles.clear();
		
	for (unsigned i=0; i < vertices.size();i++)
	{
		if (vertices[i]!=NULL)
		{
			delete vertices[i];
		}
	}
	vertices.clear();


	for (unsigned i=0; i < quads.size();i++)
	{	
		if (quads[i]!=NULL)
		{
			delete quads[i];
		}
	}
	triangles.clear();
}



void SmfObj::readSmf(std::ifstream * const input)
{
//	std::string line;
	
	for( std::string line; getline( *input, line ); )
	{
//		float co[3];
//		int index[3];
		int i;
		if (!line.empty())
		{
			i=0;
			char * cstr;
			char * p;
			cstr = new char [line.size()+1];
			strcpy(cstr,line.c_str());
			
			p=strtok(cstr," ");
			
			if (*p == 'v')
			{
//				cout<<"v: ";
				p=strtok(NULL," ");
				Vertex * temp = new Vertex;
				
				while (p!=NULL)
				{
//					printf("%s ",p);

					
					temp->co[i]= atof(p);			
					
//					cout<<temp->co[i]<<" ";
					p=strtok(NULL," ");	
						
//					cout<<co[i]<<" ";
					i++;	
					if (i==3)
					{
						break;
					}				
				}
				vertices.push_back(temp);
			}
			else if (*p == 'f') //it is a face
			{
				p=strtok(NULL," ");
				
				vector<unsigned> * index = new vector<unsigned>;
				
//				cout<<"f ";
				
				while (p!=NULL)
				{
//					printf("%s ",p);
					int tempIndex = atoi(p) -1 ;
					if (tempIndex < -1)
					{
						cout<<"invalid face index"<<endl;
						abort();
					}
					
					index->push_back(tempIndex);
//					cout<<tempIndex<<" ";
					p=strtok(NULL," ");			
					i++;
					if (i==3)
					{
						break;
					}
										
				}
				
				triangles.push_back(index);
			}
			else
			{
				cout<<"ignore: "<<line<<endl;
				continue;
				delete [] cstr;				
			}
			
		
		
			if (i<3) //smf and not 3 vertices
			{
				cout<<"Invalid Vertex"<<endl;
				exit(0);
			}
			
			delete [] cstr;
		}
//		cout<<endl;
	    
	}
	
	cout<<"vertices size: "<<vertices.size()<<endl;
	cout<<"face size: "<<triangles.size()<<endl;





}

//*****************************
//*********READ PLY************
//*****************************
void SmfObj::readPly(std::ifstream * const input)
{
//	std::string line;
	
	int vertexLine =0;
	int faceLine=0;
	bool endofHeader = false;

	
	for( std::string line; getline( *input, line ); )
	{
		int i;
		if (!line.empty())
		{
			i=0;
			char * cstr;
			char * p;
			cstr = new char [line.size()+1];
			strcpy(cstr,line.c_str());
			
			p=strtok(cstr," ");
			
			
			if (strcmp(p,"element") ==0 )
			{
				
				p=strtok(NULL," ");
				
				if (strcmp(p,"face") ==0 )
				{

					p=strtok(NULL," ");
					faceLine = atoi(p);
					cout<<"element face: "<<faceLine<<endl;			
				}
				else if (strcmp(p,"vertex")==0)
				{
					p=strtok(NULL," ");
					vertexLine = atoi(p);
//					cout<<"element vertex: "<<vertexLine<<endl;	
				}
				else
				{
					cout<<"**********some other element************"<<endl;
					printf("%s\n",p);
				}
				
				
				
			}
			else if (strcmp(p,"end_header") ==0 )
			{
				endofHeader=true;

				//START READING VERTICES				
				int linecount=0;
				while(linecount<vertexLine)
				{
					getline(*input,line);
					char * temp = new char[line.size()+1];
					strcpy(temp,line.c_str());
					
					char* curr =strtok(temp," ");
					
					Vertex *  ver= new Vertex;					
//					curr=strtok(NULL," ");				
					ver->co[0] = atof(curr);
					curr=strtok(NULL," ");				
					ver->co[1] = atof(curr);				
					curr=strtok(NULL," ");				
					ver->co[2] = atof(curr);
					curr=strtok(NULL," ");						
					
					
					
					
					if (curr!=NULL)
					{
						ver->norm[0] = atof(curr);
						curr=strtok(NULL," ");				
						ver->norm[1] = atof(curr);				
						curr=strtok(NULL," ");				
						ver->norm[2] = atof(curr);
						enableVectexNorm=true;
					}	
					
						
					
					curr=strtok(NULL," ");	
					if (curr!=NULL)
					{
//						cout<<"has rgb"<<endl;
						enableRGB=true;
						ver->r = atof(curr)/255;
						curr=strtok(NULL," ");
						ver->g = atof(curr)/255;
						curr=strtok(NULL," ");
						ver->b = atof(curr)/255;
						
					}						
					
					vertices.push_back(ver);
					

//					printf("%s \n",curr);
					
//					printf("%4.2f %4.2f %4.2f %4.2f %4.2f %4.2f\n", 
//						ver->co[0],ver->co[1],ver->co[2],ver2->co[0],ver2->co[1],ver2->co[2]);
					
					linecount++;
				}
				
				
//				

				linecount=0;
				while (linecount<faceLine)
				{
					getline(*input,line);
					char * temp = new char[line.size()+1];
					strcpy(temp,line.c_str());
					
					char* curr =strtok(temp," ");
						
					int num = atoi(curr);
					
					unsigned i,j,k,l;
					if (num==3)
					{
						curr=strtok(NULL," ");
						i=atoi(curr);
						curr=strtok(NULL," ");
						j=atoi(curr);
						curr=strtok(NULL," ");
						k=atoi(curr);
						
						vector<unsigned> * vec = new vector<unsigned>;
						vec->push_back(i);
						vec->push_back(j);
						vec->push_back(k);
						triangles.push_back(vec);
							
//						printf("%d %d %d\n",i,j,k);
					}
					else if (num==4)
					{
						curr=strtok(NULL," ");
						i=atoi(curr);
						curr=strtok(NULL," ");
						j=atoi(curr);
						curr=strtok(NULL," ");
						k=atoi(curr);
						curr=strtok(NULL," ");
						l=atoi(curr);	
						
						vector<unsigned> * vec = new vector<unsigned>;
						vec->push_back(i);
						vec->push_back(j);
						vec->push_back(k);
						vec->push_back(l);
						quads.push_back(vec);						
						
//						printf("%d %d %d %d\n",i,j,k,l);
					
					}
					else
					{
					
					}
				
					linecount++;
				}
				
//				exit(0);
//				vertices.push_back(temp);
			}
			else
			{
				cout<<"somewhere else"<<endl;
			}
			
			
			delete [] cstr;
		}
//		cout<<endl;
	    
	}
	
	cout<<"vertices size: "<<vertices.size()<<endl;
	cout<<"face size: "<<triangles.size()<<endl;
	cout<<"PLY READING FINISHED"<<endl<<endl;




}

int SmfObj::ObjRead(char  const * const filename)
{

	cout<<"reading "<<filename<<endl;
	
	std::ifstream * input = new std::ifstream(filename);
	
	std::string line;
	getline(*input,line);
	
	char * cstr = new char [line.size()+1];
	strcpy(cstr,line.c_str());
	
	//this is for the odd behavior for obj. there is a Carriage Return
	string obj="#OBJ\n";
	obj[4]=(char) 13;
	
//	for (int i=0;i < obj.size(); i++)
//	{
//		printf("%d ", (int)obj[i]);
//		
//	}	

	
	if ( strcmp( cstr ,"ply") == 0)
	{
		cout<<"PLY FILE"<<endl;
		readPly(input);
		
//		return 0;
//		exit(0);
	}
	else if ( strcmp( cstr ,"#$SMF 1.0") == 0)
	{
		readSmf(input);
	}
	else if(strcmp( cstr , obj.c_str()) == 0)
	{
		cout<<"obj: read it like smf"<<endl;
		readSmf(input);
	}
	else
	{
		
		cout<<"incorrect file type"<<endl;
		cout<<"file line: "<<cstr<<endl;
		exit(0);
	}
	
	delete [] cstr;


	return 0;
}


void SmfObj::draw()
{
//	cout<<"size V F T: "<<vertices.size()<<" "<<triangles.size()<<" "<<quads.size()<<endl;
	int i=0;
	
	
	while(i<1)
	{
//		if (i==0)
//		{	
//			glColor3f(0,0,0);
//			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
////			cout<<"fill"<<endl;
//		}
//		else 
//		{	

//			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//			glColor3f(0,0,0);
//			glLineWidth(2);
//		}
		i++;
		
		glBegin(GL_TRIANGLES);

		

			for (unsigned i=0; i<triangles.size();i++)
			{
				if (enableFaceNorm)
				{
					glNormal3f(triNorms[i][0],triNorms[i][1],triNorms[i][2]);
				}					
				
				if (enableRGB )
				{	
//					cout<<"rgb: "<<vertices[triangles[i]->at(0)]->r<<endl;	
					glColor3f(vertices[triangles[i]->at(0)]->r,
					vertices[triangles[i]->at(0)]->g,
					vertices[triangles[i]->at(0)]->b);
					glColor3f(0,0,0);
				}
				
				if (enableVectexNorm)
				{
					glNormal3f(	vertices[triangles[i]->at(0)]->norm[0],
							vertices[triangles[i]->at(0)]->norm[1],
							vertices[triangles[i]->at(0)]->norm[2]);
				}
				


					
				glVertex3f(vertices[triangles[i]->at(0)]->co[0],
					vertices[triangles[i]->at(0)]->co[1],
					vertices[triangles[i]->at(0)]->co[2]);	
				
				if (enableRGB )
				{
					glColor3f(vertices[triangles[i]->at(1)]->r,
					vertices[triangles[i]->at(1)]->g,
					vertices[triangles[i]->at(1)]->b);
				}					
					
				if (enableVectexNorm)
				{
					glNormal3f(	vertices[triangles[i]->at(1)]->norm[0],
							vertices[triangles[i]->at(1)]->norm[1],
							vertices[triangles[i]->at(1)]->norm[2]);
				}					
					
				glVertex3f(vertices[triangles[i]->at(1)]->co[0],
					vertices[triangles[i]->at(1)]->co[1],
					vertices[triangles[i]->at(1)]->co[2]);
				
				
				if (enableRGB )
				{
					glColor3f(	vertices[triangles[i]->at(2)]->r,
							vertices[triangles[i]->at(2)]->g,
							vertices[triangles[i]->at(2)]->b);
				}	
					
				if (enableVectexNorm)
				{
					glNormal3f(	vertices[triangles[i]->at(2)]->norm[0],
							vertices[triangles[i]->at(2)]->norm[1],
							vertices[triangles[i]->at(2)]->norm[2]);
				}
					
				glVertex3f(vertices[triangles[i]->at(2)]->co[0],
					vertices[triangles[i]->at(2)]->co[1],
					vertices[triangles[i]->at(2)]->co[2]);	
			}
		glEnd();
		
		glBegin(GL_QUADS);
			for (unsigned i=0; i<quads.size();i++)
			{
				if (enableFaceNorm)
				{
					glNormal3f(quadNorms[i][0],quadNorms[i][1],quadNorms[i][2]);
				}
				
				if (enableRGB )
				{	
//					cout<<"rgb: "<<vertices[quads[i]->at(0)]->r<<endl;	
					glColor3f(vertices[quads[i]->at(0)]->r,
					vertices[quads[i]->at(0)]->g,
					vertices[quads[i]->at(0)]->b);
					glColor3f(0,0,0);
				}	
				
				if (enableVectexNorm)
				{	
					glNormal3f(	vertices[quads[i]->at(0)]->norm[0],
							vertices[quads[i]->at(0)]->norm[1],
							vertices[quads[i]->at(0)]->norm[2]);
				}
					
				glVertex3f(vertices[quads[i]->at(0)]->co[0],
					vertices[quads[i]->at(0)]->co[1],
					vertices[quads[i]->at(0)]->co[2]);
					
					
				
				if (enableRGB )
				{
					glColor3f(vertices[quads[i]->at(1)]->r,
					vertices[quads[i]->at(1)]->g,
					vertices[quads[i]->at(1)]->b);
				}	
					
				if (enableVectexNorm)
				{	
					glNormal3f(	vertices[quads[i]->at(1)]->norm[0],
							vertices[quads[i]->at(1)]->norm[1],
							vertices[quads[i]->at(1)]->norm[2]);
				}		
				glVertex3f(vertices[quads[i]->at(1)]->co[0],
					vertices[quads[i]->at(1)]->co[1],
					vertices[quads[i]->at(1)]->co[2]);					
					
				
				if (enableRGB )
				{
					glColor3f(vertices[quads[i]->at(2)]->r,
					vertices[quads[i]->at(2)]->g,
					vertices[quads[i]->at(2)]->b);
				}	
				if (enableVectexNorm)
				{	
					glNormal3f(	vertices[quads[i]->at(2)]->norm[0],
							vertices[quads[i]->at(2)]->norm[1],
							vertices[quads[i]->at(2)]->norm[2]);
				};	
				glVertex3f(vertices[quads[i]->at(2)]->co[0],
					vertices[quads[i]->at(2)]->co[1],
					vertices[quads[i]->at(2)]->co[2]);
					
					
				
				if (enableRGB )
				{
					glColor3f(vertices[quads[i]->at(3)]->r,
					vertices[quads[i]->at(3)]->g,
					vertices[quads[i]->at(3)]->b);
				}	
				if (enableVectexNorm)
				{	
					glNormal3f(	vertices[quads[i]->at(3)]->norm[0],
							vertices[quads[i]->at(3)]->norm[1],
							vertices[quads[i]->at(3)]->norm[2]);
				}
				glVertex3f(vertices[quads[i]->at(3)]->co[0],
					vertices[quads[i]->at(3)]->co[1],
					vertices[quads[i]->at(3)]->co[2]);		
			}
		glEnd();	
	}
}

//this function calculates all the face normals if not given
void SmfObj::getFaceNormals()
{
	enableFaceNorm=true;
	unsigned triSize=triangles.size();	
	unsigned quadSize=quads.size();
	
	triNorms.resize(triSize);
	quadNorms.resize(quadSize);
	
	for (unsigned i=0;i<triSize;i++)
	{
		Vector3D x1 = {	vertices[triangles[i]->at(0)]->co[0],
				vertices[triangles[i]->at(0)]->co[1],
				vertices[triangles[i]->at(0)]->co[2]};
		Vector3D x2 = {	vertices[triangles[i]->at(1)]->co[0],
				vertices[triangles[i]->at(1)]->co[1],
				vertices[triangles[i]->at(1)]->co[2]};
		Vector3D x3 = {	vertices[triangles[i]->at(2)]->co[0],
				vertices[triangles[i]->at(2)]->co[1],
				vertices[triangles[i]->at(2)]->co[2]};
				
		Vector3D cr = cross(x2-x1,x3-x1);
		unitize(cr);
		triNorms[i]=cr;
		
//		cout<<cr<<endl;
		
	}
	
	for (unsigned i=0;i<quadSize;i++)
	{
		Vector3D x1 = {	vertices[quads[i]->at(0)]->co[0],
				vertices[quads[i]->at(0)]->co[1],
				vertices[quads[i]->at(0)]->co[2]};
		Vector3D x2 = {	vertices[quads[i]->at(1)]->co[0],
				vertices[quads[i]->at(1)]->co[1],
				vertices[quads[i]->at(1)]->co[2]};
		Vector3D x3 = {	vertices[quads[i]->at(2)]->co[0],
				vertices[quads[i]->at(2)]->co[1],
				vertices[quads[i]->at(2)]->co[2]};
				
		Vector3D cr = cross(x2-x1,x3-x1);
		unitize(cr);
		quadNorms[i]=cr;
	}
	
	
		
	
}


void SmfObj::getVertexNormals()
{
	vertexNorms.resize(vertices.size());
	tempVertexNormalCount.resize(vertices.size());

	if (!enableFaceNorm)
	{
		cout<<"face not available"<<endl;
	}
	
	for (unsigned i=0;i<tempVertexNormalCount.size();i++)
	{
		tempVertexNormalCount[i]=0;
		vertexNorms[i]={0,0,0};
	}
	
	for (unsigned i=0; i<triangles.size();i++)
	{
		unsigned vi0=(triangles[i])->at(0);
		unsigned vi1=(triangles[i])->at(1);
		unsigned vi2=(triangles[i])->at(2);
		
		Vector3D fNorm=triNorms[i];
		
		tempVertexNormalCount[vi0]++;
		tempVertexNormalCount[vi1]++;
		tempVertexNormalCount[vi2]++;
		
		vertexNorms[vi0]=vertexNorms[vi0]+fNorm;
		vertexNorms[vi1]=vertexNorms[vi1]+fNorm;
		vertexNorms[vi2]=vertexNorms[vi2]+fNorm;
		
		
	}	
	
	for (unsigned i=0; i<quadNorms.size();i++)
	{
		unsigned vi0=(triangles[i])->at(0);
		unsigned vi1=(triangles[i])->at(1);
		unsigned vi2=(triangles[i])->at(2);
		unsigned vi3=(triangles[i])->at(3);
		
		Vector3D fNorm=triNorms[i];
		
		tempVertexNormalCount[vi0]++;
		tempVertexNormalCount[vi1]++;
		tempVertexNormalCount[vi2]++;
		tempVertexNormalCount[vi3]++;
		
		vertexNorms[vi0]=vertexNorms[vi0]+fNorm;
		vertexNorms[vi1]=vertexNorms[vi1]+fNorm;
		vertexNorms[vi2]=vertexNorms[vi2]+fNorm;	
		vertexNorms[vi3]=vertexNorms[vi3]+fNorm;
	}
	
	
	
	for (unsigned i=0;i<vertexNorms.size();i++)
	{
		vertexNorms[i]=vertexNorms[i]/tempVertexNormalCount[i];
	}
	
	enableVertexNorm=true;
	tempVertexNormalCount.clear();	
}

void SmfObj::getQuadCentroid()
{
	//algorithm at
	//http://jwilson.coe.uga.edu/emt668/EMT668.Folders.F97/Patterson/EMT%20669/centroid%20of%20quad/Centroid.html
	for (unsigned i=0;i<quads.size();i++)
	{
		Point3D triCentroid[4];
		for (unsigned j=0;j<4;j++)
		{
			float x= (   vertices[quads[i]->at(j%4)]->co[0] +   
				 vertices[quads[i]->at((j+1)%4)]->co[0] +
				 vertices[quads[i]->at((j+2)%4)]->co[0])/3;
			float y= (   vertices[quads[i]->at(j%4)]->co[1] +   
				 vertices[quads[i]->at((j+1)%4)]->co[1] +
				 vertices[quads[i]->at((j+2)%4)]->co[1])/3;
			float z= (   vertices[quads[i]->at(j%4)]->co[2] +   
				 vertices[quads[i]->at((j+1)%4)]->co[2] +
				 vertices[quads[i]->at((j+2)%4)]->co[2])/3;
			triCentroid[j]= {x,y,z};
		}
		
		Point3D centroid=(triCentroid[0]+triCentroid[1]+triCentroid[2]+triCentroid[3])/4;
		quadCentroids.push_back(centroid);
	}
	


}

void SmfObj::getEdgeToFace()
{
	for (unsigned i=0;i<quads.size();i++)
	{
		int index[4]={quads[i]->at(0),quads[i]->at(1),quads[i]->at(2),quads[i]->at(3)};
		
		pair<int,int> edge[4]={ {min(index[0],index[1]),max(index[0],index[1])}, 
					{min(index[1],index[2]),max(index[1],index[2])}, 
					{min(index[2],index[3]),max(index[2],index[3])}, 
					{min(index[3],index[0]),max(index[3],index[0])}};
	
		
		for (unsigned j=0;j<4;j++)
		{
			edgeToFace[edge[j]].push_back(i);
		}
	
	}
//debug	
//	cout<<"map size: "<<edgeToFace.size()<<endl;

	//check if every edge has exactly 2 faces, otherwise fault
	for (map<pair<int,int>, vector<int> >::iterator it=edgeToFace.begin();it!=edgeToFace.end();it++)
	{
		if (it->second.size()!=2)
		{
			cerr<<"getEdgeToFace error"<<endl;
		}
	}
//end debug
}

void SmfObj::getEdgePoints()
{
	for (map< pair<int,int> , vector<int> >::iterator it=edgeToFace.begin(); it!=edgeToFace.end(); it++)
	{
//		edgeToEdgePoint
	
		Point3D twoOrigEdgePoint[2] = { {vertices[ it->first.first]->co[0], vertices[ it->first.first]->co[1], vertices[ it->first.first]->co[2]},
					     {vertices[ it->first.second]->co[0], vertices[ it->first.second]->co[1], vertices[ it->first.second]->co[2]}};
		Point3D twoFaceCentroids[2]= {quadCentroids[ it->second[0] ], quadCentroids[ it->second[1] ]};
		
		edgeToEdgePoint[it->first]= (twoOrigEdgePoint[0]+twoOrigEdgePoint[1]+twoFaceCentroids[0]+twoFaceCentroids[1])/4.0;	
	} 


}



void SmfObj::getVertexToFace()
{
	for (unsigned i=0; i< quads.size() ; i++)
	{
		vertexToFace[ quads[i]->at(0) ].push_back(i);
		vertexToFace[ quads[i]->at(1) ].push_back(i);
		vertexToFace[ quads[i]->at(2) ].push_back(i);
		vertexToFace[ quads[i]->at(3) ].push_back(i);
	}
	
	
//debug to check, for a 1x1 cube, every vertex should 3 faces	
//	for (map<int, vector<int> >::iterator it=vertexToFace.begin();it!=vertexToFace.end();it++)
//	{
//		cout<<it->second.size()<<endl;
//	} 
}


//New vertex position = (1/valence) x sum of…
	//Average of neighboring face points -- centroids
	//2 x average of neighboring edge points
	//(valence – 3) x original vertex position
void SmfObj::getNewVertex()
{
	
	
	for (unsigned i=0; i<vertices.size();i++)
	{
		Point3D originalVertex = vertices[i]->co;
		
		vector<int> * faces = &vertexToFace[i];
		
		Point3D avgFacePoint={0,0,0};
		for (unsigned j=0; j<faces->size(); j++)
		{
			avgFacePoint= ( (avgFacePoint*j) + quadCentroids[faces->at(j)])/(j+1);
		}
		
		//get all the edges connecting to the vertex
		//by hashing all the edges that all the faces have adjacent to the vertex
		Point3D sumEdgePoint={0,0,0};
		int edgePointCount=0;
		
		for (unsigned k=0; k<faces->size();k++)
		{
			for (unsigned l=0;l<4;l++)
			{
				pair<int,int> key= { min(i,quads[faces->at(k)]->at(l)), max(i,quads[faces->at(k)]->at(l))};
				if (edgeToEdgePoint.find(key)!=edgeToEdgePoint.end()) // if the key (edge) exist
				{
					sumEdgePoint=sumEdgePoint+edgeToEdgePoint[key]; //each edge get counted twice, so it's still fine
					edgePointCount++;
				}
								
			
			}
			
			
		}
		
		
		Point3D avgEdgePoint=sumEdgePoint/(double) edgePointCount;
//		cout<<"avgFacePoint "<<avgFacePoint<<" avgEdgePoint "<<avgEdgePoint<<endl;
		valence_n=faces->size();
		
		Point3D newVertex= (1.0/valence_n)*( avgFacePoint + 2.0*avgEdgePoint + (valence_n-3.0)*originalVertex);
//		cout<<"newVertex "<<newVertex<<endl;
		
		Vertex * newVertexPtr= new Vertex;
		newVertexPtr->co=newVertex;
		
		int indexToNewVertex=newVerticesBuffer.size(); //new vertex index in newVerticesBuffer
		newVerticesBuffer.push_back(newVertexPtr);
		
		
		
		
		//get edge point index to the newVerticesBuffer
		//edge 0 1 to face 0
		//     2 3 to face 1
		for (unsigned k=0; k<faces->size();k++)
		{
			int tempEdgeCount=0;
			pair<int,int> tempEdge[2];
			for (unsigned l=0;l<4;l++)
			{
				
				
				pair<int,int> key= { min(i,quads[faces->at(k)]->at(l)), max(i,quads[faces->at(k)]->at(l))};
				if (edgeToEdgePoint.find(key)!=edgeToEdgePoint.end()) // if the key (edge) exist
				{
					tempEdge[tempEdgeCount]=key;
					tempEdgeCount++;
				}
						
			
			}
			
			
			if(tempEdgeCount==2)
			{
				//map<int, int> centroidToVertexBuffer; //map a centroid index to an index in newVerticesBuffer
 				
 				
 				int edgeVertexIndex[2]={-1,-1};
 				
 				map<pair<int,int>, int >::iterator itEdge = edgeToVertexBuffer.find(tempEdge[0]);
 				
 				if (itEdge!=edgeToVertexBuffer.end())
 				{
 					edgeVertexIndex[0]=itEdge->second;	
 				}
 				else
 				{
 					edgeVertexIndex[0]=newVerticesBuffer.size();
 					
 					Vertex * tempVertex=new Vertex;
 					tempVertex->co=edgeToEdgePoint[tempEdge[0]];
 					newVerticesBuffer.push_back(tempVertex);
 					
 					edgeToVertexBuffer[tempEdge[0]]=edgeVertexIndex[0];
 				}
				
				
				int centroidIndex=-1;
				map<int,int>::iterator itCentroid=centroidToVertexBuffer.find(faces->at(k));
				if (itCentroid!=centroidToVertexBuffer.end())
				{
					centroidIndex=itCentroid->second;
				}
				else
				{
					centroidIndex=newVerticesBuffer.size();
 					
 					Vertex * tempVertex=new Vertex;
 					tempVertex->co=quadCentroids[faces->at(k)];
 					newVerticesBuffer.push_back(tempVertex);
 					
 					centroidToVertexBuffer[faces->at(k)]=centroidIndex;
				}
				
 				
 				itEdge = edgeToVertexBuffer.find(tempEdge[1]);
 				
 				if (itEdge!=edgeToVertexBuffer.end())
 				{
 					edgeVertexIndex[1]=itEdge->second;	
 				}
 				else
 				{
 					edgeVertexIndex[1]=newVerticesBuffer.size();
 					
 					Vertex * tempVertex=new Vertex;
 					tempVertex->co=edgeToEdgePoint[tempEdge[1]];
 					newVerticesBuffer.push_back(tempVertex);
 					
 					edgeToVertexBuffer[tempEdge[1]]=edgeVertexIndex[1];
 				}
				
				vector<unsigned> * newQuad=new vector<unsigned>;
				
				
				newQuad->push_back(indexToNewVertex);
				newQuad->push_back(edgeVertexIndex[0]);
				newQuad->push_back(centroidIndex);
				newQuad->push_back(edgeVertexIndex[1]);
				
				newQuadsBuffer.push_back(newQuad);
//				
//				newQuadsBuffer.push_back(newQuad);
				
					
			}
			else if (tempEdgeCount==0)
			{
			
			}
			else
			{
				cout<<"temp edge count error"<<endl;
			}
		}
		
		
	}
	

	

}


void SmfObj::divide()
{
	getQuadCentroid();
	
	printQuadCentroids();
	getEdgeToFace();
	getEdgePoints();
	
	
	getVertexToFace();
	getNewVertex();
	
	
	for (unsigned i=0;i<quads.size();i++)
	{
		delete quads[i];
	}
	quads.clear();
	
	for (unsigned i=0;i<vertices.size();i++)
	{
		delete vertices[i];
	}
	vertices.clear();
	
	
	vertices=newVerticesBuffer;
	quads=newQuadsBuffer;
	
	
	

	newVerticesBuffer.clear();
	newQuadsBuffer.clear();
	
	
	quadCentroids.clear();//stores normal for every quad
	
	edgeToFace.clear(); 
	
	edgeToEdgePoint.clear();	
	
	
	vertexToFace.clear();
	centroidToVertexBuffer.clear(); //map a centroid index to an index in newVerticesBuffer
	edgeToVertexBuffer.clear(); //map an edge index to an index in newVerticesBuffer

}
void SmfObj::printQuads()
{
	ofstream *writer=new ofstream("quadsDivision.ply");
	*writer<<"ply"<<endl;
	*writer<<"format ascii 1.0"<<endl;
	*writer<<"comment Created by Blender 2.61 (sub 0) - www.blender.org, source file: 'oymodel.blend'"<<endl;
	*writer<<"element vertex "<<vertices.size()<<endl;
	*writer<<"property float x"<<endl;
	*writer<<"property float y"<<endl;
	*writer<<"property float z"<<endl;
	*writer<<"property float nx"<<endl;
	*writer<<"property float ny"<<endl;
	*writer<<"property float nz"<<endl;
	*writer<<"element face "<<quads.size()<<endl;
	*writer<<"property list uchar uint vertex_indices"<<endl;
	*writer<<"end_header"<<endl;
	
	for (unsigned i=0;i<vertices.size();i++)
	{
		*writer<<vertices[i]->co;//position
		*writer<<" 1.0 0.0 0.0"<<endl;//normal
	}
	
	for (unsigned i=0;i<quads.size();i++)
	{
		*writer<<"4 "<< quads[i]->at(0)<<" "<<quads[i]->at(1)<<" "<<quads[i]->at(2)<<" "<<quads[i]->at(3)<<endl;
	}
		
	delete writer;

}



void SmfObj::printQuadCentroids()
{
	ofstream *writer=new ofstream("quadCentroids.ply");
	*writer<<"ply"<<endl;
	*writer<<"format ascii 1.0"<<endl;
	*writer<<"comment Created by Blender 2.61 (sub 0) - www.blender.org, source file: 'oymodel.blend'"<<endl;
	*writer<<"element vertex "<<quadCentroids.size()<<endl;
	*writer<<"property float x"<<endl;
	*writer<<"property float y"<<endl;
	*writer<<"property float z"<<endl;
	*writer<<"property float nx"<<endl;
	*writer<<"property float ny"<<endl;
	*writer<<"property float nz"<<endl;
	*writer<<"element face 0"<<endl;
	*writer<<"property list uchar uint vertex_indices"<<endl;
	*writer<<"end_header"<<endl;
	
	for (unsigned i=0;i<quadCentroids.size();i++)
	{
		*writer<<quadCentroids[i][0]<<" "<<quadCentroids[i][1]<<" "<<quadCentroids[i][2];//position
		*writer<<" 1.0 0.0 0.0"<<endl;//normal
	}
	
	
	delete writer;
}


