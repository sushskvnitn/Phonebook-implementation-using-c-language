#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
typedef struct nodetag
{
      long long unsigned int mobile;
      char name[20];
      char lastname[20];
      char type[20];
      struct nodetag *left;
      struct nodetag *right;
      int height;
} personal;
typedef struct node_tag
{
      long long unsigned int mobile;
      char name[20];
      char lastname[20];
      char type[20];
      char email[20];
      char address[20];
      long long unsigned int officeno;
      struct node_tag *left;
      struct node_tag *right;
      long long unsigned int height;
} professional;
int getheightpersonal(personal *root);
int getheightprofessional(professional *root);
int getbalancefactor(personal *root);
int getbalancefactorprofessional(professional *root);
int max(int a, int b);
professional *pronode(long long unsigned int mobile, char *name, char *lastname, char *type, char *email, char *address, long long unsigned int officeno);
professional *rightrotatepro(professional *y);
professional *leftrotatepro(professional *x);
professional *insertpro(professional *root, long long unsigned int mobile, char *name, char *lastname, char *type, char *email, char *address, long long unsigned int officeno, FILE *pro);
professional *searchinprofessional(professional *root, long long unsigned int key);
professional *minValueNodepro(professional *node);
professional *deleteNodepro(professional *root, long long unsigned int key,FILE *fp1);
void decendingsorted(personal *root);
void decendingsortedpro(professional *root);
void editcontact(personal *root, long long unsigned int key, FILE *fp);
void edit_professional_contact(professional *rootpro, long long unsigned int key, FILE *fp1);
void range(personal *root, long long unsigned int low, long long unsigned int high);
void rangepro(professional *root, long long unsigned int low, long long unsigned int high);
void printdatainfiles(FILE *fptr);
void printdatainfilesinprof(FILE *fptr);
void inorder(personal *root);
void inorderpro(professional *root);
personal *insert_phone_name(personal *root, long long unsigned int mobile, char *name, char *lastname, char *type);
personal *LR(personal *T);
personal *RL(personal *T);
personal *rotateleftt(personal *x);
personal *rotaterightt(personal *x);
personal *insert(personal *root, long long unsigned int mobile, char *name, char *lastname, char *type, FILE *fp1);
personal *newnode(long long unsigned int mobile, char *name, char *lastname, char *type);
personal *search(personal *root, long long unsigned int key);
void searchwithname(personal *root, char *key, int *flag);
void searchwithnamepro(professional *root, char *key, int *flag);
personal *minValueNode(personal *node);
personal *deleteNode(personal *root, long long unsigned int key, FILE *fp1);
personal *inorder_sorted(personal *root, personal *newroot);
professional *inorder_sortedpro(professional *root, professional *newroot);
int main()
{
      personal *root = NULL;
      professional *rootpro = NULL;
      personal *newroot = NULL;
      professional *newrootpro = NULL;
      printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>welcome to phonebook - BT20CSE067 <<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
      FILE *fp1 = NULL;
      fp1 = fopen("personal.txt", "a+");
      time_t t;
      time(&t);
      fprintf(fp1, "personal phone contact list--->>Date : %s ", ctime(&t));
      fclose(fp1);
      fp1 = fopen("professional.txt", "a+");
      fprintf(fp1, "professional phone contact list--->>Date : %s  ", ctime(&t));
      fclose(fp1);
      int flag = 0;
      while (flag != 1)
      {
            printf("\n...................................................................................................\n");
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
            case 1: //* done
                  printf("enter 1 for insertion of personal contact  and enter 2 to insert professional contact\n");
                  int choice1;
                  scanf("%d", &choice1);
                  printf("Enter the mobile number: \n");
                  long long unsigned int mobile = 0;
                  scanf("%llu", &mobile);
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
                  {     personal *n = search(root, mobile);
                        if (n != NULL)
                        { 
                              printf("\n>>>>>>contact already exists\n\n");
                              break;
                        }
                        root = insert(root, mobile, name, lastname, type, fp1);
                        printf("\n");
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
                        long long unsigned int officeno;
                        scanf("%llu", &officeno);

                        professional *n = searchinprofessional(rootpro, mobile);
                        if (n != NULL)
                        {
                              printf("\n>>>>>>contact already exists\n\n");
                              break;
                        }
                        rootpro = insertpro(rootpro, mobile, name, lastname, type, email, address, officeno, fp1);
                  }
                  else
                  {
                        printf("\n>>>>>>invalid choice\n");
                  }
                  break;
            case 2: //* done
                  // edit the contact
                  printf("enter 1 for edit the personal contact  and enter 2 to edit professional contact\n");
                  int choice2;
                  scanf("%d", &choice2);
                  printf("Enter the mobile number: \n");
                  long long unsigned int mobile2 = 0;
                  scanf("%llu", &mobile2);
                  if (choice2 == 1)
                  {
                        editcontact(root, mobile2, fp1);
                  }
                  else if (choice2 == 2)
                  {
                        edit_professional_contact(rootpro, mobile2, fp1);
                  }
                  else
                  {
                        printf("\n>>>>>>invalid choice\n");
                  }
                  break;
            case 3: //* done
                  // delete the contact
                  printf("enter 1 for deletion of personal contact  and enter 2 to delete professional contact\n");
                  int choice3;
                  scanf("%d", &choice3);
                  if (choice3 == 1)
                  {

                        printf("Enter the mobile number: \n");
                        long long unsigned int mobile3 = 0;
                        scanf("%llu", &mobile3);
                        personal *n = search(root, mobile3);
                        if (n == NULL)
                        {
                              printf("\n>>>>>>contact does not exist\n\n");
                              break;
                        }

                        root = deleteNode(root, mobile3, fp1);
                        printf("\n>>>>>>contact deleted\n\n");
                        break;
                  }
                  else if (choice3 == 2)
                  {
                        printf("Enter the mobile number: \n");
                        long long unsigned int mobile3 = 0;
                        scanf("%llu", &mobile3);
                        professional *n = searchinprofessional(rootpro, mobile3);
                        if (n == NULL)
                        {
                              printf("\n>>>>>>contact does not exist\n\n");
                              break;
                        }
                        rootpro = deleteNodepro(rootpro, mobile3,fp1);
                        printf("\n>>>>>>contact deleted\n\n");

                        break;
                  }
                  else
                  {
                        printf("\n>>>>>>invalid choice\n");
                  }
                  break;
            case 4: //* done  search  the contact

                  printf("Enter the 1 for searching in personal node and 2 for in professional node \n");
                  int choice4 = 0;
                  scanf("%d", &choice4);
                  printf("Enter 1 to search by mobile number and 2 to search by name \n");
                  int ch = 0;
                  scanf("%d", &ch);
                  if (ch == 1)
                  {
                        printf("Enter the number to be searched in phonebook\n");
                        long long unsigned int key = 0;
                        scanf("%llu", &key);

                        if (choice4 == 1)
                        {
                              personal *n = search(root, key);
                              if (n == NULL)
                              {
                                    printf("\n>>>>>>mobile number not found in phonebook\n\n");
                                    break;
                              }
                              if (n->mobile == key)
                              {
                                    printf("\n>>>>>>mobile number found in phonebook\n\n");
                                    printf("\n\nfound contact details:%llu %s %s %s\n\n", n->mobile, n->name, n->lastname, n->type);
                              }
                        }
                        else if (choice4 == 2)
                        {
                              professional *n = searchinprofessional(rootpro, key);
                              if (n == NULL)
                              {
                                    printf("\n>>>>>>mobile number not found in phonebook\n\n");
                                    break;
                              }
                              if (n->mobile == key)
                              {
                                    printf("\n>>>>>>mobile number found in phonebook\n\n");
                                    printf("\n\nfound contact details:%llu %s %s %s %s %s %llu\n\n", n->mobile, n->name, n->lastname, n->type, n->email, n->address, n->officeno);
                              }
                        }
                        else
                        {
                              printf("\n>>>>>>invalid choice \n\n");
                        }
                  }
                  else
                  {
                        printf("Enter the name to be searched in phonebook\n");
                        char key[20] = {'\0'};
                        scanf("%s", key);
                        if (choice4 == 1)
                        {
                              int flag = 0;
                              searchwithname(root, key, &flag);
                              if (flag == 0)
                              {
                                    printf("\n>>>>>>name not found in phonebook\n\n");
                                    break;
                              }
                        }
                        else if (choice4 == 2)
                        {
                              int flag = 0;
                              searchwithnamepro(rootpro, key, &flag);
                              if (flag == 0)
                              {
                                    printf("\n>>>>>>name not found in phonebook\n\n");
                                    break;
                              }
                        }
                        else
                        {
                              printf("\n>>>>>>invalid choice \n\n");
                        }
                  }

                  break;
            case 5:
                  // sort  the contact
                  printf("enter 1 for sorting in personal node and 2 for in professional node \n");
                  int choice5 = 0;
                  scanf("%d", &choice5);
                  if (choice5 == 1)
                  {
                        printf("Enter the 1 for sorting in ascending order and 2 for descending order \n");
                        int choice6 = 0;
                        scanf("%d", &choice6);
                        if (choice6 == 1)
                        {
                              printf("Mobile \t NAME \t Lastname \t type \n");
                              inorder(root);
                        }
                        else if (choice6 == 2)
                        {
                              printf("Mobile \t NAME \t Lastname \t type \n");
                              decendingsorted(root);
                        }
                        else
                        {
                              printf("\n>>>>>>invalid choice \n\n");
                        }
                  }
                  else if (choice5 == 2)
                  {
                        printf("Enter the 1 for sorting in ascending order and 2 for descending order \n");
                        int choice6 = 0;
                        scanf("%d", &choice6);
                        if (choice6 == 1)
                        {
                              inorderpro(rootpro);
                        }
                        else if (choice6 == 2)
                        {
                              decendingsortedpro(rootpro);
                        }
                        else
                        {
                              printf("\n>>>>>>invalid choice \n\n");
                        }
                  }
                  else
                  {
                        printf("\n>>>>>>invalid choice \n\n");
                  }
                  break;
            case 6: //* done
                  // display the contact
                  printf("\nenter 1 for recently added personal contact and \n enter 2  for recently added professional contact\n enter 3 for display complete personal contact list \n enter 4 for display all professional contact\n");
                  int choice6;
                  scanf("%d", &choice6);
                  if (choice6 == 1)
                  {
                        printf("\n\n");
                        printf("Mobile \t NAME \t Lastname \t type \n");
                        inorder(root);
                        printf("\n\n");
                  }
                  else if (choice6 == 2)
                  {
                        printf("\n\n");
                        printf("Mobile \t NAME \t Lastname \t type \t email \t address \t office number \n");
                        inorderpro(rootpro);
                        printf("\n\n");
                  }
                  else if (choice6 == 3)
                  {
                        printf("Mobile \t NAME \t Lastname \t type \n");
                        printdatainfiles(fp1);
                  }
                  else if (choice6 == 4)
                  {
                        printf("Mobile \t NAME \t Lastname \t type \t email\t address \t office no\n");
                        printdatainfilesinprof(fp1);
                  }

                  else
                  {
                        printf("\n>>>>>>invalid choice\n");
                  }

                  break;
            case 7:
                  // range search
                  printf("enter 1 for personal contact and enter 2 for professional contact\n");
                  int choice7;
                  scanf("%d", &choice7);
                  if (choice7 == 1)
                  {
                        printf("Enter the lower limit of contact number: \n");
                        long long unsigned int lower = 0;
                        scanf("%llu", &lower);
                        printf("Enter the upper limit of contact number: \n");
                        long long unsigned int upper = 0;
                        scanf("%llu", &upper);
                        if (lower > upper)
                        {
                              printf("\n>>>>>>invalid operation : lower limit cannot be greater than upper limit of contact\n");
                              break;
                        }
                        printf("mobile \t name \t lastname \t type\n");
                        range(root, lower, upper);
                  }
                  else if (choice7 == 2)
                  {
                        printf("Enter the lower limit of contact: \n");
                        long long unsigned int lower = 0;
                        scanf("%llu", &lower);
                        printf("Enter the upper limit of contact: \n");
                        long long unsigned int upper = 0;
                        scanf("%llu", &upper);
                        if (lower > upper)
                        {
                              printf("\n>>>>>>invalid operation : lower limit cannot be greater than upper limit of contact\n");
                              break;
                        }
                        printf("mobile \t name \t lastname \t type \t email \t address \t office no\n");
                        rangepro(rootpro, lower, upper);
                  }
                  else
                  {
                        printf("\n>>>>>>invalid choice\n");
                  }
                  break;
            case 8: // sort the records with names
                  printf("enter 1 for sorting in personal node and 2 for in professional node \n");
                  int choice8 = 0;
                  scanf("%d", &choice8);
                  if (choice8 == 1)
                  {
                        newroot = inorder_sorted(root, newroot);
                        printf("\n\nmobile \t name \t lastname \t type\n");
                        inorder(newroot);
                        newroot = NULL;
                  }
                  else if (choice8 == 2)
                  {
                        newrootpro = inorder_sortedpro(rootpro, newrootpro);
                        printf("\n\nmobile \t name \t lastname \t type \t email \t address \t office no\n");
                        inorderpro(newrootpro);
                        newrootpro = NULL;
                  }
                  else
                  {
                        printf("\n>>>>>>invalid choice\n");
                  }

                  break;
            case 0:
            {
                  flag = 1;
                  printf("\n>>>>>>program terminated\n");

                  break;
            }
            default:
                  printf("\n\n>>>>>>invalid choice\n");
                  break;
            }
      }
      free(root);
      free(rootpro);
      free(newroot);
      free(newrootpro);
      printf(">>>>>deleted the personal and professional contact tree generated\n");
      printf("thank you for using the program\n");
      printf("\n>>>>>>>>>>>> BT20CSE067 SUSHANT SANJIV KOGURWAR\n");
      return 0;
}

