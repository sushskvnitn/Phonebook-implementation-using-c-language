#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book_list{
	char title_of_book[20];
	char author[20];
	int number_of_copies_issued;
	int number_of_copies_available;
	struct book_list* next;
}Book_list;

typedef struct Request_queue{
	char name_of_student[20];
	char title_of_book[20];
	struct Request_queue* next;
}request_queue;

typedef struct Borrower_list{
	char name_of_student[20];
	char title_of_book[20];
	int date_of_issue;
	int date_of_return;
	int submit;
	struct Borrower_list* next;
}borrower_list;

// Question - 1 
void display(Book_list* books, request_queue* requests, borrower_list* borrowers){
	printf("\n\n  Question - 1 \n\n");
	Book_list* blptr;
	borrower_list *bptr,*temp[3];
	request_queue* rptr=requests;
	int found,status,count,i,date=20220405;
	while(rptr!=NULL){
		//Finding if the book exists
		found=0;
		blptr=books;
		while(blptr!=NULL && found==0){
			if(strcmp(rptr->title_of_book,blptr->title_of_book)==0){
				found=1;
			}	
			else{
				blptr=blptr->next;
			}
		}
		if(found==1 && blptr->number_of_copies_available>0){
			//Checking if borrower is not a defaulter
			status=1;
			bptr=borrowers;
			count=0;
			i=0;
			while(bptr!=NULL && count<3){
				if(strcmp(rptr->name_of_student,bptr->name_of_student)==0){
					temp[i]=bptr;
					count++;
					i++;
				}
				bptr=bptr->next;
			}
			if(count==0){
				status=1;
			}
			else{
				while(count>0 && status==1){
					if(temp[count-1]->submit==0){
						if(temp[count-1]->date_of_return<date){
							status=0;
						}
					}
					count--;
				}
			}
			if(status==1){
				printf("%s\n",rptr->name_of_student);
			}
		}
		rptr=rptr->next;
	}
	return;
}

// Question - 2
void most_demand(request_queue *requests, Book_list *books){
	request_queue *rptr;
	Book_list *bptr,*max_demand;
	bptr=books;
	max_demand=NULL;
	int max=0,count;
	while(bptr!=NULL){
		count=0;
		rptr=requests;
		while(rptr!=NULL){
			if(strcmp(rptr->title_of_book,bptr->title_of_book)==0){
				count++;
			}
			rptr=rptr->next;
		}
		if((count+bptr->number_of_copies_issued) > max){
			printf("OK %d\n",max);
			max=count+bptr->number_of_copies_issued;
			max_demand=bptr;
		}
		bptr=bptr->next;
	}
	if(max_demand!=NULL){
		printf("%s\n",max_demand->title_of_book);
	}
	else{
		printf("There is no book in demand\n");
	}
	return;
}

// Question - 4

Book_list* merge_books_copies_issued(book_list *ptr1,book_list *ptr2){
	Book_list *result,*lptr,*nptr,*tail;
	lptr=ptr1;
	nptr=ptr2;
	if(lptr->number_of_copies_issued>nptr->number_of_copies_issued){
		result=lptr;
		lptr=lptr->next;
	}
	else{
		result=nptr;
		nptr=nptr->next;
	}
	tail=result;
	while(lptr!=NULL && nptr!=NULL){
		if(lptr->number_of_copies_issued>nptr->number_of_copies_issued){
			tail=tail->next=lptr;
			lptr=lptr->next;
		}
		else{
			tail=tail->next=nptr;
			nptr=nptr->next;
		}
	}
	if(lptr!=NULL){
		tail->next=lptr;
	}
	else{
		tail->next=nptr;
	}
	return result;
}

Book_list* divide_books(Book_list *books){
	Book_list *slow,*fast,*ans;
	slow=books;
	fast=(books->next)->next;
	while(fast!=NULL){
		fast=fast->next;
		slow=slow->next;
		if(fast!=NULL){
			fast=fast->next;
		}
	}
	ans=slow->next;
	slow->next=NULL;
	return ans;
}

Book_list* sort_book_list_copies_issued(Book_list *books){
	Book_list *ptr1,*ptr2;
	ptr1=books;
	if(ptr1!=NULL && ptr1->next!=NULL){
		ptr2=divide_books(books);
		ptr1=sort_book_list_copies_issued(ptr1);
		ptr2=sort_book_list_copies_issued(ptr2);
		ptr1=merge_books_copies_issued(ptr1,ptr2);
	}
	return(ptr1);
}

