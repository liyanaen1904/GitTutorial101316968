#ifndef STACKARRAY_H
#define STACKARRAY_H

#include "defs.h"
#include "TextArea.h"
#include <string>
#include <X11/Xlib.h>

using namespace std;

class StackArrays{
	public:
        StackArrays();
        ~StackArrays();

        //Getter functions
        TextArea* getObjectArray();
        TextArea** getPointerArray();

        TextArea* getPointer(int index);
        TextArea& getReference(int index);

        void addTextArea(TextArea& ta);
    private:
        TextArea objects[MAX_ARRAY];
        TextArea* pointers[MAX_ARRAY];
        int num_textareas;
};

#endif