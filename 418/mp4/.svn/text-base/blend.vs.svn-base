uniform float lightswitch;
uniform float bumpswitch;


uniform sampler2D TexPot;
uniform sampler2D TexEnv;


//float length( vec3 m )
//{
//		
//	return sqrt(lightDir.x*lightDir.x + lightDir.y*lightDir.y + lightDir.z*lightDir.z);
//}	


void main()
{	
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	
	gl_TexCoord[0] = gl_MultiTexCoord0;
	
	vec3 u = normalize( vec3(gl_ModelViewMatrix * gl_Vertex) );
	vec3 n = normalize( gl_NormalMatrix * gl_Normal );
	vec3 r = reflect( u, n );
//	
	//mapping normal onto environment map	
	float m = 1.5 * sqrt( r.x*r.x + r.y*r.y + (r.z+1.0)*(r.z+1.0) );
	gl_TexCoord[1].s = r.x/m + 0.5;
	gl_TexCoord[1].t = r.y/m + 0.5;
	
	vec3 x, norm, l;
  	float ndotl;

  	x = vec3(gl_ModelViewMatrix * gl_Vertex);
  	norm = normalize(gl_NormalMatrix * gl_Normal);
 	l = normalize(vec3(gl_LightSource[0].position) - x);
  	ndotl = max(dot(norm,l),0.0);
  	
  	
  	
  	//bump mapping
  	float width = 256.0;
  	vec4 dbdu4 = texture2D( TexPot, gl_TexCoord[0].st) 
  		  - texture2D( TexPot, vec2(gl_TexCoord[0].s+1.0/width, gl_TexCoord[0].t));
  	vec4 dbdv4 = texture2D( TexPot, gl_TexCoord[0].st) 
  		  - texture2D( TexPot, vec2(gl_TexCoord[0].s, gl_TexCoord[0].t+1.0/width));
  	float dbdu = length(vec3(dbdu4));	  
  	float dbdv = length(vec3(dbdv4));	 	  
  		  
  	vec3 arbi=vec3(1,0,0);	  
	vec3 dsdu=cross(norm, arbi);
	vec3 dsdv=cross(norm, dsdu);
	   		  
	vec3 newNorm= norm - 2.5*cross(dbdu*n,dsdv) - 2.5*cross(dbdv*n,dsdu);
	
	float bumpndotl;
  	bumpndotl = max(dot(newNorm,l),0.0);		  
	   		  
//        vec3 newNorm = vec3(norm) - cross( vec3(norm) 
  	
  	
//   	gl_FrontColor = vec3(1,1,1);
   	gl_FrontColor =  gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse * (ndotl*(1.0-bumpswitch) + bumpndotl * bumpswitch);
	gl_FrontColor *= lightswitch;
	
}
