# Лабораторная работа №1 по дисциплине "Инжинерная и компьютерная графика"

# Установка библиотек OpenGL 
- freeglut
- glew
- glm

# Создание окна 
``` c++
glutInit(&argc, argv); //инициализируем glut

glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //устанавливаем свойства glut. включаем двойную буферизацию и отображение в режиме RGBA

glutInitWindowSize(1024, 768); //задаем размер окна 1024*768

glutInitWindowPosition(100, 100); //задаем начальную позицию окна относительно левого верхнего угла

glutCreateWindow("Tutorial 01"); //создаем окно с названием "Tutorial 01"

glutDisplayFunc(RenderSceneCB); //отрисовываем 1 кадр

glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //устанавливаем цвет экрана, который будет у него во время очистки буфера кадра (красный, зелёный, синий, альфа-канал)

glutMainLoop(); //этот вызов передаёт контроль GLUT'у, который теперь начнёт свой собственный цикл
```

Функция отрисовки
```c++
void RenderSceneCB() {
    glClear(GL_COLOR_BUFFER_BIT); //очистка буфера кадра
    glutSwapBuffers(); //обмен фонового буфера и буфера кадра местами 
}
```

# Рисование точки
```c++
GLuint VBO; //указатель на буфер вершин
```
редактируем main()
```c++
glm::vec3 vertices[1]; //создаём вектор вершин (векторов из glm)

vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f); //создаём вектор в центре экрана (x=0, y=0, z=0 - центр экрана)

glGenBuffers(1, &VBO); //генерируем объект переменного типа (количество объектов, ссылка на массив для хранения)

glBindBuffer(GL_ARRAY_BUFFER, VBO); //буфер будет хранить массив вершин

glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); //наполняем объект данными
```
редактируем функию отрисовки
```c++
glEnableVertexAttribArray(0); //координаты вершин, используемые в буфере, рассматриваются как атрибут вершины с индексом 0

glBindBuffer(GL_ARRAY_BUFFER, VBO); //обратно привязываем наш буфер, приготавливая его для отрисовки

glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //говорим конвейеру как воспринимать данные внутри буфера (индекс атрибута, количество аттрибутов, тип данных каждого компонента, нормализировать ли данные перед использованием, число байтов, между двумя экземплярами атрибута, смещение первого компонента первого универсального атрибута вершины)

glDrawArrays(GL_POINTS, 0, 1); //вызываем функцию отрисовки (режим рисования, индекс первого элемента в буфере, количество элементов)

glDisableVertexAttribArray(0); //отключаем каждый атрибут вершины
```
# Рисование фигуры
редактируем main()
```c++
    glm::vec3 Vertices[4]; // массив 4 точек прямоугольника
    Vertices[0] = glm::vec3(0.0f, -0.5f, 0.0f);
    Vertices[1] = glm::vec3(0.5f, -0.5f, 0.0f);
    Vertices[2] = glm::vec3(0.0f, 0.0f, 0.0f);
    Vertices[3] = glm::vec3(0.5f, 0.0f, 0.0f);
```
редактируем функию отрисовки
```c++
glColor3f(1, 1, 0); //(RGB)фигура будет желтой

glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); //вызываем функцию отрисовки (режим рисования, индекс первого элемента в буфере, количество элементов)
```


