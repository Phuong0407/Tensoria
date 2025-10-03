#ifndef include_base_tensor_utility_h
#define include_base_tensor_utility_h

#include <base/tensor_def.h>

void tensor_print(const Tensor_t* t);
bool tensor_is_contiguous(const Tensor_t* t);
const char* tensor_error_string(TensorError_t err);

#endif /* include_base_tensor_utility_h */
