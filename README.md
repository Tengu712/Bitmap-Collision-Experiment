# Bitmap Collision Experiment

## Outline

衝突判定を愚直に実装するのとビットマップを用いて行うのとの比較検証用プログラム。

2D弾幕STGを想定しており、「衝突したか否か」のみが重要であり、反射角度はどうでもいいため、`EntityPosition::reflect()`はなんちゃって実装になっている。

## Article

[https://skdassoc.com/posts/bitmap-collision/](https://skdassoc.com/posts/bitmap-collision/)

## Build

Windows向けプログラムであるため、Windowsでビルドする。

ビルドのバッチとして以下の二つを用意している。
ただし、MSVCでビルドするため、Command Prompt for VSで実行するといい。

- test.bat: 速度テスト用のビルド
- simulation.bat: シミュレーション用のビルド

## Result

### Non Trimmed

![non trimmed](img/graph-all.png?raw=true)

### Trimmed (X=[0, 2000])

![trimmed](img/graph-part.png?raw=true)
