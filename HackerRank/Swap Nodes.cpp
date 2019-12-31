#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */
void dfs(int v, int d, vector<vector<int>>& depth, const vector<vector<int>>& indexes) {
    auto vec = indexes[v];
    depth[d].emplace_back(v);
    if (vec[0] != -1) dfs(vec[0], d + 1, depth, indexes);
    if (vec[1] != -1) dfs(vec[1], d + 1, depth, indexes);
}
void inorder(int v, vector<int>& ans, const vector<vector<int>>& indexes) {
    auto vec = indexes[v];
    if (vec[0] != -1) inorder(vec[0], ans, indexes);
    ans.emplace_back(v + 1);
    if (vec[1] != -1) inorder(vec[1], ans, indexes);
}
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    int n = indexes.size(), root = 0;
    for (auto& v : indexes) {
        if (v[0] != -1) v[0]--;
        if (v[1] != -1) v[1]--;
    }
    vector<vector<int>> depth(n + 1), ans;
    dfs(root, 1, depth, indexes);
    while (depth.back().empty()) depth.pop_back();
    for (int i = 0; i < queries.size(); i++) {
        vector<int> curr;
        int k = queries[i];
        for (int j = k; j < depth.size(); j += k)
            for (int id : depth[j])
                swap(indexes[id][0], indexes[id][1]);
        inorder(root, curr, indexes);
        ans.emplace_back(curr);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
