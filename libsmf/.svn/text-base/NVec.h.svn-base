#include <iostream>
#include <vector>
#include <algorithm>
#include <stdarg.h>
#include <fstream>
#include <math.h>

#ifndef NVEC_H
#define NVEC_H

using namespace std;

template <int DIM, typename T>
class NVec : public vector<T>
{
public:
  NVec():vector<T>(DIM){};

  NVec(T * v):vector<double>(DIM)
  {
    for(int i =0;i<DIM;i++) 
      this->push_back(v[i]);
  }

  NVec(T t1,...): vector<T>(DIM)
  {   
    va_list marker; 
    this->push_back(t1); 
    va_start( marker, t1);    
    for(int i =1;i<DIM;i++)
      this->push_back((T) va_arg( marker, T));
    va_end( marker );              
  }

  /*****************************************/
  // Some more constructors
  NVec(T t1, T t2, T t3, T t4):vector<T>(DIM)
  {   
    (*this)[0] = t1;(*this)[1] = t2;
    (*this)[2] = t3;(*this)[3] = t4;
  }
  NVec(T t1, T t2, T t3):vector<T>(DIM)
  {   
    (*this)[0] = t1;(*this)[1] = t2;(*this)[2] = t3;
  }
  NVec(T t1, T t2):vector<T>(DIM)
  {   
    (*this)[0] = t1;(*this)[1] = t2;
  }
  NVec(T t1, T t2, T t3, T t4, T t5, T t6):vector<T>(DIM)
  {   
    (*this)[0] = t1;(*this)[1] = t2;
    (*this)[2] = t3;(*this)[3] = t4;
    (*this)[4] = t5;(*this)[5] = t6;
  }
  /******************************************/

  virtual ~NVec(){};

  NVec<DIM,T>& operator()(T t1,...)
  { 
    va_list marker; 
    this->push_back(t1); 
    va_start( marker, t1);    
    for(int i =1;i<DIM;i++)
      this->push_back((T) va_arg( marker, T));
    va_end( marker );             
  }

/*

inline NVec<DIM,T> & operator=(const NVec<DIM,T> & other) {
	this->clear();
  for(int i =0;i<DIM;i++) {
      this->push_back(other[i]);
		}	
		return *this; 
}
  */
};

template<int DIM, typename T>
inline ostream &operator<<(ostream &out, const NVec<DIM,T>& v)
{ 
  for(int i =0;i<DIM-1;i++) out << v[i] << " ";
  out << v[DIM-1];
  return out;
}

template<int DIM, typename T>
inline std::istream &operator>>(std::istream &in, NVec<DIM,T>& v)
{ 
  for(int i =0;i<DIM;i++) in >> v[i];
  return in;
}

template<int DIM, typename T>
inline bool operator==(const NVec<DIM,T>& v1, const NVec<DIM,T>& v2)
{ 
  for(int i =0;i<DIM;i++)
    if (v1[i] != v2[i]) return false; 
  return true;
}



/****************************************************************/
// Arithmetic operators

template<int DIM, typename T>
inline NVec<DIM,T> operator+(const NVec<DIM,T> &u, const NVec<DIM,T>& v)
{  
  NVec<DIM,T> n;
  for(int i=0;i<DIM;i++)
    n[i]=u[i]+v[i];
  return n;
}

template<int DIM, typename T>
inline NVec<DIM,T> operator-(const NVec<DIM,T> &u, const NVec<DIM,T>& v)
 {  
  NVec<DIM,T> n;
  for(int i=0;i<DIM;i++)
    n[i]=u[i]-v[i];
  return n;
}   

template<int DIM, typename T> inline NVec<DIM,T> operator-(const NVec<DIM,T> &v)
{ 
  NVec<DIM,T> n;
  for(int i=0;i<DIM;i++)
    n[i]=-v[i];
  return n;
}

template<int DIM, class T, class N> 
inline NVec<DIM,T> operator*(N s, const NVec<DIM,T> &v)
{ 
  NVec<DIM,T> n;
  for(int i=0;i<DIM;i++)
    n[i]=s*v[i];
  return n;
}

template<int DIM, class T, class N>
inline NVec<DIM,T> operator*(const NVec<DIM,T> &v, N s)
	{ return s*v; }

template<int DIM, class T, class N> 
inline NVec<DIM,T> operator/(const NVec<DIM,T> &v, N s)
{ 
  NVec<DIM,T> n;
  for(int i=0;i<DIM;i++)
    n[i]=v[i]/(T)s;
  return n;
}

template<int DIM, typename T>   // Dot Product
inline T operator*(const NVec<DIM,T> &u, const NVec<DIM,T>& v)
{ 
  T n = 0;
  for(int i=0;i<DIM;i++)
    n = n + (u[i]*v[i]);
  return n;
}

// Implement n-dimensional "cross product" JUST 3D ACTUALLY
// template<int DIM, typename T> inline NVec<DIM,T> cross(const NVec<DIM,T>& u, const NVec<DIM,T>& v)
// {
//}
//     return NVec<DIM,T>( (u[1]*v[2]) - (u[2]*v[1]),
// 			  (u[2]*v[0] - u[0]*v[2]) ,
// 		 	  (u[0]*v[1] - u[1]*v[0] ) );
// }

template<typename T> inline NVec<3,T> cross(const NVec<3,T>& u, const NVec<3,T>& v)
{
 	
    return NVec<3,T>( u[1]*v[2] - v[1]*u[2],
		-u[0]*v[2] + v[0]*u[2],
		 u[0]*v[1] - v[0]*u[1] );
}

template<int DIM, typename T> inline T norm2(const NVec<DIM,T>& v)  { return v*v; }

template<int DIM, typename T> inline T norm(const NVec<DIM,T>& v)   { return sqrt(norm2(v)); }

template<int DIM, typename T> inline void unitize(NVec<DIM,T>& v)
{
    T l = norm2(v);
    if( l!=1.0 && l!=0.0 )  v = v/sqrt(l);
}

template<int DIM, typename T> inline T euclid_distance(const NVec<DIM,T>& u, const NVec<DIM,T>& v)  
{ return norm(v-u); }

template<int DIM, typename T> 
inline T angle(const NVec<DIM,T> &u, const NVec<DIM,T>& v)
{ 
  return acos((u*v)/(norm(u) * norm(v)));
}

/* unitized angle in radians */
template<int DIM, typename T> 
inline T angle_unitized(const NVec<DIM,T> &u, const NVec<DIM,T>& v)
{ 
  return acos(u*v);
}

/* unitized angle in degrees */
template<int DIM, typename T> 
inline T d_angle_unitized(const NVec<DIM,T> &u, const NVec<DIM,T>& v)
{ 
  return acos(u*v) * 180 / M_PI;
}

#endif
