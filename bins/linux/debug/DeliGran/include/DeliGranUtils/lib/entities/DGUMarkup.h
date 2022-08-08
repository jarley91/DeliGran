#ifndef DGU_Markup_H
#define DGU_Markup_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include <stdbool.h>

  #include "DGUString.h"
  #include "DGUMarkup.h"
  #include "DGULog.h"
  #include "DGUHashTable.h"

  typedef struct DGUMUFormats {
    string YAML;
    string JSON;
  } DGUMUFormats;

  typedef struct DGUMUDocument DGUMUDocument;
  typedef struct DGUMUNode DGUMUNode;

  typedef bool (*ArrayIterationDGUMUFunction)(void *node, void *aux);
  typedef bool (*PropertiesIterationDGUMUFunction)(string key, string value, void *aux);

  typedef struct DGUMarkup DGUMarkup;

  extern struct DGUMarkupEntity {
    void (*setLogger)(DGUMarkup *oDGUMarkup, DGULog *oDGULog);
    void (*destroy)(DGUMarkup *oDGUMarkup);
    DGUMarkup *(*new)(void);
    void (*setPathFileDocument)(DGUMarkup *oDGUMarkup, string pathFileDocument);
    string (*getPathFileDocument)(DGUMarkup *oDGUMarkup);
    void (*setStringDocument)(DGUMarkup *oDGUMarkup, string stringDocument);
    string (*getStringDocument)(DGUMarkup *oDGUMarkup);
    bool (*isValidDocument)(DGUMarkup *oDGUMarkup);
    string (*getValueByPath)(DGUMarkup *oDGUMarkup, string pathNode);
    string (*getNodeValue)(DGUMarkup *oDGUMarkup, void *node, string key);
    void (*setNodeKeyValueByPath)(DGUMarkup *oDGUMarkup, string nodePath, string key, string value);
    DGUMUDocument *(*newDocument)(DGUMarkup *oDGUMarkup);
    void (*destroyDcoument)(DGUMarkup *oDGUMarkup, DGUMUDocument *document);
    void (*addPropertyToDocument)(DGUMarkup *oDGUMarkup, DGUMUDocument *document, string key, string value);
    DGUMUNode *(*addNodeToDocument)(DGUMarkup *oDGUMarkup, DGUMUDocument *document, string key);
    void (*addNodeToNode)(DGUMarkup *oDGUMarkup, DGUMUNode *nodeSource, DGUMUNode *nodeDest);
    void (*addPropertyToNode)(DGUMarkup *oDGUMarkup, DGUMUNode *node, string key, string value);
    DGUMUNode *(*addArrayToNode)(DGUMarkup *oDGUMarkup, string keyArray, string keyNodeArray, DGUMUNode *nodeDest);
    DGUMUNode *(*newNode)(DGUMarkup *oDGUMarkup, string key);
    DGUMUNode *(*newNodeItemArray)(DGUMarkup *oDGUMarkup);
    void (*addPropertyToNodeFromNode)(DGUMarkup *oDGUMarkup, DGUMUNode *node, DGUMUNode *nodeValue);
    string (*documentToString)(DGUMarkup *oDGUMarkup, DGUMUDocument *document, string format);
    string (*toString)(DGUMarkup *oDGUMarkup, string format);
    DGUMUFormats (*getFormats)(void);
  } DGUMarkupEntity;

#ifdef __cplusplus
}
#endif

#endif //DGU_Markup_H
