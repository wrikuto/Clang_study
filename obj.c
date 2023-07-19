#include <stdio.h>
#include <stdlib.h>

// 構造体変数の宣言
typedef struct {
    int width;
    int height;
    int (*calculateArea)(int, int);
} Rectangle;

// ----------

// 面積を返す関数
int calculateArea(int width, int height) {
    return width * height;
}

// 構造体を作成して返す
Rectangle* createRectangle(int w, int h) {
    Rectangle *rect; 

    rect = malloc(sizeof(Rectangle));
    rect->width = w;
    rect->height = h;
    rect->calculateArea = calculateArea;
    
    return rect;
}

int main() {
	// 構造体を作成
    Rectangle* rect; 

    rect = createRectangle(5, 10);
	// 構造体のcalculateAliaをポインタで呼び出す。
    int area = rect->calculateArea(rect->width, rect->height);
    printf("Area: %d\n", area);

    free(rect);
    return 0;
}