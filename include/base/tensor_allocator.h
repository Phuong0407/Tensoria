#ifndef base_tensor_allocation_h
#define base_tensor_allocation_h

#include <base/tensor_def.h>

TensorError_t tensor_allocate(const size_t* shape, const size_t ndim, Tensor_t** out);
TensorError_t tensor_zero(const size_t* shape, const size_t ndim, Tensor_t** out);
TensorError_t tensor_one(const size_t* shape, const size_t ndim, Tensor_t ** out);
TensorError_t tensor_copy(const Tensor_t* src, Tensor_t* dis);
TensorError_t tensor_deallocate(Tensor_t* t);

#endif /* base_tensor_allocation_h */
