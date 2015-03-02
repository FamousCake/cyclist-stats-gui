#include <node.h>

using namespace v8;

void CreateObject(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  Local<Object> obj = Object::New(isolate);

  Handle<Value> a;

  obj->Set(String::NewFromUtf8(isolate, "name"), args[0]->ToString());
  obj->Set(String::NewFromUtf8(isolate, "age"), Integer::New(isolate, 123));

  args.GetReturnValue().Set(obj);
}

void Init(Handle<Object> exports, Handle<Object> module) {
  NODE_SET_METHOD(module, "exports", CreateObject);
}

NODE_MODULE(addon, Init)
