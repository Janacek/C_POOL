#ifndef LINKED_LISTS_H_
#define LINKED_LISTS_H_

typedef struct linked_list
{
  char *name;
  int age;

  struct linked_list *next;
} list_t;

#endif
