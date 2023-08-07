#include <iostream>
#include <filesystem>
#include <regex>
// 批量重命名并移动到新文件夹
namespace fs = std::filesystem;

std::string path = R"(C:\qBittorrentCache)";
fs::path new_path = "D:/Sources/pictures/wallpapers";

int main()
{
    for (const auto &entry : fs::directory_iterator(path))
    {
        if (entry.is_directory())
        {
            std::string filename = entry.path().filename().string();
            std::cout << "filename: " << filename << std::endl;

            std::string year;
            std::string month;
            std::regex year_pattern{R"((\d+)year)"};
            std::regex month_pattern{R"((\d+)month)"};
            std::smatch year_match;
            std::smatch month_match;
            if (std::regex_search(filename, year_match, year_pattern))
            {
                year = year_match[1];
                std::cout << "Year: " << year << std::endl;
            }
            else
            {
                std::cout << "\033[31m"
                          << "year match failed"
                          << "\033[0m" << std::endl;
                break;
            }
            if (std::regex_search(filename, month_match, month_pattern))
            {
                month = month_match[1];
                // 将月份设置为两位数，并在不足两位时填充零
                std::stringstream month_ss;
                month_ss << std::setw(2) << std::setfill('0') << month;
                month = month_ss.str();
                std::cout << "Month: " << month << std::endl;
            }
            else
            {
                std::cout << "\033[31m"
                          << "month match failed "
                          << "\033[0m" << std::endl;
                break;
            }
            for (const auto &entry1 : fs::directory_iterator(entry.path()))
            {
                if (entry1.is_directory())
                {
                    for (const auto &entry2 : fs::directory_iterator(entry1.path()))
                    {
                        if (entry2.is_regular_file())
                        {
                            std::string filename = entry2.path().filename().string();
                            std::cout << "filename: " << filename << std::endl;
                            std::regex filename_regex{R"((www\.acg\.gy_|acg\.gy_|ACG.GY_))"};
                            std::smatch filename_match;
                            if (std::regex_search(filename, filename_match, filename_regex))
                            {
                                std::string new_filename = std::regex_replace(filename, filename_regex, year + month);
                                std::cout << "\033[32m"
                                          << new_filename
                                          << "\033[0m" << std::endl;
                                fs::path newPath = new_path / new_filename;
                                std::cout << "oldPath: " << entry2.path().string() << std::endl;
                                std::cout << "newPath: " << newPath.string() << std::endl;
                                fs::rename(entry2.path(), newPath);
                            }
                            else
                            {
                                std::cout << "\033[34m"
                                          << "filename search failed: " << filename
                                          << "\033[0m" << std::endl;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            std::cout << "File path: " << entry.path().string() << std::endl;
        }
    }

    return 0;
}