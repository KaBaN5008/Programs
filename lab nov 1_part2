#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

template<typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    
    Node* insert(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }
        
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        
        return node;
    }
    
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    Node* remove(Node* node, const T& value) {
        if (node == nullptr) return nullptr;
        
        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        
        return node;
    }
    
    bool contains(Node* node, const T& value) const {
        if (node == nullptr) return false;
        
        if (value == node->data) return true;
        else if (value < node->data) return contains(node->left, value);
        else return contains(node->right, value);
    }
    
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
    
    string inOrderToString(Node* node) const {
        if (node == nullptr) return "";
        
        ostringstream oss;
        string left = inOrderToString(node->left);
        string right = inOrderToString(node->right);
        
        if (!left.empty()) oss << left << ", ";
        oss << node->data;
        if (!right.empty()) oss << ", " << right;
        
        return oss.str();
    }
    
    void inOrderPrint(Node* node, ostream& os) const {
        if (node != nullptr) {
            inOrderPrint(node->left, os);
            os << node->data << " ";
            inOrderPrint(node->right, os);
        }
    }
    
    Node* copyTree(Node* otherNode) {
        if (otherNode == nullptr) return nullptr;
        
        Node* newNode = new Node(otherNode->data);
        newNode->left = copyTree(otherNode->left);
        newNode->right = copyTree(otherNode->right);
        return newNode;
    }

public:
    BinaryTree() : root(nullptr) {}
    
    BinaryTree(const BinaryTree& other) : root(nullptr) {
        root = copyTree(other.root);
    }
    
    BinaryTree& operator=(const BinaryTree& other) {
        if (this != &other) {
            clear();
            root = copyTree(other.root);
        }
        return *this;
    }
    
    ~BinaryTree() {
        clear();
    }
    
    void insert(const T& value) {
        root = insert(root, value);
    }
    
    void remove(const T& value) {
        root = remove(root, value);
    }
    
    bool contains(const T& value) const {
        return contains(root, value);
    }
    
    void clear() {
        clear(root);
        root = nullptr;
    }
    
    string toString() const {
        if (root == nullptr) return "BinaryTree: []";
        
        ostringstream oss;
        oss << "BinaryTree: [" << inOrderToString(root) << "]";
        return oss.str();
    }
    
    void print(ostream& os) const {
        os << "BinaryTree: [";
        inOrderPrint(root, os);
        os << "]";
}
    
    void read(istream& is) {
        clear();
        T value;
        while (is >> value) {
            insert(value);
        }
        is.clear();
    }
    
    bool empty() const {
        return root == nullptr;
    }
    
    size_t size() const {
        if (root == nullptr) return 0;
        
        size_t count = 0;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            count++;
            
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
        
        return count;
    }
    
    friend ostream& operator<<(ostream& os, const BinaryTree& tree) {
        tree.print(os);
        return os;
    }
    
    friend istream& operator>>(istream& is, BinaryTree& tree) {
        tree.read(is);
        return is;
    }
};

int main() {
    BinaryTree<int> tree;
    
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    
    cout << tree << endl;
    cout << "Size: " << tree.size() << endl;
    cout << "Contains 4: " << (tree.contains(4) ? "true" : "false") << endl;
    cout << "Contains 10: " << (tree.contains(10) ? "true" : "false") << endl;
    
    tree.remove(3);
    cout << "After removing 3: " << tree << endl;
    
    istringstream input("15 12 18 10 13");
    BinaryTree<int> tree2;
    tree2.read(input);
    cout << "Tree from input: " << tree2 << endl;
    
    return 0;
}
