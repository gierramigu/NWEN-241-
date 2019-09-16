/**
 * editor2.hh
 */


#include <string.h>
#include <iostream>
#include <string>

namespace editor2 {

    class EditorUtilities {
    public:
      static int countWords(const char *editing_buffer, int sizeOfBuffer);
      static int searchMultipleNoCase(const char *editing_buffer, int sizeOfBuffer);
    };
  }
