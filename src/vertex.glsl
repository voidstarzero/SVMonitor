attribute vec2 vOffset;

uniform vec2 sPosition;
uniform float sRot;
uniform vec2 winSize;

void main()
{
    const float PI = 3.1415926535897932384626433832795;
    float sRotRad = (sRot + vOffset.t) / 180.0 * PI;

    vec2 cartesianVertex = vec2(
        vOffset.s * sin(sRotRad),
        vOffset.s * -cos(sRotRad));
    vec2 vPosition = sPosition + cartesianVertex;

    gl_Position.xy = vec2(
        vPosition.x / (winSize.x / 2.0) - 1.0,
        -(vPosition.y / (winSize.y / 2.0)) + 1.0);
}
