// Name : sushant sanjiv kogurwar
// Roll_no : BT20CSE067
// topic : A phonebook  implemented using linked list of data structures 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
      int mobile;
      char name[100];
      char lname[100];
      char type[10];
      struct node *next;
      int duration;
};
struct pronode
{
      int mobile;
      char name[100];
      char lname[100];
      char email[30];
      int number;
      char office[100];
      char type[10];
      struct pronode *next;
};
struct phonebook
{
      char name[20];
      int totaltime;
      char address[20];
      struct node *list;
      struct phonebook *next;
};
struct phonebook_list
{
      struct phonebook *head;
      struct phonebook_list *next;
};
void displayContact(struct node *node)
{
      printf("\n\n...........................................................\n");
      printf("name \tlast_name \tmobile number \t type \n");
      printf("............................................................\n");
      while (node != NULL)
      {
            printf("%s \t%s \t    %d \t %s \t\n", node->name, node->lname, node->mobile, node->type);
            node = node->next;
      }
      printf("\n\n");
}

void sortlinkedlistActoNames(struct node **head_ref)
{
      struct node *current = *head_ref, *index = NULL;
      char temp[100];
      if (head_ref == NULL)
      {
            return;
      }
      else
      {
            while (current != NULL)
            {
                  index = current->next;
                  while (index != NULL)
                  {
                        if (strcmp(current->name, index->name) > 0)
                        {
                              strcpy(temp, current->name);
                              strcpy(current->name, index->name);
                              strcpy(index->name, temp);

                              strcpy(temp, current->lname);
                              strcpy(current->lname, index->lname);
                              strcpy(index->lname, temp);
                              int mo = current->mobile;
                              current->mobile = index->mobile;
                              index->mobile = mo;

                              strcpy(temp, current->type);
                              strcpy(current->type, index->type);
                              strcpy(index->type, temp);
                        }
                        index = index->next;
                  }
                  current = current->next;
            }
      }
}

void insertContact(struct node **head, int mob, char *na, char *lna, char *type)
{
      struct node *newnode = (struct node *)malloc(sizeof(struct node));
      newnode->mobile = mob;
      strcpy(newnode->name, na);
      strcpy(newnode->lname, lna);
      strcpy(newnode->type, type);
      newnode->next = NULL;
      if (*head == NULL)
      {
            *head = newnode;
            return;
      }
      struct node *temp = *head;
      while (temp->next != NULL)
      {
            temp = temp->next;
      }
      temp->next = newnode;
      sortlinkedlistActoNames(head);
      return;
}

void DeleteContact(struct node **head_ref, int key)
{
      struct node *temp = *head_ref, *prev;
      if (temp != NULL && temp->mobile == key)
      {
            *head_ref = temp->next;
            free(temp);
            return;
      }
      while (temp != NULL && temp->mobile != key)
      {
            prev = temp;
            temp = temp->next;
      }
      if (temp == NULL)
      {
            printf("The given Mobile number is not present in the list\n");
            return;
      }
      prev->next = temp->next;
      free(temp);
      return;
}

void DeleteContactwithname(struct node **head_ref, char *name, char *lname)
{
      struct node *temp = *head_ref, *prev;
      if (temp != NULL && strcmp(temp->name, name) == 0 && (strcmp(temp->lname, lname) == 0))
      {
            *head_ref = temp->next;
            free(temp);
            return;
      }
      while (temp != NULL && strcmp(temp->name, name) != 0)
      {
            prev = temp;
            temp = temp->next;
      }
      if (temp == NULL)
      {
            printf("The given name is not present in the list\n");
            return;
      }
      prev->next = temp->next;
      free(temp);
      return;
}

int searchNode(struct node **head_ref, int key)
{
      struct node *current = *head_ref;
      while (current != NULL)
      {
            if (current->mobile == key)
            {
                  return 1;
            }
            current = current->next;
      }
      return 0;
}

int searchNodewithname(struct node **head_ref, char *name)
{
      struct node *current = *head_ref;
      while (current != NULL)
      {
            if (strcmp(current->name, name) == 0)
            {
                  return 1;
            }
            current = current->next;
      }
      return 0;
}

void EditContact(struct node **head, int mobile1, char *name1, char *lname1, int prevmobile)
{
      struct node *temp = *head;
      while (temp != NULL)
      {
            if (temp->mobile == prevmobile)
            {
                  temp->mobile = mobile1;
                  strcpy(temp->name, name1);
                  strcpy(temp->lname, lname1);
                  return;
            }
            temp = temp->next;
      }
      if (temp == NULL)
      {
            printf("The given Mobile number is not present in the list\n");
            return;
      }
      printf("The details has been updated \n");
      return;
}

