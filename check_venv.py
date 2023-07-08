import os

venv = os.environ.get('VIRTUAL_ENV')
if venv:
    print(f"当前激活的虚拟环境路径为：{venv}")
else:
    print("没有激活的虚拟环境。")