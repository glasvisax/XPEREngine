#pragma once
#include <assimp/matrix4x4.h>
#include <assimp/vector3.h>
#include <glm/gtc/matrix_transform.hpp>

template <typename T> 
inline bool isInRange(T a, T b, T value)
{
	if (b > a)
	{
		return value >= a && value <= b;
	} 
	else
	{
		return value >= b && value <= a;
	}
}

template <typename T, glm::precision P>
inline std::ostream& operator<<(std::ostream& os, const glm::vec<2, T, P>& v)
{
	return os << "(" << v.x << ", " << v.y << ")";
}

template <typename T, glm::precision P>
inline std::ostream& operator<<(std::ostream& os, const glm::vec<3, T, P>& v)
{
	return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

template <typename T, glm::precision P>
inline std::ostream& operator<<(std::ostream& os, const glm::vec<4, T, P>& v)
{
	return os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
}

inline glm::mat4 assimpToGLMMat4(const aiMatrix4x4& from)
{
	glm::mat4 to;
	// the a,b,c,d in assimp is the row ; the 1,2,3,4 is the column
	to[0][0] = from.a1;
	to[1][0] = from.a2;
	to[2][0] = from.a3;
	to[3][0] = from.a4;
	to[0][1] = from.b1;
	to[1][1] = from.b2;
	to[2][1] = from.b3;
	to[3][1] = from.b4;
	to[0][2] = from.c1;
	to[1][2] = from.c2;
	to[2][2] = from.c3;
	to[3][2] = from.c4;
	to[0][3] = from.d1;
	to[1][3] = from.d2;
	to[2][3] = from.d3;
	to[3][3] = from.d4;
	return to;
}

inline glm::vec3 assimpToGLMVec3(aiVector3D from) 
{
	return glm::vec3(from.x, from.y, from.z);
}