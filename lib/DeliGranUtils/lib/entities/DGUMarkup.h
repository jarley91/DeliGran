#ifndef DGU_Markup_H
#define DGU_Markup_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include <stdbool.h>

  #include "DGUString.h"
  #include "DGUMarkupGlobal.h"

  typedef struct DGUMarkup DGUMarkup;

  extern struct DGUMarkupEntity {
    void (*destroy)(DGUMarkup *oDGUMarkup);
    DGUMarkup *(*new)();
    void (*setPathFileDocument)(DGUMarkup *oDGUMarkup, string pathFileDocument);
    string (*getPathFileDocument)(DGUMarkup *oDGUMarkup);
    void (*setStringDocument)(DGUMarkup *oDGUMarkup, string stringDocument);
    string (*getStringDocument)(DGUMarkup *oDGUMarkup);
    bool (*isValidDocument)(DGUMarkup *oDGUMarkup);
    string (*getStringValue)(DGUMarkup *oDGUMarkup, string path);
    DGUMDDocument *(*newDocument)();
    void (*destroyDcoument)(DGUMDDocument *document);
    void (*addPropertyToDocument)(DGUMDDocument *document, string key, string value);
    DGUMDNode *(*addNodeToDocument)(DGUMDDocument *document, string key);
    void (*addNodeToNode)(DGUMDNode *nodeSource, DGUMDNode *nodeDest);
    void (*addPropertyToNode)(DGUMDNode *node, string key, string value);
    DGUMDNode *(*addArrayToNode)(string keyArray, string keyNodeArray, DGUMDNode *nodeDest);
    DGUMDNode *(*newNode)(string key);
    DGUMDNode *(*newNodeItemArray)();
    void (*addPropertyToNodeFromNode)(DGUMDNode *node, DGUMDNode *nodeValue);
    string (*documentToString)(DGUMDDocument *document, string format);
    DGUMDFormats (*getFormats)();
  } DGUMarkupEntity;

#ifdef __cplusplus
}
#endif

#endif //DGU_Markup_H
