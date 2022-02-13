#include "../include/buffer.h"

buffer buffer_create(GLint type, bool dynamic)
{
    buffer self = 
    {
	.type = type,
	.dynamic = dynamic
    };
    glGenBuffers(1, &self.id);
    return self;
}

void buffer_destroy(buffer self)
{
    glDeleteBuffers(1, &self.id);
}

void buffer_bind(buffer self)
{
    glBindBuffer(self.type, self.id);
}

void buffer_fill_data(buffer self, void* data, size_t offset, size_t size)
{
    buffer_bind(self);
    glBufferData(self.type, size - offset, data, self.dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
}
