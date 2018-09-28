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
	vec3 Ldn = normalize(lightDir);
	vec3 surfacePos = vPosition.xyz;
	surfacePos = normalize(surfacePos);
	float lambert = max(0, dot(surfacePos, -Ldn));
	
	vec3 reflectedRay = reflect(Ldn, surfacePos);
	vec3 viewRay = normalize(cameraPos - surfacePos);
	
	vec4 ambient = vColor * vec4(lightColor, 1);
	vec4 diffuse = vColor * vec4(lightColor, 1) * lambert;
	float specularPower = pow(max(0, dot(reflectedRay, viewRay)), 30.0f);
	vec4 specular = (vColor * vec4(lightColor, 1) * specularPower); 
	FragColor = ambient + diffuse + specular;
}