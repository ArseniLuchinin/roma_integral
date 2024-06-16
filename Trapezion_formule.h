#ifndef TRAPEZION_FORMULE_H_INCLUDED
#define TRAPEZION_FORMULE_H_INCLUDED
#include <functional>

float trapezoid_Method(const float a, const float b, const size_t n, const std::function<float(float)> f);

#endif // TRAPEZION_FORMULE_H_INCLUDED
