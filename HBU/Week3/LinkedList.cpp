#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

//初始化链表
Node* InitList(){
    Node* H = new Node;
    H->next = NULL;
    int x;
    cout << "Enter values to add to the list (enter -1 to end): " << endl;
    cin >> x;
    while (x != -1){
        Node *nodeBlock = new Node;
        nodeBlock->data = x;
        nodeBlock->next = H->next;
        H->next = nodeBlock;
        cin >> x;
    }
    cout << "The LinkedList has been initialized!" << endl;
    return H;
}

//按序号查找
Node* getByIndex(Node* H , int aim_index){
    //直接跳过头结点，获取存储区域
    Node* currentNode = H->next;
    int current_index=1;
    while (currentNode!= NULL && current_index < aim_index){
        currentNode=currentNode->next;
        current_index++;
    }
    return (current_index == aim_index) ? currentNode : NULL;
}

//按照值查找
Node* getByData(Node* H ,int aim_data){
    Node* currentNode = H->next;
    while (currentNode != NULL && currentNode->data != aim_data){
        currentNode = currentNode->next;
    }
    if (currentNode == NULL){
        cout << "Wrong data" << endl;
        return NULL;
    } 
    return currentNode;
}

//插入链表
void InsertList(Node* H,int x,int aim_index){
    if (aim_index < 1){
        cout << "Index value must be greater than 1" << endl;
        return;
    }
    //初始化插入节点块
    Node* aimNode = new Node;
    aimNode->data = x;
    
    //处理插在第一位的特殊情况
    if (aim_index == 1){
        aimNode->next = H->next;
        H->next = aimNode;
        return;
    }

    Node* preNode = getByIndex(H,aim_index-1);
    if (preNode == NULL){
        cout << "Wrong index: " << aim_index << endl;
        delete aimNode;
        return; 
    }
    aimNode->next = preNode->next;
    preNode->next = aimNode;
    cout << "Successfully" << endl;
}
    
//按索引删除
void deleteByIndex(Node* H ,int aim_index){
    if (aim_index < 1){
        cout << "Index value must be greater than 1" << endl;
        return;
    }
    
    Node* aimNode = getByIndex(H,aim_index);
    if (aimNode == NULL){
        cout << "Wrong index: " << aim_index << endl;
        return; 
    }

    if (aim_index == 1){
        H->next = aimNode->next;
        delete aimNode;
        return;
    }

    Node* preNode = getByIndex(H,aim_index-1);
    preNode->next = aimNode->next;
    delete aimNode;
}

//按值删除（追踪指针）
void deleteByData(Node* H,int aim_data){
    Node* prev,*cur;
    prev = NULL;
    cur = H->next;
    while (cur != NULL && cur->data != aim_data){
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL){
        cout << "Wrong data" << endl;
        return;
    }
    else if (prev == NULL){
        H->next = cur->next;
        delete cur;
    }
    else{
        prev->next = cur->next;
        delete cur;
    }
}

//打印链表
void printList(Node* H){
    Node* currentNode = H->next;
    if (currentNode == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    cout << "List contents:" << endl;
    while (currentNode != NULL){
        cout << currentNode->data ;
        currentNode = currentNode->next;
        if (currentNode != NULL){
            cout << "->";
        }
    }
    cout << endl;
}

int main() {
    Node* H = InitList(); // 初始化链表
    int choice, value, index;

    while (true) {
        cout << "\n--- Linked List Operations ---" << endl;
        cout << "1. Print the list" << endl;
        cout << "2. Insert a node" << endl;
        cout << "3. Delete a node by index" << endl;
        cout << "4. Delete a node by value" << endl;
        cout << "5. Find a node by index" << endl;
        cout << "6. Find a node by value" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printList(H);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter index to insert at: ";
                cin >> index;
                InsertList(H, value, index);
                printList(H);
                break;
            case 3:
                cout << "Enter index to delete: ";
                cin >> index;
                deleteByIndex(H, index);
                printList(H);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteByData(H, value);
                printList(H);
                break;
            case 5: {
                cout << "Enter index to find: ";
                cin >> index;
                Node* foundIndexNode = getByIndex(H, index);
                if (foundIndexNode != NULL) {
                    cout << "Value at index " << index << ": " << foundIndexNode->data << endl;
                } else {
                    cout << "No node found at index " << index << "." << endl;
                }
                break;
            }
            case 6: {
                cout << "Enter value to find: ";
                cin >> value;
                Node* foundValueNode = getByData(H, value);
                if (foundValueNode != NULL) {
                    cout << "Node found with value: " << foundValueNode->data << endl;
                } else {
                    cout << "No node found with value " << value << "." << endl;
                }
                break;
            }
            case 7:
                cout << "Exiting the program." << endl;
                return 0; // 退出程序
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }

    //释放内存
    Node* currentNode = H;
    while(currentNode != NULL){
        Node* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    return 0;
}