void sortlinkedlistActoNumbers(struct node **head_ref)
{
      struct node *current = *head_ref, *index = NULL;
      char temp[100];
      if (head_ref == NULL)
      {
            return;
      }
      else
      {
            while (current != NULL)
            {
                  index = current->next;
                  while (index != NULL)
                  {
                        if (current->mobile > index->mobile)
                        {
                              strcpy(temp, current->name);
                              strcpy(current->name, index->name);
                              strcpy(index->name, temp);

                              strcpy(temp, current->lname);
                              strcpy(current->lname, index->lname);
                              strcpy(index->lname, temp);
                              int mo = current->mobile;
                              current->mobile = index->mobile;
                              index->mobile = mo;

                              strcpy(temp, current->type);
                              strcpy(current->type, index->type);
                              strcpy(index->type, temp);
                        }
                        index = index->next;
                  }
                  current = current->next;
            }
      }
}

void sortlinkedlistdecending(struct node **head_ref)
{
      struct node *current = *head_ref, *index = NULL;
      char temp[100];
      if (head_ref == NULL)
      {
            return;
      }
      else
      {
            while (current != NULL)
            {
                  index = current->next;
                  while (index != NULL)
                  {
                        if (current->mobile < index->mobile)
                        {
                              strcpy(temp, current->name);
                              strcpy(current->name, index->name);
                              strcpy(index->name, temp);

                              strcpy(temp, current->lname);
                              strcpy(current->lname, index->lname);
                              strcpy(index->lname, temp);
                              int mo = current->mobile;
                              current->mobile = index->mobile;
                              index->mobile = mo;

                              strcpy(temp, current->type);
                              strcpy(current->type, index->type);
                              strcpy(index->type, temp);
                        }
                        index = index->next;
                  }
                  current = current->next;
            }
      }
}

void removeduplicateswithNumbers(struct node **head_ref)
{
      struct node *current = *head_ref, *index = NULL;
      if (head_ref == NULL)
      {
            return;
      }
      else
      {
            while (current->next != NULL)
            {

                  if (current->mobile == current->next->mobile)
                  {
                        index = current->next;
                        current->next = current->next->next;
                        free(index);
                  }
                  else
                  {
                        current = current->next;
                  }
            }
      }
}

void removeduplicateswithNames(struct node **head_ref)
{
      struct node *current = *head_ref, *index = NULL;
      if (head_ref == NULL)
      {
            return;
      }
      else
      {
            while (current->next != NULL)
            {
                  if (strcmp(current->name, current->next->name) == 0)
                  {
                        index = current->next;
                        current->next = current->next->next;
                        free(index);
                  }
                  else
                  {
                        current = current->next;
                  }
            }
      }
}

struct node *merge(struct node *h1, struct node *h2)
{
      if (!h1){
      return h2;
      }
           
      if (!h2){
             return h1;
      }
      struct node *temp = NULL;
      if (h1->mobile > h2->mobile)
      {     temp=h2;
            temp->next = merge(h2->next, h1);
      }
      else
      {     temp=h1;
            temp->next = merge(h1->next, h2);   
      }
      sortlinkedlistActoNames(&temp);
      return temp;
}

// TODO: PROFECTIONAL NODES AND LINKED LIST
void sortlinkedlistActoNamesofpro(struct pronode **pronode)
{
      struct pronode *current = *pronode, *index = NULL;
      if (pronode == NULL)
      {
            return;
      }
      else
      {
            while (current->next != NULL)
            {
                  index = current->next;
                  while (index != NULL)
                  {
                        if (strcmp(current->name, index->name) > 0)
                        {
                              int mo = current->mobile;
                              char na[20];
                              char lna[20];
                              char type[20];
                              char email[20];
                              char company[20];
                              int office = current->number;

                              strcpy(na, current->name);
                              strcpy(current->name, index->name);
                              strcpy(index->name, na);

                              strcpy(lna, current->lname);
                              strcpy(current->lname, index->lname);
                              strcpy(index->lname, lna);

                              strcpy(type, current->type);
                              strcpy(current->type, index->type);
                              strcpy(index->type, type);

                              strcpy(email, current->email);
                              strcpy(current->email, index->email);
                              strcpy(index->email, email);

                              strcpy(company, current->office);
                              strcpy(current->office, index->office);
                              strcpy(index->office, company);

                              current->mobile = index->mobile;
                              index->mobile = mo;

                              current->number = index->number;
                              index->number = office;
                        }
                        index = index->next;
                  }
                  current = current->next;
            }
      }
}

