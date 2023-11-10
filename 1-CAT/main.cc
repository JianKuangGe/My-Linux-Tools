#include <fstream>
#include <iostream>
#include <vector>
using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char** argv)
{
    if (argc == 1) {
        cout << "usage: cat file_path" << endl;
        return 0;
    }
    string file_path = argv[1];
    ifstream in(file_path);
    if (in.bad() || in.fail()) {
        cout << "can not read the file" << endl;
        cout << "usage: cat file_path" << endl;
        return 0;
    }
    string line;
    // 将每行存入，因为尾行前需要补换行符，而尾行不应该补换行符
    vector<string> lines;
    while (getline(in, line)) {
        lines.push_back(line);
    }
    auto beg = lines.begin();
    auto end = lines.end();
    // 判断是否为空文件
    if (lines.begin() == lines.end()) {
        cout << "";
        return 0;
    }
    // 输出尾行前的所有行，末尾补上getline去除的换行符
    while(beg != end - 1) {
        cout << *beg << "\n";
        beg++;
    }
    // 输出尾行
    cout << *beg;
}