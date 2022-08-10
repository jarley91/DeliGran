/**
 * @file DGUString.h
 * @author Jarley Vargas Damian (jarley91@gmail.com)
 * @brief 
 * @version 0.1.0
 * @date 2022-08-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DGU_STRING_H
#define DGU_STRING_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include <stdbool.h>

  /**
   * @brief Simple Dynamic Strings 
   * @see https://github.com/antirez/sds
   */
  typedef char *sds;

  /**
   * @brief Abstract type sds for one familiar global type  
   * @note string includes the * pointer for easy reference
   */
  typedef sds string;

  /**
   * Entity for string functions
   * @brief String functions
   * 
   */

  extern struct DGUStringEntity {

    /**
     * Create a new string
     * 
     * Example: <p>
     * string newString = DGUStringEntity.new(""); <p>
     * string newString = DGUStringEntity.new("String value");
     * 
     * @brief New string
     * 
     * @param stringValue String value
     * 
     * @return New string
     * 
     * @note You should always destroy return value to avoid memory leaks
     */

    string (*new)(string stringValue);

    /**
     * Create a new string empty
     * 
     * Example: <p>
     * string newString = DGUStringEntity.newEmpty();
     * 
     * @brief New string empty
     * 
     * @return New string with empty value
     * 
     * @note You should always destroy return value to avoid memory leaks
     */

    string (*newEmpty)(void);

    /**
     * Destroy a string
     * 
     * Example: <p>
     * string newString = DGUStringEntity.new("String value"); <p>
     * DGUStringEntity.destroy(&newString); 
     * 
     * @brief Destroy string
     * 
     * @param stringToDestroy String to destroy
     */

    void (*destroy)(string *stringToDestroy);

    /**
     * Trim a string, remove whitespace from both the beginning and the end of a string 
     * 
     * string trimValue = DGUStringEntity.trim(" String value "); <br>
     * DGUStringEntity.destroy(&trimValue); 
     * 
     * @brief Trim string
     * 
     * @param stringValue String to trim
     * 
     * @return New string with trim value
     * 
     * @note You should always destroy return value to avoid memory leaks
     */

    string (*trim)(string stringValue);

    /**
     * Length a string
     * 
     * Example: <p>
     * string newString = DGUStringEntity.new("String value"); <br>
     * int length = DGUStringEntity.length(newString); <p>
     * DGUStringEntity.destroy(&newString); 
     * 
     * @brief Length string
     * 
     * @param stringValue String to get its length
     * 
     * @return Length of a string
     */

    int (*length)(string stringValue);

    /**
     * Check if a string is empty
     * 
     * Example: <p>
     * bool isEmpty = DGUStringEntity.isEmpty(stringValue); <br>
     * 
     * @brief Is empty string
     * 
     * @param stringValue String to validate if is empty
     * 
     * @return True or false
     */

    bool (*isEmpty)(string stringValue);

    /**
     * Convert a string to integer
     * 
     * Example: <p>
     * int stringToInteger = DGUStringEntity.toInteger(stringValue); <br>
     * 
     * @brief String to integer
     * 
     * @param stringValue String to convert to integer
     * 
     * @return True or false
     */

    int (*toInteger)(string stringValue);

    /**
     * Remove characters from a string 
     * 
     * string newValue = DGUStringEntity.removeChars("s String value Ss", "sS"); <br>
     * DGUStringEntity.destroy(&newValue); 
     * 
     * @brief Remove characters
     * 
     * @param stringValue String value
     * @param charsToRemove CharsToRemove to remove
     * 
     * @return New string without the characters indicated in the parameter charsToRemove
     * 
     * @note You should always destroy return value to avoid memory leaks
     */

    string (*removeChars)(string stringValue, string charsToRemove);

    /**
     * Format string 
     * 
     * string newValue = DGUStringEntity.format("¡%s %s!", "Hola", "mundo"); <br>
     * DGUStringEntity.destroy(&newValue); 
     * 
     * @brief Format string value
     * @see https://devdocs.io/c/io/fprintf
     * 
     * @param format String value with format
     * @param ... Comma separated values
     * 
     * @return New string with format an values
     * 
     * @note You should always destroy return value to avoid memory leaks
     */

    string (*format)(string format, ...);

    /**
     * Concatenate two strings
     * 
     * string newValue = DGUStringEntity.concat("Hola", "mundo"); <br>
     * DGUStringEntity.destroy(&newValue); 
     * 
     * @brief Concatenate strings
     * 
     * @param string1 String value one
     * @param string2 String value two
     * 
     * @return New string concatenated
     * 
     * @note You should always destroy return value to avoid memory leaks
     */

    string (*concat)(string string1, string string2);

    /**
     * Compare two strings
     * 
     * bool isEqual = DGUStringEntity.conpare("Hola", "hola"); <br>
     * 
     * @brief Compare strings
     * 
     * @param string1 String value one
     * @param string2 String value two
     * 
     * @return True or false
     */

    bool (*isEquals)(string string1, string string2);

    /**
     * Replace a value in a string
     * 
     * string newValue = DGUStringEntity.replace("--Hola Mundo--", "-", "*"); <br>
     * DGUStringEntity.destroy(&newValue); 
     * 
     * @brief Replace value
     * 
     * @param stringSource String source
     * @param stringOld String with old value
     * @param stringNew String with new value
     * 
     * @return New value of string
     * 
     * @note You should always destroy return value to avoid memory leaks
     */

    string (*replace)(string stringSource, string stringOld, string stringNew);

    /**
     * Get string date and time
     * Format sys/time with strftime, was added %MCS = Microseconds and %MLS = Milliseconds
     * 
     * string newValue = DGUStringEntity.getDateTimeToString("%d/%m/%Y %H:%M:%S.%MCS"); <br>
     * DGUStringEntity.destroy(&newValue); 
     * 
     * @brief String value of date and time
     * 
     * @param formatDateTime Format of date and time
     * 
     * @return New value of date and time as string
     * 
     * @see https://devdocs.io/c/chrono/strftime 
     * 
     * @note You should always destroy return value to avoid memory leaks
     */

    string (*getDateTimeToString)(string formatDateTime);

    /**
     * Copies the string value with the specified length, from the start of the string
     * 
     * string newValue = DGUStringEntity.copyLength("Hola Mundo", 4); <br>
     * DGUStringEntity.destroy(&newValue); 
     * 
     * @brief Replace value
     * 
     * @param source String source
     * @param length Length to copy
     * 
     * @return New value of string
     * 
     * @note You should always destroy return value to avoid memory leaks
     */

    string (*copyLength)(string source, int length);

    /**
     * Get a random uuid string value
     * 
     * string newValue = DGUStringEntity.getUUIDRandom(); <br>
     * DGUStringEntity.destroy(&newValue); 
     * 
     * @brief Random uuid
     * 
     * @return uuid string value
     * 
     * @note You should always destroy return value to avoid memory leaks
     */

    string (*getUUIDRandom)(void);
  } DGUStringEntity;

#ifdef __cplusplus
}
#endif

#endif //DGU_STRING_H
