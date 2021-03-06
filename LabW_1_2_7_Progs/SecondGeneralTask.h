#pragma once

/*	
	Создайте следующую иерархию классов и определите для них соответствующие поля и
	методы:

																	 /--Консервированый продукты
							/--- Продукты питания(Абстр. класс) <----|
							|										 \--Свежий продукт
	Товар(Абстр. класс) <---|
							|
							\--- Элктроный товар <-------------------Комплектующий

		Два класса должны быть абстрактные – Товар и Продукт питания.
		В классе Товар, как минимум, должен быть абстрактный метод приведения к строке (через
	перегрузку приведения типов) данных класса. Воспользуйтесь при выводе на экран.
		В классе Продукт питания должен быть абстрактный метод определения срока годности (он
	определяется в днях).
		Класс Свежий продукт имеет поле Срок годности (в днях).
		Класс Консервированный продукт имеет поле Срок годности в закрытом состоянии (в
	днях), Срок годности в открытом состоянии (в днях), а также поле Закрыт (bool).
		Класс Электронный товар должен иметь поле Тип товара, а класс Комплектующий еще и
	Тип комплектующей (частью чего является).
		Помимо названных продумайте и остальные поля, содержащие данные объектов, такие как
	Название, Компания производитель, Вес и т.д.
		Создайте два основных массива указателей на данные типа:
		 Электронные товары.
		 Продукты питания.
		Обеспечьте возможность заполнять эти массивы новыми объектами. Пользователь сам
	должен выбирать, данные какого объекта он хочет сейчас ввести.
		Создайте функцию, которая вычисляет для всех продуктов питания срок годности. При этом
	функция должна принимать объект типа Продукт питания и вызывать виртуальный метод.
		Создайте функцию, которая выводит данные массива Товаров на экран. Функция принимает
	в качестве аргумента массив Товаров (массив электронных товаров или продуктов питания). Для
	каждого элемента массива выводится на экран в виде строки (приведение к строке).
		sУ пользователя должна быть возможность вызвать одну из этих функций.
*/

void secondGeneralTask();