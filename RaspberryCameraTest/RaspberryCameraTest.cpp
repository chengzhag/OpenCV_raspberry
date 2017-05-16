#include <fstream>
#include <iostream>
#include <vector>
#include <raspicam.h>
#include <unistd.h>

using namespace std;


int main(int argc, char **argv) 
{
	raspicam::RaspiCam camera;
    
	if (!camera.open()) 
	{
		cerr << "Could not open the camera" << endl; 
		return 1;
	}
    
	cout << "Initial delay..." << endl;
	sleep(3);
	cout << "Acquiring image..." << endl;
	camera.grab();

	std::vector<unsigned char> buf;
	buf.resize(camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB));
    
	camera.retrieve(buf.data(), raspicam::RASPICAM_FORMAT_RGB);

	std::ofstream outFile("output.ppm", std::ios::binary);
	outFile << "P6\n" << camera.getWidth() << " " << camera.getHeight() << " 255\n";
	outFile.write((char*)buf.data(), buf.size());

	cout << "Image saved to output.ppm" << endl;
	return 0;
}
