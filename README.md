# Отчет

## Реализации заполнений
* _A[i][j] = (N/M * i + j) * 2_

https://github.com/ProbablyDead/algorithm/blob/25f5c39e19ff25c2f452321cbbd190c832a489b3/array/arrOpt.cpp#L4-L14

* _A[i][j] = (N/M * i * j) * 2_

https://github.com/ProbablyDead/algorithm/blob/d75f1d024b78f3711ab86af36883202dc5c9277f/array/arrOpt.cpp#L16-L26

---

## Реализации Алгоритмов

* _Бинарный поиск_ - O(M*log(N))

https://github.com/ProbablyDead/algorithm/blob/d75f1d024b78f3711ab86af36883202dc5c9277f/algorithms/binary/binary.cpp#L6-L17

* _Поиск лесенкой_  - O(M+N)

https://github.com/ProbablyDead/algorithm/blob/d75f1d024b78f3711ab86af36883202dc5c9277f/algorithms/ladder/ladder.cpp#L6-L16

* _Экспоненциальный поиск_ - O(M*log(N))

https://github.com/ProbablyDead/algorithm/blob/d75f1d024b78f3711ab86af36883202dc5c9277f/algorithms/exponentional/exp.cpp#L32-L53

> Бинарный поиск по столбцу
> https://github.com/ProbablyDead/algorithm/blob/d75f1d024b78f3711ab86af36883202dc5c9277f/algorithms/exponentional/exp.cpp#L19-L30

---

> ### Запуски алгоритмов и замеры времени
>
> * _Бинарный поиск_
> 
> https://github.com/ProbablyDead/algorithm/blob/25f5c39e19ff25c2f452321cbbd190c832a489b3/algorithms/binary/binary.cpp#L28-L46
> 
> * _Поиск лесенкой_
> 
> https://github.com/ProbablyDead/algorithm/blob/d75f1d024b78f3711ab86af36883202dc5c9277f/algorithms/ladder/ladder.cpp#L18-L36
>
> * _Экспоненциальный поиск_
> 
> https://github.com/ProbablyDead/algorithm/blob/d75f1d024b78f3711ab86af36883202dc5c9277f/algorithms/exponentional/exp.cpp#L55-L73
> 

---

## Замеры (в микросекундах)

* _Бинарный поиск_

![Бинарный поиск](.readmeStuff/measurements/binary.png)

* _Поиск лесенкой_

![Линейный поиск](.readmeStuff/measurements/ladder.png)


* _Экспоненциальный поиск_

![Экспоненциальный поиск](.readmeStuff/measurements/exponential.png)

---

## Визуализация

* _Бинарный поиск_

![Бинарный поиск визуализация](.readmeStuff/visualizations/binary.png)

* _Поиск лесенкой_

![Поиск лесенкой визуализация](.readmeStuff/visualizations/ladder.png)

* _Экспоненциальный поиск_

![Экспоненциальный поиск визуализация](.readmeStuff/visualizations/exponential.png)

---

## Зависимость от заполнения

* _A[i][j] = (N/M * i + j) * 2_

![Первое заполнение](.readmeStuff/visualizations/firstFill.png)

* _A[i][j] = (N/M * i * j) * 2_

![Второе заполнение](.readmeStuff/visualizations/secondFill.png)

---

## _Выводы_

* Заметно, что различия во времени выполнения между одним алгоритмом, работающим на разных данных различаются, 
в основном `второе заполнение работает быстрее`, за исключением бинарного поиска, думаю тут дело в нулях в первой строке
и первом столбце.
* Замечу факт, что бинарный поиск работает почти в `2 раза медленнее` конкурентов на больших данных, так как никаких 
смещений по строкам нет 
и приходится искать в каждой.
* Бинарный очень неплохо справляется `с малыми объемами данных` (~ М < 100).
* Самым быстрым почти на всех этапах оказался `экспоненциальный поиск`, кроме значений `m < 350` на втором заполнении. 
Думаю, это происходит потому, что в отличие от лесенки, экспоненциальный поиск пропускает большие объемы данных, 
но на малых данных он не успевает "набрать обороты" и не пропускает большую часть данных, к тому же его достаточно сильно 
замедляет бинарный поиск на больших объемах.

> __Итого:__ Самым быстрым оказался `экспоненциальный поиск` почти на всех данных,
> самым медленным на малых данных - `поиск лесенкой`, самым медленным на больших - бинарный.
> Но не стоит исключать тот факт, что экспоненциальный я, возможно, запускал с меньшим количеством открытых программ на ПК. 

### P.S. Excel report is [here](https://docs.google.com/spreadsheets/d/1FrxqawflBV525azESpkDQXcTIUvimMBtfz8EOFm53jg/edit?usp=sharing)
