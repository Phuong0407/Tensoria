#ifndef include_base_tensor_def_h
#define include_base_tensor_def_h

#include <stdbool.h>
#include <stddef.h>

typedef enum {
  TENSOR_SUCCESS = 0,
  TENSOR_ERROR_MEMORY,
  TENSOR_ERROR_SHAPE,
  TENSOR_ERROR_BROADCAST,
  TENSOR_ERROR_INVALID_AXIS,
  TENSOR_ERROR_IO
} TensorError_t;

typedef struct {
  size_t ndim;
  size_t *shape;
  size_t *strides;
  double *data;
  bool own_data;
  size_t ref_count;
} Tensor_t;

#endif /* include_base_tensor_def_h */
