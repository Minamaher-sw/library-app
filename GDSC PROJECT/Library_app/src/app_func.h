/*
 * app_func.h
 *
 *  Created on: ٠٧‏/١٠‏/٢٠٢٢
 *      Author: DELL
 */

#ifndef APP_FUNC_H_
#define APP_FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"C:\Users\DELL\Desktop\GDSC PROJECT\Library_app\lib_abb/Error_type.h"
#include"C:\Users\DELL\Desktop\GDSC PROJECT\Library_app\lib_abb/Std_type_var.h"


/**************************** struct node (self_refenetial struct) *****************/
struct node
{
 chun8  book_name[20];
 chun8  book_author[20];
 losi32 book_price;
 struct node *next;

};
/********************************** Function Prototype ******************************/
ERROR_TYPE choose_option();
ERROR_TYPE add_new_book(chun8*Enter_Book_name,chun8*Enter_author_name,losi32 Enter_Book_Price);
ERROR_TYPE view_all_book();
ERROR_TYPE delete_book(chun8 book_del_number);
ERROR_TYPE view_available_book();
#endif /* APP_FUNC_H_ */
