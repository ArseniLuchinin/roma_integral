#include "Trapezion_formule.h"

float trapezoid_Method(const float a, const float b, const size_t n, const std::function<float(float)> f){
    float deltaX = (b - a)/(float)(n);
    float cur = a + deltaX;
    float sum = (f(a) + f(b))/2.f;
    for(int i = 1; i < n-1; cur += deltaX, ++i){
        sum += f(cur);
    }
    return deltaX*sum;
}
