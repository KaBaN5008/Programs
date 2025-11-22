#include <iostream>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

template<typename T>
class PriorityQueue {
private:
    struct Node {
        int priority;
        T value;
    };
    
    Node* data = nullptr;
    size_t capacity = 0;
    size_t count = 0;
    
    void resize() {
        const auto newCapacity = (capacity == 0) ? 1 : capacity * 2;
        auto* newData = new Node[newCapacity];
        for (size_t i = 0; i < count; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    
    void sortDown() {
        for (size_t i = 0; i < count; ++i) {
            for (size_t j = i + 1; j < count; ++j) {
                if (data[i].priority < data[j].priority) {
                    auto temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }

public:
    PriorityQueue() = default;
    
    explicit PriorityQueue(const initializer_list<pair<int, T>>& init) : data(nullptr), capacity(0), count(0) {
        for (const auto& p : init) {
            enqueue(p.first, p.second);
        }
    }
    
    ~PriorityQueue() {
        delete[] data;
    }
    
    PriorityQueue(const PriorityQueue&) = delete;
    PriorityQueue& operator=(const PriorityQueue&) = delete;
    
    void enqueue(const int priority, const T& value) {
        if (count == capacity) {
            resize();
        }
        data[count].priority = priority;
        data[count].value = value;
        ++count;
        sortDown();
    }
    
    bool dequeue(T& outValue) {
        if (count == 0) return false;
        outValue = data[0].value;
        --count;
        if (count > 0) {
            data[0] = data[count];
            sortDown();
        }
        return true;
    }
    
    T dequeue() {
        if (count == 0) throw out_of_range("PriorityQueue is empty");
        auto value = data[0].value;
        --count;
        if (count > 0) {
            data[0] = data[count];
            sortDown();
        }
        return value;
    }
    
    void clear() {
        count = 0;
    }
    
    string toString() const {
        if (count == 0) return "PriorityQueue: []";
        ostringstream oss;
        oss << "PriorityQueue: [";
        for (size_t i = 0; i < count; ++i) {
            oss << "(" << data[i].priority << ": " << data[i].value << ")";
            if (i < count - 1) oss << ", ";
        }
        oss << "]";
        return oss.str();
    }
    
    void print(ostream& os) const {
        os << toString();
    }
    
    friend ostream& operator<<(ostream& os, const PriorityQueue& pq) {
        pq.print(os);
        return os;
    }
    
    void read(istream& is) {
        clear();
        int priority;
        T value;
        while (is >> priority >> value) {
            enqueue(priority, value);
        }
        is.clear();
    }
    
    bool empty() const { return count == 0; }
    size_t size() const { return count; }
    
    const T& top() const {
        if (count == 0) throw out_of_range("PriorityQueue is empty");
        return data[0].value;
    }
    
    int topPriority() const {
        if (count == 0) throw out_of_range("PriorityQueue is empty");
        return data[0].priority;
    }
};

int main() {
    PriorityQueue<string> pq;
    pq.enqueue(3, "Low");
    pq.enqueue(1, "Critical");
    pq.enqueue(2, "Normal");
    
    const auto queueStr = pq.toString();
    cout << "Queue as string: " << queueStr << endl;
    
    cout << "Size: " << pq.size() << endl;
    cout << "Is empty: " << boolalpha << pq.empty() << endl;
    
    const auto testQueue = pq;
    cout << "Copied queue: " << testQueue << endl;

    string task;
    while (pq.dequeue(task)) {
        const auto message = "Do: " + task;
cout << message << endl;
    }

    istringstream input("10 A 5 B 15 C");
    PriorityQueue<string> pq2;
    pq2.read(input);
    
    decltype(pq2)::value_type firstTask = pq2.dequeue();
    cout << "First task: " << firstTask << endl;
    
    cout << "Remaining queue: " << pq2 << endl;

    return 0;
}
