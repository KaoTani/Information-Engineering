//AJG23085 谷口香央
#include <math.h>

extern int N;

float length(float *a){
  float l, sum=0;
  for(int i=0; i<N; i++){
    sum += a[i] * a[i];
  }
  l = sqrt(sum);
  
  return l;
}

float unit(float *a, int i){
  float l, u;
  l = length(a);
  u = a[i] / l;

  return u;
}

float inner(float *a, float *b){
  float in=0;
  int i;
  for(i=0; i<N; i++){
    in += a[i] * b[i];
  }

  return in;
}

float kaku(float *a, float *b){
  float c, θ, d;
  c = inner(a, b) / (length(a) * length(b));
  θ = acos(c);
  d = θ * 180 / M_PI;

  return d;
}