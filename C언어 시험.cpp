#include<iostream>
#include<string>
using namespace std;
int main(void) {
	string line;
	cout << "소문자로 구성된 단어를 입력하시오: ";
	getline(cin, line, '\n');

	for (char a = 'a'; a <= 'z'; a++) {
		int count = 0;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == a) {
				count++;
			}
		}
		if(count > 0){
			cout << "문자" << a << "가" << count << "번 나타남!" << endl;
		}
	}
	return 0;
}




#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Picture {
private:
    int width;
    int height;
    char place[30];
public:
    Picture(int w, int h, const char* p) {
        width = w;
        height = h;
        strcpy(place, p);
    }
    Picture() : Picture(5, 7, "모름") {}
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
    const char* getPlace() {
        return place;
    }
};

int main() {
    Picture pic;
    Picture mt(10, 14, "한라산");
    cout << pic.getWidth() << "x" << pic.getHeight() << " " << pic.getPlace() << endl;
    cout << mt.getWidth() << "x" << mt.getHeight() << " " << mt.getPlace() << endl;
    return 0;
}


