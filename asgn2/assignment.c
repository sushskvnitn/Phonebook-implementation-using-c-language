#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodetag
{
      int mobile;
      char name[20];
      char lastname[20];
      char type[20];
      struct nodetag *left;
      struct nodetag *right;
      int height;
} personal;

typedef struct node_tag
{
      int mobile;
      char name[20];
      char lastname[20];
      char type[20];
      char email[20];
      char address[20];
      int officeno;
      struct node_tag *left;
      struct node_tag *right;
      int height;
} profectional;

int getheightpersonal(personal *root)
{
      if (root == NULL)
            return 0;
      return root->height;
}
int getheightprofectional(profectional *root)
{
      if (root == NULL)
            return 0;
      else
            return root->height;
}
int getbalancefactor(personal *root)
{
      if (root == NULL)
            return 0;
      else
            return getheightpersonal(root->left) - getheightpersonal(root->right);
}
int getbalancefactorprofectional(profectional *root)
{
      if (root == NULL)
            return 0;
      else
            return getheightprofectional(root->left) - getheightprofectional(root->right);
}

personal *newnode(int mobile, char *name, char *lastname, char *type)
{
      personal *n = (personal *)malloc(sizeof(personal));
      strcpy(n->name, name);
      strcpy(n->lastname, lastname);
      strcpy(n->type, type);
      n->mobile = mobile;
      n->left = NULL;
      n->right = NULL;
      n->height = 1;
      printf("new node created\n");
      return n;
}

int max(int a, int b)
{
      return (a > b) ? a : b;
}

profectional *pronode(int mobile, char *name, char *lastname, char *type, char *email, char *address, int officeno)
{
      profectional *n = (profectional *)malloc(sizeof(profectional));
      strcpy(n->name, name);
      strcpy(n->lastname, lastname);
      strcpy(n->type, type);
      strcpy(n->email, email);
      strcpy(n->address, address);
      n->mobile = mobile;
      n->officeno = officeno;
      n->left = NULL;
      n->right = NULL;
      n->height = 1;
      return n;
}
/* right rotate  after right rotation the root will be the left child of the right child of the root
           x
         /   \
       t1     y
             /  \
           t2    t3


*/
personal *rightrotate(personal *y)
{
      personal *x = y->left;
      personal *t2 = x->right;
      x->right = y;
      y->left = t2;
      y->height = max(getheightpersonal(y->left), getheightpersonal(y->right)) + 1;
      x->height = max(getheightpersonal(x->left), getheightpersonal(x->right)) + 1;
      return x;
}
profectional *rightrotatepro(profectional *y)
{
      profectional *x = y->left;
      profectional *t2 = x->right;
      x->right = y;
      y->left = t2;
      y->height = max(getheightprofectional(y->left), getheightprofectional(y->right)) + 1;
      x->height = max(getheightprofectional(x->left), getheightprofectional(x->right)) + 1;
      return x;
}
/* left rotate
           y
         /   \
       x     t3
    /  \
  t1    t2
*/
personal *leftrotate(personal *x)
{
      personal *y = x->right;
      personal *t2 = y->left;
      y->left = x;
      x->right = t2;
      y->height = max(getheightpersonal(y->left), getheightpersonal(y->right)) + 1;
      x->height = max(getheightpersonal(x->left), getheightpersonal(x->right)) + 1;
      return y;
}
profectional *leftrotatepro(profectional *x)
{
      profectional *y = x->right;
      profectional *t2 = y->left;
      y->left = x;
      x->right = t2;
      y->height = max(getheightprofectional(y->left), getheightprofectional(y->right)) + 1;
      x->height = max(getheightprofectional(x->left), getheightprofectional(x->right)) + 1;
      return y;
}

personal *insert(personal *root, double mobile, char *name, char *lastname, char *type)
{
      // insert like bst
      if (root == NULL)
            return newnode(mobile, name, lastname, type);
      if (mobile < root->mobile)
            root->left = insert(root->left, mobile, name, lastname, type);
      else if (mobile > root->mobile)
            root->right = insert(root->right, mobile, name, lastname, type);
      else
            return root;

      root->height = max(getheightpersonal(root->left), getheightpersonal(root->right)) + 1;
      // now balance the tree
      int balance = getbalancefactor(root);
      // left left case
      if (balance > 1 && mobile < root->left->mobile)
            return rightrotate(root);
      if (balance < -1 && mobile > root->right->mobile)
            return leftrotate(root);
      if (balance > 1 && mobile > root->left->mobile)
      {
            root->left = leftrotate(root->left);
            return rightrotate(root);
      }
      if (balance < -1 && mobile < root->right->mobile)
      {
            root->right = rightrotate(root->right);
            return leftrotate(root);
      }

      return root;
}

