# 嵌入式系统综合设计

基于 STM32 和 FreeRTOS 实现多外设驱动系统。

## 开发

### 准备工作

需要安装好 PlatformIO，参考：

[PlatformIO 安装教程](https://docs.platformio.org/en/latest/core/installation/index.html)

TLDR：

安装 Python 环境：

```pwsh
# windows 下使用 winget 安装
winget install -e --id Python.Python.3.11

# Linux 下参考发行版文档
```

安装 PlatformIO：

```bash
pip install platformio
# 推荐，使用 pipx
pipx install platformio
```

### 构建

```bash
pio run
```

构建并烧写：

```bash
pio run -t upload
```

### 编辑器支持

生成 compiledb：

```bash
pio run -t compiledb
```
