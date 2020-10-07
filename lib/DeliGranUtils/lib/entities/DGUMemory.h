#ifndef DGU_MEMORY_H
#define DGU_MEMORY_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include <stdio.h>
  #include <stdlib.h>

  extern struct DGUMemoryEntity {
    void *(*malloc)(size_t size);
    void *(*realloc)(void *ptr, size_t size);
    void (*free)(void *ptr);
  } DGUMemoryEntity;

#ifdef __cplusplus
}
#endif

#endif //DGU_MEMORY_H
