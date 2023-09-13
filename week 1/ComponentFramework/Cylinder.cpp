#include "Cylinder.h"
#include <MMath.h>
using namespace GEOMETRY;
using namespace MATH;

void GEOMETRY::Cylinder::generateVerticesAndNormals()
{
    const float deltaTheta = 0.5f;
    const float deltaHeight = 0.5f;
    const float height = 2.0f;

    // Generate the lateral surface of the cylinder
    for (float h = 0.0f; h <= height; h += deltaHeight)
    {
        for (float thetaDeg = 0.0f; thetaDeg <= 360.0f; thetaDeg += deltaTheta)
        {
            Vec3 circle(r * cos(thetaDeg * DEGREES_TO_RADIANS), r * sin(thetaDeg * DEGREES_TO_RADIANS), h);
            vertices.push_back(circle);
            Vec3 normal(cos(thetaDeg * DEGREES_TO_RADIANS), sin(thetaDeg * DEGREES_TO_RADIANS), 0.0f);
            normals.push_back(normal);
        }
    }

    // Generate the top and bottom circles of the cylinder
    for (float h : {0.0f, height})
    {
        for (float thetaDeg = 0.0f; thetaDeg <= 360.0f; thetaDeg += deltaTheta)
        {
            Vec3 circle(r * cos(thetaDeg * DEGREES_TO_RADIANS), r * sin(thetaDeg * DEGREES_TO_RADIANS), h);
            vertices.push_back(circle);
            Vec3 normal(0.0f, 0.0f, h == 0.0f ? -1.0f : 1.0f);
            normals.push_back(normal);
        }
    }

    // Once we are all done filling the vertices and normals, use the base class method to store the data in the GPU
    StoreMeshData(GL_POINTS);
}
