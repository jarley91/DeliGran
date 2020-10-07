#ifndef DGU_HASHTABLE_H
#define DGU_HASHTABLE_H

#ifdef __cplusplus
extern "C"
{
#endif
  
  #include <stdbool.h>

  #include "DGUString.h"

  typedef void (*forEachItemDGUHTFunction)(int index, string key, void *value);

  typedef struct DGUHashTable DGUHashTable;

  extern struct DGUHashTableEntity {
    DGUHashTable *(*new)(unsigned int initialSize);
    void (*destroy)(DGUHashTable *table);
    void (*insert)(DGUHashTable *table, string key, void *value);
    void (*delete)(DGUHashTable *table, string key);
    bool (*exist)(DGUHashTable *table, string key);
    void *(*getValue)(DGUHashTable *table, string key);
    int (*getCount)(DGUHashTable *table);
    void (*forEach)(DGUHashTable *table, forEachItemDGUHTFunction forEachFunction);
  } DGUHashTableEntity;

#ifdef __cplusplus
}
#endif

#endif //DGU_HASHTABLE_H
