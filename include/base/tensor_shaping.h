#ifndef include_base_tensor_shaping_h
#define include_base_tensor_shaping_h

#include <base/tensor_def.h>

TensorError_t tensor_reshape(Tensor_t* t, const size_t* new_shape, size_t new_ndim);
TensorError_t tensor_transpose(const Tensor_t* t, const size_t* axes, Tensor_t** result);
TensorError_t tensor_squeeze(const Tensor_t* t, Tensor_t** result);

#endif /* include_base_tensor_shaping_h */