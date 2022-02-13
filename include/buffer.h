#ifndef BUFFER_H
#define BUFFER_H

#include "opengl.h"
#include "libs.h"

typedef struct
{
    GLuint id;
    GLint type;
    bool dynamic;
} buffer;

buffer buffer_create(GLint type, bool dynamic);
void buffer_destroy(buffer self);
void buffer_bind(buffer self);
void buffer_fill_data(buffer self, void* data, size_t offset, size_t count);

#endif
