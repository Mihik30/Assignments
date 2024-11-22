#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

class Convert {
    int choice, i, n, j, d, k;
    stack<char> arr;
    vector<char> sd;
    vector<int> ns;
    string s, b;
    int o1, o2, o_res;

public:
    void input() {
        cout << "Enter the expression: ";
        cin >> s;
        n = s.size();
    }

    void input_n() {
        cout << "Enter the expression in numerical (0 to 9): ";
        cin >> s;
        n = s.size();
    }

    int priority(char c) {
        if (c == '+' || c == '-') return 1;
        else if (c == '*' || c == '/') return 2;
        else if (c == '^') return 3;
        else return 0;
    }

    void clear_sd() {
        sd.clear();
    }

    void check(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            sd.push_back(ch);
        }
        else if (ch == '(') {
            arr.push(ch);
        }
        else if (ch == ')') {
            while (!arr.empty() && arr.top() != '(') {
                sd.push_back(arr.top());
                arr.pop();
            }
            if (!arr.empty()) arr.pop();
        }
        else {
            while (!arr.empty() && priority(arr.top()) >= priority(ch)) {
                sd.push_back(arr.top());
                arr.pop();
            }
            arr.push(ch);
        }
    }

    void post() {
        for (i = 0; i < n; i++) {
            check(s[i]);
        }
        while (!arr.empty()) {
            sd.push_back(arr.top());
            arr.pop();
        }
        display();
    }

    void check_p(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            sd.push_back(ch);
        }
        else if (ch == '(') {
            arr.push(ch);
        }
        else if (ch == ')') {
            while (!arr.empty() && arr.top() != '(') {
                sd.push_back(arr.top());
                arr.pop();
            }
            if (!arr.empty()) arr.pop();
        }
        else {
            while (!arr.empty() && priority(arr.top()) > priority(ch)) {
                sd.push_back(arr.top());
                arr.pop();
            }
            arr.push(ch);
        }
    }

    void pre() {
        b = s;
        j = 0;
        for (i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                b[j] = '(';
            }
            else if (s[i] == '(') {
                b[j] = ')';
            }
            else {
                b[j] = s[i];
            }
            j++;
        }
        cout << b << endl;

        for (i = 0; i < n; i++) {
            check_p(b[i]);
        }
        while (!arr.empty()) {
            sd.push_back(arr.top());
            arr.pop();
        }

        cout << "Prefix expression is: ";
        for (i = sd.size() - 1; i >= 0; i--) {
            cout << sd[i];
        }
        cout << endl;
    }

    void display() {
        cout << "Postfix expression is: ";
        for (i = 0; i < sd.size(); i++) {
            cout << sd[i];
        }
        cout << endl;
    }

    void check_n(char ch) {
        if (ch >= '0' && ch <= '9') {
            sd.push_back(ch);
        }
        else if (ch == '(') {
            arr.push(ch);
        }
        else if (ch == ')') {
            while (!arr.empty() && arr.top() != '(') {
                sd.push_back(arr.top());
                arr.pop();
            }
            if (!arr.empty()) arr.pop();
        }
        else {
            while (!arr.empty() && priority(arr.top()) >= priority(ch)) {
                sd.push_back(arr.top());
                arr.pop();
            }
            arr.push(ch);
        }
    }

    void pos_conv(char val) {
        if (val >= '0' && val <= '9') {
            d = val - '0';
            ns.push_back(d);
        }
        else {
            o1 = ns[ns.size() - 1];
            ns.pop_back();
            o2 = ns[ns.size() - 1];
            ns.pop_back();
            switch (val) {
                case '+': o_res = o1 + o2; break;
                case '-': o_res = o1 - o2; break;
                case '*': o_res = o1 * o2; break;
                case '/': o_res = o1 / o2; break;
                case '^': 
                    o_res = 1;
                    for (i = 0; i < o2; i++) {
                        o_res *= o1;
                    }
                    break;
                default: break;
            }
            ns.push_back(o_res);
        }
    }

    void pos_evo() {
        ns.clear();
        for (i = 0; i < n; i++) {
            pos_conv(s[i]);
        }
        cout << o_res << endl;
    }

    void post_evo() {
        for (i = 0; i < n; i++) {
            check_n(s[i]);
        }
        while (!arr.empty()) {
            sd.push_back(arr.top());
            arr.pop();
        }
        display();

        for (i = 0; i < sd.size(); i++) {
            pos_conv(sd[i]);
        }
        cout << o_res << endl;
    }

    void pri_conv(char val) {
        if (val >= '0' && val <= '9') {
            d = val - '0';
            ns.push_back(d);
        }
        else {
            o1 = ns[ns.size() - 1];
            ns.pop_back();
            o2 = ns[ns.size() - 1];
            ns.pop_back();
            switch (val) {
                case '+': o_res = o2 + o1; break;
                case '-': o_res = o2 - o1; break;
                case '*': o_res = o2 * o1; break;
                case '/': o_res = o2 / o1; break;
                case '^': 
                    o_res = 1;
                    for (i = 0; i < o1; i++) {
                        o_res *= o2;
                    }
                    break;
                default: break;
            }
            ns.push_back(o_res);
        }
    }

    void pr_evo() {
        ns.clear();
        for (i = n - 1; i >= 0; i--) {
            pri_conv(s[i]);
        }
        cout << o_res << endl;
    }

    void table() {
        while (true) {
            cout << "Preference Slot\n";
            cout << "1. Input expression\n";
            cout << "2. Postfix conversion\n";
            cout << "3. Prefix conversion\n";
            cout << "4. Postfix evaluation\n";
            cout << "5. Prefix evaluation\n";
            cout << "6. Exit\n";
            cout << "Enter the choice: ";
            cin >> choice;
            switch (choice) {
                case 1: input(); break;
                case 2: post(); clear_sd(); break;
                case 3: pre(); clear_sd(); break;
                case 4:
                    cout << "1. Convert postfix and then evaluate\n";
                    cout << "2. Input postfix directly and evaluate\n";
                    cout << "Enter preference: ";
                    cin >> k;
                    if (k == 1) {
                        input_n();
                        post_evo();
                        clear_sd();
                    }
                    else if (k == 2) {
                        input_n();
                        pos_evo();
                        clear_sd();
                    }
                    else {
                        break;
                    }
                    break;
                case 5:
                    input_n();
                    pr_evo();
                    clear_sd();
                    input_n();
                    pr_evo();
                    clear_sd();
                    break;
                case 6:
                    cout << "Thank you for visiting here\n";
                    return;
                    break;
                default:
                    cout << "Invalid preference\n";
                    break;
            }
        }
    }
};

int main() {
    Convert m;
    m.table();
    return 0;
}