import os
import zipfile

# 压缩包文件夹路径
zip_folder = "C:/qBittorrentCache"

# 解压缩并重命名文件
def extract_and_rename_files(zip_file):
    with zipfile.ZipFile(zip_file, "r") as zip_ref:
        # 提取年份和月份
        year = zip_file.split("年")[0][-4:]
        month = zip_file.split("月")[0][-2:]

        # 解压缩文件
        zip_ref.extractall(zip_folder)

        # 重命名文件
        for file_name in zip_ref.namelist():
            if file_name.startswith("acg_gy"):
                new_file_name = f"{year}{month}{file_name[7:]}"
                os.rename(os.path.join(zip_folder, file_name), os.path.join(zip_folder, new_file_name))

# 遍历压缩包文件夹
for file_name in os.listdir(zip_folder):
    if file_name.endswith(".zip"):
        zip_file = os.path.join(zip_folder, file_name)
        extract_and_rename_files(zip_file)