void insertProfessionalContact(struct pronode **prohead, int mob, char *na, char *lna, char *type, char *email, char *office, int number)
{
      struct pronode *newnode = (struct pronode *)malloc(sizeof(struct pronode));
      newnode->mobile = mob;
      strcpy(newnode->name, na);
      strcpy(newnode->lname, lna);
      strcpy(newnode->type, type);
      strcpy(newnode->email, email);
      strcpy(newnode->office, office);
      newnode->number = number;
      newnode->next = NULL;
      if (*prohead == NULL)
      {
            *prohead = newnode;
            return;
      }
      struct pronode *temp = *prohead;
      while (temp->next != NULL)
      {
            temp = temp->next;
      }
      temp->next = newnode;
      sortlinkedlistActoNamesofpro(prohead);
      return;
}

void editProfessionalContact(struct pronode **prohead_ref, int mobile1, char *name1, char *lname1, char *type1, char *email1, char *company1, int office1, int prevmobile)
{
      struct pronode *temp = *prohead_ref;
      while (temp != NULL)
      {
            if (temp->mobile == prevmobile)
            {
                  temp->mobile = mobile1;
                  strcpy(temp->name, name1);
                  strcpy(temp->lname, lname1);
                  strcpy(temp->type, type1);
                  strcpy(temp->email, email1);
                  strcpy(temp->office, company1);
                  temp->number = office1;
                  return;
            }
            temp = temp->next;
      }
      if (temp == NULL)
      {
            printf("The given Mobile number is not present in the list\n");
            return;
      }
      printf("The details has been updated \n");
      return;
}

void displayprofectional(struct pronode *prohead_ref)
{
      if (prohead_ref == NULL)
      {
            printf("The list is empty\n");
            return;
      }
      printf("\n\n.....................................................................................................................\n");
      printf(" MOBILE\t NAME\t Lastname  \t type\t email\t company\t office-number\n");
      printf(".........................................................................................................................\n");
      struct pronode *temp = prohead_ref;
      while (temp != NULL)
      {
            printf("%d %s  %s %s %s %s %d\n", temp->mobile, temp->name, temp->lname, temp->type, temp->email, temp->office, temp->number);
            temp = temp->next;
      }
}

struct pronode *mergeprofectional(struct pronode *h1, struct pronode *h2)
{
      if (!h1){
      return h2;
      }
           
      if (!h2){
             return h1;
      }
      struct pronode *temp = NULL;
      if (h1->mobile > h2->mobile)
      {     temp=h2;
            temp->next = mergeprofectional(h2->next, h1);
      }
      else
      {     temp=h1;
            temp->next = mergeprofectional(h1->next, h2);   
      }
      sortlinkedlistActoNamesofpro(&temp);
      return temp;
}

void removeduplicateswithnamesOfProNode(struct pronode **head_ref)
{
      struct pronode *current = *head_ref, *index = NULL;
      if (head_ref == NULL)
      {
            return;
      }
      else
      {
            while (current->next != NULL)
            {
                  if (strcmp(current->name, current->next->name) == 0)
                  {
                        index = current->next;
                        current->next = current->next->next;
                        free(index);
                  }
                  else
                  {
                        current = current->next;
                  }
            }
      }
}

void removeduplicateswithNumbersofpro(struct pronode **head_ref)
{
      struct pronode *current = *head_ref, *index = NULL;
      if (head_ref == NULL)
      {
            return;
      }
      else
      {
            while (current->next != NULL)
            {
                  if (current->mobile == current->next->mobile)
                  {
                        index = current->next;
                        current->next = current->next->next;
                        free(index);
                  }
                  else
                  {
                        current = current->next;
                  }
            }
      }
}

int searchNodeofpro(struct pronode *head_ref, int mobile)
{
      struct pronode *temp = head_ref;
      while (temp != NULL)
      {
            if (temp->mobile == mobile)
            {
                  return 1;
            }
            temp = temp->next;
      }
      return 0;
}

int searchNodewithnameofpro(struct pronode *head_ref, char *name)
{
      struct pronode *temp = head_ref;
      while (temp != NULL)
      {
            if (strcmp(temp->name, name) == 0)
            {
                  return 1;
            }
            temp = temp->next;
      }
      return 0;
}

