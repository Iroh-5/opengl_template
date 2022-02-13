#ifndef SHADER_H
#define SHADER_H

#include "opengl.h"
#include "libs.h"
#include "maths.h"
#include "logging.h"

typedef struct
{
    GLuint spid;
    GLuint vsid;
    GLuint fsid;
} shader_program;

shader_program shader_program_create(char* vs_path, char* fs_path);
void shader_program_destroy(shader_program sp);
void shader_program_bind(shader_program sp);

// TODO: uniforms
// TODO: caching uniform locations
void shader_uniform_float(shader_program sp, const char* name, float v);
void shader_uniform_vec3f(shader_program sp, const char* name, vec3f v);
void shader_uniform_vec4f(shader_program sp, const char* name, vec4f v);
void shader_uniform_mat4f(shader_program sp, const char* name, mat4f m);

#endif
