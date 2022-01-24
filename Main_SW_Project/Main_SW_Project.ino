#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <time.h>
#include "DHT.h"



/*넣어야 할 기능 : 시간 동기화 LED*/


/*LED, 습도 센서등의 각종 모듈 핀모드 설정*/


DHT dht(5,DHT22); //습도 센서

/*전역 변수 선언*/
float temp;
int humidity;
float wind_speed;
//String weather_json = "0";
int weather_code;
int pre_weather_code = 0;


int tera_humidity; //온습도 센서 구입 후 핀모드로 변경
float tera_temp; //온습도 센서 테라리움 내부 온도 측정

/*time*/
int timezone = 3;
int dst = 0;

unsigned long previousMillis = 0;
const long interval = 1000;

unsigned long time_previous, time_current;

/*연결할 와이파이 비밀번호 변수 설정*/
//const char* ssid = "KT_starbucks";
//const char* password = "";
const char* ssid = "KT_GiGA_2G_Wave2_B1DC";
const char* password = "df1edb9997";





void setup() {

  dht.begin();
  
  //Serial 115200
  Serial.begin(115200);
  delay(500);
  Serial.print("와이파이 연결 중...");

  WiFi.begin(ssid, password); //와이파이 엑세스

/*와이파이 연결 중일때 ... 출력*/
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("연결 완료");

  //날짜 시간 정보 받기
  configTime(3 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("\n시간을 받아오는 중");
  while (!time(nullptr)) { //아무 값이 없을 때 NULL 상태
    Serial.print(".");
    delay(1000);
  }
  Serial.println("NIST서버 연결 완료");
}


void Realtime(){
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;

    time_t now = time(nullptr);
    Serial.println(ctime(&now));
  }
}



void Get_weather(){
  if(WiFi.status() == WL_CONNECTED) {
    digitalWrite(13, HIGH);
    HTTPClient http;

    //OpenWeather API 날씨 요청
    http.begin("http://api.openweathermap.org/data/2.5/weather?q=Bucheon-si,KR&APPID=27cda33370f1801776c0f179d6b7f6e8"); //API 주소

    int httpCode = http.GET(); //http값 얻어오기

    //string 값 받아오기
    if (httpCode > 0){
      String payload = http.getString();
      DynamicJsonBuffer jsonBuffer(2000);//json 버퍼 설정

      //JSON 파싱
      JsonObject& root = jsonBuffer.parseObject(payload);
      if (!root.success()){
        Serial.println(F("파싱 실패"));
        //retrun 0;
      }

      /*JSON에 대괄호 부분에 있는 중괄호는 따로 파싱 오브젝트를 제작해야함
        해당 JSON의 weather은 대괄호안에 중괄호 0가 포함되어있기에 위에 작성한
        root에 해당이 안돼 사용이 불가했었음*/
        
      JsonObject& weather = root["weather"][0]; 

      temp = (float)(root["main"]["temp"]) - 273.15; //GET temperature by Json
      humidity = root["main"]["humidity"]; // GET humidity by Json
      wind_speed = (float)(root["wind"]["speed"]); // GET wind speed by Json
      String weather_json = weather["main"];//GET Weather by Json
      weather_code = weather["id"]; //GET Weather Code by Json

      
      //날씨 정보 출력
      Serial.println("외부 날씨");
      Serial.printf("온도 = %.2fºC\r\n",temp);
      Serial.printf("습도 = %d %%\r\n",humidity);
      Serial.printf("풍속 = %.1f m/s\r\n",wind_speed);
      Serial.print("날씨 = " + weather_json);
      Serial.printf("\n날씨 코드 = %d\n",weather_code);
    }
    http.end(); //연결 끊기
  }
  //delay(60000); //1분마다 재연결 후 날씨 정보 갱신
}


void Get_tera_humidity(){
  
  tera_humidity = dht.readHumidity();
  tera_temp = dht.readTemperature();
  //tera_temp = dht.readTemperature(true); //화씨 온도 측정
  
  if (isnan(tera_humidity) || isnan(temp)){
    Serial.println("온습도 읽어오기 실패!");
    //return;
  }

  //float tera_temp_c = dht.computeHeatIndex(tera_temp, tera_humidity, false);
  Serial.println("테라리움 실내 온도");
  Serial.printf("tera_temp = %.2fºC\r\n", tera_temp);
  Serial.printf("tera_humidity = %d %%\r\n", tera_humidity);
}




