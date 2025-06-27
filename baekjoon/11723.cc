#include <cstddef>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

enum class Query { ADD, REMOVE, CHECK, TOGGLE, ALL, EMPTY, ERROR };

Query parse_query(string &input) {
    if (input == "add")
        return Query::ADD;
    if (input == "remove")
        return Query::REMOVE;
    if (input == "check")
        return Query::CHECK;
    if (input == "toggle")
        return Query::TOGGLE;
    if (input == "all")
        return Query::ALL;
    if (input == "empty")
        return Query::EMPTY;

    return Query::ERROR;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    size_t M;
    cin >> M;

    int state = 0;

    string query;
    int n;
    for (size_t i = 0; i < M; i++) {
        cin >> query;

        switch (parse_query(query)) {
            case Query::ADD:
                cin >> n;
                state |= 1 << n;
                break;
            case Query::REMOVE:
                cin >> n;
                state &= ~(1 << n);
                break;
            case Query::CHECK:
                cin >> n;
                cout << ((state & (1 << n)) ? 1 : 0) << '\n';
                break;
            case Query::TOGGLE:
                cin >> n;
                state ^= 1 << n;
                break;
            case Query::ALL:
                state = (1 << 21) - 1;
                break;
            case Query::EMPTY:
                state = 0;
                break;
            case Query::ERROR:
                break;
        }
    }
}
