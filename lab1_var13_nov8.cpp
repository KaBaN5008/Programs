
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <memory>

using namespace std;

template<typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        unique_ptr<Node> left;
        unique_ptr<Node> right;
        
        explicit Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };
    
    unique_ptr<Node> root;
    
    unique_ptr<Node> insert(unique_ptr<Node> node, const T& value) {
        if (node == nullptr) {
            return make_unique<Node>(value);
        }
        
        if (value < node->data) {
            node->left = insert(move(node->left), value);
        } else if (value > node->data) {
            node->right = insert(move(node->right), value);
        }
        
        return node;
    }
    
    Node* findMin(Node* node) const {
        auto* current = node;
        while (current->left != nullptr) {
            current = current->left.get();
        }
        return current;
    }
    
    unique_ptr<Node> remove(unique_ptr<Node> node, const T& value) {
        if (node == nullptr) return nullptr;
        
        if (value < node->data) {
            node->left = remove(move(node->left), value);
        } else if (value > node->data) {
            node->right = remove(move(node->right), value);
        } else {
            if (node->left == nullptr) {
                return move(node->right);
            } else if (node->right == nullptr) {
                return move(node->left);
            }
            
            auto* temp = findMin(node->right.get());
            node->data = temp->data;
            node->right = remove(move(node->right), temp->data);
        }
        
        return node;
    }
    
    bool contains(const Node* node, const T& value) const {
        if (node == nullptr) return false;
        
        if (value == node->data) return true;
        else if (value < node->data) return contains(node->left.get(), value);
        else return contains(node->right.get(), value);
    }
    
    string inOrderToString(const Node* node) const {
        if (node == nullptr) return "";
        
        ostringstream oss;
        const auto left = inOrderToString(node->left.get());
        const auto right = inOrderToString(node->right.get());
        
        if (!left.empty()) oss << left << ", ";
        oss << node->data;
        if (!right.empty()) oss << ", " << right;
        
        return oss.str();
    }
    
    void inOrderPrint(const Node* node, ostream& os) const {
        if (node != nullptr) {
            inOrderPrint(node->left.get(), os);
            os << node->data << " ";
            inOrderPrint(node->right.get(), os);
        }
    }
    
    unique_ptr<Node> copyTree(const Node* otherNode) const {
        if (otherNode == nullptr) return nullptr;
        
        auto newNode = make_unique<Node>(otherNode->data);
        newNode->left = copyTree(otherNode->left.get());
        newNode->right = copyTree(otherNode->right.get());
        return newNode;
    }

public:
    BinaryTree() = default;
    
    BinaryTree(const BinaryTree& other) {
        root = copyTree(other.root.get());
    }
    
    BinaryTree& operator=(const BinaryTree& other) {
        if (this != &other) {
            root = copyTree(other.root.get());
        }
        return *this;
    }
    
    BinaryTree(BinaryTree&& other) noexcept = default;
    BinaryTree& operator=(BinaryTree&& other) noexcept = default;
    
    ~BinaryTree() = default;
    
    void insert(const T& value) {
        root = insert(move(root), value);
    }
    
    void remove(const T& value) {
        root = remove(move(root), value);
    }
    
    bool contains(const T& value) const {
        return contains(root.get(), value);
    }
    
    void clear() {
        root.reset();
    }
    
    string toString() const {
        if (root == nullptr) return "BinaryTree: []";
        
        ostringstream oss;
        oss << "BinaryTree: [" << inOrderToString(root.get()) << "]";
        return oss.str();
    }
void print(ostream& os) const {
        os << "BinaryTree: [";
        inOrderPrint(root.get(), os);
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
        queue<const Node*> q;
        q.push(root.get());
        
        while (!q.empty()) {
            const auto* current = q.front();
            q.pop();
            count++;
            
            if (current->left != nullptr) q.push(current->left.get());
            if (current->right != nullptr) q.push(current->right.get());
        }
        
        return count;
    }
    
    using value_type = T;
    using reference = const T&;
    
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
    cout << "Размер: " << tree.size() << endl;
    cout << "Содержит 4: " << (tree.contains(4) ? "да" : "нет") << endl;
    cout << "Содержит 10: " << (tree.contains(10) ? "да" : "нет") << endl;
    
    tree.remove(3);
    cout << "После удаления 3: " << tree << endl;
    
    istringstream input("15 12 18 10 13");
    BinaryTree<int> tree2;
    input >> tree2;
    cout << "Дерево из ввода: " << tree2 << endl;
    
    const auto tree3 = tree2;
    cout << "Скопированное дерево: " << tree3 << endl;
    
    decltype(tree)::value_type searchValue = 12;
    cout << "Поиск " << searchValue << ": " 
         << (tree3.contains(searchValue) ? "найдено" : "не найдено") << endl;
    
    const auto treeSize = tree.size();
    cout << "Тип размера дерева: " << typeid(treeSize).name() << endl;
    
    return 0;
}
