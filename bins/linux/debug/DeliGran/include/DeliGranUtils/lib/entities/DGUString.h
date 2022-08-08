#ifndef DGU_STRING_H
#define DGU_STRING_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include <stdbool.h>

  typedef char *sds;
  typedef sds string;

  extern struct DGUStringEntity {
    string (*new)(string stringValue);
    string (*newEmpty)(void);
    void (*destroy)(string *stringToDestroy);
    string (*trim)(string stringValue);
    int (*length)(string stringValue);
    bool (*isEmpty)(string stringValue);
    int (*toInteger)(string stringValue);
    string (*removeChars)(string stringValue, string chars2Remove);
    string (*format)(string format, ...);
    string (*concat)(string string1, string string2);
    bool (*isEquals)(string string1, string string2);
    string (*replace)(string stringSource, string stringOld, string stringNew);
    string (*getDateTime2String)(string formatDateTime);
    string (*copyLength)(string source, int length);
    string (*getUUIDRandom)(void);
  } DGUStringEntity;

#ifdef __cplusplus
}
#endif

#endif //DGU_STRING_H
