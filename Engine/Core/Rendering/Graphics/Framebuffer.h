#pragma once

#include <string>

#include <glad/glad.h>

#include "Defines.h"
#include "Texture.h"
#include "Cubemap.h"

class Renderbuffer
{
public:
	Renderbuffer() = default;

	void init();

	Renderbuffer(const Renderbuffer&) = delete;
	Renderbuffer& operator=(const Renderbuffer&) = delete;

	Renderbuffer(Renderbuffer&& other) noexcept;
	Renderbuffer& operator=(Renderbuffer&& other) noexcept;

	~Renderbuffer();

	void		bind();
	static void unbind();

	void setStorage(GLsizei width, GLsizei height, GLenum internalformat);

	GLuint getID() const;

	void clear();

private:

	GLuint m_id = 0;
	inline static GLuint s_active_id = 0;
};

class Framebuffer
{
public:
	Framebuffer();

#ifdef _DEBUG
	Framebuffer(const std::string& debug_name);
	std::string m_debug_name;
#endif

	Framebuffer(const Framebuffer& other) = delete;
	Framebuffer& operator=(const Framebuffer& other) = delete;
	Framebuffer(Framebuffer&& other) noexcept = delete;
	Framebuffer& operator=(Framebuffer&& other) noexcept = delete;

	~Framebuffer();

	void init();
	void clear();

	void attachTexture2D(Texture& texture, GLenum attachment_type = GL_COLOR_ATTACHMENT0);
	void attachCubemap(Cubemap& cubemap, GLenum attachment_type = GL_COLOR_ATTACHMENT0);
	void attachRenderbuffer(Renderbuffer&& renderbuffer, GLenum attachment_type = GL_DEPTH_STENCIL_ATTACHMENT);
	void createAttachRenderbuffer(GLsizei width, GLsizei height, GLenum internal_format = GL_DEPTH24_STENCIL8, GLenum attachment_type = GL_DEPTH_STENCIL_ATTACHMENT);
	Renderbuffer& getRenderbuffer();

	void bind();
	static void bindDefault();

	void drawBuffersDefault(GLsizei size);
	void drawBuffers(GLenum* buffers, GLsizei size);
	void drawBuffer(GLenum buffer);
	void readBuffer(GLenum buffer);

	Renderbuffer m_renderbuffer;

private:
	GLuint				 m_id = 0u;
	inline static GLuint s_active_id = 0;

	static GLenum s_default_draw_buffers[16];
};
