#ifndef LALGBR_H
#define LALGBR_H

#include "libs.h"

#define PI 3.14159265358979323846

typedef struct { float x, y; } vec2f;
typedef struct { float x, y, z; } vec3f;
typedef struct { float x, y, z, w; } vec4f;
typedef struct { float m[2][2]; } mat2f;
typedef struct { float m[3][3]; } mat3f;
typedef struct { float m[4][4]; } mat4f;

// TODO: add float related functions
float sqrf(float val);
float to_radians(float angle);
float to_degrees(float rads);

// ===== vec2f =====
vec2f vec2f_add(vec2f lhs, vec2f rhs);
vec2f vec2f_sub(vec2f lhs, vec2f rhs);
vec2f vec2f_mul(vec2f v, float val);
vec2f vec2f_div(vec2f v, float val);
vec2f vec2f_norm(vec2f v);
vec2f vec2f_neg(vec2f v);
float vec2f_dot(vec2f lhs, vec2f rhs);
float vec2f_sqrlen(vec2f v);
float vec2f_len(vec2f v);
void vec2f_print(const char* name, vec2f v);

// ===== vec3f =====
vec3f vec3f_add(vec3f lhs, vec3f rhs);
vec3f vec3f_sub(vec3f lhs, vec3f rhs);
vec3f vec3f_mul(vec3f v, float val);
vec3f vec3f_div(vec3f v, float val);
vec3f vec3f_norm(vec3f v);
vec3f vec3f_neg(vec3f v);
vec3f vec3f_cross(vec3f lhs, vec3f rhs);
float vec3f_dot(vec3f lhs, vec3f rhs);
float vec3f_sqrlen(vec3f v);
float vec3f_len(vec3f v);
void vec3f_print(const char* name, vec3f v);

// ===== vec4f =====
vec4f vec4f_add(vec4f lhs, vec4f rhs);
vec4f vec4f_sub(vec4f lhs, vec4f rhs);
vec4f vec4f_mul(vec4f v, float val);
vec4f vec4f_div(vec4f v, float val);
vec4f vec4f_norm(vec4f v);
vec4f vec4f_neg(vec4f v);
float vec4f_dot(vec4f lhs, vec4f rhs);
float vec4f_sqrlen(vec4f v);
float vec4f_len(vec4f v);
void vec4f_print(const char* name, vec4f v);

// ===== mat2f =====
mat2f mat2f_identity(void);
mat2f mat2f_from_vec2fs(vec2f r0, vec2f r1);
mat2f mat2f_add(mat2f lhs, mat2f rhs);
mat2f mat2f_sub(mat2f lhs, mat2f rhs);
mat2f mat2f_mul_val(mat2f m, float val);
vec2f mat2f_mul_vec2f(mat2f m, vec2f v);
mat2f mat2f_mul_mat2f(mat2f lhs, mat2f rhs);
mat2f mat2f_transpose(mat2f m);
float mat2f_minor(mat2f m, int r, int c);
float mat2f_cof(mat2f m, int r, int c);
float mat2f_det(mat2f m);
mat2f mat2f_adj(mat2f m);
mat2f mat2f_inverse(mat2f m);
void mat2f_print(const char* name, mat2f m);

// ===== mat3f =====
mat3f mat3f_identity(void);
mat3f mat3f_from_vec3fs(vec3f r0, vec3f r1, vec3f r2);
mat3f mat3f_add(mat3f lhs, mat3f rhs);
mat3f mat3f_sub(mat3f lhs, mat3f rhs);
mat3f mat3f_mul_val(mat3f m, float val);
vec3f mat3f_mul_vec3f(mat3f m, vec3f v);
mat3f mat3f_mul_mat3f(mat3f lhs, mat3f rhs);
mat3f mat3f_transpose(mat3f m);
float mat3f_minor(mat3f m, int r, int c);
float mat3f_cof(mat3f m, int r, int c);
float mat3f_det(mat3f m);
mat3f mat3f_adj(mat3f m);
mat3f mat3f_inverse(mat3f m);
void mat3f_print(const char* name, mat3f m);

// ===== mat4f =====
mat4f mat4f_identity(void);
mat4f mat4f_from_vec4fs(vec4f r0, vec4f r1, vec4f r2, vec4f r3);
mat4f mat4f_add(mat4f lhs, mat4f rhs);
mat4f mat4f_sub(mat4f lhs, mat4f rhs);
mat4f mat4f_mul_val(mat4f m, float val);
vec4f mat4f_mul_vec4f(mat4f m, vec4f v);
mat4f mat4f_mul_mat4f(mat4f lhs, mat4f rhs);
mat4f mat4f_transpose(mat4f m);
float mat4f_minor(mat4f m, int r, int c);
float mat4f_cof(mat4f m, int r, int c); 
float mat4f_det(mat4f m);
mat4f mat4f_adj(mat4f m);
mat4f mat4f_inverse(mat4f m);
void mat4f_print(const char* name, mat4f m);

// ===== transformation matrices =====
mat4f translate(vec3f pos);
mat4f scale(vec3f factors);
mat4f rotate(float angle, vec3f axis);

// ===== projection matrices =====
mat4f frustum(float left, float right, float bottom, float top, float near, float far);
mat4f perspective(float fovy, float aspect, float near, float far);
mat4f orthographic(float left, float right, float bottom, float top, float near, float far);

#define vec2f(...) (vec2f){__VA_ARGS__}
#define vec3f(...) (vec3f){__VA_ARGS__}
#define vec4f(...) (vec4f){__VA_ARGS__}

#endif
