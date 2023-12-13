#include <curl/curl.h>
#include <iostream>
#include <string>

using namespace std;

//选择天气API，高德天气API key：470dda0007b8990cfc051d2d5e0c7052

//https://restapi.amap.com/v3/weather/weatherInfo?city=110101&key=470dda0007b8990cfc051d2d5e0c7052
//这个函数是干嘛的？
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, string *userp){
    userp->append(static_cast<char*>(contents), size * nmemb);
}

//获取天气数据
string GetWeatherData(const string& url){
    CURL *curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res != CURLE_OK){
            cout<<"curl_easy_perform() failed: "<<curl_easy_strerror(res)<<endl;
        }
    }
    return readBuffer;
}

//解析和展示天气数据
void ParseAndShowWeatherData(const string& data){
    //解析JSON数据
    auto jsonData = nlohmann::json::parse(data);
    //假设JSON数据包含温度和天气描述字段
    double temperature = jsonData["main"]["temp"];
    string description = jsonData["weather"][0]["description"];

    //展示天气数据
    cout<<"Temperature: "<<temperature<< "°C" <<endl;
    cout<<"Description: "<<description<<endl;
}

int main(){
    //获取天气数据
    string data = GetWeatherData("https://restapi.amap.com/v3/weather/weatherInfo?city=110101&key=470dda0007b8990cfc051d2d5e0c7052");
    //解析和展示天气数据
    ParseAndShowWeatherData(data);
    return 0;
}