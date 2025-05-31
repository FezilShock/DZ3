#include <stdio.h>
#include <stdlib.h>

typedef struct list_elem
{
    // Here's your code
}l_elem;
typedef struct
{
    // Here's your code
}list1;

void init_list(list1 *list_ptr);
void append(list1 *list_ptr, int value);
void print_list(list1 *list_ptr);
void clear_list(list1 *list_ptr);
int get_by_index(list1 *list_ptr, int index);
void set_by_index(list1 *list_ptr, int index, int value);
void insert_by_index(list1 *list_ptr, int index, int value);
void delete_by_index(list1 *list_ptr, int index);

int main()
{
    int i;
    int a,b,c;
    list1 mylist;
    init_list(&mylist);
    printf("append values from 0 to 9\n");
    for(i=0;i<10;i++)
    {
        append(&mylist,i);
    }
    print_list(&mylist);
    printf("get_by_index():\n");
    printf("mylist[0]==%d\n", get_by_index(&mylist,0));
    printf("mylist[4]==%d\n", get_by_index(&mylist,4));
    printf("mylist[9]==%d\n", get_by_index(&mylist,9));
    a=get_by_index(&mylist,10);
    a=get_by_index(&mylist,-10);
    a=get_by_index(&mylist,-1);
    b=get_by_index(&mylist,-4);
    c=get_by_index(&mylist,-9);
    printf("mylist[-1]==%d, mylist[-4]==%d, mylist[-9]==%d\n",a,b,c);
    printf("set_by_index():\n");
    set_by_index(&mylist,0,10);
    set_by_index(&mylist,4,10);
    set_by_index(&mylist,9,10);
    set_by_index(&mylist,10,10);
    print_list(&mylist);
    set_by_index(&mylist,-1,-10);
    set_by_index(&mylist,-4,-10);
    set_by_index(&mylist,-9,-10);
    set_by_index(&mylist,-10,-10);
    print_list(&mylist);
    clear_list(&mylist);
    insert_by_index(&mylist,0,0);
    append(&mylist,1);
    print_list(&mylist);
    insert_by_index(&mylist,0,0);
    print_list(&mylist);
    insert_by_index(&mylist,1,2);
    print_list(&mylist);
    delete_by_index(&mylist,2);
    print_list(&mylist);
    delete_by_index(&mylist,2);
    delete_by_index(&mylist,0);
    print_list(&mylist);
    clear_list(&mylist);
    append(&mylist,1);
    insert_by_index(&mylist,0,0);
    insert_by_index(&mylist,1,2);
    for(i=0;i<10;i++)append(&mylist,i);
    for(i=1;i<6;i+=2)append(&mylist,i);
    for(i=0;i<6;i+=2)append(&mylist,i);
    for(i=1;i<6;i+=2)append(&mylist,i);
    for(i=0;i<6;i+=2)append(&mylist,i);
    for(i=1;i<6;i+=2)append(&mylist,i);
    print_list(&mylist);
    for(i=0;i<mylist.size;)
    {
        if(get_by_index(&mylist,i)%2 == 0)
            delete_by_index(&mylist,i);
        else
            i++;
    }
    print_list(&mylist);
    for(i=0;i<mylist.size;)
    {
        if(get_by_index(&mylist,i)%2 == 1)
            delete_by_index(&mylist,i);
        else
            i++;
    }
    print_list(&mylist);
    clear_list(&mylist);
    return 0;
}
//
//  Here is your code of implemented functions
//
