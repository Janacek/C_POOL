#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "btree.h"

int my_strlen(const char *s)
{
  int i;
  for (i = 0; s[i]; ++i);
  return (i);
}

int get_first_semi_colomn_pos(const char *str)
{
  int i;
  for (i = 0; str[i] != '\0'; ++i)
    {
      if (str[i] == ';')
	return i;
    }
  return i;
}

char *cut_string(char *s, int startPos, int endPosition)
{
  char *new_str;

  if (endPosition - startPos <= 0)
    return NULL;
  new_str = malloc(sizeof(*new_str) * ((endPosition - startPos) + 1));
  if (new_str == NULL)
    {
      return (NULL);
    }

  int pos = 0;
  for (int i = startPos; i < endPosition; ++i, ++pos)
    {
      new_str[pos] = s[i];
    }
  new_str[pos] = '\0';
  return (new_str);
}

void init_node(btree_t **node)
{
  (*node)->left = NULL;
  (*node)->right = NULL;
}

void parse_string(btree_t *node)
{
  int semicolumn = get_first_semi_colomn_pos(node->data);

  if (semicolumn == my_strlen(node->data))
    return;
  
  btree_t *leftNode = malloc(sizeof(*leftNode));
  btree_t *rightNode = malloc(sizeof(*rightNode));
  if (leftNode)
    {
      init_node(&leftNode);
      leftNode->data = cut_string(node->data, 0, semicolumn);
      node->left = leftNode;
      if (leftNode->data != NULL)
	parse_string(leftNode);
    }
  if (rightNode)
    {
      init_node(&rightNode);
      rightNode->data = cut_string(node->data, semicolumn + 1, my_strlen(node->data));
      node->right = rightNode;
      if (rightNode->data != NULL)
	parse_string(rightNode);
    }
}

void display_btree(btree_t *node)
{
  if (node->left != NULL)
    {
      display_btree(node->left);
    }
  if (node->right != NULL)
    {
      display_btree(node->right);
    }

  if (node->left == NULL && node->right == NULL)
    printf("%s\n", node->data);
}

void free_btree(btree_t *node)
{
  if (node->left != NULL)
    free_btree(node->left);
  if (node->right != NULL)
    free_btree(node->right);
  free(node->data);
  free(node);
}

int main(int ac, char **av)
{
  btree_t *root;
  
  if (ac < 2)
    {
      return (-1);
    }

  root = malloc(sizeof(*root));
  if (root == NULL)
    {
      return (-1);
      printf("Could not allocate root\n");
    }

  root->data = strdup(av[1]);
  root->left = NULL;
  root->right = NULL;
  parse_string(root);
  display_btree(root);
  free_btree(root);
  // "ls .; cat *; cd ..
  return (0);
}
