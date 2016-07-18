# node-win-mouse 模拟鼠标动作 类似鼠标精灵

  npm install -g node-win-mouse

__`node-win-mouse` 为操作系统基本模拟. 并非`硬件驱动程序`级别模拟__


需要 `64bit Winodws`   `Nodejs 6.0.0 + `


|方法|用途|
|---|---|
|moveTo|控制鼠标移动|
|leftDown|左键按下|
|leftUp|左键弹起|
|rightDown|右键按下|
|rightUp|右键弹起|

```javascript
const WinMouse = require('node-win-mouse');
WinMouse.moveTo(200,300);
WinMouse.leftDown();
WinMouse.leftUp();
WinMouse.rightDown();
WinMouse.rightUp();
console.log(WinMouse); 
```


