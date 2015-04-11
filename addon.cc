#include <node.h>

#include "./cpp/inc/io.h"
#include "./cpp/inc/data_point.h"
#include "./cpp/inc/cyclist_data.h"

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

    //std::vector<DataPoint> v(io::readInputFile(filepath.c_str()));

    CyclistData v = io::readInputFile(filepath.c_str());

    //"./data.hrm"));

    DataPoint avg(0,0,0,0,0,0);

    for(auto node : v.HRData)
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

    Handle<Array> heartRateArray = Array::New(isolate, v.HRData.size());
    Handle<Array> speedArray = Array::New(isolate, v.HRData.size());
    Handle<Array> cadanceArray = Array::New(isolate, v.HRData.size());
    Handle<Array> altitudeArray = Array::New(isolate, v.HRData.size());
    Handle<Array> powerArray = Array::New(isolate, v.HRData.size());
    Handle<Array> powerBalanceArray = Array::New(isolate, v.HRData.size());



    for (int i = 0; i < v.HRData.size(); ++i)
    {
        heartRateArray->Set(i, Integer::New(isolate, v.HRData[i].HeartRate));
        speedArray->Set(i, Integer::New(isolate, v.HRData[i].Speed));
        cadanceArray->Set(i, Integer::New(isolate, v.HRData[i].Cadance));
        altitudeArray->Set(i, Integer::New(isolate, v.HRData[i].Altitude));
        powerArray->Set(i, Integer::New(isolate, v.HRData[i].Power));
        powerBalanceArray->Set(i, Integer::New(isolate, v.HRData[i].PowerBalance));
    }

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
    obj->Set(String::NewFromUtf8(isolate, "Count"), Integer::New(isolate, v.HRData.size()));

    for( auto x : v.Params) {
        obj->Set(String::NewFromUtf8(isolate, x.first.c_str()), String::NewFromUtf8(isolate, x.second.c_str()));
    }


    obj->Set(String::NewFromUtf8(isolate, "TestArray"), array);

    obj->Set(String::NewFromUtf8(isolate, "HeartRateData"), heartRateArray);
    obj->Set(String::NewFromUtf8(isolate, "SpeedData"), speedArray);
    obj->Set(String::NewFromUtf8(isolate, "CadanceData"), cadanceArray);
    obj->Set(String::NewFromUtf8(isolate, "AltitudeData"), altitudeArray);
    obj->Set(String::NewFromUtf8(isolate, "PowerData"), powerArray);
    obj->Set(String::NewFromUtf8(isolate, "PowerBalanceData"), powerBalanceArray);

  args.GetReturnValue().Set(obj);
}

void Init(Handle<Object> exports, Handle<Object> module) {
  NODE_SET_METHOD(module, "exports", CreateObject);
}

NODE_MODULE(addon, Init)
