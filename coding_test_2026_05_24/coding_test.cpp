#include <bits/stdc++.h>
using namespace std;

// タグ名を受け取り、開始タグを返す
string start_tag(string s) {
    string res = "";
    // 先頭のスペースから、初めて文字列に切り替わったかを管理するフラグ
    bool first = true;
    for (int i = 0;i < (int)s.size();i++) {
        if(s[i] != ' ') {
            if (first) {
                res += "<";
                first = false;
            }
            res += s[i];
        } else {
            res += s[i];
        }
    }
    res += ">";
    return res;
};

// タグ名を受け取り、スペース付きの終了タグを返す
string end_tag_with_space(string s) {
    string res = "";
    bool first = true;
    for (int i = 0;i < (int)s.size();i++) {
        if(s[i] != ' ') {
            if (first) {
                res += "</";
                first = false;
            }
            res += s[i];
        } else {
            res += s[i];
        }
    }
    res += ">";
    return res;
};

// タグ名を受け取り、スペース無しの終了タグを返す
string end_tag_without_space(string s) {
    string res = "</";
    for (int i = 0;i < (int)s.size();i++) {
        if(s[i] != ' ') {
            res += s[i];
        }
    }
    res += ">";
    return res;
};

// 先頭にいくつスペースがあるかを返す
int space_size(string s) {
    int res = 0;
    for (int i = 0;i < (int)s.size();i++) {
        if(s[i] == ' ') {
            res++;
        } else {
            break;
        }
    }
    return res;
};

// スペース文字列でインデントされたツリーをXMLツリーに変換する関数(課題の解答となる関数)
void convert_to_xml() {
    // 入力の受け取り
    string input_line;
    vector<string> inputs;
    while (getline(cin, input_line)) {
        if (!input_line.size()) break;
        inputs.push_back(input_line);
    }

    int input_row_numbers = inputs.size();
    // まだ閉じていないタグをstackで管理する。
    stack<string> sta;
    for (int i = 0; i < input_row_numbers; i++) {
        //　次の行のスペース数が現在より多く、タグがさらに広がる場合
        if (inputs[i].size() < inputs[i+1].size()) {
            // まだ閉じていないタグをstackに積み上げておく。
            sta.push(inputs[i]);
            cout << start_tag(inputs[i])<< endl;
        // 次と現在の行のスペース数が同じ場合、この行は閉じてよい。
        } else if (inputs[i].size() == inputs[i+1].size()) {
            cout << start_tag(inputs[i]) + end_tag_without_space(inputs[i]) << endl;
        //　次の行のスペース数が現在より少ない場合、stackに積んであるタグを閉じれるだけ閉じる。
        } else {
            cout << start_tag(inputs[i]) + end_tag_without_space(inputs[i]) << endl;
            while(i - 1< input_row_numbers && sta.size() && space_size(sta.top()) >= space_size(inputs[i+1])) {
                cout << end_tag_with_space(sta.top()) << endl;
                sta.pop();
            }
        }
    }
};


// 呼び出し関数です。
int main()
{
    convert_to_xml();
    return 0;
}