borrower_list* sort_borrower_list(borrower_list *borrowers, Book_list *books){
	books=sort_book_list_copies_issued(books);
	borrower_list *prev,*curr,*ans,*root=NULL;
	Book_list *blptr;
	blptr=books;
	prev=NULL;
	curr=borrowers;
	while(blptr!=NULL){
		curr=borrowers;
		while(curr!=NULL){
			if(strcmp(curr->title_of_book,blptr->title_of_book)==0){
				if(prev!=NULL){
					prev->next=curr->next;
				}
				else{
					borrowers=curr->next;
				}
				if(root==NULL){
					root=curr;
					ans=curr;
				}
				else{
					ans->next=curr;
					ans=curr;
				}
				if(prev==NULL){
					curr=borrowers;
				}
				else{
					curr=prev->next;
				}
			}
			else{
				prev=curr;
				curr=curr->next;
			} 
		}
		blptr=blptr->next;
	}
	ans->next=NULL;
	return root;
}

void print_borrowers(borrower_list *borrowers){
	borrower_list *bptr=borrowers;
	while(bptr!=NULL){
		printf("%s\n",bptr->name_of_student);
		bptr=bptr->next;
	}
	return;
}

// Question - 5

Book_list* merge_books_copies_available(book_list *ptr1,book_list *ptr2){
	Book_list *result,*lptr,*nptr,*tail;
	lptr=ptr1;
	nptr=ptr2;
	if(lptr->number_of_copies_available>nptr->number_of_copies_available){
		result=lptr;
		lptr=lptr->next;
	}
	else{
		result=nptr;
		nptr=nptr->next;
	}
	tail=result;
	while(lptr!=NULL && nptr!=NULL){
		if(lptr->number_of_copies_available>nptr->number_of_copies_available){
			tail=tail->next=lptr;
			lptr=lptr->next;
		}
		else{
			tail=tail->next=nptr;
			nptr=nptr->next;
		}
	}
	if(lptr!=NULL){
		tail->next=lptr;
	}
	else{
		tail->next=nptr;
	}
	return result;
}

Book_list* sort_book_list_copies_available(Book_list *books){
	Book_list *ptr1,*ptr2;
	ptr1=books;
	if(ptr1!=NULL && ptr1->next!=NULL){
		ptr2=divide_books(books);
		ptr1=sort_book_list_copies_available(ptr1);
		ptr2=sort_book_list_copies_available(ptr2);
		ptr1=merge_books_copies_available(ptr1,ptr2);
	}
	return(ptr1);
}

void display_books(Book_list *books){
	Book_list *blptr;
	blptr=books;
	while(blptr!=NULL){
		printf("Title : %s\n",blptr->title_of_book);
		printf("Author : %s\n",blptr->author);
		blptr=blptr->next;
	}
	return;
}

// Question - 6

borrower_list* remove_duplicates(borrower_list *borrowers){
	int date=20220405;
	borrower_list *dptr,*prev,*curr,*ptr;
	curr=borrowers;
	prev=NULL;
	dptr=NULL;
	while(curr!=NULL){
		if(curr->date_of_return<date && curr->submit==0){
			if(prev==NULL){
				borrowers=borrowers->next;
			}
			else{
				prev->next=curr->next;
			}
			if(dptr==NULL){
				dptr=curr;
				ptr=curr;
			}
			else{
				ptr->next=curr;
				ptr=curr;
			}
			curr=curr->next;
		}
		else{
			prev=curr;
			curr=curr->next;
		}
	}
	ptr->next=NULL;
	return dptr;
}

void print_defaulters(borrower_list *defaulters){
	borrower_list *dptr;
	dptr=defaulters;
	while(dptr!=NULL){
		printf("Name of student : %s\n",dptr->name_of_student);
		printf("Title of book : %s\n",dptr->title_of_book);
		dptr=dptr->next;
	}
	return;
}

// Question - 7

