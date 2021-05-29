# lua53
## 意图
学习 lua 源码
## 编译
### 1. 下载mingw64
1. (下载链接参考)[https://code.visualstudio.com/docs/cpp/config-mingw]
2. 安装完后添加环境变量
3. bin下复制mingw32-make.exe为make.exe
### 2. vscode安装
```
1. EmmyLua
2. C++
3. C++ Intellisense
```
### 3. 创建debug launch.json
```
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) 启动",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/src/lua.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "gdb",
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```
### 4. make
```
$ cd lua53
$ make mingw -- 生成lua.exe在src
$ make clean -- 清理
```
### 5. debug
```
1. gdb src/lua.exe
2. vscode F5
```