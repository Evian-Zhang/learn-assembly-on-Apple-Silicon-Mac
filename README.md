# 在 Apple Silicon Mac 上入门汇编语言

2019年，我在GitHub上创建了一个仓库[Assembly-on-macOS](https://github.com/Evian-Zhang/Assembly-on-macOS)。在这个仓库里，我写了十三篇博客，从头开始讲如何在macOS系统上入门汇编语言。3年过去了，我对二进制程序分析、汇编语言有了更深入的认识，文笔也有所长进，与此同时，Apple也在更换Mac的架构，将其从intel的amd64架构迁移到ARM的AArch64架构上。因此，我打算重制（也许是remake，也许是remaster，不如叫reforge吧）这个系列，面向使用Apple Silicon Mac的开发者，系统介绍AArch64架构汇编语言的入门知识。

HTML版本：<https://evian-zhang.github.io/learn-assembly-on-Apple-Silicon-Mac/index.html>

PDF版本：在HTML版本的右上角选择「打印」即可。

本人并不是精通汇编语言的大师，写下这一系列也只是记录自己的学习，与各位共同进步。所写文字必有错误阙漏，刍荛之言，望大家不吝斧正。欢迎大家在本仓库中提出Issue或者PR。

## 背景

我一直认为，对于一个软件开发者而言，了解一些底层的知识是十分必要的。对于汇编、操作系统、处理器的初步了解，十分有利于在日常软件开发中排除bug、优化性能。

但是，对于手持Apple Silicon Mac（即芯片为M系列的Mac）的开发者而言，入门汇编语言却相对更加困难。

1. 如今国内大部分的中文教材，还是停留在32位甚至16位的处理器上，有些还需要DOS来模拟。
2. 虽然也有一些更现代的书籍、博客会介绍如今主流的64位处理器的汇编语言，但是这些介绍往往是基于Linux和Windows操作系统，在macOS上仍然会有一些差异（如mach-O格式的段、节的名称，命名粉碎机制，系统调用号等）。
3. 就算终于找到了基于macOS的汇编语言入门的文章，也往往都是两三年前所写，仍然基于intel的amd64架构。而Apple Silicon的Mac则使用ARM的AArch64架构，两者更是完全不同。

在macOS上使用Docker等虚拟化方案，虽然可以让我们接触amd64架构的Linux系统，但为什么不用原生的呢？

因此，本系列将针对使用Apple Silicon Mac的开发者，介绍AArch64架构汇编语言的入门知识。

需要指出，我写的这一系列文章，**并不旨在让读者成为macOS底层的专家**，而是让手持Apple Silicon Mac的开发者轻松地入门汇编语言，进而为我国软件独立自主作出自己的贡献。

本系列的目的是让没有接触过汇编语言的开发者，会读、会写汇编语言，既能使用汇编语言写出一些高性能的代码，也能读懂二进制软件的逆向。只不过使用的是AArch64架构，用macOS操作系统。因此，在本系列的文章中，大部分的知识都是跨系统、跨平台都适用的概念，对于macOS独有的一些概念，并不会着重介绍。但也不必担心，本系列中的所有过程、步骤，都可以在macOS上原生执行。

## 前置知识要求

本系列的前置知识要求并不高，主要包括以下三点：

* 能看懂C语言编写的程序
* 适当了解计算机体系结构知识
* 能够简单使用命令行进行操作

## 编程环境

我在写这系列文章时，所使用的环境为：

* 芯片

   Apple M1 Pro
* 操作系统

   macOS 12.4
* 操作系统内核

   Darwin Kernel Version 21.5.0
* XNU源码版本

   `xnu-8020.101.4`，下载于[apple-oss-distributions/xnu](https://github.com/apple-oss-distributions/xnu)
* `clang`版本

   Apple clang version 13.1.6 (clang-1316.0.21.2)

## 参考资料

* [Using `as`](https://sourceware.org/binutils/docs/as/index.html)
* [OS X Assembler Reference](https://developer.apple.com/library/archive/documentation/DeveloperTools/Reference/Assembler)
* [Armv8-A Instruction Set Architecture](https://developer.arm.com/-/media/Arm%20Developer%20Community/PDF/Learn%20the%20Architecture/Armv8-A%20Instruction%20Set%20Architecture.pdf)
* [Arm Architecture Reference Manual for A-profile architecture](https://developer.arm.com/documentation/ddi0487/latest)
* [ARM Assembly Language](https://www.oreilly.com/library/view/arm-assembly-language/9781482229851/)
* [Writing ARM64 Code for Apple Platforms](https://developer.apple.com/documentation/xcode/writing-arm64-code-for-apple-platforms)

#### License

<sup>
本仓库遵循<a href="https://creativecommons.org/licenses/by/4.0/">CC-BY-4.0版权协议</a>。
</sup>

<br/>

<sub>
作为<a href="https://copyleft.org/">copyleft</a>的支持者之一，我由衷地欢迎大家积极热情地参与到开源社区中。Happy coding!
</sub>
