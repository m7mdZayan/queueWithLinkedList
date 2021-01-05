#include <iostream>

using namespace std;

struct Student{
    int id;
    string name;
};

struct Node{
    Student s;
    Node* next;
};

class Queue{
    Node* qfront;
    Node* rear;

public:
    Queue(){
         qfront = rear = NULL;
    }

    int isEmpty(){
        return ( qfront == NULL );
    }

    void enqueue( Student s ){
        Node* temp = new Node();
        temp->s=s;
        if ( isEmpty() ){ // Queue is empty
            qfront = rear = temp;
            return;
        }
        else{                  // Queue has data
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue(Student& z){
        if ( isEmpty() ){
            cout<< "sorry the queue is empty" << endl;
            return;
        }
        Node* temp = new Node();
        temp = qfront;
        z.id = temp->s.id;
        z.name = temp->s.name;
        qfront = temp->next;

        if ( qfront == NULL ){
            rear = NULL;
        }
        delete temp;
    }

    void display(){

        if ( isEmpty() ){
            cout << "sorry the Queue is empty" << endl;
            return;
        }

        Node* temp = new Node();
        temp = qfront;
        while( temp != NULL ){
            cout << temp->s.id << "-> " << temp->s.name << endl;
            temp = temp->next;
        }
    }

    Queue( Queue& q ){
        rear = NULL;
        qfront = NULL;
        Node* temp = new Node();
        temp = q.qfront;
        while( temp != NULL ){
            enqueue(temp->s);
            temp=temp->next;
        }
    }

    ~Queue(){
        delete qfront;
        delete rear;
        cout << "object destructed" << endl;
    }
};


int main()
{
    Queue myQueue;
    cout << myQueue.isEmpty() << endl;
     Student s1,s2,s3,z;
    s1.name = "Mohamed";
    s1.id = 1;
    s2.name = "Mahmoud";
    s2.id = 2;
    s3.name = "ALi";
    s3.id = 3;
    myQueue.enqueue(s1);
    myQueue.enqueue(s2);
    myQueue.enqueue(s3);
    myQueue.display();
    myQueue.dequeue(z);
    cout << "student " << z.name << " with id " << z.id << " was dequeued out of Queue." << endl;


    Queue q1(myQueue); // Testing copy constructor
    cout << "object q1 " <<endl;
    q1.display();

    return 0;
}
