// NCurses 2D vector math
// (c) 2022 by Stefan Roettger

#include <math.h>

#include "math2d.h"

static const int mat3_stack_max = 100;
static int mat3_stack_size = 0;
static Mat3 mat3_stack[mat3_stack_max];

// get current transformation
Mat3 top()
{
   if (mat3_stack_size > 0)
      return(mat3_stack[mat3_stack_size-1]);
   else
      return(mat3());
}

// push current transformation
void push()
{
   if (mat3_stack_size < mat3_stack_max)
   {
      if (mat3_stack_size > 0)
         mat3_stack[mat3_stack_size] = mat3_stack[mat3_stack_size-1];
      else
         mat3_stack[mat3_stack_size] = mat3();
      mat3_stack_size++;
   }
}

// replace current transformation with a given transformation matrix
void replace(const Mat3 &m)
{
   if (mat3_stack_size > 0)
   {
      mat3_stack[mat3_stack_size-1] = m;
   }
   else
   {
      mat3_stack[mat3_stack_size] = m;
      mat3_stack_size++;
   }
}

// pop current transformation
Mat3 pop()
{
   if (mat3_stack_size > 0)
      return(mat3_stack[--mat3_stack_size]);
   else
      return(mat3());
}

// apply translation to current transformation
void translate(float x, float y)
{
   if (mat3_stack_size > 0)
   {
      Mat3 m = mat3(1,0,x, 0,1,y, 0,0,1);
      mat3_stack[mat3_stack_size-1] = mul3(mat3_stack[mat3_stack_size-1], m);
   }
}

// apply translation vector to current transformation
void translate(Vec2 v)
{
   translate(v.x, v.y);
}

// apply clockwise rotation to current transformation
void rotate(float a, float aspect)
{
   if (mat3_stack_size > 0)
   {
      float w = M_PI*a/180;
      float s = sin(w);
      float c = cos(w);

      Mat3 m = mat3(c,-s*aspect,0, s/aspect,c,0, 0,0,1);
      mat3_stack[mat3_stack_size-1] = mul3(mat3_stack[mat3_stack_size-1], m);
   }
}

// apply uniform scaling factor to current transformation
void scale(float f)
{
   scale(f, f);
}

// apply non-uniform scaling to current transformation
void scale(float s, float t)
{
   if (mat3_stack_size > 0)
   {
      Mat3 m = mat3(s,0,0, 0,t,0, 0,0,1);
      mat3_stack[mat3_stack_size-1] = mul3(mat3_stack[mat3_stack_size-1], m);
   }
}

// get current translation vector
Vec2 translation()
{
   Vec2 v = vec2();

   if (mat3_stack_size > 0)
   {
      float x = mat3_stack[mat3_stack_size-1].r1z; // x-component of translation vector
      float y = mat3_stack[mat3_stack_size-1].r2z; // y-component of translation vector
      v = vec2(x, y);
   }

   return(v);
}

// get current rotation angle
float rotation(float aspect)
{
   float a = 0;

   if (mat3_stack_size > 0)
   {
      float x = mat3_stack[mat3_stack_size-1].r1x; // cosine of rotation angle
      float y = mat3_stack[mat3_stack_size-1].r2x*aspect; // sine of rotation angle
      if (x == 0 && y == 0) return(0);
      a = atan2(y, x);
   }

   return(180*a/M_PI);
}

// get current scaling factor
float scaling(float aspect)
{
   float c = 0;

   if (mat3_stack_size > 0)
   {
      float a = rotation();
      float x = mat3_stack[mat3_stack_size-1].r1x;
      float y = mat3_stack[mat3_stack_size-1].r2x*aspect;
      if (x == 0 && y == 0) return(0);
      if (fabs(x) > fabs(y)) c = x/cos(M_PI*a/180);
      else c = y/sin(M_PI*a/180);
   }

   return(fabs(c));
}
