#include "Mesh.h"
#include "xm/constants.h"
std::vector<Vertex> cube_vertices = {
	// Back face
	{ xm::vec3(-1.0f, -1.0f, -1.0f), xm::vec3(0.0f, 0.0f, -1.0f), xm::vec2(0.0f, 0.0f) }, // bottom-left
	{ xm::vec3(1.0f, 1.0f, -1.0f), xm::vec3(0.0f, 0.0f, -1.0f), xm::vec2(1.0f, 1.0f) },	  // top-right
	{ xm::vec3(1.0f, -1.0f, -1.0f), xm::vec3(0.0f, 0.0f, -1.0f), xm::vec2(1.0f, 0.0f) },  // bottom-right
	{ xm::vec3(1.0f, 1.0f, -1.0f), xm::vec3(0.0f, 0.0f, -1.0f), xm::vec2(1.0f, 1.0f) },	  // top-right
	{ xm::vec3(-1.0f, -1.0f, -1.0f), xm::vec3(0.0f, 0.0f, -1.0f), xm::vec2(0.0f, 0.0f) }, // bottom-left
	{ xm::vec3(-1.0f, 1.0f, -1.0f), xm::vec3(0.0f, 0.0f, -1.0f), xm::vec2(0.0f, 1.0f) },  // top-left

	// Front face
	{ xm::vec3(-1.0f, -1.0f, 1.0f), xm::vec3(0.0f, 0.0f, 1.0f), xm::vec2(0.0f, 0.0f) }, // bottom-left
	{ xm::vec3(1.0f, -1.0f, 1.0f), xm::vec3(0.0f, 0.0f, 1.0f), xm::vec2(1.0f, 0.0f) },	// bottom-right
	{ xm::vec3(1.0f, 1.0f, 1.0f), xm::vec3(0.0f, 0.0f, 1.0f), xm::vec2(1.0f, 1.0f) },	// top-right
	{ xm::vec3(1.0f, 1.0f, 1.0f), xm::vec3(0.0f, 0.0f, 1.0f), xm::vec2(1.0f, 1.0f) },	// top-right
	{ xm::vec3(-1.0f, 1.0f, 1.0f), xm::vec3(0.0f, 0.0f, 1.0f), xm::vec2(0.0f, 1.0f) },	// top-left
	{ xm::vec3(-1.0f, -1.0f, 1.0f), xm::vec3(0.0f, 0.0f, 1.0f), xm::vec2(0.0f, 0.0f) }, // bottom-left

	// Left face
	{ xm::vec3(-1.0f, 1.0f, 1.0f), xm::vec3(-1.0f, 0.0f, 0.0f), xm::vec2(1.0f, 0.0f) },	  // top-right
	{ xm::vec3(-1.0f, 1.0f, -1.0f), xm::vec3(-1.0f, 0.0f, 0.0f), xm::vec2(1.0f, 1.0f) },  // top-left
	{ xm::vec3(-1.0f, -1.0f, -1.0f), xm::vec3(-1.0f, 0.0f, 0.0f), xm::vec2(0.0f, 1.0f) }, // bottom-left
	{ xm::vec3(-1.0f, -1.0f, -1.0f), xm::vec3(-1.0f, 0.0f, 0.0f), xm::vec2(0.0f, 1.0f) }, // bottom-left
	{ xm::vec3(-1.0f, -1.0f, 1.0f), xm::vec3(-1.0f, 0.0f, 0.0f), xm::vec2(0.0f, 0.0f) },  // bottom-right
	{ xm::vec3(-1.0f, 1.0f, 1.0f), xm::vec3(-1.0f, 0.0f, 0.0f), xm::vec2(1.0f, 0.0f) },	  // top-right

	// Right face
	{ xm::vec3(1.0f, 1.0f, 1.0f), xm::vec3(1.0f, 0.0f, 0.0f), xm::vec2(1.0f, 0.0f) },	// top-left
	{ xm::vec3(1.0f, -1.0f, -1.0f), xm::vec3(1.0f, 0.0f, 0.0f), xm::vec2(0.0f, 1.0f) }, // bottom-right
	{ xm::vec3(1.0f, 1.0f, -1.0f), xm::vec3(1.0f, 0.0f, 0.0f), xm::vec2(1.0f, 1.0f) },	// top-right
	{ xm::vec3(1.0f, -1.0f, -1.0f), xm::vec3(1.0f, 0.0f, 0.0f), xm::vec2(0.0f, 1.0f) }, // bottom-right
	{ xm::vec3(1.0f, 1.0f, 1.0f), xm::vec3(1.0f, 0.0f, 0.0f), xm::vec2(1.0f, 0.0f) },	// top-left
	{ xm::vec3(1.0f, -1.0f, 1.0f), xm::vec3(1.0f, 0.0f, 0.0f), xm::vec2(0.0f, 0.0f) },	// bottom-left

	// Bottom face
	{ xm::vec3(-1.0f, -1.0f, -1.0f), xm::vec3(0.0f, -1.0f, 0.0f), xm::vec2(0.0f, 1.0f) }, // top-right
	{ xm::vec3(1.0f, -1.0f, -1.0f), xm::vec3(0.0f, -1.0f, 0.0f), xm::vec2(1.0f, 1.0f) },  // top-left
	{ xm::vec3(1.0f, -1.0f, 1.0f), xm::vec3(0.0f, -1.0f, 0.0f), xm::vec2(1.0f, 0.0f) },	  // bottom-left
	{ xm::vec3(1.0f, -1.0f, 1.0f), xm::vec3(0.0f, -1.0f, 0.0f), xm::vec2(1.0f, 0.0f) },	  // bottom-left
	{ xm::vec3(-1.0f, -1.0f, 1.0f), xm::vec3(0.0f, -1.0f, 0.0f), xm::vec2(0.0f, 0.0f) },  // bottom-right
	{ xm::vec3(-1.0f, -1.0f, -1.0f), xm::vec3(0.0f, -1.0f, 0.0f), xm::vec2(0.0f, 1.0f) }, // top-right

	// Top face
	{ xm::vec3(-1.0f, 1.0f, -1.0f), xm::vec3(0.0f, 1.0f, 0.0f), xm::vec2(0.0f, 1.0f) }, // top-left
	{ xm::vec3(1.0f, 1.0f, 1.0f), xm::vec3(0.0f, 1.0f, 0.0f), xm::vec2(1.0f, 0.0f) },	// bottom-right
	{ xm::vec3(1.0f, 1.0f, -1.0f), xm::vec3(0.0f, 1.0f, 0.0f), xm::vec2(1.0f, 1.0f) },	// top-right
	{ xm::vec3(1.0f, 1.0f, 1.0f), xm::vec3(0.0f, 1.0f, 0.0f), xm::vec2(1.0f, 0.0f) },	// bottom-right
	{ xm::vec3(-1.0f, 1.0f, -1.0f), xm::vec3(0.0f, 1.0f, 0.0f), xm::vec2(0.0f, 1.0f) }, // top-left
	{ xm::vec3(-1.0f, 1.0f, 1.0f), xm::vec3(0.0f, 1.0f, 0.0f), xm::vec2(0.0f, 0.0f) }	// bottom-left
};

