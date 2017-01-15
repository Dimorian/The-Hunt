#sginclude "://shaders/commonlight.vert.inc"

uniform float Time;

out vec3 viewPosition;
out vec3 viewNormal;

void main(void)
{
    viewPosition = eyePosition().xyz;
    viewNormal = eyeNormalVec().xyz;

    //Wave Motion
    float PI = 3.141;
    vec4 position = vertexPosition;
    position.y += sin(Time*PI*2+position.z)/2.5;
    position.x += sin(Time*PI*2+position.z)/5.0;

    gl_Position = projectionMatrix * modelViewMatrix * position;
}
