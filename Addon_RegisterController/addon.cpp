#include <node.h>
#include <string>

void ControllerRegister(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();


    v8::String::Utf8Value userParam(isolate, args[0]);
    std::string username = std::string(*userParam);


    v8::String::Utf8Value passParam(isolate, args[1]);
    std::string password = std::string(*passParam);


    if (username == "admin" && password == "demo") {
        args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "Succesfuly!").ToLocalChecked());
    } else {
        args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "Invalid login").ToLocalChecked());
    }
}

void Initialize(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "ControllerRegister", ControllerRegister);
}

NODE_MODULE(ControllerRegister, Initialize)
