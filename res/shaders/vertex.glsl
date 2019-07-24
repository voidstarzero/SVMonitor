// Choice of coordinates is (radial pixels, degrees clockwise from top)
attribute vec2 vertexPosition; // Vertex position from shape origin, in polar coordiantes

uniform vec2 shapeScale; // Shape polar scale factor, (radial, circular)
uniform float shapeRotation; // Shape rotation around itself (degrees)
uniform vec2 shapeLocation; // Cartesian coordinates, (pixels, pixels)

uniform vec2 windowSize; // In (pixels, pixels)

const float PI = 3.1415926535897932384626433832795;

void main()
{
    vec2 scaleRotVertex = vertexPosition * shapeScale + vec2(0.0, shapeRotation);
    float vertexRadAngle = scaleRotVertex.t / 180.0 * PI;   // GLSL functions expect radians

    vec2 cartesianAbsVertex = vec2(
        scaleRotVertex.s * sin(vertexRadAngle),    // Ordering of sin and cos ensures trans-
        scaleRotVertex.s * -cos(vertexRadAngle))   // formation from -y to +x angle origin
    + shapeLocation;

    gl_Position.xy = cartesianAbsVertex
        * 2.0
        / vec2(windowSize.x, -windowSize.y) // Includes down-y to up-y transformation
        + vec2(-1.0, +1.0);
}
