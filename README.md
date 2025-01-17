# CodeAdventurer
Створений студентами КФКЕПу "робот" який буде бігати по консолі і вчити молодь азам програмування на мові С++

# Документація 
Нижче наведено короткий список усіх основних та додаткових функцій:

-----
<h3><b>ОСНОВНІ</b></h3>

  • _**setMap()**_ - Функція для оновлення змінних, які зберігають назву та шлях до карти. Функція приймає один параметр у вигляді назви карти в подвійних лапках. Прописувати шлях до розширення карти не потрібно, функція за замовчуванням додає _"maps/{FileName}.map"_, де _FileName_ — назва файлу, яку передають у функцію як параметр. За замовчуванням встановлена пуста карта (_map1_).
  
  • _**rendering()**_ - Функція для відображення готової до роботи карти. 
  
  • _**turnLeft()/turnRight()**_ - Функція для повороту Кодикса вправо або вліво. За замовчуванням Кодикс дивится на схід(East) (_">"_).
  
  • _**step()**_ - Функція для проходження одного кроку вперед, за умови, що попереду немає ніяких перешкод.
  
  • _**collectBeep()**_ - Функція для підбирання "сигналу", за умови, що Кодикс стоїть на цьому-ж самому "сигналі". Після підбирання сигнал зникає візуально с карти.


----
<h3><b>ДОДАТКОВІ</b></h3>

  • _**frontCheck()**_ - Функція для перевірки наявності перешкод перед Кодиксом. Якщо перед Кодиксом є перешкода то функція повертає 1, якщо шлях вільний - 0. 
  
  • _**checkForBeep()**_ - Функція, яка перевіряє, чи стоїть Кодикс на "сигналі". Якщо Кодикс стоїть на "сигналі" то функція повератє 1, якщо під Кодиксом немає "сигналу" - 0.

----
<h3><b>СИСТЕМНІ</b></h3>

  • _**readMapFromFile()**_ - Функція, яка зчитує карту з файлу і записує її в двовимірний масив для подальшої роботи.
  
  • _**copyMap()**_ - Функція, яка створює копію карти, з якою зараз працює програміст.
  
  • _**converter()**_ - Функція, яка перетворює аргументи під картою в змінні для подальшої роботи.
  
  • _**placePlayerOnMap()**_ - Функція, яка замінює крапку на вибраних координатах на символ Кодикса для подальшої роботи.
  
  • _**displayMap()**_ - Функція, яка відображає всю карту з двовимірного масиву.

----

Для детальнішої інформації відкрийте [Wiki](https://github.com/KFKEP/CodeAdventurer/wiki) 
