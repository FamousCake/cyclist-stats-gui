#include <node.h>

#include "./cpp/inc/io.h"
#include "./cpp/inc/data_point.h"

using namespace v8;

void CreateObject(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    Local<Object> obj = Object::New(isolate);

    // get the param
    v8::String::Utf8Value param1(args[0]->ToString());

    // convert it to string
    std::string filepath = std::string(*param1);

    //printf("%s\n", filepath);
    std::cout << filepath;

    std::vector<DataPoint> v(io::readData(filepath.c_str()));//"./data.hrm"));

    DataPoint avg(0,0,0,0,0,0);

    for(auto node : v)
    {
        avg.HeartRate += node.HeartRate;
        avg.Speed += node.Speed;
        avg.Cadance += node.Cadance;
        avg.Altitude += node.Altitude;
        avg.Power += node.Power;
        avg.PowerBalance += node.PowerBalance;
    }

    // Create a new empty array.
    Handle<Array> array = Array::New(isolate, 3);

    // Fill out the values
    array->Set(0, Integer::New(isolate, 9));
    array->Set(1, Integer::New(isolate, 6));
    array->Set(2, Integer::New(isolate, 7));

    //obj->Set(String::NewFromUtf8(isolate, "name"), args[0]->ToString());
    obj->Set(String::NewFromUtf8(isolate, "HeartRate"), Integer::New(isolate, avg.HeartRate));
    obj->Set(String::NewFromUtf8(isolate, "Speed"), Integer::New(isolate, avg.Speed));
    obj->Set(String::NewFromUtf8(isolate, "Cadance"), Integer::New(isolate, avg.Cadance));
    obj->Set(String::NewFromUtf8(isolate, "Altitude"), Integer::New(isolate, avg.Altitude));
    obj->Set(String::NewFromUtf8(isolate, "Power"), Integer::New(isolate, avg.Power));
    obj->Set(String::NewFromUtf8(isolate, "PowerBalance"), Integer::New(isolate, avg.PowerBalance));
    obj->Set(String::NewFromUtf8(isolate, "Count"), Integer::New(isolate, v.size()));


    obj->Set(String::NewFromUtf8(isolate, "TestArray"), array);

  args.GetReturnValue().Set(obj);
}

void Init(Handle<Object> exports, Handle<Object> module) {
  NODE_SET_METHOD(module, "exports", CreateObject);
}

NODE_MODULE(addon, Init)
