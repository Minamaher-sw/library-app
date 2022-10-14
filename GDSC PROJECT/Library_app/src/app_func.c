/*
 * app_func.c
 *
 *  Created on: ٠٧‏/١٠‏/٢٠٢٢
 *      Author: DELL
 */
# include "app_func.h"
// head->NULL empty linked list
struct node *head=NULL;
//static until any change is saved (last value ) (call function )
static shun16 count_book=0;

/***************************************************************************/
                 /********* Display option ***********/
ERROR_TYPE choose_option()
{
	printf("\n-----------------------------------------------\n"
		   "To view all books 			Enter'1' \n"
		   "To add a new book 			Enter'2' \n"
		   "To delete a book			Enter'3'\n"
		   "To view NO of available book		Enter'4'\n"
		   "To exist the library app 		Enter'5'\n"
		   "------------------------------------------------\n"
		   "--------> Your choose is :  ");

	return lib_RT_OK;
}

/***************************************************************************/
                  /******** add new book ************/
ERROR_TYPE add_new_book(chun8 Enter_Book_name[],chun8 Enter_author_name[],losi32 Enter_Book_Price)
{
	/*
	 * Malloc used to reserve block address in memory
	 * return to first address in this block stored in (ptr_new_book)
	 * if not found empty location in memory return null
	 *
	 */
  struct node *ptr_new_book=(struct node*)malloc(sizeof(struct node));
  assert(ptr_new_book!=NULL);//until project not give error (handle if no location in memory )
  ptr_new_book->next=head;
  head=ptr_new_book;
  /*
   * To author name
   * loop to store string( author name)
   *
   */
   int author_index=0;
   while(Enter_author_name[author_index]!='\0')
    {
  	  ptr_new_book->book_author[author_index]=Enter_author_name[author_index];
  	author_index++;
    }
    ptr_new_book->book_author[author_index]='\0';

  /*
   * to enter book name
   * loop to store string (book_name)
   */
    int book_name_index=0;
  while(Enter_Book_name[book_name_index]!='\0')
  {

	  ptr_new_book->book_name[book_name_index]=Enter_Book_name[book_name_index];
	  book_name_index++;
  }
  ptr_new_book->book_name[book_name_index]='\0';


   //to Enter book price
   ptr_new_book->book_price=Enter_Book_Price;

   //to count number of new book
   count_book++;
   return lib_RT_OK;

}

/*****************************************************************************/
                   /******* to display all books *******/
ERROR_TYPE view_all_book()
{
    /*
     * first condition to check if linked list is empty
     * second to display all books
     */
	if(head==NULL)
	{
		printf("--------------------------------------\n");
		printf("the library is empty. no book To view ! \n ");
		printf("--------------------------------------");
	}
	else
	{
		// pointer of struct to store head address (optional)
		struct node* ptr_view=head;
        //to display Book number
		printf("--------------------------------------\n");
		printf("Book Number : %hu \n",count_book);
		//loop to display all book until end of linked list
		while(ptr_view!=NULL)
		{
			printf("--------------------------------------\n");
		    printf("Book name   : %s \n",ptr_view->book_name);
			printf("Book author : %s \n",ptr_view->book_author);
			printf("Book price  : %ld \n",ptr_view->book_price);
			printf("--------------------------------------\n");
			//to display next node
			ptr_view=ptr_view->next;

		}

	}
	return lib_RT_OK;

}

/*****************************************************************************/
                  /************ delete book *********/
ERROR_TYPE delete_book(chun8 book_del_number)
{

	struct node *prev;
	struct node *current;
	/*
	 * 4       condition
	 * 1       to check if one book enter so one node  so direct free(head)
	 * 2       count_book==book_del_number because of (insert at first arrange of book change so
	           if have 3 book
	           num 3 is num 1 in linked list  )
	           so head=head->next free (head direct)
	 *3        because of insert at first also  book num 1 is num3  do loop until reach for it
	 *4        to delete any middle node
	 *4         (count_book-book_del_number) this condition until reach to correct node
	 */
	if(count_book==1)
	{
		// there are one node
		prev=head;
		head=NULL;
		free(prev);
		count_book--;
		printf("--------------------------------------\n");
		printf(" Book delete successfully 12 ! \n ");
		printf("--------------------------------------\n");
	}
	else if(count_book==book_del_number)
	{
		struct node*del=head;
		head=head->next;
		free(del);
		count_book--;
		printf("--------------------------------------\n");
		printf(" Book delete successfully ! \n ");
		printf("--------------------------------------\n");
	}
	else if(book_del_number==1)
	{
		current=head;
		while(current->next!=NULL)
		{
			prev=current;
			current=current->next;
		}
		prev->next=NULL;
		free(current);
		count_book--;
		printf("--------------------------------------\n");
		printf(" Book delete successfully ! \n ");
		printf("--------------------------------------\n");
	}
	else
	{
	 for(int i=0 ; i<(count_book-book_del_number) ; i++)
	 {
		 prev=head;
		 head=head->next;
		 current=head;
	 }
	 prev->next=current->next;
	 free(current);
	 count_book--;
	 printf("--------------------------------------\n");
	 printf(" Book delete successfully ! \n ");
	 printf("--------------------------------------\n");
	}
      return lib_RT_OK;
}

/********************************************************************************/
                /*********** view available book ***********/
ERROR_TYPE view_available_book()
{
	if (count_book==0)
		 printf("----------------------------------------\n"
				"sorry the library is empty. no book To view !");
	else{
		printf("--------------------------------------\n");
		printf("Number of available book is %hu \n",count_book);
		printf("--------------------------------------\n");
	}
	return lib_RT_OK;

}