void sortlinkedlistActoNumbersofpro(struct pronode **pronode)
{
      struct pronode *current = *pronode, *index = NULL;
      if (pronode == NULL)
      {
            return;
      }
      else
      {
            while (current->next != NULL)
            {
                  index = current->next;
                  while (index != NULL)
                  {
                        if (current->mobile > index->mobile)
                        {
                              int mo = current->mobile;
                              char na[20];
                              char lna[20];
                              char type[20];
                              char email[20];
                              char company[20];
                              int office = current->number;

                              strcpy(na, current->name);
                              strcpy(current->name, index->name);
                              strcpy(index->name, na);

                              strcpy(lna, current->lname);
                              strcpy(current->lname, index->lname);
                              strcpy(index->lname, lna);

                              strcpy(type, current->type);
                              strcpy(current->type, index->type);
                              strcpy(index->type, type);

                              strcpy(email, current->email);
                              strcpy(current->email, index->email);
                              strcpy(index->email, email);

                              strcpy(company, current->office);
                              strcpy(current->office, index->office);
                              strcpy(index->office, company);

                              current->mobile = index->mobile;
                              index->mobile = mo;

                              current->number = index->number;
                              index->number = office;
                        }
                        index = index->next;
                  }
                  current = current->next;
            }
      }
}

void sortlinkedlistdecendingofpro(struct pronode **head_ref)
{
      struct pronode *current = *head_ref, *index = NULL;
      if (head_ref == NULL)
      {
            return;
      }
      else
      {
            while (current->next != NULL)
            {
                  index = current->next;
                  while (index != NULL)
                  {
                        if (current->mobile < index->mobile)
                        {
                              int mo = current->mobile;
                              char na[20];
                              char lna[20];
                              char type[20];
                              char email[20];
                              char company[20];
                              int office = current->number;

                              strcpy(na, current->name);
                              strcpy(current->name, index->name);
                              strcpy(index->name, na);

                              strcpy(lna, current->lname);
                              strcpy(current->lname, index->lname);
                              strcpy(index->lname, lna);

                              strcpy(type, current->type);
                              strcpy(current->type, index->type);
                              strcpy(index->type, type);

                              strcpy(email, current->email);
                              strcpy(current->email, index->email);
                              strcpy(index->email, email);

                              strcpy(company, current->office);
                              strcpy(current->office, index->office);
                              strcpy(index->office, company);

                              current->mobile = index->mobile;
                              index->mobile = mo;

                              current->number = index->number;
                              index->number = office;
                        }
                        index = index->next;
                  }
                  current = current->next;
            }
      }
}

void DeleteProfContact(struct pronode **head_ref, int key)
{
      struct pronode *temp = *head_ref, *prev;
      if (temp != NULL && temp->mobile == key)
      {
            *head_ref = temp->next;
            free(temp);
            return;
      }
      while (temp != NULL && temp->mobile != key)
      {
            prev = temp;
            temp = temp->next;
      }
      if (temp == NULL)
      {
            printf("The given Mobile number is not present in the list\n");
            return;
      }
      prev->next = temp->next;
      free(temp);
      return;
}

void DeleteprofContactwithname(struct pronode **head_ref, char *name, char *lname)
{
      struct pronode *temp = *head_ref, *prev;
      if (temp != NULL && strcmp(temp->name, name) == 0 && (strcmp(temp->lname, lname) == 0))
      {
            *head_ref = temp->next;
            free(temp);
            return;
      }
      while (temp != NULL && strcmp(temp->name, name) != 0)
      {
            prev = temp;
            temp = temp->next;
      }
      if (temp == NULL)
      {
            printf("The given name is not present in the list\n");
            return;
      }
      prev->next = temp->next;
      free(temp);
      return;
}

