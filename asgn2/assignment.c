#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// TODO: CASE 3 5 8 REMAINING 
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
      printf("new node created\n\n\n");
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

personal *search(personal *root, int key)
{
      if (root == NULL)
      {
            return NULL;
      }
      if (root->mobile == key)
      {
            return root;
      }
      if ( root->mobile >key)
      {
            return search(root->left, key);
      }
      return search(root->right, key);
}
profectional *searchinprofectional(profectional *root, int key)
{
      if (root == NULL)
      {
            return NULL;
      }
      if (root->mobile == key)
      {
            return root;
      }
      if ( root->mobile >key)
      {
            return searchinprofectional(root->left, key);
      }
      return searchinprofectional(root->right, key);
}

void editcontact(personal *root, int key)
{
      personal *temp = search(root, key);
      if (temp == NULL)
      {
            printf("\nContact not found\n");
            return;
      }
      printf("\nEnter new mobile no: ");
      scanf("%d", &temp->mobile);
      printf("\nEnter new name: ");
      scanf("%s", temp->name);
      printf("\nEnter new lastname: ");
      scanf("%s", temp->lastname);

      printf("\nEnter new type: ");
      scanf("%s", temp->type);
      printf("\n\nupdated contact details\n\n");
}
 void edit_professional_contact(profectional *root, int key){
      profectional *temp = searchinprofectional(root, key);
      if (temp == NULL)
      {
            printf("\nContact not found\n");
            return;
      }
      printf("\nEnter new name: ");
      scanf("%s", temp->name);
      printf("\nEnter new lastname: ");
      scanf("%s", temp->lastname);
      printf("\nEnter new type: ");
      scanf("%s", temp->type);
      printf("\nEnter new email: ");
      scanf("%s", temp->email);
      printf("\nEnter new address: ");
      scanf("%s", temp->address);
      printf("\nEnter new office no: ");
      scanf("%d", &temp->officeno);
      printf("\n\nupdated contact details\n\n");
 }


void range(personal *root, int low, int high)
{
      if (root == NULL)
      {
            return;
      }
      if (root->mobile >= low && root->mobile <= high)
      {
            
            printf("%d \t %s \t %s \t %s\n", root->mobile, root->name, root->lastname, root->type);
      }
      range(root->left, low, high);
      range(root->right, low, high);
}
void rangepro(profectional *root,int low,int high){
      if (root == NULL)
      {
            return;
      }
      if (root->mobile >= low && root->mobile <= high)
      {     
            printf("%d \t %s \t %s \t %s \t %s \t %s \t %d\n", root->mobile, root->name, root->lastname, root->type, root->email, root->address, root->officeno);
      }
      rangepro(root->left, low, high);
      rangepro(root->right, low, high); 
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
            case 1://* done
                  printf("enter 1 for insertion of personal contact  and enter 2 to insert profectional contact\n");
                  int choice1;
                  scanf("%d", &choice1);
                  printf("Enter the mobile number: \n");
                  int mobile = 0;
                  scanf("%d", &mobile);
                  printf("Enter the name: \n");
                  char name[20] = {'\0'};
                  scanf("%s", name);
                  printf("Enter the lastname: \n");
                  char lastname[20] = {'\0'};
                  scanf("%s", lastname);
                  printf("Enter the type: \n");
                  char type[20] = {'\0'};
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
            case 2://* done
                  // edit the contact
                  printf("enter 1 for edit the personal contact  and enter 2 to edit profectional contact\n");
                  int choice2;
                  scanf("%d", &choice2);
                  printf("Enter the mobile number: \n");
                  int mobile2 = 0;
                  scanf("%d", &mobile2);
                  if (choice2 == 1)
                  {
                       editcontact( root,mobile2);
                  }
                  else if (choice2 == 2)
                  {
                        edit_professional_contact(rootpro, mobile2);
                  }else{
                        printf("invalid choice\n");
                  }
                      
                  break;
            case 3:
                  // delete the contact
                  printf("enter 1 for deletion of personal contact  and enter 2 to delete profectional contact\n");
                  int choice3;
                  scanf("%d", &choice3);
                  if (choice3 == 1)
                  {
                        printf("Enter the mobile number: \n");
                        int mobile = 0;
                        scanf("%d", &mobile);
                        root = del(root, mobile);
                        printf("\ndeleted contact with number %d and name %s  \n", mobile, name);
                  }
                  else if (choice3 == 2)
                  {
                        printf("Enter the mobile number: \n");
                        int mobile = 0;
                        scanf("%d", &mobile);
                        // rootpro = delpro(rootpro, mobile);
                         printf("\ndeleted contact with number %d and name %s  \n", mobile, name);
                  }
                  else
                  {
                        printf("invalid choice\n");
                  }
                  break;
            case 4://* done  search  the contact
                 
                  printf("Enter the 1 for searching in personal node and 2 for in profectional node \n");
                  int choice4 = 0;
                  scanf("%d", &choice4);
                  printf("Enter the number to be searched in phonebook\n");
                  int key = 0;
                  scanf("%d", &key);

                  if (choice4 == 1)
                  {
                        personal *n = search(root, key);
                        if(root==NULL){
                            printf("mobile number not found in phonebook\n\n");
                            break;   
                        }
                        if (n->mobile == key)
                        {
                              printf("mobile number found in phonebook\n\n");
                              printf("\n\nfound contact details:%d %s %s %s\n\n", n->mobile, n->name, n->lastname, n->type);
                        }
                  }
                   else if(choice4 == 2)
                  {
                        profectional *n = searchinprofectional(rootpro, key);
                        if(root==NULL){
                            printf("mobile number not found in phonebook\n\n");
                            break;   
                        }
                        if (n->mobile == key)
                        {
                              printf("mobile number found in phonebook\n\n");
                              printf("\n\nfound contact details:%d %s %s %s %s %s %d\n\n", n->mobile, n->name, n->lastname, n->type, n->email, n->address, n->officeno);
                        }    
                  }else{
                        printf("invalid choice \n\n");
                  }
                  break;
            case 5:
                  // sort  the contact
                  break;
            case 6:
                  // display the contact
                  printf("enter 1 for personal contact and enter 2 for profectional contact\n");
                  int choice6;
                  scanf("%d", &choice6);
                  if (choice6 == 1)
                  {
                        preorder(root);
                  }
                  else if (choice6 == 2)
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
                  printf("enter 1 for personal contact and enter 2 for profectional contact\n");
                  int choice7;
                  scanf("%d", &choice7);
                  if (choice7 == 1)
                  {
                        printf("Enter the lower limit of contact: \n");
                        int lower = 0;
                        scanf("%d", &lower);
                        printf("Enter the upper limit of contact: \n");
                        int upper = 0;
                        scanf("%d", &upper);
                        printf("mobile \t name \t lastname \t type\n");
                        range(root, lower, upper);

                  }
                  else if (choice7 == 2)
                  {
                        printf("Enter the lower limit of contact: \n");
                        int lower = 0;
                        scanf("%d", &lower);
                        printf("Enter the upper limit of contact: \n");
                        int upper = 0;
                        scanf("%d", &upper);
                        printf("mobile \t name \t lastname \t type \t email \t address \t office no\n");
                        rangepro(rootpro, lower, upper);
                  }
                  else
                  {
                        printf("invalid choice\n");
                  }
                  break;
            case 8:
            // sort the records
            case 0:
                  flag = 1;
                  break;
            }
      }
      return 0;
}