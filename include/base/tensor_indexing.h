#ifndef include_base_tensor_indexing_h
#define include_base_tensor_indexing_h

#include <base/tensor_def.h>

size_t tensor_offset(const Tensor_t *t, const size_t *indices);
double tensor_get(const Tensor_t *t, const size_t *indices);
void tensor_set(Tensor_t *t, const size_t *indices, double value);

#endif /* include_base_tensor_indexing_h */