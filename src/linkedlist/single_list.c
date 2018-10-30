#include <stdio.h>
#include <stdbool.h>

struct single_list {
  struct single_list *next;
  int val;
};

// 头结点(哨兵)
struct single_list_head {
  struct single_list *head;
};

bool is_empty(struct single_list_head *head) {
  return head->head == NULL;
}

void dump(struct single_list_head *head) {
  struct single_list *tmp = head->head;
  int index = 0;

  while(tmp) {
    printf("[%02d]:%08d -> ", index++, tmp->val);
    tmp = tmp->next;
  }
}
// 在前驱prev之后插入元素elem
void insert(struct single_list **prev, struct single_list *elem) {
  if (!prev)
    return;
  if (*prev)
    elem->next = *prev;
  *prev = elem;
}

void insert_head(struct single_list_head *head, struct single_list *elem) {
  insert(&head->head, elem);
}

struct single_list* del(struct single_list **prev) {
  struct single_list *tmp;

  if(!prev)
    return NULL;
  tmp = *prev;
  *prev = (*prev)->next;
  tmp->next = NULL;

  return tmp;
}

void reverse(struct single_list_head *head) {

}

int main() {
  struct single_list_head head = {NULL};
  struct single_list lists[10]; // 存储链表的10个结点内容
  struct single_list **prev;
  int idx;

  for (idx = 0; idx < 10; idx++) {
    lists[idx].val = idx;
    lists[idx].next = NULL;
  }
  // 从头结点逐个插入结点
  insert_head(&head, &lists[6]);
  insert_head(&head, &lists[5]);
  insert_head(&head, &lists[4]);
  insert_head(&head, &lists[1]);
  insert_head(&head, &lists[0]);

  printf("=== insert 0, 1, 4, 5, 6\n");
  dump(&head);

}