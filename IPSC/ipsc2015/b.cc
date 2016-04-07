#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include <map>
#include <cassert>

using namespace std;

int main() {
    unordered_map<int, list<pair<int,int>>> mp12;
    // unordered_map<int, list<pair<int,int>>::iterator> it12;
    unordered_map<int, list<int>> mp3;
    // unordered_map<int, list<int>::iterator> it3;
    vector<pair<string, int>> v1, v2, v3;
    map<string, int> s1, s2, s3;
    int m;
    cin >> m;
    string s;
    int c;
    while (m--) {
        cin >> s >> c;
        v1.emplace_back(s, c);
        s1[s] = c;
    }
    cin >> m;
    cerr << m << endl;
    while (m--) {
        cin >> s >> c;
        v2.emplace_back(s, c);
        s2[s] = c;
    }
    cin >> m;
    cerr << m << endl;
    while (m--) {
        cin >> s >> c;
        v3.emplace_back(s, c);
        s3[s] = c;
    }


    int n;
    cin >> n;
    // cerr << n << endl;
    vector<int> qv;
    map<int, int> qs;
    map<int, list<pair<pair<int,int>,int>>> ans;
    string w1, w2, w3;
    while (n--) {
        cin >> w1 >> w2 >> w3;
        assert(s1[w1] && s2[w2] && s3[w3]);
        int score = s1[w1] + s2[w2] + s3[w3] + 1;
        qv.push_back(score);
        qs[score]++;
        cerr << score << endl;
    }
    
    for (int i = 0; i < v1.size(); i++) {
        cerr << i << endl;
        for (int j = 0; j < v2.size(); j++) {
            mp12[v1[i].second + v2[j].second].emplace_back(i, j);
        }
    }

    for (int i = 0; i < v3.size(); i++) {
        mp3[v3[i].second].push_back(i);
    }

    for (auto &pr: qs) {
        int q = pr.first, c = pr.second;
        cerr << q << ' ' << c << endl;
        for (auto &pr3: mp3) {
            if (c == 0) {
                break;
            }
            int s = q - pr3.first;
            auto it = mp12.find(s);
            if (it != mp12.end()) {
                for (auto &pr: it->second) {
                    if (c == 0) {
                        break;
                    }
                    for (int i3: pr3.second) {
                        if (c == 0) {
                            break;
                        }
                        ans[q].push_back(make_pair(pr, i3));
                        c--;
                    }
                }
            }
        }
    }

    for (int q: qv) {
        // cerr << q << ' ' << ans[q].size() << endl;
        int i1 = ans[q].front().first.first, i2 = ans[q].front().first.second, i3 = ans[q].front().second;
        ans[q].pop_front();
        cout << v1[i1].first << ' ' << v2[i2].first << ' ' << v3[i3].first << endl;
    }

}