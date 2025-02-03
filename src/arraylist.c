#include <stdlib.h>
#include <string.h>

#include "arraylist.h"

ArrayList *arraylist_new(unsigned int length)
{
    ArrayList *new_arraylist;

    new_arraylist = (ArrayList *)malloc(sizeof(ArrayList));

    if (new_arraylist == NULL)
        return NULL;

    if (length <= 0)
    {
        length = 16;
    }

    new_arraylist->length = 0;
    new_arraylist->size = length;

    new_arraylist->data = malloc(length * sizeof(ArrayListValue));

    if (new_arraylist->data == NULL)
    {
        free(new_arraylist);
        return NULL;
    }

    return new_arraylist;
}

void arraylist_free(ArrayList *arrayList)
{
    if (arrayList == NULL)
        return;

    free(arrayList->data);
    free(arrayList);
}

static int arraylist_expand(ArrayList *arraylist)
{
    ArrayListValue *data;
    unsigned int newSize;

    newSize = arraylist->size * 2;

    data = realloc(arraylist->data, newSize * sizeof(ArrayListValue));

    if (data == NULL)
        return 0;

    arraylist->data = data;
    arraylist->size = newSize;

    return 1;
}

void arraylist_clear(ArrayList *arraylist)
{
    arraylist->length = 0;
}

int arraylist_is_empty(ArrayList *arraylist)
{
    return arraylist->length == 0;
}

int arraylist_is_full(ArrayList *arraylist)
{
    return arraylist->length == arraylist->size;
}

int arraylist_length(ArrayList *arraylist)
{
    return arraylist->length;
}

int arraylist_insert(ArrayList *arraylist, unsigned int index, ArrayListValue data)
{
    if (index > arraylist->length)
        return 0;

    if (arraylist->length + 1 > arraylist->size)
    {
        if (!arraylist_expand(arraylist))
        {
            return 0;
        }
    }

    memmove(&arraylist->data[index + 1], &arraylist->data[index],
            (arraylist->length - index) * sizeof(ArrayListValue));

    arraylist->data[index] = data;
    arraylist->length++;

    return 1;
}

int arraylist_append(ArrayList *arraylist, ArrayListValue data)
{
    return arraylist_insert(arraylist, arraylist->length, data);
}

int arraylist_remove(ArrayList *arraylist, unsigned int index)
{
    if (index >= arraylist->length)
        return 0;

    memmove(&arraylist->data[index], &arraylist->data[index + 1],
            (arraylist->length - (index + 1)) * sizeof(ArrayListValue));

    arraylist->length--;

    return 1;
}

ArrayListValue arraylist_get(ArrayList *arraylist, unsigned int index)
{
    if (index > arraylist->length)
        return NULL;

    return arraylist->data[index];
}
