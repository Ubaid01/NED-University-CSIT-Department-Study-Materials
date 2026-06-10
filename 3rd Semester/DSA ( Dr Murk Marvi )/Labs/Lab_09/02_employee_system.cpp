#include<iostream>
using namespace std ;

struct EmpRecords {
    int id ;
    string name ;
    string dept ;
    EmpRecords( int id = 0 , string name = "" , string dept = "" ) {
        this -> id = id ;
        this -> name = name ;
        this -> dept = dept ;
    }

    void display( ) {
        cout << "Record for ID = " << id << " :\n" 
        << "Name = " << name << "\tDepartment = " << dept << endl ;
    }
} ;

struct Node {
    EmpRecords record ;
    Node* left ;
    Node* right ;
    Node( EmpRecords rec ) : record( rec ) , left( nullptr ), right( nullptr ) {}
} ;

class BST {
    private:
        Node* root ;

        void deleteChild( Node* node ) {
            if( node ) {
                deleteChild( node -> left ) ;
                deleteChild( node -> right ) ;
                delete node ;
                node = nullptr ;
            }
        }

        Node* findSuccessor( Node* node ) {
            if( !node )
                return nullptr ;
            
            while( node -> left )
                node = node -> left ;
            return node ;
        }
    
        Node* insert_R( Node* node , int id , string name , string depart ) {
            if( !node )
                return new Node( EmpRecords( id, name, depart ) ) ;
            
            if( node -> record.id == id ) {
                cout << "Duplicates are not allowed as ID should be unique!\n" ;
                return node ;
            }
            else if( node -> record.id > id )
                node -> left = insert_R( node -> left , id , name , depart ) ;
            else
                node -> right = insert_R( node -> right , id , name , depart ) ;
            
            return node ;
        }

        Node* DeleteNode( Node* node , int id ) {
            if( !node )
                return nullptr ;
            
            if( node -> record.id > id ) 
                node -> left = DeleteNode( node -> left , id ) ;
            else if( node -> record.id < id )
                node -> right = DeleteNode( node -> right , id ) ;
            else {
                if( node -> left == nullptr || node -> right == nullptr ) {
                    Node* temp = ( node -> right ) ? node -> right : node -> left ;
                    delete node ;
                    return temp ;
                }
                else {
                    Node* temp = findSuccessor( node -> right ) ;
                    node -> record = temp -> record ;
                    node -> right = DeleteNode( node -> right , temp -> record.id ) ;
                }
            }

            return node ;
        }

        void inorder( Node* node ) {
            if( node ) {
                inorder( node -> left ) ;
                node -> record.display() ;
                inorder( node -> right ) ;
            }
        }

    public:
        BST() : root( nullptr ) {}
        void insert( int id , string name , string department ) {
            if( name.empty() || department.empty() ) {
                cout << "Invalid data: Name and department cannot be empty.\n";
                return;
            }
            root = insert_R( root , id , name , department ) ;
        }

        void deleteNode( int id ) {
            root = DeleteNode( root , id ) ;
        }

        void search( int id ) {
            if( !root ) {
                cout << "The tree is empty.\n";
                return;
            }

            Node* cur = root ;
            while( cur ) {
                if( cur -> record.id > id )
                    cur = cur -> left ;
                else if( cur -> record.id < id )
                    cur = cur -> right ;
                else {
                    cur -> record.display() ;
                    return ;
                }
            }
            cout << "Record for " << id << " not found. Try again!\n" ;
        }

        void inorderTraversal( ) {
            inorder( root ) ;
        }

        void findMin( ) {
            if( !root ) {
                cout << "The tree is empty.\n";
                return;
            }
            
            Node* cur = root ;
            while( cur -> left ) // As minimum will be the leftmost node of left-subtree.
                cur = cur -> left ;
            
            cout << "Min Record --> " ;
            cur -> record.display() ;
        }

        
        void findMax( ) {
            if( !root ) {
                cout << "The tree is empty.\n";
                return;
            }
            
            Node* cur = root ;
            while( cur -> right )
                cur = cur -> right ;
            
            cout << "Max Record --> " ;
            cur -> record.display() ;
        }

        ~BST( ) {   deleteChild( root ) ;   }
} ;

int main(){
    BST t ;
    t.insert( 25 , "Obaid" , "CSIT" ) ;
    t.insert( 49 , "Ahmed" , "CSIT" ) ;
    t.insert( 31 , "John" , "Electrical" ) ;
    t.insert( 17 , "Ali" , "CSIT" ) ;
    t.insert( 50, "Liam", "Mechanical");

    cout << "\nIn-Order Traversal of Tree in start:\n" ;
    t.inorderTraversal();
    cout << "\nSearch for Existing Records:\n" ;
    t.search(25); 
    t.search(49);
    t.search(100);

    cout << "\nFinding Minimum and Maximum Records:\n" ;
    t.findMin();
    t.findMax();

    cout << "\nDeleting Record with ID 25:\n" ;
    t.deleteNode(25); 

    cout << "\nIn-Order Traversal of Tree in end:\n" ;
    t.inorderTraversal();
    t.deleteNode(100);
    return 0;
}