void insertphonebook(struct phonebook_list **head_ref)
{
      struct phonebook *temp = (struct phonebook *)malloc(sizeof(struct phonebook));
      printf("Enter the name of the person\n");
      scanf("%s", temp->name);
      printf("Enter the address\n");
      scanf("%s", temp->address);
      printf("enter the number of the contact in list \n");
      int n;
      scanf("%d", &n);
      int ttime = 0;
      struct node *newnode = NULL;
      int i = 0;
      for (i = 0; i < n; i++)
      {
            printf("Enter the mobile number of the contact \n");
            int mobile;
            scanf("%d", &mobile);
            printf("Enter the name of the contact \n");
            char name[100] = "";
            scanf("%s", name);
            printf("Enter the last name of the contact \n");
            char lname[100] = "";
            scanf("%s", lname);
            printf("Enter the type of the contact \n");
            char type[10] = "";
            scanf("%s", type);
            printf("enter the duration of the call \n");
            int duration;
            scanf("%d", &duration);
            ttime = ttime + duration;
            insertContact(&newnode, mobile, name, lname, type);
            printf("The contact is added successfully\n");
      }
      temp->totaltime = ttime;
      temp->list = newnode;
      temp->next = NULL;
      struct phonebook_list *new = (struct phonebook_list *)malloc(sizeof(struct phonebook_list));
      new->head = temp;
      new->head->next = NULL;
      if (*head_ref == NULL)
      {
            *head_ref = new;
      }
      else
      {
            struct phonebook_list *current = *head_ref;
            while (current->head->next != NULL)
            {
                  current = current->next;
            }
            current->head->next = new->head;
      }
      printf("The phonebook is added successfully \n");
}
void displayPhonebook(struct phonebook_list *head)
{
      struct phonebook *current = head->head;
      printf("................................................................................................\n");
      printf("Name \t\t\t\tTotal time \t\t\t\tAddress \n");
      printf("................................................................................................\n");
      while (current != NULL)
      {
            printf("%s \t\t\t\t%d \t\t\t\t%s\n", current->name, current->totaltime, current->address);
            printf("\n");
            current = current->next;
      }
}
//commented as not working properly
// void sortPhonebookList(struct phonebook_list **head_ref)
// {
//       struct phonebook_list *temp = *head_ref;
//       struct phonebook *current = temp->head, *index = NULL;
//       char tempo[20];
//       if (temp == NULL)
//       {
//             return;
//       }
//       else
//       {

//             while (current != NULL)
//             {
//                   index = current->next;
//                   while (index != NULL)
//                   {
//                         if (current->totaltime < index->totaltime)
//                         {
//                               strcpy(tempo, current->name);
//                               strcpy(current->name, index->name);
//                               strcpy(index->name, tempo);

//                               strcpy(tempo, current->address);
//                               strcpy(current->address, index->address);
//                               strcpy(index->address, tempo);

//                               int ttime = current->totaltime;
//                               current->totaltime = index->totaltime;
//                               index->totaltime = ttime;
//                         }
//                         temp = temp->next;
//                   }
//                   current = current->next;
//             }
//       }
// }

