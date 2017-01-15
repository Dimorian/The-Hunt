struct SunLight
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    vec3 viewDirection;
};

in vec4 vertexPosition;
in vec3 vertexNormal;
in vec4 vertexColor;
in vec2 textureCoords;

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;

out vec2 texCoords;
out vec3 ec_pos;

void main()
{
    gl_Position = projectionMatrix * modelViewMatrix * vertexPosition;
    texCoords=textureCoords;
    ec_pos = (modelViewMatrix * vertexPosition).xyz;
}
