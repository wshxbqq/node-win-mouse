# node-win-mouse
nodejs 模拟鼠标动作 类似鼠标精灵

__底层使用软件模拟点击. 并非驱动程序级别模拟__


需要 `64bit Winodws`   `Nodejs 6.0.0 + `


|方法|用途|
|---|---|
|moveTo|控制鼠标移动|
|leftDown|左键按下|
|leftUp|左键弹起|
|rightDown|右键按下|
|rightUp|右键弹起|

```javascript
const WinMouse = require('./build/Release/addon');
WinMouse.moveTo(200,300);
WinMouse.leftDown();
WinMouse.leftUp();
WinMouse.rightDown();
WinMouse.rightUp();
console.log(WinMouse); 
```


