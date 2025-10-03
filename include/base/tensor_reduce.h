#ifndef include_base_tensor_reduce_h
#define include_base_tensor_reduce_h

#include <base/tensor_def.h>

double tensor_sum(const Tensor_t* t);
double tensor_mean(const Tensor_t* t);
double tensor_max(const Tensor_t* t);
double tensor_min(const Tensor_t* t);

#endif /* include_base_tensor_reduce_h */