int main()
{
      struct node *head = NULL;
      struct pronode *prohead = NULL;
      struct phonebook_list *headlist = NULL;
      int flag = 0;
      while (flag == 0)
      {
            printf("\n Enter the number to perform the operations in Phone-book \n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("Enter 1 -> Add contact to phonebook \n");
            printf("Enter 2 -> Edit contact in phonebook \n");
            printf("Enter 3 -> Delete contact in phonebook \n");
            printf("Enter 4 -> search contact in phonebook \n");
            printf("Enter 5 -> sort contacts in phonebook \n");
            printf("Enter 6 -> Display contacts in phonebook \n");
            printf("Enter 7 -> union of two linked lists sorted based on name and mobile number\n");
            printf("Enter 8 -> remove duplicate contacts from Phonebook\n");
            printf("Enter 9 -> Design  a  linked  list  that  stores  phonebooks  of  different  people\n");
            printf("Enter 0 -> To exit \n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("Enter your choice : ");
            int choice;
            scanf("%d", &choice);
            switch (choice)
            {
            case 1: //* done
                  printf("Enter 1 for personal contact and 2 for profectional contact\t:");
                  int choice6 = 0;
                  scanf("%d", &choice6);
                  printf("Enter the mobile number of the contact \n");
                  int mobile = 0;
                  scanf("%d", &mobile);
                  printf("Enter the name of the contact \n");
                  char name[100] = "";
                  scanf("%s", name);
                  printf("Enter the last name of the contact \n");
                  char lname[100] = "";
                  scanf("%s", lname);
                  printf("Enter the type of the contact \n");
                  char type[10] = "";
                  scanf("%s", type);
                  if (choice6 == 1)
                  {
                        insertContact(&head, mobile, name, lname, type);
                        printf(">>>>>>>>>success\n");
                  }
                  else if (choice6 == 2)
                  {
                        printf("Enter the email of the contact \n");
                        char email[100] = "";
                        scanf("%s", email);
                        printf("Enter the company name of the contact \n");
                        char company[100] = "";
                        scanf("%s", company);
                        printf("Enter the OFFICE number of the contact \n");
                        int office;
                        scanf("%d", &office);
                        insertProfessionalContact(&prohead, mobile, name, lname, type, email, company, office);
                        printf(">>>>>>>>>success\n");
                  }
                  else
                  {
                        printf("Invalid choice\n");
                  }
                  break;
            case 2: //*done
                  printf("Enter 1 for personal contact and 2 for profectional contact\t:");
                  int choice7 = 0;
                  scanf("%d", &choice7);
                  printf("Enter the mobile number of the contact to be updated \n");
                  int prevmobile;
                  scanf("%d", &prevmobile);
                  if (choice7 == 1)
                  {

                        printf("Enter the new  mobile number of the contact \n");
                        int mobile1=0;
                        scanf("%d", &mobile1);
                        printf("Enter the new name of the contact \n");
                        char name1[100] = "";
                        scanf("%s", name1);
                        printf("Enter the new last name of the contact \n");
                        char lname1[100] = "";
                        scanf("%s", lname1);
                        EditContact(&head, mobile1, name1, lname1, prevmobile);
                  }
                  else if (choice7 == 2)
                  {
                        printf("Enter the new  mobile number of the contact \n");
                        int mobile1=0;
                        scanf("%d", &mobile);
                        printf("Enter the new name of the contact \n");
                        char name1[100] = "";
                        scanf("%s", name);
                        printf("Enter the new last name of the contact \n");
                        char lname1[100] = "";
                        scanf("%s", lname);
                        printf("Enter the new type of the contact \n");
                        char type1[10] = "";
                        scanf("%s", type);
                        printf("Enter the email of the contact \n");
                        char email[100] = "";
                        scanf("%s", email);
                        printf("Enter the company name of the contact \n");
                        char company[100] = "";
                        scanf("%s", company);
                        printf("Enter the OFFICE number of the contact \n");
                        int office;
                        scanf("%d", &office);
                        editProfessionalContact(&prohead, mobile, name, lname, type, email, company, office, prevmobile);
                        printf(">>>>>>>>>success\n");
                  }
                  else
                  {
                        printf("Invalid choice\n");
                  }
                  break;
            case 3: //* done
                  printf("Enter 1 for personal contact and 2 for profectional contact\t:");
                  int inp = 0;
                  scanf("%d", &inp);
                  if (inp == 1)
                  {
                        printf("enter 1 to delete the contact with mobile number \n");
                        printf("enter 2 to delete the contact with name \n");
                        int choice4;
                        scanf("%d", &choice4);
                        if (choice4 == 1)
                        {
                              printf("Enter the mobile number of the contact to be deleted \n");
                              int mobile2;
                              scanf("%d", &mobile2);
                              DeleteContact(&head, mobile2);
                        }
                        else if (choice4 == 2)
                        {
                              printf("Enter the name of the contact to be deleted \n");
                              char name2[100] = "";
                              scanf("%s", name2);
                              printf("Enter the last name of the contact to be deleted \n");
                              char lname2[100] = "";
                              scanf("%s", lname2);
                              DeleteContactwithname(&head, name2, lname2);
                        }
                        else
                        {
                              printf("Invalid choice \n");
                        }
                  }
                  else if (inp == 2)
                  {
                        printf("enter 1 to delete the contact with mobile number \n");
                        printf("enter 2 to delete the contact with name \n");
                        int choice4;
                        scanf("%d", &choice4);
                        if (choice4 == 1)
                        {
                              printf("Enter the mobile number of the contact to be deleted \n");
                              int mobile2;
                              scanf("%d", &mobile2);
                              DeleteProfContact(&prohead, mobile2);
                        }
                        else if (choice4 == 2)
                        {
                              printf("Enter the name of the contact to be deleted \n");
                              char name2[100] = "";
                              scanf("%s", name2);
                              printf("Enter the last name of the contact to be deleted \n");
                              char lname2[100] = "";
                              scanf("%s", lname2);
                              DeleteprofContactwithname(&prohead, name2, lname2);
                        }
                        else
                        {
                              printf("Invalid choice \n");
                        }
                  }
                  else
                  {
                        printf("Invalid choice\n");
                  }

                  break;
            case 4: //* done
                  printf("Enter 1 for personal contact and 2 for profectional contact\t:");
                  int cho = 0;
                  scanf("%d", &cho);
                  if (cho == 1)
                  {
                        printf("Enter 1 to search in contacts with mobile number \n");
                        printf("Enter 2 to search in contacts with name \n");
                        int choice5;
                        scanf("%d", &choice5);
                        if (choice5 == 1)
                        {
                              printf("Enter the mobile number of the contact to be searched \n");
                              int mobile3;
                              scanf("%d", &mobile3);
                              int t = searchNode(&head, mobile3);
                              if (t == 1)
                              {
                                    printf("Contact found \n");
                              }
                              else
                              {
                                    printf("Contact not found \n");
                              }
                        }
                        else if (choice5 == 2)
                        {
                              printf("Enter the name of the contact to be searched \n");
                              char name3[100] = "";
                              scanf("%s", name3);
                              int j = searchNodewithname(&head, name3);
                              if (j == 1)
                              {
                                    printf("Contact found \n");
                              }
                              else
                              {
                                    printf("Contact not found \n");
                              }
                        }
                        else
                        {
                              printf("Invalid choice \n");
                        }
                  }
                  else if (cho == 2)
                  {
                        printf("Enter 1 to search in contacts with mobile number \n");
                        printf("Enter 2 to search in contacts with name \n");
                        int choice5;
                        scanf("%d", &choice5);
                        if (choice5 == 1)
                        {
                              printf("Enter the mobile number of the contact to be searched \n");
                              int mobile3;
                              scanf("%d", &mobile3);
                              int t = searchNodeofpro(prohead, mobile3);
                              if (t == 1)
                              {
                                    printf("Contact found \n");
                              }
                              else
                              {
                                    printf("Contact not found \n");
                              }
                        }
                        else if (choice5 == 2)
                        {
                              printf("Enter the name of the contact to be searched \n");
                              char name3[100] = "";
                              scanf("%s", name3);
                              int j = searchNodewithnameofpro(prohead, name3);
                              if (j == 1)
                              {
                                    printf("Contact found \n");
                              }
                              else
                              {
                                    printf("Contact not found \n");
                              }
                        }
                        else
                        {
                              printf("Invalid choice \n");
                        }
                  }
                  else
                  {
                        printf("Invalid choice \n");
                  }

                  break;
            case 5: //* done
                  printf("Enter 1 for personal contact and 2 for profectional contact\t:");
                  int ch = 0;
                  scanf("%d", &ch);
                  if (ch == 1)
                  {
                        printf("Enter 1 to sorting the contact list with mobile numbers \n");
                        printf("Enter 2 for sorting the contact list with names \n");
                        int choice1;
                        scanf("%d", &choice1);
                        if (choice1 == 1)
                        {
                              printf("enter 1 to sort the contact list with mobile numbers in ascending order\n");
                              printf("enter 2 to sort the contact list with mobile numbers in descending order\n");
                              int inp;
                              scanf("%d", &inp);
                              if (inp == 1)
                              {
                                    sortlinkedlistActoNumbers(&head);
                                    printf("Invalid choice \n");
                              }
                              else if (inp == 2)
                              {
                                    sortlinkedlistdecending(&head);
                                    printf("Invalid choice \n");
                              }
                              else
                              {
                                    printf("Invalid choice \n");
                              }
                        }
                        else
                        {
                              sortlinkedlistActoNames(&head);
                              printf("Contact list sorted \n");
                        }
                  }
                  else if (ch == 2)
                  {
                        printf("Enter 1 to sorting the contact list with mobile numbers \n");
                        printf("Enter 2 for sorting the contact list with names \n");
                        int input1;
                        scanf("%d", &input1);
                        if (input1 == 1)
                        {
                              printf("enter 1 to sort the contact list with mobile numbers in ascending order\n");
                              printf("enter 2 to sort the contact list with mobile numbers in descending order\n");
                              int inp;
                              scanf("%d", &inp);
                              if (inp == 1)
                              {
                                    sortlinkedlistActoNumbersofpro(&prohead);
                              }
                              else if (inp == 2)
                              {
                                    sortlinkedlistdecendingofpro(&prohead);
                              }
                              else
                              {
                                    printf("Invalid choice \n");
                              }
                        }
                        else
                        {
                              sortlinkedlistActoNamesofpro(&prohead);
                        }
                  }
                  else
                  {
                        printf("Invalid choice\n");
                  }

                  break;
            case 6: //* done
                  printf("enter 1 to print personal contact list and 2 to print profectional contact list: \n");
                  int choice8;
                  scanf("%d", &choice8);
                  if (choice8 == 1)
                  {
                        displayContact(head);
                  }
                  else if (choice8 == 2)
                  {
                        displayprofectional(prohead);
                  }
                  else
                  {
                        printf("Invalid choice \n");
                  }

                  break;
            case 7: //* done
                  printf("enter 1 to merge personal contact list and 2 to merge in profectional contact list: \n");
                  int choice9;
                  scanf("%d", &choice9);
                  if (choice9 == 1)
                  {

                        printf("Enter the size of contact list to be added to the list\n");
                        struct node *listmerge = NULL;
                        int size;
                        scanf("%d", &size);
                        int i;
                        for (i = 0; i < size; i++)
                        {
                              printf("Enter the mobile number of the contact \n");
                              int mobile;
                              scanf("%d", &mobile);
                              printf("Enter the name of the contact \n");
                              char name[100] = "";
                              scanf("%s", name);
                              printf("Enter the last name of the contact \n");
                              char lname[100] = "";
                              scanf("%s", lname);
                              printf("Enter the type of the contact \n");
                              char type[10] = "";
                              scanf("%s", type);
                              insertContact(&listmerge, mobile, name, lname, type);
                        }
                        sortlinkedlistActoNumbers(&listmerge);
                        sortlinkedlistActoNumbers(&head);
                      head= merge(listmerge, head);
                        printf(" merged list successfully \n");
                  }
                  else if (choice9 == 2)
                  {
                        printf("Enter the size of contact list to be added to the list\n");
                        struct pronode *listmerge = NULL;
                        int size;
                        scanf("%d", &size);
                        int i;
                        for (i = 0; i < size; i++)
                        {
                              printf("Enter the mobile number of the contact \n");
                              int mobile;
                              scanf("%d", &mobile);
                              printf("Enter the name of the contact \n");
                              char name[100] = "";
                              scanf("%s", name);
                              printf("Enter the last name of the contact \n");
                              char lname[100] = "";
                              scanf("%s", lname);
                              printf("Enter the type of the contact \n");
                              char type[10] = "";
                              scanf("%s", type);
                              printf("Enter the email of the contact \n");
                              char email[100] = "";
                              scanf("%s", email);
                              printf("Enter the company of the contact \n");
                              char company[100] = "";
                              scanf("%s", company);
                              printf("Enter the office number  of the contact \n");
                              int office = 0;
                              scanf("%d", &office);
                              insertProfessionalContact(&listmerge, mobile, name, lname, type, email, company, office);
                        }

                        sortlinkedlistActoNumbersofpro(&listmerge);
                        sortlinkedlistActoNumbersofpro(&prohead);
                       prohead = mergeprofectional(listmerge, prohead);
                        printf(" merged list successfully \n");
                  }
                  else
                  {
                        printf("Invalid choice \n");
                  }

                  break;
            case 8: // * done
                  printf("enter 1 to remove duplicates personal contact list and 2 to remove duplicates profectional contact list: \n");
                  int choice10;
                  scanf("%d", &choice10);
                  if (choice10 == 1)
                  {
                        printf("Enter 1 for removing the duplicates ac to mobile number\n");
                        printf("Enter 2 for removing the duplicates ac to name\n");
                        int choice2;
                        scanf("%d", &choice2);
                        if (choice2 == 1)
                        {
                              sortlinkedlistActoNumbers(&head);
                              removeduplicateswithNumbers(&head);
                        }
                        else
                        {
                              sortlinkedlistActoNames(&head);
                              removeduplicateswithNames(&head);
                        }
                  }
                  else if (choice10 == 2)
                  {
                        printf("Enter 1 for removing the duplicates ac to mobile number\n");
                        printf("Enter 2 for removing the duplicates ac to name\n");
                        int choice2;
                        scanf("%d", &choice2);
                        if (choice2 == 1)
                        {
                              sortlinkedlistActoNumbersofpro(&prohead);
                              removeduplicateswithNumbersofpro(&prohead);
                        }
                        else
                        {
                              sortlinkedlistActoNamesofpro(&prohead);
                              removeduplicateswithnamesOfProNode(&prohead);
                        }
                  }
                  else
                  {
                        printf("Invalid choice \n");
                  }

                  break;
            case 9:
            {
                  insertphonebook(&headlist);
                  displayPhonebook(headlist);
                  break;
            }
            case 0:
                  printf("Exited");
                  flag = 1;
                  break;

            default:
                  break;
            }
      }

      return 0;
}