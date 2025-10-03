#ifndef include_base_tensor_contraction_h
#define include_base_tensor_contraction_h

#include <base/tensor_def.h>

int tensor_contractable(const Tensor_t* A, const Tensor_t* B, int axisA, int axisB);
int tensor_contract(const Tensor_t* A, const Tensor_t* B, int axisA, int axisB, Tensor_t** result);
int tensor_contract_all(const Tensor_t* A, const Tensor_t* B, Tensor_t** result);

#endif /* include_base_tensor_contraction_h */