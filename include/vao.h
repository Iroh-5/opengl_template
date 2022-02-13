#ifndef VAO_H
#define VAO_H

#include "libs.h"
#include "buffer.h"

typedef struct
{
    GLuint id;
} vao;

vao vao_create(void);
void vao_destroy(vao self);
void vao_bind(vao self);
void vao_attr(vao self, buffer vbo, GLuint slot, GLint size, GLenum type, GLsizei stride, size_t offset);

#endif
