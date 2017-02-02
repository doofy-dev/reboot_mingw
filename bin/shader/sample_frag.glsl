#version 330 core
in vec4 col;
in vec3 normal;

in vec3 toCameraVector;
in vec3 toLightVector;

out vec4 color;
void main() {

vec3 unitNormal = normalize(normal);
	vec3 unitVectorToCamera = normalize(toCameraVector);

	vec4 totalColor =vec4(1);
	vec3 totalDiffuse = vec3(0.0);
	vec3 attenuation = vec3(500,0.000001,0.0001);
	vec3 totalSpecular = vec3(0);
	float shineDamper =1000;
	vec3 lightColor = vec3(255);
	float reflectivity=10;

    float distance = length(toLightVector);

    float attFactor = attenuation.x + (attenuation.y*distance)+(attenuation.z*distance*distance);

    vec3 unitLightVector = normalize(toLightVector);
    float nDotl = dot(unitNormal,unitLightVector);
    float brightness = max(nDotl,0.0);
    vec3 lightDirection = -unitLightVector;
    vec3 reflectedLightDirection = reflect(lightDirection,unitNormal);
    float specularFactor = dot(reflectedLightDirection, unitVectorToCamera);
    specularFactor = max(specularFactor,0.0);
    float dampedFactor = pow(specularFactor, shineDamper);
    totalDiffuse = totalDiffuse + (brightness * lightColor)/attFactor;
    totalSpecular = totalSpecular + (dampedFactor*reflectivity*lightColor)/attFactor;
	totalDiffuse = max(totalDiffuse,0.05);

//	color= col;//vec4(totalDiffuse,1.0) * col ;//+ vec4(totalSpecular,1.0);

	color= vec4(totalDiffuse,1.0) * totalColor + vec4(totalSpecular,1.0);

//    color=col*dot(normal,light);
}
