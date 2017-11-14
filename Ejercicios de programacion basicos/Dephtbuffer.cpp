#include "Dephtbuffer.h"
#include <IL/il.h>
#include <GL/glew.h>


Dephtbuffer::Dephtbuffer()
{
	 _framebuffer = 0;
	 _depthmap = 0;
	 _resolution = 0;
}

Dephtbuffer::~Dephtbuffer()
{
	glDeleteFramebuffers(1, &_framebuffer);

}

void Dephtbuffer::Create(int resolution)
{
	
	glGenFramebuffers(1, &_framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);
	glGenTextures(1, &_depthmap);
	BindDepthMap();
	_resolution = resolution;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	glTexImage2D(
		GL_TEXTURE_2D, 
		0,
		GL_DEPTH_COMPONENT,
		_resolution,
		_resolution,
		0,
		GL_DEPTH_COMPONENT,
		GL_FLOAT,
		nullptr);
	
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	
	glFramebufferTexture2D(
		GL_FRAMEBUFFER,
		GL_DEPTH_ATTACHMENT,
		GL_TEXTURE_2D,
		_depthmap,
		0);

	Unbind();

}

void Dephtbuffer::Bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);
	glViewport(0, 0, _resolution, _resolution);
}

void Dephtbuffer::Unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Dephtbuffer::BindDepthMap()
{
	glBindTexture(GL_TEXTURE_2D, _depthmap);
}

void Dephtbuffer::UnbindDepthMap()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
