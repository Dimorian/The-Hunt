#sginclude "://shaders/commonlightmodels.inc"

in vec3 viewPosition;
in vec3 viewNormal;

out vec4 fragColor;

void main()
{
    vec3 viewDirection = -normalize(viewPosition);
    vec3 viewNormal = normalize(viewNormal);
    vec3 vertexColor = phong(viewPosition, viewDirection, viewNormal, vec3(1.0));
    fragColor = vec4(vertexColor + material.emission.rgb, computeMaterialAlpha());
}
