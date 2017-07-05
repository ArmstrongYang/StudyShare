#include <iostream>
#include <string>

using namespace std;
class Box
{
public:
	double length;
	double width;
	double height;
	void setLength(double len)
	{
		length = len;
	}
	double getLength(void)
	{
		return length;
	}
	double getSurfaceArea(void);
	double getVolume(void)
	{
		return length*width*height;
	}
};
double Box::getSurfaceArea(void)
{
	return 2*(length * width + width * height + length * height);
}
int main(int argc, char* argv[])
{
	Box box1;
	double volume = 0;
	box1.setLength(2);
	box1.width = 1;
	box1.height = 1;
	volume = box1.length * box1.width * box1.height;
	cout << "box1 volume:" << volume << endl;
	cout << "box1 volume:" << box1.getVolume() << endl;
	cout << "box1 SurfaceArea:" << box1.getSurfaceArea() << endl;
	cout << "box1.length" << box1.getLength() << endl;
	cin >> volume;
	return 0;
}