profectional *insertpro(profectional *root, double mobile, char *name, char *lastname, char *type, char *email, char *address, int officeno)
{
      // insert like bst
      if (root == NULL)
            return pronode(mobile, name, lastname, type, email, address, officeno);
      if (mobile < root->mobile)
            root->left = insertpro(root->left, mobile, name, lastname, type, email, address, officeno);
      else if (mobile > root->mobile)
            root->right = insertpro(root->right, mobile, name, lastname, type, email, address, officeno);
      else
            return root;

      root->height = max(getheightprofectional(root->left), getheightprofectional(root->right)) + 1;
      // now balance the tree
      int balance = getbalancefactorprofectional(root);
      // left left case
      if (balance > 1 && mobile < root->left->mobile)
            return rightrotatepro(root);
      if (balance < -1 && mobile > root->right->mobile)
            return leftrotatepro(root);
      if (balance > 1 && mobile > root->left->mobile)
      {
            root->left = leftrotatepro(root->left);
            return rightrotatepro(root);
      }
      if (balance < -1 && mobile < root->right->mobile)
      {
            root->right = rightrotatepro(root->right);
            return leftrotatepro(root);
      }

      return root;
}

void preorder(personal *root)
{
      if (root != NULL)
      {
            printf("%d %s %s %s\n", root->mobile, root->name, root->lastname, root->type);
            preorder(root->left);
            preorder(root->right);
      }
}
void preorderpro(profectional *root)
{
      if (root != NULL)
      {
            printf("%d %s %s %s %s %s %d\n", root->mobile, root->name, root->lastname, root->type, root->email, root->address, root->officeno);
            preorderpro(root->left);
            preorderpro(root->right);
      }
}

int main()
{
      personal *root = NULL;
      profectional *rootpro = NULL;
      int flag = 0;
      while (flag != 1)
      {
            printf("Enter 1 for insertion of contact \n");
            printf("Enter 2 for edit the contact \n");
            printf("Enter 3 for deletion of contact \n");
            printf("Enter 4 for search of contact \n");
            printf("Enter 5 for sort the contacts \n");
            printf("Enter 6 for display the contacts \n");
            printf("Enter 7 for range search  \n");
            printf("Enter 8 for sort the records \n");
            printf("Enter 0 for exit \n");
            int choice;
             printf("Enter the choice: ");
            scanf("%d", &choice);
           
            switch (choice)
            {
            case 1:
                  printf("enter 1 for insertion of personal contact  and enter 2 to insert profectional contact\n");
                  int choice1;
                  scanf("%d", &choice1);
                   printf("Enter the mobile number: \n");
                        int mobile=0;
                        scanf("%d", &mobile);
                        printf("Enter the name: \n");
                        char name[20]={'\0'};
                        scanf("%s", name);
                        printf("Enter the lastname: \n");
                        char lastname[20]={'\0'};
                        scanf("%s", lastname);
                        printf("Enter the type: \n");
                        char type[20]={'\0'};
                        scanf("%s", type);
                  if (choice1 == 1)
                  {
                        root = insert(root, mobile, name, lastname, type);
                  }
                  else if (choice1 == 2)
                  {
                        printf("Enter the email: \n");
                        char email[20];
                        scanf("%s", email);
                        printf("Enter the address: \n");
                        char address[20];
                        scanf("%s", address);
                        printf("Enter the office number: \n");
                        int officeno;
                        scanf("%d", &officeno);
                        rootpro = insertpro(rootpro, mobile, name, lastname, type, email, address, officeno);
                  }
                  else
                  {
                        printf("invalid choice\n");
                  }
                  break;
            case 2:
                  // edit the contact
                  break;
            case 3:
                  // delete the contact
                  break;
            case 4:
                  // search  the contact
                  break;
            case 5:
                  // sort  the contact
                  break;
            case 6:
                  // display the contact
                  printf("enter 1 for personal contact and enter 2 for profectional contact\n");
                  int choice2;
                  scanf("%d", &choice2);
                  if (choice2 == 1)
                  {
                        preorder(root);
                  }
                  else if (choice2 == 2)
                  {
                        preorderpro(rootpro);
                  }
                  else
                  {
                        printf("invalid choice\n");
                  }
                  
                  break;
            case 7:
            // range search
            case 8:
            // sort the records
            case 0:
                  flag = 1;
                  break;
            }
      }
      return 0;
}