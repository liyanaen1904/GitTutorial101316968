#include <iostream>
#include "StackArrays.h"

using namespace std;

StackArrays::StackArrays(){
    num_textareas = 0;
}

StackArrays::~StackArrays(){
    for (int i = 0; i < num_textareas; i++){
        delete pointers[i];
    }
}

//Getter functions
TextArea* StackArrays::getObjectArray(){
    return objects;
}

TextArea** StackArrays::getPointerArray(){
    return pointers;
}

TextArea* StackArrays::getPointer(int index){
    if (index < 0 || index >= num_textareas){
        return nullptr;
    } 
    return pointers[index];
}

TextArea& StackArrays::getReference(int index){
    return objects[index];
}

void StackArrays::addTextArea(TextArea& ta){
    if (num_textareas >= MAX_ARRAY){
        return;
    }
    objects[num_textareas] = ta;
    pointers[num_textareas] = new TextArea(ta);
    num_textareas++;
}