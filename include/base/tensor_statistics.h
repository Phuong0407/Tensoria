#ifndef include_base_tensor_statistics_h
#define include_base_tensor_statistics_h

#include <base/tensor_def.h>

double tensor_mean(const Tensor_t* tensor, int axis);
double tensor_sum(const Tensor_t* tensor, int axis);
double tensor_std(const Tensor_t* tensor, int axis);
double tensor_var(const Tensor_t* tensor, int axis);
double tensor_norm(const Tensor_t* tensor, double p);

#endif /* include_base_tensor_statistics_h */