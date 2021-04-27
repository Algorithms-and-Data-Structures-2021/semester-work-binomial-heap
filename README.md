#Биномиальная куча

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-binomial-heap/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-binomial-heap/actions/workflows/cmake.yml)

https://drive.google.com/drive/folders/1-p9M5AXZTXIXM9PM4MRjlpkHWtD8deeH

- _Какая структура данных реализуется?_ Биномиальная куча
- _Что она из себя представляет (сбалансированное дерево, линейный список и пр.)?_Биномиальная куча — структура данных, реализующая абстрактный тип данных «очередь с приоритетом», которая представляет собой набор биномиальных деревьев с двумя свойствами:
ключ каждой вершины не меньше ключа её родителя;
все биномиальные деревья имеют разный размер.

- _Где и как она используется (приложения)?_
- Биномиальная куча используется в Дискретном моделировании событий.
Дискретно-событийное моделирование (DES) моделирует работу системы как (дискретную) последовательность событий во времени.

- _Какие операции над ней можно выполнять (поиск, удаление, добавление, вставка и пр.)?_Основные операции:                                              Сложность данных операций:
1) Вставка элемента в кучу.                                  1) O(1) - Константная.
2) Слияние двух куч.                                             2) O(logN) - Логарифмическая.
3) Удаление минимального элемента из кучи.   3) O(logN) - Логарифмическая.
- _Какова теоретическая сложность операций (поиск за `O(log(n))`, вставка за `O(n^2)` и т.д.)?_
- _Какая-то другая справочная информация о проекте._

## Команда "Балдеж"

| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Миннибаева Алина  | 50        |  Тока Киришима          |
|Гаделев Максим     | 50        | Канеки Кен               |

**Девиз команды**
Я гуль.

## Структура проекта

_Описание основных частей семестрового проекта._

Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Рекомендуемый объем оперативной памяти - не менее 16 ГБ.
4. Свободное дисковое пространство объемом ~ 3 ГБ (набор данных для контрольных тестов).

## Сборка и запуск:

#### Сборка проекта

Склонируйте проект к себе на устройство с помощью IDE:

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template.git
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-template

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

С поомощью файла generate_csv_dataset вы можете сгенерировать данные в диапозоне от 100 до 5 миллионов.
Данных хранятся в папке /dataset/data/.

Тестовые данные представлены в CSV формате (см.
[`dataset/data/`](dataset/data/dataset-example.csv)):


#### Контрольные тесты (benchmarks)

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.
Запустите один из 3-х файлов: benchmark_merge, benchmark_insert,bencmark_deleteMin  
Введите консоль кол-во данных для тестов от 100 до 5 миллионов
В папке датасет появится .csv файл,где вы можете увидеть время выполнения операций.

Ссылка на архив с набором данных: [Google Drive](https://drive.google.com/drive/folders/14sQmE_G3YR1yVIKV19gLp6F2CTwnooat).

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `benchmark_merge` | слияние куч   | _время_         |
| `benchmark_insert`           | вставка элемента в куча | _время |
|bencmark_deleteMin             | удаление минимального элемента в куче                                     | время             |

##### Примеры запуска

Описаны в контрольных тестах.

## Источники

1. https://www.geeksforgeeks.org/binomial-heap-2/
2. https://iq.opengenus.org/binomial-heap/
3. https://ru.wikipedia.org/wiki/Биномиальная_куча#:~:te..(англ.%20binomial%20heap),биномиальных%20деревьев%20с%20двумя%20свойствами%3A
4. https://www.youtube.com/watch?v=PzytwZRjjS8&t=1301s
