#include<stdio.h>
#include <iostream>
#include <cmath>


// 抽象クラス Shape
class Shape {
public:
	virtual float size() const = 0; // 純粋仮想関数: 面積を計算する
	virtual void draw() const = 0;  // 純粋仮想関数: 面積を表示する
	virtual ~Shape() {}             // 仮想デストラクタ
};

// 矩形クラス Rectangle
class Rectangle : public Shape {
private:
	float width;
	float height;

public:
	Rectangle(float w, float h) : width(w), height(h) {}

	float size() const override { return width * height; }

	void draw() const override { std::cout << "Rectangle: Area = " << size() << std::endl; }
};

// 円クラス Circle
class Circle : public Shape {
private:
	float radius;

	float pi = 3.14f;

public:
	Circle(float r) : radius(r) {}

	float size() const override { return pi * radius * radius; }

	void draw() const override { std::cout << "Circle: Area = " << size() << std::endl; }
};

int main() {
	// インスタンスを作成
	Shape* shapes[] = {new Rectangle(5.0f, 3.0f), new Circle(2.0f)};

	// 各形状の面積を計算し表示
	for (Shape* shape : shapes) {
		shape->draw();
	}

	// メモリを解放
	for (Shape* shape : shapes) {
		delete shape;
	}

	return 0;
}
