#version 410
in vec4 vColor;
in vec4 vPosition;
out vec4 FragColor;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 lightDir;
uniform vec3 cameraPos;

void main() 
{
	vec3 surfacePos = vPosition.xyz;
	
	//normalize the surface position and the light direction
	vec3 surfaceNormal = normalize(surfacePos);
	vec3 Ldn = normalize(lightDir + lightPos);
	
	//ambient light
	vec4 ambient = vColor * vec4(lightColor, 1);
	
	//diffuse light
	float lambert = max(0, dot(surfaceNormal, -Ldn));
	vec4 diffuse = vColor * lambert * vec4(lightColor, 1); 
	
	//specular light
	
	//calculate the view vector and the reflection vector
	vec3 V = normalize(cameraPos - surfaceNormal);
	vec3 H = (V + -Ldn);
	float viewDot = dot(H, surfaceNormal);
	
	float specularStrength = .5;
	float specularTerm = pow(max(0, viewDot), 2.0f);
	vec4 specular = vColor * specularTerm * vec4(lightColor, 1) * specularStrength; 
	
	FragColor = ambient + diffuse + specular;
}