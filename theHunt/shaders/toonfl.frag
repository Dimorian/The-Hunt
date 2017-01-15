#sginclude "://shaders/commonlightmatdefs.inc"

uniform sampler2D qt_Texture0;
varying vec4 qt_TexCoord0;

in vec3 viewPosition;
in vec3 viewNormal;

float toonKd(vec3 lightViewDirection, vec3 viewNormal)
{
    return max(dot(lightViewDirection, viewNormal), 0.0);
}

float toonKs(vec3 viewDirection, vec3 reflectDirection)
{
    return pow(max(dot(viewDirection, reflectDirection), 0.0), material.shininess);
}

float toonKa()
{
    return(1.0);
}

vec3 toonKdKaColor(vec3 lightViewDirection, vec3 viewNormal, vec3 lightAmbient, vec3 lightDiffuse, float lightAttenuation, vec3 textureColor)
{
    Kd = toonKd(lightViewDirection, viewNormal);
    if(Kd > 0.9)
        Kd = 1.0;
    else if(Kd > 0.7)
        Kd = 0.7;
    else if(Kd > 0.4)
        Kd = 0.4;
    else if(Kd > 0.1)
        Kd = 0.1;

    vec3 diffuseColor =  Kd * (lightDiffuse * material.diffuse.rgb);
    vec3 ambientColor = toonKa() * lightAmbient * material.ambient.rgb;
    vec3 color = (diffuseColor + ambientColor) * textureColor * lightAttenuation;

    return color;
}

vec3 toon(vec3 unnormalizedLightViewDirection, vec3 viewDirection, vec3 viewNormal, vec3 lightAmbient, vec3 lightDiffuse, vec3 lightSpecular, vec2 lightAttenuations, vec3 textureColor)
{
    float lightViewDistance = length(unnormalizedLightViewDirection);
    float lightAttenuation = computeLightAttenuation(lightViewDistance, lightAttenuations);
    vec3 lightViewDirection = unnormalizedLightViewDirection / lightViewDistance;
    vec3 specularColor = toonKsColor(lightViewDirection, viewDirection, viewNormal, lightSpecular, lightAttenuation);

    return toonKdKaColor(lightViewDirection, viewNormal, lightAmbient, lightDiffuse, lightAttenuation, textureColor) + specularColor;
}

void main(void)
{
    vec3 viewDirection = -normalize(viewPosition);

    vec3 color = vec3(0.0);
    for (int i = 0; i < sunLightCount; ++i)
    {
        color += toon(-sunLights[i].viewDirection, viewDirection, viewNormal, sunLights[i].ambient,
                       sunLights[i].diffuse, sunLights[i].specular, vec2(0.0), textureColor).rgb;
    }

    for (int i = 0; i < pointLightCount; ++i)
    {
        vec3 lightViewDirection = pointLights[i].viewPosition - viewPosition;
        color += toon(lightViewDirection, viewDirection, viewNormal, pointLights[i].ambient,
                       pointLights[i].diffuse, pointLights[i].specular, pointLights[i].attenuations, textureColor).rgb;
    }

    for (int i = 0; i < spotLightCount; ++i)
    {
        vec3 lightViewDirection = spotLights[i].viewPosition - viewPosition;
        float clampedCosine = max(-dot(normalize(lightViewDirection), spotLights[i].viewDirection), 0.0);
        if (clampedCosine >= spotLights[i].falloffAngle)
        {
            float falloffExponent = pow(clampedCosine, spotLights[i].falloffExponent);
            color += toon(lightViewDirection, viewDirection, viewNormal, spotLights[i].ambient,
                           spotLights[i].diffuse, spotLights[i].specular, spotLights[i].attenuations, textureColor).rgb * falloffExponent;
        }
    }

    gl_FragColor = vec4(color + material.emission.rgb, computeMaterialAlpha());
}
