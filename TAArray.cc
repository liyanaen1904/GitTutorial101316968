#include <iostream>
#include "TAArray.h"

using namespace std;

TAArray::TAArray(){
    num_textareas = 0;
    //objects = new TextArea[MAX_ARRAY];
    elements = new TextArea*[MAX_COMPONENTS];
}

TAArray::~TAArray(){
    // for (int i = 0; i < num_textareas; i++){
    //     delete elements[i];
    // }
    delete [] elements;
    //delete [] objects;
}

//Getter functions
// TextArea* TAArray::getObjectArray(){
//     return objects;
// }

TextArea** TAArray::getPointerArray(){
    return elements;
}

int TAArray::getSize() const{
    return num_textareas;
}

TextArea* TAArray::get(int index) const{
    if (index < 0 || index >= num_textareas){
        return nullptr;
    } 
    return elements[index];
}

TextArea* TAArray::get(const string& id) const{
    for (int i = 0; i < num_textareas; i++){
        if (elements[i]->getText() == id){
            return elements[i];
        }
    }
    return nullptr;
}

// TextArea& HeapArrays::getReference(int index){
//     return objects[index];
// }

bool TAArray::add(TextArea* ta){
    if (num_textareas >= MAX_COMPONENTS){
        return false;
    }
    //objects[num_textareas] = ta;
    elements[num_textareas] = ta;
    num_textareas++;
    return true;
}

bool TAArray::add(TextArea* ta,int index){
    if (num_textareas >= MAX_COMPONENTS){
        return false;
    }
    if (index < 0 || index > num_textareas){
        return false;
    }
    for (int i = num_textareas; i > index; i--){
        elements[i] = elements[i - 1];
    }
    elements[index] = ta;
    num_textareas++;
    return true;
}

TextArea* TAArray::remove(const string& id){

	int index = 0;
    while (id != elements[index]->getText() && index < num_textareas){
        ++index;
    }
    return remove(index);
}

TextArea* TAArray::remove(int index){
    if (index < 0 || index >= num_textareas){
        return nullptr;
    }

    
    TextArea* removed = elements[index];
    for (int i = index; i < num_textareas - 1; i++){
        elements[i] = elements[i+1];
    }
    num_textareas--;
    return removed;
}