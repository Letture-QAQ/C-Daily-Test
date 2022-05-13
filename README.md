# C-Daily-Test
## 2022-5-8 实现String ===> 2022-5-9 完成
- auto str1 = CustomString("test1");(√)
- auto str2 = CustomString("test2, test3");(√)
- str1 = "test3";(√)
- int len = str1.len();(√)
- CustomString sub1 = str1.sub(1,2);(√)
- str1.append("append");(√)
- bool equal = str1 == str2;(√)
- int index = str1.find("es");(√)
- CustomString* ret = str2.split(",");(√)

- 实现截图(输出字符串的时候有乱码，等我有时间看一下)
![image](https://user-images.githubusercontent.com/74652578/167532823-e165cac6-cc69-47b3-8c8e-45517bfa2eed.png)

## 2022-5-9 开始实现Array

- 实现数组以及以下api
- auto arr = new CustomArray();(√)
- arr.reserve(4);(×)
- arr.push(1);(×)
- arr.push(2);(×)
- arr.insert(1, 3);(×)
- arr.remove(1);(×)
- arr.pop();(×)
- arr.clear();(×)
- int index = arr.findIndex(1);(×)

---
2022-5-10 Notify一下，今天去打球，晚上看情况实现以下Array
---
2022-5-13 Vector实现完成，准备实现Double_Link_List
---

