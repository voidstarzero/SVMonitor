uniform vec3 lineColor;

void main()
{
    gl_FragColor = vec4(lineColor.xyz, 1.0);
}