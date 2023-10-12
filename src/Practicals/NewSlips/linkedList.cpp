#include "likedlist.h"
int main()
{
  struct Node *l1=createNode(5);
  printList(l1);
  int pos;
  printf("Enter bhau tuzi posito;");
  scanf("%d",&pos);
  l1=insertAtPos(l1,pos);
  printf("List after insertion \n");
  printList(l1);
  return 0;
}
