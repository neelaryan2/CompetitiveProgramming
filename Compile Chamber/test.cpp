// #include <iostream>
#include<bits/stdc++.h>
using namespace std;
// #include <jsoncpp/json/json.h>
#define all(v) (v).begin(), (v).end()
struct Menu {
    map<string, int> prices;
    map<string, vector<int>> subparts;
    map<string, int> ingredID;
    vector<string> ingreds;
    vector<vector<string>> dishes;
    Menu () {}
    void updateIngred(const vector<string>& ingredients) {
        for (string s : ingredients) {
            auto it = ingredID.find(s);
            if (it == ingredID.end()) {
                ingredID[s] = ingreds.size();
                ingreds.push_back(s);
            }
        }
    }
    void addDish(string dishName, const vector<string>& ingredients, int price) {
        auto it = prices.find(dishName);
        if (it != prices.end()) return;
        prices[dishName] = price;
        updateIngred(ingredients);
        vector<int> cur;
        for (string s : ingredients) {
            int id = ingredID[s];
            cur.push_back(id);
            while (id >= (int)dishes.size())
                dishes.emplace_back();
            dishes[id].push_back(dishName);
        }
        subparts[dishName] = cur;
    }  
    void printMenu() {
        cout << "Dish : Ingredients : Price\n";
        for (auto p : prices) {
            string s = p.first;
            cout << s << " : ( ";
            for (int id : subparts[s]) {
                string cur = ingreds[id];
                cout << cur << ", ";
            }
            cout << ") : ";
            cout << prices[s] << '\n';
        }
    }
    vector<string> getDishes2(const string& ingredient) {
        int id = ingredID[ingredient];
        return dishes[id];
    }
    vector<string> getDishes(const vector<string>& ingredients) {
        set<string> ans;
        bool init = false;
        for (string ingredient : ingredients) {
            int id = ingredID[ingredient];
            set<string> cur = set<string>(all(dishes[id]));
            // if (!is_sorted(cur.begin(), cur.end()))
                // sort(cur.begin(), cur.end());
            if (!init) {
                ans = cur;
                init = true;
                continue;
            }
            // vector<string> tmp;
            for (string s : cur) {
                auto it = ans.find(s);
                if (it != ans.end()) continue;
                ans.erase(it);
            }
            for (auto it = ans.begin(); it != ans.end();) {
                auto it2 = cur.find(*it);
                if (it2 != cur.end()) it++;
                else it = ans.erase(it);
            }
            // set_intersection(all(ans), all(cur), tmp.begin());
            // ans.swap(tmp);
        }
        return vector<string>(all(ans));
    }
};
int main() {
    Menu menu; 
    menu.addDish("D1", {"I1", "I2"}, 123);
    menu.addDish("D2", {"I2", "I3", "I4", "I5"}, 12);
    menu.addDish("D3", {"I1"}, 1456);
    menu.printMenu();
    for (string s : menu.getDishes2("I2")) cout << s << ' '; cout << '\n' << flush;
    for (string s : menu.getDishes({"I2", "I3"})) cout << s << ' ';  cout << '\n';
    for (string s : menu.getDishes({"I6"})) cout << s << ' ';  cout << '\n';
}

// Implement a Restaurant Menu application with the following functionalities -
// 1. Adding dishes to the menu (where a dish includes name, list of ingredients & price)
// 2. Displaying the menu (list of dishes with details)
// 3. Filtering the menu based on a list of ingredients - show all dishes with given ingredients & without given ingredients
