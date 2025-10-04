#include <base/tensor_allocator.h>

#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

TensorError_t tensor_allocate(const size_t *shape, const size_t ndim,
                              Tensor_t **out) {
  if (!shape || !out)
    return TENSOR_ERROR_NULL_POINTER;
  if (ndim == 0)
    return TENSOR_ERROR_SHAPE;

  Tensor_t *t = malloc(sizeof(Tensor_t));
  if (!t)
    return TENSOR_ERROR_MEMORY;

  t->ndim = ndim;
  t->shape = NULL;
  t->strides = NULL;
  t->data = NULL;
  t->own_data = true;
  t->ref_count = 1;

  t->shape = (size_t *)malloc(ndim * sizeof(size_t));
  if (!t->shape) {
    free(t);
    return TENSOR_ERROR_MEMORY;
  }
  memcpy(t->shape, shape, ndim * sizeof(size_t));

  t->strides = (size_t *)malloc(ndim * sizeof(size_t));
  if (!t->strides) {
    free(t->shape);
    free(t);
    return TENSOR_ERROR_MEMORY;
  }

  size_t stride = 1;
  for (ssize_t i = ndim - 1; i >= 0; --i) {
    t->strides[i] = stride;
    if (SIZE_MAX / stride < shape[i]) {
      free(t->strides);
      free(t->shape);
      free(t);
      return TENSOR_ERROR_MEMORY;
    }
    stride *= shape[i];
  }

  t->num_entries = stride;
  t->data = (double *)malloc(t->num_entries * sizeof(double));
  if (!t->data) {
    free(t->strides);
    free(t->shape);
    free(t);
    return TENSOR_ERROR_MEMORY;
  }

  memset(t->data, 0, t->num_entries * sizeof(double));
  *out = t;

  return TENSOR_SUCCESS;
}

TensorError_t tensor_fill(const size_t *shape, const size_t ndim, double value,
                          Tensor_t **out) {
  if (!shape || !out)
    return TENSOR_ERROR_NULL_POINTER;
  if (ndim == 0)
    return TENSOR_ERROR_SHAPE;

  TensorError_t err = tensor_allocate(shape, ndim, out);
  if (err != TENSOR_SUCCESS)
    return err;

  Tensor_t *t = *out;
  for (size_t i = 0; i < t->num_entries; ++i) {
    t->data[i] = value;
  }

  return TENSOR_SUCCESS;
}

TensorError_t tensor_copy(const Tensor_t *src, Tensor_t **out) {
  if (!src || !out)
    return TENSOR_ERROR_NULL_POINTER;

  TensorError_t err = tensor_allocate(src->shape, src->ndim, out);
  if (err != TENSOR_SUCCESS)
    return err;

  Tensor_t *dst = *out;
  memcpy(dst->data, src->data, src->num_entries * sizeof(double));

  return TENSOR_SUCCESS;
}

TensorError_t tensor_deallocate(Tensor_t *t) {
  if (!t)
    return TENSOR_ERROR_NULL_POINTER;

  if (t->own_data && t->data) {
    free(t->data);
    t->data = NULL;
  }

  if (t->shape) {
    free(t->shape);
    t->shape = NULL;
  }

  if (t->strides) {
    free(t->strides);
    t->strides = NULL;
  }

  free(t);

  return TENSOR_SUCCESS;
}
