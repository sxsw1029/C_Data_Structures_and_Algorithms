/**
 * @file arraylist.h
 *
 * @brief 顺序表
 */

#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

typedef void *ArrayListValue;

typedef struct _ArrayList ArrayList;

struct _ArrayList
{
    /* 顺序表元素 */
    ArrayListValue *data;

    /* 顺序表大小 */
    unsigned int length;

    /* 顺序表容量 */
    unsigned int size;
};

/**
 * @brief 构造一个空的顺序表
 *
 * @param length 顺序表存储容量
 *
 * @return 返回新创建的顺序表，如果内存分配失败，返回 NULL
 */
ArrayList *arraylist_new(unsigned int length);

/**
 * @brief 销毁已有的顺序表
 *
 * @param arrayList 需要销毁的顺序表
 */
void arraylist_free(ArrayList *arrayList);

/**
 * @brief 清空已有的顺序表元素
 *
 * @param arrayList 需要清空的顺序表
 */
void arraylist_clear(ArrayList *arraylist);

/**
 * @brief 检查顺序表大小是否为空
 *
 * @param arrayList 需要检查的顺序表
 *
 * @return 如果为空，返回非 0 值，
 *         如果不为空，返回 0
 */
int arraylist_is_empty(ArrayList *arraylist);

/**
 * @brief 检查顺序表容量是否已满
 *
 * @param arrayList 需要检查的顺序表
 *
 * @return 如果已满，返回非 0 值，
 *         如果没有满，返回 0
 */
int arraylist_is_full(ArrayList *arraylist);

/**
 * @brief 获取顺序表当前大小
 *
 * @param arrayList 需要获取大小的顺序表
 *
 * @return 返回顺序表大小
 */
int arraylist_length(ArrayList *arraylist);

/**
 * @brief 向顺序表指定的位置插入一个元素
 *
 * @param arrayList 需要插入元素的顺序表
 * @param index 需要插入的位置
 * @param data 需要插入的元素
 * 
 * @return 如果插入成功，返回非 0 值，
 *         如果插入失败，返回 0
 */
int arraylist_insert(ArrayList *arraylist, unsigned int index, ArrayListValue data);

/**
 * @brief 向顺序表末尾追加一个元素
 *
 * @param arrayList 需要插入元素的顺序表
 * @param data 需要插入的元素
 * 
 * @return 如果插入成功，返回非 0 值，
 *         如果插入失败，返回 0
 */
int arraylist_append(ArrayList *arraylist, ArrayListValue data);

/**
 * @brief 删除顺序表中指定位置的元素
 *
 * @param arrayList 需要删除元素的顺序表
 * @param index 需要删除元素的位置
 * 
 * @return 如果删除成功，返回非 0 值，
 *         如果删除失败，返回 0
 */
int arraylist_remove(ArrayList *arraylist, unsigned int index);

/**
 * @brief 获取顺序表中指定位置的元素
 *
 * @param arrayList 需要获取元素的顺序表
 * @param index 需要获取元素的位置
 * 
 * @return 返回获取的元素
 */
ArrayListValue arraylist_get(ArrayList *arraylist, unsigned int index);

#endif
