#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    int id;
    struct node_type *left, *right;

} NodeT;

NodeT *root;





NodeT *createBinTreeFromFile(FILE* f)
{
    NodeT *p;

    int c;

    fscanf(f, "%d", &c);

    if ( c == 0 )
        return NULL;
    else
    {
        p = ( NodeT *) malloc( sizeof( NodeT ));
        if ( p == NULL )
            return 0;

        p->id = c;
        p->left = createBinTreeFromFile(f);
        p->right = createBinTreeFromFile(f);
    }
    return p;
}

NodeT *insertNode( NodeT *nod, int key )
{
    if(nod==NULL)
    {
        NodeT *p;
        p = ( NodeT *) malloc( sizeof( NodeT ));
        if ( p == NULL )
            return 0;

        p->id = key;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    else if (nod->id > key)
    {
        nod->left = insertNode(nod->left,key);
    }
    else if (nod->id < key)
    {
        nod->right = insertNode(nod->right,key);
    }
    return nod;
}
NodeT* findNodeRec(NodeT* nod, int key)
{
    if (nod == NULL || nod->id == key)
        return nod;

    if (nod->id < key)
        return findNodeRec(nod->right, key);

    return findNodeRec(nod->left, key);
}
NodeT *Cautare( NodeT *p,int key)
{
    if ( p != NULL &&p->id==key)
    {
        return p;
        NodeT*t=Cautare(p->left,key);
        if(t) return t;
        return Cautare(p->right,key);

    }
}




void preorder( NodeT *p )
{
    if ( p != NULL )
    {
        printf( "%d ", p->id );
        preorder( p->left);
        preorder( p->right);

    }
}
void postorder( NodeT *p )
{
    if ( p != NULL )
    {
        postorder( p->left);
        postorder( p->right);
        printf( "%d ", p->id );

    }
}
void inorder( NodeT *p )
{
    if ( p != NULL )
    {
        inorder( p->left);
        printf( "%d ", p->id );
        inorder( p->right);


    }
}
int leaf_node(NodeT *node)
{
    if ( node != NULL )
    {
        if(node->left==NULL && node->right==NULL)
            return 1;
        else return leaf_node( node->left)+leaf_node( node->right);



    }
    else return 0;
}
int daddys(NodeT *node)
{
    if ( node != NULL )
    {
        if(node->left==NULL && node->right==NULL)
            return 0;
        else return daddys( node->left)+daddys( node->right)+1;



    }
    else return 0;
}

int height(NodeT *node)
{
    if ( node != NULL )
    {
        if(node->left==NULL && node->right==NULL)
            return 1;
        else
        {
            int x=height( node->left);
            int y=height( node->right);
            if(x>y)return x+1;
            else return y+1;
        }


    }
    else return 0;
}
void eliminare( NodeT *p )
{
    if ( p != NULL )
    {
        postorder( p->left);
        postorder( p->right);
        free(p);

    }
}



int main()
{


    FILE *f = fopen("ArboreBinar.txt", "r");

    if (!f)
    {
        printf("Nu se poate deschide fisierul ArboreBinar.txt\n");
        return -1;
    }

    root = NULL;
    //root = ( NodeT *) malloc( sizeof( NodeT ));
    //root->id=40;

    fclose(f);

    root = insertNode(root,10);
    root = insertNode (root, 4);
    root = insertNode (root, 11);
    root = insertNode (root, 5);
    root = insertNode (root, 7);
    root = insertNode (root, 6);

    /*NodeT *p=findNodeRec(root, 7);

    printf("%d",p->id);*/




}
