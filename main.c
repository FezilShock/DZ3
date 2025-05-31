#include <stdio.h>
#include <stdlib.h>

typedef struct list_elem
{
    // Here's your code
    int x;
    struct list_elem *next;
}l_elem;

typedef struct
{
    // Here's your code
    l_elem *first;
    l_elem *last;
    int size;
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

void init_list(list1 *list_ptr)
{
    list_ptr->first = NULL;
    list_ptr->last = NULL;
    list_ptr->size = 0;
}

void append(list1 *list_ptr, int value)
{
    l_elem *tmp = NULL;
    tmp = (l_elem *) malloc(sizeof(l_elem));
    if(tmp)
    {
        if(list_ptr->size == 0)
        {
            list_ptr->first = tmp;
            list_ptr->last = tmp;
        }
        tmp->x = value;
        list_ptr->last->next = tmp;
        list_ptr->last = tmp;
        list_ptr->last->next = list_ptr->first;
        list_ptr->size++;
    }
    else
    {
        printf("append(): Not enought memory\n");
    }
}

void print_list(list1 *list_ptr)
{
    int i;
    l_elem *tmp = NULL;
    tmp = list_ptr->first;
    if(list_ptr->size)
    {
        printf("print_list(): ");
        for(i = 0; i < list_ptr->size; i++)
        {
            printf("%d ", tmp->x);
            tmp = tmp->next;
        }
        printf("\n");
    }
    else 
    {
        printf("print_list(): list is empty\n");
    }
}

void clear_list(list1 *list_ptr)
{
    l_elem *tmp1 = NULL;
    l_elem *tmp2 = NULL;
    if(list_ptr->size)
    {
        tmp1 = list_ptr -> first;
        printf("clear_elemets: ");
        for(; list_ptr->size; list_ptr->size--)
        {
            tmp2 = tmp1->next;
            printf("%d ", tmp1->x);
            free(tmp1);
            tmp1 = tmp2;
        }
        printf("\n");
        list_ptr->first = NULL;
        list_ptr->last = NULL;
    }
    else
    {
        printf("clear_list(): list is empty\n");
    }
}

l_elem *move (list1 *list_ptr, int n)
{
    l_elem *p = list_ptr->first;
    if(n >= 0)
    {
        for(; n; n--)
        {
            p = p->next;
        }
    }
    else
    {
        for(n = list_ptr->size + n; n; n--)
        {
            p = p->next;
        }
    }
    return p;
}

int get_by_index(list1 *list_ptr, int index)
{
    l_elem *tmp = NULL;
    int res = 0;
    if(list_ptr->size)
    {
        if(abs(index) < list_ptr->size)
        {
            tmp = move(list_ptr, index);
            res = tmp -> x;
        }
        else 
        {
            printf("get_by_index(%d): index %d out of range\n", index, index);
        }
    }
    else 
    {
        printf("get_by_index(%d): list is empty\n", index);
    }
    return res;
}

void set_by_index(list1 *list_ptr, int index, int value)
{
    l_elem *tmp = NULL;
    if(list_ptr->size)
    {
        if(abs(index) < list_ptr->size)
        {
            tmp = move(list_ptr, index);
            tmp -> x = value;
        }
        else 
        {
            printf("set_by_index(%d): index %d out of range\n", index, index);
        }
    }
    else
    {
        printf("set_by_index(%d): list is empty\n", index);
    }
}

void insert_by_index(list1 *list_ptr, int index, int value)
{
    l_elem *tmp = NULL, *tmp1 = NULL, *tmp2 = NULL;
    if(abs(index) < list_ptr->size)
    {
        tmp = (l_elem *) malloc(sizeof(l_elem));
        if(tmp)
        {
            tmp1 = move(list_ptr, index - 1);
            tmp2 = move(list_ptr, index);
            tmp->x = value;
            tmp->next = tmp2;
            tmp1->next = tmp;
            list_ptr->size++;
            if(index == 0)
            {
                list_ptr->first = tmp;
            }
        }
        else 
        {
            printf("insert_by_index(%d): Not enough memory\n", index);
        }
    }
    else
    {
        printf("insert_by_index(%d): index %d out of range\n", index, index);
    }
}

void delete_by_index(list1 *list_ptr, int index)
{
    l_elem *tmp = NULL, *tmp1 = NULL, *tmp2 = NULL;
    if(abs(index) < list_ptr->size)
    {
        if(list_ptr->size == 1)
        {
            free(list_ptr->first);
            list_ptr->first = NULL;
            list_ptr->last = NULL;
            list_ptr->size = 0;
        }
        else
        {
            tmp = move(list_ptr, index);
            if(tmp == list_ptr->first)
                list_ptr->first = list_ptr->first->next;
            if(tmp == list_ptr->last)
                list_ptr->last = move(list_ptr, index - 1);
            tmp2 = tmp->next;
            tmp1 = move(list_ptr, index - 1 );
            tmp1->next = tmp2;
            free(tmp);
            list_ptr->size--;
        }
    }
    else
    {
        printf("delete_by_index(%d): index %d out of range",index, index);
    }
}
