//uniform GLubyte * imageData;
void main()
{
  vec3 x, n, l;
  float ndotl;

  x = vec3(gl_ModelViewMatrix * gl_Vertex);
  n = normalize(gl_NormalMatrix * gl_Normal);
  l = normalize(vec3(gl_LightSource[0].position) - x);
  ndotl = max(dot(n,l),0.0);
   gl_FrontColor = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse * ndotl;
 //gl_FrontColor = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse * ndotl+(10,10,10)*imageData[x.x*256+x.y];
  //gl_FrontColor = (10,10,10)*gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse * ndotl;
  
/*  vec4 texel = texture2D(Texture0, TexCoord0);*/
/*    texel *= texture2D(Texture0, 1);*/
/*gl_FragColor = texel;*/

  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
