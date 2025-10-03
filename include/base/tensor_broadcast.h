#ifndef include_base_tensor_broadcast_h
#define include_base_tensor_broadcast_h

#include <base/tensor_def.h>

int tensor_broadcast_shape(const Tensor_t* A, const Tensor_t* B, Tensor_t** result);
int tensor_broadcast_to(const Tensor_t* src, Tensor_t* dst);

#endif /* include_base_tensor_broadcast_h */