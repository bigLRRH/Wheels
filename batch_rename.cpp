#include <iostream>
#include <filesystem>
#include <regex>
// 批量重命名并移动到新文件夹
namespace fs = std::filesystem;
using fs::__cxx11::directory_entry;

const std::string path{R"(C:\qBittorrentCache)"};
const fs::path new_path{"D:/Sources/pictures/wallpapers"};

void find_file_and_rename(const directory_entry &entry, const std::string &year, const std::string &month);

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
            const std::regex year_pattern{R"((\d+)年)"};
            const std::regex month_pattern{R"((\d+)月)"};
            std::smatch year_match;
            std::smatch month_match;
            if (std::regex_search(filename, year_match, year_pattern) && std::regex_search(filename, month_match, month_pattern))
            {
                year = year_match[1];
                month = month_match[1];

                // 将月份设置为两位数，并在不足两位时填充零
                std::stringstream month_ss;
                month_ss << std::setw(2) << std::setfill('0') << month;
                month = month_ss.str();
            }
            else
            {
                std::cout << "\033[31m"
                          << "year or month match failed:"
                          << entry.path().string()
                          << "\033[0m" << std::endl;
                continue;
            }

            std::cout << "year: " << year << std::endl;
            std::cout << "month: " << month << std::endl;
            find_file_and_rename(entry, year, month);
        }
        else
        {
            std::cout << "File path: " << entry.path().string() << std::endl;
            continue;
        }
    }

    std::cout << "File rename complete" << std::endl;
    return 0;
}

void find_file_and_rename(const directory_entry &entry, const std::string &year, const std::string &month)
{
    if (entry.is_regular_file())
    {
        std::string filename = entry.path().filename().string();
        std::cout << "\033[34m"
                  << "old_filename: " << filename
                  << "\033[0m" << std::endl;
        const std::regex filename_regex{R"((www\.acg\.gy_|acg\.gy_|ACG\.GY_)|acg,gy_)"};
        std::smatch filename_match;
        if (std::regex_search(filename, filename_match, filename_regex))
        {
            std::string new_filename = std::regex_replace(filename, filename_regex, year + month);
            std::cout << "\033[32m"
                      << "new_filename: " << new_filename
                      << "\033[0m" << std::endl;

            fs::path old_filepath = entry.path();
            fs::path new_filepath = new_path / new_filename;
            std::cout << "\033[34m"
                      << "old_filepath: " << old_filepath.string()
                      << "\033[0m" << std::endl;
            std::cout << "\033[32m"
                      << "new_filepath: " << new_filepath.string()
                      << "\033[0m" << std::endl;

            // warning
            fs::rename(old_filepath, new_filepath);
        }
        else
        {
            std::cout << "\033[33m"
                      << "filename search failed: " << filename
                      << "\033[0m" << std::endl;
        }
    }
    else if (entry.is_directory())
    {
        for (auto &sub_entry : fs::directory_iterator(entry.path()))
        {
            find_file_and_rename(sub_entry, year, month);
        }
    }
}