void asking_for_books_again(borrower_list *borrowers, request_queue *requests){
	request_queue *rptr;
	borrower_list *bptr;
	int status;
	rptr=requests;
	while(rptr!=NULL){
		bptr=borrowers;
		status=0;
		while(bptr!=NULL && status==0){
			if(strcmp(rptr->name_of_student,bptr->name_of_student)==0){
				status=1;
			}
			bptr=bptr->next;
		}
		if(status==1){
			printf("%s\n",rptr->name_of_student);
		}
		rptr=rptr->next;
	}
	return;
}

// Question - 8

void available_books(Book_list *books, request_queue *requests){
	Book_list *blptr;
	request_queue *rptr;
	blptr=books;
	int status;
	while(blptr!=NULL){
		if(blptr->number_of_copies_available>0){
			rptr=requests;
			status=0;
			while(rptr!=NULL && status==0){
				if(strcmp(rptr->title_of_book,blptr->title_of_book)){
					status=1;
				}
				else{
					rptr=rptr->next;
				}
			}
			if(status==1){
				printf("%s\n",blptr->title_of_book);
			}
		}
		blptr=blptr->next;
	}
}

//Question - 9

void books_not_issued(Book_list *books){
	Book_list *blptr=books;
	while(blptr!=NULL){
		if(blptr->number_of_copies_issued==0){
			printf("%s\n",blptr->title_of_book);
		}
		blptr=blptr->next;
	}
	return;
}

// Question - 10

void max_no_of_books(request_queue *requests){
	int max,count,n=0;
	request_queue *rptr,*curr;
	rptr=requests;
	max=0;
	while(rptr!=NULL){
		curr=rptr->next;
		count=1;
		while(curr!=NULL){
			if(strcmp(rptr->name_of_student,curr->name_of_student)){
				count++;
			}
			curr=curr->next;
		}
		if(count>max){
			max=count;
		}
		rptr=rptr->next;
	}
}

int main(){
	Book_list *books=NULL,*blptr,*blcurr=NULL;
	request_queue *requests=NULL,*rptr,*rcurr=NULL;
	borrower_list *borrowers=NULL,*bptr,*bcurr=NULL;
	int i,count,j;
	char str[20];
	printf("Enter the number of books : ");
	scanf("%d",&count);
	i=0;
	while(i<count){
		blptr=NULL;
		blptr=(Book_list*)malloc(sizeof(Book_list));
		printf("Enter title of book : ");
		scanf("%s",blptr->title_of_book);
		printf("Enter the name of author : ");
		scanf("%s",blptr->author);
		printf("Enter the copies issued : ");
		scanf("%d",&blptr->number_of_copies_issued);
		printf("Enter the copies available : ");
		scanf("%d",&blptr->number_of_copies_available);
		if(books==NULL){
			blcurr=blptr;
			books=blptr;
		}
		else{
			blcurr->next=blptr;
			blcurr=blptr;
		}
		i++;
	}
	blcurr->next=NULL;
	printf("Enter the number of borrowers : ");
	scanf("%d",&count);
	i=0;
	while(i<count){
		bptr=(borrower_list*)malloc(sizeof(borrower_list));
		printf("Enter the name of the student : ");
		scanf("%s",bptr->name_of_student);
		printf("Enter the title of the book : ");
		scanf("%s",bptr->title_of_book);
		printf("Enter date of issue : ");
		scanf("%d",&bptr->date_of_issue);
		printf("Enter the date of return : ");
		scanf("%d",&bptr->date_of_return);
		printf("Enter 1 if sbmitted, 0 if not submitted : ");
		scanf("%d",&bptr->submit);
		if(borrowers==NULL){
			bcurr=bptr;
			borrowers=bptr;
		}
		else{
			bcurr->next=bptr;
			bcurr=bptr;
		}
		i++;
	}
	bcurr->next=NULL;
	printf("Enter number of requests : ");
	scanf("%d",&count);
	i=0;
	while(i<count){
		
		rptr=(request_queue*)malloc(sizeof(request_queue));
		printf("Enter the name of the student : ");
		scanf("%s",rptr->name_of_student);
		printf("Enter the title of the book : ");
		scanf("%s",rptr->title_of_book);
		
		if(requests==NULL){
			rcurr=rptr;
			requests=rptr;
		}
		else{
			rcurr->next=rptr;
			rcurr=rptr;
		}
		i++;
	}
	available_books(books, requests);
	return 0;
}
