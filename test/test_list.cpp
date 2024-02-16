#include <cstdlib>
#include <cstring>
#include <gtest/gtest.h>
#include <stdbool.h>

extern "C" {
    #include "Lists/List.h"
}


TEST(List_constructor, should_initialize_list_with_array) {
	int array[] = {8, 10, 15, 11, 35, 40};

    List *list = newList(array, 6);

    char *strList = list->toString(list);

    EXPECT_EQ(strcmp(strList, "[8, 10, 15, 11, 35, 40]"), 0);

    free(list);
    free(strList);
}

TEST(List_get, should_obtain_element_at_possition) {
	int array[] = {8, 10, 15, 11, 35, 40};

    List *list = newList(array, 6);

    EXPECT_EQ(list->get(list, 3), 11);
    EXPECT_EQ(list->get(list, 5), 40);

    free(list);
}


TEST(List_prepend, Should_Add_element_at_beginning) {
	int array[] = {8, 10, 15, 11, 35, 40};

    List *list = newList(array, 6);

    list->prepend(list, 20);

    char *stringList = list->toString(list);

    EXPECT_EQ(strcmp(stringList, "[20, 8, 10, 15, 11, 35, 40]"), 0);

    free(stringList);
}

TEST(list_insertAt, Should_Add_element_at_position) {
	int array[] = {8, 10, 15, 11, 35, 40};

    List *list = newList(array, 6);
    char *stringList;

    list->insertAt(list, 20, 2);
    stringList = list->toString(list);
    EXPECT_EQ(strcmp(stringList, "[8, 10, 20, 15, 11, 35, 40]"), 0);

    list->insertAt(list, 100, 0);
    stringList = list->toString(list);
    EXPECT_EQ(strcmp(stringList, "[100, 8, 10, 20, 15, 11, 35, 40]"), 0);

    list->insertAt(list, 50, 7);
    stringList = list->toString(list);
    EXPECT_EQ(strcmp(stringList,"[100, 8, 10, 20, 15, 11, 35, 50, 40]"), 0);

    free(list);
    free(stringList);
}

TEST(list_removeAt, Should_delete_element_at_position) {
	int array[] = {8, 10, 15, 11, 35, 40};

    List *list = newList(array, 6);
    char *strList;

    list->removeAt(list, 2);
    strList = list->toString(list);
    EXPECT_EQ(strcmp(strList, "[8, 10, 11, 35, 40]"), 0);

    list->removeAt(list, 0);
    strList = list->toString(list);
    EXPECT_EQ(strcmp(strList, "[10, 11, 35, 40]"), 0);

    list->removeAt(list, 3);
    strList = list->toString(list);
    EXPECT_EQ(strcmp(strList, "[10, 11, 35]"), 0);

    free(list);
    free(strList);
}
