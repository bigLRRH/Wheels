#include <iostream>
#include <filename>
using namespace std;
int main()
{
    // 构建新的文件路径
    fs::path new_path = entry2.path().parent_path() / new_filename;

    // 重命名文件
    fs::rename(entry2.path(), new_path);
}