Mesh::Mesh(Mesh&& other) noexcept
{
	m_vertices_count = other.m_vertices_count;
	m_indices_count = other.m_indices_count;
	m_draw_element = other.m_draw_element;
	vertex_array = std::move(other.vertex_array);
}

Mesh& Mesh::operator=(Mesh&& other) noexcept
{
	if (&other != this)
	{
		m_vertices_count = other.m_vertices_count;
		m_indices_count = other.m_indices_count;
		m_draw_element = other.m_draw_element;
		vertex_array = std::move(other.vertex_array);
	}
	return *this;
}

Mesh::~Mesh()
{
	clear();
}

void Mesh::draw()
{
	vertex_array.bind();
	if (m_draw_element)
	{
		glDrawElements(GL_TRIANGLES, m_indices_count, GL_UNSIGNED_INT, nullptr);
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, m_vertices_count);
	}
	checkGeneralErrorGL("mesh");
}

void Mesh::clear()
{
	vertex_array.clear();
}

Mesh generateIdenticalCube()
{
	Mesh cube(cube_vertices);
	return cube;
}

Mesh generateSphere(float radius, uint sector_count, uint stack_count)
{
	size_t				vertex_amount = (sector_count + 1) * (stack_count + 1);
	std::vector<Vertex> vertices;
	vertices.reserve(vertex_amount);

	float sector_step = 2 * static_cast<float>(xm::PI) / sector_count;
	float stack_step = static_cast<float>(xm::PI) / stack_count;
	float sector_angle, stack_angle;
	float length_inv = 1.0f / radius;

	for (uint i = 0; i <= stack_count; ++i)
	{
		stack_angle = xm::PI / 2 - i * stack_step;
		float xz = radius * cosf(stack_angle);
		float y = radius * sinf(stack_angle);

		for (uint j = 0; j <= sector_count; ++j)
		{
			sector_angle = j * sector_step;

			Vertex v;
			// vertex position (x, y, z)
			float x = xz * cosf(sector_angle);
			float z = -xz * sinf(sector_angle);

			v.m_position = xm::vec3(x, y, z);

			// normalized vertex normal (nx, ny, nz)
			float nx = x * length_inv;
			float ny = y * length_inv;
			float nz = z * length_inv;

			v.m_normal = xm::vec3(nx, ny, nz);

			// vertex tex coord (s, t) range between [0, 1]
			float s = (float)j / sector_count;
			float t = (float)i / stack_count;

			v.m_uv = xm::vec2(s, t);

			vertices.push_back(v);
		}
	}
	std::vector<uint> indices;
	indices.reserve(stack_count * sector_count * 6);
	int k1, k2;
	for (uint i = 0; i < stack_count; ++i)
	{
		k1 = i * (sector_count + 1);
		k2 = k1 + sector_count + 1;

		for (uint j = 0; j < sector_count; ++j, ++k1, ++k2)
		{
			// 2 triangles per sector excluding first and last stacks
			// k1 => k2 => k1+1
			if (i != 0)
			{
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			// k1+1 => k2 => k2+1
			if (i != (stack_count - 1))
			{
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}

	Mesh sphere(std::move(vertices), std::move(indices));
	return sphere;
}
