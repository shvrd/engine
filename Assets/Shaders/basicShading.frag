#version 130

in vec2 fragmentPosition;
in vec4 fragmentColor;
in vec2 fragmentUV;

out vec4 color;

uniform float time;
uniform sampler2D image;

void main() {

    vec4 textureColor = texture(image, fragmentUV);

    color = textureColor * fragmentColor * (sin(time)+1)*0.5;

}