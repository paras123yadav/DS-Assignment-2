
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 10

//struct for node
struct node {
    char *value;            
    struct node *p_left;
    struct node *p_right;
};

//use typedef to make calling the compare function easier
typedef int (*Compare)(const char *, const char *);

//inserts elements into the tree
void insert(char* key, struct node** leaf, Compare cmp)
{
    int res;
    if( *leaf == NULL ) {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->value = malloc( strlen (key) +1 );     
        strcpy ((*leaf)->value, key);                   
        (*leaf)->p_left = NULL;
        (*leaf)->p_right = NULL;
        //printf(  "\nnew node for %s" , key);
    } else {
        res = cmp (key, (*leaf)->value);
        if( res < 0)
            insert( key, &(*leaf)->p_left, cmp);
        else if( res > 0)
            insert( key, &(*leaf)->p_right, cmp);
        else                                            
            printf ("Key '%s' already in tree\n", key);
    }
}

//compares value of the new node against the previous node
int CmpStr(const char *a, const char *b)
{
    return (strcmp (a, b));    
}

char *input( void )              //input of string
{
    static char line[MAXLEN+1];       
    printf("enter a string : ");
    fgets( line, sizeof line, stdin );
    return ( strtok(line, "\n" ));   
}

void in_order(struct node *root)
{
    if( root != NULL ) {
        in_order(root->p_left);
        printf("   %s\n", root->value);    
        in_order(root->p_right);
    }
}
void pre_order(struct node *root)
{
    if( root != NULL ) {
        printf("   %s\n", root->value);
        pre_order(root->p_left);    
        pre_order(root->p_right);
    }
}
void post_order(struct node *root)
{
    if( root != NULL ) {
        post_order(root->p_left);    
        post_order(root->p_right);
        printf("   %s\n", root->value);
    }
}


void delete_tree(struct node** leaf)           //delete the current tree
{
    if( *leaf != NULL ) {
        delete_tree(&(*leaf)->p_left);
        delete_tree(&(*leaf)->p_right);
        free( (*leaf)->value );       
        free( (*leaf) );
    }
}

int main()
{
    struct node *p_root = NULL;
    char *value;
    int choice;
    printf("\npress 1 to insert a string");
    printf("\npress 2 to print inorder");
    printf("\npress 3 to print preorder");
    printf("\npress 4 to print postorder");
    printf("\npress 5 to delete current tree");
    printf("\npress 6 to end");
    while(1)
    {
        printf("\nenter your choice:");
        scanf("%d",&choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            value = input();
            printf ("%s\n", value);
            insert(value,  &p_root, (Compare)CmpStr);
            break;
        case 2:
            in_order(p_root);
            break;
        case 3:
            pre_order(p_root);
            break;
        case 4:
            post_order(p_root);
            break;        
        case 5:
            delete_tree(&p_root);
            printf("Tree destroyed");
            p_root = NULL;
            break;
        case 6:
             end(0);
             break;                  
        default:
              printf("\nwrong choice");
            break;
        }
    }
   
return 0;
}