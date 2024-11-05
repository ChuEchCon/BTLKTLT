#include <iostream>

using namespace std;
class LinkedList {
public:
    struct Node {
        int data;
        Node* next;
    };
typedef struct Node* node;
    Node* head;

    LinkedList() {
        head = nullptr;
    }
    // Nhap so va chuyen thanh chuoi
    void input(string s) {
        for (int i = s.length() - 1; i >= 0; --i) {
            node newNode = new Node;
            newNode->data = s[i] - '0';
            newNode->next = head;
            head = newNode;
        }
    }

    // In so
    void print() {
        node temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next;
        }
    }

    // Tong hai so
    LinkedList add(LinkedList so2) {
        LinkedList result;
        node p1 = head;
        node p2 = so2.head;
        int carry = 0;

        while (p1 != nullptr || p2 != nullptr || carry != 0) {
            int sum = carry;
            if (p1 != nullptr) {
                sum += p1->data;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                sum += p2->data;
                p2 = p2->next;
            }
            node newNode = new Node;
            newNode->data = sum % 10;
            newNode->next = result.head;
            result.head = newNode;
            carry = sum / 10; // Lay phan du
        }

        return result;
    }

    // So sanh
    int compare(LinkedList other) {
        node p1 = head;
        node p2 = other.head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->data > p2->data) {
                return 1; // Số hiện tại lớn hơn
            } else if (p1->data < p2->data) {
                return -1; // Số hiện tại nhỏ hơn
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1 != nullptr) {
            return 1; // Số hiện tại lớn hơn
        } else if (p2 != nullptr) {
            return -1; // Số hiện tại nhỏ hơn
        } else {
            return 0; // Hai số bằng nhau
        }
    }
};
int main() {
    int T;
    cin >> T;

    while (T--) {
        string num1Str, num2Str, op;
        cin >> num1Str >> op >> num2Str;

        LinkedList num1, num2;
        num1.input(num1Str);
        num2.input(num2Str);

        if (op == "+") {
            LinkedList result = num1.add(num2);
            result.print();
            cout << "\n";
        } else if (op == "=") {
            if (num1.compare(num2) == 0) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else if (op == ">") {
            if (num1.compare(num2) > 0) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else if (op == "<") {
            if (num1.compare(num2) < 0) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}
