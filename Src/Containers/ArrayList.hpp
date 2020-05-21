#pragma once
#include <stdint.h>
namespace Eros
{
template<typename T>
class ArrayList
{
public:
    ArrayList<T>()
    {
    }

    ArrayList<T>(uint32_t initialSize) : size(initialSize)
    {
        resizeCadence = 1.0f;
    }

    /* initialSize of array, percentage of the prev. size array will expand to when full */ 
    ArrayList<T>(uint32_t initialSize, float resizeCadence) : size(initialSize), resizeCadence(resizeCadence)
    {

    }

    ~ArrayList() 
    {
        delete data;
    }

    T& operator[](uint32_t index)
    {
       return data[index]; 
    }

    void PushBack(const T& element)
    {

    }



private:



    float resizeCadence;
    uint32_t size;
    T * data;
};
}