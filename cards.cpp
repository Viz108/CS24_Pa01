#include <iostream>
#include "cards.h"

using namespace std;




// intbst.cpp
// Implements class IntBST
// Vishal Seenivasan


// constructor sets up empty tree
IntBST::IntBST() 
{ 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {

    if(n == nullptr)
    {
        return;
    }
    else
    {
        clear(n -> left);
        clear(n -> right);
        delete n;
        return;
    }

}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {

    if(n == nullptr) //empty list
    {
        root = new Node(value);
        return true;
    }

    if(n -> info == value)
    {
        return false;
    }
    else if(value < n -> info)
    {
        if(n -> left == nullptr)
        {
            n -> left = new Node(value);
            n -> left -> parent = n; 
            return true;
        }
        else
        {
            return insert(value, n -> left);
        }
    }
    else if(value > n -> info)
    {
        if(n -> right == nullptr)
        {
            n -> right = new Node(value);
            n -> right -> parent = n; 
            return true;
        }
        else
        {
            return insert(value, n -> right);
        }
    }

    return false; 
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    
    printPreOrder(root);

}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    
    if(n == nullptr)
    {
        return;
    }
    else
    {
        cout << n -> info << " ";
        printPreOrder(n -> left);
        printPreOrder(n -> right);
    }

}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if(n == nullptr)
    {
        return;
    }
    else
    {
        printInOrder(n -> left);
        cout << n -> info << " ";
        printInOrder(n -> right);
    }
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if(n == nullptr)
    {
        return;
    }
    else
    {
        printPostOrder(n -> left);
        printPostOrder(n -> right);
        cout << n -> info << " ";
    }
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if(n == nullptr)
    {
        return 0;
    }
    else
    {
        int leftSum = sum(n -> left);
        int rightSum = sum(n -> right);
        return n -> info + leftSum + rightSum;
    }
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if(n == nullptr)
    {
        return 0;
    }
    else
    {
        int leftCount = count(n -> left);
        int rightCount = count(n -> right);
        return 1 + leftCount + rightCount;
    }
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    
    if(n == nullptr)
    {
        return nullptr;
    }
    else if(value == n -> info)
    {
        return n;
    }
    else if(value < n -> info)
    {
        return getNodeFor(value, n -> left);
    }
    else if(value > n -> info)
    {
        return getNodeFor(value, n -> right);
    }
    return nullptr; 
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if(getNodeFor(value, root) != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    
    if(!contains(value)) //Check special case - value not in tree
    {
        return nullptr; 
    }

    if(root -> info == value) //Check special case - root is value node
    {
        if(root -> left == nullptr)
        {
            return nullptr;
        }
        Node* currNode = root -> left; 
        while(currNode -> right != nullptr)
        {
            currNode = currNode -> right; 
        }
        return currNode;
    }

    if(getNodeFor(value, root) -> left != nullptr) //Check special case - has a left child
    {
        Node* currNode = getNodeFor(value, root) -> left;
        while(currNode -> right != nullptr)
        {
            currNode = currNode -> right;
        }
        return currNode;
    }

    if(root -> info > value) //Value node is less than starting point
    {
        Node* currNode = root;
        while(currNode -> info > value) //Go to value node's highest ancestor
        {
            currNode = currNode -> left;
        }

        if(currNode -> info == value) //If the ancestor is the value node itself, just return it's left child
        {
            return currNode -> left;
        }
        Node* currReturnNode = currNode;
        while(currNode -> info != value) //Find the last node that has the value node in its right branch
        {
            if(currNode -> info < value)
            {
                currReturnNode = currNode; 
                currNode = currNode -> right;
            }
            else if(currNode -> info > value)
            {
                currNode = currNode -> left; 
            }
        }
        return currReturnNode; 
    }
    else if(root -> info < value) //Value node is greater than starting point
    {
        Node* prevNode = root;
        Node* currNode = root -> right;
        while(currNode -> info < value)//Go to value node's highest ancestor
        {
            prevNode = currNode; 
            currNode = currNode -> right;
        }

        if((currNode -> info) == value) //If the ancestor is the value node itself, just return it's parent
        {
            if(currNode -> left != nullptr)
            {
                return currNode -> left;
            }
            else
            {
                return prevNode;
            }
        }

        Node* currReturnNode = prevNode;
        while(currNode -> info != value) //Find the last node that has the value node in its right branch
        {
            if(currNode -> info < value)
            {
                currReturnNode = currNode; 
                currNode = currNode -> right;
            }
            else if(currNode -> info > value)
            {
                currNode = currNode -> left; 
            }
        }
        return currReturnNode; 
    }
    return nullptr; 
}
    

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* returnNode = getPredecessorNode(value);

    if(returnNode != nullptr)
    {
        return returnNode -> info;
    }
    else
    {
        return 0;
    }
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
     if(!contains(value)) //Check special case - value not in tree
    {
        return nullptr; 
    }

    if(root -> info == value) //Check special case - root is value node
    {
        if(root -> right == nullptr)
        {
            return nullptr; 
        }
        Node* currNode = root -> right; 
        while(currNode -> left != nullptr)
        {
            currNode = currNode -> left; 
        }
        return currNode; 
    }

    if(getNodeFor(value, root) -> right != nullptr) //Check special case - has a right child
    {
        Node* currNode = getNodeFor(value, root) -> right;
        while(currNode -> left != nullptr)
        {
            currNode = currNode -> left;
        }
        return currNode;
    }

    if(root -> info < value) //Value node is greater than starting point
    {
        Node* currNode = root;
        while(currNode -> info < value) //Go to value node's highest ancestor
        {
            currNode = currNode -> right;
        }

        if(currNode -> info == value) //If the ancestor is the value node itself, just return it's left child
        {
            return currNode -> right;
        }
        Node* currReturnNode = currNode;
        while(currNode -> info != value) //Find the last node that has the value node in its right branch
        {
            if(currNode -> info > value)
            {
                currReturnNode = currNode; 
                currNode = currNode -> left;
            }
            else if(currNode -> info < value)
            {
                currNode = currNode -> right; 
            }
        }
        return currReturnNode; 
    }
    else if(root -> info > value) //Value node is greater than starting point
    {
        Node* prevNode = root;
        Node* currNode = root -> left;
        while(currNode -> info > value)//Go to value node's highest ancestor
        {
            prevNode = currNode; 
            currNode = currNode -> left;
        }

        if((currNode -> info) == value) //If the ancestor is the value node itself, just return it's parent
        {
            if(currNode -> right != nullptr)
            {
                return currNode -> right;
            }
            else
            {
                return prevNode;
            }
        }

        Node* currReturnNode = prevNode;
        while(currNode -> info != value) //Find the last node that has the value node in its left branch
        {
            if(currNode -> info > value)
            {
                currReturnNode = currNode; 
                currNode = currNode -> left;
            }
            else if(currNode -> info < value)
            {
                currNode = currNode -> right; 
            }
        }
        return currReturnNode; 
    }
    return nullptr;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* returnNode = getSuccessorNode(value);

    if(returnNode != nullptr)
    {
        return returnNode -> info;
    }
    else
    {
        return 0;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    if(!contains(value))
    {
        return false; 
    }

    Node* nodeToRemove = getNodeFor(value, root);
    //Node* parent = root;

    Node* currNode = root; 
    bool leftOrRight = true; //True for left, false for right
    while(currNode -> info != value)
        {
            //parent = currNode;
            if(value < currNode -> info)
            {
                currNode = currNode -> left; 
                leftOrRight = true;
            }
            else if(value > currNode -> info)
            {
                currNode = currNode -> right; 
                leftOrRight = false; 
            }
        }
    
    

    if(nodeToRemove -> left == nullptr && nodeToRemove -> right == nullptr) //Leaf Node
    {
        if(nodeToRemove == root)
        {
            root = nullptr; 
            delete nodeToRemove;
            return true; 
        }
        

       if(leftOrRight) //nodeToRemove on the Left
        {
            nodeToRemove -> parent -> left = nullptr; 
        }   
        else //nodeToRemove on the Right
        {
            nodeToRemove -> parent -> right = nullptr; 
        } 
        delete nodeToRemove;
        return true;
    }
    else if(nodeToRemove -> left != nullptr && nodeToRemove -> right == nullptr) //Only Left Child
    {
        if(nodeToRemove == root)
        {
            root = nodeToRemove -> left; 
            root -> parent = nullptr; 
            delete nodeToRemove;
            return true; 
        }
        if(leftOrRight) //nodeToRemove on the Left
        {
            nodeToRemove -> left -> parent = nodeToRemove -> parent;
            nodeToRemove -> parent -> left = nodeToRemove -> left;
        }   
        else //nodeToRemove on the Right
        {
            nodeToRemove -> left -> parent = nodeToRemove -> parent;
            nodeToRemove -> parent -> right = nodeToRemove -> left; 
        } 
        delete nodeToRemove; 
        return true; 
    }
    else if(nodeToRemove -> left == nullptr && nodeToRemove -> right != nullptr) //Only Right Child
    {
        if(nodeToRemove == root)
        {
            root = nodeToRemove -> right; 
            root -> parent = nullptr; 
            delete nodeToRemove;
            return true; 
        }
        if(leftOrRight) //nodeToRemove on the Left
        {
            nodeToRemove -> right -> parent = nodeToRemove -> parent; 
            nodeToRemove -> parent -> left = nodeToRemove -> right;
        }   
        else //nodeToRemove on the Right
        {
            nodeToRemove -> right -> parent = nodeToRemove -> parent; 
            nodeToRemove -> parent -> right = nodeToRemove -> right; 
        } 
        delete nodeToRemove; 
        return true; 
    }
    else if(nodeToRemove -> left != nullptr && nodeToRemove -> right != nullptr)
    {
        // Node* rightMostNodeonLeft = nodeToRemove -> left;
        // while(rightMostNodeonLeft -> right != nullptr)
        // {
        //     rightMostNodeonLeft = rightMostNodeonLeft -> right; 
        // }

        // rightMostNodeonLeft -> right = nodeToRemove -> right; 

        // if(nodeToRemove == root)
        // {
        //     root = nodeToRemove -> left;
        // }
        // else if(leftOrRight)
        // {
        //     parent -> left = nodeToRemove -> left; 
        // }
        // else
        // {
        //     parent -> right = nodeToRemove -> left; 
        // }
        // delete nodeToRemove; 
        // return true;        
        Node* successor = getSuccessorNode(value); 
        int newValue = successor -> info; 
        remove(successor -> info);
        nodeToRemove -> info = newValue; 
        return true; 
    }


   return false; 
}


