#include "optim.h"
#include "front.h"

int Optimization_Const  ( struct Node_t **tree_node ) // +
{
    if ( *tree_node == nullptr || (*tree_node)->right == nullptr || (*tree_node)->left == nullptr ) {
$
        return 0;
    }
$   if ( (*tree_node)->left->type  == NODE_TYPE_NUM &&
         (*tree_node)->right->type == NODE_TYPE_NUM  ) {

$       (*tree_node)->value = (int)Eval_Body ( *tree_node, 0 );
$       (*tree_node)->type = NODE_TYPE_NUM;
$       Node_Free ( &((*tree_node)->left)  );
$       Node_Free ( &((*tree_node)->right) );

        return OK_OCCURR;
    }
    else {
$
        return ( Optimization_Const ( &((*tree_node)->left ) ) ||
                 Optimization_Const ( &((*tree_node)->right) ) );
    }
}

int Optimization_Option ( struct Node_t **tree_node )  // +-
{
$   if ( *tree_node == nullptr || (*tree_node)->right == nullptr || (*tree_node)->left == nullptr ) {
$
        return 0;
    }
$   if ( (*tree_node)->type == NODE_TYPE_OP && (*tree_node)->value == OP_MUL ) {
        if ( (*tree_node)->left->value  == 0 || (*tree_node)->right->value == 0 ) {
$           (*tree_node)->value = 0;
$           (*tree_node)->type  = NODE_TYPE_NUM;
$           Node_Free ( &((*tree_node)->left)  );
$           Node_Free ( &((*tree_node)->right) );

            return OK_OCCURR;
        }
        if ( (*tree_node)->left->value  == 1 ) {  // func
            Node_Free ( &((*tree_node)->left) );
            (*tree_node) = (*tree_node)->right;

            return OK_OCCURR;
        }
        else if ( (*tree_node)->right->value == 1 ) {
            Node_Free ( &((*tree_node)->right) );
            *tree_node = (*tree_node)->left; // for this moment

            return OK_OCCURR;
        }
$
        return 0;
    }
    /* else if ( (*tree_node)->value == OP_ADD || (*tree_node)->value == OP_SUB ) {
        if ( (*tree_node)->right->type  == NODE_TYPE_NUM &&
             (*tree_node)->right->value == 0 ) {
            Node_Free ( &((*tree_node)->right) );
            *tree_node = (*tree_node)->left;
$
            return OK_OCCURR;
        }
        else if ( (*tree_node)->left->type  == NODE_TYPE_NUM &&
                  (*tree_node)->left->value == 0 ) {
            Node_Free ( &((*tree_node)->left) );
            *tree_node = (*tree_node)->right;
$           //

            return OK_OCCURR;
        }
$
        return ( Optimization_Option ( &(*tree_node)->left ) ||
                 Optimization_Option ( &(*tree_node)->right )  );
    }  */
    else {
$
       return ( Optimization_Option ( &(*tree_node)->left ) ||
                Optimization_Option ( &(*tree_node)->right )  );
    }
}

void Optimization ( struct Node_t *tree_node )
{
    while ( Optimization_Const  ( &tree_node ) || Optimization_Option ( &tree_node ) );
}
