#include "../include/vao.h"

vao vao_create(void)
{
    vao self;
    glGenVertexArrays(1, &self.id);
    return self;
}

void vao_destroy(vao self)
{
    glDeleteVertexArrays(1, &self.id);
}

void vao_bind(vao self)
{
    glBindVertexArray(self.id);
}

void vao_attr(vao self, buffer vbo, GLuint slot, GLint count, GLenum type, GLsizei stride, size_t offset)
{
    vao_bind(self);
    buffer_bind(vbo);

    switch (type)
    {
	case GL_BYTE:
	case GL_UNSIGNED_BYTE:
	case GL_SHORT:
	case GL_UNSIGNED_SHORT:
	case GL_INT:
	case GL_UNSIGNED_INT:
	case GL_INT_2_10_10_10_REV:
	case GL_UNSIGNED_INT_2_10_10_10_REV:
	{
	    glVertexAttribIPointer(slot, count, type, stride, (void*)offset);
	} break;
	
	default:
	{
	    glVertexAttribPointer(slot, count, type, GL_FALSE, stride, (void*)offset);
	} break;
    }
    
    glEnableVertexAttribArray(slot);
}
