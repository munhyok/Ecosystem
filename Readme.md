# #Project EcoSystem

# 서론
**한정 된 공간에 지구의 날씨와 비슷한 환경에서 식물 성장 유지가 가능할까?**

날씨 정보를 이용해 실시간으로 테라리움 안에서 보여주는 것뿐만 아니라
밖의 날씨를 이용해 실제 식물을 사용자가 관리하지 않아도 스스로 성장이 가능할 수 있게 해주는 시스템

식물 참고 : https://brunch.co.kr/@zzanggusis/8


# 구현 범위

광합성, 습도(안개), 비 구현 예정

난제
가습기 살균 문제 (UV LED로 해결이 가능)
모터 소음
일회성 정수 필터

Ex) 밖 : 비가온다 -> 테라리움 : 비가 내리듯이 물을 뿌려준다


# 재료

## Main Body
OpenWeather API
https://kocoafab.cc/tutorial/view/654
https://randomnerdtutorials.com/esp8266-weather-forecaster/
https://simple-circuit.com/iot-internet-weather-station-esp8266/

아크릴

LED BAR (Plant Grow LED)

Arduino Uno

Bread Board 

ESP 8266(Wifi) API연결 목적 및 스마트폰 앱 제어의 목적

8000

Peristaltic pump (튜빙 펌프)


BLDC motor PWM Controller(motor shield)

UV LED (가급적 살균력이 좋은 UV-C LED로..)
https://ko.aliexpress.com/item/4000174320639.html?pid=808_0008_0131&spm=a2g0n.search-amp.list.4000174320639&aff_trace_key=&aff_platform=msite&m_page_id=3832EogFbAJA5_653QU28-qvzAc0iHLtP7IeENlIcTDqN3jdvwFursYTSOTO_aYFz5DY1583320468439&browser_id=3baf5fa2fa234049b13547afe5965909&is_c=Y

17000 × 2

식물 생장 백색 LED
http://mitem.gmarket.co.kr/Item?goodsCode=1373556203&jaehuid=200010778

13900

투명 실리콘 호스
https://www.navimro.com/p/K07147328?utm_source=google&utm_medium=shopping&gclid=CjwKCAjwwvfrBRBIEiwA2nFiPQf0xMKw1srC8Nocf1DTWpSke222WxwrkYmrNsgloBy5iyF00L8AFRoCD3MQAvD_BwE

6890

초음파 가습기 모듈
https://greenteeaaa.tistory.com/m/12?category=675066

8000

12V FAN / TIP120(Transistor) 10K 저항
https://youtu.be/Z-9Mio92w5g

1000

수분 센서
http://mechasolution.com/shop/goods/goods_view.php?goodsno=543105&category=

3300

온습도 센서 (DHT22)
https://front.wemakeprice.com/product/143290911?utm_source=google_ss&utm_medium=cpc&utm_campaign=r_sa&gclid=Cj0KCQjwiILsBRCGARIsAHKQWLOzLKUpIVP3JR3M26q_HYUbXAdJC6P_fPI6Rf8xJAMNDbuGrQkjB9IaAkrdEALw_wcB
6050

필터 제작
여과지
http://itempage3.auction.co.kr/DetailView.aspx?ItemNo=B477612571&frm3=V2

11550

활성탄
http://www.11st.co.kr/product/SellerProductDetail.tmall?method=getSellerProductDetail&prdNo=2272622540&gclid=Cj0KCQjwiILsBRCGARIsAHKQWLOPgWFg2zESBHGNiSgy9-wCPF0OblY-8dm_mRZMUYybHfBxM8M5WfUaAkfUEALw_wcB&utm_term=&utm_campaign=%B1%B8%B1%DB%BC%EE%C7%CEPC+%C3%DF%B0%A1%C0%DB%BE%F7&utm_source=%B1%B8%B1%DB_PC_S_%BC%EE%C7%CE&utm_medium=%B0%CB%BB%F6

3500

부직포


103800원
아크릴 5~60000



이산화탄소 측정 센서
http://eduino.kr/product/detail.html?product_no=559&cate_no=34&display_group=2

공기 측정 센서
http://eduino.kr/product/detail.html?product_no=578&cate_no=34&display_group=2

-----

## 2019.09.20(초안)

<img width="436" alt="image" src="https://user-images.githubusercontent.com/11683617/232244705-eec2ca2a-5ba2-4fc0-a04e-9f75bf1e74da.png">


이미지 5개의 레이어 층으로 구성

Layer 1 : HardWare (arduino, pi, etc)
Layer 2 : Water Block
Layer 3 : Filter
Layer 4 : Terrarium
Layer 5 : Module

### 2019.10.05 *변경 : 모듈과 하드웨어를 통합*/
Layer 1 : Water Block
Layer 2 : Filter
Layer 3 : Terrarium
Layer 4 : Module + HardWare (arduino .etc)

### 2020.02.08
내부 설계

### 2020.07.29

통신 - UART

INPUT - Arduino D1 Wifi board
WIFI를 활용해 OpenWeatherMap API를 통해 날씨정보 및 time.nist.gov의 시간 정보를 송신
날씨 정보를 활용해 어떤 하드웨어를 작동시킬지 계산 후 OUTPUT으로 송신

OUTPUT - Arduino UNO (NANO)
D1 Wifi board가 디지털 PWM을 미지원해서 UNO를 채용
INPUT이 송신한 정보를 수신받아 하드웨어 동작



### 2020.09.05
Weather Condition Code를 정리하여 어떤 하드웨어를 작동시킬지의 여부를 정의함

### 2020.09.18
정리한 Weather Condition Code를 Switch-Case로 분류해 코드 작성
이전 날씨 코드와 Refresh한 날씨코드를 비교해 같은 코드일 경우 AtmoCore를 거치지 않게 하여 작동 효율을 올림
