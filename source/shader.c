#include "../include/shader.h"

static size_t _get_file_size(FILE* file)
{
    size_t length = 0;
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    return length;
}

static void _check(GLuint id, const char* what, const char* path, const char* file,
       void (*getlog)(GLuint, GLsizei, GLsizei*, GLchar*),
       void (*getiv)(GLuint, GLenum, GLint*))
{
    int success;
    const size_t info_size = 512;
    char log[info_size];

    getiv(id, strcmp(what, "compilation") == 0 ? GL_COMPILE_STATUS : GL_LINK_STATUS, &success);
    if (!success)
    {
	getlog(id, info_size, NULL, log);

	if (path != NULL)
	{
	    logger_log(ERROR, "[%s][%s]: %s went wrong\n[ERROR_MESSAGE]: %s\n", file, path, what, log);
	}
	else
	{
	    logger_log(ERROR, "[%s]: %s went wrong\n[ERROR_MESSAGE]: %s\n", file, what, log);
	}
    }
    else
    {
	logger_log(INFO, "[%s]: %s was successful\n", file, what);
    }
}

static void _check_compile(GLuint id, GLenum type, const char* path)
{
    _check(id, "compilation", path, type == GL_VERTEX_SHADER ? "VERTEX_SHADER" : "FRAGMENT_SHADER", glGetShaderInfoLog, glGetShaderiv);
}

static void _check_link(GLuint id)
{
    _check(id, "linkage", NULL, "SHADER_PROGRAM", glGetProgramInfoLog, glGetProgramiv);
}

static char* _read_shader(char* file_path)
{
    FILE* src_file = fopen(file_path, "rb");
    if (src_file == NULL)
    {
	logger_log(ERROR, "Could not open a file: \'%s\'\n", file_path);
    }

    size_t size = _get_file_size(src_file);
    if (size == 0)
    {
	logger_log(ERROR, "File is empty: \'%s\'\n", file_path);
    }

    char* buffer = calloc(1, size + 1);
    if (buffer == NULL)
    {
	logger_log(ERROR, "Program has run out of memory");
    }

    fread(buffer, 1, size, src_file);
    buffer[size] = '\0';

    fclose(src_file);
    return buffer;
}

static GLuint _compile_shader(char* path, GLenum type)
{
    char* src = _read_shader(path);
    size_t size = strlen(src);
    if (size == 0)
    {
	logger_log(ERROR, "Error during file reading has occured");
    }

    GLuint shader_id = glCreateShader(type);
    glShaderSource(shader_id, 1, (const GLchar* const*)&src, (const GLint*)&size);
    glCompileShader(shader_id);

    _check_compile(shader_id, type, path);
    free(src);

    return shader_id;
}

shader_program shader_program_create(char* vs_path, char* fs_path)
{
    shader_program shader_program;

    shader_program.vsid = _compile_shader(vs_path, GL_VERTEX_SHADER);
    shader_program.fsid = _compile_shader(fs_path, GL_FRAGMENT_SHADER);
    shader_program.spid = glCreateProgram();

    glAttachShader(shader_program.spid, shader_program.vsid);
    glAttachShader(shader_program.spid, shader_program.fsid);
    glLinkProgram(shader_program.spid);

    _check_link(shader_program.spid);

    return shader_program;
}

void shader_program_bind(shader_program sp)
{
    glUseProgram(sp.spid);
}

void shader_program_destroy(shader_program sp)
{
    glDeleteProgram(sp.spid);
    glDeleteShader(sp.vsid);
    glDeleteShader(sp.fsid);
}

void shader_uniform_float(shader_program sp, const char* name, float v)
{
    glUniform1f(glGetUniformLocation(sp.spid, name), v);
}

void shader_uniform_vec3f(shader_program sp, const char* name, vec3f v)
{
    glUniform3f(glGetUniformLocation(sp.spid, name), v.x, v.y, v.z);
}

void shader_uniform_vec4f(shader_program sp, const char* name, vec4f v)
{
    glUniform4f(glGetUniformLocation(sp.spid, name), v.x, v.y, v.z, v.w);
}

void shader_uniform_mat4f(shader_program sp, const char* name, mat4f m)
{
    glUniformMatrix4fv(glGetUniformLocation(sp.spid, name), 1, GL_TRUE, (const GLfloat*)&m.m[0][0]);
}
