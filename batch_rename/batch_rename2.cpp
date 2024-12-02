// 批量重命名指定目录下指定格式的文件并移动到目标目录                                

#include <print>
#include <filesystem>
#include <regex>

namespace fs = std::filesystem;

const fs::path source_path{R"(C:\wallpapercache)"};
const fs::path destination_path{"D:/Sources/pictures/wallpapers"};

