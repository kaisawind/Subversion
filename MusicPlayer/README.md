# MusicPlayer

## 1. 概述

VS2012 创建的工程
使用WINAPI编程

## 2. 源代码目录结构

```shell
    MusicPlayer.sln
    README.md
    设计文档.xlsx
    MusicPlayer
	CFilesProcessor.cpp
	CFilesProcessor.h
	CMusicProcessor.cpp
	CMusicProcessor.h
	Common.cpp
	Common.h
	CViewerProcessor.cpp
	CViewerProcessor.h
	libzplay.dll
	libzplay.h
	libzplay.lib
	MusicPlayer.aps
	MusicPlayer.cpp
	MusicPlayer.h
	MusicPlayer.ico
	MusicPlayer.rc
	MusicPlayer.vcxproj
	MusicPlayer.vcxproj.filters
	ReadMe.txt
	resource.h
	small.ico
	stdafx.cpp
	stdafx.h
	targetver.h
```

## 3. 编译及运行

编译工程时会产生Debug或者Release文件夹
需要将MusicPlayer文件夹下的libzplay.dll拷贝到
Debug或者Release文件夹下

目录结构
```shell
MusicPlayer
  Debug
    libzplay.dll
    ...
    MusicPlayer
```shell
--------	...
