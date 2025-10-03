#ifndef include_base_tensor_arithmetic_h
#define include_base_tensor_arithmetic_h

#include <base/tensor_def.h>

TensorError_t tensor_add(const Tensor_t* a, const Tensor_t* b, Tensor_t** result);
TensorError_t tensor_sub(const Tensor_t* a, const Tensor_t* b, Tensor_t** result);
TensorError_t tensor_mul(const Tensor_t* a, const Tensor_t* b, Tensor_t** result);
TensorError_t tensor_muls(const Tensor_t* a, double scalar, Tensor_t** result);

TensorError_t tensor_add_inplace(Tensor_t* a, const Tensor_t* b);
TensorError_t tensor_muls_inplace(Tensor_t* a, double scalar);

#endif /* include_base_tensor_arithmetic_h */