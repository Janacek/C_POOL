#ifndef BTREE_H_
#define BTREE_H_

struct btree_s
{
  char *data;

  struct btree_s *left;
  struct btree_s *right;
};

typedef struct btree_s btree_t;

#endif
