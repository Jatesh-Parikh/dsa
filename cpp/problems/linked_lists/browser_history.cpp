#include <string>

using namespace std;

class Node {
    public:
        string data;
        Node *next;
        Node *back;

        Node(const string& data): data(data), next(nullptr), back(nullptr) {}
};

class Browser {
    private:
        Node* current_page;

    public:
        Browser(const string& home_page) {
            current_page = new Node(home_page);
        }

        ~Browser() {
            while (current_page->back) {
                current_page = current_page->back;
            }

            while (current_page) {
                Node *temp = current_page;
                current_page = current_page->next;
                delete temp;
            }
        }

        void visit(const string& url) {
            // Delete forward history
            Node *temp = current_page->next;

            while (temp) {
                Node *next_node = temp->next;
                delete temp;
                temp = next_node;
            }

            current_page->next = nullptr;

            Node *new_node = new Node(url);
            current_page->next = new_node;
            new_node->back = current_page;
            current_page = new_node;
        }
        
        string forward(int steps) {
            while (steps > 0 && current_page->next) {
                current_page = current_page->next;
                steps--;        
            }

            return current_page->data;
        }
        
        string back(int steps) {
            while (steps > 0 && current_page->back) {
                current_page = current_page->back;
                steps--;
            }

            return current_page->data;
        }
};