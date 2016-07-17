// hello.cc
#include <node.h>
#include <iostream>
#include <sstream>
#include <windows.h>

namespace NATIVE_INFO {

	using v8::Exception;
	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Number;
	using v8::Object;
	using v8::String;
	using v8::Value;
	
	void MouseMove(int x, int y)//鼠标移动到指定位置  
    {  
        double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;//获取屏幕分辨率宽度  
        double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;//获取屏幕分辨率高度  
        double fx = x*(65535.0f / fScreenWidth);  
        double fy = y*(65535.0f / fScreenHeight);  
        INPUT  Input = { 0 };  
        Input.type = INPUT_MOUSE;  
        Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;  
        Input.mi.dx = fx;  
        Input.mi.dy = fy;  
        SendInput(1, &Input, sizeof(INPUT));  
    }  
      
    void MouseLeftDown()//鼠标左键按下  
    {  
        INPUT  Input = { 0 };  
        Input.type = INPUT_MOUSE;  
        Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;  
        SendInput(1, &Input, sizeof(INPUT));  
    }  
      
    void MouseLeftUp()//鼠标左键放开  
    {  
        INPUT  Input = { 0 };  
        Input.type = INPUT_MOUSE;  
        Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;  
        SendInput(1, &Input, sizeof(INPUT));  
          
    }  
      
    void MouseRightDown()//鼠标右键按下  
    {  
        INPUT  Input = { 0 };  
        Input.type = INPUT_MOUSE;  
        Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;  
        SendInput(1, &Input, sizeof(INPUT));  
    }  
      
    void MouseRightUp()//鼠标右键放开  
    {  
        INPUT  Input = { 0 };  
        Input.type = INPUT_MOUSE;  
        Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;  
        SendInput(1, &Input, sizeof(INPUT));  
    }  


	void MoveTo(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();
		MouseMove(args[0]->Int32Value(), args[1]->Int32Value());
	}

	void LeftDown(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();
		MouseLeftDown();
	}

	void LeftUp(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();
		MouseLeftUp();
	}

	void RightDown(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();
		MouseRightDown();
	}

	void RightUp(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();
		MouseRightUp();
	}



	void Init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "moveTo", MoveTo);
		NODE_SET_METHOD(exports, "leftDown", LeftDown);
		NODE_SET_METHOD(exports, "leftUp", LeftUp);
		NODE_SET_METHOD(exports, "rightDown", RightDown);
		NODE_SET_METHOD(exports, "rightUp", RightUp);
		
	}

	NODE_MODULE(addon, Init)

}  // namespace demo