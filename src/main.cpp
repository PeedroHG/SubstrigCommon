#include <iostream>
#include <string>
#include <vector>
using namespace std;

int recursiveLCSMemo(
    const string& s1, const string& s2,
    size_t i, size_t j,
    int& max_len, int& start_index,
    vector<vector<int>>& memo
) {
    if (i == s1.length() || j == s2.length()) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    if (s1[i] == s2[j]) {
        int len = 1 + recursiveLCSMemo(s1, s2, i + 1, j + 1, max_len, start_index, memo);
        memo[i][j] = len;

        // Guarda a maior substring
        if (len > max_len) {
            max_len = len;
            start_index = i; // guarda onde começa na string principal
        }

        return len;
    } else {
        // Se não casam, reseta a contagem para zero
        recursiveLCSMemo(s1, s2, i + 1, j, max_len, start_index, memo);
        recursiveLCSMemo(s1, s2, i, j + 1, max_len, start_index, memo);
        return memo[i][j] = 0;
    }
}

pair<int, int> encontrarMaiorSubstringComumRec(const string& s1, const string& s2) {
    int max_len = 0;
    int start_index = -1;
    vector<vector<int>> memo(s1.length(), vector<int>(s2.length(), -1));

    recursiveLCSMemo(s1, s2, 0, 0, max_len, start_index, memo);

    if (max_len == 0) return {-1, -1};
    return {start_index, start_index + max_len - 1};
}

int main() {
    string s1 = "banana";
    string s2 = "ananas";

    auto [inicio, fim] = encontrarMaiorSubstringComumRec(s1, s2);

    if (inicio == -1) {
        cout << "Nenhuma substring comum encontrada.\n";
    } else {
        cout << inicio << "->" << fim << ": " << s1.substr(inicio, fim - inicio + 1)<< endl;

    }

    return 0;
}
