#ifndef include_base_tensor_io_h
#define include_base_tensor_io_h

#include <base/tensor_def.h>

int tensor_save_binary(const Tensor_t* tensor, const char* filename);
int tensor_load_binary(Tensor_t* tensor, const char* filename);
int tensor_save_text(const Tensor_t* tensor, const char* filename);
int tensor_load_text(Tensor_t* tensor, const char* filename);

#endif /* include_base_tensor_io_h */