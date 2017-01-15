#sginclude "://shaders/commonlight.vert.inc"

uniform float hasTexture=0.0f;
uniform sampler2D textureMap;

in vec2 texCoords;
out vec4 fragColor;
in vec3 ec_pos;

void main()
{
    vec3 ec_normal = normalize(cross(dFdx(ec_pos), dFdy(ec_pos)));

    if(hasTexture > 0.5)
    {
        /*
        vec4 textureFrag = vec4(0.0);
        for (int i = 0; i < sunLightCount; ++i)
            textureFrag += texture(textureMap, texCoords) * max(dot(normalize(-sunLights[i].viewDirection), ec_normal), 0.0);
        fragColor = vec4(textureFrag.rgb, texture(textureMap, texCoords).a);
        */

        vec3 viewDirection = -normalize(ec_pos);
        fragColor = vec4(lambert(ec_pos, viewDirection, ec_normal, texture(textureMap, texCoords).rgb), texture(textureMap, texCoords).a);

    }
//    fragColor = vec4(texCoords.x,texCoords.y,0.,1.);
}
