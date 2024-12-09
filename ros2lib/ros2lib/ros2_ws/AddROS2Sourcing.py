import yaml
import os
import re
from pathlib import Path

def add_source_command_to_bashrc():
    current_file_path = os.path.abspath(__file__)
    current_directory = os.path.dirname(current_file_path)
    new_file_path = os.path.join(current_directory, 'install', 'setup.sh')
    
    bashrc_path = os.path.expanduser('~/.bashrc')
    
    # .bashrc 파일 읽기
    with open(bashrc_path, 'r') as file:
        bashrc_contents = file.readlines()
    
    # 소스 명령어 목록
    commands_to_add = [
        'source /opt/ros/humble/setup.bash',
        f'source {new_file_path}'
    ]
    
    # 각각의 source 명령어 확인 및 추가
    for command in commands_to_add:
        # 해당 source 명령어가 .bashrc 파일에 존재하는지 확인
        if not any(command in line for line in bashrc_contents):
            # 명령어가 없다면 .bashrc 파일 끝에 추가
            with open(bashrc_path, 'a') as file:
                file.write(f'\n{command}\n')
            print(f"Added '{command}' to .bashrc")
        else:
            print(f"'{command}' already exists in .bashrc")

def main():
    add_source_command_to_bashrc()

if __name__ == "__main__":
    main()
