/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* find_NextRight(Node* p){
        Node* temp=p->next;
        while(temp!=NULL){
            if(temp->left)
                return temp->left;
            else if(temp->right)
                return temp->right;
            else temp=temp->next;
        }
        return NULL;
    }
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;

        root->next=NULL;
        Node* p = root;
        while(p){
                Node* q=p;
                while(q){
                    if(q->left){
                        if(q->right)
                            q->left->next=q->right;   
                        else
                            q->left->next=find_NextRight(q);
                    }
                    if(q->right)
                        q->right->next=find_NextRight(q);
                    q = q->next;
                }//END of INNER WHILE LOOP
                if(p->left)
                    p=p->left;
                else if (p->right)
                    p=p->right;
                else p=find_NextRight(p);
        }//END OF OUTER WHILE LOOP

        return root;
        }//END OF FUNCTION DEFINITION
    
};