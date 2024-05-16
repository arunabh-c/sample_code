#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node *next;
  struct Node *prev;
  int key;
  int val;
} ll;

int cap, curr_sz;
ll *last_node, *first_node;

ll *
new_node ()
{
  ll *x = (ll *) malloc (24);
  x->prev = NULL;
  x->next = NULL;
  x->key = 0;
  x->val = 0;
  return x;
}

void
delete_first_node ()
{
  ll *x = first_node->next;
  first_node = x;
  first_node->prev = NULL;
}

int
find_delete_key_node (int k)
{
  int ans = -1;

  if (first_node != NULL)
	{
	  ll *x = first_node;
	  while ((x->key != k) && (x->next != NULL))
		x = x->next;
	  if (x->key == k)
		{
		  ans = x->val;
		  ll *y = x->prev;
		  ll *z = x->next;
		  if (y != NULL)
			y->next = z;
		  else
			first_node = z;
		  if (z != NULL)
			z->prev = y;
		  else
			last_node = y;
		  --curr_sz;
		}
	}
  return ans;
}

void
add_node (int k, int v)
{
  find_delete_key_node (k);
  if (curr_sz < cap)
	++curr_sz;
  else
	delete_first_node ();
  ll *x = new_node ();
  x->key = k;
  x->val = v;
  if (last_node != NULL)
	{
	  last_node->next = x;
	  x->prev = last_node;
	}
  last_node = x;
  if (first_node == NULL)
	first_node = x;
}

void
print_nodes ()
{
  ll *x = first_node;
  while (x != NULL)
	{
	  printf ("%d:%d->", x->key, x->val);
	  x = x->next;
	}
  printf ("\n");
}

int
get_val (int k)
{
  int ans = find_delete_key_node (k);
  if (ans != -1)
	add_node (k, ans);
  return ans;
}

void
set_key_val (int k, int v)
{
  add_node (k, v);
}

void
start_lru_cache (int c)
{
  cap = c, curr_sz = 0;
  first_node = NULL, last_node = NULL;
}

int
main ()
{
  start_lru_cache (5);
  set_key_val (5, 50);
  print_nodes ();
  set_key_val (6, 60);
  print_nodes ();
  set_key_val (7, 70);

  print_nodes ();

  set_key_val (6, 66);
  print_nodes ();
  get_val (6);
  print_nodes ();
  set_key_val (8, 80);
  print_nodes ();
  set_key_val (9, 90);			//<---
  print_nodes ();
  set_key_val (4, 40);
  print_nodes ();
  set_key_val (5, 55);
  print_nodes ();
  return 0;
}
