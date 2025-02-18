#ifndef TAARRAY_H
#define TAARRAY_H

#include "defs.h"
#include "TextArea.h"
#include <string>
#include <X11/Xlib.h>

using namespace std;

class TAArray{
	public:
        TAArray();
        ~TAArray();

        //Getter functions
        //TextArea* getObjectArray();
        TextArea** getPointerArray();

        TextArea* get(const string& id) const;
        TextArea* get(int index) const;
        int getSize() const;

        //TextArea& getReference(int index);

        bool add(TextArea* ta);
        bool add(TextArea* ta, int index);
        TextArea* remove(const string& id);
        TextArea* remove(int index);


    private:
        //TextArea* objects;
        TextArea** elements;
        int num_textareas;
};

#endif