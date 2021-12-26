# Bilibili-Playin-Mpv

------------

本项目旨在基于[Bilibili-Evolved](https://github.com/the1812/Bilibili-Evolved "Bilibili-Evolved")提供在本地播放器MPV中在线播放Bilibili视频的功能。

视频播放地址API随[Bilibili-Evolved](https://github.com/the1812/Bilibili-Evolved "Bilibili-Evolved")进行更新，使用Application URL的方式调用本地程序，进行参数转换后唤起mpv播放器进行播放。

------------

## 编译

 - 用VS2022编译，其他版本的也应该可以
 
## 食用指南

 - 运行前确保系统已安装[Visual C++ 2022 Redistributable (x64)](https://aka.ms/vs/17/release/vc_redist.x64.exe)或[Visual C++ 2022 Redistributable (x86)](https://aka.ms/vs/17/release/vc_redist.x86.exe)
 - 下载[最新发行版](https://github.com/diannaojiang/Bilibili-Playin-Mpv/releases "最新发行版")并解压
 - 将**playinmpv.exe**放置到MPV安装目录中的**mpv.exe**程序同目录
 - 修改**mpv.reg**中的目录信息为你的MPV所在目录
```bash
Windows Registry Editor Version 5.00

[HKEY_CLASSES_ROOT\mpv]
"URL Protocol"=""

[HKEY_CLASSES_ROOT\mpv\DefaultIcon]
@="你的MPV安装目录\\mpv.exe,1"

[HKEY_CLASSES_ROOT\mpv\shell]

[HKEY_CLASSES_ROOT\mpv\shell\open]
@=""

[HKEY_CLASSES_ROOT\mpv\shell\open\command]
@="\"你的MPV安装目录\\playinmpv.exe\" \"%1\""


```

- 双击运行**mpv.reg**导入注册表
- 在[Bilibili-Evolved](https://github.com/the1812/Bilibili-Evolved "Bilibili-Evolved")中使用:**设置-插件-添加插件-在线**添加**MPV 输出支持**
- 在视频页左侧呼出[Bilibili-Evolved](https://github.com/the1812/Bilibili-Evolved "Bilibili-Evolved")-功能-下载视频
- 请注意使用时**格式**要选用Dash-h.265或h.264
- 输出方式选择MPV后点击开始屏幕左下方会弹出播放按钮，再次点击后即可呼出本地播放器进行播放