int getheightpersonal(personal *root)
{
      if (root == NULL)
            return 0;
      return root->height;
}
int getheightprofessional(professional *root)
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
int getbalancefactorprofessional(professional *root)
{
      if (root == NULL)
            return 0;
      else
            return getheightprofessional(root->left) - getheightprofessional(root->right);
}
personal *newnode(long long unsigned int mobile, char *name, char *lastname, char *type)
{
      personal *n = (personal *)malloc(sizeof(personal));
      strcpy(n->name, name);
      strcpy(n->lastname, lastname);
      strcpy(n->type, type);
      n->mobile = 0;
      n->mobile = mobile;
      n->left = NULL;
      n->right = NULL;
      n->height = 1;
      return n;
}
int max(int a, int b)
{
      return (a > b) ? a : b;
}
professional *pronode(long long unsigned int mobile, char *name, char *lastname, char *type, char *email, char *address, long long unsigned int officeno)
{
      professional *n = (professional *)malloc(sizeof(professional));
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
personal *insert(personal *root, long long unsigned int mobile, char *name, char *lastname, char *type, FILE *fp1)
{
      if (root == NULL)
      {
            fopen("personal.txt", "a+");
            root = newnode(mobile, name, lastname, type);
            fprintf(fp1, "%llu\t%s\t%s\t%s\n", mobile, name, lastname, type);
            fclose(fp1);
            printf(">>>>>contact inserted\n");
            return root;
      }

      if (mobile < root->mobile)
            root->left = insert(root->left, mobile, name, lastname, type, fp1);
      else if (mobile > root->mobile)
            root->right = insert(root->right, mobile, name, lastname, type, fp1);
      else
            return root;

      root->height = max(getheightpersonal(root->left), getheightpersonal(root->right)) + 1;
      int balance = getbalancefactor(root);
      if (balance > 1 && mobile < root->left->mobile)
            return rotaterightt(root);
      if (balance < -1 && mobile > root->right->mobile)
            return rotateleftt(root);
      if (balance > 1 && mobile > root->left->mobile)
      {
            root->left = rotateleftt(root->left);
            return rotaterightt(root);
      }
      if (balance < -1 && mobile < root->right->mobile)
      {
            root->right = rotaterightt(root->right);
            return rotateleftt(root);
      }

      return root;
}
professional *insertpro(professional *root, long long unsigned int mobile, char *name, char *lastname, char *type, char *email, char *address, long long unsigned int officeno, FILE *pro)
{
      if (root == NULL)
      {
            fopen("professional.txt", "a+");
            root = pronode(mobile, name, lastname, type, email, address, officeno);
            fprintf(pro, "%llu\t%s\t%s\t%s\t%s\t%s\t%llu\n", mobile, name, lastname, type, email, address, officeno);
            fclose(pro);
            printf(">>>>>>>>>>>>>>new contact created\n\n\n");
            return root;
      }

      if (mobile < root->mobile)
            root->left = insertpro(root->left, mobile, name, lastname, type, email, address, officeno, pro);
      else if (mobile > root->mobile)
            root->right = insertpro(root->right, mobile, name, lastname, type, email, address, officeno, pro);
      else
            return root;

      root->height = max(getheightprofessional(root->left), getheightprofessional(root->right)) + 1;
      // now balance the tree
      int balance = getbalancefactorprofessional(root);
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
void inorder(personal *root)
{
      if (root != NULL)
      {
            inorder(root->left);
            printf("%llu %s %s %s\n", root->mobile, root->name, root->lastname, root->type);

            inorder(root->right);
      }
}
void inorderpro(professional *root)
{

      if (root != NULL)
      {
            inorderpro(root->left);
            printf("%llu %s %s %s %s %s %llu \n", root->mobile, root->name, root->lastname, root->type, root->email, root->address, root->officeno);

            inorderpro(root->right);
      }
}
void printdatainfiles(FILE *fptr)
{
      printf("\n");
      fptr = fopen("personal.txt", "r");
      char c;
      if (fptr == NULL)
      {
            printf("Cannot open file \n");
            exit(0);
      }

      // Read contents from file
      c = fgetc(fptr);
      while (c != EOF)
      {
            printf("%c", c);
            c = fgetc(fptr);
      }
      printf("\n");
      fclose(fptr);
      return;
}
void printdatainfilesinprof(FILE *fptr)
{
      printf("\n");
      fptr = fopen("professional.txt", "r");
      char c;
      if (fptr == NULL)
      {
            printf(">>>>>>>>Cannot open file \n");
            exit(0);
      }

      // Read contents from file
      c = fgetc(fptr);
      while (c != EOF)
      {
            printf("%c", c);
            c = fgetc(fptr);
      }
      printf("\n");
      fclose(fptr);
      return;
}
personal *search(personal *root, long long unsigned int key)
{
      if (root == NULL)
      {
            return NULL;
      }
      if (root->mobile == key)
      {
            return root;
      }
      if (root->mobile > key)
      {
            return search(root->left, key);
      }
      return search(root->right, key);
}
professional *searchinprofessional(professional *root, long long unsigned int key)
{
      if (root == NULL)
      {
            return NULL;
      }
      if (root->mobile == key)
      {
            return root;
      }
      if (root->mobile > key)
      {
            return searchinprofessional(root->left, key);
      }
      return searchinprofessional(root->right, key);
}
void searchwithname(personal *root, char *key, int *flag)
{

      if (root == NULL)
      {
            return;
      }
      if (strcmp(root->name, key) == 0)
      {
            printf(">>>>>>>>>contact found\n");
            printf("%llu %s %s %s\n", root->mobile, root->name, root->lastname, root->type);
            *flag = 1;
      }
      searchwithname(root->left, key, flag);
      searchwithname(root->right, key, flag);
}
void searchwithnamepro(professional *root, char *key, int *flag)
{
      if (root == NULL)
      {
            return;
      }
      if (strcmp(root->name, key) == 0)
      {
            printf(">>>>>>>>>contact found\n");
            printf("%llu %s %s %s %s %s %llu\n", root->mobile, root->name, root->lastname, root->type, root->email, root->address, root->officeno);
            *flag = 1;
      }
      searchwithnamepro(root->left, key, flag);
      searchwithnamepro(root->right, key, flag);
}

void editcontact(personal *root, long long unsigned int key, FILE *fp)
{
      personal *temp = search(root, key);
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
      printf("\n>>>>>>>>>>>>>>updated contact details\n\n");
      fopen("personal.txt", "a+");
      fprintf(fp, "%llu\t%s\t%s\t%s  (updated contact of mobile no %llu ) \n", temp->mobile, temp->name, temp->lastname, temp->type, key);
      fclose(fp);
}
void edit_professional_contact(professional *root, long long unsigned int key, FILE *fp)
{
      professional *temp = searchinprofessional(root, key);
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
      scanf("%llu", &temp->officeno);
      fopen("professional.txt", "a+");
      fprintf(fp, "%llu\t%s\t%s\t%s  (updated contact of mobile no %llu ) \n", temp->mobile, temp->name, temp->lastname, temp->type, key);
      fclose(fp);
      printf("\n\nupdated contact details\n\n");
}

void range(personal *root, long long unsigned int low, long long unsigned int high)
{
      if (root == NULL)
      {
            return;
      }
      if (root->mobile >= low && root->mobile <= high)
      {

            printf("%llu %s %s %s\n", root->mobile, root->name, root->lastname, root->type);
      }
      range(root->left, low, high);
      range(root->right, low, high);
}
void rangepro(professional *root, long long unsigned int low, long long unsigned int high)
{
      if (root == NULL)
      {
            return;
      }
      rangepro(root->left, low, high);
      if (root->mobile >= low && root->mobile <= high)
      {
            printf("%llu %s %s %s %s %s %llu\n", root->mobile, root->name, root->lastname, root->type, root->email, root->address, root->officeno);
      }

      rangepro(root->right, low, high);
}

personal *minValueNode(personal *node)
{
      personal *current = node;
      while (current->left != NULL)
            current = current->left;
      return current;
}

personal *deleteNode(personal *root, long long unsigned int key, FILE *fp1)
{
      if (root == NULL)
      {
            return root;
      }
      else if (key < root->mobile)
      {
            root->left = deleteNode(root->left, key, fp1);
      }
      else if (key > root->mobile)
            root->right = deleteNode(root->right, key, fp1);
      else
      {
            if (root->left == NULL)
            {
                  personal *temp = root->right;
                  fopen("personal.txt", "a+");
                  fprintf(fp1, "%llu\t%s\t%s\t%s  (deleted contact of mobile no %llu ) \n", root->mobile, root->name, root->lastname, root->type, key);
                  fclose(fp1);
                  free(root);

                  return temp;
            }
            else if (root->right == NULL)
            {
                  personal *temp = root->left;
                  fopen("personal.txt", "a+");
                  fprintf(fp1, "%llu\t%s\t%s\t%s  (deleted contact of mobile no %llu ) \n", root->mobile, root->name, root->lastname, root->type, key);
                  fclose(fp1);
                  free(root);
                  return temp;
            }
            else
            {
                  personal *temp = minValueNode(root->right);
                  root->mobile = temp->mobile;
                  root->right = deleteNode(root->right, temp->mobile, fp1);
            }
      }

      if (root == NULL)
      {
            return root;
      }

      root->height = 1 + max(getheightpersonal(root->left), getheightpersonal(root->right));

      int balance = getbalancefactor(root);
      if (balance == 2 && getbalancefactor(root->left) >= 0)
            return rotaterightt(root);
      else if (balance == 2 && getbalancefactor(root->left) == -1)
      {
            root->left = rotateleftt(root->left);
            return rotaterightt(root);
      }
      else if (balance == -2 && getbalancefactor(root->right) <= 0)
            return rotateleftt(root);
      else if (balance == -2 && getbalancefactor(root->right) == 1)
      {
            root->right = rotaterightt(root->right);
            return rotateleftt(root);
      }
      return root;
}

professional *minValueNodepro(professional *node)
{
      professional *current = node;
      while (current->left != NULL)
            current = current->left;
      return current;
}

/* right rotate  after right rotation the root will be the left child of the right child of the root
           x
         /   \
       t1     y
             /  \
           t2    t3


*/
professional *rightrotatepro(professional *y)
{
      professional *x = y->left;
      professional *t2 = x->right;
      x->right = y;
      y->left = t2;
      y->height = max(getheightprofessional(y->left), getheightprofessional(y->right)) + 1;
      x->height = max(getheightprofessional(x->left), getheightprofessional(x->right)) + 1;
      return x;
}
/* left rotate
           y
         /   \
       x     t3
     /  \
   t1    t2
*/

professional *leftrotatepro(professional *x)
{
      professional *y = x->right;
      professional *t2 = y->left;
      y->left = x;
      x->right = t2;
      y->height = max(getheightprofessional(y->left), getheightprofessional(y->right)) + 1;
      x->height = max(getheightprofessional(x->left), getheightprofessional(x->right)) + 1;
      return y;
}

personal *rotaterightt(personal *x)
{
      personal *y;
      y = x->left;
      x->left = y->right;
      y->right = x;
      x->height = max(getheightpersonal(x->left), getheightpersonal(x->right)) + 1;
      y->height = max(getheightpersonal(y->left), getheightpersonal(y->right)) + 1;
      return y;
}

personal *rotateleftt(personal *x)
{
      personal *y;
      y = x->right;
      x->right = y->left;
      y->left = x;
      x->height = max(getheightpersonal(x->left), getheightpersonal(x->right)) + 1;
      y->height = max(getheightpersonal(y->left), getheightpersonal(y->right)) + 1;
      return y;
}

professional *deleteNodepro(professional *root, long long unsigned int key, FILE *fp1)
{
      if (root == NULL)
      {
            return root;
      }
      else if (key < root->mobile)
      {
            root->left = deleteNodepro(root->left, key,fp1);
      }
      else if (key > root->mobile)
            root->right = deleteNodepro(root->right, key, fp1);
      else
      {
            if (root->left == NULL)
            {
                  professional *temp = root->right;
                  fopen("professional.txt", "a+");
                  fprintf(fp1, "%llu\t%s\t%s\t%s  (deleted contact of mobile no %llu ) \n", root->mobile, root->name, root->lastname, root->type, key);
                  fclose(fp1);

                  free(root);
                  return temp;
            }
            else if (root->right == NULL)
            {
                  professional *temp = root->left;
                  fopen("professional.txt", "a+");
                  fprintf(fp1, "%llu\t%s\t%s\t%s  (deleted contact of mobile no %llu ) \n", root->mobile, root->name, root->lastname, root->type, key);
                  fclose(fp1);
                  free(root);
                  return temp;
            }
            else
            {
                  professional *temp = minValueNodepro(root->right);
                  root->mobile = temp->mobile;
                  root->right = deleteNodepro(root->right, temp->mobile, fp1);
            }
      }
      if (root == NULL)
            return root;
      root->height = 1 + max(getheightprofessional(root->left), getheightprofessional(root->right));
      int balance = getbalancefactorprofessional(root);

      if (balance == 2 && getbalancefactorprofessional(root->left) >= 0)
            return rightrotatepro(root);
      else if (balance == 2 && getbalancefactorprofessional(root->left) == -1)
      {
            root->left = leftrotatepro(root->left);
            return rightrotatepro(root);
      }
      else if (balance == -2 && getbalancefactorprofessional(root->right) <= 0)
            return leftrotatepro(root);
      else if (balance == -2 && getbalancefactorprofessional(root->right) == 1)
      {
            root->right = rightrotatepro(root->right);
            return leftrotatepro(root);
      }
      return root;
}

void decendingsorted(personal *root)
{
      if (root == NULL)
      {
            return;
      }
      decendingsorted(root->right);
      printf("%llu \t %s \t %s \t %s\n", root->mobile, root->name, root->lastname, root->type);
      decendingsorted(root->left);
}
void decendingsortedpro(professional *root)
{
      if (root == NULL)

            return;

      decendingsortedpro(root->right);
      printf("%llu \t %s \t %s \t %s \t %s \t %s \t %llu \n", root->mobile, root->name, root->lastname, root->type, root->email, root->address, root->officeno);
      decendingsortedpro(root->left);
}

personal *insert_phone_name(personal *root, long long unsigned int mobile, char *name, char *lastname, char *type)
{
      if (root == NULL)
      {
            root = newnode(mobile, name, lastname, type);
            return root;
      }
      if (strcmp(name, root->name) < 0 || (strcmp(name, root->name) == 0 && mobile < root->mobile))
            root->left = insert_phone_name(root->left, mobile, name, lastname, type);
      else if (strcmp(name, root->name) > 0 || (strcmp(name, root->name) == 0 && mobile > root->mobile))
            root->right = insert_phone_name(root->right, mobile, name, lastname, type);
      else
            return root;
      root->height = max(getheightpersonal(root->left), getheightpersonal(root->right)) + 1;
      int balance = getbalancefactor(root);
      if (balance > 1 && strcmp(name, root->left->name) < 0)
            return rotaterightt(root);
      if (balance < -1 && strcmp(name, root->right->name) > 0)
            return rotateleftt(root);
      if (balance > 1 && strcmp(name, root->left->name) > 0)
      {
            root->left = rotateleftt(root->left);
            return rotaterightt(root);
      }
      if (balance < -1 && strcmp(name, root->right->name) < 0)
      {
            root->right = rotaterightt(root->right);
            return rotateleftt(root);
      }

      return root;
}

professional *insert_phone_namepro(professional *root, long long unsigned int mobile, char *name, char *lastname, char *type, char *email, char *address, int officeno)
{
      if (root == NULL)
      {
            root = pronode(mobile, name, lastname, type, email, address, officeno);
            return root;
      }
      if (strcmp(name, root->name) < 0 || (strcmp(name, root->name) == 0 && mobile < root->mobile))
            root->left = insert_phone_namepro(root->left, mobile, name, lastname, type, email, address, officeno);
      else if (strcmp(name, root->name) > 0 || (strcmp(name, root->name) == 0 && mobile > root->mobile))
            root->right = insert_phone_namepro(root->right, mobile, name, lastname, type, email, address, officeno);
      else
            return root;
      root->height = max(getheightprofessional(root->left), getheightprofessional(root->right)) + 1;
      int balance = getbalancefactorprofessional(root);
      if (balance > 1 && strcmp(name, root->left->name) < 0)
            return rightrotatepro(root);
      if (balance < -1 && strcmp(name, root->right->name) > 0)
            return leftrotatepro(root);
      if (balance > 1 && strcmp(name, root->left->name) > 0)
      {
            root->left = leftrotatepro(root->left);
            return rightrotatepro(root);
      }
      if (balance < -1 && strcmp(name, root->right->name) < 0)
      {
            root->right = rightrotatepro(root->right);
            return leftrotatepro(root);
      }

      return root;
}

personal *inorder_sorted(personal *root, personal *newroot)
{
      if (root == NULL)
            return newroot;
      newroot = inorder_sorted(root->left, newroot);
      newroot = insert_phone_name(newroot, root->mobile, root->name, root->lastname, root->type);
      newroot = inorder_sorted(root->right, newroot);
      return newroot;
}

professional *inorder_sortedpro(professional *root, professional *newroot)
{
      if (root == NULL)
            return newroot;
      newroot = inorder_sortedpro(root->left, newroot);
      newroot = insert_phone_namepro(newroot, root->mobile, root->name, root->lastname, root->type, root->email, root->address, root->officeno);
      newroot = inorder_sortedpro(root->right, newroot);
      printf("\n");
      return newroot;
}