void AtmoCore(){
  /*AtmoCore Code 작성*/

  
    //Serial.printf("현재 날씨 코드 : %d",weather_code);
    switch(weather_code){
      

      case 200: //thunderstorm
        Serial.println("UART_Code : 200");
        break;
      case 201:
        Serial.println("UART_Code : 201");
        break;
      case 202:
        Serial.println("UART_Code : 202");
        break;
      case 210:
        Serial.println("UART_Code : 210");
        break;
      case 211:
        Serial.println("UART_Code : 211");
        break;
      case 212:
        Serial.println("UART_Code : 212");
        break;
      case 221:
        Serial.println("UART_Code : 221");
        break;
      case 230:
        Serial.println("UART_Code : 230");
        break;
      case 231:
        Serial.println("UART_Code : 231");
        break;
      case 232:
        Serial.println("UART_Code : 232");
        break;

      case 300: //drizzle
        Serial.println("UART_Code : 300");
        break;
      case 301:
        Serial.println("UART_Code : 301");
        break;
      case 302:
        Serial.println("UART_Code : 302");
        break;
      case 310:
        Serial.println("UART_Code : 310");
        break;
      case 311:
        Serial.println("UART_Code : 311");
        break;
      case 312:
        Serial.println("UART_Code : 312");
        break;
      case 313:
        Serial.println("UART_Code : 313");
        break;
      case 314:
        Serial.println("UART_Code : 314");
        break;
      case 321:
        Serial.println("UART_Code : 321");
        break;

      case 500: //rain
        Serial.println("UART_Code : 500");
        break;
      case 501:
        Serial.println("UART_Code : 501");
        break;
      case 502:
        Serial.println("UART_Code : 502");
        break;
      case 503:
        Serial.println("UART_Code : 503");
        break;
      case 504:
        Serial.println("UART_Code : 504");
        break;
      case 511:
        Serial.println("UART_Code : 511");
        break;
      case 520:
        Serial.println("UART_Code : 520");
        break;
      case 521:
        Serial.println("UART_Code : 521");
        break;
      case 522:
        Serial.println("UART_Code : 522");
        break;
      case 531:
        Serial.println("UART_Code : 531");
        break;

      case 701: //Atmosphere(대기)
        Serial.println("UART_Code : 701");
        break;
      case 711:
        Serial.println("UART_Code : 711");
        break;
      case 721:
        Serial.println("UART_Code : 721");
        break;
      case 731:
        Serial.println("UART_Code : Dust(황사)_none");
        break;
      case 741:
        Serial.println("UART_Code : 741");
        break;
      case 751:
        Serial.println("UART_Code : Sand_none");
        break;
      case 761:
        Serial.println("UART_Code : Dust_none");
        break;
      case 762:
        Serial.println("UART_Code : Volcanic ash_none");
        break;
      case 771:
        Serial.println("UART_Code : 771");
        break;
      case 781:
        Serial.println("UART_Code : 781");
        break;
        
      
      case 800://Clear & Clouds
        Serial.println("UART_Code : 800");
        break;
      case 801:
        Serial.println("UART_Code : None");
        break;
      case 802:
        Serial.println("UART_Code : none");
        break;
      case 803:
        Serial.println("UART_Code : none");
        break;
      case 804:
        Serial.println("UART_Code : none");
        break;
   }
  
  

}

void humi(){

  if (tera_humidity != humidity){
    Serial.println("Activate water atomization");
  }else{
    Serial.println("Deactivate water atomization");
  }
  
}





void loop() {

  time_previous = millis(); //start time
  time_current = millis(); //now





  printf("\n");
  Realtime();
  Get_weather();
  printf("\n");
  Get_tera_humidity();
  humi();
 

  if (pre_weather_code != weather_code){ 
    /*이전 날씨 코드와 수신한 날짜코드가 다를 경우 새로운 날씨 적용을 위해 스위치로 넘어간다
    무식하게 스위치로 도배해서 좀 슬픈데 날짜 코드 마다 각 모듈의 작동방식이 전부 다르기 때문에 스위치로 도배*/
    AtmoCore();
  }
  
  pre_weather_code = weather_code;
  
  
  //delay(300000); //5분마다 Refresh
}
