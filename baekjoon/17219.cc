#include <cstddef>
#include <ios>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    size_t N, M;
    cin >> N >> M;

    map<string, string> passwords;
    string site, password;
    for (size_t i = 0; i < N; i++) {
        cin >> site >> password;
        passwords.insert(make_pair(site, password));
    }

    string query;
    for (size_t i = 0; i < M; i++) {
        cin >> query;
        cout << passwords.find(query)->second << '\n';
    }

    return 0;
}