//cards.cpp
//Authors: Your name and your partner's name
//Implementation of the classes defined in cards.h



cards :: cards()
{

}

void cards :: addCard(int cardValue)
{
    list.insert(cardValue);
}

void cards :: printCards()
{
    // list.printInOrder();
    // cout << endl; 
    int currCard = getFirstCard();

    while(currCard != 0)
    {
        if(currCard >= 1 && currCard <= 13) //club
        {
          cout << "c ";
          if(currCard == 11) //jack
          {
            cout << "j" << endl;
          }
          else if(currCard == 12) //queen
          {
            cout << "q" << endl;
          }
          else if(currCard == 13) //king
          {
            cout << "k" << endl;
          }
          else if(currCard == 1) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << currCard - 0 << endl; 
          }
        }
        else if(currCard >= 14 && currCard <= 26) //diamond
        {
          cout << "d ";
          if(currCard == 11 + 13) //jack
          {
            cout << "j" << endl;
          }
          else if(currCard == 12 + 13) //queen
          {
            cout << "q" << endl;
          }
          else if(currCard == 13 + 13) //king
          {
            cout << "k" << endl;
          }
          else if(currCard == 1 + 13) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << currCard - 13 << endl; 
          }
        }
        else if(currCard >= 27 && currCard <= 39) //spade
        {
          cout << "s ";
          if(currCard == 11 + 26) //jack
          {
            cout << "j" << endl;
          }
          else if(currCard == 12 + 26) //queen
          {
            cout << "q" << endl;
          }
          else if(currCard == 13 + 26) //king
          {
            cout << "k" << endl;
          }
          else if(currCard == 1 + 26) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << currCard - 26 << endl; 
          }
        }
        else if(currCard >= 40 && currCard <= 52) //heart
        {
          cout << "h ";
          if(currCard == 11 + 39) //jack
          {
            cout << "j" << endl;
          }
          else if(currCard == 12 + 39) //queen
          {
            cout << "q" << endl;
          }
          else if(currCard == 13 + 39) //king
          {
            cout << "k" << endl;
          }
          else if(currCard == 1 + 39) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << currCard - 39 << endl; 
          }
        }

        currCard = getNextCard(currCard);
    }
}

int cards :: getFirstCard()
{
    for(int i = 0; i <= 52; i++)
    {
        if(list.contains(i))
        {
            return i; 
        }
    }
    return 0;
}

int cards :: getLastCard()
{
    for(int i = 52; i >= 0; i--)
    {
        if(list.contains(i))
        {
            return i;
        }
    }
    return 0;
}

int cards :: getNextCard(int cardValue)
{
    return list.getSuccessor(cardValue);
}

int cards :: getPreviousCard(int cardValue)
{
    return list.getPredecessor(cardValue);
}

bool cards :: containsCard(int cardValue)
{
    return list.contains(cardValue);
}

bool cards :: removeCard(int cardValue)
{
    return list.remove(cardValue);
}



