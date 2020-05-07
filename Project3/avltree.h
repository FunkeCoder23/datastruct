#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "dsexceptions.h"
#include <algorithm>
#include <iostream>


// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted
#include <queue>
template <typename Comparable>
class AvlTree
{
  public:
    AvlTree( ) : root{ nullptr }
      { }
    
    AvlTree( const AvlTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }

    AvlTree( AvlTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    ~AvlTree( )
    {
        makeEmpty( );
    }

    /**
     * Deep copy.
     */
    AvlTree & operator=( const AvlTree & rhs )
    {
        AvlTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move.
     */
    AvlTree & operator=( AvlTree && rhs )
    {
        std::swap( root, rhs.root );
        
        return *this;
    }
    
    
    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    
    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
     
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( Comparable && x )
    {
        insert( std::move( x ), root );
    }
     
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }
    void numNodes()
    {
        std::cout << numNodes(root)<<std::endl;
    }
    void printLevelOrder()
    {
        printLevelOrder(root);
    }
    void numLeaves()
    {
        std::cout << numLeaves(root)<<std::endl;
    }
    void numFull()
    {
        std::cout << numFull(root) << std::endl;
    }
    
    void printTree( ) const
    {
        if( isEmpty( ) )
            std::cout << "Empty tree" << std::endl;
        else{
            printTree( root );
       
        }
        
        
    }

    void outputRange()
    {
        int lower=0, higher=0;
        std::cout << "Please enter the lower bound ";
        std::cin >> lower;
        std::cout << std::endl;
        std::cout << "Please enter the higher bound ";
        std::cin >> higher;
        outputRange(root,lower,higher);
        std::cout <<std::endl;
    }
  private:
    struct AvlNode
    {
        Comparable element;
        AvlNode   *left;
        AvlNode   *right;
        int       height;

        AvlNode( const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : element{ ele }, left{ lt }, right{ rt }, height{ h } { }
        
        AvlNode( Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
    };

    AvlNode *root;
    //This function is O(N) because it could have to iterate though the entire tree
    //to get the values 
    void outputRange( AvlNode * & t, const int & lower, const int & higher)
    {
        if (t==nullptr) return;
        if (lower < t->element)
            outputRange(t->left, lower, higher);
        if ( lower <= t->element && higher>= t->element )
            std::cout<<t->element<<" ";
              
            /* If root->data is smaller than k2,
                then only we can get o/p keys
                in right subtree */
            if ( higher> t->element )
                outputRange(t->right, lower, higher);
    }
        
    //Numfull is O(N) time because of the while loop and it would
    //have to iterate though the whole tree
    
    int numFull( AvlNode * & t)
    {
        if (!t) return 0;
        std::queue<AvlNode *> qu;
        int count =0;
        qu.push(t);
        while (!qu.empty())
        {
            AvlNode * tmp = qu.front();
            qu.pop();
            if (tmp ->left&& tmp->right)
                count++;
            if (tmp ->left != nullptr)
                qu.push(tmp->left);
            if (tmp-> right !=nullptr)
                qu.push(tmp->right);
        }
        return count;
    }
    //This would be O(N) because you would have to iterate though the
    //entire tree counts the number if nodes that dont have any children
    int numLeaves( AvlNode * & t)
    {
        if (t==nullptr) return 0;
        if( t->left == nullptr && t->right == nullptr)
            return 1;
        else
        {
            return numLeaves(t->left)+numLeaves(t->right);
        }
        
    }
    //This would be O(N) because you would have to iterate though the
    //entire tree but this function prints the number of nodes in each
    //side of the tree
    int numNodes( AvlNode * & t)
    {
        {
            if(t == nullptr){
                return 0;
            }
            else{
                return 1 + numNodes(t->left) + numNodes(t->right);
            }
        }
    }
    //This would be O(N) because you would have to iterate though the
    //entire tree but this function prints the tree level by level
    void printLevelOrder (AvlNode * & t)
    {
        if (t==nullptr) return;
        std::queue<AvlNode *> qu;
        qu.push(t);
        while (!qu.empty())
        {
            int nodeCount = qu.size();
            while (nodeCount > 0 )
            {
                AvlNode * node = qu.front();
                std::cout << node->element<< " ";
                qu.pop();
                if (node->left != nullptr)
                {
                    qu.push(node->left);
                }
                if (node->right!=nullptr)
                {
                    qu.push(node->right);
                }
                --nodeCount;
            }
           
        }
         std::cout << std::endl;
    }
   

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, AvlNode * & t )
    {
        if( t == nullptr )
            t = new AvlNode{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        
        balance( t );
    }

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( Comparable && x, AvlNode * & t )
    {
        if( t == nullptr )
            t = new AvlNode{ std::move( x ), nullptr, nullptr };
        else if( x < t->element )
            insert( std::move( x ), t->left );
        else if( t->element < x )
            insert( std::move( x ), t->right );
        
        balance( t );
    }
     
    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, AvlNode * & t )
    {
        if( t == nullptr )
        {
            std::cout << "Item not found"<< std::endl;
            return;   // Item not found; do nothing
        }
        
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            AvlNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
            std::cout << "Item deleted" << std::endl;
        }
        
        balance( t );
    }
    
    static const int ALLOWED_IMBALANCE = 1;

    // Assume t is balanced or within one of being balanced
    void balance( AvlNode * & t )
    {
        if( t == nullptr )
            return;
        
        if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
            if( height( t->left->left ) >= height( t->left->right ) )
                rotateWithLeftChild( t );
            else
               // doubleWithLeftChild( t );
                fastDoubleWithLeftChild(t);
        else
        if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
            if( height( t->right->right ) >= height( t->right->left ) )
                rotateWithRightChild( t );
            else
                //doubleWithRightChild( t );
                fastDoubleWithRightChild( t );
                
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }
    
    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    AvlNode * findMin( AvlNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    AvlNode * findMax( AvlNode *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the tree.
     */
    bool contains( const Comparable & x, AvlNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
/****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, AvlNode *t ) const
    {
        while( t != nullptr )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
*****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( AvlNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to 8
     a subtree rooted at t in sorted order.
     */
    void printTree( AvlNode *t ) const
    {
        if( t != nullptr )
        {
            printTree( t->left );
            std::cout << t->element << std::endl;
            printTree( t->right );
        }
    }

    /**
     * Internal method to clone subtree.
     */
    AvlNode * clone( AvlNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new AvlNode{ t->element, clone( t->left ), clone( t->right ), t->height };
    }
        // Avl manipulations
    /**
     * Return the height of node t or -1 if nullptr.
     */
    int height( AvlNode *t ) const
    {
        return t == nullptr ? -1 : t->height;
    }

    int max( int lhs, int rhs ) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    /**
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild( AvlNode * & k2 )
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
    }
   //This function does what the other function did without the need of recursion
    void fastDoubleWithRightChild(AvlNode * & k2)
       {
           AvlNode *k1 = k2->right;
           AvlNode *k3 = k1->left;
           k1->left = k3->right;
           k3->right=k1;
           k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
           k3->height = max( height( k3->right ), k1->height ) + 1;
           k1=k3;
           AvlNode *k4 = k2->right;
           k2->right=k4->left;
           k4->left =k2;
           k2 = k4;
            k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
            k4->height = max( height( k4->left ), k2->height ) + 1;
       }
    //This function does what the other function did without the need of recursion
    void fastDoubleWithLeftChild(AvlNode * & k2)
       {
           AvlNode *k1 = k2->left;
           AvlNode *k3 = k1->right;
           k1->right = k3->left;
           k3->left=k1;
           k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
           k3->height = max( height( k3->right ), k1->height ) + 1;
           k1=k3;
           AvlNode *k4 = k2->left;
           k2->left=k4->right;
           k4->right =k2;
           k2 = k4;
            k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
            k4->height = max( height( k4->left ), k2->height ) + 1;
           
       }

    /**
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     */
    void rotateWithRightChild( AvlNode * & k1 )
    {
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2->height = max( height( k2->right ), k1->height ) + 1;
        k1 = k2;
    }
   
  
};

#endif
