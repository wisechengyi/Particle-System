//uniform samplerCube TexEnv;
//uniform sampler2D TexPot;

//const float reflect_factor = .5;

//void main (void)
//{
//	vec4 output_color;
//	
//	// Perform a simple 2D texture look up.
//	vec3 base_color = texture2D(TexPot, gl_TexCoord[0].xy).rgb;
//	
//	// Perform a cube map look up.
//	vec3 cube_color = textureCube(TexEnv, gl_TexCoord[1].xyz).rgb;
////	vec3 cube_color = textureCube(TexEnv, vec3(1,1,1)).rgb;

//	// Write the final pixel.
//	gl_FragColor = vec4( mix(base_color, cube_color, reflect_factor), 1.0);
//}



uniform sampler2D TexPot;
uniform sampler2D TexEnv;
uniform float envswitch;

void main (void)
{
	vec4 color = texture2D( TexPot, gl_TexCoord[0].st);
//	color -=  texture2D(TexPot, gl_TexCoord[0].st-vec2(.005,0))/4 +  texture2D( TexPot, gl_TexCoord[0].st-vec2(0,.005))/4;
	vec4 env = texture2D( TexEnv, gl_TexCoord[1].st);

	gl_FragColor = (color*.5 )+ ((env*.2)*envswitch) + (.8*gl_Color);
//	gl_FragColor = (color*.4) + .6*gl_Color;
//	gl_FragColor = (color);
//	gl_FragColor =  gl_Color;
}
