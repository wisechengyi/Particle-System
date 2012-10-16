#ifndef PARTICLESYS_H
#define PARTICLESYS_H

#include <vector>
#include <fstream> 
#include <sstream>
#include <map>

#include "vertex.h"
#include "vector.h"
#include "smfobj.h"

using namespace std;


class ParticleSystem : public SmfObj
{
	public:
		ParticleSystem();
		~ParticleSystem();		
		ParticleSystem(char const * const filename);
		void updateParticles();
		void particleRead(char const * const filename);
		
		
		vector<Vector3D> v;	//velocity
		vector<Vector3D> f;	//force	
		vector<float>    m;	//mass
		
		map< pair<int,int>, float > springConnection; //maps a pair of vertex indcies to a spring rest length	
		
		
		void simulate(float DeltaT);	
					
};


#endif
