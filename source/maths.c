#include "../include/maths.h"

// ===== float numbers functions =====

float sqrf(float val)
{
    return val * val;
}

float to_radians(float angle)
{
    return angle * PI / 180.0f;
}

float to_degrees(float rads)
{
    return rads * 180.0f / PI;
}

// ===== vec2f =====

vec2f vec2f_add(vec2f lhs, vec2f rhs)
{
    return vec2f(lhs.x + rhs.x, lhs.y + rhs.y);
}

vec2f vec2f_sub(vec2f lhs, vec2f rhs)
{
    return vec2f(lhs.x - rhs.x, lhs.y - rhs.y);
}

vec2f vec2f_mul(vec2f v, float val)
{
    return vec2f(v.x * val, v.y * val);
}

vec2f vec2f_div(vec2f v, float val)
{
    return vec2f_mul(v, 1 / val);
}

vec2f vec2f_norm(vec2f v)
{
    float len = vec2f_len(v);
    assert(len > 0);

    return vec2f(v.x / len, v.y / len);
}

vec2f vec2f_neg(vec2f v)
{
    return vec2f(-v.x, -v.y);
}

float vec2f_dot(vec2f lhs, vec2f rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

float vec2f_sqrlen(vec2f v)
{
    return sqrf(v.x) + sqrf(v.y);
}

float vec2f_len(vec2f v)
{
    return sqrtf(vec2f_sqrlen(v));
}

void vec2f_print(const char* name, vec2f v)
{
    printf("%s = (%f, %f)\n", name, v.x, v.y);
}

// ===== vec3f =====

vec3f vec3f_add(vec3f lhs, vec3f rhs)
{
    return vec3f(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

vec3f vec3f_sub(vec3f lhs, vec3f rhs)
{
    return vec3f(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

vec3f vec3f_mul(vec3f v, float val)
{
    return vec3f(v.x * val, v.y * val, v.z * val);
}

vec3f vec3f_div(vec3f v, float val)
{
    return vec3f_mul(v, 1 / val);
}

vec3f vec3f_norm(vec3f v)
{
    float len = vec3f_len(v);
    assert(len > 0);

    return vec3f(v.x / len, v.y / len, v.z / len);
}

vec3f vec3f_neg(vec3f v)
{
    return vec3f(-v.x, -v.y, -v.z);
}

vec3f vec3f_cross(vec3f lhs, vec3f rhs)
{
    mat3f minor_mat = mat3f_from_vec3fs(vec3f(1, 1, 1), lhs, rhs);

    float x = mat3f_cof(minor_mat, 0, 0); 
    float y = mat3f_cof(minor_mat, 0, 1);
    float z = mat3f_cof(minor_mat, 0, 2);

    return vec3f(x, y, z);
}

float vec3f_dot(vec3f lhs, vec3f rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

float vec3f_sqrlen(vec3f v)
{
    return sqrf(v.x) + sqrf(v.y) + sqrf(v.z);
}

float vec3f_len(vec3f v)
{
    return sqrtf(vec3f_sqrlen(v));
}
    
void vec3f_print(const char* name, vec3f v)
{
    printf("%s = (%f, %f, %f)\n", name, v.x, v.y, v.z);
}

// ===== vec4f =====

vec4f vec4f_add(vec4f lhs, vec4f rhs)
{
    return vec4f(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

vec4f vec4f_sub(vec4f lhs, vec4f rhs)
{
    return vec4f(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

vec4f vec4f_mul(vec4f v, float val)
{
    return vec4f(v.x * val, v.y * val, v.z * val, v.w * val);
}

vec4f vec4f_div(vec4f v, float val)
{
    return vec4f_mul(v, 1 / val);
}

vec4f vec4f_norm(vec4f v)
{
    float len = vec4f_len(v);
    assert(len > 0);

    return vec4f(v.x / len, v.y / len, v.z / len, v.w / len);
}

vec4f vec4f_neg(vec4f v)
{
    return vec4f(-v.x, -v.y, -v.z, -v.w);
}

float vec4f_dot(vec4f lhs, vec4f rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

float vec4f_sqrlen(vec4f v)
{
    return sqrf(v.x) + sqrf(v.y) + sqrf(v.z) + sqrf(v.w);
}

float vec4f_len(vec4f v)
{
    return sqrtf(vec4f_sqrlen(v));
}

void vec4f_print(const char* name, vec4f v)
{
    printf("%s = (%f, %f, %f, %f)\n", name, v.x, v.y, v.z, v.w);
}

// ===== mat2f

mat2f mat2f_identity(void)
{
    return (mat2f)
    {{
	{1, 0},
	{0, 1}
    }};
}

mat2f mat2f_from_vec2fs(vec2f r0, vec2f r1)
{
    return (mat2f)
    {{ 
	{r0.x, r0.y},
	{r1.x, r1.y}
    }};
}

mat2f mat2f_add(mat2f lhs, mat2f rhs)
{
    mat2f out;

    for (int r = 0; r < 2; ++r)
    {
	for (int c = 0; c < 2; ++c)
	{
	    out.m[r][c] = lhs.m[r][c] + rhs.m[r][c];
	}
    }

    return out;
}

mat2f mat2f_sub(mat2f lhs, mat2f rhs)
{
    mat2f out;

    for (int r = 0; r < 2; ++r)
    {
	for (int c = 0; c < 2; ++c)
	{
	    out.m[r][c] = lhs.m[r][c] - rhs.m[r][c];
	}
    }

    return out;
}

mat2f mat2f_mul_val(mat2f m, float val)
{
    mat2f out;

    for (int r = 0; r < 2; ++r)
    {
	for (int c = 0; c < 2; ++c)
	{
	    out.m[r][c] = m.m[r][c] * val;
	}
    }

    return out;
}

vec2f mat2f_mul_vec2f(mat2f m, vec2f v)
{
    float x, y;
    x = m.m[0][0] * v.x + m.m[0][1] * v.y;
    y = m.m[1][0] * v.x + m.m[1][1] * v.y;

    return vec2f(x, y);
}

mat2f mat2f_mul_mat2f(mat2f lhs, mat2f rhs)
{
    mat2f out = {{{ 0 }}};

    for (int r = 0; r < 2; ++r)
    {
	for (int c = 0; c < 2; ++c)
	{
	    for (int k = 0; k < 2; ++k)
	    {
		out.m[r][c] += lhs.m[r][k] * rhs.m[k][c];
	    }
	}
    }

    return out;
}

mat2f mat2f_transpose(mat2f m)
{
    mat2f out;

    for (int r = 0; r < 2; ++r)
    {
	for (int c = 0; c < 2; ++c)
	{
	    out.m[r][c] = m.m[c][r];
	}
    }

    return out;
}

float mat2f_minor(mat2f m, int r, int c)
{
    return m.m[1 - r][1 - c];
}

float mat2f_cof(mat2f m, int r, int c)
{
    int sign = ((r + c) % 2 == 0) ? 1 : -1;

    return sign * mat2f_minor(m, r, c);
}

float mat2f_det(mat2f m)
{
    float det = 0;

    for (int c = 0; c < 2; ++c)
    {
	det += m.m[0][c] * mat2f_cof(m, 0, c);
    }

    return det;
}

mat2f mat2f_adj(mat2f m)
{
    mat2f out;

    for (int r = 0; r < 2; ++r)
    {
	for (int c = 0; c < 2; ++c)
	{
	    out.m[r][c] = mat2f_cof(m, r, c);
	}
    }

    return mat2f_transpose(out);
}

mat2f mat2f_inverse(mat2f m)
{
    float det = mat2f_det(m);
    assert(det != 0);

    float inv_det = 1 / det;
    mat2f adj = mat2f_adj(m);

    return mat2f_mul_val(adj, inv_det);
}


void mat2f_print(const char* name, mat2f m)
{
    printf("%s:\n", name);

    for (int r = 0; r < 2; ++r)
    {
	for (int c = 0; c < 2; ++c)
	{
	    printf("%f ", m.m[r][c]);
	}
	putchar('\n');
    }
}

// ===== mat3f =====

mat3f mat3f_identity(void)
{
    return (mat3f)
    {{ 
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1}
    }};
}

mat3f mat3f_from_vec3fs(vec3f r0, vec3f r1, vec3f r2)
{
    return (mat3f)
    {{ 
	{r0.x, r0.y, r0.z},
	{r1.x, r1.y, r1.z},
	{r2.x, r2.y, r2.z}
    }};
}

mat3f mat3f_add(mat3f lhs, mat3f rhs)
{
    mat3f out;

    for (int r = 0; r < 3; ++r)
    {
	for (int c = 0; c < 3; ++c)
	{
	    out.m[r][c] = lhs.m[r][c] + rhs.m[r][c];
	}
    }

    return out;
}

mat3f mat3f_sub(mat3f lhs, mat3f rhs)
{
    mat3f out;

    for (int r = 0; r < 3; ++r)
    {
	for (int c = 0; c < 3; ++c)
	{
	    out.m[r][c] = lhs.m[r][c] - rhs.m[r][c];
	}
    }

    return out;
}

mat3f mat3f_mul_val(mat3f m, float val)
{
    mat3f out;

    for (int r = 0; r < 3; ++r)
    {
	for (int c = 0; c < 3; ++c)
	{
	    out.m[r][c] = m.m[r][c] * val;
	}
    }

    return out;
}

vec3f mat3f_mul_vec3f(mat3f m, vec3f v)
{
    float x, y, z;
    x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z;
    y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z;
    z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z;

    return vec3f(x, y, z);
}

mat3f mat3f_mul_mat3f(mat3f lhs, mat3f rhs)
{
    mat3f out = {{{ 0 }}};

    for (int r = 0; r < 3; ++r)
    {
	for (int c = 0; c < 3; ++c)
	{
	    for (int k = 0; k < 3; ++k)
	    {
		out.m[r][c] += lhs.m[r][k] * rhs.m[k][c];
	    }
	}
    }

    return out;
}

mat3f mat3f_transpose(mat3f m)
{
    mat3f out;

    for (int r = 0; r < 3; ++r)
    {
	for (int c = 0; c < 3; ++c)
	{
	    out.m[r][c] = m.m[c][r];
	}
    }

    return out;
}

float mat3f_minor(mat3f m, int r0, int c0)
{
    int y = 0;
    int x = 0;
    mat2f minor_mat;
    for (int r = 0; r < 3; ++r)
    {
	for (int c = 0; c < 3; ++c)
	{
	    if (r != r0 && c != c0)
	    {
		minor_mat.m[y][x] = m.m[r][c];

		if (++x == 2)
		{
		    x = 0;
		    ++y;
		}
	    }
	}
    }

    return mat2f_det(minor_mat);
}

float mat3f_cof(mat3f m, int r, int c)
{
    int sign = ((r + c) % 2 == 0) ? 1 : -1;

    return sign * mat3f_minor(m, r, c);
}

float mat3f_det(mat3f m)
{
    float det = 0;

    for (int c = 0; c < 3; ++c)
    {
	det += m.m[0][c] * mat3f_cof(m, 0, c);
    }

    return det;
}

mat3f mat3f_adj(mat3f m)
{
    mat3f out;

    for (int r = 0; r < 3; ++r)
    {
	for (int c = 0; c < 3; ++c)
	{
	    out.m[r][c] = mat3f_cof(m, r, c);
	}
    }

    return mat3f_transpose(out);
}

mat3f mat3f_inverse(mat3f m)
{
    float det = mat3f_det(m);
    assert(det != 0);

    float inv_det = 1 / det;
    mat3f adj = mat3f_adj(m);

    return mat3f_mul_val(adj, inv_det);
}


void mat3f_print(const char* name, mat3f m)
{
    printf("%s:\n", name);

    for (int r = 0; r < 3; ++r)
    {
	for (int c = 0; c < 3; ++c)
	{
	    printf("%f ", m.m[r][c]);
	}
	putchar('\n');
    }
}

// ===== mat3f =====

mat4f mat4f_identity(void)
{
    return (mat4f)
    {{
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
    }};
}

mat4f mat4f_from_vec4fs(vec4f r0, vec4f r1, vec4f r2, vec4f r3)
{
    return (mat4f)
    {{
	{r0.x, r0.y, r0.z, r0.w},
	{r1.x, r1.y, r1.z, r1.w},
	{r2.x, r2.y, r2.z, r2.w},
	{r3.x, r3.y, r3.z, r3.w}
    }};
}

vec4f mat4f_mul_vec4f(mat4f m, vec4f v)
{
    float product[4];

    for (int i = 0; i < 4; ++i)
    {
	float a = m.m[i][0] * v.x;
	float b = m.m[i][1] * v.y;
	float c = m.m[i][2] * v.z;
	float d = m.m[i][3] * v.w;

	product[i] = a + b + c + d;
    }

    return vec4f(product[0], product[1], product[2], product[3]);
}

mat4f mat4f_add(mat4f lhs, mat4f rhs)
{
    mat4f out;

    for (int r = 0; r < 4; ++r)
    {
	for (int c = 0; c < 4; ++c)
	{
	    out.m[r][c] = lhs.m[r][c] + rhs.m[r][c];
	}
    }

    return out;
}

mat4f mat4f_sub(mat4f lhs, mat4f rhs)
{
    mat4f out;

    for (int r = 0; r < 4; ++r)
    {
	for (int c = 0; c < 4; ++c)
	{
	    out.m[r][c] = lhs.m[r][c] - rhs.m[r][c];
	}
    }

    return out;
}

mat4f mat4f_mul_mat4f(mat4f lhs, mat4f rhs)
{
    mat4f out = {{{ 0 }}};

    for (int r = 0; r < 4; ++r)
    {
	for (int c = 0; c < 4; ++c)
	{
	    for (int ind = 0; ind < 4; ++ind)
	    {
		out.m[r][c] += lhs.m[r][ind] * rhs.m[ind][c];
	    }
	}
    }

    return out;
}

mat4f mat4f_mul_val(mat4f m, float val)
{
    mat4f out = {{{ 0 }}};

    for (int r = 0; r < 4; ++r)
    {
	for (int c = 0; c < 4; ++c)
	{
	    out.m[r][c] = m.m[r][c] * val;
	}
    }

    return out;
}

mat4f mat4f_transpose(mat4f m)
{
    mat4f out = {{{ 0 }}};

    for (int r = 0; r < 4; ++r)
    {
	for (int c = 0; c < 4; ++c)
	{
	    out.m[r][c] = m.m[c][r];
	}
    }

    return out;
}

float mat4f_minor(mat4f m, int r0, int c0)
{
    int y = 0;
    int x = 0;
    mat3f minor_mat;
    for (int r = 0; r < 4; ++r)
    {
	for (int c = 0; c < 4; ++c)
	{
	    if (r != r0 && c != c0)
	    {
		minor_mat.m[y][x] = m.m[r][c];

		if (++x == 3)
		{
		    x = 0;
		    ++y;
		}
	    }
	}
    }

    return mat3f_det(minor_mat);
}

float mat4f_cof(mat4f m, int r, int c)
{
    int sign = ((r + c) % 2 == 0) ? 1 : -1;

    return sign * mat4f_minor(m, r, c);
}

float mat4f_det(mat4f m)
{
    float det = 0;

    for (int c = 0; c < 4; ++c)
    {
	det += m.m[0][c] * mat4f_cof(m, 0, c);
    }

    return det;
}

mat4f mat4f_adj(mat4f m)
{
    mat4f out;

    for (int r = 0; r < 4; ++r)
    {
	for (int c = 0; c < 4; ++c)
	{
	    out.m[r][c] = mat4f_cof(m, r, c);
	}
    }

    return mat4f_transpose(out);
}

mat4f mat4f_inverse(mat4f m)
{
    float det = mat4f_det(m);
    assert(det != 0);

    float inv_det = 1 / det;
    mat4f adj = mat4f_adj(m);

    return mat4f_mul_val(adj, inv_det);
}

void mat4f_print(const char* name, mat4f m)
{
    printf("%s:\n", name);
    for (int r = 0; r < 4; ++r)
    {
	for (int c = 0; c < 4; ++c)
	{
	    printf("%f ", m.m[r][c]);
	}
	putchar('\n');
    }
}

// ===== transformation matrices =====
mat4f translate(vec3f pos)
{
    mat4f m = mat4f_identity();
    
    m.m[0][3] = pos.x;
    m.m[1][3] = pos.y;
    m.m[2][3] = pos.z;

    return m;
}

mat4f scale(vec3f factors)
{
    mat4f m = mat4f_identity();
    
    m.m[0][0] = factors.x;
    m.m[1][1] = factors.y;
    m.m[2][2] = factors.z;

    return m;
}

mat4f rotate(float angle, vec3f axis)
{
    angle   = (angle * PI) / 180.0f;
    axis    = vec3f_norm(axis); 
    mat4f m = mat4f_identity();
    float c = cos(angle);
    float s = sin(angle);

    m.m[0][0] = sqrf(axis.x) * (1 - c) + c;
    m.m[0][1] = axis.x * axis.y * (1 - c) - s * axis.z;
    m.m[0][2] = axis.x * axis.z * (1 - c) + s * axis.y;
    m.m[1][0] = axis.y * axis.x * (1 - c) + s * axis.z;
    m.m[1][1] = sqrf(axis.y) * (1 - c) + c;
    m.m[1][2] = axis.y * axis.z * (1 - c) - s * axis.x;
    m.m[2][0] = axis.x * axis.z * (1 - c) - s * axis.y;
    m.m[2][1] = axis.y * axis.z * (1 - c) + s * axis.x;
    m.m[2][2] = sqrf(axis.z) * (1 - c) + c;

    return m;
}

// ===== projection matrices =====

mat4f frustum(float left, float right, float bottom, float top, float near, float far)
{
    float x_range = right - left;
    float y_range = top - bottom;
    float z_range = far - near;

    assert(x_range > 0 && y_range > 0 && z_range > 0);
    assert(near > 0 && far > 0);

    vec4f r0 = vec4f(2 * near / x_range, 0.0f, (right + left) / x_range, 0.0f);
    vec4f r1 = vec4f(0.0f, 2 * near / y_range, (top + bottom) / y_range, 0.0f);
    vec4f r2 = vec4f(0.0f, 0.0f, -(near + far) / z_range, -2 * near * far / z_range);
    vec4f r3 = vec4f(0.0f, 0.0f, -1.0f, 0.0f);

    return mat4f_from_vec4fs(r0, r1, r2, r3);
}

mat4f orthographic(float left, float right, float bottom, float top, float near, float far)
{
    float x_range = right - left;
    float y_range = top - bottom;
    float z_range = far - near;

    assert(x_range > 0 && y_range > 0 && z_range > 0);
    assert(near > 0 && far > 0);

    vec4f r0 = vec4f(-2 / x_range, 0.0f, 0.0f, -(left + right) / x_range);
    vec4f r1 = vec4f(0.0f, 2 / y_range, 0.0f, -(top + bottom) / y_range);
    vec4f r2 = vec4f(0.0f, 0.0f, -2 / z_range, -(far + near) / z_range);
    vec4f r3 = vec4f(0.0f, 0.0f, 0.0f, 1.0f);

    return mat4f_from_vec4fs(r0, r1, r2, r3);
}

mat4f perspective(float fovy, float aspect, float near, float far)
{
    float top    = near * (float)tan(fovy / 2.0f);
    float bottom = -top;
    float right  = top * aspect;
    float left   = -right;

    return frustum(left, right, bottom, top, near, far);
}
