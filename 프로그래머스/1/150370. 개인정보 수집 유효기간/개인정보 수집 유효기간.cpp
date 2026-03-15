#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    stringstream ss(today);
    string ty, tm, td, temp;
    string y, m, d;
    int ity, itm, itd;
    int iy, im, id;
    int due;
    getline(ss, ty, '.');
    getline(ss, tm, '.');
    getline(ss, td, '.');
    ity = stoi(ty);
    itm = stoi(tm);
    itd = stoi(td);
    map<char, int> expires;
    for (int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        getline(ss, temp, ' ');
        getline(ss, temp, ' ');
        expires.insert(make_pair(terms[i][0], stoi(temp)));
    }
    for (int i = 0; i < privacies.size(); i++) {
        stringstream ss(privacies[i]);
        getline(ss, y, '.');
        getline(ss, m, '.');
        getline(ss, d, ' ');
        iy = stoi(y);
        im = stoi(m);
        id = stoi(d);
        getline(ss, temp, ' ');
        due = expires.find(temp[0])->second;
        im += due;
        while (im > 12) {
            iy++;
            im -= 12;
        }
        cout << iy << " " << im << " " << id << endl;
        if (ity > iy)
            answer.push_back(i + 1);
        else if (ity == iy) {
            if (itm > im)
                answer.push_back(i + 1);
            else if (itm == im) {
                if (itd >= id)
                    answer.push_back(i + 1);
            }
        }
    }
    
    return answer;
}