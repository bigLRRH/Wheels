import os

# 设置路径和输出文件
source_folder = (
    "C:/Users/redir/Desktop/temp/projects/im/src-tauri/src"  # 替换为你的代码目录路径
)
output_file = "./merged_code.txt"  # 合并输出文件

# 要合并的文件扩展名（可根据需要添加）
extensions = [
    ".py",
    ".js",
    ".ts",
    ".rs",
    ".cpp",
    ".c",
    ".h",
    ".html",
    ".css",
    ".vue",
    ".scss",
]

with open(output_file, "w", encoding="utf-8") as outfile:
    for root, _, files in os.walk(source_folder):
        for file in files:
            if any(file.endswith(ext) for ext in extensions):
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, "r", encoding="utf-8") as infile:
                        # 写入标题和分隔线
                        outfile.write(f"\n\n====== {file_path} ======\n\n")
                        outfile.write(infile.read())
                except Exception as e:
                    print(f"无法读取文件 {file_path}：{e}")
