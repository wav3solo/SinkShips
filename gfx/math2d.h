// NCurses 2D vector math
// (c) 2022 by Stefan Roettger

#pragma once

//! 2D vector type
struct Vec2
{
   float x;
   float y;
};

//! 3D vector type
struct Vec3
{
   float x;
   float y;
   float z;
};

//! 3D matrix type
struct Mat3
{
   float r1x, r1y, r1z;
   float r2x, r2y, r2z;
   float r3x, r3y, r3z;
};

//! 2D vector construction from components x and y
inline Vec2 vec2(float x = 0, float y = 0)
{
   Vec2 v = {x, y};
   return(v);
}

//! 3D vector construction from components x, y and z
//! * homogeneous coordinate z is 1 by default
inline Vec3 vec3(float x = 0, float y = 0, float z = 1)
{
   Vec3 v = {x, y, z};
   return(v);
}

//! 3D vector construction from 2D vector
//! * homogeneous coordinate is complemented to be 1
inline Vec3 vec3(Vec2 v)
{
   return(vec3(v.x, v.y));
}

//! 3D matrix construction
inline Mat3 mat3(float r1x = 1, float r1y = 0, float r1z = 0,
                 float r2x = 0, float r2y = 1, float r2z = 0,
                 float r3x = 0, float r3y = 0, float r3z = 1)
{
   Mat3 M = {r1x, r1y, r1z, r2x, r2y, r2z, r3x, r3y, r3z};
   return(M);
}

//! 2D vector addition
inline Vec2 add2(Vec2 a, Vec2 b)
{
   return(vec2(a.x+b.x, a.y+b.y));
}

//! 2D vector subtraction
inline Vec2 sub2(Vec2 a, Vec2 b)
{
   return(vec2(a.x-b.x, a.y-b.y));
}

//! 2D vector multiplication
inline Vec2 mul2(Vec2 a, Vec2 b)
{
   return(vec2(a.x*b.x, a.y*b.y));
}

//! 2D vector multiplication with scalar value
inline Vec2 mul2s(Vec2 a, float s)
{
   return(vec2(a.x*s, a.y*s));
}

//! 2D dot product
inline float dot2(Vec2 a, Vec2 b)
{
   return(a.x*b.x + a.y*b.y);
}

//! 3D dot product
inline float dot3(Vec3 a, Vec3 b)
{
   return(a.x*b.x + a.y*b.y + a.z*b.z);
}

//! get 3D matrix row
inline Vec3 row1(const Mat3 &m) {return(vec3(m.r1x, m.r1y, m.r1z));}
inline Vec3 row2(const Mat3 &m) {return(vec3(m.r2x, m.r2y, m.r2z));}
inline Vec3 row3(const Mat3 &m) {return(vec3(m.r3x, m.r3y, m.r3z));}

//! get 3D matrix column
inline Vec3 col1(const Mat3 &m) {return(vec3(m.r1x, m.r2x, m.r3x));}
inline Vec3 col2(const Mat3 &m) {return(vec3(m.r1y, m.r2y, m.r3y));}
inline Vec3 col3(const Mat3 &m) {return(vec3(m.r1z, m.r2z, m.r3z));}

//! 3D matrix multiplication
inline Mat3 mul3(const Mat3 &m1, const Mat3 &m2)
{
   return(mat3(dot3(row1(m1), col1(m2)), dot3(row1(m1), col2(m2)), dot3(row1(m1), col3(m2)),
               dot3(row2(m1), col1(m2)), dot3(row2(m1), col2(m2)), dot3(row2(m1), col3(m2)),
               dot3(row3(m1), col1(m2)), dot3(row3(m1), col2(m2)), dot3(row3(m1), col3(m2))));
}

//! 3D matrix multiplication with right-hand side vector
inline Vec2 mul3v(const Mat3 &m, Vec3 v)
{
   Vec3 v3 = vec3(dot3(row1(m), v),
                  dot3(row2(m), v),
                  dot3(row3(m), v));

   float h = v3.z;
   if (h != 0)
      if (h != 1)
         h = 1/h;

   return(vec2(v3.x*h, v3.y*h));
}

//! convert x-component of 2D vector to rounded int
inline int vec2_x(Vec2 v)
{
   return((int)(v.x+0.5f));
}

//! convert y-component of 2D vector to rounded int
inline int vec2_y(Vec2 v)
{
   return((int)(v.y+0.5f));
}

//! convert x-component of 3D vector to rounded int
inline int vec3_x(Vec3 v)
{
   return((int)(v.x+0.5f));
}

//! convert y-component of 3D vector to rounded int
inline int vec3_y(Vec3 v)
{
   return((int)(v.y+0.5f));
}

//! convert z-component of 3D vector to rounded int
inline int vec3_z(Vec3 v)
{
   return((int)(v.z+0.5f));
}

//! get current transformation represented by a 3x3 homogeneous matrix
//! the current transformation is the top of the matrix stack
Mat3 top();

//! push current transformation
//! this duplicates the current matrix on top of the matrix stack
void push();

//! replace current transformation with a given transformation matrix
void replace(const Mat3 &m);

//! pop current transformation
//! this removes the current matrix on top of the matrix stack
Mat3 pop();

//! apply translation vector to current transformation
//! * the current transformation matrix is multiplied with a translation matrix
//! * defined by the translation vector v
void translate(Vec2 v);

//! apply translation to current transformation
//! * the current transformation matrix is multiplied with a translation matrix
//! * defined by the translation vector (x, y)
void translate(float x, float y);

//! apply clockwise rotation to current transformation
//! * the current transformation matrix is multiplied with a rotation matrix
//! * defined by a rotation angle a given in degrees
//! * the rotation aspect is 2 by default for characters two times higher than wide
void rotate(float a, float aspect = 2);

//! apply uniform scaling factor to current transformation
//! * the current transformation matrix is multiplied with a scaling matrix
//! * defined by the scaling factor f in x- and y-direction
void scale(float f);

//! apply non-uniform scaling to current transformation
//! * the current transformation matrix is multiplied with a scaling matrix
//! * defined by the scaling factors in x- and y-direction s and t
void scale(float s, float t);

//! get current translation vector
Vec2 translation();

//! get current rotation angle
//! * does not work for non-uniformly scaled transformations
//! * the rotation aspect is 2 by default for characters two times higher than wide
float rotation(float aspect = 2);

//! get current scaling factor
//! * does not work for non-uniformly scaled transformations
//! * the rotation aspect is 2 by default for characters two times higher than wide
float scaling(float aspect = 2);
