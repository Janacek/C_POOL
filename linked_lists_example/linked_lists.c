#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_lists.h"

list_t *create_new_element(const char *name, int age)
{
  list_t *elem = NULL;

  elem = malloc(sizeof(elem));
  if (elem == NULL)
    return NULL;
  elem->name = strdup(name);
  elem->age = age;
  elem->next = NULL;
  return (elem);
}

void add_elem_to_list(list_t **list, list_t *elem)
{
  list_t *tmp = *list;

  *list = elem;
  elem->next = tmp;
}

void show_linked_list(list_t *list)
{
  while (list != NULL)
    {
      printf("%s, %d\n", list->name, list->age);
      list = list->next;
    }
}

void delete_first_elem(list_t **list)
{
  list_t *tmp = *list;

  if (*list != NULL)
    {
      (*list) = (*list)->next;
    }

  free(tmp);
}

int main(void)
{
  list_t *list = NULL;

  list_t *thomas_elem = create_new_element("Thomas", 25);
  list_t *new_elem = create_new_element("Test", 42);
  list_t *new_elem2 = create_new_element("Test2", 422);
  add_elem_to_list(&list, thomas_elem);
  add_elem_to_list(&list, new_elem);
  add_elem_to_list(&list, new_elem2);

  show_linked_list(list);

  delete_first_elem(&list);
  delete_first_elem(&list);
  delete_first_elem(&list);
  delete_first_elem(&list);

  printf("\n");
  show_linked_list(list);
}
