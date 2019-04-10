#include <napi.h>
#include <iostream>
#include <sstream>
#include <windows.h>

namespace NATIVE_INFO
{
void MouseMove(int x, int y)
{
    double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
    double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
    double fx = x * (65535.0f / fScreenWidth);
    double fy = y * (65535.0f / fScreenHeight);
    INPUT Input = {0};
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    Input.mi.dx = fx;
    Input.mi.dy = fy;
    SendInput(1, &Input, sizeof(INPUT));
}
void MouseLeftDown() //鼠标左键按下
{
    INPUT Input = {0};
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &Input, sizeof(INPUT));
}

void MouseLeftUp() //鼠标左键放开
{
    INPUT Input = {0};
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &Input, sizeof(INPUT));
}

void MouseRightDown() //鼠标右键按下
{
    INPUT Input = {0};
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &Input, sizeof(INPUT));
}

void MouseRightUp() //鼠标右键放开
{
    INPUT Input = {0};
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &Input, sizeof(INPUT));
}

//--------------------------------------

Napi::Boolean MoveTo(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int x = info[0].As<Napi::Number>().Int32Value();
    int y = info[1].As<Napi::Number>().Int32Value();
    MouseMove(x, y);
    return Napi::Boolean::New(env, true);
}

Napi::Boolean LeftDown(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    MouseLeftDown();
    return Napi::Boolean::New(env, true);
}
Napi::Boolean LeftUp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    MouseLeftUp();
    return Napi::Boolean::New(env, true);
}
Napi::Boolean RightDown(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    MouseRightDown();
    return Napi::Boolean::New(env, true);
}
Napi::Boolean RightUp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    MouseRightUp();
    return Napi::Boolean::New(env, true);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "moveTo"),
                Napi::Function::New(env, MoveTo));
    exports.Set(Napi::String::New(env, "leftDown"),
                Napi::Function::New(env, LeftDown));
    exports.Set(Napi::String::New(env, "leftUp"),
                Napi::Function::New(env, LeftUp));
    exports.Set(Napi::String::New(env, "rightDown"),
                Napi::Function::New(env, RightDown));
    exports.Set(Napi::String::New(env, "rightUp"),
                Napi::Function::New(env, RightUp));

    return exports;
}

NODE_API_MODULE(hello, Init)

} // namespace NATIVE_INFO