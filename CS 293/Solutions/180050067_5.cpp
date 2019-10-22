#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct query {
	char type;
	int pid;
	int size;
	int address;
	int index;
};
struct block {
	int pid;
	int s;
	int e;
};
list<block> alloc;
list<query> pending;
int ans[1000007];
int n, M;

bool my_allocator(query curr_query) {
	block t;
	if (alloc.empty()) {
		t.s = 0;
		t.e = curr_query.size - 1;
		t.pid = curr_query.pid;
		alloc.push_back(t);
		ans[curr_query.index] = 0;
		return true;
	}
	else {
		auto it = alloc.begin();
		int end = (*it).e;
		if ((*it).s >= curr_query.size) {
			t.s = 0;
			t.e = curr_query.size - 1;
			t.pid = curr_query.pid;
			alloc.insert(it, t);
			ans[curr_query.index] = 0;
			return true;
		}
		it++;
		for (; it != alloc.end(); it++) {
			if ((*it).s - end - 1 >= curr_query.size) {
				t.s = end + 1;
				t.e = end + curr_query.size;
				t.pid = curr_query.pid;
				alloc.insert(it, t);
				ans[curr_query.index] = end + 1;
				return true;
			}
			end = (*it).e;
		}
	}
	int endi = alloc.back().e;
	if (endi + curr_query.size < M) {
		t.s = endi + 1;
		t.e = curr_query.size + endi;
		t.pid = curr_query.pid;
		alloc.push_back(t);
		ans[curr_query.index] = t.s;
		return true;
	}
	return false;
}

void process() {
	if (!pending.empty()) {
		for (auto it = pending.begin(); it != pending.end(); it++) {
			if (my_allocator((*it))) {
				it = pending.erase(it);
				it--;
			}
		}
	}
	else return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> M;
	int query_count = 0;
	for (int i = 0; i < 1000007; i++)
		ans[i] = -10;
	vector<query> q;
	query curr_query;
	cin >> curr_query.type;
	if (curr_query.type == 'A') {
		cin >> curr_query.pid >> curr_query.size;
		curr_query.address = -1;
		curr_query.index = query_count;
	}
	else if (curr_query.type == 'D') {
		cin >> curr_query.pid >> curr_query.address;
		curr_query.size = -1;
		curr_query.index = query_count;
	}
	else if (curr_query.type == 'T') {
		cin >> curr_query.pid;
		curr_query.address = -1;
		curr_query.size = -1;
		curr_query.index = query_count;
	}
	else {
		curr_query.pid = -1;
		curr_query.address = -1;
		curr_query.size = -1;
		curr_query.index = query_count;
	}
	while (curr_query.type != 'H') {
		bool c;
		block t;
		if (curr_query.type == 'A') {
			if (!my_allocator(curr_query))
				pending.push_back(curr_query);
		}
		if (curr_query.type == 'T') {
			c = 1;
			for (auto it = alloc.begin(); it != alloc.end(); it++) {
				if (curr_query.pid == (*it).pid) {
					it = alloc.erase(it);
					it--;
					c = 0;
					ans[curr_query.index] = 0;
				}
			}
			if (!pending.empty()) {
				for (auto it = pending.begin(); it != pending.end(); it++) {
					if ((*it).pid == curr_query.pid) {
						it = pending.erase(it);
						it--;
					}
				}
			}
			if (c) ans[curr_query.index] = 1;
			process();
		}
		if (curr_query.type == 'D') {
			c = 1;
			for (auto it = alloc.begin(); it != alloc.end(); it++) {
				if (curr_query.pid == (*it).pid && curr_query.address == (*it).s) {
					alloc.erase(it);
					c = 0;
					ans[curr_query.index] = 0;
					break;
				}
			}
			if (c) ans[curr_query.index] = 1;
			process();
		}
		query_count++;
		cin >> curr_query.type;
		if (curr_query.type == 'A') {
			cin >> curr_query.pid >> curr_query.size;
			curr_query.address = -1;
			curr_query.index = query_count;
		}
		else if (curr_query.type == 'D') {
			cin >> curr_query.pid >> curr_query.address;
			curr_query.size = -1;
			curr_query.index = query_count;
		}
		else if (curr_query.type == 'T') {
			cin >> curr_query.pid;
			curr_query.address = -1;
			curr_query.size = -1;
			curr_query.index = query_count;
		}
		else {
			curr_query.pid = -1;
			curr_query.address = -1;
			curr_query.size = -1;
			curr_query.index = query_count;
		}

	}
	if (!pending.empty()) {
		for (auto it = pending.begin(); it != pending.end(); it++) {
			ans[(*it).index] = -1;
		}
	}
	for (int i = 0; i < query_count; i++)
		if (ans[i] == -10)
			ans[i] = -1;
	for (int i = 0; i < query_count; i++)
		cout << ans[i] << endl;
}
