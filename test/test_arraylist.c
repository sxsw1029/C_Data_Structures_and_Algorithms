#include <stdio.h>
#include <assert.h>

#include "arraylist.h"

void test_arraylist_new_and_free()
{
    ArrayList *arraylist;

    arraylist = arraylist_new(0);
    assert(arraylist != NULL);
    arraylist_free(arraylist);

    arraylist = arraylist_new(10);
    assert(arraylist != NULL);
    arraylist_free(arraylist);

    printf("test_arraylist_new_and_free passed!\n");
}

void test_arraylist_insert_and_get()
{
    ArrayList *arraylist;

    arraylist = arraylist_new(0);

    assert(arraylist->size == 16);
    assert(arraylist_insert(arraylist, 17, (ArrayListValue) "X") == 0);
    assert(arraylist->size == 16);

    assert(arraylist_insert(arraylist, 0, (ArrayListValue) "A") != 0);
    assert(arraylist_length(arraylist) == 1);

    assert(arraylist_insert(arraylist, 1, (ArrayListValue) "B") != 0);
    assert(arraylist_length(arraylist) == 2);

    assert(arraylist_insert(arraylist, 1, (ArrayListValue) "C") != 0);
    assert(arraylist_length(arraylist) == 3);

    assert(arraylist_get(arraylist, 0) == (ArrayListValue) "A");
    assert(arraylist_get(arraylist, 1) == (ArrayListValue) "C");
    assert(arraylist_get(arraylist, 2) == (ArrayListValue) "B");

    arraylist_free(arraylist);

    printf("test_arraylist_insert_and_get passed!\n");
}

void test_arraylist_append()
{
    ArrayList *arraylist;

    arraylist = arraylist_new(0);

    assert(arraylist_length(arraylist) == 0);

    assert(arraylist_append(arraylist, (ArrayListValue) "A") != 0);
    assert(arraylist_length(arraylist) == 1);

    assert(arraylist_append(arraylist, (ArrayListValue) "B") != 0);
    assert(arraylist_length(arraylist) == 2);

    assert(arraylist_append(arraylist, (ArrayListValue) "C") != 0);
    assert(arraylist_length(arraylist) == 3);

    assert(arraylist_get(arraylist, 0) == (ArrayListValue) "A");
    assert(arraylist_get(arraylist, 1) == (ArrayListValue) "B");
    assert(arraylist_get(arraylist, 2) == (ArrayListValue) "C");

    arraylist_free(arraylist);

    printf("test_arraylist_append passed!\n");
}

void test_arraylist_remove()
{
    ArrayList *arraylist;

    arraylist = arraylist_new(0);

    arraylist_append(arraylist, (ArrayListValue) "A");
    arraylist_append(arraylist, (ArrayListValue) "B");
    arraylist_append(arraylist, (ArrayListValue) "C");

    assert(arraylist_remove(arraylist, 1) != 0);
    assert(arraylist_length(arraylist) == 2);

    assert(arraylist_get(arraylist, 0) == (ArrayListValue) "A");
    assert(arraylist_get(arraylist, 1) == (ArrayListValue) "C");

    assert(arraylist_remove(arraylist, 2) == 0);

    arraylist_free(arraylist);

    printf("test_arraylist_remove passed!\n");
}

void test_arraylist_clear()
{
    ArrayList *arraylist;

    arraylist = arraylist_new(0);

    assert(arraylist_length(arraylist) == 0);
    assert(arraylist_is_empty(arraylist) != 0);

    arraylist_append(arraylist, (ArrayListValue) "A");
    arraylist_append(arraylist, (ArrayListValue) "B");
    arraylist_append(arraylist, (ArrayListValue) "C");

    arraylist_clear(arraylist);

    assert(arraylist_length(arraylist) == 0);
    assert(arraylist_is_empty(arraylist) != 0);

    arraylist_free(arraylist);

    printf("test_arraylist_clear passed!\n");
}

void test_arraylist_is_full_and_empty()
{
    ArrayList *arraylist;

    arraylist = arraylist_new(3);

    assert(arraylist_is_empty(arraylist) != 0);

    arraylist_append(arraylist, (ArrayListValue) "A");
    assert(arraylist_is_empty(arraylist) == 0);
    assert(arraylist_is_full(arraylist) == 0);

    arraylist_append(arraylist, (ArrayListValue) "B");
    assert(arraylist_is_empty(arraylist) == 0);
    assert(arraylist_is_full(arraylist) == 0);

    arraylist_append(arraylist, (ArrayListValue) "C");
    assert(arraylist_is_empty(arraylist) == 0);
    assert(arraylist_is_full(arraylist) != 0);

    arraylist_free(arraylist);

    printf("test_arraylist_is_full_and_empty passed!\n");
}

int main()
{
    test_arraylist_new_and_free();
    test_arraylist_insert_and_get();
    test_arraylist_append();
    test_arraylist_remove();
    test_arraylist_clear();
    test_arraylist_is_full_and_empty();

    printf("\nAll tests passed!\n");

    return 0;
}
