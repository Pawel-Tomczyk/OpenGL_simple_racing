#version 330

// trzeba równie¿ zmieniæ w coanstants.h
const int maxDirectionalLightCount = 1;
const int maxPointLightCount = 12;
const int maxSpotLightCount = 4;

//Lighting
struct Light
{
	vec3 color;
	float ambientIntensity;
	float diffuseIntensity;
};

struct DirectionalLight
{
	Light base;
	vec3 direction;
};
uniform DirectionalLight directionalLights[maxDirectionalLightCount];
uniform int directionalLightCount;

struct PointLight
{
	Light base;
	vec3 position;
	float constant;
	float linear;
	float exponent;

};
uniform PointLight pointLights[maxPointLightCount];
uniform int pointLightCount;

struct SpotLight
{
	PointLight base;
	vec3 direction;
	float edge;
};
uniform SpotLight spotLights[maxSpotLightCount];
uniform int spotLightCount;

struct Material
{
	float shininess;
	float specularIntensity;
};
uniform Material material;

uniform sampler2D theTexture;
uniform vec3 cameraPosition;

in vec4 vCol;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

out vec4 colour;

vec4 calcLightByDirection(Light light, vec3 direction){
	vec4 ambientColor = vec4(light.color, 1.0f) * light.ambientIntensity; //kolor œwiat³a otoczenia

	float diffuseFactor = max(dot(normalize(Normal), normalize(direction)), 0.0f) * light.diffuseIntensity; //!!! mo¿liwe ¿e trzeba dodaæ '-' przed direction
	vec4 diffuseColor = vec4(light.color * diffuseFactor, 1.0f); // kolor œwiat³a rozproszonego

	vec4 specularColor = vec4(0.0f, 0.0f, 0.0f, 0.0f); //kolor œwiat³a odbitego
	
	if(diffuseFactor > 0.0f)
	{
		vec3 toEye = normalize(cameraPosition - FragPos); //kierunek od punktu do kamery
		vec3 reflectDir = normalize(reflect(-normalize(direction), normalize(Normal))); //kierunek odbicia œwiat³a

		float specularFactor = dot(toEye, reflectDir); //cosinus k¹ta miêdzy kierunkiem odbicia a kierunkiem do kamery
		if(specularFactor > 0.0f){
			specularFactor = pow(specularFactor, material.shininess);
			specularColor = vec4(light.color * material.specularIntensity * specularFactor, 1.0f);
		}
	}
	return ambientColor + diffuseColor + specularColor;
}

vec4 calcDirectionalLights(){
	vec4 directionalLigthsColor = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	
	for(int i = 0; i < directionalLightCount; i++)
		directionalLigthsColor += calcLightByDirection(directionalLights[i].base, directionalLights[i].direction);

	return directionalLigthsColor;
}

vec4 calcLightByPoint(PointLight light){
	vec3 direction = FragPos - light.position; // mo¿eliwe ¿e trzeba zamieniæ miejscami
	float distance  = length(direction);
	direction = normalize(direction);

	vec4 lightColor = calcLightByDirection(light.base, -direction);

	float attenuation = 1.0f / (light.constant + light.linear * distance + light.exponent * distance * distance);

	return lightColor * attenuation;
}

vec4 calcLightBySpot(SpotLight light){
	vec3 rayDirection = normalize(FragPos - light.base.position);
	float spotFactor = dot(rayDirection, light.direction); // cosinus k¹ta miêdzy kierunkiem œwiat³a a kierunkiem reflektora

	if(spotFactor > light.edge){
		vec4 pointLightColor = calcLightByPoint(light.base);
		return pointLightColor *  (1.0f - (1.0f - spotFactor)*(1.0f/(1.0f - light.edge)));
	}
	else{
		return vec4(0.0f, 0.0f, 0.0f, 0.0f);
	}
}

vec4 calcPointLights(){
	vec4 pointLightsColor = vec4(0.0f, 0.0f, 0.0f, 0.0f);

	for(int i = 0; i < pointLightCount; i++){
		pointLightsColor += calcLightByPoint(pointLights[i]);
	}

	return pointLightsColor;
}

vec4 calcSpotLights(){
	vec4 spotLightsColor = vec4(0.0f, 0.0f, 0.0f, 0.0f);

	for(int i = 0; i < spotLightCount; i++){
		spotLightsColor += calcLightBySpot(spotLights[i]);
	}

	return spotLightsColor;
}

void main()
{
	vec4 finalColor = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	finalColor += calcDirectionalLights();
	finalColor += calcPointLights();
	finalColor += calcSpotLights();

	colour = texture(theTexture, TexCoord) * finalColor;
}

