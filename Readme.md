# #EcoSystem



**Original Idea : Project Oasis (https://github.com/googlecreativelab/project-oasis)**

**이 프로젝트는 [Experiments with Google](https://experiments.withgoogle.com/)의 Project oasis에서 영감을 받아 제작되었습니다.**



## 소개

한정된 공간에 지구의 날씨와 비슷한 환경에서 식물 생장이 가능할까? 라는 생각으로 시작해

사람의 관리 없이 현재 밖의 날씨 정보를 실시간으로 받아와 한정된 공간인 테라리움 안에 인공적인 날씨를 연출시켜 식물 생장이 가능하게 해주는 시스템입니다.

OpenWeatherMap API를 활용했으며 JSON 형식으로 아두이노에서 정보를 받아옵니다.

받아 온 정보를 기반으로 하드웨어를 동작시켜 테라리움 내부에도 외부날씨와 동일한 날씨를 연출시켜줍니다.

## 기능

#### 식물 광합성

​	광합성이 가능한 생장 LED를 활용해 시간과 연동하여 LED가 리얼타임으로 작동됩니다.

#### 습도

​	실시간으로 받아온 날씨 데이터에 포함된 습도와 테라리움의 내부 습도 값을 가져와 가습기 모듈을 이용해

​	테라리움의 내부 습도를 조절합니다.

#### 비

​	밖에서 비가 온다면 테라리움 내부에도 비가 내립니다.



## 하드웨어

#### 핵심 하드웨어

**Main Body : Arduino Uno WeMos D1 Wifi Board**

**Sub Body : Ardunio Uno**

// Main Body에 날씨정보를 받아오고 받아온 날씨정보를 토대로 Sub Body에 날씨 코드를 보내줍니다.

Sub Body는 받아온 날씨 코드를 기반으로 하드웨어 모듈을 작동시킵니다. 이 둘의 통신은 UART로 할 예정입니다.



**Peristaltic pump** - Sub Body

// BLDC모터가 내장된 펌프를 이용해 비를 내리게 해줍니다.



**UV-C LED **- Sub Body

//  살균력이 가장 좋은 UV-C LED를 활용해 기기 내부에 저장되어있는 물을 항상 소독시킵니다.



**식물 생장 백색 LED** -Sub Body

// 식물 광합성에 필요한 LED입니다.



**투명 실리콘 호스**

// 물을 이동시키는 호스입니다.



**초음파 가습기 모듈** - Sub Body

// 습도를 조절하기 위한 가습기 모듈입니다.

 

**12V 120mm FAN** - Sub Body

// 습도를 빠르게 낮추거나 테라리움 내부 공기 순환을 할 때 이용됩니다.



**DHT22 Sensor** - Main Body

// 테라리움 내부의 온도와 습도를 측정하기 위한 센서입니다.



**Water Sensor** - Sub Body

// Water Block의 물이 얼만큼 저장되어있는지 확인하기 위한 센서입니다.



**여과지 & 부직포**

// 흙을 거친 물을 다시 재활용하기 위해 불순물을 거르기 위한 여과지와 부직포입니다.



**활성탄**

// 흙을 거친 물을 정화시키기 위한 활성탄입니다.



#### **부가적인 하드웨어**

**CO² Sensor** - Main Body

// 테라리움 내부의 이산화탄소 농도를 측정하기 위한 센서입니다.

**공기 질 측정 센서(PM)** - Main Body

// 외부 공기 질을 확인하기 위한 센서입니다.