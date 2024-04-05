# 🛺 ESP32-XAMPP-with-Python
## 🤔 ภาพรวม
โปรเจกต์นี้จะนำเสนอวิธีการใช้ ESP32 ส่งข้อมูลไปเก็บใน MySQL Server ด้วย XAMPP และ Python ในตัวอย่างต่อไปนี้เป็นโปรแกรมวัดค่าอุณหภูมิและความชื้นด้วยเซนเซอร์ DHT22

## 🧰 เครื่องมือ
- [XAMPP](https://www.apachefriends.org/download.html) สำหรับ MySQL Server
- 💻 Editor
  - ในตัวอย่างนี้จะใช้ [Visual Studio Code](https://code.visualstudio.com/) (สามารถใช้ [Arduino IDE](https://www.arduino.cc/en/software) ได้)
  - VScode ต้องติดตั้ง [PlatformIO IDE](https://docs.platformio.org/en/latest/integration/ide/vscode.html) สำหรับเขียนโปรแกรม ESP32
- 🔨 อุปกรณ์
  - บอร์ด ESP32
  - เซนเซอร์ DHT22
 
## ⏰ การทำงาน
1. เปิด MySQL Server และสร้าง Database สำหรับเก็บข้อมูล
2. รัน [PythonServer.py](../blob/main/PythonServer.py) สำหรับรับค่าจาก sensor ด้วยการรับ request และส่งข้อมูลไปเก็บที่ MySQL Server
3. อัพโหลดโปรแกรม ESP32 สำหรับวัดค่าอุณหภูมิและความชื้น และส่ง request พร้อมค่าที่วัดได้

## 🖼️ ภาพ
<div align="center">
  <img src="https://github.com/SonOfThitivas/ESP32-XAMPP-with-Python/assets/83740933/02e1f0b7-b060-449d-bc39-57dd6a7194ab" width="500"/>
</div>

![image](https://github.com/SonOfThitivas/ESP32-XAMPP-with-Python/assets/83740933/8aeb10a5-8b4b-4522-bd02-75cc977e4fd8)

## 📖 สุดท้าย
แหล่งที่มาข้อมูลได้คอมเมนต์ไว้ในโค้ดแล้ว

🏪 ขอบคุณอุปกรณ์จากร้าน:
1. <img src="https://th.bing.com/th?id=ODLS.89188d41-8c11-42e9-9942-842f77220682&amp;w=32&amp;h=32&amp;qlt=93&amp;pcl=fffffa&amp;o=6&amp;pid=1.2" height="32" width="32" alt="Global web icon" class="rms_img" data-bm="44"> ARDUINO in Thailand : http://www.arduino.in.th/
2. <img src="https://th.bing.com/th?id=ODLS.414a449b-7b4c-4c7b-a96f-33c7a91e102e&amp;w=32&amp;h=32&amp;qlt=90&amp;pcl=fffffa&amp;o=6&amp;pid=1.2" height="32" width="32" alt="Global web icon" class="rms_img" data-bm="41"> Arduitronics : https://www.arduitronics.com/
