#include "Box.h"
#include <MMath.h>

using namespace GEOMETRY;
using namespace MATH;

void GEOMETRY::Box::generateVerticesAndNormals() {
	// empty the vertices and normals lists
	vertices.clear();
	normals.clear();

	for (float x = -halfSideLength; x <= halfSideLength; x += halfSideLength * 2) {
		for (float y = -halfSideLength; y <= halfSideLength; y += halfSideLength * 2) {
			for (float z = -halfSideLength; z <= halfSideLength; z += halfSideLength * 2)
			{
				// calculate the vertex position relative to the center
				Vec3 vertex = centerPos + Vec3(x, y, z);

				// add the vertex to the list of vertices
				vertices.push_back(vertex);

				//add the normals
				normals.push_back(vertex);

			}

		}
	}

	// render
	StoreMeshData(GL_POINTS);
}