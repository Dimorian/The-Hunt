#sginclude "://shaders/commonlight.vert.inc"

uniform float Time;

in vec3 viewPosition;
in vec3 viewNormal;

out vec4 fragColor;

void main(void)
{
    float PI = 3.141;
    vec3 viewDirection = -normalize(viewPosition);

    vec3 color = lambert(viewPosition, viewDirection, viewNormal, vec3(1.0));

    fragColor = vec4(color.rgb, /*sin(Time*PI)**/0.5);
}
